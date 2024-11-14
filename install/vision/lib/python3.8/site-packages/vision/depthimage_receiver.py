import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2

class ImageReceiver(Node):
    def __init__(self, max_depth=500):
        super().__init__('image_receiver')

        self.declare_parameter('max_depth', 500)  # Standard 50cm als Cutoff im Tiefenbild
        self.max_depth = self.get_parameter('max_depth').get_parameter_value().integer_value
        self.get_logger().info(f"Maximale Tiefe für Filterung: {self.max_depth} mm")

        self.depth_subscription = self.create_subscription(
            Image,
            '/camera/camera/aligned_depth_to_color/image_raw',
            self.depth_callback,
            10
        )

        self.color_subscription = self.create_subscription(
            Image,
            '/camera/camera/color/image_raw',
            self.color_callback,
            10
        )

        self.bridge = CvBridge()
        self.depth_image = None
        self.color_image = None



    def depth_callback(self, msg):
        try:
            cv_depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            mask_zeros = cv_depth_image == 0

            min_value = cv_depth_image.min()
            max_value = cv_depth_image.max()
            if max_value > min_value:
                cv_depth_image_normalized = ((cv_depth_image - min_value) / (max_value - min_value)) * 255
            else:
                cv_depth_image_normalized = np.zeros_like(cv_depth_image, dtype=np.float32)

            cv_depth_image_normalized = np.uint8(np.round(cv_depth_image_normalized))

            depth_colormap = cv2.applyColorMap(cv_depth_image_normalized, cv2.COLORMAP_JET)
            depth_colormap[mask_zeros] = [0, 0, 0]
            cv2.imshow("Depth Image", depth_colormap)



            cv_depth_cutout = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            cv_depth_cutout = cv_depth_cutout[np.where(cv_depth_cutout >= self.max_depth)] = 0
            mask_depth = cv_depth_cutout == 0

            min_cutout_value = cv_depth_cutout.min()
            max_cutout_value = cv_depth_cutout.max()
            if max_cutout_value > min_cutout_value:
                cv_depth_cutout_normalized = ((cv_depth_cutout - min_cutout_value) / (max_cutout_value - min_cutout_value)) * 255
            else:
                cv_depth_cutout_normalized = np.zeros_like(cv_depth_cutout, dtype=np.float32)

            depth_cutout_colormap = cv2.applyColorMap(cv_depth_cutout_normalized, cv2.COLORMAP_JET)
            depth_cutout_colormap[mask_zeros] = [0, 0, 0]
            cv2.imshow("Cutout Depth Image", depth_cutout_colormap)



            self.depth_image = cv_depth_image
            self.get_logger().info(f"Tiefenbild empfangen: {cv_depth_image.shape[0]}x{cv_depth_image.shape[1]}")

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des Tiefenbildes: {e}")



    def color_callback(self, msg):
        try:
            cv_color_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

            cv2.imshow("Color Image", cv_color_image)
            cv2.waitKey(1)

            self.color_image = cv_color_image
            height, width, channels = self.color_image.shape
            self.get_logger().info(f"RGB-Bild empfangen: {height}x{width} mit {channels} Kanälen")

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")



def main(args=None):
    rclpy.init(args=args)

    max_depth = 100
    node = ImageReceiver(max_depth=max_depth)

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
