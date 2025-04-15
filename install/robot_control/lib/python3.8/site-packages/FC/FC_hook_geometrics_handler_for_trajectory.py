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
        # Variablen für Haken-Koordinaten in WORK und TFC
        self.hook_pos_in_camframe = None
        self.hook_pos_in_workframe = None
        self.hook_pos_in_tcpframe = None
        self.tip_pos_in_camframe = None
        self.tip_pos_in_workframe = None
        self.tip_pos_in_tfcframe = None
        self.lowpoint_pos_in_camframe = None
        self.lowpoint_pos_in_workframe = None
        self.lowpoint_pos_in_tcpframe = None
        self.path_points_in_workframe = None
        self.path_points_in_tfcframe = None

        # Dict für Speicherung der aktuellen Hakengerade
        self.hook_line = {}
        self.handling_last_path_point = False
        self.distance_to_tip_in_mm = distance_to_tip_in_mm
        ##########

        # Variablen für die Regelung
        self.plane = None
        self.plane_midpoint = None
        self.T_plane_in_tfcframe = np.eye(4)
        self.plane_trans_in_tcpframe = None
        self.plane_rot_in_tcpframe = None
        self.delta_angles = None
        self.control_state = None
        self.trans_diff_in_tfcframe = None
        self.rot_diff_in_tfcframe = None

        # Optimale Richtungsvektoren für Gerade in WORK-Frame (XYZ-Konvention)
        optim_rotation_a_in_workframe = [0.0, 45.0, 45.0]
        optim_rotation_b_in_workframe = [0.0, 0.0, 25.0]
        optim_rotation_c_in_workframe = [0.0, 0.0, 45.0]
        optim_rotation_d_in_workframe = [0.0, 0.0, 15.0]

        self.optim_rot_list_in_workframe = [optim_rotation_a_in_workframe, 
                                            optim_rotation_b_in_workframe, 
                                            optim_rotation_c_in_workframe, 
                                            optim_rotation_d_in_workframe]
        
        # Berechne Rotationsmatrizen und daraus die Roll-Pitch-Yaw Winkel
        for idx in range(len(self.optim_rot_list_in_workframe)):
            rot = self.optim_rot_list_in_workframe[idx]
            rot_matrix_x = self.frame_handler.calculate_rot_matrix(rot = [rot[0], 0, 0])
            rot_matrix_y = self.frame_handler.calculate_rot_matrix(rot = [0, rot[1], 0])
            rot_matrix_z = self.frame_handler.calculate_rot_matrix(rot = [0, 0, rot[2]])
            rot_matrix = rot_matrix_x @ rot_matrix_y @ rot_matrix_z
            rpy = self.frame_handler.rotation_matrix_to_euler_angles(rotation_matrix = rot_matrix)
            print(rpy)
            self.optim_rot_list_in_workframe[idx] = rpy



    def _extract_hook_of_global_scan_dict(self, hook_num):
        """
        Lädt alle Daten für eine gegebene Hakennummer aus Global Scan Dict
        """
        if hook_num != 0 and hook_num <= len(self.global_scan_dict) and self.global_scan_dict is not None:
            self.hook_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_hook_in_camframe']
            self.hook_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_hook_in_workframe']
            self.tip_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_tip_in_camframe']
            self.tip_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_tip_in_workframe']
            self.lowpoint_pos_in_camframe = self.global_scan_dict[str(hook_num)]['xyz_lowpoint_in_camframe']
            self.lowpoint_pos_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_lowpoint_in_workframe']
            self.path_points_in_workframe = self.global_scan_dict[str(hook_num)]['xyz_path_points_in_workframe']
    


    def _calculate_trajectory_point_along_hook_line(self):
        """Methode zur Berechnung eines Trajektorien-Punktes über Haken-Gerade"""
        # self._calculate_hook_line(p0_in_workframe=p0_in_workframe, p1_in_workframe=p1_in_workframe)

        # Richtungsvektor dir berechnen
        dir_in_workframe = np.array(self.hook_line['p1_in_workframe']) - np.array(self.hook_line['p0_in_workframe'])
        abs = np.linalg.norm(dir_in_workframe)
        dir_in_workframe = dir_in_workframe / abs if abs != 0 else dir_in_workframe

        # neue x-TCP-Achse als Projektion des Richtungsvektors auf die xz-Ebene
        dir_xz_in_workframe = np.array([dir_in_workframe[0], 0, dir_in_workframe[2]])
        abs = np.linalg.norm(dir_xz_in_workframe)
        x_new = dir_xz_in_workframe / abs if abs != 0 else dir_xz_in_workframe

        # neue z-TCP-Achse entspricht dem Richtungsvektor (senkrechter Schnitt in die Lochebene)
        y_new = -dir_in_workframe
        
        # neue y-TCP-Achse über Kreuzprodukt
        z_new = np.cross(x_new, y_new)
        abs = np.linalg.norm(z_new)
        z_new = z_new / abs if abs != 0 else z_new

        # Aufbau der homogenen Transformation für TCP_new in WORK
        T_tcp_new_in_workframe = np.eye(4)
        T_tcp_new_in_workframe[:3, 0] = x_new
        T_tcp_new_in_workframe[:3, 1] = y_new
        T_tcp_new_in_workframe[:3, 2] = z_new
        T_tcp_new_in_workframe[:3, 3] = np.array(self.hook_line['p1_in_workframe'])

        # Transformation in WORLD
        T_work_in_worldframe = self.frame_handler.get_work_in_worldframe()
        T_tcp_new_in_worldframe = T_work_in_worldframe @ T_tcp_new_in_workframe

        # Translation und RPY extrahieren
        trans_xyz = T_tcp_new_in_worldframe[:3, 3].tolist()
        rot_rpy = R.from_matrix(T_tcp_new_in_worldframe[:3, :3]).as_euler('xyz', degrees = True).tolist()
        return trans_xyz, rot_rpy
    


    def _calculate_hook_line(self, p0_in_workframe = None, p1_in_workframe = None):
        """
        Berechnet eine Gerade entlang des Haken von p_0 (Senke) nach p_1 (Spitze)
        --> kann auch für stückweise tangentiale Geraden verwendet werden, dann p_0 bzw. p_1 eintragen
        """
        if self.tip_pos_in_workframe is not None and self.lowpoint_pos_in_workframe is not None:
            if p0_in_workframe is None:
                p_0 = self.lowpoint_pos_in_workframe     # p_0 ist Lowpoint
            else:
                p_0 = p0_in_workframe
            if p1_in_workframe is None:
                p_1 = self.tip_pos_in_workframe          # p_1 ist Spitze
            else:
                p_1 = p1_in_workframe
            
            # Richtungsvektor (normiert)
            p_dir = np.array(p_1) - np.array(p_0)
            abs_p_dir = np.linalg.norm(p_dir)
            if abs_p_dir != 0:
                p_dir /= abs_p_dir

            # self.get_logger().info("Updating hook line parameters...")
            # wird gespeichert in TCP-Frame
            self.hook_line['p0_in_workframe'] = p_0
            self.hook_line['p1_in_workframe'] = p_1
            self.hook_line['dir_in_workframe'] = p_dir            



    def _calculate_init_trajectory_point(self, p1_in_workframe = None, dir_in_workframe = None):
        """
        Berechnet den Init-Punkt für die Trjaketorie mit Abstand distance_to_tip_in_mm in [mm] zur Spitze
        """
        p_tip = self.hook_line['p1_in_workframe'] if p1_in_workframe is None else p1_in_workframe
        p_dir = self.hook_line['dir_in_workframe'] if dir_in_workframe is None else dir_in_workframe
        p_traj_init = p_tip + self.distance_to_tip_in_mm * p_dir
        self.hook_line['p_traj_init_in_workframe'] = p_traj_init
        return p_traj_init



    def plan_path_point_trajectory(self, hook_num=None):
        """
        Ansatz 1 - Pfad-Trajektorie
        Berechnet die vollständige Trajektorie für das Einfädeln entlang der Hakenform
        """
        if hook_num is None:
            self.get_logger().error(f"No Hook Num selected!")
            return None
        else:
            trajectory = []
            self._extract_hook_of_global_scan_dict(hook_num=hook_num)
            self._calculate_hook_line()

            # Berechne Init-Punkt (mit Abstand zur Spitze)
            self.get_logger().info("Calculating initial trajectory point...")
            p_traj_init = self._calculate_init_trajectory_point()

            # Berechne Anfangspunkt der Trajektorie
            self._calculate_hook_line(p0_in_workframe=self.tip_pos_in_workframe, p1_in_workframe=p_traj_init)
            pre_pose = self._calculate_trajectory_point_along_hook_line()

            # Trajektorie für alle Path Points berechnen
            for idx in range(len(self.path_points_in_workframe)):
                # Wenn wir nicht den letzten Punkt haben
                if idx < (len(self.path_points_in_workframe) - 1):
                    ppoint_1 = self.path_points_in_workframe[idx]
                    ppoint_0 = self.path_points_in_workframe[idx + 1]
                    self._calculate_hook_line(p0_in_workframe=ppoint_0, p1_in_workframe=ppoint_1)

                # Falls es der letzte Punkt ist
                elif idx == (len(self.path_points_in_workframe) - 1):
                    self.handling_last_path_point = True    # Flag für letzten path point setzen
                    self.get_logger().info(f"Handling last path point...")
                    self.hook_line['p1_in_workframe'] = self.path_points_in_workframe[idx]  # Letzten Punkt setzen

                # Berechne Trajektorienpunkt
                trajectory_point = self._calculate_trajectory_point_along_hook_line()
                trajectory.append(trajectory_point)

            # Füge den Prepose hinzu (Anfangspunkt der Trajektorie)
            trajectory.insert(0, pre_pose)

            # Optional: Ausreißer und Rotation glätten
            # trajectory_smoothed = self._smooth_trajectory(trajectory = trajectory, z_thresh = 2.3)
            # Rotationen glätten durch Polynom-Regression n=3
            # trajectory = self._polynomial_regression_trajectory_rotations(trajectory = trajectory_smoothed, degree = 1)
            return trajectory
    


    def plan_trajectory_with_fixed_orientation(self, hook_num = None, end_ppoint = None):
        """
        Ansatz 2 - Berechnung von Trajektorie mit fester Orientierung
            -> Orientierung kommt von Gerade Spitze -> Senke
        """
        if hook_num is None:
            self.get_logger().error(f"No Hook Num selected!")
            return None
        else:
            trajectory = []
            self._extract_hook_of_global_scan_dict(hook_num=hook_num)
            self._calculate_hook_line()
            end_ppoint = len(self.path_points_in_workframe) if end_ppoint is None else end_ppoint       # falls nicht anders übergeben, geht die Trajektorie bis in den letzten Path-Point            

            # Berechne konstante Orientierung anhand Gerade (Spitze -> Senke)
            _, rotation = self._calculate_trajectory_point_along_hook_line()
            
            # Berechne Init-Punkt (mit Abstand zur Spitze)
            self.get_logger().info("Calculating initial trajectory point...")
            p_traj_init = self._calculate_init_trajectory_point()

            # Berechne Anfangspunkt der Trajektorie
            self._calculate_hook_line(p0_in_workframe=self.tip_pos_in_workframe, p1_in_workframe=p_traj_init)
            pre_pose_translation, _ = self._calculate_trajectory_point_along_hook_line()
            pre_pose = (pre_pose_translation, rotation)

            # Trajektorie für alle Path Points berechnen
            for idx in range(len(self.path_points_in_workframe)):
                # Wenn wir nicht den letzten Punkt haben
                if idx < (len(self.path_points_in_workframe) - 1):
                    ppoint_1 = self.path_points_in_workframe[idx]
                    ppoint_0 = self.path_points_in_workframe[idx + 1]
                    self._calculate_hook_line(p0_in_workframe=ppoint_0, p1_in_workframe=ppoint_1)

                # Falls es der letzte Punkt ist
                elif idx == (len(self.path_points_in_workframe) - 1):
                    self.handling_last_path_point = True    # Flag für letzten path point setzen
                    self.get_logger().info(f"Handling last path point...")
                    self.hook_line['p1_in_workframe'] = self.path_points_in_workframe[idx]  # Letzten Punkt setzen
                
                trajectory_point_translation, _ = self._calculate_trajectory_point_along_hook_line()
                trajectory.append((trajectory_point_translation, rotation))
            
            # Ausreißer auf Translation und Rotationen entfernen
            # trajectory = self._smooth_trajectory(trajectory = trajectory, z_thresh = 2.3)
            # Rotationen glätten durch Polynom-Regression n=3 -> WIRD HIER NICHT BENÖTIGT, DA ROTATION IMMER GLEICH
            # trajectory = self._polynomial_regression_trajectory_rotations(trajectory = trajectory_smoothed, degree = 3)
            trajectory.insert(0, pre_pose)
            return trajectory
        

    
    def plan_trajectory_with_optimized_orientation(self, hook_num = None, end_ppoint = None, hook_type = 'a', beta=0):
        """
        Ansatz 3 - Berechnung der Trajektorie unter Voraussetzung einer optimalen Orientierung
            - Orientierung mit Hook-Line (Spitze -> Senke) berechnen und mit optimaler Orientierung (entsprechend Hakenmodell) vergleichen
                -> wenn Abweichung zu hoch -> Haken nicht nutzbar!
            - Orientierung korrigieren auf Mittelmaß zwischen Optimum und berechneter Orientierung
            - Planen der Trajektorie mit festem Einfädelungs-Weg attachment_distance_in_mm
        """
        if hook_num is None:
            self.get_logger().error(f"No Hook Num selected!")
            return None
        else:
            trajectory = []
            self._extract_hook_of_global_scan_dict(hook_num=hook_num)
            self._calculate_hook_line()
            end_ppoint = len(self.path_points_in_workframe) if end_ppoint is None else end_ppoint       # falls nicht anders übergeben, geht die Trajektorie bis in den letzten Path-Point            

            # Berechne konstante Orientierung anhand Gerade (Spitze -> Senke)
            _, rotation_calculated = self._calculate_trajectory_point_along_hook_line()

            # Extrahiere optimalen Richtungsvektor für Hook Type aus Liste und rechne von WORK in WORLD-Frame um
            rotation_optimal_in_workframe = self.optim_rot_list_in_workframe[['a', 'b', 'c', 'd'].index(hook_type)]
            R_in_workframe = self.frame_handler.calculate_rot_matrix(rot = rotation_optimal_in_workframe)
            T_work_in_worldframe = self.frame_handler.get_work_in_worldframe()
            R_in_worldframe = T_work_in_worldframe[:3, :3] @ R_in_workframe
            rotation_optimal = self.frame_handler.rotation_matrix_to_euler_angles(rotation_matrix = R_in_worldframe)

            # Gewichtung der Richtungsvektoren
            rotation_weighted = (1 - beta) * rotation_optimal + beta * np.array(rotation_calculated)
            rotation_weighted = rotation_weighted.tolist()

            self.get_logger().info(f"Calculated rotation for hook_type {hook_type}: {rotation_calculated}")
            self.get_logger().info(f"Optimal rotation for hook type {hook_type}: {rotation_optimal}")
            self.get_logger().info(f"Weighted rotation for hook type {hook_type}: {rotation_weighted}")
            
            # Berechne Init-Punkt (mit Abstand zur Spitze)
            self.get_logger().info("Calculating initial trajectory point...")
            p_traj_init = self._calculate_init_trajectory_point()

            # Berechne Anfangspunkt der Trajektorie
            self._calculate_hook_line(p0_in_workframe=self.tip_pos_in_workframe, p1_in_workframe=p_traj_init)
            pre_pose_translation, _ = self._calculate_trajectory_point_along_hook_line()
            pre_pose = (pre_pose_translation, rotation_weighted)

            # Trajektorie für alle Path Points berechnen
            for idx in range(len(self.path_points_in_workframe)):
                # Wenn wir nicht den letzten Punkt haben
                if idx < (len(self.path_points_in_workframe) - 1):
                    ppoint_1 = self.path_points_in_workframe[idx]
                    ppoint_0 = self.path_points_in_workframe[idx + 1]
                    self._calculate_hook_line(p0_in_workframe=ppoint_0, p1_in_workframe=ppoint_1)

                # Falls es der letzte Punkt ist
                elif idx == (len(self.path_points_in_workframe) - 1):
                    self.handling_last_path_point = True    # Flag für letzten path point setzen
                    self.get_logger().info(f"Handling last path point...")
                    self.hook_line['p1_in_workframe'] = self.path_points_in_workframe[idx]  # Letzten Punkt setzen
                
                trajectory_point_translation, _ = self._calculate_trajectory_point_along_hook_line()
                trajectory.append((trajectory_point_translation, rotation_weighted))
            
            # Ausreißer auf Translation und Rotationen entfernen
            # trajectory = self._smooth_trajectory(trajectory = trajectory, z_thresh = 2.3)
            # Rotationen glätten durch Polynom-Regression n=3 -> WIRD HIER NICHT BENÖTIGT, DA ROTATION IMMER GLEICH
            # trajectory = self._polynomial_regression_trajectory_rotations(trajectory = trajectory_smoothed, degree = 3)
            trajectory.insert(0, pre_pose)
            return trajectory
        

    def plan_optimized_trajectory(self, hook_num = None, hook_type = 'a', beta = 0, attachment_distance_in_mm = 0):
        """
        Ansatz 4 - Planung einer Trajektorie mit optimierter Orientierung (vgl. Ansatz 3) 
        und fester Einfädeldistanz von Spitze in Richtung Senke
        """
        if hook_num is None:
            self.get_logger().error(f"No Hook Num selected!")
            return None
        else:
            self._extract_hook_of_global_scan_dict(hook_num=hook_num)
            self._calculate_hook_line()

            # Berechne konstante Orientierung anhand Gerade (Spitze -> Senke)
            _, rotation_calculated = self._calculate_trajectory_point_along_hook_line()

            # Extrahiere optimalen Richtungsvektor für Hook Type aus Liste und rechne von WORK in WORLD-Frame um
            rotation_optimal_in_workframe = self.optim_rot_list_in_workframe[['a', 'b', 'c', 'd'].index(hook_type)]
            R_in_workframe = self.frame_handler.calculate_rot_matrix(rot = rotation_optimal_in_workframe)
            T_work_in_worldframe = self.frame_handler.get_work_in_worldframe()
            R_in_worldframe = T_work_in_worldframe[:3, :3] @ R_in_workframe
            rotation_optimal = self.frame_handler.rotation_matrix_to_euler_angles(rotation_matrix = R_in_worldframe)

            # Gewichtung der Richtungsvektoren
            rotation_weighted = (1 - beta) * rotation_optimal + beta * np.array(rotation_calculated)
            rotation_weighted = rotation_weighted.tolist()

            self.get_logger().info(f"Calculated rotation for hook_type {hook_type}: {rotation_calculated}")
            self.get_logger().info(f"Optimal rotation for hook type {hook_type}: {rotation_optimal}")
            self.get_logger().info(f"Weighted rotation for hook type {hook_type}: {rotation_weighted}")
            
            # Berechne Init-Punkt (mit Abstand zur Spitze)
            self.get_logger().info("Calculating initial trajectory point...")
            p_traj_init = self._calculate_init_trajectory_point()

            # Berechne Anfangspunkt der Trajektorie
            self._calculate_hook_line(p0_in_workframe=self.tip_pos_in_workframe, p1_in_workframe=p_traj_init)
            pre_pose_translation, _ = self._calculate_trajectory_point_along_hook_line()
            pre_pose = (pre_pose_translation, rotation_weighted)

            # Berechne Hakengerade für Spitze -> Senke und damit Startpunkt an Spitze
            self._calculate_hook_line(p0_in_workframe=self.lowpoint_pos_in_workframe, p1_in_workframe=self.tip_pos_in_workframe)
            tip_pose_translation, _ = self._calculate_trajectory_point_along_hook_line()
            tip_pose = (tip_pose_translation, rotation_weighted)

            # Berechne Endpose in Distanz attachment_distance_in_mm zur Spitze (dann wird Teil losgelassen)
            dir_in_workframe = self.hook_line['dir_in_workframe']
            end_pose_translation = (np.array(tip_pose_translation) - np.array(dir_in_workframe) * attachment_distance_in_mm).tolist()
            end_pose = (end_pose_translation, rotation_weighted)

            self.get_logger().warn(f"Pre Pose: {pre_pose}")
            self.get_logger().warn(f"Tip Pose: {tip_pose}")
            self.get_logger().warn(f"End Pose: {end_pose}")

            # Trajektorie aufbauen
            trajectory = [tip_pose, end_pose]
            
            # Ausreißer auf Translation und Rotationen entfernen
            # trajectory = self._smooth_trajectory(trajectory = trajectory, z_thresh = 2.3)
            # Rotationen glätten durch Polynom-Regression n=3 -> WIRD HIER NICHT BENÖTIGT, DA ROTATION IMMER GLEICH
            # trajectory = self._polynomial_regression_trajectory_rotations(trajectory = trajectory_smoothed, degree = 3)
            trajectory.insert(0, pre_pose)
            return trajectory



    def _polynomial_regression_trajectory_rotations(self, trajectory, degree=2):
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
    


    def _smooth_trajectory(self, trajectory, z_thresh=2.0):
        """
        Glättet die Rotationen in einer Trajektorie durch Vektorausreißer-Erkennung und Interpolation.

        Parameter:
            trajectory: Liste von (Position, Rotation)
            z_thresh: Z-Score-Schwellenwert

        Rückgabe:
            Neue geglättete Trajektorie mit gleich aufgebauter Struktur
        """
        positions = np.array([pos for pos, _ in trajectory])
        rotations = np.array([rot for _, rot in trajectory])  # Shape (N, 3)

        smoothed_rot = self._interpolate_outlier_vectors_zscore(rotations, z_thresh = z_thresh)
        smoothed_trans = self._interpolate_outlier_vectors_zscore(positions, z_thresh = z_thresh)

        # Geglättete Trajektorie - Translatorisch und Rotatorisch
        new_trajectory = [(pos, rot) for pos, rot in zip (smoothed_trans, smoothed_rot)]

        # Geglättete Trajektorie - Rotatorisch
        # new_trajectory = [(pos, rot) for pos, rot in zip(positions, smoothed_rot)]

        # Geglättete Trajektorie - Translatorisch
        # new_trajectory = [(pos, rot) for pos, rot in zip(smoothed_ptrans, rotations)]
        return new_trajectory



    def calculate_pre_position_with_z_offset(self, trajectory_in_worldframe = None, z_off_in_mm_in_workframe = 0.0):
        """
        Berechnet eine Pre-Pose für den TCP mit einem z-Offset z_off_in_mm zum Haken
            -> anschließend kann mit linearer Bewegung an den Haken gefahren werden
        """
        if trajectory_in_worldframe is not None:
            # extrahiere ersten Punkt (Spitze) aus der Trajektorie
            p_start_hook = trajectory_in_worldframe[0]
            p_start_hook_translation = p_start_hook[0]
            p_start_hook_rotation = p_start_hook[1]

            # Berechne Homogene Matrix der Pose in WORLD
            R_hook_pose_in_worldframe = self.frame_handler.calculate_rot_matrix(rot = p_start_hook_rotation)
            T_hook_pose_in_worldframe = np.eye(4)
            T_hook_pose_in_worldframe[:3, :3] = R_hook_pose_in_worldframe
            T_hook_pose_in_worldframe[:3, 3] = p_start_hook_translation

            # Transformiere die Pose in das WORK-Frame
            T_world_in_workframe = self.frame_handler.get_world_in_workframe()
            T_pose_in_workframe = T_world_in_workframe @ T_hook_pose_in_worldframe

            # Berechne neuen Translationsvektor für Pre-Pose
            translation_hook_in_workframe = T_pose_in_workframe[:3, 3]
            translation_hook_in_workframe[2] = translation_hook_in_workframe[2] - z_off_in_mm_in_workframe
            T_pose_in_workframe[:3, 3] = translation_hook_in_workframe

            # Zurücktransformieren ins WORLD-Frame als Listen zur Ansteuerung des Roboters
            pre_pose_translaion_in_worldframe, pre_pose_rotation_in_worldframe = self.frame_handler.transform_pose_to_world(
                pose_ref_frame = 'work',
                trans = T_pose_in_workframe[:3, 3],
                rot = self.frame_handler.rotation_matrix_to_euler_angles(rotation_matrix = T_pose_in_workframe[:3, :3]),
                )
            return pre_pose_translaion_in_worldframe, pre_pose_rotation_in_worldframe
        else:
            self.get_logger().error(f"Unable to calculate pre position - trajectory missing!")
            return None, None





def main(args=None):
    rclpy.init(args=args)
    node = HookGeometricsHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
