import rclpy
from rclpy.node import Node
from FC.FC_save_load_global_hook_dict import load_csv_to_dict
from FC.FC_frame_handler import FrameHandler
import numpy as np


class GeometricsHandler(Node):
    def __init__(self):
        super().__init__("geometrics_handler")

        # Laden des Global Scan Dict
        self.global_scan_dict = None
        self.global_scan_dict = load_csv_to_dict(node = self, filename = '/home/mo/Thesis/src/robot_control/robot_control/data/global_scan_dicts/global_hook_dict_horizontal.csv')
        if self.global_scan_dict is not None:
            self.get_logger().info("Global Scan Dict loaded successfully from CSV for Geometrics Handler!")
        else:
            self.get_logger().error("Error at loading Global Scan Dict from CSV!")


        # Instanziieren eines Frame Handlers
        self.frame_handler = FrameHandler(node_name = "frame_handler_for_geometrics_handler")
        self.get_logger().info("Frame Handler for Geomtrics Handler instantiated successfully!")


        # speichern der aktuellen Hakeninstanz
        self.hook_entry = None
        self.hook_pos_in_camframe = None
        self.hook_pos_in_workframe = None

        self.hook_pos_in_tfcframe = None
        self.tip_pos_in_camframe = None
        self.tip_pos_in_workframe = None
        
        self.tip_pos_in_tfcframe = None
        self.lowpoint_pos_in_camframe = None
        self.lowpoint_pos_in_workframe = None
        self.lowpoint_pos_in_tfcframe = None
        
        self.hook_tfc_pos_in_workframe = None
        self.hook_tfc_pos_in_worldframe = None


        # Dict für die Gerade (Stützpunkt und Richtungsvektor)
        self.hook_line = {}





    def get_hook_of_global_scan_dict(self, hook_num):
        if hook_num != 0 and hook_num <= len(self.global_scan_dict) and self.global_scan_dict is not None:
            self.hook_tfc_pos_in_workframe = self.global_scan_dict[str(hook_num)]['tfc_workframe']
            self.hook_tfc_pos_in_worldframe = self.global_scan_dict[str(hook_num)]['tfc_worldframe']

            self.hook_entry = self.global_scan_dict[str(hook_num)]
            self.hook_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_hook']
            self.hook_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_hook_workframe']
            
            self.tip_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_tip']
            self.tip_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_tip_workframe']

            self.lowpoint_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_lowpoint']
            self.lowpoint_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_lowpoint_workframe']
            return self.hook_entry
        


    def update_hook_data(self, hook_num):
        if self.global_scan_dict is not None:
            # hole die aktuelle TFC Position und rechne sie ins WORK-Frame um
            _, _, T_tfc_in_worldframe = self.frame_handler.get_system_frame(name = 'tfc', ref = 'world')
            T_tfc_in_workframe = self.frame_handler.transform_worldpose_to_desired_frame(T_in_worldframe = T_tfc_in_worldframe,
                                                                                         frame_desired = "work")
            
            # hole die Haken Koordinaten im WORK Frame aus Global Scan Dict
            _ = self.get_hook_of_global_scan_dict(hook_num)
            T_work_in_tfcframe = np.linalg.inv(T_tfc_in_workframe)

            hook_point_in_workframe_hom = np.array([self.hook_pos_in_workframe[0], 
                                                    self.hook_pos_in_workframe[1], 
                                                    self.hook_pos_in_workframe[2], 
                                                    1.0])
            tip_point_in_workframe_hom = np.array([self.tip_pos_in_workframe[0], 
                                                   self.tip_pos_in_workframe[1], 
                                                   self.tip_pos_in_workframe[2], 
                                                   1.0])
            lowpoint_point_in_workframe_hom = np.array([self.lowpoint_pos_in_workframe[0], 
                                                        self.lowpoint_pos_in_workframe[1], 
                                                        self.lowpoint_pos_in_workframe[2], 
                                                        1.0])
            
            self.hook_pos_in_tfcframe = T_work_in_tfcframe @ hook_point_in_workframe_hom
            self.hook_pos_in_tfcframe = self.hook_pos_in_tfcframe[:3]

            self.tip_pos_in_tfcframe = T_work_in_tfcframe @ tip_point_in_workframe_hom
            self.tip_pos_in_tfcframe = self.tip_pos_in_tfcframe[:3]

            self.lowpoint_pos_in_tfcframe = T_work_in_tfcframe @ lowpoint_point_in_workframe_hom
            self.lowpoint_pos_in_tfcframe = self.lowpoint_pos_in_tfcframe[:3]


    
    def calculate_hook_line(self):
        if self.hook_pos_in_tfcframe is not None and self.tip_pos_in_tfcframe is not None and self.lowpoint_pos_in_tfcframe is not None:
            p_0 = self.lowpoint_pos_in_tfcframe
            p_dir = self.tip_pos_in_tfcframe - p_0
            p_dir /= np.linalg.norm(p_dir)

            self.hook_line['p_0'] = p_0
            self.hook_line['p_dir'] = p_dir
            return self.hook_line
        



    def calculate_plane(self):
        pass
        



def main(args=None):
    rclpy.init(args=args)
    node = GeometricsHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
