import rclpy
from rclpy.node import Node
import numpy as np
import os
import time
from kr_msgs.srv import GetSystemFrame
from scipy.spatial.transform import Rotation as R


class FrameHandler(Node):
    def __init__(self, node_name='frame_handler_node', save_path=None):
        """Initialisiert den FrameHandler als ROS2 Node mit dem Pfad zu den CSV-Dateien."""
        super().__init__(node_name)
        if save_path is None:
            self.save_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
        else:
            self.save_path = save_path
        self.get_logger().info('FrameHandler Node started.')

        self.get_system_frame_client = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')
        while not self.get_system_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Wait for service GetSystemFrame...")
        self.get_logger().info("Service GetSystemFrame available!")



    def load_transformation_matrix_from_csv(self, frame_name, max_retries=5, delay=0.05):
        """Lädt die 4x4 Transformationsmatrix aus einer CSV-Datei mit Wiederholungsversuchen bei Fehlern."""
        filename = os.path.join(self.save_path, f"{frame_name}")
        for attempt in range(1, max_retries + 1):
            try:
                if not os.path.exists(filename):
                    self.get_logger().info(f"Warning: CSV for frame '{frame_name}' not found. Attempt {attempt}/{max_retries}")
                    time.sleep(delay)
                    continue  # Erneuter Versuch

                matrix = np.loadtxt(filename, delimiter=',')
                if matrix.shape != (4, 4):
                    self.get_logger().info(f"Warning: Loaded matrix for frame '{frame_name}' has wrong shape! Attempt {attempt}/{max_retries}")
                    time.sleep(delay)
                    continue  # Erneuter Versuch

                return matrix  # Erfolgreich geladen

            except Exception as e:
                self.get_logger().info(f"Error loading matrix for frame '{frame_name}', attempt {attempt}/{max_retries}: {str(e)}")
                time.sleep(delay)

        self.get_logger().info(f"Failed to load transformation matrix for frame '{frame_name}' after {max_retries} attempts.")
        return None



    def query_and_load_frame(self, frame_name):
        """Abfrage des Frames, Laden der Transformation und Rückgabe der Matrix."""
        matrix = self.load_transformation_matrix_from_csv(frame_name)
        if matrix is not None:
            return matrix
        else:
            self.get_logger().info(f"Error at loading matrix for frame: {frame_name}")
            return None



    def transform_pose_to_world(self, pose_ref_frame, trans=[0.0, 0.0, 0.0], rot=[0.0, 0.0, 0.0]):
        """
        Transformiert eine gegebene Position und Orientierung (in einem lokalen Frame) in das Welt-Koordinatensystem.
        """
        R_local = self.calculate_rot_matrix(rot)
        if pose_ref_frame == "work":
            T_ref_to_poseframe = self.load_transformation_matrix_from_csv(frame_name = 'WORK_frame_in_world.csv')
        else:
            _, _, T_ref_to_poseframe = self.get_system_frame(name = pose_ref_frame, ref = 'world')

        if T_ref_to_poseframe is None:
            return None, None

        R_ref_to_poseframe = T_ref_to_poseframe[:3, :3]
        t_ref_to_poseframe_position = T_ref_to_poseframe[:3, 3]

        trans_world = R_ref_to_poseframe @ trans + t_ref_to_poseframe_position
        rot_world_matrix = R_ref_to_poseframe @ R_local
        rot_world = self.rotation_matrix_to_euler_angles(rot_world_matrix)
        return trans_world, rot_world



    def transform_velocity_to_world(self, vel, from_frame):
        """Transformiert eine Geschwindigkeit in das Welt-Koordinatensystem."""
        if from_frame == 'work':
            T_world_to_velframe = self.load_transformation_matrix_from_csv(frame_name = 'WORK_frame_in_world.csv')
        else:
            _, _, T_world_to_velframe = self.get_system_frame(name = from_frame, ref = 'world')
        
        if T_world_to_velframe is None:
            return None
        R_world_to_velframe = T_world_to_velframe[:3, :3]
        return R_world_to_velframe @ vel



    def calculate_rot_matrix(self, rot):
        """Berechnet die Rotationsmatrix aus den Euler-Winkeln."""
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



    def rotation_matrix_to_euler_angles(self, rotation_matrix):
        r = R.from_matrix(rotation_matrix)  # Erstelle ein Rotation-Objekt aus der Matrix
        euler_angles = r.as_euler('xyz', degrees=True)  # Berechne Euler-Winkel, hier 'xyz' als Beispiel, kannst auch andere Achsenbestellungen verwenden
        return euler_angles


    '''
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
    '''


    def calculate_position_difference_in_same_frame(self, T_1, T_2):
        """Berechnet den Positionsunterschied zwischen zwei Transformationen im selben Koordinatensystem."""
        t_1 = T_1[:3, 3]
        t_2 = T_2[:3, 3]
        return t_2 - t_1



    def transform_worldpoint_in_frame(self, point, frame_desired):
        """Transformiert einen Weltpunkt in ein anderes Frame."""
        if frame_desired == "work":
            T_world_to_desired = self.load_transformation_matrix_from_csv(frame_name = 'WORK_frame_in_world.csv')
        else:
            _, _, T_world_to_desired = self.get_system_frame(name = frame_desired, ref = 'world')

        T_desired_to_world = np.linalg.inv(T_world_to_desired)
        point_world_hom = np.array([point[0], point[1], point[2], 1.0])
        point_desired_hom = T_desired_to_world @ point_world_hom
        return point_desired_hom[:3].tolist()
    


    def transform_worldpose_to_desired_frame(self, T_in_worldframe, frame_desired):
        """Transformiert eine homogene Transformationsmatrix in ein anderes Frame frame_desired."""
        if frame_desired == "work":
            T_world_to_desired = self.load_transformation_matrix_from_csv(frame_name = 'WORK_frame_in_world.csv')
        else:
            _, _, T_world_to_desired = self.get_system_frame(name = frame_desired, ref = 'world')

        T_desired_to_world = np.linalg.inv(T_world_to_desired)
        return T_desired_to_world @ T_in_worldframe
    


    def get_system_frame(self, name: str, ref: str):
        """Ruft den Service /kr/robot/get_system_frame auf und gibt die Position und Orientierung zurück."""
        request = GetSystemFrame.Request()
        request.name = name
        request.ref = ref

        # Service-Aufruf und Antwort abwarten
        future = self.get_system_frame_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None and future.result().success:
            pos = future.result().pos.tolist()
            rot = future.result().rot.tolist()

            R = self.calculate_rot_matrix(rot = rot)
            T = np.eye(4)
            T[:3, :3] = R
            T[:3, 3] = np.array(pos)
            return pos, rot, T
        else:
            self.get_logger().error("Error at service call GetSystemFrame.")
            return None, None, None
        


    def get_cam_transform_in_world(self):
        """Lädt die Transformation von CAM zu WORLD"""
        _, _, T_world_tfc = self.get_system_frame(name = 'tcp', ref = 'world')
        T_tfc_cam = self.load_transformation_matrix_from_csv(frame_name = 'CAM_frame_in_tcp.csv')
        return T_world_tfc @ T_tfc_cam
    


    def get_world_transform_in_cam(self):
        """Lädt die Transformation von WORLD zu CAM"""
        T_cam_in_worldframe = self.get_cam_transform_in_world()
        return np.linalg.inv(T_cam_in_worldframe)
    


    def get_cam_transform_in_workframe(self):
        """Lädt die Transformation von CAM zu WORK"""
        T_cam_in_worldframe = self.get_cam_transform_in_world()
        return self.transform_worldpose_to_desired_frame(T_cam_in_worldframe, 'work')
    


    def get_work_in_worldframe(self):
        """Liefert die homogene Transformation von WORK in WORLD"""
        T_work_in_worldframe = self.query_and_load_frame(frame_name = 'WORK_frame_in_world.csv')
        return T_work_in_worldframe



    def get_world_in_workframe(self):
        """Liefert die homogene Transformation von WORLD in WORK"""
        T_work_in_worldframe = self.query_and_load_frame(frame_name = 'WORK_frame_in_world.csv')
        T_world_in_workframe = np.linalg.inv(T_work_in_worldframe)
        return T_world_in_workframe




def main(args=None):
    rclpy.init(args=args)

    save_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
    frame_handler_node = FrameHandler(node_name='frame_handler_node', save_path=save_path)

    rclpy.spin(frame_handler_node)

    frame_handler_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
