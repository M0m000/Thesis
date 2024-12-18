import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis
from kr_msgs.srv import MoveLinear


class MoveTcpAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('MoveTcpAlongAxis_action_server')
        self.get_logger().info("Initializing Action Server")

        # Init des Action Servers
        self._action_server = ActionServer(
            self,
            MoveTcpAlongAxis,
            'move_tcp_along_axis',
            self.execute_callback
        )

        self.client = self.create_client(MoveLinear, '/kr/motion/move_linear')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service MoveLinear...')
        self.get_logger().info('Service MoveLinear available!')

        self.pos = None
        self.rot = None
        self.axis_idx = None
        self.frame_idx = None
        self.baseline = None
        self.movement_frame = None
        self.movement_axis = None
        self.speed_in_mm_per_s = None


    def execute_callback(self, goal_handle):
        self.get_logger().info("Starting TCP movement")

        if goal_handle.is_cancel_requested:
            self.get_logger().info("Action canceled by client.")

        try:
            self.baseline = goal_handle.request.baseline
            self.movement_frame = goal_handle.request.movement_frame
            self.movement_axis = goal_handle.request.movement_axis
            self.speed_in_mm_per_s = goal_handle.request.speed_in_mm_per_s

            self.get_axis_idx()
            self.get_frame_idx()
            self.set_pose()

            srv_request = MoveLinear.Request()
            srv_request.pos = self.pos
            srv_request.rot = self.rot
            srv_request.ref = self.frame_idx
            srv_request.ttype = 0
            srv_request.tvalue = self.speed_in_mm_per_s
            srv_request.bpoint = 0
            srv_request.btype = 0
            srv_request.bvalue = 500.0
            srv_request.sync = 0.0
            srv_request.chaining = 0

            future = self.client.call_async(srv_request)
            rclpy.spin_until_future_complete(self, future)

            if future.result().success:
                feedback_msg = MoveTcpAlongAxis.Feedback()
                feedback_msg.current_diff = 0.0
                goal_handle.publish_feedback(feedback_msg)

                goal_handle.succeed()

                result = MoveTcpAlongAxis.Result()
                result.success = True
                return result
            else:
                goal_handle.abort()
                result = MoveTcpAlongAxis.Result()
                result.success = False
                return result
        
        except Exception as e:
            self.get_logger().info(f"Error during execution: {e}")



    def get_axis_idx(self):
        if self.movement_axis == 'axis_x':
            self.axis_idx = 0
        elif self.movement_axis == 'axis_y':
            self.axis_idx = 1
        elif self.movement_axis == 'axis_z':
            self.axis_idx = 2

    def get_frame_idx(self):
        if self.movement_frame == 'world':
            self.frame_idx = 0
        elif self.movement_frame == 'base':
            self.frame_idx = 1
        elif self.movement_frame == 'tcp':
            self.frame_idx = 2
        else:
            self.frame_idx = None
    

    def set_pose(self):
        self.pos = [0.0, 0.0, 0.0]
        self.rot = [0.0, 0.0, 0.0]

        self.pos[self.axis_idx] = self.baseline



def main(args=None):
    rclpy.init(args=args)
    action_server_node = MoveTcpAlongAxisActionServer()

    try:
        while rclpy.ok():
            rclpy.spin_once(action_server_node, timeout_sec=0.1)
    except KeyboardInterrupt:
        action_server_node.get_logger().info("Shutting down Action Server.")
    finally:
        action_server_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
