import rclpy
from rclpy.node import Node
import py_trees
import py_trees.behaviours as behaviours
import py_trees.common
from pynput import keyboard
from kr_msgs.srv import MoveTCPAlongAxis


class SetCameraAngle(py_trees.behaviour.Behaviour):
    def __init__(self, node: Node, angle: str):
        super().__init__(name=f"SetCameraAngle({angle})")
        self.node = node
        self.angle = angle

    def initialise(self):
        self.node.get_logger().info(f"Setting camera angle to {self.angle}")

    def update(self):
        success = True
        return py_trees.common.Status.SUCCESS if success else py_trees.common.Status.FAILURE


class TraverseLine(py_trees.behaviour.Behaviour):
    def __init__(self, node, direction, baseline, movement_frame, movement_axis):
        super().__init__(name=f"TraverseLine({direction})")
        self.node = node
        self.direction = direction
        self.baseline = baseline
        self.current_position = 0.0
        self.end_position = 10.0  # Beispiel: Länge der Leiste

    def initialise(self):
        self.node.get_logger().info(f"Initializing traversal in direction {self.direction}")
        self.current_position = 0.0

    def update(self):
        if self.current_position >= self.end_position:
            self.node.get_logger().info("Traversal complete.")
            return py_trees.common.Status.SUCCESS
        else:
            self.current_position += self.baseline
            self.node.get_logger().info(
                f"Moving to position {self.current_position}, capturing image."
            )
            return py_trees.common.Status.RUNNING


class WaitAfterScan(py_trees.behaviour.Behaviour):
    def __init__(self, node: Node):
        super().__init__(name="WaitAfterScan")
        self.node = node
        self.listener = keyboard.Listener(on_press=self.on_key_press)
        self.listener.start()
        self.key_pressed = False
        self.finished = False

    def on_key_press(self, key):
        try:
            if key == keyboard.KeyCode.from_char('i'):
                self.node.get_logger().info("Key 'i' pressed. Ending behavior tree...")
                self.key_pressed = True
        except AttributeError:
            pass

    def update(self):
        if self.finished:
            return py_trees.common.Status.SUCCESS
        
        if self.key_pressed:
            self.finished = True
            # Beende den gesamten ROS2 Knoten
            self.node.get_logger().info("Shutting down node after 'i' pressed.")
            rclpy.shutdown()  # Beendet den ROS2 Knoten
            return py_trees.common.Status.SUCCESS
        else:
            return py_trees.common.Status.RUNNING


def create_behavior_tree(node: Node, baseline: float, movement_frame, movement_axis):
    root = py_trees.composites.Sequence(name="MainSequence")

    # Front-Ansicht
    front_view = py_trees.composites.Sequence(name="FrontViewSequence")
    front_view.add_child(SetCameraAngle(node, "front"))
    front_view.add_child(TraverseLine(node, direction="front", baseline=baseline, movement_frame=movement_frame, movement_axis=movement_axis))

    # Top-Ansicht
    top_view = py_trees.composites.Sequence(name="TopViewSequence")
    top_view.add_child(SetCameraAngle(node, "top"))
    top_view.add_child(TraverseLine(node, direction="top", baseline=baseline, movement_frame=movement_frame, movement_axis=movement_axis))
    top_view.add_child(WaitAfterScan(node))

    root.add_child(front_view)
    root.add_child(top_view)

    return root


class RobotMovementService(Node):
    def __init__(self):
        super().__init__('robot_movement_service')
        self.cli = self.create_client(MoveTCPAlongAxis, 'move_tcp_along_axis')

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.get_logger().info('Service for Robot Movement available!')

    def call_service(self, baseline, frame, axis):
        request = MoveTCPAlongAxis.Request()
        request.baseline = baseline
        request.frame = frame
        request.axis = axis

        future = self.cli.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            self.get_logger().info(f"Service response: {future.result().success}")
            return future.result().success
        else:
            self.get_logger().error("Service call failed")
            return False


class BTScanHookstrip(Node):
    def __init__(self):
        super().__init__("bt_scan_hookstrip")
        self.get_logger().info("ScanHookstrip Node started.")

        self.declare_parameter("baseline", 1.0)
        self.declare_parameter("movement_frame", 'tcp')
        self.declare_parameter("movement_axis", 'x')
        baseline = self.get_parameter("baseline").value

        self.listener = keyboard.Listener(on_press=self.on_key_press)
        self.listener.start()

        self.tree_started = False
        self.tree = None

        self.timer = self.create_timer(0.1, self.tick_tree)

    def on_key_press(self, key):
        try:
            if key == keyboard.KeyCode.from_char('u'):
                self.get_logger().info("Key 'u' pressed. Starting behavior tree...")
                self.start_behavior_tree()
        except AttributeError:
            pass

    def start_behavior_tree(self):
        if not self.tree_started:
            baseline = self.get_parameter("baseline").value
            movement_frame = self.get_parameter("movement_frame").value
            movement_axis = self.get_parameter("movement_axis").value

            self.tree = py_trees.trees.BehaviourTree(create_behavior_tree(self, baseline, movement_frame, movement_axis))
            self.tree_started = True
            self.get_logger().info("Behavior Tree started.")

    def tick_tree(self):
        if self.tree_started and self.tree:
            self.tree.tick()
            visited = {}
            py_trees.display.ascii_tree(self.tree.root, visited=visited)


def main(args=None):
    rclpy.init(args=args)
    node = BTScanHookstrip()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down ScanHookstrip Node.")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()


