import numpy as np
import time
import cv2


class StereoTriangulationProcessor:
    def __init__(self,
                 calib_path = '/home/mo/Thesis/calibration_data.npz',
                 measure_time = False,
                 img_width = 1280,
                 img_height = 720):
        
        self.calib_data = np.load(calib_path)
        self.intrinsics = self.calib_data['mtx']     # Kameramatrix (mit Brennweite Verzerrung etc.)

        f_x = 0.006/3.45e-6
        f_y = 0.006/3.45e-6
        c_x = img_width / 2
        c_y = img_height / 2
        '''
        self.intrinsics = np.array([[f_x, 0, c_x], 
                                    [0, f_y, c_y], 
                                    [0, 0, 1]])
        '''
        self.intrinsics[0][2] = c_x
        self.intrinsics[1][2] = c_y
        
        self.dist = self.calib_data['dist']          # Verzerrungskoeffizienten
        self.rvecs = self.calib_data['rvecs']        # Rotationsvektoren - UNBENUTZT
        self.tvecs = self.calib_data['tvecs']        # Translationsvektoren - UNBENUTZT
        
        self.projection_matrix_point_1 = None
        self.projection_matrix_point_2 = None
        self.measure_time = measure_time

        self.T_baseline = None
        self.R_baseline = None
        self.t_baseline = None

        self.rot_matrix = np.array([[1, 0, 0],
                                    [0, -1, 0],
                                    [0, 0, -1]])


    def calculate_relatvie_pose(self, T_cam_1_in_workframe, T_cam_2_in_workframe):
        """
        Berechnet die Transformationsmatrix von Cam2 zu Cam1 (für Triangulation im Frame von Kamera 2)
        """
        self.T_baseline = np.linalg.inv(T_cam_2_in_workframe) @ T_cam_1_in_workframe
        self.R_baseline = self.T_baseline[:3, :3]
        self.t_baseline = self.T_baseline[:3, 3].reshape(3, 1)
        return self.R_baseline, self.t_baseline, self.T_baseline
    

    def calculate_projection_matrices(self, intrinsics = None, R_baseline = None, t_baseline = None):
        """
        Berechnet die Projektionsmatrizen für Cam2 (Referenz) und Cam1
        """
        if intrinsics is None:
            intrinsics = self.intrinsics
        if R_baseline is None:
            R_baseline = self.R_baseline
        if t_baseline is None:
            t_baseline = self.t_baseline
        self.projection_matrix_cam1 = intrinsics @ np.hstack((R_baseline, t_baseline))
        self.projection_matrix_cam2 = intrinsics @ np.hstack((np.eye(3), np.zeros((3, 1))))
        return self.projection_matrix_cam1, self.projection_matrix_cam2
    

    def prepare_point_for_triangulation(self, point):
        """
        Entzerrt den Punkt gemäß der geschätzten Verzerrungsparameter des Objektivs
        """
        point = np.array(point, dtype=np.float64).reshape(1, 2)  # shape: (1, 2)
        point = cv2.undistortPoints(point, self.intrinsics, self.dist, None, self.intrinsics)
        return point.reshape(2, 1)  # OpenCV erwartet (2, N)        
    

    def triangulate_point(self, projection_matrix_cam1 = None, projection_matrix_cam2 = None, point_1_uv = [0.0, 0.0], point_2_uv = [0.0, 0.0]):
        """
        Berechnet die Triangulation
        """
        projection_matrix_cam1 = self.projection_matrix_cam1 if projection_matrix_cam1 is None else projection_matrix_cam1
        projection_matrix_cam2 = self.projection_matrix_cam2 if projection_matrix_cam2 is None else projection_matrix_cam2

        X_hom = cv2.triangulatePoints(projection_matrix_cam2, projection_matrix_cam1, point_2_uv, point_1_uv)
        X = X_hom[:3] / X_hom[3]
        return X


    def triangulate_single_point(self, point_1_uv, point_2_uv, T_cam_1_in_workframe, T_cam_2_in_workframe):
        """
        Funktion, die für die Triangulation mit vorgegebener Baseline Transformation genutzt werden kann
        """
        start_time = time.perf_counter()

        self.calculate_relatvie_pose(T_cam_1_in_workframe = T_cam_1_in_workframe, T_cam_2_in_workframe = T_cam_2_in_workframe)
        self.calculate_projection_matrices()
        point_1_uv = self.prepare_point_for_triangulation(point = point_1_uv)
        point_2_uv = self.prepare_point_for_triangulation(point = point_2_uv)
        xyz_point = self.triangulate_point(point_1_uv = point_1_uv, point_2_uv = point_2_uv)
        print("XYZ Point before Rotation: ", xyz_point)
        xyz_point = self.rot_matrix @ xyz_point
        print("XYZ Point after Rotation: ", xyz_point)

        end_time = time.perf_counter
        time_token = end_time - start_time
        return xyz_point, time_token if self.measure_time else xyz_point


    def triangulate_path_points(self, uv_path_points_1 = None, uv_path_points_2 = None,
                                T_cam_1_in_workframe = None, T_cam_2_in_workframe = None):
        """
        Berechnet die Stereo-Triangulation für eine komplette Path Point Länge entsprechend beider Path Point Liste
        """
        xyz_path_points = []

        start_time = time.perf_counter() if self.measure_time else None

        num_ppoints_1 = len(uv_path_points_1)
        num_ppoints_2 = len(uv_path_points_2)

        # wenn Listen ungleiche Länge haben -> Fehler!
        if num_ppoints_1 != num_ppoints_2:
            print(f"ERROR - Lengths of Path Point Lists are unequal!")
            return None
        else:
            for idx in range(num_ppoints_1):
                ppoint_img1 = uv_path_points_1[idx]
                ppoint_img2 = uv_path_points_2[idx]
                xyz_ppoint, _ = self.triangulate_single_point(
                    point_1_uv = ppoint_img1, point_2_uv = ppoint_img2, 
                    T_cam_1_in_workframe = T_cam_1_in_workframe, 
                    T_cam_2_in_workframe = T_cam_2_in_workframe)
                xyz_path_points.append(xyz_ppoint)
        
        end_time = time.perf_counter() if self.measure_time else None
        time_token = end_time - start_time if self.measure_time else None
        return xyz_path_points, time_token if self.measure_time else xyz_path_points
    