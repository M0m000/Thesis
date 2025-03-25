import numpy as np
import time
import cv2


class StereoTriangulationProcessor:
    def __init__(self,
                 extrinsic_data = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
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

        self.intrinsics[0][2] = c_x
        self.intrinsics[1][2] = c_y

        '''
        self.intrinsics = np.array([[f_x, 0, c_x], 
                                    [0, f_y, c_y], 
                                    [0, 0, 1]])
        '''
        
        self.dist = self.calib_data['dist']          # Verzerrungskoeffizienten
        self.rvecs = self.calib_data['rvecs']        # Rotationsvektoren - UNBENUTZT
        self.tvecs = self.calib_data['tvecs']        # Translationsvektoren - UNBENUTZT
        
        self.extrinsics_t = np.array([extrinsic_data[:3]])
        self.extrinsics_rot = np.array(extrinsic_data[-3:])
        self.extrinsics_t_for_calculation = None
        self.extrinsics = None
        
        self.projection_matrix_point_1 = None
        self.projection_matrix_point_2 = None
        self.measure_time = measure_time



    def calculate_extrinsics(self, baseline_vector, baseline, baseline_axis):
        angle_x, angle_y, angle_z = np.radians(self.extrinsics_rot)
        self.query_baseline(baseline_vector, baseline, baseline_axis)

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
        self.extrinsics = np.hstack((R, self.extrinsics_t_for_calculation.T))
        return self.extrinsics
    


    def calculate_projection_matrix(self, extrinsics):
        return self.intrinsics @ extrinsics



    def query_baseline(self, baseline_vector, baseline, baseline_axis):
        baseline_vector = np.array([0.0, 0.0, 0.0])
        
        if baseline_axis == 'x':
            baseline_vector = np.array([baseline, 0.0, 0.0])
        if baseline_axis == 'y':
            baseline_vector = np.array([0.0, baseline, 0.0])
        if baseline_axis == 'z':
            baseline_vector = np.array([0.0, 0.0, baseline])
        
        self.extrinsics_t_for_calculation = self.extrinsics_t + baseline_vector
        return self.extrinsics
    


    def prepare_point_for_triangulation(self, point):
        point = np.array(point, dtype=np.float64).T
        point = cv2.undistortPoints(point, self.intrinsics, self.dist, None, self.intrinsics)
        return point
    


    def triangulate_horizontal_points(self, projection_matrix_point_1, projection_matrix_point_2,
                                      point_1_uv, point_2_uv):
        """
        Berechnung der Horizontalen Triangulation
        """
        # Sicherstellen, dass die Punkte als 1D-Arrays vorliegen
        point1 = np.ravel(point_1_uv)
        point2 = np.ravel(point_2_uv)
        u1, v1 = point1[0], point1[1]
        u2, v2 = point2[0], point2[1]

        # Aufbau der 4x4-Gleichungsmatrix A
        A = np.zeros((4, 4))
        A[0, :] = u1 * projection_matrix_point_1[2, :] - projection_matrix_point_1[0, :]
        A[1, :] = v1 * projection_matrix_point_1[2, :] - projection_matrix_point_1[1, :]
        A[2, :] = u2 * projection_matrix_point_2[2, :] - projection_matrix_point_2[0, :]
        A[3, :] = v2 * projection_matrix_point_2[2, :] - projection_matrix_point_2[1, :]

        # Lösung des homogenen Gleichungssystems mittels Singulärwertzerlegung
        _, _, Vt = np.linalg.svd(A)
        X = Vt[-1]
        X = X / X[3]  # Normierung: Umwandlung in kartesische Koordinaten
        return X[:3]
    


    def triangulate_vertical_points(self, projection_matrix_point_1, projection_matrix_point_2,
                                    point_1_uv, point_2_uv):
        """
        Berechnet den 3D-Punkt aus zwei korrespondierenden Bildpunkten bei vertikaler Verschiebung,
        indem eine vollständige Rotation des Systems vorgenommen wird.

        Vorgehen:
          1. Definiere eine Rotationsmatrix R, um das Koordinatensystem so zu drehen, 
             dass der vertikale Baseline-Versatz (entlang der y-Achse) in einen horizontalen
             Versatz überführt wird. Hier verwenden wir eine Drehung um -90° um die z-Achse.
          2. Erzeuge aus R eine 4x4-Transformationsmatrix Q.
          3. Transformiere die Projektionsmatrizen: P_rot = P * Q⁻¹.
          4. Transformiere die Bildpunkte: p_rot = R * [u, v, 1]ᵀ (und normiere).
          5. Führe die horizontale Triangulation (DLT) im rotierten System durch.
          6. Transformiere die erhaltenen 3D-Punkte zurück in das Originalkoordinatensystem.

        Rückgabe:
          Ein numpy-Array mit den XYZ-Koordinaten des berechneten 3D-Punktes.
        """
        # 1. Definiere die Rotationsmatrix R (Rotation um -90° um die z-Achse)
        theta = np.radians(-90)
        R = np.array([[np.cos(theta), -np.sin(theta), 0],
                      [np.sin(theta),  np.cos(theta), 0],
                      [0,              0,             1]])

        # 2. Erzeuge eine 4x4 Transformationsmatrix Q aus R
        Q = np.eye(4)
        Q[:3, :3] = R
        # Da Q eine reine Rotation ist, entspricht Q⁻¹ = Qᵀ
        Q_inv = Q.T

        # 3. Transformiere die Projektionsmatrizen in das rotierte Koordinatensystem
        #    P_rot = P * Q⁻¹
        P1_rot = projection_matrix_point_1 @ Q_inv
        P2_rot = projection_matrix_point_2 @ Q_inv

        # 4. Transformiere die Bildpunkte:
        #    Zunächst in homogene Koordinaten überführen und dann mit R rotieren.
        p1 = np.ravel(point_1_uv)
        p2 = np.ravel(point_2_uv)
        p1_hom = np.array([p1[0], p1[1], 1.0])
        p2_hom = np.array([p2[0], p2[1], 1.0])
        p1_rot_hom = R @ p1_hom
        p2_rot_hom = R @ p2_hom
        # Normiere, sodass der dritte Eintrag 1 ist (falls möglich)
        p1_rot = p1_rot_hom[:2] / p1_rot_hom[2]
        p2_rot = p2_rot_hom[:2] / p2_rot_hom[2]

        # 5. Trianguliere im rotierten Koordinatensystem mithilfe der horizontalen Methode.
        #    Die Funktion triangulate_horizontal_points erwartet 2D-Punkte (u,v)
        X_rot = self.triangulate_horizontal_points(projection_matrix_point_1=P1_rot,
                                                   projection_matrix_point_2=P2_rot,
                                                   point_1_uv=p1_rot,
                                                   point_2_uv=p2_rot)

        # 6. Transformiere die berechneten 3D-Punkte zurück in das Originalkoordinatensystem:
        #    Da X_rot = Q * X gilt, folgt: X = Q⁻¹ * X_rot = Qᵀ * X_rot.
        X_rot_hom = np.append(X_rot, 1.0)
        X_hom = Q_inv @ X_rot_hom  # Q_inv = Qᵀ
        X_hom = X_hom / X_hom[3]
        X = X_hom[:3]
        return X
    


    def triangulate_single_point(self, point_1_uv = None, point_2_uv = None, baseline_vector = [0.0, 0.0, 0.0], baseline = 5.0, baseline_axis = 'x'):
        if point_1_uv is not None and point_2_uv is not None:
            extrinsics_point_1 = self.calculate_extrinsics(baseline_vector = [0.0, 0.0, 0.0], baseline = 0.0, baseline_axis = baseline_axis)
            extrinsics_point_2 = self.calculate_extrinsics(baseline_vector = baseline_vector, baseline = baseline, baseline_axis = baseline_axis)

            self.projection_matrix_point_1 = self.calculate_projection_matrix(extrinsics = extrinsics_point_1)
            self.projection_matrix_point_2 = self.calculate_projection_matrix(extrinsics = extrinsics_point_2)

            point_1_uv = self.prepare_point_for_triangulation(point_1_uv)
            point_2_uv = self.prepare_point_for_triangulation(point_2_uv)
            
            '''
            points4D_hom = cv2.triangulatePoints(self.projection_matrix_point_1, self.projection_matrix_point_2,
                                                 point_1_uv, point_2_uv)
            points3D = points4D_hom[:3] / points4D_hom[3]'
            '''

            if baseline_axis == 'x':
                points3D = self.triangulate_horizontal_points(
                    projection_matrix_point_1 = self.projection_matrix_point_1,
                    projection_matrix_point_2 = self.projection_matrix_point_2,
                    point_1_uv = point_1_uv,
                    point_2_uv = point_2_uv)
            if baseline_axis == 'y':
                points3D = self.triangulate_vertical_points(
                    projection_matrix_point_1 = self.projection_matrix_point_1,
                    projection_matrix_point_2 = self.projection_matrix_point_2,
                    point_1_uv = point_1_uv,
                    point_2_uv = point_2_uv)
            return points3D
        else:
            return None



    def triangulate_3_points(self, point_1_1_uv = None, point_1_2_uv = None, point_1_3_uv = None,
                                   point_2_1_uv = None, point_2_2_uv = None, point_2_3_uv = None,
                                   baseline_vector = [0.0, 0.0, 0.0],
                                   baseline = 0.0,
                                   baseline_axis='x'):
        start_time = time.perf_counter() if self.measure_time else None

        point_1_xyz = self.triangulate_single_point(point_1_1_uv, point_2_1_uv, baseline_vector = baseline_vector, baseline = baseline, baseline_axis = baseline_axis)
        point_2_xyz = self.triangulate_single_point(point_1_2_uv, point_2_2_uv, baseline_vector = baseline_vector, baseline = baseline, baseline_axis = baseline_axis)
        point_3_xyz = self.triangulate_single_point(point_1_3_uv, point_2_3_uv, baseline_vector = baseline_vector, baseline = baseline, baseline_axis = baseline_axis)

        end_time = time.perf_counter() if self.measure_time else None
        time_token = end_time - start_time if self.measure_time else None
        return [point_1_xyz, point_2_xyz, point_3_xyz], time_token if self.measure_time else [point_1_xyz, point_2_xyz, point_3_xyz]



    def triangulate_path_points(self, uv_path_points_1 = None, uv_path_points_2 = None,
                                baseline_vector = [0.0, 0.0, 0.0],
                                baseline = 0.0,
                                baseline_axis = 'x'):
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
                xyz_ppoint = self.triangulate_single_point(ppoint_img1, ppoint_img2, baseline_vector = baseline_vector, baseline = baseline, baseline_axis = baseline_axis)
                xyz_path_points.append(xyz_ppoint)
        
        end_time = time.perf_counter() if self.measure_time else None
        time_token = end_time - start_time if self.measure_time else None
        return xyz_path_points, time_token if self.measure_time else xyz_path_points