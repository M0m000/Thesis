import rclpy
from rclpy.node import Node
from FC.FC_frame_handler import FrameHandler
import numpy as np
import cv2



class CamGeometricsHandler(Node):
    def __init__(self,
                 calib_path_cam1 = '/home/mo/Thesis/calibration_data.npz',
                 calib_path_cam2 = '/home/mo/Thesis/calibration_data.npz',
                 img_width = 1280,
                 img_height = 720,
                 global_scan_dict = None):
        
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

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = "frame_handler_for_cam_geometrics_handler")

        # Speichern des Global Scan Dict
        self.global_scan_dict = global_scan_dict

    

    def _calculate_aperture_angle(self, cam_index = 1):
        """
        Berechnet die Öffnungswinkel des Objektivs - vgl. Breite des Sichtkegels
        """
        if cam_index == 1:
            sensor_width, sensor_height = self.sensor_width_cam_1, self.sensor_height_cam_1
            f_in_px = self.f_cam_1
            f_in_mm = self.objective_1_f_in_mm
        else:
            sensor_width, sensor_height = self.sensor_width_cam_2, self.sensor_height_cam_2
            f_in_px = self.f_cam_2
            f_in_mm = self.objective_2_f_in_mm
        
        aperture_angle_width = 2 * np.arctan(sensor_width / 2 * f_in_mm)
        aperture_angle_height = 2 * np.arctan(sensor_height / 2 * f_in_mm)
        return aperture_angle_width, aperture_angle_height
    


    def _calculate_field_of_view(self, aperture_angle_width, aperture_angle_height, distance_in_mm):
        """
        Berechnet FoV -> die Breite und Höhe des Sichtfeld in einem bestimmten Abstand d
        """
        fov_width = 2 * distance_in_mm * np.tan(aperture_angle_width / 2)
        fov_height = 2 * distance_in_mm * np.tan(aperture_angle_height / 2)
        return fov_width, fov_height
    


    def _calculate_fov_borders_in_camframe(self, fov_width, fov_height, distance_in_mm):
        """
        Berechnet aus den FoV-Werten die Grenzen als Bounding Box in CAM-Frame
        --> x-Achse zeigt im Bild nach rechts, y-Achse nach unten
        """
        upper_left = np.array([-fov_width/2, -fov_height/2, distance_in_mm])
        lower_right = np.array([fov_width/2, fov_height/2, distance_in_mm])
        return upper_left, lower_right
    


    def _transform_fov_bbox_to_desired_frame(self, bbox_upper_left, bbox_lower_right, frame_desired = 'work'):
        """
        Transformiert die FoV-Bounding Boxes in gewünschtes Frame (hier WORK)
        """
        bbox_upper_left_in_workframe = self.frame_handler.transform_worldpoint_in_frame(
            point = bbox_upper_left, 
            frame_desired = frame_desired)
        
        bbox_lower_right_in_workframe = self.frame_handler.transform_worldpoint_in_frame(
            point = bbox_lower_right, 
            frame_desired = frame_desired)
        
        return bbox_upper_left_in_workframe, bbox_lower_right_in_workframe
    


    def _get_visible_global_hook_ids(self, cam_index = 1, distance_in_mm = 0):
        """
        Findet die Indizes der momentan sichtbaren Haken aus Global Hook Dict
        """
        aperture_angle_width, aperture_angle_height = self._calculate_aperture_angle(cam_index = cam_index)

        fov_width, fov_height = self._calculate_field_of_view(
            aperture_angle_width = aperture_angle_width, 
            aperture_angle_height = aperture_angle_height,
            distance_in_mm = distance_in_mm)
        
        upper_left, lower_right = self._calculate_fov_borders_in_camframe(
            fov_width = fov_width, 
            fov_height = fov_height, 
            distance_in_mm = distance_in_mm)
        
        bbox_upper_left_in_workframe, bbox_lower_right_in_workframe = self._transform_fov_bbox_to_desired_frame(
            bbox_upper_left = upper_left, 
            bbox_lower_right = lower_right, 
            desired_frame = 'work')

        # Überprüfen aller Haken im Global Scan Dict, ob sie innerhalb des sichtbaren Bereichs liegen
        visible_hook_ids = []

        if self.global_scan_dict is not None:
            for idx, key in enumerate(self.global_scan_dict):
                xyz_hook_in_workframe = self.global_scan_dict[key]['xyz_hook_in_workframe']     # sobald Haken detektiert, gibt es diese Koordinate

                # Auf FoV-BBoxüberprüfen
                if (xyz_hook_in_workframe[0] >= bbox_upper_left_in_workframe[0] and xyz_hook_in_workframe[1] >= bbox_upper_left_in_workframe[1] and
                    xyz_hook_in_workframe[0] <= bbox_lower_right_in_workframe[0] and xyz_hook_in_workframe[1] <= bbox_lower_right_in_workframe[1]):
                    visible_hook_ids.append(idx)
            return visible_hook_ids
        else:
            return None
    


    def get_local_hook_id_to_follow(self, cam_index = 1, distance_in_mm = 0, global_id = 1):
        """
        Findet für eine globale Hook-ID anhand des FoV und der aktuellen Kameraposition die lokale ID eines Hakens im Bild
        """
        visible_hook_ids = self._get_visible_global_hook_ids(cam_index = cam_index, 
                                                             distance_in_mm = distance_in_mm)
        if visible_hook_ids is not None:
            for idx in range(len(visible_hook_ids)):
                if visible_hook_ids[idx] == global_id:
                    return idx      # Index in der Liste visible_hook_ids ist direkt der Instanz-Index des Hakens im Bild -> NOCH ZU CHECKEN, ob rückwärts
        return None             # falls der Index nicht gefunden wurde -> Kamera steht falsch und kann den gewünschten Haken nicht sehen -> return None
    


    def get_robot_position_for_global_hook_id(self, global_id = 1):
        """
        Findet die richtige Roboterstellung, sodass Haken mit gewünschter ID im Bild zu sehen ist
        """
        pass



    def plot_local_id(self, yolo_output_img = None, local_id = None, global_id = None):
        """
        Plottet den zu trackenden Haken innerhalb des Yolo-Output-Bilds
        """
        if yolo_output_img is not None and local_id is not None and global_id is not None and self.global_scan_dict is not None:
            key = 'hook_' + str(global_id)

            if key in self.global_scan_dict:
                bbox_hook = self.global_scan_dict[key].get('hook_box', None)
                x1, y1, x2, y2 = bbox_hook
                cv2.rectangle(yolo_output_img, (int(x1), int(y1)), (int(x2), int(y2)), (0, 255, 0), 3)
                return yolo_output_img
            if bbox_hook is None:
                self.get_logger().error(f"No Bounding Box found for {key}!")
        else:
            self.get_logger().error("No Image to plot...")
            return None




def main(args=None):
    rclpy.init(args=args)
    node = CamGeometricsHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
