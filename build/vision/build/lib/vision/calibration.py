import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
import matplotlib.pyplot as plt


class Calibration(Node):
    def __init__(self):
        super().__init__('calibration')

        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value
        self.declare_parameter('threshold', 50)
        self.threshold = self.get_parameter('threshold').get_parameter_value().integer_value
        self.declare_parameter('point_distance_in_mm', 50)
        self.point_distance_in_mm = self.get_parameter('point_distance_in_mm').get_parameter_value().double_value

        self.subscription = self.create_subscription(Image, 'vision/actual_rgbd', self.rgbd_raw_callback, 10)

        self.bridge = CvBridge()
        self.actual_rgbd_raw = None
        self.actual_rgb = None
        self.actual_depth = None
        self.img_plane_coords = []

        ### Fenster für Koordinatenwerte und ratio-Ergebnis
        self.points_text_window_name = 'Black Points with Coordinates'
        self.ratio_window = 'ratio Pixels to mm'

        ### Kameraparameter (ausgelesen aus RealSense Console)
        self.cx = 422.081146240234 # Mittelpunkt in x (in Pixeln)
        self.cy = 243.28205871582  # Mittelpunkt in y (in Pixeln)
        self.fx = None
        self.fy = None
        self.mm_per_pixel = None
        self.pixel_per_mm = None



    def rgbd_raw_callback(self, msg):
        try:
            self.get_logger().info("RGBD Raw Bild empfangen!")
            self.actual_rgbd_raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

            if self.actual_rgbd_raw is not None:
                self.split_rgbd_tensor()
                self.img_plane_coords = self.find_black_points()

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")



    def split_rgbd_tensor(self):
        self.actual_rgb = self.actual_rgbd_raw[:, :, 0:3]   # RGB
        self.actual_depth = self.actual_rgbd_raw[:, :, 3]   # Tiefe
        self.actual_rgb = np.asarray(self.actual_rgb, dtype = np.uint8)
        self.actual_depth = np.asarray(self.actual_depth, dtype = np.uint16)



    def calc_cam_to_real_point(self, point=(0, 0, 0)):
        u, v, w = point
        X = (u - self.cx) * self.mm_per_pixel
        Y = (v - self.cy) * self.mm_per_pixel
        '''
        if w != 0:
            X = (u - self.cx) * w / self.fx
            Y = (v - self.cy) * w / self.fy
        '''
        return (X, Y, w)
    


    def find_black_points(self):
        try:
            gray = cv2.cvtColor(self.actual_rgb, cv2.COLOR_BGR2GRAY)
            _, mask = cv2.threshold(gray, self.threshold, 255, cv2.THRESH_BINARY_INV)
            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            points = []
            rgb_with_contours = self.actual_rgb.copy()

            points_text = ''
            ratio_text = ''

            for contour in contours:
                M = cv2.moments(contour)
                if M['m00'] != 0:
                    cx_img = int(M['m10'] / M['m00'])
                    cy_img = int(M['m01'] / M['m00'])
                    Z = self.actual_depth[cy_img, cx_img] 

                    points.append((cx_img, cy_img, Z))
                    self.get_logger().info(f"3D Punkt: X={cx_img}, Y={cy_img}, Z={Z}")
                    points_text += f"[pixels] X: {cx_img:.2f} mm Y: {cy_img:.2f} mm Z: {Z:.2f} mm;"

                    cv2.drawMarker(self.actual_rgb, (cx_img, cy_img), (0, 0, 255), cv2.MARKER_CROSS, 10, 2)

            # Darstellung der Bilder mit Konturen bzw. gefundenen Punkten
            if points:
                self.visualize_rgb(self.actual_rgb, title='RGB with detected Points')
            else:
                self.get_logger().info("Keine schwarzen Punkte gefunden.")

            # Aufruf Calibration, sobald genau 2 Punkte vorliegen
            if len(points) == 2:
                self.calc_pixel_mm_ratio(point_1=points[0], point_2=points[1])

                ratio_text += f"[Calibration RESULT] mm_per_pixel: {self.mm_per_pixel:.4f}; [Calibration RESLUT] pixel_per_mm: {self.pixel_per_mm:.4f}; ; "

                p1_real = self.calc_cam_to_real_point(points[0])
                p2_real = self.calc_cam_to_real_point(points[1])

                self.get_logger().info(f"Kontrolle - Punkt 1 bei x: {p1_real[0]} y: {p1_real[1]} z: {p1_real[2]}")
                self.get_logger().info(f"Kontrolle - Punkt 2 bei x: {p2_real[0]} y: {p2_real[1]} z: {p2_real[2]}")
                points_text += f"[Point 1 in mm] X: {p1_real[0]:.2f} mm Y: {p1_real[1]:.2f} mm Z: {p1_real[2]:.2f} mm;"
                points_text += f"[Point 2 in mm] X: {p2_real[0]:.2f} mm Y: {p2_real[1]:.2f} mm Z: {p2_real[2]:.2f} mm;"

                self.calc_focal_lengths(points[0], points[1])
                ratio_text += f"[FOCAL LENGTHS] fx: {self.fx:.4f} fy: {self.fy:.4f}; "
                self.show_ratio(ratio_text)
            else:
                self.get_logger().warn("Weniger als zwei Punkte gefunden. Kalibrierung kann nicht durchgeführt werden.")

            self.img_plane_coords = points
            self.show_point_coordinates(points_text)

            return points

        except Exception as e:
            self.get_logger().error(f"Fehler in find_black_points: {e}")
            return []
    


    def show_point_coordinates(self, points_text):
        points_img = np.zeros((480, 640, 3), dtype=np.uint8)
        lines = points_text.split(";")
        y_offset = 30

        for line in lines:
            cv2.putText(points_img, line, (10, y_offset), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1, cv2.LINE_AA)
            y_offset += 20
        
        cv2.imshow(self.points_text_window_name, points_img)
        cv2.waitKey(1)


    
    def show_ratio(self, ratio_text):
        ratio_img = np.zeros((480, 640, 3), dtype=np.uint8)
        lines = ratio_text.split("; ")
        y_offset = 30

        for line in lines:
            cv2.putText(ratio_img, line, (10, y_offset), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1, cv2.LINE_AA)
            y_offset += 20

        cv2.imshow(self.ratio_window, ratio_img)
        cv2.waitKey(1)



    def visualize_rgb(self, rgb, title='RGB'):
        if self.show_img:
            center_x = int(self.cx)
            center_y = int(self.cy)
            cv2.drawMarker(rgb, (center_x, center_y), (200, 200, 200), cv2.MARKER_CROSS, 80, 1)
            cv2.imshow(title, rgb)
            cv2.waitKey(1)
    


    def calc_pixel_mm_ratio(self, point_1, point_2):
        dist_px = np.sqrt((point_2[1] - point_1[1])**2 + (point_2[0] - point_1[0])**2)

        self.mm_per_pixel = self.point_distance_in_mm / dist_px
        self.pixel_per_mm = 1 / self.mm_per_pixel

        self.get_logger().info(f"Verhaeltnis mm pro Pixel: {self.mm_per_pixel}")
        self.get_logger().info(f"Verhaeltnis Pixel pro mm: {self.pixel_per_mm}")



    def calc_focal_lengths(self, point_1, point_2, point_3):
        u_1, v_1, w_1 = point_1
        u_2, v_2, w_2 = point_2
        u_3, v_3, w_3 = point_3

        Z_mean = (w_1 + w_2 + w_3) / 3

        points = [(u_1, v_1), (u_2, v_2), (u_3, v_3)]
        points = sorted(points, key=lambda p: (p[0], p[1]))
        upper_left = points[0]
        lower_left = min(points[1:], key=lambda p: p[0])
        lower_right = max(points[1:], key=lambda p: p[0])
        line_1 = [lower_left, upper_left]
        line_2 = [lower_left, lower_right]

        dx_px = abs(lower_right[0] - lower_left[0])         # fuer Brennweite fy
        dy_px = abs(upper_left[1] - lower_left[1])          # fuer Brennweite fx

        if self.point_distance_in_mm == 0:
            self.get_logger().error("Der Punktabstand in mm darf nicht null sein.")
            return
        
        self.fx = dx_px * Z_mean / self.point_distance_in_mm
        self.fy = dy_px * Z_mean / self.point_distance_in_mm
    
        self.get_logger().info(f"Berechnete Brennweite fx: {self.fx:.4f} Pixel")
        self.get_logger().info(f"Berechnete Brennweite fy: {self.fy:.4f} Pixel")



def main(args=None):
    rclpy.init(args=args)
    node = Calibration()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


