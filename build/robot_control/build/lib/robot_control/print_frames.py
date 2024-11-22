import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetSystemFrame

class PrintFrames(Node):
    def __init__(self):
        super().__init__('print_frames')

        self.declare_parameter('desired_frame', 'tcp')
        self.desired_frame = self.get_parameter('desired_frame').get_parameter_value().string_value

        self.declare_parameter('reference_frame', 'world')
        self.reference_frame = self.get_parameter('reference_frame').get_parameter_value().string_value

        self.client = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')      # Service Client

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warten auf den Service /kr/robot/get_robot_pose...')

        self.timer_period = 0.2
        self.timer = self.create_timer(self.timer_period, self.call_service)

    def call_service(self):
        request = GetSystemFrame.Request()
        request.name = self.desired_frame
        request.ref = self.reference_frame

        future = self.client.call_async(request)
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"Position: {response.pos}     Rotation: {response.rot}")
        except Exception as e:
            self.get_logger().error(f'Service-Aufruf fehlgeschlagen: {e}')

def main(args=None):
    rclpy.init(args=args)
    robot_pose_client = PrintFrames()
    rclpy.spin(robot_pose_client)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
