import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetSystemFrame
from pynput import keyboard
from sensor_msgs.msg import Image
import numpy as np
from cv_bridge import CvBridge
from std_msgs.msg import Bool


class TransformationDelta(Node):
    def __init__(self):
        super().__init__('transformation_delta')
        
        self.declare_parameter('desired_frame', 'tcp')
        self.desired_frame = self.get_parameter('desired_frame').get_parameter_value().string_value
        self.declare_parameter('reference_frame', 'world')
        self.reference_frame = self.get_parameter('reference_frame').get_parameter_value().string_value

        self.snapshot_listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.snapshot_listener.start()

        self.transformation_delta_trigger = self.create_subscription(Bool, '/robot_control/transformation_delta_trigger', self.transformation_trigger_callback, 10)
        self.transformation_publisher = self.create_publisher(Image, '/robot_control/transformation_delta', 10)

        self.client_GetSystemFrame = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')
        
        self.timer_period = 0.01
        self.timer = self.create_timer(self.timer_period, self.call_service)

        self.trigger_time = 0.01
        self.trigger = self.create_timer(self.trigger_time, self.on_trigger)

        self.transform1_trans = None
        self.transform1_rot = None
        self.transform2_trans = None
        self.transform2_rot = None
        self.response_trans = None
        self.response_rot = None

        self.service_available = False
        self.flag = False
        self.trigger = False

        self.bridge = CvBridge()

        while not self.client_GetSystemFrame.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warten auf Service GetSystemFrame')
        self.service_available = True
    
    def transformation_trigger_callback(self, msg):
        self.trigger = msg.data

        if self.trigger:
            if self.service_available:
                try:
                    self.transform1_trans = self.response_trans
                    self.transform1_rot = self.response_rot
                    self.flag = True
                    self.get_logger().info(f"Gestartet!")

                except AttributeError:
                    self.get_logger().info(f"Press S to start snapshot.")
        

    def call_service(self):
        request = GetSystemFrame.Request()
        request.name = self.desired_frame
        request.ref = self.reference_frame

        future = self.client_GetSystemFrame.call_async(request)
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        try:
            response = future.result()
            self.response_trans = [response.pos[0], response.pos[1], response.pos[2]]
            self.response_rot = [response.rot[0], response.rot[1], response.rot[2]]

        except Exception as e:
            self.get_logger().error(f'Service-Call failed!: {e}')
    
    def on_press(self, key):
        if self.service_available:
            try:
                if key.char == 's' or key.char == 'S':
                    self.transform1_trans = self.response_trans
                    self.transform1_rot = self.response_rot
                    self.flag = True
                    self.get_logger().info(f"Gestartet!")

            except AttributeError:
                self.get_logger().info(f"Press S to start snapshot.")

    def on_release(self, key):
        pass
    
    def on_trigger(self):
        if self.flag:
            self.transform2_trans = self.response_trans
            self.transform2_rot = self.response_rot

            diff_vector = self.calc_diff()
            self.publish_result(diff_vector)
    
    def calc_diff(self):
        diff_trans = np.array(self.transform2_trans) - np.array(self.transform1_trans)
        diff_rot = np.array(self.transform2_rot) - np.array(self.transform1_rot)

        diff_vector = np.array([diff_trans, diff_rot])
        return diff_vector

    def publish_result(self, diff_vector):
        transformation_msg = self.bridge.cv2_to_imgmsg(diff_vector, encoding="passthrough")
        self.transformation_publisher.publish(transformation_msg)


def main(args=None):
    rclpy.init(args=args)
    node = TransformationDelta()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
