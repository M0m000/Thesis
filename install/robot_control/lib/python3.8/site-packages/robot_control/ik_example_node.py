import rclpy
from rclpy.node import Node
from FC.FC_ik_interface import IK_Interface
from FC.FC_call_move_ptp_service import MovePTPServiceClient
import numpy as np

class IKExampleNode(Node):
    def __init__(self):
        super().__init__('ik_example_node')

        self.ptp_movement = MovePTPServiceClient()

        # Beispiel: Sende eine Zielpose nach 2 Sekunden
        self.timer = self.create_timer(2.0, self.send_example_request)

    def send_example_request(self):
        target_translation = [150.0, 420.0, 800.0]
        target_rotation = [-90.0, -60.0, 0.0]

        self.get_logger().info('Sende Beispiel-PTP-Request...')
        self.ptp_movement.call_move_ptp_service(
            pos = target_translation,
            rot = target_rotation,
            ttype = 0,
            tvalue = 30.0,
            bpoint = 0,
            btype = 0,
            bvalue = 30.0,
            sync = 0,
            chaining = 0,
        )

        self.timer.cancel()


def main(args=None):
    rclpy.init(args=args)
    node = IKExampleNode()
    
    # Spinne sowohl den Sender-Node als auch den eingebetteten Bewegungsknoten
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(node)
    # executor.add_node(node.ptp_node)
    executor.spin()

    # node.ptp_node.destroy_node()
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
