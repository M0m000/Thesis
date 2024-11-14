import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2


class PointFinder(Node):
    def __init__(self):
        super().__init__('point_finder')

        # Parameter deklarieren
        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value
        self.declare_parameter('threshold', 50)  # Standard-Schwellenwert auf 50 gesetzt
        self.threshold = self.get_parameter('threshold').get_parameter_value().integer_value

        # Abonnement nur für das RGB-Bild
        self.color_subscription = self.create_subscription(
            Image, '/camera/camera/color/image_raw',
            self.img_callback, 10
        )

        self.bridge = CvBridge()
        self.actual_rgb = None
        self.img_plane_coords = []  # Liste zur Speicherung der Koordinaten mehrerer Punkte

    def img_callback(self, msg):
        try:
            self.get_logger().info("RGB-Bild empfangen!")
            # Konvertiere ROS-Bildnachricht zu OpenCV-Bild
            self.actual_rgb = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            self.visualize_rgb(self.actual_rgb, title='RGB')

            # Suche nach schwarzen Punkten
            if self.actual_rgb is not None:
                self.get_logger().info("Suche nach schwarzen Punkten beginnt")
                self.img_plane_coords = self.find_black_points()

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")

    def find_black_points(self):
        try:
            # Konvertiere RGB-Bild in Graustufen
            gray = cv2.cvtColor(self.actual_rgb, cv2.COLOR_BGR2GRAY)

            # Erstelle eine binäre Maske basierend auf dem Schwellenwert
            _, mask = cv2.threshold(gray, self.threshold, 255, cv2.THRESH_BINARY_INV)

            # Finde Konturen im maskierten Bild
            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            # Liste zur Speicherung der gefundenen Punkte
            points = []

            # Durchlaufe alle gefundenen Konturen
            for contour in contours:
                M = cv2.moments(contour)
                if M['m00'] != 0:
                    cx = int(M['m10'] / M['m00'])
                    cy = int(M['m01'] / M['m00'])
                    
                    # Speichere die Koordinaten des gefundenen Punktes
                    points.append((cx, cy))
                    self.get_logger().info(f"Schwarzer Punkt gefunden: x={cx}, y={cy}")

                    # Markiere den gefundenen Punkt auf dem RGB-Bild
                    cv2.drawMarker(self.actual_rgb, (cx, cy), (0, 0, 255), cv2.MARKER_CROSS, 10, 2)

            # Speichere die gefundenen Punkte
            self.img_plane_coords = points

            # Zeige das Bild mit markierten Punkten an
            if points:
                self.visualize_rgb(self.actual_rgb, title='RGB with detected Points')
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

    node = PointFinder()

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
