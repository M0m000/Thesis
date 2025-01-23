import rclpy
from rclpy.node import Node
from kr_msgs.msg import SystemState  # Importiere den Nachrichtentyp

class HelloNode(Node):
    def __init__(self):
        super().__init__('hello_node')
        # Abonniere das Topic /kr/system/state
        self.subscription = self.create_subscription(
            SystemState,
            '/kr/system/state',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        # Ausgabe von robot_state und robot_mode
        self.get_logger().info(f"Robot Mode: {msg.robot_mode}")
        self.get_logger().info(f"Robot State: {msg.robot_state}")
        self.get_logger().info(f"Sensed Position: {msg.sensed_pos}")

def main(args=None):
    rclpy.init(args=args)
    node = HelloNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
