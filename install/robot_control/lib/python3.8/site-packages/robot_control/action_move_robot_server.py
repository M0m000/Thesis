import rclpy
from rclpy.node import Node
from robot_control.action import MoveRobot
from rclpy.action import ActionServer
import time

class MoveRobotActionServer(Node):

    def __init__(self):
        super().__init__('move_robot_action_server')
        self._action_server = ActionServer(
            self,
            MoveRobot,
            'move_robot',
            self.execute_callback
        )
        self.get_logger().info('MoveRobot Action Server gestartet.')

    def execute_callback(self, goal_handle):
        self.get_logger().info(f"Moving robot {goal_handle.request.baseline} along {goal_handle.request.axis} axis.")
        
        # Simuliere eine lange Bewegung (z. B. 5 Sekunden)
        time.sleep(5)
        
        # Sende Feedback
        feedback_msg = MoveRobot.Feedback()
        feedback_msg.message = "Robot moved."
        goal_handle.publish_feedback(feedback_msg)
        
        # Setze das Resultat
        goal_handle.succeed()
        result = MoveRobot.Result()
        result.success = True
        return result

def main(args=None):
    rclpy.init(args=args)
    move_robot_action_server = MoveRobotActionServer()
    rclpy.spin(move_robot_action_server)

if __name__ == '__main__':
    main()
