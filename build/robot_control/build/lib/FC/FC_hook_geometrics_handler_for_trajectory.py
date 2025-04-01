import rclpy
from rclpy.node import Node
from FC.FC_save_load_global_hook_dict import load_csv_to_dict
from FC.FC_frame_handler import FrameHandler
import numpy as np
from scipy.spatial.transform import Rotation as R
import pandas as pd
from scipy import stats
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures



class HookGeometricsHandler(Node):
    def __init__(self, distance_to_tip_in_mm, global_scan_dict_filename = '/home/mo/Thesis/src/robot_control/robot_control/data/global_scan_dicts/global_hook_dict_horizontal_modellA.csv'):
        super().__init__("hook_geometrics_handler")

        # Laden des Global Scan Dict
        self.global_scan_dict = None
        self.global_scan_dict = load_csv_to_dict(filename = global_scan_dict_filename)
        if self.global_scan_dict is not None:
            self.get_logger().info("Global Scan Dict loaded successfully from CSV for Geometrics Handler!")
        else:
            self.get_logger().error("Error at loading Global Scan Dict from CSV!")

        # Instanziieren eines Frame Handlers
        self.frame_handler = FrameHandler(node_name = "frame_handler_for_geometrics_handler")
        self.get_logger().info("Frame Handler for Geometrics Handler instantiated successfully!")

        ########## speichern der aktuellen Hakeninstanz
        self.hook_entry = None

        # Variablen für Hook-Pos in WORK und TFC
        self.hook_pos_in_camframe = None
        self.hook_pos_in_workframe = None
        self.hook_pos_in_tfcframe = None

        # Variablen für Tip-Pos in WORK und TFC
        self.tip_pos_in_camframe = None
        self.tip_pos_in_workframe = None
        self.tip_pos_in_tfcframe = None

        # Variablen für Lowpoints-Pos in WORK und TFC
        self.lowpoint_pos_in_camframe = None
        self.lowpoint_pos_in_workframe = None
        self.lowpoint_pos_in_tfcframe = None

        # Variablen für Path-Points in WORK und TFC
        self.path_points_in_workframe = None
        self.path_points_in_tfcframe = None

        # Variablen für TFC-Pose in WORK und WORLD
        self.hook_tfc_pos_in_workframe = None
        self.hook_tfc_pos_in_worldframe = None

        # Dict für Speicherung der aktuellen Hakengerade
        self.hook_line = {}
        self.handling_last_path_point = False
        self.distance_to_tip_in_mm = distance_to_tip_in_mm
        ##########

        # Variablen für die Regelung
        self.plane = None
        self.plane_midpoint = None
        self.T_plane_in_tfcframe = np.eye(4)
        self.delta_angles = None
        self.control_state = None
        self.trans_diff_in_tfcframe = None
        self.rot_diff_in_tfcframe = None



    def get_hook_of_global_scan_dict(self, hook_num):
        """
        Lädt alle Daten für eine gegebene Hakennummer aus Global Scan Dict
        """
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
        """
        Aktualisiert alle Daten des Hakes (verändert sich in Bezug auf das TFC-Frame permanent während Bewegung)
        """
        if self.global_scan_dict is not None:
            # hole die aktuelle TFC Position im WORLD-Frame und rechne sie ins WORK-Frame um
            _, _, T_tcp_in_worldframe = self.frame_handler.get_system_frame(name = 'tcp', ref = 'world')
            T_tcp_in_workframe = self.frame_handler.transform_worldpose_to_desired_frame(
                T_in_worldframe = T_tcp_in_worldframe,
                frame_desired = "work")
            

            # hole die Haken Koordinaten im WORK Frame aus Global Scan Dict
            _ = self.get_hook_of_global_scan_dict(hook_num)
            T_work_in_tcpframe = np.linalg.inv(T_tcp_in_workframe)

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
            self.hook_pos_in_tcpframe = T_work_in_tcpframe @ hook_point_in_workframe_hom
            self.hook_pos_in_tcpframe = self.hook_pos_in_tcpframe[:3]

            self.tip_pos_in_tcpframe = T_work_in_tcpframe @ tip_point_in_workframe_hom
            self.tip_pos_in_tcpframe = self.tip_pos_in_tcpframe[:3]

            self.lowpoint_pos_in_tcpframe = T_work_in_tcpframe @ lowpoint_point_in_workframe_hom
            self.lowpoint_pos_in_tcpframe = self.lowpoint_pos_in_tcpframe[:3]


            # rechne die Path Points ins TFC Frame um
            self.path_points_in_tcpframe = []       # leeren der bisherigen Liste
            for ppoint in self.path_points_in_workframe:
                x = ppoint[0]
                y = ppoint[1]
                z = ppoint[2]
                ppoint_hom = np.array([x, y, z, 1.0])
                ppoint_in_tcpframe = T_work_in_tcpframe @ ppoint_hom
                ppoint_in_tcpframe = ppoint_in_tcpframe[:3]
                self.path_points_in_tcpframe.append(ppoint_in_tcpframe)         # speichern in Liste



    def calculate_hook_line(self, p_0_in_tcpframe = None, p_1_in_tcpframe = None):
        """
        Berechnet eine Gerade entlang des Haken von p_0 (Senke) nach p_1 (Spitze)
        --> kann auch für stückweise tangentiale Geraden verwendet werden, dann p_0 bzw. p_1 eintragen
        """
        if self.hook_pos_in_tcpframe is not None and self.tip_pos_in_tcpframe is not None and self.lowpoint_pos_in_tcpframe is not None:
            if p_0_in_tcpframe is None:
                p_0 = self.lowpoint_pos_in_tcpframe     # p_0 ist Lowpoint
            else:
                p_0 = p_0_in_tcpframe
            if p_1_in_tcpframe is None:
                p_1 = self.tip_pos_in_tcpframe          # p_1 ist Spitze
            else:
                p_1 = p_1_in_tcpframe
            
            # Richtungsvektor (normiert)
            p_dir = p_1 - p_0
            abs_p_dir = np.linalg.norm(p_dir)
            if abs_p_dir != 0:
                p_dir /= abs_p_dir

            # wird gespeichert in TCP-Frame
            self.hook_line['p_0'] = p_0
            self.hook_line['p_1'] = p_1
            self.hook_line['p_dir'] = p_dir
            return self.hook_line
        


    def calculate_plane(self, trans_in_tcpframe, rot_in_tcpframe):
        """
        Berechnet die Ebene des Aufhängelochs basierend auf festen translatorischen und rotatorischen Werten in Bezug auf TFC
        """
        x, y, z = trans_in_tcpframe
        
        # Berechne Rotationsmatrix
        R = self.frame_handler.calculate_rot_matrix(rot = rot_in_tcpframe)
        self.T_plane_in_tfcframe[:3, :3] = R
        self.T_plane_in_tfcframe[:3, 3] = np.array([x, y, z])

        # Berechne Normalenvektor in Pinhole-Frame (=TCP-Frame)
        normal_in_pinhole_frame = np.array([1.0, 0.0, 0.0])     # Normalenvektor im Pinhole ist die x-Achse
        normal_in_tcp_frame = R @ normal_in_pinhole_frame
        abs_normal_in_tcp_frame = np.linalg.norm(normal_in_tcp_frame)
        if abs_normal_in_tcp_frame != 0.0:
            normal_in_tcp_frame /= abs_normal_in_tcp_frame

        # Berechne Ebenengleichung des Pinhole in TCP-Frame
        n_x, n_y, n_z = normal_in_tcp_frame
        d = -(n_x * x + n_y * y + n_z * z)
        self.plane = (n_x, n_y, n_z, d)
        self.plane_midpoint = np.array(trans_in_tcpframe)
        return n_x, n_y, n_z, d
    


    def _calculate_adjustment_angles(self, plane=None, line_dir=None):
        """
        Berechnet die notwendigen Roll-Pitch-Yaw-Winkel, um die Ebene so zu drehen,
        dass ihr Normalenvektor mit dem Richtungsvektor der Geraden übereinstimmt.

        plane: Tuple (n_x, n_y, n_z, d) - Normalenvektor der Ebene
        line_dir: Liste [d_x, d_y, d_z] - Richtungsvektor der Geraden
        return: Liste [delta_roll, delta_pitch, delta_yaw] (hier in Grad)
        """
        if plane is None:
            plane = self.plane

        if line_dir is None:
            line_dir = self.hook_line['p_dir']  # in TCP-Frame

        n = np.array(plane[:3])     # Normalenvektor der Ebene
        d_vec = np.array(line_dir)  # Richtungsvektor der Geraden

        # Berechnung der Rotationsachse
        rot_axis = np.cross(n, d_vec)
        if np.linalg.norm(rot_axis) < 1e-6:
            return [0.0, 0.0, 0.0]  # Vektoren sind bereits parallel
        else:
            rot_axis /= np.linalg.norm(rot_axis)  # Normieren der Rotationsachse

        # Berechnung des Winkels und der Rotationsmatrix, die diese Drehung beschreibt
        angle = np.arccos(np.clip(np.dot(n, d_vec) / (np.linalg.norm(n) * np.linalg.norm(d_vec)), -1.0, 1.0))
        R_adj = R.from_rotvec(angle * rot_axis).as_matrix()

        # Transformation in den TCP-Frame mit Inversen
        # R_plane = self.T_plane_in_tcpframe[:3, :3]  # Rotationsanteil der Matrix
        R_adjustment_TFC = R_adj    # R_plane @ R_adj @ np.linalg.inv(R_plane)

        # Extrahiere Euler-Winkel (z.B. im 'xyz'-Format) aus der umgerechneten Rotationsmatrix
        delta_angles_TCP = R.from_matrix(R_adjustment_TFC).as_euler('xyz')
        delta_angles_TCP = np.array(delta_angles_TCP) * (180 / np.pi)           # Umrechnung in Grad

        self.delta_angles = delta_angles_TCP
        return self.delta_angles

    

    def _calculate_translation_difference(self, target_position = None, plane = None, plane_midpoint = None):
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
            target_position = self.hook_line['p_1'] if self.handling_last_path_point == False else self.hook_line['p_0']    # in TCP    # umschalten auf p0, wenn letzter Path Point
        
        '''
        # Transformation der Hakenkoordinaten in Spitze
        target_position_hom = np.append(plane_midpoint, 1)
        target_position_in_pinholeframe = self.T_plane_in_tfcframe @ target_position_hom
        target_position_in_pinholeframe = target_position_in_pinholeframe[:3]
        '''

        # Der Mittelpunkt der Ebene
        P_center = plane_midpoint
        P_target = np.array(target_position)    # target_position_in_pinholeframe

        # Berechne die Differenz (Verschiebung)
        translation_diff = P_target # - P_center
        return translation_diff
    


    def _calculate_targetpose_in_worldframe(self, target_position = None, line_dir = None, plane = None, plane_midpoint = None):
        """
        Berechnet die Endpose des TFC im WORLD-Frame -> kann dann direkt für MoveLinear servcie call genutzt werden...
        """
        trans_diff_in_tcpframe = self._calculate_translation_difference(
            target_position = target_position, 
            plane = plane, 
            plane_midpoint = plane_midpoint)
        
        rot_diff_in_tcpframe = self._calculate_adjustment_angles(plane = plane, line_dir = line_dir)

        trans_diff_in_worldframe, rot_diff_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = trans_diff_in_tcpframe, 
            rot = rot_diff_in_tcpframe,
            pose_ref_frame = 'tcp')
        return trans_diff_in_worldframe, rot_diff_in_worldframe
    


    def _calculate_init_trajectory_point(self):
        """
        Berechnet den Init-Punkt für die Trjaketorie mit Abstand distance_to_tip_in_mm in [mm] zur Spitze
        """
        p_tip = self.hook_line['p_1']
        p_dir = self.hook_line['p_dir']
        p_traj_init = p_tip + self.distance_to_tip_in_mm * p_dir
        self.hook_line['p_traj_init'] = p_traj_init



    def plan_path_point_trajectory(self, hook_num=None):
        """
        Berechnet die vollständige Trajektorie für das Einfädeln entlang der Hakenform
        """
        if hook_num is None:
            self.get_logger().error(f"No Hook Num selected!")
            return None
        else:
            trajectory = []
            _ = self.get_hook_of_global_scan_dict(hook_num=hook_num)
            
            # Berechne Init-Punkt (mit Abstand zur Spitze)
            self.get_logger().info("Calculating initial trajectory point...")
            self._calculate_init_trajectory_point()
            p_traj_init = self.hook_line['p_traj_init']
            trajectory.append(self._calculate_targetpose_in_worldframe(target_position = p_traj_init, line_dir = self.hook_line['p_dir']))

            # Berechne alle Trajektorienpunkt von Spitze bis Senke
            for idx in range(len(self.path_points_in_tcpframe)):
                self.get_logger().info(f"Calculation trajectory path point {idx + 1}")
                if idx < (len(self.path_points_in_tcpframe) - 1):
                    ppoint_1 = self.path_points_in_tcpframe[idx]
                    ppoint_0 = self.path_points_in_tcpframe[idx + 1]
                    self.calculate_hook_line(p_0_in_tcpframe = ppoint_0, p_1_in_tcpframe = ppoint_1)

                if idx == (len(self.path_points_in_tcpframe) - 1):
                    self.handling_last_path_point = True    # Flag für letzten path point setzen
                    self.get_logger().info(f"Handling last path point...")
                    self.hook_line['p_1'] = self.path_points_in_tcpframe[idx]
                trajectory.append(self._calculate_targetpose_in_worldframe())
            # trajectory_smoothed = self._smooth_trajectory_rotations(trajectory = trajectory, z_thresh = 2.3)
            # trajectory = self._polynomial_regression_trajectory_positions(trajectory = trajectory_smoothed, degree = 3)
            return trajectory
    


    def _polynomial_regression_trajectory_positions(self, trajectory, degree=2):
        """
        Erstellt eine neue Trajektorie, bei der die Positionen durch eine polynomiale Regression geglättet wurden.
        Rotation bleibt unverändert.
        """
        positions = [pos for pos, _ in trajectory]  # Shape (N, 3)
        rotations = np.array([rot for _, rot in trajectory])
        indices = np.arange(len(rotations)).reshape(-1, 1)

        poly = PolynomialFeatures(degree=degree)
        X_poly = poly.fit_transform(indices)

        smoothed_rotations = []
        for axis in range(3):  # x, y, z
            y = rotations[:, axis]
            model = LinearRegression()
            model.fit(X_poly, y)
            predicted = model.predict(X_poly)
            smoothed_rotations.append(predicted)

        smoothed_rotations = np.stack(smoothed_rotations, axis=1)
        new_trajectory = [(pos, rot) for pos, rot in zip(positions, smoothed_rotations)]
        return new_trajectory
    


    def _interpolate_outlier_vectors_zscore(self, vector, z_thresh=2.0):
        """
        Identifiziert Ausreißer auf Vektorebene (z. B. 3D Rotation) und interpoliert sie.

        Parameter:
            rotations: np.ndarray der Form (N, 3)
            z_thresh: z-Score-Schwelle zur Ausreißererkennung

        Rückgabe:
            Interpolierte Rotationen gleicher Form (N, 3)
        """
        # Z-Score pro Achse berechnen
        z_scores = np.abs(stats.zscore(vector, nan_policy='omit'))

        # Vektoren als Ausreißer markieren, wenn **irgendein** Wert im Vektor über Schwelle liegt
        outlier_mask = np.any(z_scores > z_thresh, axis=1)

        # Daten vorbereiten
        vector_with_nans = vector.copy().astype(float)
        vector_with_nans[outlier_mask] = np.nan

        # Achsenweise Interpolation durchführen
        interpolated = np.empty_like(vector_with_nans)
        for axis in range(3):
            series = pd.Series(vector_with_nans[:, axis])
            interpolated[:, axis] = series.interpolate(method='linear', limit_direction='both').to_numpy()
        return interpolated
    


    def _smooth_trajectory_rotations(self, trajectory, z_thresh=2.0):
        """
        Glättet die Rotationen in einer Trajektorie durch Vektorausreißer-Erkennung und Interpolation.

        Parameter:
            trajectory: Liste von (Position, Rotation)
            z_thresh: Z-Score-Schwellenwert

        Rückgabe:
            Neue geglättete Trajektorie mit gleich aufgebauter Struktur
        """
        positions = [pos for pos, _ in trajectory]
        rotations = np.array([rot for _, rot in trajectory])  # Shape (N, 3)

        smoothed_rot = self._interpolate_outlier_vectors_zscore(rotations, z_thresh=z_thresh)
        new_trajectory = [(pos, rot) for pos, rot in zip(positions, smoothed_rot)]
        return new_trajectory
    


    def plan_trajectory_with_fixed_orientation():
        """
        Variante 2 - Berechnung von Trajektorie mit fester Orientierung
            -> Orientierung kommt von Gerade Spitze -> Senke
        """
        pass



def main(args=None):
    rclpy.init(args=args)
    node = HookGeometricsHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
