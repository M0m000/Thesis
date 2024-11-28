import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from kr_msgs.action import MoveTCPAlongAxis  # Importiere die neue Action-Datei
import time

class MoveTCPAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('move_tcp_along_axis_action_server')
        self._action_server = ActionServer(
            self,
            MoveTCPAlongAxis,
            'move_tcp_along_axis',  # Name der Action
            self.execute_callback  # Callback-Funktion für die Ausführung der Action
        )

    def execute_callback(self, goal_handle):
        self.get_logger().info(f"Received goal: {goal_handle.request}")
        # Goal-Daten auslesen
        baseline = goal_handle.request.baseline
        movement_frame = goal_handle.request.movement_frame
        movement_axis = goal_handle.request.movement_axis
    
        self.get_logger().info(f"Starting TCP movement with baseline: {baseline}, frame: {movement_frame}, axis: {movement_axis}")
        start_time = time.time()
    
        # Während der Ausführung Feedback senden
        while time.time() - start_time < 5:
            feedback = MoveTCPAlongAxis.Feedback()
            feedback.current_time = time.time() - start_time
            goal_handle.publish_feedback(feedback)
            time.sleep(0.1)  # Feedback alle 100ms senden
    
        self.get_logger().info(f"Goal succeeded: {goal_handle.request}")
        goal_handle.succeed()
        result = MoveTCPAlongAxis.Result()
        result.success = True
        return result



def main(args=None):
    rclpy.init(args=args)
    action_server = MoveTCPAlongAxisActionServer()
    rclpy.spin(action_server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
