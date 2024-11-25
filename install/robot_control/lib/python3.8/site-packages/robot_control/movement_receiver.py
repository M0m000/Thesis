import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetSystemFrame
from pynput import keyboard
from sensor_msgs.msg import Image



class TransformationSnapshot(Node):
    def __init__(self):
        super().__init__('transformation_snapshot')

        self.declare_parameter('desired_frame', 'tcp')
        self.desired_frame = self.get_parameter('desired_frame').get_parameter_value().string_value
        self.declare_parameter('reference_frame', 'world')
        self.reference_frame = self.get_parameter('reference_frame').get_parameter_value().string_value

        self.snapshot_listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.snapshot_listener.start()

        self.transformation_publisher = self.create_publisher(Image, 'robot_control/transformation_snapshot', 10)

        self.client_GetSystemFrame = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warten auf Service GetSystemFrame')
        self.send_request()

        self.flag = False
        self.transform1_trans = None
        self.transform1_rot = None
        self.transform2_trans = None
        self.transform2_rot = None

    def on_press(self, key):
        try:
            if key.char == 's' and not self.flag:
                self.get_logger().info(f"Snapshot started! Now move TCP and press S again.")
                self.transform1_trans, self.transform1_rot = self.call_service()
                self.flag = True

            if key.char == 's' and self.flag:
                self.get_logger().info(f"Snapshot done!")
                self.transform2_trans, self.transform2_rot = self.call_service()
                diff_vector = self.calc_transformation()
                self.publish_result(diff_vector)
                self.flag = False

        except AttributeError:
            self.get_logger().info(f"Press S to start snapshot.")

    def calc_transformation(self):
        diff_trans = self.transform2_trans - self.transform1_trans
        diff_rot = self.transform2_rot - self.transform1_rot
        print(type(diff_trans))
        print(type(diff_rot))
        diff_vector = None
        return diff_vector
    
    def publish_result(self, diff_vector):
        transformation_msg = self.bridge.cv2_to_imgmsg(self.diff_vector, encoding="passthrough")
        self.transformation_publisher.publish(transformation_msg)

    def call_service(self):
        request = GetSystemFrame.Request()
        request.name = self.desired_frame
        request.ref = self.reference_frame

        future = self.client.call_async(request)
        response_trans, response_rot = future.add_done_callback(self.handle_response)
        return response_trans, response_rot

    def handle_response(self, future):
        try:
            response = future.result()
            return response.pos, response.rot
        except Exception as e:
            self.get_logger().error(f'Service-Call failed!: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = TransformationSnapshot()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

