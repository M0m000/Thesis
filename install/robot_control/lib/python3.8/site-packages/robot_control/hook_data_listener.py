import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_dict_receive_processing import DictReceiveProcessor

class HookDataListener(Node):
    def __init__(self):
        """
        Initialisiert den Node, der auf das HookData-Topic hört und die Nachrichten verarbeitet.
        """
        super().__init__('hook_data_listener')
        
        # Initialisiere den DictReceiveProcessor, der das Entpacken und Speichern übernimmt
        self.dict_processor = DictReceiveProcessor(self)
        
        # Erstelle einen Subscriber, der auf das 'hook_data' Topic hört
        self.subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.listener_callback, 10)
        self.subscription



    def listener_callback(self, msg):
        """
        Callback-Funktion, die aufgerufen wird, wenn eine Nachricht empfangen wird.
        Sie verarbeitet die Nachricht und speichert sie im Dictionary.
        """
        hooks_dict = self.dict_processor.process_hooks_dict(msg)
        self.get_logger().info(f"Verarbeitetes Dictionary: {hooks_dict}")



def main(args=None):
    rclpy.init(args=args)

    node = HookDataListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
