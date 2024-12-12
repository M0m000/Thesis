import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis

class MoveTcpAlongAxisActionClient(Node):

    def __init__(self):
        super().__init__('move_tcp_along_axis_action_client')

        # ROS 2 Parameter deklarieren
        self.declare_parameter('baseline', 0.0)
        self.declare_parameter('movement_frame', 'tcp')
        self.declare_parameter('movement_axis', 'axis_x')
        self.declare_parameter('speed', 20.0)

        # Action Client erstellen
        self._action_client = ActionClient(self, MoveTcpAlongAxis, 'move_tcp_along_axis')

    def send_goal(self, baseline, movement_frame, movement_axis, speed):
        goal_msg = MoveTcpAlongAxis.Goal()
        goal_msg.baseline = baseline
        goal_msg.movement_frame = movement_frame
        goal_msg.movement_axis = movement_axis
        goal_msg.speed_in_mm_per_s = speed

        if not self._action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().info("Server is not available after waiting.")
            return

        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

        rclpy.spin_until_future_complete(self, self._send_goal_future)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Feedback - Current Position: {0}'.format(feedback.current_position))
        self.get_logger().info('Feedback - Current Difference: {0}'.format(feedback.current_diff))

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('ERROR - Movement request rejected!')
            return

        self.get_logger().info('Movement request accepted!')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Movement successful!' if result.success else 'Movement ERROR!')

def main(args=None):
    rclpy.init(args=args)

    # Parameter aus ROS 2 Knoten abrufen
    node = MoveTcpAlongAxisActionClient()

    baseline = node.get_parameter('baseline').get_parameter_value().double_value
    movement_frame = node.get_parameter('movement_frame').get_parameter_value().string_value
    movement_axis = node.get_parameter('movement_axis').get_parameter_value().string_value
    speed = node.get_parameter('speed').get_parameter_value().double_value

    # Goal mit den Parametern senden
    try:
        node.send_goal(
            baseline=baseline,
            movement_frame=movement_frame,
            movement_axis=movement_axis,
            speed=speed
        )
    except Exception as e:
        node.get_logger().error(f"Error during action: {e}")
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
