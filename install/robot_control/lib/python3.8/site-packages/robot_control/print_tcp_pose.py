import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetRobotPose

class PrintTCPPose(Node):
    def __init__(self):
        super().__init__('print_tcp_pose')

        self.client = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')      # Service Client

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warten auf den Service /kr/robot/get_robot_pose...')

        self.timer_period = 0.2
        self.timer = self.create_timer(self.timer_period, self.call_service)

    def call_service(self):
        request = GetRobotPose.Request()

        future = self.client.call_async(request)
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        try:
            response = future.result()
            print()
            self.get_logger().info(f'TCP Pos in mm: {response.pos}')
            print()
            self.get_logger().info(f'TCP Rot in degree: {response.rot}')
            print()
            self.get_logger().info(f'Joint configuration: {response.jsconf}')
            print()
        except Exception as e:
            self.get_logger().error(f'Service-Aufruf fehlgeschlagen: {e}')

def main(args=None):
    rclpy.init(args=args)
    robot_pose_client = PrintTCPPose()
    rclpy.spin(robot_pose_client)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
