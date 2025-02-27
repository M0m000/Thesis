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
        self.dict_processor = DictReceiveProcessor(dual_cam_setup = False)
        
        # Erstelle einen Subscriber, der auf das 'hook_data' Topic hört
        self.subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.listener_callback, 10)
        self.subscription



    def listener_callback(self, msg):
        """
        Callback-Funktion, die aufgerufen wird, wenn eine Nachricht empfangen wird.
        Sie verarbeitet die Nachricht und speichert sie im Dictionary.
        """
        hooks_dict = self.dict_processor.process_hooks_dict(msg)
        if 'hook_1' in hooks_dict:
            self.get_logger().info(f"UV Tip: {hooks_dict['hook_1']['uv_tip']}")
            self.get_logger().info(f"Path Points: {hooks_dict['hook_1']['path_points']}")
            self.get_logger().info(f"UV Lowpoint: {hooks_dict['hook_1']['uv_lowpoint']}")
            self.get_logger().info(f"Path Points XYZ: {hooks_dict['hook_1']['path_points_xyz_in_camframe']}")



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
