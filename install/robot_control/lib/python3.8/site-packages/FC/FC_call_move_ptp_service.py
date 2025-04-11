import rclpy
from rclpy.node import Node
from kr_msgs.srv import MoveJoint, GetRobotPose
from kr_msgs.msg import RobotPose, Number
import time


class MovePTPServiceClient(Node):
    def __init__(self):
        super().__init__('move_ptp_client_node')

        ##### Service-Clients
        self.move_joint_client = self.create_client(MoveJoint, '/kr/motion/move_joint')
        self.tcp_pose_client = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')

        while not self.move_joint_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for MoveJoint service...')

        while not self.tcp_pose_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for GetRobotPose service...')

        ##### Publisher & Subscriber
        self.req_publisher = self.create_publisher(Number, 'ptp_movements/req_bit', 10)
        self.act_pose_publisher = self.create_publisher(RobotPose, 'ptp_movements/act_robot_pose', 10)
        self.target_pose_publisher = self.create_publisher(RobotPose, 'ptp_movements/target_robot_pose', 10)
        self.start_flag_publisher = self.create_publisher(Number, 'ptp_movements/start_IK_calculation', 10)

        self.req_acc_sub = self.create_subscription(Number, 'ptp_movements/req_accepted', self.cb_req_accepted, 10)
        self.ik_result_sub = self.create_subscription(RobotPose, 'ptp_movements/ptp_result_pose', self.cb_ik_result, 10)
        self.ik_state_sub = self.create_subscription(Number, 'ptp_movements/ptp_IK_status', self.cb_ik_status, 10)

        self.ik_state = 'idle'
        self.target_trans = None
        self.target_rot = None
        self.ik_result = None

    def call_move_ptp_service(self, pos = None, rot = None, ref = 0, ttype = 0, tvalue = 30.0, bpoint = 0, btype = 0, bvalue = 30.0, sync = 0.0, chaining = 0):
        """
        Methode, die in ROS2 Nodes aufgerufen werden kann
            -> anschließend wird die IK über Handshake mit KR1205 berechnet
            -> Gelenkwinkel werden zurückgeliefert
            -> MoveJoint Bewegung mit diesen Gelenkwinkeln wird aufgerufen
        """
        self.reset_trigger_bits()  # vor dem Start: alle Bits zurücksetzen
        time.sleep(0.1)  # kleine Pause, um Reset zu propagieren

        # Variablen für Bewegungsservice speichern
        self.move_service_ref = ref
        self.move_service_ttype = ttype
        self.move_service_tvalue = tvalue
        self.move_service_bpoint = bpoint
        self.move_service_btype = btype
        self.move_service_bvalue = bvalue
        self.move_service_sync = sync
        self.move_service_chaining = chaining

        # IK Status auf Request
        self.ik_state = 'requested'
        self.target_trans = pos
        self.target_rot = rot
        self.ik_result = None

        try:
            # IK Request starten
            self.send_req_bit()
            self.wait_for_state('req_accepted')

            act_pose = self.get_actual_pose()
            self.publish_actual_pose(act_pose)
            self.publish_target_pose(pos, rot)
            self.send_start_flag()

            self.wait_for_state('ik_successful')

            if self.ik_result is None:
                self.get_logger().error("IK result missing")
                self.reset_trigger_bits()
                return False

            success = self.send_move_joint(self.ik_result)
            self.reset_trigger_bits()
            return success

        except TimeoutError as e:
            self.get_logger().error(str(e))
            self.reset_trigger_bits()
            return False

        except RuntimeError as e:
            self.get_logger().error(str(e))
            self.reset_trigger_bits()
            return False

    ##### Hilfsfunktionen
    def wait_for_state(self, desired_state, timeout_sec=10.0):
        start = time.time()
        while rclpy.ok() and self.ik_state != desired_state:
            rclpy.spin_once(self, timeout_sec=0.1)
            if time.time() - start > timeout_sec:
                raise TimeoutError(f"Timeout waiting for state '{desired_state}'")

    def get_actual_pose(self):
        req = GetRobotPose.Request()
        future = self.tcp_pose_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return future.result()

    def send_req_bit(self):
        msg = Number()
        msg.value = 1.0
        self.req_publisher.publish(msg)

    def send_start_flag(self):
        msg = Number()
        msg.value = 1.0
        self.start_flag_publisher.publish(msg)

    def reset_trigger_bits(self):
        """Setze req_bit und start_flag zurück auf 0"""
        req_bit = Number()
        req_bit.value = 0.0
        self.req_publisher.publish(req_bit)

        start_flag = Number()
        start_flag.value = 0.0
        self.start_flag_publisher.publish(start_flag)

    def publish_actual_pose(self, pose):
        msg = RobotPose()
        msg.pos = pose.pos
        msg.rot = pose.rot
        msg.jsconf = pose.jsconf
        self.act_pose_publisher.publish(msg)

    def publish_target_pose(self, trans, rot):
        msg = RobotPose()
        msg.pos = trans
        msg.rot = rot
        self.target_pose_publisher.publish(msg)

    def send_move_joint(self, ik_result):
        req = MoveJoint.Request()
        req.jsconf = ik_result.jsconf
        req.ttype = self.move_service_ttype
        req.tvalue = self.move_service_tvalue
        req.bpoint = self.move_service_bpoint
        req.btype = self.move_service_btype
        req.bvalue = self.move_service_bvalue
        req.sync = self.move_service_sync
        req.chaining = self.move_service_chaining

        future = self.move_joint_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None and future.result().success:
            self.get_logger().info("MoveJoint succeeded")
            return True
        else:
            self.get_logger().error("MoveJoint failed or returned no result")
            return False

    ##### Callbacks
    def cb_req_accepted(self, msg):
        if msg.value == 1.0 and self.ik_state == 'requested':
            self.ik_state = 'req_accepted'

    def cb_ik_status(self, msg):
        if self.ik_state not in ['req_accepted', 'waiting_ik']:
            return

        if msg.value == 0:
            self.ik_state = 'waiting_result'
        elif msg.value in [1, 2, 4, 5, 100, 101]:
            self.get_logger().error(f"IK failed with code {msg.value}")
            self.ik_state = 'failed'

    def cb_ik_result(self, msg):
        if self.ik_state == 'waiting_result':
            self.ik_result = msg
            self.ik_state = 'ik_successful'
