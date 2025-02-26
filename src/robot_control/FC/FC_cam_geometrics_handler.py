import rclpy
from rclpy.node import Node
from FC.FC_frame_handler import FrameHandler
from FC.FC_geometrics_handler import GeometricsHandler
import numpy as np



class CamGeometricsHandler(Node):
    def __init__(self,
                 calib_path_cam1 = '/home/mo/Thesis/calibration_data.npz',
                 calib_path_cam2 = '/home/mo/Thesis/calibration_data.npz',
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

        self.sensor_width_cam_1 = 3.45e-6
        self.sensor_height_cam_1 = 3.45e-6
        self.sensor_width_cam_2 = 3.45e-6
        self.sensor_height_cam_2 = 3.45e-6

        self.objective_1_f_in_mm = 0.006            # Brennweite der Objektive [mm]
        self.objective_2_f_in_mm = 0.008

        self.f_cam_1 = self.objective_1_f_in_mm/self.sensor_width_cam_1         # Brennweite [px]
        self.f_cam_2 = self.objective_2_f_in_mm/self.sensor_width_cam_2

        self.frame_handler = FrameHandler(node_name = "frame_handler_for_cam_geometrics_handler")
        self.hook_geometrics_handler = GeometricsHandler()

    

    def calculate_aperture_angle(self, cam_index = 1):
        """
        Berechnet die Öffnungswinkel des Objektivs - vgl. Breite des Sichtkegels
        """
        if cam_index == 1:
            sensor_width, sensor_height = self.sensor_width_cam_1, self.sensor_height_cam_1
            f_in_px = self.f_cam_1
            f_in_mm = self.objective_1_f_in_mm
        else:
            sensor_widht, sensor_height = self.sensor_width_cam_2, self.sensor_height_cam_2
            f_in_px = self.f_cam_2
            f_in_mm = self.objective_2_f_in_mm
        
        aperture_angle_width = 2 * np.arctan(sensor_width / 2 * f_in_mm)
        aperture_angle_height = 2 * np.arctan(sensor_height / 2 * f_in_mm)
        return aperture_angle_width, aperture_angle_height
    


    def calculate_field_of_view(self, aperture_angle_width, aperture_angle_height, distance_in_mm):
        """
        Berechnet FoV -> die Breite und Höhe des Sichtfeld in einem bestimmten Abstand d
        """
        fov_width = 2 * distance_in_mm * np.tan(aperture_angle_width / 2)
        fov_height = 2 * distance_in_mm * np.tan(aperture_angle_height / 2)
        return fov_width, fov_height
    


    def calculate_fov_borders_in_camframe(self, fov_width, fov_height, distance_in_mm):
        """
        Berechnet aus den FoV-Werten die Grenzen als Bounding Box in CAM-Frame
        --> x-Achse zeigt im Bild nach rechts, y-Achse nach unten
        """
        upper_left = np.array([-fov_width/2, -fov_height/2, distance_in_mm])
        lower_right = np.array([fov_width/2, fov_height/2, distance_in_mm])
        return upper_left, lower_right
    


    def transform_fov_bbox_to_desired_frame(self, bbox_upper_left, bbox_lower_right, desired_frame = 'work'):
        """
        Transformiert die FoV-Bounding Boxes in gewünschtes Frame (hier WORK)
        """
        bbox_upper_left_in_workframe = self.frame_handler.transform_worldpoint_in_frame(point = bbox_upper_left, frame_desired = 'work')
        bbox_lower_right_in_workframe = self.frame_handler.transform_worldpoint_in_frame(point = bbox_lower_right, frame_desired = 'work')
        return bbox_upper_left_in_workframe, bbox_lower_right_in_workframe
    


    def get_visible_hook_ids(self, bbox_upper_left_in_workframe, bbox_lower_right_in_workframe):
        """
        Findet die Indizes der momentan sichtbaren Haken aus Global Hook Dict
        """
        visible_hook_ids = []

        # Überprüfen aller Haken im Global Scan Dict, ob sie innerhalb des sichtbaren Bereichs liegen
        for idx, key in enumerate(self.hook_geometrics_handler.global_scan_dict):
            xyz_hook_in_workframe = self.hook_geometrics_handler.global_scan_dict[key]['xyz_hook_in_workframe']     # sobald Haken detektiert, gibt es diese Koordinate

            # Auf FoV-BBoxüberprüfen
            if (xyz_hook_in_workframe[0] >= bbox_upper_left_in_workframe[0] and xyz_hook_in_workframe[1] >= bbox_upper_left_in_workframe[1] and
                xyz_hook_in_workframe[0] <= bbox_lower_right_in_workframe[0] and xyz_hook_in_workframe[1] <= bbox_lower_right_in_workframe[1]):
                visible_hook_ids.append(idx)
        return visible_hook_ids

        



def main(args=None):
    rclpy.init(args=args)
    node = CamGeometricsHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
