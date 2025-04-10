import rclpy
from rclpy.node import Node
from FC.FC_call_move_ptp_service import MovePTPServiceClient

class IKExampleNode(Node):
    def __init__(self):
        super().__init__('ik_example_node')

        self.ik_executor = MovePTPServiceClient()
        self.timer = self.create_timer(2.0, self.send_example_request)

    def send_example_request(self):
        self.get_logger().info('Sende Beispiel-PTP-Request...')
        try:
            self.ik_executor.move_to_pose(
                pos=[400.0, 620.0, 800.0],
                rot=[-90.0, -60.0, 0.0]
            )
            self.get_logger().info("Bewegung erfolgreich ausgeführt.")
        except Exception as e:
            self.get_logger().error(f"Fehler bei Bewegung: {str(e)}")

        self.timer.cancel()

    def shutdown(self):
        self.ik_executor.destroy_node()
        self.destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = IKExampleNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.shutdown()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

