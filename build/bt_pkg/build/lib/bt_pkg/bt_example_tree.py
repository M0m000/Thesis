import rclpy
from rclpy.node import Node
import py_trees
from pynput import keyboard
import time

class WaitForKey(py_trees.behaviour.Behaviour):
    def __init__(self, name, key, logger=None):
        super().__init__(name)
        self.key = key
        self.key_pressed = False
        self.logger = logger

    def update(self):
        if self.key_pressed:
            self.logger.info(f"Key {self.key} pressed, moving to next node.")
            self.key_pressed = False
            return py_trees.common.Status.SUCCESS
        return py_trees.common.Status.RUNNING

    def on_key_press(self, key):
        """Callback function to be called when the key is pressed"""
        try:
            if key.char == self.key:
                self.key_pressed = True
            else:
                self.key_pressed = False
        except AttributeError:
            pass


class ExampleTree(Node):
    def __init__(self):
        super().__init__('bt_example_tree')
        self.get_logger().info("Behavior Tree Node gestartet.")
        
        # Erstelle den Baum
        self.tree = self.create_behavior_tree()

        # Timer für den Baumtick
        self.timer = self.create_timer(0.1, self.tick_tree)

        # Listener für Tasteneingaben
        self.listener = keyboard.Listener(on_press=self.on_key_press)
        self.listener.start()

    def create_behavior_tree(self):
        root = py_trees.composites.Sequence("Root Sequence")
        
        # WaitForKey-Instanzen
        wait_for_1 = WaitForKey("Wait for 1", key="1", logger=self.get_logger())
        wait_for_2 = WaitForKey("Wait for 2", key="2", logger=self.get_logger())
        
        # Kinder zum Wurzelknoten hinzufügen
        root.add_children([wait_for_1, wait_for_2])
        
        return root

    def tick_tree(self):
        self.tree.tick_once()

        tree_visualization = py_trees.display.ascii_tree(self.tree)
        self.get_logger().info("\n" + tree_visualization)

        if self.tree.status == py_trees.common.Status.SUCCESS:
            self.get_logger().info("Behaviour Tree completed successfully.")
            rclpy.shutdown()

    def on_key_press(self, key):
        """Callback für Tasteneingaben"""
        for child in self.tree.children:
            if isinstance(child, WaitForKey):
                child.on_key_press(key)


def main(args=None):
    rclpy.init(args=args)
    node = ExampleTree()
    rclpy.spin(node)

if __name__ == "__main__":
    main()
