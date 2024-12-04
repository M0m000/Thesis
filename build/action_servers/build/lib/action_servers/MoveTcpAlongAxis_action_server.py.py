import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from std_msgs.msg import Float64MultiArray
import numpy as np


class MoveTcpAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('MoveTcpAlongAxis_action_server')

        # Publisher für Twist-Befehle
        self.twist_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
        self.timer_period = 0.002
        self.timer = self.create_timer(self.timer_period, self.publish_callback)
        self.TwistPublisher_active = True

        # Bei Serverstart Stillstand
        self.ServerInit_movement()
        self.publish_callback()
        self.TwistPublisher_active = False

        # Subscriber für aktuelle Pose
        self.pose_subscriber = self.create_subscription(
            Float64MultiArray,
            '/robot/pose',
            self.pose_callback,
            10
        )

        # Variablen zur Speicherung der aktuellen Pose und Orientierung
        self.pos = [0.0, 0.0, 0.0]  # Position: x, y, z
        self.rot = [0.0, 0.0, 0.0]  # Orientierung: a, b, c

        # Initialisierung des Action Servers
        self._action_server = ActionServer(
            self,
            MoveTcpAlongAxis,
            'move_tcp_along_axis',
            self.execute_callback
        )

        # Client für SelectJoggingFrame
        self.client_SelectJoggingFrame = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.client_SelectJoggingFrame.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for Service Kassow: SelectJoggingFrame')
        self.get_logger().info(f"Service Kassow: SelectJoggingFrame available!")

    def pose_callback(self, msg):
        self.srv_pos = msg.data[:3]  # x, y, z aus den ersten drei Werten
        self.srv_rot = msg.data[3:]  # a, b, c aus den letzten drei Werten

    def ServerInit_movement(self):
        self.jog_msg = JogLinear()
        self.jog_msg.vel = [0.0, 0.0, 0.0]
        self.jog_msg.rot = [0.0, 0.0, 0.0]

    def execute_callback(self, goal_handle):
        self.TwistPublisher_active = True
        self.get_logger().info(f"Starting TCP movement")

        self.baseline = goal_handle.request.baseline
        self.movement_frame = goal_handle.request.movement_frame
        self.movement_axis = goal_handle.request.movement_axis
        self.speed_in_mm_per_s = goal_handle.request.speed_in_mm_per_s

        self.feedback_msg = MoveTcpAlongAxis.Feedback()

        # Bewegung starten
        self.set_frame()
        self.get_axis_index()

        # Startposition auslesen und Differenz berechnen
        self.startpos = self.pos
        self.startrot = self.rot
        self.pos_diff = self.calc_pose_diff()
        self.send_action_feedback(goal_handle)

        while abs(self.pos_diff) > 1e-3:  # Solange es eine nennenswerte Differenz gibt
            self.set_movement()
            self.publish_callback()
            self.pos_diff = self.calc_pose_diff()

        self.TwistPublisher_active = False
        result = MoveTcpAlongAxis.Result()
        result.success = True

        self.get_logger().info(f"Movement complete: Success = {result.success}")
        goal_handle.succeed()

        return result

    def set_frame(self):
        self.get_logger().info("Set Frame...")
        req = SelectJoggingFrame.Request()
        if self.movement_frame == 'world':
            req.ref = 0
        elif self.movement_frame == 'base':
            req.ref = 1
        elif self.movement_frame == 'tcp':
            req.ref = 2

        future = self.client_SelectJoggingFrame.call_async(req)
        future.add_done_callback(self.handle_response_Srv_SelectJoggingFrame)

    def handle_response_Srv_SelectJoggingFrame(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info("Robot Frame set successfully!")
        except Exception as e:
            self.get_logger().info(f"Service Call SelectJoggingFrame failed!")

    def get_axis_index(self):
        if self.movement_axis == 'axis_x':
            self.axis_idx = 0
        elif self.movement_axis == 'axis_y':
            self.axis_idx = 1
        elif self.movement_axis == 'axis_z':
            self.axis_idx = 2

        if self.baseline >= 0:
            self.movement_sign = 1
        else:
            self.movement_sign = -1

    def calc_pose_diff(self):
        diff_vector = (np.array(self.startpos) + np.array([self.baseline, self.baseline, self.baseline])) - np.array(self.pos)
        return diff_vector[self.axis_idx]

    def set_movement(self):
        vel = [0.0, 0.0, 0.0]
        for i in range(3):
            if i == self.axis_idx:
                vel[i] = self.movement_sign * self.speed_in_mm_per_s
            else:
                vel[i] = 0.0

        self.jog_msg.vel = vel
        self.jog_msg.rot = [0.0, 0.0, 0.0]

    def publish_callback(self):
        if self.TwistPublisher_active:
            self.twist_publisher.publish(self.jog_msg)

    def send_action_feedback(self, goal_handle):
        self.feedback_msg.current_position = self.pos
        self.feedback_msg.current_diff = self.pos_diff
        goal_handle.publish_feedback(self.feedback_msg)


def main(args=None):
    rclpy.init(args=args)

    MoveTcpAlongAxis_action_server = MoveTcpAlongAxisActionServer()

    rclpy.spin(MoveTcpAlongAxis_action_server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
