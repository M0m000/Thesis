import rclpy
from rclpy.node import Node
from FC.FC_ik_interface import IK_Interface
import numpy as np

class IKExampleNode(Node):
    def __init__(self):
        super().__init__('ik_example_node')

        # PTPMovementNode als Attribut dieser Klasse instanziieren
        self.ptp_node = IK_Interface()

        # Beispiel: Sende eine Zielpose nach 2 Sekunden
        self.timer = self.create_timer(2.0, self.send_example_request)

    def send_example_request(self):
        target_translation = [100.0, 400.0, 800.0]
        target_rotation = [-90.0, -60.0, 0.0]

        self.get_logger().info('Sende Beispiel-PTP-Request...')
        self.ptp_node.send_request(
            target_trans_in_worldframe=target_translation,
            target_rot_in_worldframe=target_rotation
        )

        self.timer.cancel()


def main(args=None):
    rclpy.init(args=args)
    node = IKExampleNode()

    # Spinne sowohl den Sender-Node als auch den eingebetteten Bewegungsknoten
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(node)
    executor.add_node(node.ptp_node)
    executor.spin()

    node.ptp_node.destroy_node()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
