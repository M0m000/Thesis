import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
import matplotlib.pyplot as plt

class PointFinder3D(Node):
    def __init__(self):
        super().__init__('point_finder_3d')

        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value
        self.declare_parameter('threshold', 50)
        self.threshold = self.get_parameter('threshold').get_parameter_value().integer_value
        self.declare_parameter('show_error_plot', False)
        self.show_error_plot = self.get_parameter('show_error_plot').get_parameter_value().bool_value

        self.subscription = self.create_subscription(Image, 'vision/actual_rgbd', self.rgbd_raw_callback, 10)

        self.bridge = CvBridge()
        self.actual_rgbd_raw = None
        self.actual_rgb = None
        self.actual_depth = None
        self.img_plane_coords = []
        
        self.errors = []
        self.fig, self.ax = plt.subplots()
        self.ax.set_xlabel('Punkte')
        self.ax.set_ylabel('Abweichung (mm)')
        self.ax.set_title('Abweichung zwischen Mean und Moment')
        plt.ion()
        plt.show()

        ### Fenster für Koordinatenwerte und Abweichungen
        self.points_text_window_name = 'Black Points with Coordinates'
        self.error_window_name = 'Current Errors'

        ### Kameraparameter
        self.fx = 619.3136              # Brennweite in x-Richtung (in Pixeln) - kann über Calibration Node ausgelesen werden
        self.fy = 620.4985              # Brennweite in y-Richtung (in Pixeln) - kann über Calibration Node ausgelesen werden
        self.cx = 318.262176513672      # Mittelpunkt in x (in Pixeln) - ausgelesen aus Realsense Console
        self.cy = 242.990539550781      # Mittelpunkt in y (in Pixeln) - ausgelesen aus Realsense Console

        # Füge eine Methode hinzu, um den Schwellenwert dynamisch anzupassen
        self.create_threshold_slider()

    def create_threshold_slider(self):
        cv2.namedWindow("Threshold Control")
        cv2.createTrackbar("Threshold", "Threshold Control", self.threshold, 255, self.update_threshold)

    def update_threshold(self, val):
        self.threshold = val
        self.get_logger().info(f"Threshold geändert: {self.threshold}")

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
        if w != 0:
            X = (u - self.cx) * w / self.fx
            Y = (v - self.cy) * w / self.fy
        return (X, Y, w)

    def find_black_points(self):
        try:
            gray = cv2.cvtColor(self.actual_rgb, cv2.COLOR_BGR2GRAY)
            _, mask = cv2.threshold(gray, self.threshold, 255, cv2.THRESH_BINARY_INV)

            if self.show_img:
                cv2.imshow("Threshold Mask", mask)

            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            points = []
            rgb_with_contours = self.actual_rgb.copy()
            rgb_with_geometric_points = self.actual_rgb.copy()

            points_text = ''
            error_text = ''

            for contour in contours:
                M = cv2.moments(contour)
                cx_img, cy_img = None, None
                if M['m00'] != 0:
                    cx_img = M['m10'] / M['m00']
                    cy_img = M['m01'] / M['m00']
                    
                    if cx_img is not None and cy_img is not None:
                        cx_img = int(cx_img)
                        cy_img = int(cy_img)
                        if 0 <= cx_img < self.actual_depth.shape[1] and 0 <= cy_img < self.actual_depth.shape[0]:
                            Z = self.actual_depth[cy_img, cx_img]
                            if Z > 0:
                                X, Y, Z = self.calc_cam_to_real_point((cx_img, cy_img, Z))
                                points.append((X, Y, Z))
                                points_text += f"[moments] X: {X:.2f} mm Y: {Y:.2f} mm Z: {Z:.2f} mm; "
                                cv2.drawMarker(self.actual_rgb, (cx_img, cy_img), (0, 0, 255), cv2.MARKER_CROSS, 10, 2)
            
                if len(contour) > 2:
                    contour_points = contour[:, 0, :]
                    cx_geo = np.mean(contour_points[:, 0])
                    cy_geo = np.mean(contour_points[:, 1])

                    if cx_geo is not None and cy_geo is not None:
                        cx_geo = int(cx_geo)
                        cy_geo = int(cy_geo)
                        if 0 <= cx_geo < self.actual_depth.shape[1] and 0 <= cy_geo < self.actual_depth.shape[0]:
                            Z_geo = self.actual_depth[cy_geo, cx_geo]
                            if Z_geo > 0:
                                X_geo, Y_geo, Z_geo = self.calc_cam_to_real_point((cx_geo, cy_geo, Z_geo))
                                points_text += f"[mean] X: {X_geo:.2f} mm Y: {Y_geo:.2f} mm Z: {Z_geo:.2f} mm; "
                                dist = np.sqrt((X - X_geo)**2 + (Y - Y_geo)**2 + (Z - Z_geo)**2)
                                self.errors.append(dist)
                                if self.show_error_plot:
                                    self.update_plot()
                                error_text += f"Abweichung: {dist:.4f} mm; "
                                cv2.drawMarker(rgb_with_geometric_points, (cx_geo, cy_geo), (255, 255, 255), cv2.MARKER_CROSS, 10, 2)

                cv2.drawContours(rgb_with_contours, [contour], -1, (255, 0, 0), 2)

            if Z > 0:
                self.img_plane_coords = points
                self.show_point_coordinates(points_text)
            if Z_geo > 0:
                self.show_current_error(error_text)

            if points:
                self.visualize_rgb(rgb_with_contours, 'RGB with Contours')
                self.visualize_rgb(self.actual_rgb, 'RGB with detected Points (moments)')
                self.visualize_rgb(rgb_with_geometric_points, 'RGB with detected Points (geometric mean)')
            
            return points

        except Exception as e:
            self.get_logger().error(f"Fehler in find_black_points: {e}")
            return []

    def show_point_coordinates(self, points_text):
        points_img = np.zeros((240, 800, 3), dtype=np.uint8)
        lines = points_text.split("; ")
        y_offset = 30

        for line in lines:
            cv2.putText(points_img, line, (10, y_offset), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1, cv2.LINE_AA)
            y_offset += 20
        
        cv2.imshow(self.points_text_window_name, points_img)
        cv2.waitKey(1)

    def update_plot(self):
        self.ax.clear()
        self.ax.set_xlabel('Punkte')
        self.ax.set_ylabel('Abweichung (mm)')
        self.ax.set_title('Abweichung zwischen Mean und Moment')

        self.ax.plot(range(len(self.errors)), self.errors, label='Abweichung', color='r')
        self.ax.legend()
        plt.pause(0.01)

    def show_current_error(self, error_text):
        error_img = np.zeros((240, 800, 3), dtype=np.uint8)
        lines = error_text.split("; ")
        y_offset = 30

        for line in lines:
            cv2.putText(error_img, line, (10, y_offset), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1, cv2.LINE_AA)
            y_offset += 20
        cv2.imshow(self.error_window_name, error_img)
        cv2.waitKey(1)

    def visualize_rgb(self, img, window_name):
        cv2.imshow(window_name, img)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    point_finder = PointFinder3D()

    try:
        rclpy.spin(point_finder)
    except KeyboardInterrupt:
        pass
    finally:
        point_finder.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
