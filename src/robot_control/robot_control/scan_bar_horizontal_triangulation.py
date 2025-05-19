import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_dict_receive_processing import DictReceiveProcessor
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from FC.FC_edge_detector import EdgeDetector
from FC.FC_frame_handler import FrameHandler
from FC.FC_triangulation_processor import StereoTriangulationProcessor
from FC.FC_save_load_global_hook_dict import save_dict_to_csv
from FC.FC_doc_visualization import DocVisualization
from FC.FC_call_move_ptp_service import MovePTPServiceClient
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.srv import SetSystemFrame
from std_msgs.msg import Int32, Bool
import os
import time
import numpy as np
import csv



class ScanBarHorizontalTriangulation(Node):
    def __init__(self):
        super().__init__('scan_bar_horizontal_triangulation')

        # startpoint_trans_in_workframe = [-10.0, -410.0, 30.0]       # Modell A
        startpoint_trans_in_workframe = [0.0, -410.0, 30.0]         # Modell B
        # startpoint_trans_in_workframe = [-10.0, -390.0, 30.0]       # Modell C
        # startpoint_trans_in_workframe = [-25.0, -395.0, -40.0]      # Modell D
        
        startpoint_rot_in_workframe = [0.0, 0.0, 0.0]

        # startpoint_trans_in_workframe = [100.0, -390.0, 20.0]      # Modell B mit seitlicher Kamera-Rotation
        # startpoint_rot_in_workframe = [0.0, -20.0, 0.0]

        self.node_shutdown_flag = False
        self.baseline_error = False

        self.declare_parameter('num_hooks_existing', 2)
        self.num_hooks_existing = self.get_parameter('num_hooks_existing').get_parameter_value().integer_value
        self.declare_parameter('do_vibration_test', False)
        self.do_vibration_test = self.get_parameter('do_vibration_test').get_parameter_value().bool_value
        self.declare_parameter('speed_in_mm_per_s', 10.0)
        self.speed_in_mm_per_s = self.get_parameter('speed_in_mm_per_s').get_parameter_value().double_value

        # Sub Yolov8 Output
        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}

        # Instanz zum Entpacken der Yolo Outputs
        self.hooks_dict_processor = DictReceiveProcessor(dual_cam_setup = False)
        self.yolo_hooks_dict = {}       # Dict für NN Output
        self.global_hooks_dict = {}     # Scan Dict (Ergebnis)

        # Timer für das Prüfen neuer Hakeninstanzen im Bild
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
        self.img_width = 896
        self.img_height = 480
        self.img_width_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/width', self.received_img_width, 10)
        self.img_width_sub
        self.img_height_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/height', self.received_img_height, 10)
        self.img_height_sub

        # Publisher für Filter-Schaltung bei NN Output
        self.nn_output_filter_publisher = self.create_publisher(Bool, 'vision/nn_output_filter/enable', 10)
        filter_enabled = Bool()
        filter_enabled.data = False
        self.nn_output_filter_publisher.publish(filter_enabled)

        # Variablen für Prozess
        self.hook_ref = {}
        self.hook_horizontal = {}
        self.act_hook_num = 0
        self.path_point_triangulation_successful = False
        self.xyz_path_points_in_camframe = None
        self.hook_extraction_done = False

        # Dict für die Aufzeichnung von Schwingungsdaten
        self.vibration_data = {'time': [], 'uv_hook': [], 'uv_tip': [], 'uv_lowpoint': []}  # Schwingungsdaten
        self.first_measurement_iteration = True
        self.measurement_start_time = None
        self.measure_hook_2 = True

        # Instanz Doku Plotfenster
        self.doc_visualizer = DocVisualization(plot_save_filename = 'src/robot_control/robot_control/data/global_scan_dicts/horizontal_scan_plot.png')
        # self.doc_visualizer.init_plot()

        self.T_cam_in_workframe_ref = None
        self.T_cam_in_worldframe_ref = None
        self.T_cam_in_workframe_horizontal = None
        self.T_cam_in_worldframe_horizontal = None

        # Instanz für Berechnung der Stereo Triangulation
        self.triangulation_processor = StereoTriangulationProcessor(
            calib_path = '/home/mo/Thesis/calibration_data.npz',
            measure_time = True,
            img_width = self.img_width,
            img_height = self.img_height)
        
        # Instanz FrameHandler
        frame_csv_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
        self.frame_handler = FrameHandler(node_name = 'frame_handler_node_for_scan_bar', save_path = frame_csv_path)
        self.cam_to_world_transform = None

        # Transformation der Startpose in das WORLD-Frame
        self.start_position_tfc_in_worldframe, self.start_rotation_tfc_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = startpoint_trans_in_workframe,
            rot = startpoint_rot_in_workframe,
            pose_ref_frame = 'work')

        # Publisher für Linear Servoing
        self.vel_lin_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

        # Service Client SelectJogging Frame
        self.select_jogging_frame_client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.select_jogging_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SelectJoggingFrame...")
        self.get_logger().info("Service SelectJoggingFrame available!")

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
        self.set_frame(trans = [0.0, 0.0, 0.0], rot = [0.0, 0.0, 30.0], frame = "tcp", ref_frame = "tfc")

        # Timer für Prozess
        self.process_step = None
        self.process_cycle_time = 0.001
        self.process_timer = self.create_timer(self.process_cycle_time, self.process_main)
        self.process_time_val = time.perf_counter()
        self.upcoming_process_step = None
        self.wait_timer = None
        self.move_linear_client = MoveLinearServiceClient()
        self.move_ptp_client = MovePTPServiceClient()

        # Bewegung zum Init-Startpunkt in der Mitte des Gestells
        init_position_tfc_in_workframe = [662.7679417387326, -457.86324018092, 10.694603651697957]
        init_rotation_tfc_in_workframe = [0.0, 0.0, 0.0]
        self.init_position_tfc_in_worldframe, self.init_rotation_tfc_in_worldframe = self.frame_handler.transform_pose_to_world(
            pose_ref_frame = 'work',
            trans = init_position_tfc_in_workframe,
            rot = init_rotation_tfc_in_workframe
        )

        ########## Bewege Roboter auf die Startposition ##########
        self.init_movement_done = False
        if self.init_position_tfc_in_worldframe is not None and self.init_rotation_tfc_in_worldframe is not None:
            self.init_movement_done = False
            self.init_movement_done = self.move_linear_client.call_move_linear_service(
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
            self.process_step = "move_until_2_hooks_visible"
        else:
            self.get_logger().error("Init movement failed!")
        
        self.startpoint_movement_done = False
        if self.start_rotation_tfc_in_worldframe is not None and self.start_position_tfc_in_worldframe is not None:
            self.startpoint_movement_done = False
            self.startpoint_movement_done = self.move_linear_client.call_move_linear_service(
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
            self.process_step = "move_until_2_hooks_visible"
        else:
            self.get_logger().error("Startpose movement failed!")
        
        # self.get_logger().info("Wait 5 sec...")
        time.sleep(1)
        ###########################################################

        self.scan_process_start_time = time.perf_counter()
        self.scan_process_end_time = None
    


    def set_frame(self, trans, rot, frame="tcp", ref_frame="tfc"):
        """
        Funktion für Service Call von SetSystemFrame
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



    def received_img_width(self, msg):
        """
        Topic-Callback für Bildaufloesung Breite
        """
        self.img_width = msg.data

    def received_img_height(self, msg):
        """
        Topic-Callback für Bildauflösung Höhe
        """
        self.img_height = msg.data
    
    

    def process_main(self):
        """
        Prozessablauf mit Schrittkette - wird zyklisch alle 1ms aufgerufen
        """
        '''
        ##### Berechne Zykluszeit
        t = time.perf_counter() - self.process_time_val
        self.process_time_val = time.perf_counter()
        if t > self.process_cycle_time:
            self.get_logger().warn(f"Process Cycle Time - {t:.4f}")
        '''

        ##### prüfe auf Flanken für Haken am Bildrand
        rside_rising_edge, rside_falling_edge = self.edge_detector_rside.detect_edge(var=self.new_hook_in_picture)
        lside_rising_edge, lside_falling_edge = self.edge_detector_lside.detect_edge(var=self.hook_in_left_area)


        ##### Fahre von Init Position solange nach rechts, bis 2 Haken zu sehen sind
        if self.process_step == "move_until_2_hooks_visible":
            """
            Fahre weiter, bis 2 Haken im Bild zu sehen sind (zu Beginn des Scan-Prozesses benötigt)
            """
            # setze und publishe Geschwindigkit für Regelung
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.transform_velocity_to_world(vel = vel_work, from_frame = 'work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)
            
            # Prüfen, ob neuer Haken detektiert
            if rside_falling_edge:
                self.previous_edge_rside = "falling"
            # wenn detektiert:
            if rside_rising_edge and self.previous_edge_rside == "falling":
                self.previous_edge_rside = None

                # Roboter stoppen
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                
                # Filter NN Output aktivieren
                filter_enabled = Bool()
                filter_enabled.data = True
                self.nn_output_filter_publisher.publish(filter_enabled)

                ##### Nächster Prozessschritt
                self.get_logger().info("Done! -> next process step <Extract Hook 2 as initial Reference Point>")
                self.upcoming_process_step = "extract_hook_2_as_init_ref"
                self.start_timer_for_step(2.0)    # Timer starten
                self.process_step = "waiting_for_timer"


        ##### Doku - Messung der Schwingung nach Stillstand
        if self.process_step == "measure_vibration":
            """
            Messung der Vibrationen nach einem Roboterstopp (zu Testzwecken)
            """
            self.get_logger().info("Measuring vibration...")
            if self.first_measurement_iteration == True:
                self.measurement_start_time = time.perf_counter()
                self.first_measurement_iteration = False

            vibration_duration = 10
            current_time = time.perf_counter() - self.measurement_start_time

            if current_time < vibration_duration:
                if self.measure_hook_2:
                    uv_hook = self.yolo_hooks_dict['hook_2']['uv_hook']
                    uv_tip = self.yolo_hooks_dict['hook_2']['uv_tip']
                    uv_lowpoint = self.yolo_hooks_dict['hook_2']['uv_lowpoint']
                else:
                    uv_hook = self.yolo_hooks_dict['hook_3']['uv_hook']
                    uv_tip = self.yolo_hooks_dict['hook_3']['uv_tip']
                    uv_lowpoint = self.yolo_hooks_dict['hook_3']['uv_lowpoint']

                self.vibration_data['time'].append(time.time())
                self.vibration_data['uv_hook'].append(uv_hook)
                self.vibration_data['uv_tip'].append(uv_tip)
                self.vibration_data['uv_lowpoint'].append(uv_lowpoint)
                # time.sleep(0.0001)
            else:
                if self.measure_hook_2:
                    self.measure_hook_2 = False
                else:
                    self.measure_hook_2 = True

                self.save_vibration_data_to_csv()

                ##### Nächster Prozessschritt
                self.get_logger().info("Done! -> next process step <Extract Hook 2 als initial Reference Point>")
                self.process_step = "extract_hook_2_as_init_ref"


        ##### Extrahiere Pixelkoordinaten von Haken 2 nach Beginn des Scans
        if self.process_step == "extract_hook_2_as_init_ref":
            """
            Extrahieren des ersten Haken_2 als initiale Referenz für Triangulation des ersten Hakens
            """
            if self.yolo_hooks_dict['hook_2']['path_points'] is not None:         # wenn path_points im Dict vefügbar
                self.hook_ref['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
                self.hook_ref['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
                self.hook_ref['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']
                self.hook_ref['path_points'] = self.yolo_hooks_dict['hook_2']['path_points']
                self.hook_extraction_done = True
            else:       # wenn 'path_points' gerade nicht vergübar, warte nächsten Prozesszyklus ab, bis verfügbar
                self.hook_extraction_done = False

            if self.hook_extraction_done == True:        # nächster Prozessschritt nur, wenn Hook erfolgreich extrahiert
                # CAM Pose in WORK speichern
                self.T_cam_in_workframe_ref = self.frame_handler.get_cam_transform_in_workframe()
                self.T_cam_in_worldframe_ref = self.frame_handler.get_cam_transform_in_world()

                # Filter NN Output ausschalten
                filter_enabled = Bool()
                filter_enabled.data = False
                self.nn_output_filter_publisher.publish(filter_enabled)

                ##### Nächster Prozessschritt
                self.get_logger().info("Done! -> next process step <Move Until New Hook>")
                self.process_step = "move_until_new_hook"


        ##### Fahre, bis neuer Haken erscheint
        if self.process_step == "move_until_new_hook":
            """
            Weiterfahren, bis im rechten Bildrand eine neue Hakeninstanz auftaucht, dann Stopp
            """
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.transform_velocity_to_world(vel = vel_work, from_frame='work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)

            if rside_falling_edge:
                self.previous_edge_rside = "falling"
            
            if rside_rising_edge and self.previous_edge_rside == "falling":
                self.previous_edge_rside = None
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)

                # Filter NN Output einschalten
                filter_enabled = Bool()
                filter_enabled.data = True
                self.nn_output_filter_publisher.publish(filter_enabled)

                ##### Nächster Prozessschritt
                if self.do_vibration_test:
                    self.get_logger().info("Done! -> next process step <Measure Vibration>")
                    self.first_measurement_iteration = True
                    self.vibration_data = {'time': [], 'uv_hook': [], 'uv_tip': [], 'uv_lowpoint': []}
                    self.process_step = "measure_vibration"
                else:
                    self.get_logger().info("Done! -> next process step <Extract Hook 3 as Horizontal Point>")
                    self.upcoming_process_step = "extract_hook_3_as_horizontal_point"
                    self.start_timer_for_step(2.0)    # Timer starten
                    self.process_step = "waiting_for_timer"
        

        ##### Extrahiere Pixelkoordinaten von Haken 3 (war vorher Haken 2)
        if self.process_step == "extract_hook_3_as_horizontal_point":
            """
            Extrahieren von Haken 3 (links im Bild) als zweiter Punkt für Triangulation
            """
            if self.handling_last_two_hooks:
                if self.yolo_hooks_dict['hook_2']['path_points'] is not None:         # wenn path_points im Dict vefügbar
                    self.hook_horizontal['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
                    self.hook_horizontal['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
                    self.hook_horizontal['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']
                    self.hook_horizontal['path_points'] = self.yolo_hooks_dict['hook_2']['path_points']
                    self.hook_extraction_done = True
                else:
                    self.hook_extraction_done = False
            elif self.handling_last_hook:
                if self.yolo_hooks_dict['hook_1']['path_points'] is not None:         # wenn path_points im Dict vefügbar
                    self.hook_horizontal['uv_hook'] = self.yolo_hooks_dict['hook_1']['uv_hook']
                    self.hook_horizontal['uv_tip'] = self.yolo_hooks_dict['hook_1']['uv_tip']
                    self.hook_horizontal['uv_lowpoint'] = self.yolo_hooks_dict['hook_1']['uv_lowpoint']
                    self.hook_horizontal['path_points'] = self.yolo_hooks_dict['hook_1']['path_points']
                    self.hook_extraction_done = True
                else:
                    self.hook_extraction_done = False
            else:
                if self.yolo_hooks_dict['hook_3']['path_points'] != []:         # wenn path_points im Dict vefügbar
                    self.hook_horizontal['uv_hook'] = self.yolo_hooks_dict['hook_3']['uv_hook']
                    self.hook_horizontal['uv_tip'] = self.yolo_hooks_dict['hook_3']['uv_tip']
                    self.hook_horizontal['uv_lowpoint'] = self.yolo_hooks_dict['hook_3']['uv_lowpoint']
                    self.hook_horizontal['path_points'] = self.yolo_hooks_dict['hook_3']['path_points']
                    self.hook_extraction_done = True
                else:
                    self.hook_extraction_done = False

            if self.hook_extraction_done == True:
                # CAM Pose in WORK speichern
                self.T_cam_in_workframe_horizontal = self.frame_handler.get_cam_transform_in_workframe()
                self.T_cam_in_worldframe_horizontal = self.frame_handler.get_cam_transform_in_world()

                # Filter NN Output ausschalten
                filter_enabled = Bool()
                filter_enabled.data = False
                self.nn_output_filter_publisher.publish(filter_enabled)

                ##### Nächster Prozessschritt
                self.get_logger().info("Done! -> next process step <Horizontal Triangulation>")
                self.process_step = "horizontal_triangulation"


        ##### Horizontale Triangulation
        if self.process_step == "horizontal_triangulation":
            """
            Horizontale Triangulation (Berechnung der realen Koordinaten der Hakenpunkte)
            """
            ##### Berechnung der Baseline
            horizontal_baseline_vector = self.T_cam_in_workframe_horizontal[:3, 3] - self.T_cam_in_workframe_ref[:3, 3]
            baseline_along_x = horizontal_baseline_vector[0]
            self.get_logger().info(f"Baseline along X axis: {baseline_along_x} mm")
            
            self.path_point_triangulation_successful = False

            ##### Berechne Triangulation für Hook, Tip, Lowpoint
            if baseline_along_x == 0:
                self.get_logger().error(f"!!!!!!!!!!!!!!!!!!!!")
                self.get_logger().error("ERROR either in moving robot or in position acquisition!")
                self.get_logger().error(f"!!!!!!!!!!!!!!!!!!!!")
                self.baseline_error = True
                self.process_step = "move_back_to_init"
            else:
                xyz_hook_in_camframe, time1 = self.triangulation_processor.triangulate_single_point(
                    point_1_uv = self.hook_ref['uv_hook'], 
                    point_2_uv = self.hook_horizontal['uv_hook'], 
                    T_cam_1_in_workframe = self.T_cam_in_workframe_ref, 
                    T_cam_2_in_workframe = self.T_cam_in_workframe_horizontal)
                
                xyz_tip_in_camframe, time2 = self.triangulation_processor.triangulate_single_point(
                    point_1_uv = self.hook_ref['uv_tip'], 
                    point_2_uv = self.hook_horizontal['uv_tip'], 
                    T_cam_1_in_workframe = self.T_cam_in_workframe_ref, 
                    T_cam_2_in_workframe = self.T_cam_in_workframe_horizontal)
                
                xyz_lowpoint_in_camframe, time3 = self.triangulation_processor.triangulate_single_point(
                    point_1_uv = self.hook_ref['uv_lowpoint'], 
                    point_2_uv = self.hook_horizontal['uv_lowpoint'], 
                    T_cam_1_in_workframe = self.T_cam_in_workframe_ref, 
                    T_cam_2_in_workframe = self.T_cam_in_workframe_horizontal)
                
                time_token = time1 + time2 + time3      # Berechnungszeiten aller drei Punkten addieren
                

                ##### Berechne Triangulation für Path Points
                uv_path_points_ref = self.hook_ref['path_points']
                uv_path_points_horizontal = self.hook_horizontal['path_points']

                if uv_path_points_ref is not None and uv_path_points_horizontal is not None:
                    self.path_point_triangulation_successful = True
                    self.xyz_path_points_in_camframe, time_token_ppoint_triangulation = self.triangulation_processor.triangulate_path_points(                    
                        uv_path_points_1 = uv_path_points_ref, 
                        uv_path_points_2 = uv_path_points_horizontal,
                        T_cam_1_in_workframe = self.T_cam_in_workframe_ref, 
                        T_cam_2_in_workframe = self.T_cam_in_workframe_horizontal)

                    uv_path_points_ref = None
                    uv_path_points_horizontal = None
                else:
                    self.xyz_path_points_in_camframe = None
                    self.path_point_triangulation_successful = False
                    time_token_ppoint_triangulation = None
                    self.get_logger().error(f"No path points available for triangulation!")
                
                ##### Nächster Prozessschritt
                self.get_logger().info("Done! -> next process step <Save Hook>")
                self.process_step = "save_hook"


        ##### Speicher die Daten des aktuellen Hakens
        if self.process_step == "save_hook":
            """
            Abspeichern aller Hakenparameter
            - XYZ Koordinaten von Haken, Spitze, Senke
            --- im CAM-Frame, WORK-Frame
            - TFC-Roboterposition bei Aufnahme des Hakens
            --- TFC-Pose im WORK- und WORLD-Frame
            """
            # Inkrement für Dict-Zuordnung
            self.act_hook_num += 1
            self.global_hooks_dict[str(self.act_hook_num)] = {}

            ##### Umrechnung der Punkte XYZ von Hook, Tip und Lowpoint in das aktuelle WORK-Frame
            xyz_hook_in_camframe_hom = np.array([xyz_hook_in_camframe[0], xyz_hook_in_camframe[1], xyz_hook_in_camframe[2]]).reshape(3, 1)
            xyz_hook_in_camframe_hom = np.vstack((xyz_hook_in_camframe_hom, [[1]]))  # -> (4, 1)
            xyz_hook_in_workframe = self.T_cam_in_workframe_horizontal @ xyz_hook_in_camframe_hom               # Umrechnung in WORK
            xyz_hook_in_workframe = xyz_hook_in_workframe[:3]
            xyz_hook_in_worldframe = self.T_cam_in_worldframe_horizontal @ xyz_hook_in_camframe_hom             # Umrechnung in WORLD
            xyz_hook_in_worldframe = xyz_hook_in_worldframe[:3]

            xyz_tip_in_camframe_hom = np.array([xyz_tip_in_camframe[0], xyz_tip_in_camframe[1], xyz_tip_in_camframe[2]]).reshape(3, 1)
            xyz_tip_in_camframe_hom = np.vstack((xyz_tip_in_camframe_hom, [[1]]))  # -> (4, 1)
            xyz_tip_in_workframe = self.T_cam_in_workframe_horizontal @ xyz_tip_in_camframe_hom                 # Umrechnung in WORK
            xyz_tip_in_workframe = xyz_tip_in_workframe[:3]
            xyz_tip_in_worldframe = self.T_cam_in_worldframe_horizontal @ xyz_tip_in_camframe_hom               # Umrechung in WORLD
            xyz_tip_in_worldframe = xyz_tip_in_worldframe[:3]

            xyz_lowpoint_in_camframe_hom = np.array([xyz_lowpoint_in_camframe[0], xyz_lowpoint_in_camframe[1], xyz_lowpoint_in_camframe[2]]).reshape(3, 1)
            xyz_lowpoint_in_camframe_hom = np.vstack((xyz_lowpoint_in_camframe_hom, [[1]]))  # -> (4, 1)
            xyz_lowpoint_in_workframe = self.T_cam_in_workframe_horizontal @ xyz_lowpoint_in_camframe_hom       # Umrechnung in WORK
            xyz_lowpoint_in_workframe = xyz_lowpoint_in_workframe[:3]
            xyz_lowpoint_in_worldframe = self.T_cam_in_worldframe_horizontal @ xyz_lowpoint_in_camframe_hom     # Umrechung in WORLD
            xyz_lowpoint_in_worldframe = xyz_lowpoint_in_worldframe[:3]

            ##### Umrechnung der XYZ Path Points vom CAM-Frame ins WORK-Frame
            xyz_path_points_in_workframe = []
            if self.xyz_path_points_in_camframe is not None:
                for ppoint in self.xyz_path_points_in_camframe:
                    ppoint_xyz_hom = np.append(ppoint, 1)
                    xyz_ppoint_in_workframe = self.T_cam_in_workframe_horizontal @ ppoint_xyz_hom
                    xyz_path_points_in_workframe.append(xyz_ppoint_in_workframe[:3])

            ##### Speichern der Koordinaten in restlichen Frames CAM, WORLD
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_in_camframe'] = xyz_hook_in_camframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_in_camframe'] = xyz_tip_in_camframe
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_in_camframe'] = xyz_lowpoint_in_camframe

            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_in_worldframe'] = xyz_hook_in_worldframe[:3]
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_in_worldframe'] = xyz_tip_in_worldframe[:3]
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_in_worldframe'] = xyz_lowpoint_in_worldframe[:3]

            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_in_workframe'] = xyz_hook_in_workframe.flatten().tolist()
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_in_workframe'] = xyz_tip_in_workframe.flatten().tolist()
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_in_workframe'] = xyz_lowpoint_in_workframe.flatten().tolist()

            self.global_hooks_dict[str(self.act_hook_num)]['xyz_path_points_in_workframe'] = xyz_path_points_in_workframe

            tfc_in_worldframe_horizontal, _, T_robot_position_horizontal = self.frame_handler.get_system_frame(name = 'tfc', ref = 'world')
            tfc_in_workframe_horizontal = self.frame_handler.transform_worldpoint_in_frame(T_robot_position_horizontal[:3, 3], 'work')
            self.global_hooks_dict[str(self.act_hook_num)]['tfc_in_workframe'] = tfc_in_workframe_horizontal
            self.global_hooks_dict[str(self.act_hook_num)]['tfc_in_worldframe'] = tfc_in_worldframe_horizontal

            ##### Ausgabe der aktuellen Daten
            self.get_logger().warn(f"------------------------------------------------------------------")
            self.get_logger().warn(f"Data for hook {self.act_hook_num}")
            self.get_logger().warn(f"Hook XYZ [horizontal]: {self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_in_workframe']}")
            self.get_logger().warn(f"Lowpoint XYZ [horizontal]: {self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_in_workframe']}")
            self.get_logger().warn(f"Tip XYZ [horizontal]: {self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_in_workframe']}")
            if time_token_ppoint_triangulation is not None:
                self.get_logger().warn(f"Time token for path points triangulation [horizontal]: {time_token_ppoint_triangulation:.6f} sec")
                self.get_logger().warn(f"Path points XYZ [horizontal]: {self.global_hooks_dict[str(self.act_hook_num)]['xyz_path_points_in_workframe']}")
            self.get_logger().warn(f"Time token for hook triangulation [horizontal]: {time_token:.6f} sec")
            self.get_logger().warn(f"already scanned: {len(self.global_hooks_dict)} Hooks")
            self.get_logger().warn(f"------------------------------------------------------------------")

            
            ##### Visualisierung aktualisieren
            self.doc_visualizer.update_lists(hook_point = xyz_hook_in_workframe.flatten().tolist(),
                                             lowpoint_point = xyz_lowpoint_in_workframe.flatten().tolist(),
                                             tip_point = xyz_tip_in_workframe.flatten().tolist(),
                                             path_points = xyz_path_points_in_workframe)
            self.doc_visualizer.update_plot()
            
            ##### Nächster Prozessschritt
            if len(self.global_hooks_dict) == self.num_hooks_existing:
                self.get_logger().info("Done! -> next process step <Save Global Dict as CSV>")
                self.process_step = "save_global_dict_as_csv"
            else:
                self.get_logger().info("Done! -> next process step <Extract Hook 2 as Reference>")
                # self.upcoming_process_step = "extract_hook_2_as_ref"
                # self.start_timer_for_step(2.0)    # Timer starten
                # self.process_step = "waiting_for_timer"
                self.get_logger().warn(f"actual process duration: {((time.perf_counter() - self.scan_process_start_time) / 60):.4f} min")
                self.process_step = "extract_hook_2_as_ref"


        ##### Extrahiere Pixelkoordinaten von Haken 2 während Prozess
        if self.process_step == "extract_hook_2_as_ref":
            """
            Extrahieren von Haken 2 (rechts im Bild) als Referenzpunkt für die Triangulation
            """
            if self.handling_last_two_hooks:
                if self.yolo_hooks_dict['hook_1']['path_points'] is not None:         # wenn path_points im Dict vefügbar
                    self.hook_ref['uv_hook'] = self.yolo_hooks_dict['hook_1']['uv_hook']
                    self.hook_ref['uv_tip'] = self.yolo_hooks_dict['hook_1']['uv_tip']
                    self.hook_ref['uv_lowpoint'] = self.yolo_hooks_dict['hook_1']['uv_lowpoint']
                    self.hook_ref['path_points'] = self.yolo_hooks_dict['hook_1']['path_points']
                    self.hook_extraction_done = True
                else:       # wenn 'path_points' gerade nicht vergübar, warte nächsten Prozesszyklus ab, bis verfügbar
                    self.hook_extraction_done = False

            else:
                if self.yolo_hooks_dict['hook_2']['path_points'] is not None:         # wenn path_points im Dict vefügbar
                    self.hook_ref['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
                    self.hook_ref['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
                    self.hook_ref['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']
                    self.hook_ref['path_points'] = self.yolo_hooks_dict['hook_2']['path_points']
                    self.hook_extraction_done = True
                else:       # wenn 'path_points' gerade nicht vergübar, warte nächsten Prozesszyklus ab, bis verfügbar
                    self.hook_extraction_done = False

            if self.hook_extraction_done == True:        # nächster Prozessschritt nur, wenn Hook erfolgreich extrahiert
                self.T_cam_in_workframe_ref = self.frame_handler.get_cam_transform_in_workframe()
                self.T_cam_in_worldframe_ref = self.frame_handler.get_cam_transform_in_world()

                ##### Nächster Prozessschritt
                if len(self.global_hooks_dict) == (self.num_hooks_existing - 2):
                    self.handling_last_two_hooks = True
                    self.handling_last_hook = False
                    self.get_logger().info("Done! -> next process step <Move Until Hook Disappears>")
                    self.process_step = "move_until_hook_disappears"
                elif len(self.global_hooks_dict) == (self.num_hooks_existing - 1):
                    self.handling_last_two_hooks = False
                    self.handling_last_hook = True
                    self.get_logger().info("Done! -> next process step <Move Until Hook Disappears>")
                    self.process_step = "move_until_hook_disappears"
                else:
                    self.get_logger().info("Done! -> next process step <Move Until New Hook>")
                    self.process_step = "move_until_new_hook"


        ##### Fahre, bis Haken aus linkem Randbereich draußen
        if self.process_step == "move_until_hook_disappears":
            """
            Weiterfahren, bis der linke Hand im Bild verschwindet (wird für das Handling der letzten 2 Haken benötigt, da Überprüfung auf rechten Bildrand hier nicht mehr funktioniert)
            """
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.transform_velocity_to_world(vel = vel_work, from_frame='work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)
            
            ##### Nächster Prozessschritt
            if lside_rising_edge:
                self.previous_edge_lside = None
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)

                # Filter NN Output einschalten
                filter_enabled = Bool()
                filter_enabled.data = True
                self.nn_output_filter_publisher.publish(filter_enabled)

                self.get_logger().info("Done! -> next process step <Extract Hook 2 as Horizontal Point>")
                self.upcoming_process_step = "extract_hook_3_as_horizontal_point"
                self.start_timer_for_step(2.0)    # Timer starten
                self.process_step = "waiting_for_timer"


        ##### Speichern des Global Dict als CSV, wenn Scanvorgang fertig
        if self.process_step == "save_global_dict_as_csv":
            """
            Abspeichern des fertigen Dict mit allen Haken
            """
            save_dict_to_csv(node = self, data = self.global_hooks_dict, filename = 'src/robot_control/robot_control/data/global_scan_dicts/global_hook_dict_horizontal.csv')
            
            ##### Nächster Prozessschritt
            self.get_logger().info("Done! -> next process step <Finish>")
            self.process_step = "move_back_to_init"


        ##### Zurückfahren auf Startposition
        if self.process_step == "move_back_to_init":
            """
            Zurückfahren auf die ursprüngliche Startposition
            """
            self.startpoint_movement_done = self.move_linear_client.call_move_linear_service(
                pos = self.init_position_tfc_in_worldframe,
                rot = self.init_rotation_tfc_in_worldframe,
                ref = 0,
                ttype = 0,
                tvalue = 100.0,
                bpoint = 0,
                btype = 0,
                bvalue = 100.0,
                sync = 0.0,
                chaining = 0)
            
            ##### Nächster Prozessschritt
            if self.startpoint_movement_done and not self.baseline_error:
                self.get_logger().info("Done! -> next process step <Finish>")
                self.process_step = "finish"
            else:
                self.node_shutdown_flag = True


        ##### Endzustand
        if self.process_step == "finish":
            """
            Endzustand -> Finish
            """
            self.get_logger().info("Scan finished!")
            self.node_shutdown_flag = True
            self.scan_process_end_time = time.perf_counter()
            self.get_logger().warn(f"Time token for full scan process: {((self.scan_process_end_time - self.scan_process_start_time) / 60):.2f}min")





    def start_timer_for_step(self, delay_sec):
        """
        Starte einen Timer, der nach einer bestimmten Zeit den nächsten Schritt ausführt
        """
        next_step = self.upcoming_process_step
        self.get_logger().info(f"Starting timer for {next_step} with {delay_sec} seconds delay")
        self.wait_timer = self.create_timer(delay_sec, self.timer_callback)


    def timer_callback(self):
        """
        Callback, der nach Ablauf des Timers ausgeführt wird
        """
        next_step = self.upcoming_process_step
        self.get_logger().info(f"Timer expired, switching to {next_step}")
        self.process_step = next_step
        self.wait_timer.cancel()
        self.wait_timer = None

    
    def save_vibration_data_to_csv(self):
        """
        Speichert die Schwingungsdaten in einer CSV-Datei.
        """
        if self.measure_hook_2:
            filename = '/home/mo/Thesis/src/robot_control/robot_control/vibration_measurement/vibration_measurement_2.csv'
        else:
            filename = '/home/mo/Thesis/src/robot_control/robot_control/vibration_measurement/vibration_measurement_3.csv'

        # Öffnen der Datei im Schreibmodus
        with open(filename, mode='w', newline='') as file:
            writer = csv.writer(file)

            # Schreibe die Kopfzeile
            writer.writerow(['Time (s)', 'UV Hook', 'UV Tip', 'UV Lowpoint'])

            # Schreibe die gesammelten Schwingungsdaten
            for i in range(len(self.vibration_data['time'])):
                writer.writerow([self.vibration_data['time'][i],
                                 self.vibration_data['uv_hook'][i],
                                 self.vibration_data['uv_tip'][i],
                                 self.vibration_data['uv_lowpoint'][i]])
        self.get_logger().info(f"Vibration data saved as CSV.")
    

    def publish_linear_velocity(self, vel_in_worldframe):
        """
        Funktion für Publish der Twist-Msg
        """
        jog_msg = JogLinear()
        jog_msg.vel = vel_in_worldframe
        jog_msg.rot = [0.0, 0.0, 0.0]
        self.vel_lin_publisher.publish(jog_msg)



    def load_work_frame(self):
        """
        Funktion für das Laden einer Transformation zwischen zwei Frames aus FrameHandler
        """
        csv_name = 'WORK_frame_in_world.csv'
        transformation_matrix = self.frame_handler.load_transformation_matrix_from_csv(frame_name = csv_name)

        if transformation_matrix is not None:
            self.get_logger().info(f"Loaded matrix for frame '{csv_name}' successfully!")
            return transformation_matrix
        else:
            self.get_logger().error(f"Error while loading matrix for frame '{csv_name}'!")
            return None


    def hooks_dict_callback(self, msg):
        """
        Callback für das Ankommen neuer Nachrichten aus NN Output
        """
        self.yolo_hooks_dict = self.hooks_dict_processor.process_hooks_dict(msg)


    def check_for_new_hook_instance(self):
        """
        überprüft kontinuierlich den Netzoutput, ob im rechten Randbereich des Bildausschnitts eine neue Hakeninstanz auftaucht
        falls ja, setzt diese Funktion die Variable self.new_hook_in_picture auf True
        """
        if self.yolo_hooks_dict is not {} and "hook_1" in self.yolo_hooks_dict:
            ### Prüfen auf rechten Randbereich -> Detektion, ob neuer Haken
            if 'hook_2' in self.yolo_hooks_dict:
                if self.yolo_hooks_dict['hook_1']['uv_hook'][0] > self.yolo_hooks_dict['hook_2']['uv_hook'][0]:
                    self.new_hook_in_picture = True
                if self.yolo_hooks_dict['hook_1']['uv_hook'][0] < (self.img_width * 0.8):
                    self.new_hook_in_picture = False
            else:
                if self.yolo_hooks_dict['hook_1']['uv_hook'][0] > (self.img_width * 0.9):
                    self.new_hook_in_picture = True
                if self.yolo_hooks_dict['hook_1']['uv_hook'][0] < (self.img_width * 0.9):
                    self.new_hook_in_picture = False
            
            ### Prüfen auf linken Randbereich -> Detektion, ob alter Haken weg
            if self.handling_last_two_hooks:
                # x_left_hook = self.yolo_hooks_dict['hook_3']['uv_hook'][0]
                x_left_hook = self.yolo_hooks_dict[(list(self.yolo_hooks_dict.keys())[-3])]['uv_hook'][0]
            elif self.handling_last_hook:
                # x_left_hook = self.yolo_hooks_dict['hook_2']['uv_hook'][0]
                x_left_hook = self.yolo_hooks_dict[(list(self.yolo_hooks_dict.keys())[-2])]['uv_hook'][0]
            else:
                x_left_hook = self.yolo_hooks_dict[(list(self.yolo_hooks_dict.keys())[0])]['uv_hook'][0]
            
            if x_left_hook < (self.img_width * 0.1) and x_left_hook != 0:
                self.hook_in_left_area = True
            if x_left_hook > (self.img_width * 0.1) and x_left_hook != 0:
                self.hook_in_left_area = False

            
    
        
    def shutdown_node(self):
        """
        Funktion für Node-Shutdown
        """
        self.doc_visualizer.save_plot_as_png()
        save_dict_to_csv(node = self, data = self.global_hooks_dict, filename = 'src/robot_control/robot_control/data/global_scan_dicts/global_hook_dict_horizontal.csv')

        if self.baseline_error:
            self.get_logger().error("Shutting down... Consider restarting KR1205 Controller")
        else:
            self.get_logger().info("Shutting down...")
        
        # Timer stoppen und Node zerstören
        self.process_timer.cancel()
        self.timer_check_new_instances.cancel()
        self.destroy_node()
        rclpy.shutdown()




def main(args=None):
    rclpy.init(args=args)
    node = ScanBarHorizontalTriangulation()

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.0001)
            if node.node_shutdown_flag:
                node.shutdown_node()
                break
    except KeyboardInterrupt:
        node.shutdown_node()

if __name__ == '__main__':
    main()
