import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetSystemFrame
from pynput import keyboard
from sensor_msgs.msg import Image
import numpy as np
from cv_bridge import CvBridge



class TransformationSnapshot(Node):
    def __init__(self):
        super().__init__('transformation_snapshot')

        self.declare_parameter('desired_frame', 'tcp')
        self.desired_frame = self.get_parameter('desired_frame').get_parameter_value().string_value
        self.declare_parameter('reference_frame', 'world')
        self.reference_frame = self.get_parameter('reference_frame').get_parameter_value().string_value

        self.snapshot_listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.snapshot_listener.start()

        self.transformation_publisher = self.create_publisher(Image, '/robot_control/transformation_snapshot', 10)

        self.client_GetSystemFrame = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')
        
        self.timer_period = 0.2
        self.timer = self.create_timer(self.timer_period, self.call_service)

        self.transform1_trans = None
        self.transform1_rot = None
        self.transform2_trans = None
        self.transform2_rot = None
        self.response_trans = None
        self.response_rot = None
        self.service_available = False

        self.bridge = CvBridge()

        while not self.client_GetSystemFrame.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warten auf Service GetSystemFrame')
        self.service_available = True

    def on_press(self, key):
        if self.service_available:
            try:
                if key.char == 's' or key.char == 'S':
                    self.transform1_trans = self.response_trans
                    self.transform1_rot = self.response_rot

                    self.get_logger().info(f"Snapshot started! Now move TCP and press D.")

                if key.char == 'd' or key.char == 'D':
                    self.transform2_trans = self.response_trans
                    self.transform2_rot = self.response_rot

                    diff_vector = self.calc_transformation()
                    self.publish_result(diff_vector)
                    

            except AttributeError:
                self.get_logger().info(f"Press S to start snapshot.")

    def on_release(self, key):
        pass

    def calc_transformation(self):
        diff_trans = np.array(self.transform2_trans) - np.array(self.transform1_trans)
        diff_rot = np.array(self.transform2_rot) - np.array(self.transform1_rot)

        diff_vector = np.array([diff_trans, diff_rot])
        return diff_vector
    
    def publish_result(self, diff_vector):
        transformation_msg = self.bridge.cv2_to_imgmsg(diff_vector, encoding="passthrough")
        self.transformation_publisher.publish(transformation_msg)
        self.get_logger().info(f"Snapshot done!")

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


def main(args=None):
    rclpy.init(args=args)
    node = TransformationSnapshot()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

