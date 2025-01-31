import rclpy
from rclpy.action import ActionClient
from action_interfaces.action import TransformAction
from geometry_msgs.msg import TransformStamped
from rclpy.node import Node

class TransformActionClient(Node):

    def __init__(self):
        super().__init__('transform_action_client')
        self._action_client = ActionClient(self, TransformAction, 'transform')
        self.goal_handle = None
        self.world_to_work_transform = None

    def send_goal(self, ref_frame, frame, result_callback, feedback_callback=None):
        goal_msg = TransformAction.Goal()
        goal_msg.ref_frame = ref_frame
        goal_msg.frame = frame

        # Warte darauf, dass der Action Server bereit ist
        self._action_client.wait_for_server()

        # Sende das Ziel an den Action Server
        goal_handle_future = self._action_client.send_goal_async(goal_msg, feedback_callback=feedback_callback)
        goal_handle_future.add_done_callback(lambda future: self.goal_response_callback(future, result_callback))

    def goal_response_callback(self, future, result_callback):
        goal_handle = future.result()
        if goal_handle.accepted:
            self.get_logger().info('Goal accepted')
            # Resultat anfordern
            result_future = goal_handle.get_result_async()
            result_future.add_done_callback(lambda future: self.result_callback(future, result_callback))
        else:
            self.get_logger().info('Goal rejected')

    def result_callback(self, future, result_callback):
        result = future.result().result
        if result:
            self.world_to_work_transform = result.transform
            self.get_logger().info(f"Received Transform: {self.world_to_work_transform}")
            result_callback(self.world_to_work_transform)  # Rückgabe des Ergebnisses
        else:
            self.get_logger().info("No result received")
