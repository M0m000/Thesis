import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis

class MoveTcpAlongAxisActionClient(Node):

    def __init__(self):
        super().__init__('move_tcp_along_axis_action_client')
        self._action_client = ActionClient(self, MoveTcpAlongAxis, 'move_tcp_along_axis')

    def send_goal(self, baseline, movement_frame, movement_axis, speed):
        goal_msg = MoveTcpAlongAxis.Goal()
        goal_msg.baseline = baseline
        goal_msg.movement_frame = movement_frame
        goal_msg.movement_axis = movement_axis
        goal_msg.speed_in_mm_per_s = speed

        # Warte darauf, dass der Server verfügbar ist
        if not self._action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().info("Server is not available after waiting.")
            return

        # Sende das Ziel und registriere die Rückrufe
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

        # Spin und warte auf den Abschluss der Anfrage
        rclpy.spin_until_future_complete(self, self._send_goal_future)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Feedback - Current Position: {0}'.format(feedback.current_position))
        self.get_logger().info('Feedback - Current Difference: {0}'.format(feedback.current_diff))

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('ERROR - Movement request rejected!')
            return

        self.get_logger().info('Movement request accepted!')

        # Hole das Ergebnis des Ziels und registriere den Rückruf
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Movement successful!' if result.success else 'Movement ERROR!')
        # Hier erfolgt kein rclpy.shutdown() mehr

def main(args=None):
    rclpy.init(args=args)
    action_client = MoveTcpAlongAxisActionClient()

    try:
        # Sende ein Ziel und warte auf das Ergebnis
        action_client.send_goal(baseline=50.0, movement_frame="tcp", movement_axis="axis_x", speed=20.0)
    except Exception as e:
        action_client.get_logger().error(f"Error during action: {e}")
    finally:
        rclpy.shutdown()  # Eventloop ordnungsgemäß beenden

if __name__ == '__main__':
    main()
