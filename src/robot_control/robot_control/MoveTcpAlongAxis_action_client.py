import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis  # Der Action-Typ

class MoveTcpAlongAxisActionClient(Node):

    def __init__(self):
        super().__init__('move_tcp_along_axis_action_client')
        self._action_client = ActionClient(self, MoveTcpAlongAxis, 'move_tcp_along_axis')

    def send_goal(self, baseline, movement_frame, movement_axis):
        goal_msg = MoveTcpAlongAxis.Goal()
        goal_msg.baseline = baseline
        goal_msg.movement_frame = movement_frame
        goal_msg.movement_axis = movement_axis

        self._action_client.wait_for_server()

        goal_handle = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        return goal_handle

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        print(feedback)
        self.get_logger().info('Received feedback: {0}'.format(feedback.current_position))

def main(args=None):
    rclpy.init(args=args)

    action_client = MoveTcpAlongAxisActionClient()
    goal_handle = action_client.send_goal(0.0, "tcp", "axis_x")
    result = goal_handle.result()  # Jetzt erhalten wir das Ergebnis

    rclpy.shutdown()

if __name__ == '__main__':
    main()
