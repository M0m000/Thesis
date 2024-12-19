import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetRobotPose
from std_msgs.msg import Float64MultiArray, Header


class GetRobotPoseNode(Node):

    def __init__(self):
        super().__init__('get_robot_pose_node')

        self.get_robot_pose_client = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')

        while not self.get_robot_pose_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("Waiting for GetRobotPose service...")

        self.get_logger().info("GetRobotPose service available!")

        self.pose_publisher = self.create_publisher(Float64MultiArray, '/robot/pose', 10)

        self.update_robot_pose()

    def update_robot_pose(self):
        request = GetRobotPose.Request()

        while rclpy.ok():
            future = self.get_robot_pose_client.call_async(request)
            rclpy.spin_until_future_complete(self, future)

            response = future.result()

            if response.success:
                pose_msg = Float64MultiArray()
                pose_msg.data = [
                    response.pos[0], response.pos[1], response.pos[2],
                    response.rot[0], response.rot[1], response.rot[2],
                    *response.jsconf
                ]
                
                self.pose_publisher.publish(pose_msg)
                self.get_logger().info(f"Published Robot Pose: {pose_msg.data}")
            else:
                self.get_logger().warn("Failed to get robot pose.")
            
            rclpy.spin_once(self)


def main(args=None):
    rclpy.init(args=args)
    node = GetRobotPoseNode()
    rclpy.spin(node)


if __name__ == '__main__':
    main()
