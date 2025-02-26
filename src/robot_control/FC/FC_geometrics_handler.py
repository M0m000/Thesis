import rclpy
from rclpy.node import Node
from FC.FC_save_load_global_hook_dict import load_csv_to_dict
from FC.FC_frame_handler import FrameHandler
import numpy as np
from scipy.spatial.transform import Rotation as R


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
        self.get_logger().info("Frame Handler for Geometrics Handler instantiated successfully!")


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

        self.path_points = None

        self.hook_line = {}
        self.plane = None
        self.plane_midpoint = None
        self.delta_angles = None




    def get_hook_of_global_scan_dict(self, hook_num):
        if hook_num != 0 and hook_num <= len(self.global_scan_dict) and self.global_scan_dict is not None:
            self.hook_tfc_pos_in_workframe = self.global_scan_dict[str(hook_num)]['tfc_in_workframe']
            self.hook_tfc_pos_in_worldframe = self.global_scan_dict[str(hook_num)]['tfc_in_worldframe']

            self.hook_entry = self.global_scan_dict[str(hook_num)]
            self.hook_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_hook_in_camframe']
            self.hook_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_hook_in_workframe']
            
            self.tip_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_tip_in_camframe']
            self.tip_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_tip_in_workframe']

            self.lowpoint_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_lowpoint_in_camframe']
            self.lowpoint_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_lowpoint_in_workframe']

            self.path_points_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_path_points_in_workframe']
            return self.hook_entry
        
        


    def update_hook_data(self, hook_num):
        if self.global_scan_dict is not None:
            # hole die aktuelle TFC Position im WORLD-Frame und rechne sie ins WORK-Frame um
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
            
            # rechne die Hakenkoordinaten vom WORK-Frame ins TFC-Frame um
            self.hook_pos_in_tfcframe = T_work_in_tfcframe @ hook_point_in_workframe_hom
            self.hook_pos_in_tfcframe = self.hook_pos_in_tfcframe[:3]

            self.tip_pos_in_tfcframe = T_work_in_tfcframe @ tip_point_in_workframe_hom
            self.tip_pos_in_tfcframe = self.tip_pos_in_tfcframe[:3]

            self.lowpoint_pos_in_tfcframe = T_work_in_tfcframe @ lowpoint_point_in_workframe_hom
            self.lowpoint_pos_in_tfcframe = self.lowpoint_pos_in_tfcframe[:3]


    
    
    def calculate_hook_line(self):
        """
        Berechnet eine Gerade entlang des Haken von p_0 (Senke) nach p_1 (Spitze)"""
        if self.hook_pos_in_tfcframe is not None and self.tip_pos_in_tfcframe is not None and self.lowpoint_pos_in_tfcframe is not None:
            p_0 = self.lowpoint_pos_in_tfcframe     # p_0 ist Lowpoint
            p_1 = self.tip_pos_in_tfcframe          # p_1 ist Spitze
            p_dir = p_1 - p_0

            abs_p_dir = np.linalg.norm(p_dir)
            if abs_p_dir != 0:
                p_dir /= abs_p_dir

            # wird gespeichert in TFC-Frame
            self.hook_line['p_0'] = p_0
            self.hook_line['p_1'] = p_1
            self.hook_line['p_dir'] = p_dir
            return self.hook_line
        



    def calculate_plane(self, trans_in_tfcframe, rot_in_tfcframe):
        """
        Berechnet die Ebene des Aufhängelochs basierend auf festen translatorischen und rotatorischen Werten in Bezug auf TFC
        """
        x, y, z = trans_in_tfcframe
        
        # Berechne Rotationsmatrix
        R = self.frame_handler.calculate_rot_matrix(rot = rot_in_tfcframe)

        # Berechne Normalenvektor in Pinhole-Frame und in TCP-Frame
        normal_in_pinhole_frame = np.array([1.0, 0.0, 0.0])     # Normalenvektor im Pinhole ist die x-Achse
        normal_in_tcp_frame = R @ normal_in_pinhole_frame
        abs_normal_in_tcp_frame = np.linalg.norm(normal_in_tcp_frame)
        if abs_normal_in_tcp_frame != 0.0:
            normal_in_tcp_frame /= abs_normal_in_tcp_frame

        # Berechne Ebenengleichung des Pinhole in TCP-Frame
        n_x, n_y, n_z = normal_in_tcp_frame
        d = -(n_x * x + n_y * y + n_z * z)
        self.plane = (n_x, n_y, n_z, d)
        self.plane_midpoint = np.array(trans_in_tfcframe)
        return n_x, n_y, n_z, d
    



    def calculate_adjustment_angles(self, plane = None, line_dir = None):
        """
        Berechnet die notwendigen Roll-Pitch-Yaw-Winkel, um die Ebene so zu drehen,
        dass ihr Normalenvektor mit dem Richtungsvektor der Geraden übereinstimmt.

        plane: Tuple (n_x, n_y, n_z, d) - Normalenvektor der Ebene
        line_dir: Liste [d_x, d_y, d_z] - Richtungsvektor der Geraden
        return: Liste [delta_roll, delta_pitch, delta_yaw] in Radiant
        """
        if plane is None:
            plane = self.plane

        if line_dir is None:
            line_dir = self.hook_line['p_dir']      # in TFC-Frame

        n = np.array(plane[:3])  # Normalenvektor der Ebene
        d = np.array(line_dir)   # Richtungsvektor der Geraden

        # Berechnung der Rotationsachse
        rot_axis = np.cross(n, d)
        if np.linalg.norm(rot_axis) < 1e-6:
            return [0.0, 0.0, 0.0]  # Bereits korrekt ausgerichtet -> Kreuzprodukt ist Null -> Vektoren parallel
        else:
            rot_axis /= np.linalg.norm(rot_axis)  # Normieren der Rotationsachse

        # Berechnung des Winkels
        angle = np.arccos(np.clip(np.dot(n, d) / (np.linalg.norm(n) * np.linalg.norm(d)), -1.0, 1.0))

        # Rotationsmatrix um die Achse erstellen
        rotation_matrix = R.from_rotvec(angle * rot_axis).as_matrix()

        # Euler-Winkel aus der Rotationsmatrix extrahieren
        self.delta_angles = R.from_matrix(rotation_matrix).as_euler('xyz')
        # self.delta_angles = self.delta_angles.tolist()
        self.delta_angles = np.array(self.delta_angles) * (180 / np.pi)  # Umrechnung in Grad
        return self.delta_angles
    



    def calculate_translation_difference(self, target_position = None, plane = None, plane_midpoint = None):
        """
        Berechnet die Reglerdifferenz für die translatorische Verschiebung
        zwischen dem Mittelpunkt der Ebene und einem Zielpunkt.

        plane: Tuple (n_x, n_y, n_z, d) - Normalenvektor der Ebene und der Abstand d
        target_position: Liste [x_t, y_t, z_t] - Zielposition, an die der Mittelpunkt verschoben werden soll

        return: Liste [delta_x, delta_y, delta_z] - Differenz in den drei Richtungen
        """
        if plane is None:
            plane = self.plane
            plane_midpoint = self.plane_midpoint
        
        if target_position is None:
            target_position = self.hook_line['p_1']

        # Der Mittelpunkt der Ebene
        P_center = plane_midpoint
        P_target = np.array(target_position)

        # Berechne die Differenz (Verschiebung)
        translation_diff = P_target - P_center
        return translation_diff
    



    def calculate_targetpose_in_worldframe(self, target_position = None, line_dir = None, plane = None, plane_midpoint = None):
        """
        Berechnet die Endpose des TFC im WORLD-Frame -> kann dann direkt für MoveLinear servcie call genutzt werden...
        """
        trans_diff_in_tfcframe = self.calculate_translation_difference(target_position = target_position, 
                                                                        plane = plane, 
                                                                        plane_midpoint = plane_midpoint)
        rot_diff_in_tfcframe = self.calculate_adjustment_angles(plane = plane, line_dir = line_dir)

        trans_diff_in_worldframe, rot_diff_in_worldframe = self.frame_handler.transform_pose_to_world(trans = trans_diff_in_tfcframe, 
                                                                                                      rot = rot_diff_in_tfcframe,
                                                                                                      pose_ref_frame = 'tfc')
        return trans_diff_in_worldframe, rot_diff_in_worldframe


        

def main(args=None):
    rclpy.init(args=args)
    node = GeometricsHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
