import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis
from kr_msgs.srv import GetRobotPose
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.msg import JogLinear
import numpy as np


class MoveTcpAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('MoveTcpAlongAxis_action_server')
        self.get_logger().info("Initializing Action Server")

        # Init des Action Servers
        self._action_server = ActionServer(
            self,
            MoveTcpAlongAxis,
            'move_tcp_along_axis',
            self.execute_callback
        )

        # Client für GetRobotPose
        self.get_robot_pose_client = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.get_robot_pose_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("Waiting for Kassow Robot services...")
        self.get_logger().info("GetRobotPose service available!")

        # Client für SelectJoggingFrame
        self.set_jogging_frame_client = self.create_client(SelectJoggingFrame, 'kr/motion/select_jogging_frame')
        while not self.set_jogging_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("Waiting for Kassow Robot services...")
        self.get_logger().info("SelectJoggingFrame service available!")

        # Publisher Move Linear Kassow
        self.jog_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

        self.pos = None
        self.rot = None
        self.jconf = None
        self.axis_idx = None
        self.dest_pos = None
        self.frame_idx = None
        self.actual_pos_diff = None
        self.abs_diff_pos = None
        self.tolerance = 0.5
        self.init_pos = None
        self.init_rot = None
        self.end_pos = None
        self.end_rot = None

    def execute_callback(self, goal_handle):
        self.get_logger().info("Starting TCP movement")

        if goal_handle.is_cancel_requested:
            self.get_logger().info("Action canceled by client.")

        try:
            self.reset_variables()

            self.baseline = goal_handle.request.baseline
            self.movement_frame = goal_handle.request.movement_frame
            self.movement_axis = goal_handle.request.movement_axis
            self.speed_in_mm_per_s = goal_handle.request.speed_in_mm_per_s

            pose_client_request = GetRobotPose.Request()
            future = self.get_robot_pose_client.call_async(pose_client_request)
            rclpy.spin_until_future_complete(self, future)
            response = future.result()

            if not response.success:
                self.get_logger().warn("Failed to get robot pose.")
                goal_handle.abort()
                return MoveTcpAlongAxis.Result(success=False)

            self.set_pos(response)
            self.get_logger().info(f"Start Pose: {self.pos}")

            self.get_axis_idx()
            self.get_frame_idx()
            self.select_frame()
            self.calc_destination_pose()
            self.get_logger().info(f"Destination Pose: {self.dest_pos}")

            goal_reached = False

            while True:
                if goal_handle.is_cancel_requested:
                    self.get_logger().info("Goal canceled by the client.")
                    goal_handle.canceled()
                    self.jog_publisher.destroy()
                    self.jog_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
                    return MoveTcpAlongAxis.Result(success=False)

                future = self.get_robot_pose_client.call_async(pose_client_request)
                while not future.done():
                    rclpy.spin_once(self, timeout_sec=0.1)
                response = future.result()

                if not response.success:
                    self.get_logger().warn("Failed to get robot pose.")
                    continue

                self.set_pos(response)
                self.calc_diff()
                self.calc_abs_dist()

                action_feedback = MoveTcpAlongAxis.Feedback()
                action_feedback.current_diff = self.abs_diff_pos
                goal_handle.publish_feedback(action_feedback)

                if abs(self.abs_diff_pos) <= self.tolerance:
                    self.get_logger().info("Target position reached!")
                    goal_reached = True
                    break

                self.set_velocity()
                self.publish_velocity()

            if goal_reached:
                goal_handle.succeed()
                return MoveTcpAlongAxis.Result(success=True)
        
        except Exception as e:
            self.get_logger().info(f"Error during execution: {e}")
        finally:
            self.reset_variables()
            self.get_logger().info("Callback execution finished!")


    def select_frame(self):
        request = SelectJoggingFrame.Request()
        request.ref = self.frame_idx
        future = self.set_jogging_frame_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            response = future.result()
            if response.success:
                self.get_logger().info("Jogging Frame selected successfully!")
            else:
                self.get_logger().error("Jogging Frame Selection failed!")
        else:
            self.get_logger().error("Jogging Frame Selection failed!")


    def calc_exact_baseline(self):
        return np.sqrt((self.end_pos[0] - self.init_pos[0])**2 + 
                       (self.end_pos[1] - self.init_pos[1])**2 + 
                       (self.end_pos[2] - self.init_pos[2])**2)

    def reset_variables(self):
        self.pos = None
        self.rot = None
        self.jconf = None
        self.axis_idx = None
        self.dest_pos = None
        self.frame_idx = None
        self.actual_pos_diff = None
        self.abs_diff_pos = None

    def publish_velocity(self):
        msg = JogLinear()
        msg.vel = self.actual_vel
        msg.rot = self.actual_rot
        self.jog_publisher.publish(msg)

    def set_velocity(self):
        self.actual_vel = [0.0, 0.0, 0.0]
        self.actual_vel[self.axis_idx] = self.speed_in_mm_per_s * (self.baseline / (abs(self.baseline)))
        self.actual_rot = [0.0, 0.0, 0.0]

    def calc_abs_dist(self):
        self.abs_diff_pos = np.sqrt((self.dest_pos[0] - self.pos[0])**2 + (self.dest_pos[1] - self.pos[1])**2 + (self.dest_pos[2] - self.pos[2])**2)

    def set_pos(self, srv_response):
        self.pos = [srv_response.pos[0], srv_response.pos[1], srv_response.pos[2]]
        self.rot = [srv_response.rot[0], srv_response.rot[1], srv_response.rot[2]]
        self.jconf = [srv_response.jsconf[0], srv_response.jsconf[1], srv_response.jsconf[2]]
    
    def get_axis_idx(self):
        if self.movement_axis == 'axis_x':
            self.axis_idx = 0
        elif self.movement_axis == 'axis_y':
            self.axis_idx = 1
        elif self.movement_axis == 'axis_z':
            self.axis_idx = 2

    def calc_diff(self):
        self.actual_pos_diff = np.array(self.dest_pos) - np.array(self.pos)

    def calc_destination_pose(self):
        self.dest_pos = self.pos
        self.dest_pos[self.axis_idx] = self.pos[self.axis_idx] + self.baseline

    def get_frame_idx(self):
        if self.movement_frame == 'world':
            self.frame_idx = 0
        elif self.movement_frame == 'base':
            self.frame_idx = 1
        elif self.movement_frame == 'tcp':
            self.frame_idx = 2
        else:
            self.frame_idx = None

def main(args=None):
    rclpy.init(args=args)
    action_server_node = MoveTcpAlongAxisActionServer()

    try:
        while rclpy.ok():
            rclpy.spin_once(action_server_node, timeout_sec=0.1)
    except KeyboardInterrupt:
        action_server_node.get_logger().info("Shutting down Action Server.")
    finally:
        action_server_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()


