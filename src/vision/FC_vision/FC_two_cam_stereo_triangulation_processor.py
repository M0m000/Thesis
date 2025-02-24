import numpy as np
import time
import cv2


class TwoCamStereoTriangulationProcessor:
    def __init__(self,
                 extrinsic_data = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
                 calib_path_cam1 = '/home/mo/Thesis/calibration_data.npz',
                 calib_path_cam2 = '/home/mo/Thesis/calibration_data.npz',
                 measure_time = False,
                 img_width = 1280,
                 img_height = 720):
        
        self.calib_data_cam1 = np.load(calib_path_cam1)
        self.calib_data_cam2 = np.load(calib_path_cam2)
        self.intrinsics_cam1 = self.calib_data_cam1['mtx']     # Kameramatrix (mit Brennweite Verzerrung etc.)
        self.intrinsics_cam2 = self.calib_data_cam2['mtx']

        # f = 0.006/3.45e-6
        c_x = img_width / 2
        c_y = img_height / 2

        self.calib_data_cam1[0][2] = c_x
        self.calib_data_cam1[1][2] = c_y
        self.calib_data_cam2[0][2] = c_x
        self.calib_data_cam2[1][2] = c_y

        self.dist_cam1 = self.calib_data_cam1['dist']          # Verzerrungskoeffizienten
        self.dist_cam2 = self.calib_data_cam2['dist']
        
        self.extrinsics_t = np.array([extrinsic_data[:3]])      # Translation
        self.extrinsics_rot = np.array(extrinsic_data[-3:])     # Rotation
        self.extrinsics = None
        
        self.projection_matrix_point_1 = None
        self.projection_matrix_point_2 = None
        self.measure_time = measure_time



    def calculate_extrinsics(self, cam_index = 1):
        if cam_index == 2:
            t = self.extrinsics_t
            angle_x, angle_y, angle_z = np.radians(self.extrinsics_rot)
        else:
            t = np.array([0, 0, 0])
            angle_x, angle_y, angle_z = 0, 0, 0
        
        R_x = np.array([[1, 0, 0],
                        [0, np.cos(angle_x), -np.sin(angle_x)],
                        [0, np.sin(angle_x), np.cos(angle_x)]])

        R_y = np.array([[np.cos(angle_y), 0, np.sin(angle_y)],
                        [0, 1, 0],
                        [-np.sin(angle_y), 0, np.cos(angle_y)]])

        R_z = np.array([[np.cos(angle_z), -np.sin(angle_z), 0],
                        [np.sin(angle_z), np.cos(angle_z), 0],
                        [0, 0, 1]])
        R = R_x @ (R_y @ R_z)

        self.extrinsics = np.hstack((R, self.extrinsics_t.T))
        return self.extrinsics
    


    def calculate_projection_matrix(self, extrinsics):
        return self.calib_data_cam1 @ extrinsics
        


    def prepare_point_for_triangulation(self, point, cam_index = 1):
        if cam_index == 1:
            calib_data = self.calib_data_cam1
            dist = self.dist_cam1
        else:
            calib_data = self.calib_data_cam2
            dist = self.dist_cam2

        point = np.array(point, dtype=np.float64).T
        point = cv2.undistortPoints(point, calib_data, dist, None, calib_data)
        return point
    


    def triangulate_single_point(self, point_1_uv = None, point_2_uv = None):
        if point_1_uv is not None and point_2_uv is not None:
            extrinsics_point_1 = self.calculate_extrinsics(cam_index = 1)
            extrinsics_point_2 = self.calculate_extrinsics(cam_index = 2)

            self.projection_matrix_point_1 = self.calculate_projection_matrix(extrinsics = extrinsics_point_1)
            self.projection_matrix_point_2 = self.calculate_projection_matrix(extrinsics = extrinsics_point_2)

            point_1_uv = self.prepare_point_for_triangulation(point_1_uv, cam_index = 1)
            point_2_uv = self.prepare_point_for_triangulation(point_2_uv, cam_index = 2)

            points4D_hom = cv2.triangulatePoints(self.projection_matrix_point_1, self.projection_matrix_point_2,
                                                 point_1_uv, point_2_uv)
            return points4D_hom[:3] / points4D_hom[3]
        else:
            return None



    def triangulate_3_points(self, point_1_1_uv = None, point_1_2_uv = None, point_1_3_uv = None,
                                   point_2_1_uv = None, point_2_2_uv = None, point_2_3_uv = None):
        start_time = time.perf_counter() if self.measure_time else None

        point_1_xyz = self.triangulate_single_point(point_1_1_uv, point_2_1_uv)
        point_2_xyz = self.triangulate_single_point(point_1_2_uv, point_2_2_uv)
        point_3_xyz = self.triangulate_single_point(point_1_3_uv, point_2_3_uv)

        end_time = time.perf_counter() if self.measure_time else None
        time_token = end_time - start_time if self.measure_time else None
        return [point_1_xyz, point_2_xyz, point_3_xyz], time_token if self.measure_time else [point_1_xyz, point_2_xyz, point_3_xyz]
    
    