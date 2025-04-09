import rclpy
from rclpy.node import Node
from example_interfaces.msg import Float64MultiArray
from kr_msgs.msg import RobotPose
from kr_msgs.msg import Number
from kr_msgs.srv import GetRobotPose
import numpy as np

class IK_Interface(Node):
    def __init__(self):
        super().__init__('ik_interface_node')
        self.process_timer_period = 0.001
        
        # Publisher für Request Bit
        self.req_publisher = self.create_publisher(Number, 'ptp_movements/req_bit', 10)

        # Subscriber für Request Accpeted Bit
        self.req_acc_subscriber = self.create_subscription(Number, 'ptp_movements/req_accepted', self.callback__req_accept, 10)

        # Publisher für Ist-Pose
        self.act_pose_publisher = self.create_publisher(RobotPose, 'ptp_movements/act_robot_pose', 10)

        # Publisher für Soll-Pose
        self.target_pose_publisher = self.create_publisher(RobotPose, 'ptp_movements/target_robot_pose', 10)

        # Publisher für Start Flag
        self.start_flag_publisher = self.create_publisher(Number, 'ptp_movements/start_IK_calculation', 10)

        # Subscriber für Ergebnis der IK-Berechnung
        self.ik_result_subscriber = self.create_subscription(RobotPose, 'ptp_movements/ptp_result_pose', self.callback__res_pose, 10)

        # Subscriber für State der IK-Berechnung
        self.ik_state_subscriber = self.create_subscription(Number, 'ptp_movements/ptp_IK_status', self.callback__IK_state, 10)

        # Service Client für GetRobotPose
        self.tcp_pose_client = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.tcp_pose_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service GetRobotPose...")
        self.get_logger().info("Service GetRobotPose available!")

        # Instanzvariablen
        self.state = "standby"
        self.target_trans_in_worldframe = None
        self.target_rot_in_worldframe = None
        self.IK_result_trans = None
        self.IK_result_rot = None
        self.IK_result_jsconf = None


    def timer_callback(self):
        """Prozess-Callback"""

        if self.state == "req_accepted":
            self.get_logger().info("PTP request accepted...")
            self.state = "get_and_send_act_pose"

        if self.state == "get_and_send_act_pose":
            self.get_logger().info("Requesting actual robot pose...")
            self.get_act_tcp_pose()  # startet async Call
            self.state = "waiting_for_act_pose"

        # Warten auf Antwort des Services -> nichts tun
        if self.state == "waiting_for_act_pose":
            pass

        if self.state == "send_target_pose":
            self.get_logger().info("Sending target pose for IK...")
            self.send_target_pose_to_kr1205(
                trans=self.target_trans_in_worldframe,
                rot=self.target_rot_in_worldframe
            )
            self.state = "start_IK_calculation"

        if self.state == "start_IK_calculation":
            self.get_logger().info("Sending start flag for IK calculation...")
            start_flag = Number()
            start_flag.value = 1.0
            self.start_flag_publisher.publish(start_flag)
            self.state = "waiting_for_IK_result"

        if self.state == "ik_successful":
            self.get_logger().info("IK calculated successfully!")
            self.get_logger().warn(f"Target pose - Translation: {self.IK_result_trans}")
            self.get_logger().warn(f"Target pose - Rotation: {self.IK_result_rot}")
            self.get_logger().warn(f"Target pose - Joint Configs: {self.IK_result_jsconf}")
            self.state = "standby"
            self.reset_topics_to_default_values()

    
    def send_request(self, target_trans_in_worldframe, target_rot_in_worldframe):
        """
        Methode zum Anfordern einer PTP-Bewegung
            -> wird dann von KR1205 akzeptiert
        """
        self.target_trans_in_worldframe = target_trans_in_worldframe
        self.target_rot_in_worldframe = target_rot_in_worldframe

        if self.state == "standby":
            # sende Request Bit über Topic
            req_bit = Number()
            req_bit.value = 1.0
            self.req_publisher.publish(req_bit)

            # direkt danach auf 0 setzen
            # req_bit.value = 0.0
            # self.req_publisher.publish(req_bit)

            self.state = "req_sent"
            self.timer = self.create_timer(self.process_timer_period, self.timer_callback)


    def callback__req_accept(self, msg):
        """Callback für Topic Subscriber Request Accept Bit"""
        req_acc_bit = msg.value
        if req_acc_bit == 1.0 and self.state == "req_sent":
            self.state = "req_accepted"
    
    def get_act_tcp_pose(self):
        """Sendet die aktuelle Größe an Kassow-Robot als Istgröße"""
        req = GetRobotPose.Request()
        future = self.tcp_pose_client.call_async(req)
        future.add_done_callback(self.handle_act_tcp_pose_response)

    def handle_act_tcp_pose_response(self, future):
        try:
            result = future.result()
            trans = result.pos
            rot = result.rot
            jsconf = result.jsconf

            self.get_logger().info("Received actual robot pose.")
            self.send_act_pose_to_kr1205(trans, rot, jsconf)

            # Weiter mit nächstem Zustand
            self.state = "send_target_pose"

        except Exception as e:
            self.get_logger().error(f"Service call failed: {str(e)}")
            self.state = "ik_failed"


    def send_act_pose_to_kr1205(self, trans, rot, jsconf):
        """Sendet aktuelle Pose an KR1205 als Init-Pose für IK-Berechnung"""
        act_pose = RobotPose()
        act_pose.pos = trans
        act_pose.rot = rot
        act_pose.jsconf = jsconf
        self.act_pose_publisher.publish(act_pose)


    def send_target_pose_to_kr1205(self, trans, rot):
        """Sendet die Zielpose an KR1205 für IK-Berechnung"""
        target_pose = RobotPose()
        target_pose.pos = trans
        target_pose.rot = rot
        self.target_pose_publisher.publish(target_pose)

    
    def callback__res_pose(self, msg):
        """Callback für empfangenes IK-Ergebnis"""
        if self.state == "waiting_for_result_values_over_topic":
            self.IK_result_trans = msg.pos
            self.IK_result_rot = msg.rot
            self.IK_result_jsconf = msg.jsconf
            self.state = "ik_successful"


    def callback__IK_state(self, msg):
        """Callback für Status der IK-Berechnung"""
        num = msg.value
        if self.state == "waiting_for_IK_result":
            if num == 0:
                self.get_logger().info(f"Calculation of inverse kinematics successful!")
                self.state = "waiting_for_result_values_over_topic"
            elif num == 1:
                self.get_logger().error(f"IK - Invalid init joint configuration!")
                self.state = "ik_failed"
            elif num == 2:
                self.get_logger().error(f"IK - Invalid result joint configuration!")
                self.state = "ik_failed"
            elif num == 4:
                self.get_logger().error(f"IK - Unable to update robot model kinematics!")
                self.state = "ik_failed"
            elif num == 5:
                self.get_logger().error(f"IK - Solver exceeded min iteraions!")
                self.state = "ik_failed"
            elif num == 100:
                self.get_logger().error(f"IK - Gradient of joint angles used for the computation is too small!")
                self.state = "ik_failed"
            elif num == 101:
                self.get_logger().error(f"IK - Increment in joint angles is too small!")
                self.state = "ik_failed"


    def reset_topics_to_default_values(self):
        """Setzt nach erfolgreicher Berechnung der Inverskinematik die Topics wieder auf ihre Default Standby Werte zurück"""
        # Rücksetzen des req bit
        req_bit = Number()
        req_bit.value = 0.0
        self.req_publisher.publish(req_bit)

        # Rücksetzen des Start Flag
        start_flag = Number()
        start_flag.value = 0.0
        self.start_flag_publisher.publish(start_flag)



def main(args=None):
    rclpy.init(args=args)
    node = IK_Interface()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
