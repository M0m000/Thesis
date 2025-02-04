import numpy as np
import os
from rclpy.node import Node
import time


class FrameHandler:
    def __init__(self, node, save_path):
        """Initialisiert den FrameHandler mit dem Pfad zu den CSV-Dateien."""
        self.node = node
        self.save_path = save_path  # Der Pfad zu den CSV-Dateien mit den Transformationsmatrizen



    def load_transformation_matrix_from_csv(self, frame_name, max_retries=5, delay=0.05):
        """
        Lädt die 4x4 Transformationsmatrix aus einer CSV-Datei mit Wiederholungsversuchen bei Fehlern.

        :param frame_name: Name des Frames (String), der zur Matrix gehört.
        :param max_retries: Maximale Anzahl an Wiederholungen bei Fehlern (default: 5).
        :param delay: Wartezeit (Sekunden) zwischen den Versuchen (default: 0.5s).
        :return: 4x4 numpy-Array der Transformationsmatrix oder None bei Fehler.
        """
        filename = os.path.join(self.save_path, f"{frame_name}")

        for attempt in range(1, max_retries + 1):
            try:
                if not os.path.exists(filename):
                    self.node.get_logger().info(f"Warning: CSV for frame '{frame_name}' not found. Attempt {attempt}/{max_retries}")
                    time.sleep(delay)
                    continue  # Erneuter Versuch

                matrix = np.loadtxt(filename, delimiter=',')

                if matrix.shape != (4, 4):
                    self.node.get_logger().info(f"Warning: Loaded matrix for frame '{frame_name}' has wrong shape! Attempt {attempt}/{max_retries}")
                    time.sleep(delay)
                    continue  # Erneuter Versuch

                return matrix  # Erfolgreich geladen

            except Exception as e:
                self.node.get_logger().info(f"Error loading matrix for frame '{frame_name}', attempt {attempt}/{max_retries}: {str(e)}")
                time.sleep(delay)

        self.node.get_logger().info(f"Failed to load transformation matrix for frame '{frame_name}' after {max_retries} attempts.")
        return None




    def query_and_load_frame(self, frame_name):
        """Abfrage des Frames, Laden der Transformation und Rückgabe der Matrix."""
        matrix = self.load_transformation_matrix_from_csv(frame_name)
        if matrix is not None:
            return matrix
        else:
            print(f"Fehler beim Laden der Matrix für das Frame: {frame_name}")
            return None



    def transform_pose_to_world(self, trans, rot, pose_ref_frame):
        """
        Transformiert eine gegebene Position und Orientierung (in einem lokalen Frame)
        in das Welt-Koordinatensystem und gibt die transformierten Position und Orientierung zurück.
        :param trans: Translationswerte (x, y, z) im lokalen Frame
        :param rot: Rotationswerte [roll, pitch, yaw] im lokalen Frame
        :param pose_ref_frame: Der Name des Referenz-Frames, das die Transformation definiert
        :return: transformierte Position und Orientierung im Weltkoordinatensystem
        """
        R_local = self.calculate_rot_matrix(rot)

        frame_name = str(pose_ref_frame) + '_world.csv'
        T_ref_to_poseframe = self.query_and_load_frame(frame_name)

        if T_ref_to_poseframe is None:
            return None, None

        R_ref_to_poseframe = T_ref_to_poseframe[:3, :3]
        t_ref_to_poseframe_position = T_ref_to_poseframe[:3, 3]

        trans_world = R_ref_to_poseframe @ trans + t_ref_to_poseframe_position
        rot_world_matrix = R_ref_to_poseframe @ R_local
        rot_world = self.rotation_matrix_to_euler_angles(rot_world_matrix)
        return trans_world, rot_world
    


    def tansform_velocity_to_world(self, vel, from_frame):
        frame_name = str(from_frame) + '_world.csv'
        T_world_to_velframe = self.query_and_load_frame(frame_name)
        
        if T_world_to_velframe is None:
            return None
        
        R_world_to_velframe = T_world_to_velframe[:3, :3]
        return R_world_to_velframe @ vel
        



    def calculate_rot_matrix(self, rot):
        ax, ay, az = np.radians(rot)  # rot = [roll, pitch, yaw]

        R_x = np.array([[1, 0, 0],
                        [0, np.cos(ax), -np.sin(ax)],
                        [0, np.sin(ax), np.cos(ax)]])

        R_y = np.array([[np.cos(ay), 0, np.sin(ay)],
                        [0, 1, 0],
                        [-np.sin(ay), 0, np.cos(ay)]])

        R_z = np.array([[np.cos(az), -np.sin(az), 0],
                        [np.sin(az), np.cos(az), 0],
                        [0, 0, 1]])
        return R_z @ R_y @ R_x
    


    def rotation_matrix_to_euler_angles(self, R):
        """Umwandlung einer 3x3 Rotationsmatrix in Euler-Winkel (roll, pitch, yaw)."""
        sy = np.sqrt(R[0, 0] ** 2 + R[1, 0] ** 2)

        singular = sy < 1e-6  # Prüfen auf Singularität

        if not singular:
            ax = np.arctan2(R[2, 1], R[2, 2])  # roll
            ay = np.arctan2(-R[2, 0], sy)       # pitch
            az = np.arctan2(R[1, 0], R[0, 0])   # yaw
        else:
            ax = np.arctan2(-R[1, 2], R[1, 1])  # roll
            ay = np.arctan2(-R[2, 0], sy)       # pitch
            az = 0                              # yaw (undefiniert)
        return np.degrees([ax, ay, az])
    


    def calculate_position_difference_in_same_frame(self, T_1, T_2):
        t_1 = T_1[:3, 3]
        t_2 = T_2[:3, 3]
        return t_2 - t_1
    


    def transform_worldpoint_in_frame(self, point, frame_desired):
        '''
        Berechnet einen Punkt gegeben im WORLD Frame in ein anderes Frame 'frame_desired' um
        -> Voraussetzung, es muss über den tf_frame_publisher eine Transformation von frame_desired zu WORLD existieren, die invertiert werden kann!
        '''
        frame_name = str(frame_desired) + '_world.csv'
        T_world_to_desired = self.query_and_load_frame(frame_name)

        T_desired_to_world = np.linalg.inv(T_world_to_desired)
        point_world_hom = np.array([point[0], point[1], point[2], 1.0])
        point_desired_hom = T_desired_to_world @ point_world_hom
        return point_desired_hom[:3].tolist()