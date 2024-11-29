import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis  # Dein Action-Typ

class MoveTcpAlongAxisActionClient(Node):

    def __init__(self):
        super().__init__('move_tcp_along_axis_action_client')
        self._action_client = ActionClient(self, MoveTcpAlongAxis, 'move_tcp_along_axis')

    def send_goal(self, baseline, movement_frame, movement_axis):
        # Erstelle das Ziel (Goal) für die Action
        goal_msg = MoveTcpAlongAxis.Goal()
        goal_msg.baseline = baseline
        goal_msg.movement_frame = movement_frame
        goal_msg.movement_axis = movement_axis

        # Warten, bis der Action-Server verfügbar ist
        self._action_client.wait_for_server()

        # Sende das Ziel an den Server und füge eine Callback-Funktion für Feedback hinzu
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )

        # Füge eine Callback-Funktion hinzu, um das Ergebnis nach Abschluss zu erhalten
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()

        # Überprüfen, ob das Ziel akzeptiert wurde
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        # Warte auf das Ergebnis der Aktion
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        # Hol das Ergebnis des Action-Servers
        result = future.result().result
        self.get_logger().info('Result: Success = {0}'.format(result.success))
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        # Diese Methode wird aufgerufen, wenn der Server Feedback sendet
        feedback = feedback_msg.feedback
        self.get_logger().info('Received feedback: Current position = {0}'.format(feedback.current_position))


def main(args=None):
    rclpy.init(args=args)

    # Erstelle den Action-Client
    action_client = MoveTcpAlongAxisActionClient()

    # Sende das Ziel (z.B. Baseline=0.0, Koordinatensystem="tcp", Achse="x")
    action_client.send_goal(0.0, "tcp", "x")

    # Warten, bis alle asynchronen Prozesse abgeschlossen sind
    rclpy.spin(action_client)


if __name__ == '__main__':
    main()
