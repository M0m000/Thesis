import rclpy
from rclpy.node import Node
from rclpy.task import Future
from kr_msgs.srv import MoveJoint, GetRobotPose
from kr_msgs.msg import RobotPose, Number

class IKMoveExecutor(Node):
    def __init__(self):
        super().__init__('ik_move_executor')

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

    def move_to_pose(self, pos, rot):
        self.ik_state = 'requested'
        self.target_trans = pos
        self.target_rot = rot
        self.ik_result = None

        # === Request IK Berechnung ===
        self.send_req_bit()
        self.wait_for_state('req_accepted')

        act_pose = self.get_actual_pose()
        self.publish_actual_pose(act_pose)
        self.publish_target_pose(pos, rot)
        self.send_start_flag()

        self.wait_for_state('ik_successful')

        print(self.ik_result)
        if self.ik_result is None:
            raise RuntimeError("IK result missing")

        self.send_move_joint(self.ik_result)

    ##### Hilfsfunktionen
    def wait_for_state(self, desired_state, timeout_sec=10.0):
        import time
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
        req.ttype = 0
        req.tvalue = 30.0
        req.bpoint = 0
        req.btype = 0
        req.bvalue = 30.0
        req.sync = 0.0
        req.chaining = 0

        future = self.move_joint_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if not future.result().success:
            raise RuntimeError("MoveJoint failed")

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


def main(args=None):
    rclpy.init(args=args)
    executor = IKMoveExecutor()
    try:
        executor.move_to_pose([150.0, 420.0, 800.0], [-90.0, -60.0, 0.0])
    except Exception as e:
        executor.get_logger().error(str(e))
    executor.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
