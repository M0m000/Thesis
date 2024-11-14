import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2


class PointFinder2D(Node):
    def __init__(self):
        super().__init__('point_finder_2d')
        
        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value
        self.declare_parameter('threshold', 50)
        self.threshold = self.get_parameter('threshold').get_parameter_value().integer_value

        self.subscription = self.create_subscription(Image, 'vision/actual_rgbd', self.rgbd_raw_callback, 10)

        self.bridge = CvBridge()
        self.actual_rgbd_raw = None
        self.actual_rgb = None
        self.actual_depth = None
        self.img_plane_coords = []

    def rgbd_raw_callback(self, msg):
        try:
            self.get_logger().info("RGBD Raw Bild empfangen!")
            self.actual_rgbd_raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

            if self.actual_rgbd_raw is not None:
                self.split_rgbd_tensor()
                # self.visualize_rgb(self.actual_rgb, title = 'RGB')
                self.img_plane_coords = self.find_black_points()

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")


    def split_rgbd_tensor(self):
        self.actual_rgb = self.actual_rgbd_raw[:, :, 0:3]   # RGB
        self.actual_depth = self.actual_rgbd_raw[:, :, 3]   # Tiefe
        self.actual_rgb = np.asarray(self.actual_rgb, dtype = np.uint8)
        self.actual_depth = np.asarray(self.actual_depth, dtype = np.uint16)

    
    def find_black_points(self):
        try:
            gray = cv2.cvtColor(self.actual_rgb, cv2.COLOR_BGR2GRAY)
            _, mask = cv2.threshold(gray, self.threshold, 255, cv2.THRESH_BINARY_INV)
            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            points = []
            rgb_with_contours = self.actual_rgb.copy()

            for contour in contours:
                # Berechnung des Mittelpunkts über die Momente (Originalmethode)
                M = cv2.moments(contour)
                if M['m00'] != 0:
                    cx_moments = int(M['m10'] / M['m00'])
                    cy_moments = int(M['m01'] / M['m00'])
                    points.append((cx_moments, cy_moments))
                    self.get_logger().info(f"Momenten Mittelpunkt: x={cx_moments}, y={cy_moments}")

                    # Zeichne den Momenten-Mittelpunkt als rotes Kreuz auf rgb_with_contours
                    cv2.drawMarker(rgb_with_contours, (cx_moments, cy_moments), (0, 0, 255), cv2.MARKER_CROSS, 10, 2)

                # Berechnung des Mittelpunkts über das geometrische Mittel (Durchschnitt der Punkte)
                if len(contour) > 0:  # Wenn die Kontur aus mehr als einem Punkt besteht
                    contour_points = contour[:, 0, :]  # Extrahiere die x- und y-Koordinaten
                    cx_geo = np.mean(contour_points[:, 0])  # Durchschnitt der x-Koordinaten
                    cy_geo = np.mean(contour_points[:, 1])  # Durchschnitt der y-Koordinaten
                    points.append((int(cx_geo), int(cy_geo)))
                    self.get_logger().info(f"Geometrischer Mittelpunkt: x={int(cx_geo)}, y={int(cy_geo)}")

                    # Zeichne den geometrischen Mittelpunkt als weißes Kreuz auf rgb_with_contours
                    cv2.drawMarker(rgb_with_contours, (int(cx_geo), int(cy_geo)), (255, 255, 255), cv2.MARKER_CROSS, 10, 2)

                # Zeichne die Kontur auf rgb_with_contours
                cv2.drawContours(rgb_with_contours, [contour], -1, (255, 0, 0), 2)

            self.img_plane_coords = points

            if points:
                # Visualisiere das RGB-Bild mit den erkannten Punkten und beiden Mittelpunkten
                self.visualize_rgb(rgb_with_contours, title='RGB with detected Points and Centers')
            else:
                self.get_logger().info("Keine schwarzen Punkte gefunden.")

            return points

        except Exception as e:
            self.get_logger().error(f"Fehler in find_black_points: {e}")
            return []

    def visualize_rgb(self, rgb, title='RGB'):
        if self.show_img:
            cv2.imshow(title, rgb)
            cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = PointFinder2D()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
