import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetRobotPose
from std_msgs.msg import Float64MultiArray

class RobotTcpPoseNode(Node):
    def __init__(self):
        super().__init__('robot_TcpPose_node')

        self.client_GetRobotPose = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.client_GetRobotPose.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warten auf Service GetRobotPose')

        self.timer_period = 0.001  # 1 Millisekunde
        self.timer = self.create_timer(self.timer_period, self.call_service)
        self.pose_publisher = self.create_publisher(Float64MultiArray, '/robot/pose', 10)

    def call_service(self):
        request = GetRobotPose.Request()
        future = self.client_GetRobotPose.call_async(request)
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        try:
            response = future.result()

            pose_vector = Float64MultiArray()
            pose_vector.data = [
                response.pos[0], response.pos[1], response.pos[2],  # x, y, z (Position)
                response.rot[0], response.rot[1], response.rot[2]   # a, b, c (Rotation)
            ]

            self.pose_publisher.publish(pose_vector)
            self.get_logger().info(f"Published Pose Vector: {pose_vector.data}")

        except Exception as e:
            self.get_logger().error(f'Service-Call failed!: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = RobotTcpPoseNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
