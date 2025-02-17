import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_dict_receive_processing import DictReceiveProcessor
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from FC.FC_edge_detector import EdgeDetector
from FC.FC_frame_handler import FrameHandler
from FC.FC_stereo_triangulation_processor import StereoTriangulationProcessor
from FC.FC_save_load_global_hook_dict import save_dict_to_csv, load_csv_to_dict
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.srv import SetSystemFrame
from std_msgs.msg import Int32
import os
import time
import numpy as np
import csv


class ScanBarHorizontalTriangulation(Node):
    def __init__(self):
        super().__init__('scan_bar_horizontal_triangulation')

        self.node_shutdown_flag = False

        self.declare_parameter('num_hooks_existing', 1)
        self.num_hooks_existing = self.get_parameter('num_hooks_existing').get_parameter_value().integer_value
        self.declare_parameter('do_vibration_test', False)
        self.do_vibration_test = self.get_parameter('do_vibration_test').get_parameter_value().bool_value
        self.declare_parameter('speed_in_mm_per_s', 10.0)
        self.speed_in_mm_per_s = self.get_parameter('speed_in_mm_per_s').get_parameter_value().double_value

        # Sub Yolov8 Output
        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}

        # Instanz zum Entacken der Yolo Outputs
        self.hooks_dict_processor = DictReceiveProcessor(self)
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
        self.img_width_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/width', self.received_img_width, 10)
        self.img_width_sub
        self.img_height_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/height', self.received_img_height, 10)
        self.img_height_sub
        self.img_width = 896
        self.img_height = 450

        self.hook_ref = {}
        self.hook_horizontal = {}
        self.act_hook_num = 0

        # Dict für die Aufzeichnung von Schwingungsdaten
        self.vibration_data = {'time': [], 'uv_hook': [], 'uv_tip': [], 'uv_lowpoint': []}  # Schwingungsdaten
        self.first_measurement_iteration = True
        self.measurement_start_time = None
        self.measure_hook_2 = True

        self.robot_position_ref = None
        self.T_robot_position_ref = None
        self.robot_position_horizontal = None

        # Instanz für Berechnung der Stereo Triangulation
        self.triangulation_processor = StereoTriangulationProcessor(extrinsic_data = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
                                                                    calib_path = '/home/mo/Thesis/calibration_data.npz',
                                                                    measure_time = True,
                                                                    img_width = self.img_width,
                                                                    img_height = self.img_height)
        
        # Instanz FrameHandler
        frame_csv_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
        self.frame_handler = FrameHandler(node_name = 'frame_handler_node_for_scan_bar', save_path = frame_csv_path)
        self.cam_to_world_transform = None

        startpoint_trans_in_workframe = [130.0, -430.0, 100.0]
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
        self.set_frame([0.0, 0.0, 0.0], [0.0, 0.0, 0.0], frame="tcp", ref_frame="tfc")

        # Timer für Prozess
        self.process_step = None
        self.process_timer = self.create_timer(0.001, self.process_main)
        self._help_movement_done = False
        self._help_movement_service_called = False
        self.move_linear_client = MoveLinearServiceClient()
        

        ########## Bewege Roboter auf die Startposition ##########
        self.startpoint_movement_done = False
        print(self.startpoint_rot_worldframe)
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
        time.sleep(3)
        ###########################################################
    


    def set_frame(self, R, T, frame="tcp", ref_frame="tfc"):
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
        rside_rising_edge, rside_falling_edge = self.edge_detector_rside.detect_edge(var=self.new_hook_in_picture)        # prüfe auf Flanken für Haken am Bildrand
        lside_rising_edge, lside_falling_edge = self.edge_detector_lside.detect_edge(var=self.hook_in_left_area)
        # Fahre von Init Position solange nach rechts, bis 2 Haken zu sehen sind
        if self.process_step == "move_until_2_hooks_visible":
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame='work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)

            if rside_falling_edge:
                self.previous_edge_rside = "falling"
            
            if rside_rising_edge and self.previous_edge_rside == "falling":
                self.previous_edge_rside = None
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                self.get_logger().info("Done! -> next process step <Extract Hook 2 als initial Reference Point>")
                time.sleep(3)
                self.process_step = "extract_hook_2_as_init_ref"

        # Doku - Messung der Schwingung nach Stillstand
        if self.process_step == "measure_vibration":
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
                self.get_logger().info("Done! -> next process step <Extract Hook 2 als initial Reference Point>")
                self.process_step = "extract_hook_2_as_init_ref"
        
        # Extrahiere Pixelkoordinaten von Haken 2 nach Beginn des Scans
        if self.process_step == "extract_hook_2_as_init_ref":
            self.hook_ref['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
            self.hook_ref['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
            self.hook_ref['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']

            _, _, self.T_robot_position_ref = self.frame_handler.get_system_frame(name = 'tfc', ref = 'world')
            self.robot_position_ref = self.frame_handler.transform_worldpoint_in_frame(self.T_robot_position_ref[:3, 3], 'work')
            self.get_logger().info("Done! -> next process step <Move Until New Hook>")
            self.process_step = "move_until_new_hook"

        # Fahre, bis neuer Haken erscheint
        if self.process_step == "move_until_new_hook":
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
                    time.sleep(3)
                    self.process_step = "extract_hook_3_as_horizontal_point"
        
        # Extrahiere Pixelkoordinaten von Haken 3 (war vorher Haken 2)
        if self.process_step == "extract_hook_3_as_horizontal_point":
            if self.handling_last_two_hooks:
                self.hook_horizontal['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
                self.hook_horizontal['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
                self.hook_horizontal['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']
            elif self.handling_last_hook:
                self.hook_horizontal['uv_hook'] = self.yolo_hooks_dict['hook_1']['uv_hook']
                self.hook_horizontal['uv_tip'] = self.yolo_hooks_dict['hook_1']['uv_tip']
                self.hook_horizontal['uv_lowpoint'] = self.yolo_hooks_dict['hook_1']['uv_lowpoint']
            else:
                self.hook_horizontal['uv_hook'] = self.yolo_hooks_dict['hook_3']['uv_hook']
                self.hook_horizontal['uv_tip'] = self.yolo_hooks_dict['hook_3']['uv_tip']
                self.hook_horizontal['uv_lowpoint'] = self.yolo_hooks_dict['hook_3']['uv_lowpoint']

            _, _, self.robot_position_horizontal = self.frame_handler.get_system_frame(name = 'tfc', ref = 'world')
            self.robot_position_horizontal = self.frame_handler.transform_worldpoint_in_frame(self.robot_position_horizontal[:3, 3], 'work')
            self.get_logger().info("Done! -> next process step <Horizontal Triangulation>")
            self.process_step = "horizontal_triangulation"

        # Horizontale Triangulation
        if self.process_step == "horizontal_triangulation":
            horizontal_baseline_vector = np.array(self.robot_position_horizontal) - np.array(self.robot_position_ref)
            baseline_along_x = horizontal_baseline_vector[0]
            self.get_logger().info(f"Baseline X-Distanz: {baseline_along_x} mm")

            if baseline_along_x == 0:
                self.get_logger().error("ERROR either in moving robot or in position acquisition -> consider restarting KR810...")

            [hook_xyz, tip_xyz, lowpoint_xyz], time_token = self.triangulation_processor.triangulate_3_points(point_1_1_uv = self.hook_horizontal['uv_hook'], point_2_1_uv = self.hook_ref['uv_hook'],
                                                                                                                    point_1_2_uv = self.hook_horizontal['uv_tip'], point_2_2_uv = self.hook_ref['uv_tip'],
                                                                                                                    point_1_3_uv = self.hook_horizontal['uv_lowpoint'], point_2_3_uv = self.hook_ref['uv_lowpoint'],
                                                                                                                    baseline_vector = horizontal_baseline_vector,
                                                                                                                    baseline = baseline_along_x, baseline_axis = 'x')
            # hook_xyz[1] = -hook_xyz[1]
            # tip_xyz[1] = -tip_xyz[1]
            # lowpoint_xyz[1] = -lowpoint_xyz[1]

            self.get_logger().warn(f"Hook XYZ [horizontal]: {hook_xyz}")
            self.get_logger().warn(f"Tip XYZ [horizontal]: {tip_xyz}")
            self.get_logger().warn(f"Lowpoint XYZ [horizontal]: {lowpoint_xyz}")
            self.get_logger().warn(f"Time token for triangulation [horizontal]: {time_token}sec")
            
            self.get_logger().info("Done! -> next process step <Save Hook>")
            self.process_step = "save_hook"

        # Speicher die Daten des aktuellen Hakens
        if self.process_step == "save_hook":
            self.act_hook_num += 1
            self.global_hooks_dict[str(self.act_hook_num)] = {}
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook'] = hook_xyz
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip'] = tip_xyz
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint'] = lowpoint_xyz
            
            robot_position_in_tfcframe = self.T_robot_position_ref
            transform_cam_in_tfcframe = self.frame_handler.load_transformation_matrix_from_csv(frame_name = 'CAM_frame_in_tfc.csv')
            # self.cam_to_world_transform = self.frame_handler.get_cam_transform_in_world()
            self.cam_to_world_transform = robot_position_in_tfcframe @ transform_cam_in_tfcframe

            hook_xyz_hom = np.append(hook_xyz, 1)
            point = self.cam_to_world_transform @ hook_xyz_hom
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_hook_workframe'] = self.frame_handler.transform_worldpoint_in_frame(point = point, frame_desired = 'work')
            
            tip_xyz_hom = np.append(tip_xyz, 1)
            point = self.cam_to_world_transform @ tip_xyz_hom
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_tip_workframe'] = self.frame_handler.transform_worldpoint_in_frame(point = point, frame_desired = 'work')
            
            lowpoint_xyz_hom = np.append(lowpoint_xyz, 1)
            point = self.cam_to_world_transform @ lowpoint_xyz_hom
            self.global_hooks_dict[str(self.act_hook_num)]['xyz_lowpoint_workframe'] = self.frame_handler.transform_worldpoint_in_frame(point = point, frame_desired = 'work')
            
            self.global_hooks_dict[str(self.act_hook_num)]['tfc_workframe'] = self.robot_position_horizontal
            self.global_hooks_dict[str(self.act_hook_num)]['tfc_worldframe'], _, _ = self.frame_handler.get_system_frame(name = 'tfc', ref = 'world')

            self.get_logger().warn(f"Hook XYZ [horizontal]: {hook_xyz_hom}")
            self.get_logger().warn(f"Tip XYZ [horizontal]: {tip_xyz_hom}")
            self.get_logger().warn(f"Lowpoint XYZ [horizontal]: {lowpoint_xyz_hom}")
            self.get_logger().warn(f"Time token for triangulation [horizontal]: {time_token}sec")

            self.get_logger().info(f"already scanned: {len(self.global_hooks_dict)} Hooks")

            if len(self.global_hooks_dict) == self.num_hooks_existing:
                self.get_logger().info("Done! -> next process step <Save Global Dict as CSV>")
                self.process_step = "save_global_dict_as_csv"
            else:
                self.get_logger().info("Done! -> next process step <Extract Hook 2 as Reference>")
                self.process_step = "extract_hook_2_as_ref"

        # Extrahiere Pixelkoordinaten von Haken 2 während Prozess
        if self.process_step == "extract_hook_2_as_ref":
            if self.handling_last_two_hooks:
                self.hook_ref['uv_hook'] = self.yolo_hooks_dict['hook_1']['uv_hook']
                self.hook_ref['uv_tip'] = self.yolo_hooks_dict['hook_1']['uv_tip']
                self.hook_ref['uv_lowpoint'] = self.yolo_hooks_dict['hook_1']['uv_lowpoint']
            else:
                self.hook_ref['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
                self.hook_ref['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
                self.hook_ref['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']

            _, _, self.T_robot_position_ref = self.frame_handler.get_system_frame(name = 'tcp', ref = 'world')
            self.robot_position_ref = self.frame_handler.transform_worldpoint_in_frame(self.T_robot_position_ref[:3, 3], 'work')
            
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

        # Fahre, bis Haken aus linkem Randbereich draußen
        if self.process_step == "move_until_hook_disappears":
            vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
            vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame='work')
            self.publish_linear_velocity(vel_in_worldframe = vel_world)
            
            if lside_rising_edge:
                self.previous_edge_lside = None
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                self.get_logger().info("Done! -> next process step <Extract Hook 2 as Horizontal Point>")
                time.sleep(3)
                self.process_step = "extract_hook_3_as_horizontal_point"

        # Speichern des Global Dict als CSV, wenn Scanvorgang fertig
        if self.process_step == "save_global_dict_as_csv":
            save_dict_to_csv(node = self, data = self.global_hooks_dict, filename = 'src/robot_control/robot_control/data/global_scan_dicts/global_hook_dict_horizontal.csv')
            self.get_logger().info("Done! -> next process step <Finish>")
            self.process_step = "move_back_to_init"

        # Endzustand
        if self.process_step == "move_back_to_init":
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
            self.get_logger().info("Scan finished!")
            self.node_shutdown_flag = True

    

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


    
    def check_for_new_hook_instance(self):
        '''
        überprüft kontinuierlich den Netzoutput, ob im rechten Randbereich des Bildausschnitts eine neue Hakeninstanz auftaucht
        falls ja, setzt diese Funktion die Variable self.new_hook_in_picture auf True
        '''
        if self.yolo_hooks_dict is not {} and "hook_1" in self.yolo_hooks_dict:
            if self.yolo_hooks_dict['hook_1']['hook_box'][0] > (self.img_width * 0.8):
                self.new_hook_in_picture = True
            if self.yolo_hooks_dict['hook_1']['uv_hook'][0] < (self.img_width * 0.9):
                self.new_hook_in_picture = False
            
            x_left_hook = self.yolo_hooks_dict[(list(self.yolo_hooks_dict.keys())[0])]['uv_tip'][0]
            if x_left_hook < (self.img_width * 0.1) and x_left_hook != 0:
                self.hook_in_left_area = True
            if x_left_hook > (self.img_width * 0.1) and x_left_hook != 0:
                self.hook_in_left_area = False
            

        
    def shutdown_node(self):
        # Timer stoppen und Node zerstören
        self.process_timer.cancel()
        self.timer_check_new_instances.cancel()
        self.get_logger().info("Shutting down node...")
        self.destroy_node()
        rclpy.shutdown()



def main(args=None):
    rclpy.init(args=args)
    node = ScanBarHorizontalTriangulation()

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

