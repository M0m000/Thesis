import rclpy
from rclpy.node import Node
from pynput import keyboard  # Modul für Tastatureingaben
from FC.FC_gripper_handler import GripperHandler
from FC.FC_geometrics_handler import GeometricsHandler

class DummyNode(Node):
    def __init__(self):
        super().__init__('_dummy_node')

        self.geometrics_handler = GeometricsHandler()
        self.hook = self.geometrics_handler.get_hook_of_global_scan_dict(hook_num=2)
        self.geometrics_handler.update_hook_data(hook_num=1)
        self.geometrics_handler.calculate_hook_line()

        self.gripper_handler = GripperHandler()

        self.get_logger().info("Drücke 'c' zum Schließen des Greifers, 'v' zum Öffnen. 'q' zum Beenden.")

        # Tastatur-Listener starten
        self.listener = keyboard.Listener(on_release=self.on_key_press)
        self.listener.start()

    def on_key_press(self, key):
        """ Wird aufgerufen, wenn eine Taste gedrückt wird """
        try:
            if key.char == 'c':  # Greifer schließen
                self.get_logger().info("Schließe den Greifer...")
                self.create_task(self.gripper_handler.close_gripper)

            elif key.char == 'v':  # Greifer öffnen
                self.get_logger().info("Öffne den Greifer...")
                self.create_task(self.gripper_handler.open_gripper)

            elif key.char == 'q':  # Programm beenden
                self.get_logger().info("Beende das Programm...")
                self.listener.stop()
                rclpy.shutdown()

        except AttributeError:
            pass  # Sondertasten ignorieren

    def create_task(self, function):
        """ Führt eine ROS-Funktion sicher im ROS-Executor aus """
        future = self.executor.create_task(function)
        future.add_done_callback(self.task_callback)

    def task_callback(self, future):
        """ Callback-Funktion für abgeschlossene Tasks """
        try:
            result = future.result()
            self.get_logger().info(f"Task abgeschlossen: {result}")
        except Exception as e:
            self.get_logger().error(f"Task-Fehler: {e}")


            

def main(args=None):
    rclpy.init(args=args)
    node = DummyNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.listener.stop()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
