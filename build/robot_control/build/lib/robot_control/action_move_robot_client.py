import rclpy
from rclpy.node import Node
from robot_control.action import MoveRobot
from rclpy.action import ActionClient
from rclpy.executors import MultiThreadedExecutor

class MoveRobotActionClient(Node):

    def __init__(self):
        super().__init__('move_robot_action_client')
        self._action_client = ActionClient(self, MoveRobot, 'move_robot')

    def send_goal(self, baseline, frame, axis):
        goal_msg = MoveRobot.Goal()
        goal_msg.baseline = baseline
        goal_msg.frame = frame
        goal_msg.axis = axis
        
        # Warte darauf, dass der Server verfügbar ist
        if not self._action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('Action server not available')
            return False
        
        # Sende den Goal-Request
        send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        rclpy.spin_until_future_complete(self, send_goal_future)
        
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected.')
            return False
        
        # Hole das Resultat
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        
        result = result_future.result()
        if result.success:
            self.get_logger().info('Movement completed successfully!')
        else:
            self.get_logger().info('Movement failed.')
        return result.success

    def feedback_callback(self, feedback):
        self.get_logger().info(f"Feedback: {feedback.message}")

def main(args=None):
    rclpy.init(args=args)
    action_client = MoveRobotActionClient()
    action_client.send_goal(10.0, 'world', 'x')
    rclpy.shutdown()

if __name__ == '__main__':
    main()
