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

        success = self.ik_executor.call_move_ptp_service(
            pos=[111.38811176, 165.31722525, 792.60884063],
            rot=[-91.27098247, -30.92798873, 0.60895482],
            ref=0, 
            ttype=0, 
            tvalue=30.0, 
            bpoint=0, 
            btype=0, 
            bvalue=30.0, 
            sync=0.0, 
            chaining=0,
        )

        if success:
            self.get_logger().info("Bewegung erfolgreich ausgeführt.")
        else:
            self.get_logger().warn("Bewegung fehlgeschlagen oder abgebrochen.")


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
