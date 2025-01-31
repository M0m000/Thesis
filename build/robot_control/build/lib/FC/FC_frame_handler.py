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
