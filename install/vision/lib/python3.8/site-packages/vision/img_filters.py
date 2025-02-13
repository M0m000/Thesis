import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2


class ImageFilters(Node):
    def __init__(self):
        super().__init__('img_filters')

        # Subscriber für das RGBD-Bild
        self.subscription = self.create_subscription(Image, 'vision/actual_rgbd', self.callback, 10)

        # Parameter zum Anzeigen der Bilder
        self.declare_parameter('show_img', False)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value

        # Parameter zum Aktivieren des Sobel-Filters
        self.declare_parameter('use_sobel', False)
        self.use_sobel = self.get_parameter('use_sobel').get_parameter_value().bool_value

        # Publisher für das Ergebnisbild
        self.sobel_publisher = self.create_publisher(Image, '/vision/camera_1/sobel_img', 10)

        # Pfad zur Referenzkontur
        self.reference_contour_path = "/home/vboxuser/ros2_ws/src/vision/vision/reference_img.png"
        self.reference_contour = self.load_reference_contour()

        self.bridge = CvBridge()
        self.actual_rgb = None
        self.actual_depth = None

    def callback(self, msg):
        try:
            self.get_logger().info("RGBD Raw Bild empfangen!")
            self.actual_rgbd_raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

            if self.actual_rgbd_raw is not None:
                self.split_rgbd_tensor()
                if self.show_img:
                    self.visualize_rgb(self.actual_rgb, title='RGB')

                ### Sobel
                if self.use_sobel:
                    sobel_img = self.filter_sobel(self.actual_rgb)
                    if self.show_img:
                        self.visualize_rgb(sobel_img, title='Sobel Filter Ergebnis')

                    # Konturen finden und Referenzkonturen im Bild suchen
                    contours = self.find_contours(sobel_img)
                    matched_contours = self.match_reference_contour(contours)
                    self.draw_matched_contours(matched_contours, self.actual_rgb)

                    # Das Ergebnisbild veröffentlichen
                    # self.publish_result_image(self.actual_rgb)

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")

    def split_rgbd_tensor(self):
        self.actual_rgb = self.actual_rgbd_raw[:, :, 0:3]   # RGB
        self.actual_depth = self.actual_rgbd_raw[:, :, 3]   # Tiefe
        self.actual_rgb = np.asarray(self.actual_rgb, dtype = np.uint8)
        self.actual_depth = np.asarray(self.actual_depth, dtype = np.uint16)

    def visualize_rgb(self, img, title):
        cv2.imshow(title, img)  # Verwende OpenCV, um das Bild anzuzeigen
        cv2.waitKey(1)  # Aktualisiere das Fenster

    def filter_sobel(self, image):
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        grad_x = cv2.Sobel(gray_image, cv2.CV_64F, 1, 0, ksize=3)  # Sobel in x-Richtung
        grad_y = cv2.Sobel(gray_image, cv2.CV_64F, 0, 1, ksize=3)  # Sobel in y-Richtung

        magnitude = cv2.magnitude(grad_x, grad_y)

        magnitude = np.uint8(np.clip(magnitude, 0, 255))

        return magnitude

    def load_reference_contour(self):
        ref_image = cv2.imread(self.reference_contour_path, cv2.IMREAD_COLOR)
        ref_sobel = self.filter_sobel(ref_image)
        if self.show_img:
            self.visualize_rgb(ref_image, title='Reference Contour RGB')
            cv2.imshow('Sobel Reference', ref_sobel)  # Verwende OpenCV für die Anzeige
            cv2.waitKey(1)

        _, ref_binary = cv2.threshold(ref_sobel, 127, 255, cv2.THRESH_BINARY)
        contours, _ = cv2.findContours(ref_binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        if contours:
            # Alle Konturen auf dem Referenzbild einzeichnen
            cv2.drawContours(ref_image, contours[4], -1, (255, 0, 0), 2)  # Zeichne alle Konturen in Blau
            if self.show_img:
                self.visualize_rgb(ref_image, title='Reference Contour with All Detected Contours')

            return contours[0]  # Nimm die größte (erste) Kontur als Referenz
        else:
            self.get_logger().error("Keine Konturen in der Referenz gefunden!")
            return None

    def find_contours(self, sobel_img):
        _, thresholded = cv2.threshold(sobel_img, 127, 255, cv2.THRESH_BINARY)
        contours, _ = cv2.findContours(thresholded, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        return contours

    def match_reference_contour(self, contours):
        matched_contours = []
        for contour in contours:
            similarity = cv2.matchShapes(self.reference_contour, contour, cv2.CONTOURS_MATCH_I1, 0.0)
            if similarity < 0.2:  # Wenn die Form ähnlich genug ist (Schwellenwert anpassen)
                matched_contours.append(contour)
        return matched_contours

    def draw_matched_contours(self, matched_contours, img):
        cv2.drawContours(img, matched_contours, -1, (0, 255, 0), 3)  # Zeichne mit grüner Farbe

    def publish_result_image(self, img):
        img_msg = self.bridge.cv2_to_imgmsg(img, encoding="bgr8")
        self.sobel_publisher.publish(img_msg)


def main(args=None):
    rclpy.init(args=args)
    image_filters_node = ImageFilters()

    try:
        rclpy.spin(image_filters_node)
    except KeyboardInterrupt:
        pass
    finally:
        image_filters_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
