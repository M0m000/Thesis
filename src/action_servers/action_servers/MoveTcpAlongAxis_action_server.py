import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis
from kr_msgs.msg import FollowLinear
from kr_msgs.srv import GetRobotPose
from kr_msgs.srv import SelectJoggingFrame
import numpy as np


class MoveTcpAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('MoveTcpAlongAxis_action_server')

        # Publisher Move Linear Kassow
        self.twist_publisher = self.create_publisher(FollowLinear, '/kr/motion/follow_linear', 10)
        self.timer_period = 0.002
        self.timer = self.create_timer(self.timer_period, self.publish_callback)

        # Init des Action Servers
        self._action_server = ActionServer(
            self,
            MoveTcpAlongAxis,
            'move_tcp_along_axis',
            self.execute_callback
        )

        self.get_robot_pose_client = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.get_robot_pose_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service "Get Robot Pose" nicht verfügbar, warte...')
        self.get_logger().info('Service "Get Robot Pose" verfügbar.')


        self.activate_publisher = False
        self.pos = None
        self.rot = None
        self.jconf = None
        self.axis_idx = None
        self.dest_pos = None


    def execute_callback(self, goal_handle):
        self.get_logger().info(f"Starting TCP movement")

        self.baseline = goal_handle.request.baseline
        self.movement_frame = goal_handle.request.movement_frame
        self.movement_axis = goal_handle.request.movement_axis
        self.speed_in_mm_per_s = goal_handle.request.speed_in_mm_per_s

        self.feedback_msg = MoveTcpAlongAxis.Feedback()

        self.get_robot_pose()
        print(self.pos)
        self.get_axis_idx()
        self.calc_destination_pose()
        print(self.dest_pos)

        # Publish der Ziel-Pose auf Topic
        self.activate_publisher = True


        goal_handle.succeed()
        self.activate_publisher = False
        result = MoveTcpAlongAxis.Result()
        result.success = True
        return result
    

    def get_axis_idx(self):
        if self.movement_axis == 'axis_x':
            self.axis_idx = 0
        elif self.movement_axis == 'axis_y':
            self.axis_idx = 1
        elif self.movement_axis == 'axis_z':
            self.axis_idx = 2


    def calc_destination_pose(self):
        self.dest_pos = self.pos
        self.dest_pos[self.axis_idx] = self.pos[self.axis_idx] + self.baseline
    

    def get_robot_pose(self):
        request = GetRobotPose.Request()
        future = self.get_robot_pose_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            robot_pose = future.result()
            self.pos = [robot_pose.pos[0], robot_pose.pos[1], robot_pose.pos[2]]
            self.rot = [robot_pose.rot[0], robot_pose.rot[1], robot_pose.rot[2]]
            self.jconf = [robot_pose.jsconf[0],
                          robot_pose.jsconf[1],
                          robot_pose.jsconf[2],
                          robot_pose.jsconf[3],
                          robot_pose.jsconf[4],
                          robot_pose.jsconf[5],
                          robot_pose.jsconf[6]]
        else:
            self.get_logger().error("Service call failed")


    def publish_callback(self):
        pass



def main(args=None):
    rclpy.init(args=args)
    MoveTcpAlongAxis_action_server = MoveTcpAlongAxisActionServer()
    rclpy.spin(MoveTcpAlongAxis_action_server)

if __name__ == '__main__':
    main()
    