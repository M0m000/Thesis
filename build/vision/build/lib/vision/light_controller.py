# light_controller.py
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from kr_msgs.srv import SetDiscreteOutput, SetAnalogOutput
from std_msgs.msg import Bool, Float64


class LightController(Node):
    def __init__(self):
        super().__init__('light_controller')

        # Initial Desired Brightness
        self.declare_parameter('desired_brightness', 230.0)
        self.desired_brightness = self.get_parameter('desired_brightness').get_parameter_value().double_value

        # Image subscription
        self.subscription = self.create_subscription(Image, 'vcnanoz/image_raw', self.image_callback, 1)
        self.bridge = CvBridge()

        # Service Clients
        self.set_dig_out_client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')
        while not self.set_dig_out_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SetDiscreteOutput...")
        self.get_logger().info("Service SetDiscreteOutput available!")

        self.set_analog_out_client = self.create_client(SetAnalogOutput, '/kr/iob/set_voltage_output')
        while not self.set_analog_out_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SetAnalogOutput...")
        self.get_logger().info("Service SetAnalogOutput available!")

        # Control flags
        self.light_control_active = True
        self.light_control_freeze = False
        self.manual_mode_active = False

        # Control variables
        self.current_voltage = 2.0
        self.K_p = 0.005
        self.manual_voltage = 0.0

        # Outputs initialisieren
        self.set_digital_output(index=2, value=1)  # Power
        self.set_digital_output(index=3, value=1)  # Trigger
        self.set_analog_output(index=1, value=self.current_voltage)

        # Topic-based control
        self.create_subscription(Bool, '/vision/light_control/active', self.sub_control_active_callback, 10)
        self.create_subscription(Bool, '/vision/light_control/freeze', self.sub_control_freeze_callback, 10)
        self.create_subscription(Bool, '/vision/light_control/manual_mode', self.sub_control_manual_mode_callback, 10)
        self.create_subscription(Float64, '/vision/light_control/manual_brightness', self.sub_manual_control_callback, 10)
        self.create_subscription(Float64, '/vision/light_control/desired_brightness', self.sub_desired_brightness_callback, 10)

    def image_callback(self, msg):
        try:
            if self.light_control_active and not self.manual_mode_active:
                self.set_digital_output(index=3, value=1)
                img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
                brightness = np.mean(img)
                self.get_logger().info(f'Average brightness: {brightness:.1f}')
                e_brightness = self.desired_brightness - brightness
                control_signal = self.K_p * e_brightness
                self.current_voltage = max(2.0, min(10.0, self.current_voltage + control_signal))
                if not self.light_control_freeze:
                    self.set_analog_output(index=1, value=self.current_voltage)
            elif self.light_control_active and self.manual_mode_active:
                self.set_digital_output(index=3, value=1)
                self.set_analog_output(index=1, value=self.manual_voltage)
                self.get_logger().info(f"Manual mode: voltage {self.manual_voltage:.2f}V")
            else:
                self.set_digital_output(index=3, value=0)
                self.get_logger().info("Light control disabled.")
        except Exception as e:
            self.get_logger().error(f'Image processing error: {e}')

    def set_analog_output(self, index=1, value=0.0):
        req = SetAnalogOutput.Request()
        req.index = index
        req.value = float(value)
        future = self.set_analog_out_client.call_async(req)
        future.add_done_callback(self.analog_output_service_response)

    def analog_output_service_response(self, future):
        try:
            if future.result().success:
                self.get_logger().info(f"Analog output set to {self.current_voltage:.2f}V")
            else:
                self.get_logger().warn("Analog output failed")
        except Exception as e:
            self.get_logger().error(f"Analog service failed: {e}")

    def set_digital_output(self, index, value):
        req = SetDiscreteOutput.Request()
        req.index = index
        req.value = int(value)
        future = self.set_dig_out_client.call_async(req)
        future.add_done_callback(self.digital_output_service_response)

    def digital_output_service_response(self, future):
        try:
            if future.result().success:
                self.get_logger().info("Digital output set successfully!")
            else:
                self.get_logger().warn("Failed to set digital output")
        except Exception as e:
            self.get_logger().error(f"Digital service failed: {e}")

    def shutdown(self):
        self.get_logger().info("Shutting down and resetting outputs...")
        self.set_analog_output(index=1, value=0.0)
        self.set_digital_output(index=2, value=0)
        self.set_digital_output(index=3, value=0)

    def sub_control_active_callback(self, msg): self.light_control_active = msg.data
    def sub_control_freeze_callback(self, msg): self.light_control_freeze = msg.data
    def sub_control_manual_mode_callback(self, msg): self.manual_mode_active = msg.data
    def sub_manual_control_callback(self, msg):
        percent = max(0.0, min(100.0, msg.data))
        self.manual_voltage = 2.0 + (percent / 100.0) * 8.0
    def sub_desired_brightness_callback(self, msg):
        self.desired_brightness = msg.data
        self.get_logger().info(f"New desired brightness: {self.desired_brightness}")

def main(args=None):
    rclpy.init(args=args)
    node = LightController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.shutdown()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
