import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis
from kr_msgs.msg import JogLinear


class MoveTcpAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('MoveTcpAlongAxis_action_server')

        # Publisher Move Linear Kassow
        self.twist_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
        self.timer_period = 0.002
        self.timer = self.create_timer(self.timer_period, self.publish_callback)

        # Bei Serverstart Stillstand
        self.ServerInit_movement()

        # Init des Action Servers
        self._action_server = ActionServer(
            self,
            MoveTcpAlongAxis,
            'move_tcp_along_axis',
            self.execute_callback
        )

    def ServerInit_movement(self):
        self.jog_msg = JogLinear()
        self.jog_msg.vel = [0.0, 0.0, 0.0]
        self.jog_msg.rot = [0.0, 0.0, 0.0]
    

    def execute_callback(self, goal_handle):
        self.get_logger().info(f"Starting TCP movement with goal: {goal_handle.request}")

        baseline = goal_handle.request.baseline
        movement_frame = goal_handle.request.movement_frame
        movement_axis = goal_handle.request.movement_axis
        speed = goal_handle.request.speed_in_mm_per_s

        self.feedback_msg = MoveTcpAlongAxis.Feedback()

        ### Movement Frame als System Frame setzen
        self.set_frame()

        ### Aktuelle Startposition auslesen und als Feedback zurueckgeben
        self.get_current_position(goal_handle)
        self.feedback_msg.current_position = baseline

        ### Case-Anweisung - auf welcher Achse soll verfahren werden
        self.set_movement()

        for i in range(5):
            # Roboterbewegung
            self.get_current_position(goal_handle)
            self.set_movement()
            self.publish_callback()

            time.sleep(1)  # Simuliere Pause während Bewegung

        result = MoveTcpAlongAxis.Result()
        result.success = True
        
        self.get_logger().info(f"Movement complete: Success = {result.success}")
        goal_handle.succeed()

        return result
    

    def set_frame(self):
        self.get_logger().info("Set Frame...")
    
    def get_current_position(self, goal_handle):
        self.get_logger().info("Get Current Pose...")
        self.feedback_msg.current_position = 0.0
        goal_handle.publish_feedback(self.feedback_msg)

    def set_movement(self):
        self.get_logger().info("Set Movement on Axis...")
        self.jog_msg.vel = [0.0, 0.0, 0.0]
        self.jog_msg.rot = [0.0, 0.0, 0.0]        

    def publish_callback(self):
        self.twist_publisher.publish(self.jog_msg)
        self.get_logger().info("---------- Twist published! ----------")


def main(args=None):
    rclpy.init(args=args)

    MoveTcpAlongAxis_action_server = MoveTcpAlongAxisActionServer()

    rclpy.spin(MoveTcpAlongAxis_action_server)

if __name__ == '__main__':
    main()