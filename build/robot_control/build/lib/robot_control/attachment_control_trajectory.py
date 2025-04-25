import rclpy
from rclpy.node import Node
from FC.FC_gripper_handler import GripperHandler
from FC.FC_hook_geometrics_handler_for_trajectory import HookGeometricsHandler
from FC.FC_frame_handler import FrameHandler
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from FC.FC_call_move_ptp_service import MovePTPServiceClient
from FC.FC_doc_plot_attachment import DocPlotAttachment
from FC.FC_eval_save_trajectory_to_csv import save_trajectory_to_csv
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.srv import SetSystemFrame
import sys, select, termios, tty
import time
import numpy as np



class AttachmentTrajectory(Node):
    def __init__(self):
        super().__init__('attachment_control_trajectory')
        
        self.declare_parameter('hook_num', 15)
        self.hook_num = self.get_parameter('hook_num').get_parameter_value().integer_value
        self.declare_parameter('distance_to_tip_in_mm', 10)
        self.distance_to_tip_in_mm = self.get_parameter('distance_to_tip_in_mm').get_parameter_value().double_value

        # Publisher für Linear Servoing
        self.jog_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
        self.jog_publisher_timer = self.create_timer(0.01, self.publish_velocity)
        self.velocity_trans = [0.0, 0.0, 0.0]
        self.velocity_rot = [0.0, 0.0, 0.0]

        # Client für Auswahl von Servoing Frame
        self.max_retry = 10
        self.select_jog_frame_client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        i = 0
        while not self.select_jog_frame_client.wait_for_service(timeout_sec=1.0) and i < self.max_retry:
            self.get_logger().info("Waiting for service SelectJoggingFrame...")
            i += 1
        self.get_logger().info("Service SelectJoggingFrame available!")
        req = SelectJoggingFrame.Request()
        req.ref = 0     # Servoing passiert in WORLD Frame
        future = self.select_jog_frame_client.call_async(req)
        future.add_done_callback(self.select_jogging_frame_callback)

        # Setze TCP auf TFC
        self.set_kassow_frame_client = self.create_client(SetSystemFrame, '/kr/robot/set_system_frame')
        i = 0
        while not self.set_kassow_frame_client.wait_for_service(timeout_sec=1.0) and i < self.max_retry:
            self.get_logger().info("Waiting for Service SetSystemFrame...")
            i += 1
        self.get_logger().info("Service SetSystemFrame available!")

        # self.tcp_in_tfc_trans = [0.61629099, 4.49679891, 238.7470473]       # 3D-Schablone auf Schunk
        # self.tcp_in_tfc_rot = [0.0, 0.0, 30.0]

        # self.tcp_in_tfc_trans = [-1.78034352, 0.33577707, 105.41798404]   # 3D-Schablone groß
        # self.tcp_in_tfc_rot = [0.0, 0.0, 0.0]

        self.tcp_in_tfc_trans = [23.8, -28.06898406, 311.2201606]    # Bauteile in Schunk
        self.tcp_in_tfc_rot = [2.54749762, 10.38190283, 37.52598048]       # (x und y Vorzeichen tauschen)
        
        self.set_frame(self.tcp_in_tfc_rot, self.tcp_in_tfc_trans, frame="tcp", ref_frame="tfc")

        # Instanz Hook Geometrics Handler
        self.hook_geometrics_handler = HookGeometricsHandler(
            distance_to_tip_in_mm = self.distance_to_tip_in_mm,
            global_scan_dict_filename = '/home/mo/Thesis/src/robot_control/robot_control/data/global_scan_dicts/global_hook_dict_horizontal.csv')           # /home/mo/Thesis/Evaluation/1_Scan-Prozess/1_Triangulationsmethoden/1_Horizontale-Triangulation/d_50/global_hook_dict_horizontal.csv

        # Instanz DOKUMENTATION Plot-Fkt
        self.doc_plot = DocPlotAttachment(plot_save_filename='/home/mo/Thesis/src/robot_control/robot_control/data/controller_output_logging', hook_num = self.hook_num)
        self.doc_plot.initialize_plot()

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = 'frame_handler_for_dummy_node')

        # Instanz Gripper Handler
        # self.gripper_handler = GripperHandler()
        # self.gripper_handler.gripper_startup()
        # self.gripper_handler.open_gripper()

        # Instanz des MoveLinearServiceClient
        self.move_lin_client = MoveLinearServiceClient()
        self.move_ptp_client = MovePTPServiceClient()

        # Bewege Roboter auf Pre Pose in Mitte von Gestell
        # init_position_tcp_in_workframe = [662.7679417387326, -457.86324018092, 10.694603651697957]
        init_position_tcp_in_workframe = [500.0, -450.0, 10.0]
        init_rotation_tcp_in_workframe = [0.0, 0.0, 0.0]

        self.init_position_tcp_in_worldframe, self.init_rotation_tcp_in_worldframe = self.frame_handler.transform_pose_to_world(
            pose_ref_frame = 'work',
            trans = init_position_tcp_in_workframe,
            rot = init_rotation_tcp_in_workframe
        )

        if self.init_position_tcp_in_worldframe is not None and self.init_rotation_tcp_in_worldframe is not None:
            self.movement_done = False
            self.movement_done = self.move_ptp_client.call_move_ptp_service(
                pos = self.init_position_tcp_in_worldframe,
                rot = self.init_rotation_tcp_in_worldframe,
                ref = 0,
                ttype = 0,
                tvalue = 150.0,
                bpoint = 0,
                btype = 0,
                bvalue = 100.0,
                sync = 0.0,
                chaining = 0
            )
        while self.movement_done == False:
            self.get_logger().warn("Movement...")
        self.get_logger().warn("Movement done!")

        '''
        ########## Bewege Roboter auf die Startposition und anschließend auf die Ausgleichsposition (wegen LIN-Bewegung) ##########
        # Bewegung zum Init-Startpunkt in der Mitte des Gestells
        init_position_tfc_in_workframe = [662.7679417387326, -457.86324018092, 10.694603651697957]
        init_rotation_tfc_in_workframe = [0.0, 0.0, 0.0]
        self.init_position_tfc_in_worldframe, self.init_rotation_tfc_in_worldframe = self.frame_handler.transform_pose_to_world(
            pose_ref_frame = 'work',
            trans = init_position_tfc_in_workframe,
            rot = init_rotation_tfc_in_workframe
        )

        self.start_position_tfc_in_worldframe, self.start_rotation_tfc_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = startpoint_trans_in_workframe,
            rot = startpoint_rot_in_workframe,
            pose_ref_frame = 'work')
        
        self.init_movement_done = False
        if self.init_position_tfc_in_worldframe is not None and self.init_rotation_tfc_in_worldframe is not None:
            self.init_movement_done = False
            self.init_movement_done = self.move_lin_client.call_move_linear_service(
                pos = self.init_position_tfc_in_worldframe,
                rot = self.init_rotation_tfc_in_worldframe,
                ref = 0,
                ttype = 0,
                tvalue = 150.0,
                bpoint = 0,
                btype = 0,
                bvalue = 100.0,
                sync = 0.0,
                chaining = 0)
            
        if self.init_movement_done == True:
            self.init_movement_done = False
            self.get_logger().info("Init movement done successfully!")
        else:
            self.get_logger().error("Init movement failed!")

        self.startpoint_movement_done = False
        if self.start_rotation_tfc_in_worldframe is not None and self.start_position_tfc_in_worldframe is not None:
            self.startpoint_movement_done = False
            self.startpoint_movement_done = self.move_lin_client.call_move_linear_service(
                pos = self.start_position_tfc_in_worldframe,
                rot = self.start_rotation_tfc_in_worldframe,
                ref = 0,
                ttype = 0,
                tvalue = 100.0,
                bpoint = 0,
                btype = 0,
                bvalue = 100.0,
                sync = 0.0,
                chaining = 0)
            
        if self.startpoint_movement_done == True:
            self.startpoint_movement_done = False
            self.get_logger().info("Startpose movement done successfully!")
        else:
            self.get_logger().error("Startpose movement failed!")
        ###########################################################
        '''


        '''
        ########## Positionen Greifer ##########
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
        ###########################################################'
        '''

        ########## Aufruf Trajektorienberechnung ##########
        # Berechne die Trajektorie basierend auf den Hook-Daten
        time.sleep(5)
        # xyz, rpy = self.hook_geometrics_handler.update_hook_data(hook_num=self.hook_num)
        # self.hook_geometrics_handler.calculate_hook_line()
        
        # Trajektorie als Liste von Punkten, wobei jeder Punkt ein Tupel aus (Translation, Rotation) ist
        self.trajectory_1 = self.hook_geometrics_handler.plan_path_point_trajectory(hook_num = self.hook_num)
        self.trajectory_2 = self.hook_geometrics_handler.plan_trajectory_with_fixed_orientation(hook_num = self.hook_num)
        self.trajectory_3 = self.hook_geometrics_handler.plan_trajectory_with_optimized_orientation(hook_num = self.hook_num, hook_type = 'a', beta = 1.0)
        self.trajectory_4 = self.hook_geometrics_handler.plan_optimized_trajectory(hook_num = self.hook_num, hook_type = 'a', beta = 0, attachment_distance_in_mm = 5)

        # Zur Evaluation - speichern der Trajektorien als CSV
        self.save_traj_in_workframe_as_csv(self.trajectory_1, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_1_work.csv')
        self.save_traj_in_workframe_as_csv(self.trajectory_2, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_2_work.csv')
        self.save_traj_in_workframe_as_csv(self.trajectory_3, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_3_work.csv')
        self.save_traj_in_workframe_as_csv(self.trajectory_4, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_4_work.csv')
        save_trajectory_to_csv(self.trajectory_1, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_1.csv')
        save_trajectory_to_csv(self.trajectory_2, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_2.csv')
        save_trajectory_to_csv(self.trajectory_3, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_3.csv')
        save_trajectory_to_csv(self.trajectory_4, '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_4.csv')

        self.trajectory = self.trajectory_4
        for k in range(len(self.trajectory)):
            print("Trajektorie im Hauptprogramm: ", self.trajectory[k])
        
        self.trajectory_point_num = 0
        
        
        ########## Bewegung zur Pre-Pose mit z-Offset ##########
        self.hook_pre_position, self.hook_pre_rotation = self.hook_geometrics_handler.calculate_pre_position_with_z_offset(trajectory_in_worldframe = self.trajectory, z_off_in_mm_in_workframe = 200)
        self.get_logger().warn(f"Starte Bewegung zu Pre-Position: Pose: {self.hook_pre_position}, Rotation: {self.hook_pre_rotation}")
        
        self.movement_done = False
        self.movement_done = self.move_ptp_client.call_move_ptp_service(
            pos = self.hook_pre_position,
            rot = self.hook_pre_rotation,
            ref = 0,
            ttype = 0,
            tvalue = 30.0,
            bpoint = 0,
            btype = 0,
            bvalue = 30.0,
            sync = 0.0,
            chaining = 0)
        while self.movement_done == False:
            self.get_logger().warn("Movement...")
        self.get_logger().warn("Movement done!")
        
        # Variablen und Plot für Trajektorien-Ansteuerung
        self.target_pos_trans_in_worldframe = None
        self.target_pos_rot_in_worldframe = None

        # Setze das Terminal in den "cbreak" Modus für non-blocking Tastatureingaben
        self.orig_term_settings = termios.tcgetattr(sys.stdin)
        tty.setcbreak(sys.stdin.fileno())

        # Timer zum periodischen Abfragen der Tastatur
        self.keyboard_timer = self.create_timer(0.1, self.check_keyboard)



    def save_traj_in_workframe_as_csv(self, traj_in_worldframe, savepath):
        """Methode zur Umrechnung der Trajektorie ins WORK-Frame und anschließenden Speicherung als CSV"""
        traj_in_workframe = []
        T_world_in_workframe = self.frame_handler.get_world_in_workframe()
        for traj_point in traj_in_worldframe:
            traj_pos_in_worldframe = traj_point[0]
            traj_rot_in_worldframe = traj_point[1]

            R_trajpoint_in_worldframe = self.frame_handler.calculate_rot_matrix(rot = traj_rot_in_worldframe)
            T_trajpoint_in_worldframe = np.eye(4)
            T_trajpoint_in_worldframe[:3, :3] = R_trajpoint_in_worldframe
            T_trajpoint_in_worldframe[:3, 3] = traj_pos_in_worldframe

            T_trajpoint_in_workframe = T_world_in_workframe @ T_trajpoint_in_worldframe

            traj_pos_in_workframe = T_trajpoint_in_workframe[:3, 3]
            traj_rot_in_workframe = self.frame_handler.rotation_matrix_to_euler_angles(rotation_matrix = T_trajpoint_in_workframe[:3, :3])

            print(traj_pos_in_workframe, traj_rot_in_workframe)
            # traj_pos_in_workframe = T_world_in_workframe @ np.hstack((traj_pos_in_worldframe, 1))
            # traj_rot_in_workframe = T_world_in_workframe[:3, :3] @ np.array(traj_rot_in_worldframe)
            # traj_in_workframe.append((traj_pos_in_workframe[:3].tolist(), traj_rot_in_workframe.tolist()))
            traj_in_workframe.append((traj_pos_in_workframe.tolist(), traj_rot_in_workframe.tolist()))
        save_trajectory_to_csv(trajectory = traj_in_workframe, filepath = savepath)




    def check_keyboard(self):
        """
        Überprüft non-blocking, ob eine Taste gedrückt wurde.
        Wenn 'n' gedrückt wurde, wird der Trajektorienindex inkrementiert und der nächste Punkt angesteuert.
        """
        if select.select([sys.stdin], [], [], 0)[0]:
            key = sys.stdin.read(1)
            if key == 'n':
                if self.trajectory_point_num == 0:      # wenn es sich um den resten Trajektorienpunkt handelt
                    initial_point = self.trajectory[self.trajectory_point_num]
                    print(initial_point)
                    self.target_pos_trans_in_worldframe = initial_point[0]
                    self.target_pos_rot_in_worldframe = initial_point[1]
                    self.prepare_and_update_plot()      # Plot updaten

                if self.trajectory_point_num < len(self.trajectory):        # wenn es sich um Path Point handelt
                    act_point = self.trajectory[self.trajectory_point_num]
                    self.target_pos_trans_in_worldframe = act_point[0]
                    self.target_pos_rot_in_worldframe = act_point[1]
                    self.prepare_and_update_plot()      # Plot updaten

                    self.get_logger().warn(f"Moving to current trajectory point {self.trajectory_point_num}")
                    self.get_logger().warn(f"Pose: {self.target_pos_trans_in_worldframe}, Rotation: {self.target_pos_rot_in_worldframe}")
                    
                    self.movement_done = False
                    self.movement_done = self.move_lin_client.call_move_linear_service(
                        pos = self.target_pos_trans_in_worldframe,
                        rot = self.target_pos_rot_in_worldframe,
                        ref = 0,
                        ttype = 0,
                        tvalue = 30.0,
                        bpoint = 0,
                        btype = 0,
                        bvalue = 100.0,
                        sync = 0.0,
                        chaining = 0)
                    while self.movement_done == False:
                        self.get_logger().warn("Movement...")
                    self.get_logger().warn("Movement done!")
                        
                else:
                    self.doc_plot.save_plot_as_png()
                    self.get_logger().info("Reached last trajectory point!")
                self.trajectory_point_num += 1



    def prepare_and_update_plot(self):
        """
        Methode für das Aufbereiten der Plot-Parameter mit anschließendem Update-Plot-Aufruf
        """
        self.doc_plot.update_plot_lists(
            target_trans_list = self.target_pos_trans_in_worldframe,
            target_rot_list = self.target_pos_rot_in_worldframe,
            num_trajectory_point = self.trajectory_point_num,
        )
        self.doc_plot.update_plot()
        
        

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