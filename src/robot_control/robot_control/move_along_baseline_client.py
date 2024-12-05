import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import MoveAlongBaseline


class MoveAlongBaselineClient(Node):

    def __init__(self):
        super().__init__('move_along_baseline_client')
        self._action_client = ActionClient(self, MoveAlongBaseline, 'move_along_baseline')

    def send_goal(self, baseline):
        # Zielnachricht erstellen
        goal_msg = MoveAlongBaseline.Goal()
        goal_msg.baseline = baseline

        # Auf Server warten
        self.get_logger().info('Warte auf Action-Server...')
        self._action_client.wait_for_server()

        # Ziel senden
        self.get_logger().info(f'Sende Ziel: Strecke {baseline} mm')
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        # Zielannahme prüfen
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Ziel wurde abgelehnt.')
            return

        self.get_logger().info('Ziel wurde akzeptiert.')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.result_callback)

    def feedback_callback(self, feedback_msg):
        # Feedback verarbeiten
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Aktuelle x-Position: {feedback.current_x} mm')

    def result_callback(self, future):
        # Ergebnis erhalten
        result = future.result().result
        if result.success:
            self.get_logger().info(f'Aktion erfolgreich: {result.message}')
        else:
            self.get_logger().info(f'Aktion fehlgeschlagen: {result.message}')
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    # Client-Knoten erstellen
    action_client = MoveAlongBaselineClient()

    # Ziel-Strecke in x-Richtung definieren
    baseline = 50.0  # Strecke in mm

    # Ziel senden
    action_client.send_goal(baseline)

    # Spin, bis der Prozess abgeschlossen ist
    rclpy.spin(action_client)


if __name__ == '__main__':
    main()
