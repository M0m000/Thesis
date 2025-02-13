import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import TransformAction
from geometry_msgs.msg import TransformStamped
from rclpy.executors import MultiThreadedExecutor

class TransformActionClient(Node):

    def __init__(self):
        super().__init__('transform_action_client')
        self._action_client = ActionClient(self, TransformAction, 'transform')
        self.goal_handle = None

    def send_goal(self, ref_frame, frame):
        goal_msg = TransformAction.Goal()
        goal_msg.ref_frame = ref_frame
        goal_msg.frame = frame

        # Warte darauf, dass der Action Server bereit ist
        self._action_client.wait_for_server()

        # Sende das Ziel an den Action Server
        self.goal_handle = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self.goal_handle.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if goal_handle.accepted:
            self.get_logger().info('Goal accepted')
            # Resultat anfordern
            result_future = goal_handle.get_result_async()
            result_future.add_done_callback(self.result_callback)
        else:
            self.get_logger().info('Goal rejected')

    def feedback_callback(self, feedback_msg):
        # Feedback verarbeiten
        self.get_logger().info(f"Feedback: {feedback_msg.feedback.status}")

    def result_callback(self, future):
        result = future.result().result
        if result:
            # Zeige das Ergebnis (Transformation) in der Konsole an
            self.get_logger().info(f"Received Transform: {result.transform}")
        else:
            self.get_logger().info("No result received")

def main(args=None):
    rclpy.init(args=args)
    action_client = TransformActionClient()

    # Sende die Anfrage für die Transformation
    action_client.send_goal("world", "work")

    # Starte den Client
    rclpy.spin(action_client)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
