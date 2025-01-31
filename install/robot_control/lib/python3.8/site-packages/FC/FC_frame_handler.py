import numpy as np
import os
from rclpy.node import Node


class FrameHandler:
    def __init__(self, node, save_path):
        """Initialisiert den FrameHandler mit dem Pfad zu den CSV-Dateien."""
        self.node = node
        self.save_path = save_path  # Der Pfad zu den CSV-Dateien mit den Transformationsmatrizen



    def load_transformation_matrix_from_csv(self, frame_name):
        """Lädt die 4x4 Transformationsmatrix aus einer CSV-Datei, wenn der Frame-Name valide ist."""
        try:
            # Generiere den Dateinamen für die CSV-Datei
            filename = os.path.join(self.save_path, f"{frame_name}")
            
            if not os.path.exists(filename):
                self.node.get_logger().info(f"Warning: CSV for frame '{frame_name}' not existing!.")
                return None
            
            # Matrix aus CSV laden
            matrix = np.loadtxt(filename, delimiter=',')
            
            if matrix.shape != (4, 4):
                self.node.get_logger().info(f"Warning: Loaded matrix for frame '{frame_name}' has wrong shape!")
                return None

            self.node.get_logger().info(f"Loaded matrix for frame '{frame_name}' successfully!")
            return matrix

        except Exception as e:
            self.node.get_logger().info(f"Error while loading matrix for frame '{frame_name}'!")
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
        :param rot: Rotationswerte (roll, pitch, yaw) im lokalen Frame
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
        rot_world = R_ref_to_poseframe @ R_local

        return trans_world, rot_world
        



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