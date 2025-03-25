import rclpy
from rclpy.node import Node
from FC.FC_gripper_handler import GripperHandler
from FC.FC_hook_geometrics_handler_for_trajectory import HookGeometricsHandler
from FC.FC_frame_handler import FrameHandler
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.srv import SetSystemFrame
import sys, select, termios, tty



class AttachmentTrajectory(Node):
    def __init__(self):
        super().__init__('attachment_control_trajectory')
        
        self.declare_parameter('hook_num', 5)
        self.hook_num = self.get_parameter('hook_num').get_parameter_value().integer_value
        self.declare_parameter('distance_to_tip_in_mm', 10)
        self.distance_to_tip_in_mm = self.get_parameter('distance_to_tip_in_mm').get_parameter_value().double_value

        # Publisher für Linear Servoing
        self.jog_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
        self.jog_publisher_timer = self.create_timer(0.01, self.publish_velocity)
        self.velocity_trans = [0.0, 0.0, 0.0]
        self.velocity_rot = [0.0, 0.0, 0.0]

        # Client für Auswahl von Servoing Frame
        self.select_jog_frame_client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.select_jog_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SelectJoggingFrame...")
        self.get_logger().info("Service SelectJoggingFrame available!")
        req = SelectJoggingFrame.Request()
        req.ref = 0     # Servoing passiert in WORLD Frame
        future = self.select_jog_frame_client.call_async(req)
        future.add_done_callback(self.select_jogging_frame_callback)

        # Setze TCP auf TFC
        self.set_kassow_frame_client = self.create_client(SetSystemFrame, '/kr/robot/set_system_frame')
        while not self.set_kassow_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Service SetSystemFrame...")
        self.get_logger().info("Service SetSystemFrame available!")
        self.tcp_in_tfc_trans = [0.0, 0.0, 117.0]       # in mm
        self.tcp_in_tfc_rot = [0.0, 0.0, 0.0]         # in Grad
        self.set_frame(self.tcp_in_tfc_rot, self.tcp_in_tfc_trans, frame="tcp", ref_frame="tfc")

        # Instanz Hook Geometrics Handler
        self.hook_geometrics_handler = HookGeometricsHandler(distance_to_tip_in_mm = self.distance_to_tip_in_mm)
        self.hook = self.hook_geometrics_handler.get_hook_of_global_scan_dict(hook_num=self.hook_num)
        self.hook_geometrics_handler.update_hook_data(hook_num=self.hook_num)
        self.hook_geometrics_handler.calculate_hook_line()

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = 'frame_handler_for_dummy_node')

        # Instanz Gripper Handler
        # self.gripper_handler = GripperHandler()
        # self.gripper_handler.gripper_startup()
        # self.gripper_handler.open_gripper()

        # Instanz des MoveLinearServiceClient
        self.move_lin_client = MoveLinearServiceClient()

        # Position Grip in WORK Frame
        self.grip_pre_pos_in_workframe = [1018.0, -100.0, -50.0]
        self.grip_pre_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pre_pos_in_worldframe, self.grip_pre_rot_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = self.grip_pre_pos_in_workframe,
            rot = self.grip_pre_rot_in_workframe,
            pose_ref_frame = "work")
        
        # Preposition Grip in WORK Frame
        self.grip_pos_in_workframe = [1018.0, -100.0, 20.0]
        self.grip_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pos_in_worldframe, self.grip_rot_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = self.grip_pos_in_workframe,
            rot = self.grip_rot_in_workframe,
            pose_ref_frame = "work")
        
        # Position zum Rausnehmen des Bauteils
        self.grip_post_pos_in_workframe = [1018.0, -200.0, 20.0]
        self.grip_post_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_post_pos_in_worldframe, self.grip_post_rot_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = self.grip_post_pos_in_workframe,
            rot = self.grip_post_rot_in_workframe,
            pose_ref_frame = "work")
        
        '''
        self.grip_pre_pos_movement_done = False
        self.grip_pre_pos_movement_done = self.move_lin_client.call_move_linear_service(
            pos = self.grip_pre_pos_in_worldframe,
            rot = self.grip_pre_rot_in_worldframe,
            ref = 0,
            ttype = 0,
            tvalue = 20.0,
            bpoint = 0,
            btype = 0,
            bvalue = 100.0,
            sync = 0.0,
            chaining = 0)
        if self.grip_pre_pos_movement_done:
            time.sleep(1)
        
        self.grip_pos_movement_done = False
        self.grip_pos_movement_done = self.move_lin_client.call_move_linear_service(
            pos = self.grip_pos_in_worldframe,
            rot = self.grip_rot_in_worldframe,
            ref = 0,
            ttype = 0,
            tvalue = 20.0,
            bpoint = 0,
            btype = 0,
            bvalue = 100.0,
            sync = 0.0,
            chaining = 0)
        if self.grip_pos_movement_done:
            time.sleep(2)
        self.gripper_handler.close_gripper()
        
        if self.gripper_handler.gripper_closed:
            self.grip_post_movement_done = False
            self.grip_post_movement_done = self.move_lin_client.call_move_linear_service(
            pos = self.grip_post_pos_in_worldframe,
            rot = self.grip_post_rot_in_worldframe,
            ref = 0,
            ttype = 0,
            tvalue = 20.0,
            bpoint = 0,
            btype = 0,
            bvalue = 100.0,
            sync = 0.0,
            chaining = 0)
        '''

        # Berechne die Trajektorie basierend auf den Hook-Daten
        self.plane = self.hook_geometrics_handler.calculate_plane(trans_in_tcpframe=[0.0, 0.0, 0.0], 
                                                                  rot_in_tcpframe=[0.0, 0.0, 0.0])
        self.hook_geometrics_handler.update_hook_data(hook_num=self.hook_num)
        self.hook_geometrics_handler.calculate_hook_line()
        
        # endpos_trans_in_worldframe, endpos_rot_in_worldframe = self.hook_geometrics_handler.calculate_targetpose_in_worldframe()

        # Trajektorie als Liste von Punkten, wobei jeder Punkt ein Tupel aus (Translation, Rotation) ist
        self.trajectory = self.hook_geometrics_handler.plan_trajectory(hook_num=self.hook_num)
        self.trajectory_point_num = 0

        # Starte initial den ersten Bewegungsbefehl (falls gewünscht)
        initial_point = self.trajectory[self.trajectory_point_num]
        pos_trans_in_worldframe = initial_point[0].tolist()
        pos_rot_in_worldframe = initial_point[1].tolist()
        
        self.get_logger().warn(f"Starte Bewegung zu Punkt 0: Pose: {pos_trans_in_worldframe}, Rotation: {pos_rot_in_worldframe}")
        self.move_lin_client.call_move_linear_service(
            pos=pos_trans_in_worldframe,
            rot=pos_rot_in_worldframe,
            ref=0,
            ttype=0,
            tvalue=60.0,
            bpoint=0,
            btype=0,
            bvalue=30.0,
            sync=0.0,
            chaining=0)

        # Setze das Terminal in den "cbreak" Modus für non-blocking Tastatureingaben
        self.orig_term_settings = termios.tcgetattr(sys.stdin)
        tty.setcbreak(sys.stdin.fileno())

        # Timer zum periodischen Abfragen der Tastatur
        self.keyboard_timer = self.create_timer(0.1, self.check_keyboard)



    def check_keyboard(self):
        """
        Überprüft non-blocking, ob eine Taste gedrückt wurde.
        Wenn 'n' gedrückt wurde, wird der Trajektorienindex inkrementiert und der nächste Punkt angesteuert.
        """
        if select.select([sys.stdin], [], [], 0)[0]:
            key = sys.stdin.read(1)
            if key == 'n':
                self.trajectory_point_num += 1
                if self.trajectory_point_num < len(self.trajectory):
                    act_point = self.trajectory[self.trajectory_point_num]
                    pos_trans_in_worldframe = act_point[0].tolist()
                    pos_rot_in_worldframe = act_point[1].tolist()
                    self.get_logger().warn(f"Moving to current trajectory point {self.trajectory_point_num}")
                    self.get_logger().warn(f"Pose: {pos_trans_in_worldframe}, Rotation: {pos_rot_in_worldframe}")
                    self.move_lin_client.call_move_linear_service(
                        pos=pos_trans_in_worldframe,
                        rot=pos_rot_in_worldframe,
                        ref=0,
                        ttype=0,
                        tvalue=30.0,
                        bpoint=0,
                        btype=0,
                        bvalue=100.0,
                        sync=0.0,
                        chaining=0)
                else:
                    self.get_logger().info("Reached last trajectory point!")

        

    def select_jogging_frame_callback(self, future):
        """
        Funktion für Service Callback SelectJoggingFrame
        """
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('Service call SelectJoggingFrame successful!')
            else:
                self.get_logger().info('Service call SelectJoggingFrame failed!')
        except Exception as e:
            self.get_logger().error(f'Error calling service SelectJoggingFrame: {e}')



    def publish_velocity(self):
        """
        Funktion für das Publishing der aktuellen Twist-Messages
        """
        msg = JogLinear()
        msg.vel = self.velocity_trans
        msg.vel = self.velocity_rot
        self.jog_publisher.publish(msg = msg)



    def set_frame(self, rot, trans, frame="tcp", ref_frame="tfc"):
        """
        Funktion für Service Call SetSystemFrame -> setzt hier das TCP-Frame in Relation zum TFC-Frame
        """
        request = SetSystemFrame.Request()
        request.name = frame
        request.ref = ref_frame
        request.pos = trans
        request.rot = rot

        future = self.set_kassow_frame_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Frame '{frame}' set successfully!")
            else:
                self.get_logger().warn(f"Failed to set frame '{frame}'!")
        except Exception as e:
            self.get_logger().error(f"Service call of SetSystemFrame failed: {e}")



    def shutdown(self):
        """
        Gibt alle Ressourcen frei, bevor der Node beendet wird.
        """
        self.get_logger().info("Shutting down...")
        self.jog_publisher_timer.cancel()
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.orig_term_settings)  # Terminal zurücksetzen
        self.destroy_node()




def main(args=None):
    rclpy.init(args=args)
    node = AttachmentTrajectory()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().warn("Shutting down...")
    finally:
        node.shutdown()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
