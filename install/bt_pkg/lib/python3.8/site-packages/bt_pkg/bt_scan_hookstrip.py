import rclpy
from rclpy.node import Node
import py_trees
import time
from pynput import keyboard


class WaitForKey(py_trees.behaviour.Behaviour):
    def __init__(self, name, key, next_node=None, logger=None):
        super().__init__(name)
        self.key = key
        self.key_pressed = False
        self.logger = logger

    def update(self):
        if self.key_pressed:
            self.logger.info(f"Key {self.key} pressed, moving to next node.")
            self.key_pressed = False  # Reset the flag after processing the input
            return py_trees.common.Status.SUCCESS
        return py_trees.common.Status.RUNNING

    def on_key_press(self, key):
        """Callback function to be called when the key is pressed"""
        try:
            if key.char == self.key:
                self.key_pressed = True
            else:
                # Reset key_pressed if the wrong key was pressed
                self.key_pressed = False
        except AttributeError:
            pass


class WaitForKeyWithTimer(py_trees.behaviour.Behaviour):
    def __init__(self, name, key, next_node=None, timeout=20, logger=None):
        super().__init__(name)
        self.key = key
        self.timeout = timeout
        self.start_time = None
        self.key_pressed = False
        self.logger = logger
        self.waiting_for_input = False  # Flag für das Warten auf Tasteneingaben

    def update(self):
        if self.key_pressed and self.start_time is None:
            self.logger.info(f"Waiting for key {self.key} and starting timer.")
            self.start_time = time.time()
            self.waiting_for_input = True  # Blockiere Eingaben während des Timers
            self.key_pressed = False  # Reset the flag after starting the timer

        if self.waiting_for_input:
            if time.time() - self.start_time >= self.timeout:
                self.logger.info(f"Timer for {self.timeout} seconds finished.")
                self.waiting_for_input = False  # Timer abgelaufen, Eingaben sind wieder möglich
                return py_trees.common.Status.SUCCESS
            else:
                self.logger.info(f"Waiting for {self.timeout - (time.time() - self.start_time):.2f} more seconds.")
                return py_trees.common.Status.RUNNING

        return py_trees.common.Status.RUNNING

    def on_key_press(self, key):
        """Callback function to be called when the key is pressed"""
        if not self.waiting_for_input:  # Eingabe nur zulassen, wenn der Timer abgelaufen ist
            try:
                if key.char == self.key:
                    self.key_pressed = True
                else:
                    # Reset key_pressed if the wrong key was pressed
                    self.key_pressed = False
            except AttributeError:
                pass


class BehaviorTreeNode(Node):
    def __init__(self):
        super().__init__('behavior_tree_node')
        self.get_logger().info("Behavior Tree Node gestartet.")
        self.tree = self.create_behavior_tree()

        self.timer = self.create_timer(0.1, self.tick_tree)

        self.listener = keyboard.Listener(on_press=self.on_key_press)
        self.listener.start()

    def create_behavior_tree(self):
        root = py_trees.composites.Sequence("Root Sequence")
        
        wait_for_1 = WaitForKey("Wait for 1", key="1", logger=self.get_logger())
        wait_for_2 = WaitForKeyWithTimer("Wait for 2 with Timer", key="2", timeout=20, logger=self.get_logger())
        wait_for_3 = WaitForKey("Wait for 3", key="3", logger=self.get_logger())
        
        root.add_children([wait_for_1, wait_for_2, wait_for_3])
        
        return root

    def tick_tree(self):
        self.tree.tick_once()

        tree_visualization = py_trees.display.ascii_tree(self.tree)
        self.get_logger().info("\n" + tree_visualization)

        if self.tree.status == py_trees.common.Status.SUCCESS:
            self.get_logger().info("Behavior Tree completed successfully.")
            rclpy.shutdown()

    def on_key_press(self, key):
        """Callback für Tasteneingaben"""
        for child in self.tree.children:
            if isinstance(child, (WaitForKey, WaitForKeyWithTimer)):
                child.on_key_press(key)


def main(args=None):
    rclpy.init(args=args)
    node = BehaviorTreeNode()
    rclpy.spin(node)

if __name__ == "__main__":
    main()
