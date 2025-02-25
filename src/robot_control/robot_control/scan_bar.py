import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_dict_receive_processing import DictReceiveProcessor
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from FC.FC_edge_detector import EdgeDetector
from FC.FC_frame_handler import FrameHandler
from FC.FC_stereo_triangulation_processor import StereoTriangulationProcessor
from FC.FC_save_load_global_hook_dict import save_dict_to_csv
from FC.FC_parameterized_cubic_spline import ParameterizedCubicSplineCalculator
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.srv import SetSystemFrame
from std_msgs.msg import Int32
import os
import time
import numpy as np
import csv



class ScanBar(Node):
    def __init__(self):
        super().__init__('scan_bar')

        self.node_shutdown_flag = False

        self.declare_parameter('num_hooks_existing', 1)
        self.num_hooks_existing = self.get_parameter('num_hooks_existing').get_parameter_value().integer_value
        self.declare_parameter('speed_in_mm_per_s', 10.0)
        self.speed_in_mm_per_s = self.get_parameter('speed_in_mm_per_s').get_parameter_value().double_value

        # Sub Yolov8 Output
        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}

        # Instanz zum Entacken der Yolo Outputs
        self.hooks_dict_processor = DictReceiveProcessor(dual_cam_setup = False)
        self.yolo_hooks_dict = {}       # Dict für NN Output
        self.global_hooks_dict = {}     # Scan Dict (Ergebnis)

        # Timer und Flankendetektion für das Prüfen neuer Hakeninstanzen im Bild
        self.edge_detector_rside = EdgeDetector()
        self.edge_detector_lside = EdgeDetector()
        self.new_hook_in_picture = False
        self.hook_in_left_area = False
        self.timer_check_new_instances = self.create_timer(0.0001, self.check_for_new_hook_instance)     # starte Timer für Abfrage, ob am Bildrand ein neuer Haken erscheint
        self.previous_edge_rside = None
        self.previous_edge_lside = None
        self.handling_last_two_hooks = False
        self.handling_last_hook = False

        # Subscriber auf Bildgroesse
        self.img_width_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/width', self.received_img_width, 10)
        self.img_width_sub
        self.img_height_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/height', self.received_img_height, 10)
        self.img_height_sub
        self.img_width = 896
        self.img_height = 450

        # Variablen für Prozess
        self.act_hook_num = 0
        
        # Instanz FrameHandler
        frame_csv_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
        self.frame_handler = FrameHandler(node_name = 'frame_handler_node_for_scan_bar', save_path = frame_csv_path)
        self.cam_to_world_transform = None

        startpoint_trans_in_workframe = [160.0, -430.0, 80.0]
        startpoint_rot_in_workframe = [0.0, 0.0, 0.0]
        self.startpoint_trans_worldframe, self.startpoint_rot_worldframe = self.frame_handler.transform_pose_to_world(trans = startpoint_trans_in_workframe,
                                                                                                                      rot = startpoint_rot_in_workframe,
                                                                                                                      pose_ref_frame = 'work')
        
        # Publisher für Linear Servoing
        self.vel_lin_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

        # Service Client SelectJogging Frame
        self.select_jogging_frame_client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.select_jogging_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SelectJoggingFrame...")
        self.get_logger().info("Service SelectJoggingFrame available!")

        # Aufruf von SelectJoggingFrame -> Bewegung im WORLD-Frame
        req = SelectJoggingFrame.Request()
        req.ref = 0
        future = self.select_jogging_frame_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info("SelectJoggingFrame service call successful!")
        else:
            self.get_logger().error("Failed to call SelectJoggingFrame service")

        # Service Client SetSystemFrame
        self.set_kassow_frame_client = self.create_client(SetSystemFrame, '/kr/robot/set_system_frame')
        while not self.set_kassow_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Service SetSystemFrame...")
        self.get_logger().info("Service SetSystemFrame available!")

        # Set TCP-Frame auf TFC-Frame
        self.set_frame([0.0, 0.0, 0.0], [0.0, 0.0, 0.0], frame="tcp", ref_frame="tfc")

        # Timer für Prozess
        self.process_step = None
        self.process_timer = self.create_timer(0.001, self.process_main)
        self._help_movement_done = False
        self._help_movement_service_called = False
        self.upcoming_process_step = None
        self.wait_timer = None
        self.move_linear_client = MoveLinearServiceClient()
        

        ########## Bewege Roboter auf die Startposition ##########
        self.startpoint_movement_done = False
        if self.startpoint_rot_worldframe is not None and self.startpoint_trans_worldframe is not None:
            self.startpoint_movement_done = False
            self.startpoint_movement_done = self.move_linear_client.call_move_linear_service(pos = self.startpoint_trans_worldframe,
                                                                                             rot = self.startpoint_rot_worldframe,
                                                                                             ref = 0,
                                                                                             ttype = 0,
                                                                                             tvalue = 80.0,
                                                                                             bpoint = 0,
                                                                                             btype = 0,
                                                                                             bvalue = 100.0,
                                                                                             sync = 0.0,
                                                                                             chaining = 0)
        if self.startpoint_movement_done == True:
            self.startpoint_movement_done = False
            self.get_logger().info("Init movement done successfully!")
            self.process_step = "move_until_2_hooks_visible"
        else:
            self.get_logger().error("Init movement failed!")
        
        self.get_logger().info("Wait 5 sec...")
        time.sleep(5)
        ###########################################################
    


    def set_frame(self, R, T, frame = "tcp", ref_frame = "tfc"):
        request = SetSystemFrame.Request()
        request.name = frame
        request.ref = ref_frame
        request.pos = T
        request.rot = R

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



    def received_img_width(self, msg):
        self.img_width = msg.data

    def received_img_height(self, msg):
        self.img_height = msg.data
    
    

    def process_main(self):
        '''
        Prozessablauf mit Schrittkette - wird zyklisch alle 1ms aufgerufen
        '''

        # prüfe auf Flanken für Haken am Bildrand
        rside_rising_edge, rside_falling_edge = self.edge_detector_rside.detect_edge(var = self.new_hook_in_picture)
        lside_rising_edge, lside_falling_edge = self.edge_detector_lside.detect_edge(var = self.hook_in_left_area)



        # Fahre von Init Position solange nach rechts, bis 2 Haken zu sehen sind
        if self.process_step == "move_until_2_hooks_visible":
            """
            Fahre weiter, bis 2 Haken im Bild zu sehen sind (zu Beginn des Scan-Prozesses benötigt)
            """
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame = 'work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)

            if rside_falling_edge:
                self.previous_edge_rside = "falling"
            
            if rside_rising_edge and self.previous_edge_rside == "falling":
                self.previous_edge_rside = None
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                self.get_logger().info("Done! -> next process step <Extract Hook 2>")
                self.upcoming_process_step = "extract_hook_2"
                self.start_timer_for_step(3.0)    # Timer starten
                self.process_step = "waiting_for_timer"
        


        # Extrahiere Pixelkoordinaten von Haken 2 nach Beginn des Scans
        if self.process_step == "extract_hook_2":
            """
            Extrahieren von Haken_2
            """
            xyz_hook_in_camframe = np.array(self.yolo_hooks_dict['hook_2']['xyz_hook_in_camframe'])
            xyz_tip_in_camframe = np.array(self.yolo_hooks_dict['hook_2']['xyz_tip_in_camframe'])
            xyz_lowpoint_in_camframe = np.array(self.yolo_hooks_dict['hook_2']['xyz_lowpoint_in_camframe'])

            # Aktuelle Kameraposition im WORLD-Frame auslesen
            T_cam_in_worldframe = self.frame_handler.get_cam_transform_in_world()

            # Umrechnung von Hakenkoordinaten in WORLD-Frame
            xyz_hook_in_worldframe = T_cam_in_worldframe @ xyz_hook_in_camframe
            xyz_tip_in_worldframe = T_cam_in_worldframe @ xyz_tip_in_camframe
            xyz_lowpoint_in_worldframe = T_cam_in_worldframe @ xyz_lowpoint_in_camframe
            
            # Umrechnung von Hakenkoordinaten in WORK-Frame
            xyz_hook_in_workframe = self.frame_handler.transform_worldpoint_in_frame(point = xyz_hook_in_worldframe[:3])
            xyz_tip_in_workframe = self.frame_handler.transform_worldpoint_in_frame(point = xyz_tip_in_worldframe[:3])
            xyz_lowpoint_in_workframe = self.frame_handler.transform_worldpoint_in_frame(point = xyz_lowpoint_in_worldframe[:3])

            self.get_logger().info("Done! -> next process step <Move Until New Hook>")
            self.process_step = "save_hook"


        # Speicher die Daten des aktuellen Hakens
        if self.process_step == "save_hook":
            """
            Abspeichern des Hakenparameters
            - XYZ Koordinaten von Haken, Spitze, Senke
            --- im CAM-Frame, WORK-Frame
            - TFC-Roboterposition bei Aufnahme des Hakens
            --- TFC-Pose im WORK- und WORLD-Frame
            """
            self.act_hook_num += 1
            self.global_hooks_dict[str(self.act_hook_num)] = {}
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook'] = xyz_hook_in_camframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip'] = xyz_tip_in_camframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint'] = xyz_lowpoint_in_camframe

            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_in_worldframe'] = xyz_hook_in_worldframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_in_worldframe'] = xyz_tip_in_worldframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_in_worldframe'] = xyz_lowpoint_in_worldframe

            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_in_workframe'] = xyz_hook_in_workframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_in_workframe'] = xyz_tip_in_workframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_in_workframe'] = xyz_lowpoint_in_workframe
            
            self.get_logger().warn(f"Hook XYZ [WORK]: {self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_workframe']}")
            self.get_logger().warn(f"Tip XYZ [WORK]: {self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_workframe']}")
            self.get_logger().warn(f"Lowpoint XYZ [WORK]: {self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_workframe']}")

            self.get_logger().info(f"already scanned: {len(self.global_hooks_dict)} Hooks")

            if len(self.global_hooks_dict) == self.num_hooks_existing:
                self.get_logger().info("Done! -> next process step <Save Global Dict as CSV>")
                self.process_step = "save_global_dict_as_csv"
            else:
                self.get_logger().info("Done! -> next process step <Extract Hook 2 as Reference>")
                self.upcoming_process_step = "move_until_new_hook"
                self.start_timer_for_step(3.0)    # Timer starten
                self.process_step = "waiting_for_timer"



        # Fahre, bis neuer Haken erscheint
        if self.process_step == "move_until_new_hook":
            """
            Weiterfahren, bis im rechten Bildrand eine neue Hakeninstanz auftaucht, dann Stopp
            """
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame='work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)

            if rside_falling_edge:
                self.previous_edge_rside = "falling"
            
            if rside_rising_edge and self.previous_edge_rside == "falling":
                self.previous_edge_rside = None
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                if self.do_vibration_test:
                    self.get_logger().info("Done! -> next process step <Measure Vibration>")
                    self.first_measurement_iteration = True
                    self.vibration_data = {'time': [], 'uv_hook': [], 'uv_tip': [], 'uv_lowpoint': []}
                    self.process_step = "measure_vibration"
                else:
                    self.get_logger().info("Done! -> next process step <Extract Hook 3 as Horizontal Point>")
                    self.upcoming_process_step = "extract_hook_2"
                    self.start_timer_for_step(3.0)    # Timer starten
                    self.process_step = "waiting_for_timer"



        # Tiefeninterpolation für Spitze -> Senke
        if self.process_step == "interpolate_depth_shape":
            """
            Interpolieren der Tiefe für alle Wegpunkte zwischen Spitze und Senke
            """

            # Hole uv_tip und uv_lowpoint aus Dict
            uv_tip_ref = self.hook_ref['uv_tip']
            uv_lowpoint_ref = self.hook_ref['uv_lowpoint']
            uv_tip_horizontal = self.hook_horizontal['uv_tip']
            uv_lowpoint_horizontal = self.hook_horizontal['uv_lowpoint']

            # Berechnung der Pixelstrecke von Tip bis Lowpoint für u und v
            u_diff_ref = abs(uv_tip_ref[0] - uv_lowpoint_ref[0])
            v_diff_ref = abs(uv_tip_ref[1] - uv_lowpoint_ref[1])
            u_diff_horizontal = abs(uv_tip_horizontal[0] - uv_lowpoint_horizontal[0])
            v_diff_horizontal = abs(uv_tip_horizontal[1] - uv_lowpoint_horizontal[1])
            u_diff = int((u_diff_ref + u_diff_horizontal) / 2)      # Differenz von u_tip bis u_lowpoint in px
            v_diff = int((v_diff_ref + v_diff_horizontal) / 2)      # Differenz von v_tip bis v_lowpoint in px

            # Berechnung von mm_per_px in x- und y-Richtung
            x_tip, y_tip, z_tip = xyz_tip_in_workframe
            x_lowpoint, y_lowpoint, z_lowpoint = xyz_lowpoint_in_workframe
            x_diff = abs(x_tip - x_lowpoint)
            y_diff = abs(y_tip - y_lowpoint)
            mm_per_px_x = x_diff / v_diff           # Übersetzung mm pro Pixel in x-Richtung
            mm_per_px_y = y_diff / u_diff           # Übersetzung mm pro Pixel in y-Richtung

            # Berechnung von realen XY-Kordinaten der Path points
            uv_path_points = self.hook_ref['path_points']
            xy_path_points = []
            u_center = self.img_height / 2
            v_center = self.img_width / 2
            for p in uv_path_points:
                ppoint_u = p[0]
                ppoint_v = p[1]
                ppoint_x = (ppoint_v - v_center) * mm_per_px_x
                ppoint_y = (ppoint_u - u_center) * mm_per_px_y
                xy_path_points.append((ppoint_x, ppoint_y))

            # Berechnung von interpolierten Tiefenwerten für path_points
            path_points_xyz = self.spline_calculator.interpolate(xy_points = xy_path_points, 
                                                                 start_point_with_depth = xyz_tip_in_workframe, 
                                                                 end_point_with_depth = xyz_lowpoint_in_workframe)

            self.get_logger().info("Done! -> next process step <Save Hook>")
            self.process_step = "save_hook"



        # Fahre, bis Haken aus linkem Randbereich draußen
        if self.process_step == "move_until_hook_disappears":
            """
            Weiterfahren, bis der linke Hand im Bild verschwindet (wird für das Handling der letzten 2 Haken benötigt, da Überprüfung auf rechten Bildrand hier nicht mehr funktioniert)
            """
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame='work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)
            
            if lside_rising_edge:
                self.previous_edge_lside = None
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                self.get_logger().info("Done! -> next process step <Extract Hook 2 as Horizontal Point>")
                self.upcoming_process_step = "extract_hook_3_as_horizontal_point"
                self.start_timer_for_step(3.0)    # Timer starten
                self.process_step = "waiting_for_timer"



        # Speichern des Global Dict als CSV, wenn Scanvorgang fertig
        if self.process_step == "save_global_dict_as_csv":
            """
            Abspeichern des fertigen Dict mit allen Haken
            """
            save_dict_to_csv(node = self, data = self.global_hooks_dict, filename = 'src/robot_control/robot_control/data/global_scan_dicts/global_hook_dict_horizontal.csv')
            self.get_logger().info("Done! -> next process step <Finish>")
            self.process_step = "move_back_to_init"



        # Zurückfahren auf Startposition
        if self.process_step == "move_back_to_init":
            """
            Zurückfahren auf die ursprüngliche Startposition
            """
            self.startpoint_movement_done = self.move_linear_client.call_move_linear_service(pos = self.startpoint_trans_worldframe,
                                                                                             rot = self.startpoint_rot_worldframe,
                                                                                             ref = 0,
                                                                                             ttype = 0,
                                                                                             tvalue = 60.0,
                                                                                             bpoint = 0,
                                                                                             btype = 0,
                                                                                             bvalue = 100.0,
                                                                                             sync = 0.0,
                                                                                             chaining = 0)
            if self.startpoint_movement_done:
                self.get_logger().info("Done! -> next process step <Finish>")
                self.process_step = "finish"
        


        # Endzustand
        if self.process_step == "finish":
            """ Ednzustand -> Finish
            """
            self.get_logger().info("Scan finished!")
            self.node_shutdown_flag = True


    
    def start_timer_for_step(self, delay_sec):
        '''
        Starte einen Timer, der nach einer bestimmten Zeit den nächsten Schritt ausführt
        '''
        next_step = self.upcoming_process_step
        self.get_logger().info(f"Starting timer for {next_step} with {delay_sec} seconds delay")
        self.wait_timer = self.create_timer(delay_sec, self.timer_callback)

    def timer_callback(self):
        '''
        Callback, der nach Ablauf des Timers ausgeführt wird
        '''
        next_step = self.upcoming_process_step
        self.get_logger().info(f"Timer expired, switching to {next_step}")
        self.process_step = next_step
        self.wait_timer.cancel()
        self.wait_timer = None       



    def publish_linear_velocity(self, vel_in_worldframe):
        jog_msg = JogLinear()
        jog_msg.vel = vel_in_worldframe
        jog_msg.rot = [0.0, 0.0, 0.0]
        self.vel_lin_publisher.publish(jog_msg)



    def load_work_frame(self):
        '''
        Funktion für das Laden einer Transformation zwischen zwei Frames aus FrameHandler
        '''
        csv_name = 'WORK_frame_in_world.csv'
        transformation_matrix = self.frame_handler.load_transformation_matrix_from_csv(frame_name = csv_name)

        if transformation_matrix is not None:
            self.get_logger().info(f"Loaded matrix for frame '{csv_name}' successfully!")
            return transformation_matrix
        else:
            self.get_logger().error(f"Error while loading matrix for frame '{csv_name}'!")
            return None



    def hooks_dict_callback(self, msg):
        '''
        Callback für das Ankommen neuer Nachrichten aus NN Output
        '''
        self.yolo_hooks_dict = self.hooks_dict_processor.process_hooks_dict(msg)
            

        
    def shutdown_node(self):
        # Timer stoppen und Node zerstören
        self.process_timer.cancel()
        self.timer_check_new_instances.cancel()
        self.get_logger().info("Shutting down node...")
        self.destroy_node()
        rclpy.shutdown()



def main(args=None):
    rclpy.init(args=args)
    node = ScanBar()

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.001)
            if node.node_shutdown_flag:
                node.shutdown_node()
                break
    except KeyboardInterrupt:
        node.shutdown_node()

if __name__ == '__main__':
    main()
