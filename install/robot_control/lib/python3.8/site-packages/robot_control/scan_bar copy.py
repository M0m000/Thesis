import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_dict_receive_processing import DictReceiveProcessor
from FC.FC_call_move_linear_service import call_move_linear_service
from FC.FC_edge_detector import EdgeDetector
from FC.FC_frame_handler import FrameHandler
from FC.FC_stereo_triangulation_processor import StereoTriangulationProcessor
from kr_msgs.msg import JogLinear
import os
import time
import numpy as np


class ScanBar(Node):
    def __init__(self):
        super().__init__('scan_bar')

        # Sub Yolov8 Output
        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}

        # Instanz zum Entacken der Yolo Outputs
        self.hooks_dict_processor = DictReceiveProcessor(self)
        self.yolo_hooks_dict = {}       # Dict für NN Output
        self.global_hooks_dict = {}     # Scan Dict (Ergebnis)

        # Timer für das Prüfen neuer Hakeninstanzen im Bild
        self.edge_detector = EdgeDetector()
        self.new_hook_in_picture = False
        self.img_width = 1280
        self.img_height = 720

        self.hook_ref = {}
        self.hook_horizontal = {}
        self.hook_vertical = {}

        self.robot_position_ref = None
        self.robot_position_horizontal = None
        self.robot_position_vertical = None

        # Instanz für Berechnung der Stereo Triangulation
        self.horizontal_triangulation_processor = HorizontalTriangulationProcessor(extrinsic_data = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
                                                                                   calib_path = '/home/mo/Thesis/calibration_data.npz',
                                                                                   measure_time = True)
        
        # Instanz FrameHandler
        frame_csv_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
        self.frame_handler = FrameHandler(node=self, save_path=frame_csv_path)
        self.world_to_work_transform = self.load_frame(frame='work', ref_frame='world')

        startpoint_trans_in_workframe = [130.0, -420.0, 100.0]
        startpoint_rot_in_workframe = [0.0, 0.0, 0.0]
        startpoint_trans_worldframe, startpoint_rot_worldframe = self.frame_handler.transform_pose_to_world(trans = startpoint_trans_in_workframe,
                                                                                                            rot = startpoint_rot_in_workframe,
                                                                                                            pose_ref_frame = 'work')
        
        # Publisher für Linear Servoing
        self.vel_lin_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

        # Timer für Prozess
        self.speed_in_mm_per_s = 10.0
        self.process_step = None
        self.process_timer = self.create_timer(0.001, self.process_main)
        

        ########## Bewege Roboter auf die Startposition ##########
        self.startpoint_movement_done = False
        if startpoint_rot_worldframe is not None and startpoint_trans_worldframe is not None:
            self.startpoint_movement_done = False
            self.startpoint_movement_done = call_move_linear_service(node = self,
                                                                    pos = startpoint_trans_worldframe,
                                                                    rot = startpoint_rot_worldframe,
                                                                    ref = 0,
                                                                    ttype = 0,
                                                                    tvalue = 50.0,
                                                                    bpoint = 0,
                                                                    btype = 0,
                                                                    bvalue = 100.0,
                                                                    sync = 0.0,
                                                                    chaining = 0)
        '''
        while self.startpoint_movement_done is False:
            self.get_logger().warn("Waiting for init movement to complete...")
            print(self.process_step)
        '''
        self.startpoint_movement_done = True

        if self.startpoint_movement_done == True:
            self.get_logger().info("Init movement done successfully!")
            self.process_step = "move_until_2_hooks_visible"
        else:
            self.get_logger().error("Init movement failed!")
        ###########################################################
        





    def process_main(self):
        '''
        Prozessablauf mit Schrittkette - wird zyklisch alle 1ms aufgerufen
        '''
        # Fahre von Init Position solange, nach rechts, bis 2 Haken zu sehen sind
        if self.process_step == "move_until_2_hooks_visible":
            if len(self.yolo_hooks_dict) < 2:
                vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
                vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame='work')
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
            else:
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                time.sleep(3)
                self.get_logger().info("Done! -> next process step <Extract Hook 2>")
                self.process_step = "extract_hook_2"
        
        # Extrahiere Pixelkoordinaten von Haken 2
        if self.process_step == "extract_hook_2":
            self.hook_ref['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
            self.hook_ref['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
            self.hook_ref['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']
            self.robot_position_ref = self.frame_handler.query_and_load_frame('tcp_world.csv')
            self.get_logger().info("Done! -> next process step <Move Vertical>")
            self.process_step = "move_vertical"

        # Fahre vertikal nach oben mit fester Baseline
        if self.process_step == "move_vertical":
            if self.yolo_hooks_dict['hook_2']['uv_lowpoint'][1] < (self.img_height * 0.9):
                vel_work = [0.0, -self.speed_in_mm_per_s, 0.0]
                vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame='work')
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
            else:
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                time.sleep(3)
                self.get_logger().info("Done! -> next process step <Extract Vertical Hook 2")
                self.process_step = "extract_vertical_hook"

        # Extrahiere Haken mit vertikaler Baseline
        if self.process_step == "extract_vertical_hook":
            self.hook_vertical['uv_hook'] = self.yolo_hooks_dict['hook_2']['uv_hook']
            self.hook_vertical['uv_tip'] = self.yolo_hooks_dict['hook_2']['uv_tip']
            self.hook_vertical['uv_lowpoint'] = self.yolo_hooks_dict['hook_2']['uv_lowpoint']
            self.robot_position_vertical = self.frame_handler.query_and_load_frame('tcp_world.csv')
            self.get_logger().info("Done! -> next process step <Move Vertical>")
            self.process_step = "move_back_to_ref_hook"

        # Fahre zurück zur REF Position
        if self.process_step == "move_back_to_ref_hook":
            pass
            
        # Fahre weiter, bis 3 Haken zu sehen sind
        if self.process_step == "move_until_3_hooks_visible":
            if len(self.yolo_hooks_dict) < 3:
                vel_work = [self.speed_in_mm_per_s, 0.0, 0.0]
                vel_world = self.frame_handler.tansform_velocity_to_world(vel = vel_work, from_frame='work')
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
            else:
                vel_world = [0.0, 0.0, 0.0]
                self.publish_linear_velocity(vel_in_worldframe = vel_world)
                self.get_logger().info("Done! -> next process step <Extract Hook 3>")
                time.sleep(3)
                self.process_step = "extract_hook_3"

        # Extrahiere Pixelkoordinaten von Haken 3 (war vorher Haken 2)
        if self.process_step == "extract_hook_3":
            self.hook_horizontal['uv_hook'] = self.yolo_hooks_dict['hook_3']['uv_hook']
            self.hook_horizontal['uv_tip'] = self.yolo_hooks_dict['hook_3']['uv_tip']
            self.hook_horizontal['uv_lowpoint'] = self.yolo_hooks_dict['hook_3']['uv_lowpoint']
            self.robot_position_horizontal = self.frame_handler.query_and_load_frame('tcp_world.csv')
            
            self.get_logger().info("Done! -> next process step <Horizontal Triangulation>")
            self.process_step = "horizontal_triangulation"

        # Horizontale Triangulation
        if self.process_step == "horizontal_triangulation":
            self.robot_position_ref = self.frame_handler.transform_worldpoint_in_frame(self.robot_position_ref[:3, 3], 'work')
            self.robot_position_horizontal = self.frame_handler.transform_worldpoint_in_frame(self.robot_position_horizontal[:3, 3], 'work')
            self.robot_position_vertical = self.frame_handler.transform_worldpoint_in_frame(self.robot_position_vertical[:3, 3], 'work')

            horizontal_baseline_vector = np.array(self.robot_position_ref) - np.array(self.robot_position_horizontal)
            vertical_baseline_vector = np.array(self.robot_position_ref) - np.array(self.robot_position_vertical)
            
            baseline_along_x = horizontal_baseline_vector[0]
            baseline_along_y = vertical_baseline_vector[1]

            [hook_xyz, tip_xyz, lowpoint_xyz], time_token = self.horizontal_triangulation_processor.triangulate_3_points(point_1_1_uv = self.hook_ref['uv_hook'], point_2_1_uv = self.hook_horizontal['uv_hook'],
                                                            point_1_2_uv = self.hook_ref['uv_tip'], point_2_2_uv = self.hook_horizontal['uv_tip'],
                                                            point_1_3_uv = self.hook_ref['uv_lowpoint'], point_2_3_uv = self.hook_horizontal['uv_lowpoint'],
                                                            baseline = baseline_along_x, baseline_axis = 'x')
            
            print("Hook XYZ: ", hook_xyz)
            print("Tip XYZ: ", tip_xyz)
            print("Lowpoint XYZ: ", lowpoint_xyz)
            print("Time for horizontal triangulation: ", time_token)

            self.get_logger().info("Done! -> next process step <Finish>")
            self.process_step = "finish"






            self.timer_check_new_instances = self.create_timer(0.001, self.check_for_new_hook_instance)     # starte Timer für Abfrage, ob am Bildrand ein neuer Haken erscheint
            rising_edge, falling_edge = self.edge_detector.detect_edge(var=self.new_hook_in_picture)        # prüfe auf Flanken für Haken am Bildrand
            '''
            if rising_edge:
                print("Rising")
            if falling_edge:
                print("Falling")
            '''





    def publish_linear_velocity(self, vel_in_worldframe):
        jog_msg = JogLinear()
        jog_msg.vel = vel_in_worldframe
        jog_msg.rot = [0.0, 0.0, 0.0]
        self.vel_lin_publisher.publish(jog_msg)




    def load_frame(self, frame, ref_frame):
        '''
        Funktion für das Laden einer Transformation zwischen zwei Frames aus FrameHandler
        '''
        csv_name = str(frame) + '_' + str(ref_frame) + '.csv'
        transformation_matrix = self.frame_handler.query_and_load_frame(csv_name)

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
        falls ja, setzt diese Funktion, die Variable self.new_hook_in_picture für 0.5s auf True
        '''
        if self.yolo_hooks_dict is not {} and "hook_1" in self.yolo_hooks_dict:
            if self.yolo_hooks_dict['hook_1']['uv_hook'][0] > (self.img_width * 0.9):
                self.new_hook_in_picture = True
            if self.yolo_hooks_dict['hook_1']['uv_hook'][0] < (self.img_width * 0.9):
                self.new_hook_in_picture = False






def main(args=None):
    rclpy.init(args=args)
    node = ScanBar()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

