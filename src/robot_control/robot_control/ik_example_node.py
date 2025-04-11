import rclpy
from rclpy.node import Node
from FC.FC_call_move_ptp_service import MovePTPServiceClient

class IKExampleNode(Node):
    def __init__(self):
        super().__init__('ik_example_node')

        self.ik_executor = MovePTPServiceClient()

        self.send_example_request()

    def send_example_request(self):
        self.get_logger().info('Sende Beispiel-PTP-Request...')
        try:
            self.ik_executor.move_to_pose(
                pos=[111.38811176, 165.31722525, 792.60884063],
                rot=[-91.27098247, -30.92798873, 0.60895482]
            )
            self.get_logger().info("Bewegung erfolgreich ausgeführt.")
        except Exception as e:
            self.get_logger().error(f"Fehler bei Bewegung: {str(e)}")


    def shutdown_node(self):
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
        node.shutdown_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
