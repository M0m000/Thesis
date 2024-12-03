import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis  # Der Action-Typ

class MoveTcpAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('MoveTcpAlongAxis_action_server')

        self._action_server = ActionServer(
            self,
            MoveTcpAlongAxis,
            'move_tcp_along_axis',
            self.execute_callback
        )

    def execute_callback(self, goal_handle):
        self.get_logger().info(f"Starting TCP movement with goal: {goal_handle.request}")

        baseline = goal_handle.request.baseline
        movement_frame = goal_handle.request.movement_frame
        movement_axis = goal_handle.request.movement_axis

        feedback_msg = MoveTcpAlongAxis.Feedback()
        feedback_msg.current_position = baseline  # Startposition

        for i in range(5):
            # Roboterbewegung
            
            feedback_msg.current_position += 0.1  # fortschreitende Bewegung
            self.get_logger().info(f"Feedback: {feedback_msg.current_position}")
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)  # Simuliere Pause während Bewegung

        result = MoveTcpAlongAxis.Result()
        result.success = True
        
        self.get_logger().info(f"Movement complete: Success = {result.success}")
        goal_handle.succeed()

        return result

def main(args=None):
    rclpy.init(args=args)

    MoveTcpAlongAxis_action_server = MoveTcpAlongAxisActionServer()

    rclpy.spin(MoveTcpAlongAxis_action_server)

if __name__ == '__main__':
    main()
    