import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveTcpAlongAxis
from kr_msgs.msg import JogLinear
from kr_msgs.srv import GetRobotPose
from kr_msgs.srv import SelectJoggingFrame


class MoveTcpAlongAxisActionServer(Node):

    def __init__(self):
        super().__init__('MoveTcpAlongAxis_action_server')

        # Publisher Move Linear Kassow
        self.twist_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
        self.timer_period = 0.002
        self.timer = self.create_timer(self.timer_period, self.publish_callback)
        self.TwistPublisher_active = False

        # Bei Serverstart Stillstand
        self.ServerInit_movement()

        # Aktuelle Werte Roboter
        self.pos = None
        self.rot = None
        self.jconf = None
        self.pos_target = None
        self.rot_target = None

        # Init des Action Servers
        self._action_server = ActionServer(
            self,
            MoveTcpAlongAxis,
            'move_tcp_along_axis',
            self.execute_callback
        )

        # Service Clients Kassow
        self.client_GetRobotPose = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.client_GetRobotPose.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for Service Kassow: GetRobotPose')
            self.Srv_GetRobotPose_available = False
        self.get_logger().info(f"Service Kassow: GetRobotPose available!")
        self.Srv_GetRobotPose_available = True

        self.client_SelectJoggingFrame = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.client_SelectJoggingFrame.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for Service Kassow: SelectJoggingFrame')
            self.Srv_SelectJoggingFrame_available = False
        self.get_logger().info(f"Service Kassow: SelectJoggingFrame available!")
        self.Srv_SelectJoggingFrame_available = True


    def callSrv_SelectJoggingFrame(self):
        req = SelectJoggingFrame.Request()
        
        if self.movement_frame == 'world':
            req.ref = 0
        elif self.movement_frame == 'base':
            req.ref = 1
        elif self.movement_frame == 'tcp':
            req.ref = 2

        future = self.client_SelectJoggingFrame.call_async(req)
        future.add_done_callback(self.handle_response_Srv_SelectJoggingFrame)

    def handle_response_Srv_SelectJoggingFrame(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info("Robot Frame set successfully!")
        except Exception as e:
            self.get_logger().info(f"Service Call SelectJoggingFrame failed!")

    
    def callSrv_GetRobotPose(self):
        req = GetRobotPose.Request()
        future = self.client_GetRobotPose.call_async(req)
        future.add_done_callback(self.handle_response_Srv_GetRobotPose)

    def handle_response_Srv_GetRobotPose(self, future):
        try:
            response = future.result()
            if response.success:
                # self.get_logger().info("Got Robot Pose successfully!")
                # self.get_logger().info(f"Robot Position: {response.pos}")
                self.pos = [response.pos[0], response.pos[1], response.pos[2]]
                # self.get_logger().info(f"Robot Orientation: {response.rot}")
                self.rot = [response.rot[0], response.rot[1], response.rot[2]]
                # self.get_logger().info(f"Current Joint Config: {response.jsconf}")
                self.jconf = [response.jsconf[0],
                                response.jsconf[1],
                                response.jsconf[2],
                                response.jsconf[3],
                                response.jsconf[4],
                                response.jsconf[5],
                                response.jsconf[6]]
                self.get_logger().info(f"Got Robot Pose successfully!")
        except Exception as e:
            self.get_logger().info("Service Call GetRobotPose failed!")


    def ServerInit_movement(self):
        self.jog_msg = JogLinear()
        self.jog_msg.vel = [0.0, 0.0, 0.0]
        self.jog_msg.rot = [0.0, 0.0, 0.0]
    

    def execute_callback(self, goal_handle):
        self.TwistPublisher_active = True
        self.get_logger().info(f"Starting TCP movement") # with goal: {goal_handle.request}")

        self.baseline = goal_handle.request.baseline
        self.movement_frame = goal_handle.request.movement_frame
        self.movement_axis = goal_handle.request.movement_axis
        self.speed = goal_handle.request.speed_in_mm_per_s

        self.feedback_msg = MoveTcpAlongAxis.Feedback()

        ### Movement Frame als System Frame setzen
        self.set_frame()

        ### Aktuelle Startposition auslesen und als Feedback zurueckgeben
        self.get_current_position(goal_handle)

        ### Twist aufbauen
        self.set_movement()

        for i in range(5):
            # Roboterbewegung
            self.get_current_position(goal_handle)
            self.set_movement()
            self.publish_callback()

            time.sleep(0.1)  # Simuliere Pause während Bewegung

        self.TwistPublisher_active = False
        result = MoveTcpAlongAxis.Result()
        result.success = True
        
        self.get_logger().info(f"Movement complete: Success = {result.success}")
        goal_handle.succeed()

        return result


    def set_frame(self):
        self.get_logger().info("Set Frame...")
        self.callSrv_SelectJoggingFrame()
    
    def get_current_position(self, goal_handle):
        self.get_logger().info("Get Current Pose...")
        self.callSrv_GetRobotPose()

        # Warte auf Antwort
        timeout = 2.0  # max Timeout Zeit
        start_time = time.time()
        while self.pos is None and (time.time() - start_time) < timeout:
            rclpy.spin_once(self, timeout_sec=0.01)

        if self.pos is not None:
            self.feedback_msg.current_position = self.pos
            goal_handle.publish_feedback(self.feedback_msg)
        else:
            self.get_logger().warning("Failed to get current position within timeout.")


    def set_movement(self):
        self.get_logger().info("Set Movement on Axis...")
        self.jog_msg.vel = [0.0, 0.0, 0.0]
        self.jog_msg.rot = [0.0, 0.0, 0.0]

    def publish_callback(self):
        if self.TwistPublisher_active:
            self.twist_publisher.publish(self.jog_msg)
            # self.get_logger().info("---------- Twist published! ----------")


def main(args=None):
    rclpy.init(args=args)

    MoveTcpAlongAxis_action_server = MoveTcpAlongAxisActionServer()

    rclpy.spin(MoveTcpAlongAxis_action_server)

if __name__ == '__main__':
    main()

