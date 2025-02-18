import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from kr_msgs.srv import SetDiscreteOutput
from kr_msgs.srv import SetAnalogOutput



class LightController(Node):
    def __init__(self):
        super().__init__('light_controller')

        # Subscriber auf VC Cam
        self.subscription = self.create_subscription(
            Image,
            'vcnanoz/image_raw',
            self.image_callback,
            1)
        self.subscription
        self.bridge = CvBridge()

        # Service Client SetDiscreteOutput
        self.set_dig_out_client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')
        while not self.set_dig_out_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SetDiscreteOutput...")
        self.get_logger().info("Service SetDiscreteOutput available!")

        # Service Client SetAnalogOutput
        self.set_analog_out_client = self.create_client(SetAnalogOutput, '/kr/iob/set_voltage_output')
        while not self.set_analog_out_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SetAnalogOutput...")
        self.get_logger().info("Service SetAnalogOutput available!")

        # Parameter für Regelung
        self.desired_brightness = 220
        self.current_voltage = 2.0
        self.K_p = 0.005
        self.K_i = 0.5
        self.integral = 0.0

        # Initiale spannungsversorgung und Helligkeitsregelung
        self.set_digital_output(index = 2, value = 1)     # Spannungsversorgung
        self.set_digital_output(index = 3, value = 1)     # Schalteingang
        self.set_analog_output(index = 1, value = self.current_voltage)     # Helligkeit auf 2V (minimal)

    
    def image_callback(self, msg):
        try:
            img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            brightness = np.mean(img)
            self.get_logger().info(f'Average brightness measured: {brightness}')

            # Regelabweichung berechnen
            e_brightness = self.desired_brightness - brightness
            control_signal = self.K_p * e_brightness                # P-Regler

            # Stellgröße berechnen und begrenzen
            self.current_voltage = max(2.0, min(10.0, self.current_voltage + control_signal))

            # Stellgröße setzen, wenn sich etwas geändert hat
            self.set_analog_output(index=1, value=self.current_voltage)

        except Exception as e:
            self.get_logger().error(f'Error in image processing: {e}')





    def set_analog_output(self, index = 1, value = 0.0):
        req = SetAnalogOutput.Request()
        req.index = index
        req.value = float(value)

        future = self.set_analog_out_client.call_async(request = req)
        future.add_done_callback(self.analog_output_service_response)

    def analog_output_service_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Analog output set to {self.current_voltage} successfully!")
            else:
                self.get_logger().warn("Failed to set analog output.")
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")


    def set_digital_output(self, index, value):
        req = SetDiscreteOutput.Request()
        req.index = index
        req.value = int(value)

        future = self.set_dig_out_client.call_async(request = req)
        future.add_done_callback(self.digital_output_service_response)

    def digital_output_service_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Digital output set successfully!")
            else:
                self.get_logger().warn("Failed to set digital output.")
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")


    def shutdown(self):
        self.get_logger().info("Shutting down... Resetting outputs to 0.")

        # Setze Analog Output auf 0V
        self.set_analog_output(index=1, value=0.0)

        # Setze Digital Outputs 2 & 3 auf 0
        self.set_digital_output(index=2, value=0)
        self.set_digital_output(index=3, value=0)


def main(args=None):
    rclpy.init(args=args)
    node = LightController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('shutting down Light Controller node...')
    finally:
        node.shutdown()  # Outputs zurücksetzen
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()

