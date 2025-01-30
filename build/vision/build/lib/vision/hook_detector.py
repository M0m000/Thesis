import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class HookDetector(Node):
    def __init__(self):
        super().__init__('hook_detector')
        self.get_logger().info('Hook Detector Node gestartet.')
        
        # Subscriber Bild
        self.subscription = self.create_subscription(
            Image,
            'vcnanoz/img_raw',
            self.image_callback,
            10)
        
        self.bridge = CvBridge()
        
        # Init OpenCV-Fenster
        cv2.namedWindow("Hook Detection", cv2.WINDOW_NORMAL)
    


    def image_callback(self, msg):
        # Konvertiere ROS2-Bild in ein OpenCV-Format (Graustufenbild)
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        except Exception as e:
            self.get_logger().error(f"Fehler bei der Bildkonvertierung: {e}")
            return
        
        processed_image = self.detect_hooks(frame)
        
        # Zeige Ergebnis in OpenCV-Fenster
        cv2.imshow("Hook Detection", processed_image)
        cv2.waitKey(1)
    


    def detect_hooks(self, frame):
        """
        Diese Methode verarbeitet das Bild, um die Haken zu erkennen.
        - Graustufen-Umwandlung
        - Glättung
        - Kanten- und Konturenerkennung
        """
        # Graustufen-Bild
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        
        # Gaussfilter
        blurred = cv2.GaussianBlur(gray, (5, 5), 0)
        
        # Kanten erkennen (Canny)
        edges = cv2.Canny(blurred, 50, 150)
        
        # Konturen finden
        contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        
        # Kopie des Originalbildes zur Visualisierung
        output_image = frame.copy()
        
        # Zeichne gefundene Konturen
        for contour in contours:
            if cv2.contourArea(contour) > 100:  # Mindestgröße der Kontur -> Rauschen aussortieren
                # Berechne Bounding Box
                x, y, w, h = cv2.boundingRect(contour)
                
                # Zeichne Rechteck auf Visualisierung
                cv2.rectangle(output_image, (x, y), (x+w, y+h), (0, 255, 0), 2)

        return output_image



def main(args=None):
    rclpy.init(args=args)
    node = HookDetector()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Knoten wurde beendet.')
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()

