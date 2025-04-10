import rclpy
from rclpy.node import Node
from kr_msgs.srv import MoveJoint
from time import time
from FC.FC_ik_interface import IK_Interface


class MovePTPServiceClient(Node):
    def __init__(self):
        super().__init__('move_ptp_service_client')
        self.client = self.create_client(MoveJoint, '/kr/motion/move_joint')
        self.joint_config = None
        self.ik_interface = IK_Interface()

    def call_move_ptp_service(self, pos, rot, ttype, tvalue, bpoint, btype, bvalue, sync, chaining):
        """Methode zum Aufruf der IK-Berechnung und der Bewegung MoveJoint"""
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.get_logger().info('Service MoveJoint available, making service call...')        

        # IK-Berechnung
        self.ik_interface.send_request(
            target_trans_in_worldframe = pos,
            target_rot_in_worldframe = rot
        )
        while self.ik_interface.state == "waiting_for_IK_result":
            self.get_logger().info(f"Waiting for IK calculation...")
            if self.ik_interface.state == "ik_successful":
                self.get_logger().info(f"IK calculation successful! - making service call for MoveJoint")
                self.joint_config = self.ik_interface.IK_result_jsconf

        # Aufruf Service MoveJoint mit IK-Ergebnis
        request = MoveJoint.Request()
        request.jsconf = self.joint_config
        request.ttype = ttype
        request.tvalue = tvalue
        request.bpoint = bpoint
        request.btype = btype
        request.bvalue = bvalue
        request.sync = sync
        request.chaining = chaining

        # Sende Service-Request und warte auf Antwort
        start_time = time()
        while True:
            future = self.client.call_async(request)
            rclpy.spin_until_future_complete(self, future)
            
            if future.result() is not None:
                # Warte auf eine erfolgreiche Antwort (success=True)
                if future.result().success:
                    self.get_logger().info("Movement completed successfully")
                    return True  # Erfolgreiche Bewegung
                else:
                    self.get_logger().warn("Movement failed!")
                    return False  # Bewegung fehlgeschlagen
            elif time() - start_time > 10:  # Timeout nach 10 Sekunden
                self.get_logger().warn("Service call timed out!")
                return False  # Timeout, falls keine Antwort innerhalb von 10 Sekunden