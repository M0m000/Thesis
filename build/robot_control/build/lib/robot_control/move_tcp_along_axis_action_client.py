import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from kr_msgs.action import MoveTCPAlongAxis  # Importiere die neue Action-Datei

class MoveTCPAlongAxisActionClient(Node):

    def __init__(self):
        super().__init__('move_tcp_along_axis_action_client')
        self._action_client = ActionClient(self, MoveTCPAlongAxis, 'move_tcp_along_axis')

    def send_goal(self):
        goal_msg = MoveTCPAlongAxis.Goal()
        goal_msg.baseline = 1.23
        goal_msg.movement_frame = 'frame_1'
        goal_msg.movement_axis = 'x'

        # Sende das Ziel und setze Rückruf für Feedback
        future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        future.add_done_callback(self.goal_response_callback)

    def feedback_callback(self, feedback):
        self.get_logger().info(f'Current time: {feedback.current_time}')

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if goal_handle.accepted:
            self.get_logger().info('Goal accepted!')
        else:
            self.get_logger().info('Goal rejected!')

def main(args=None):
    rclpy.init(args=args)
    action_client = MoveTCPAlongAxisActionClient()
    action_client.send_goal()

    rclpy.spin(action_client)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
