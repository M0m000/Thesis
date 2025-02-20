import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2


class TestNode(Node):
    def __init__(self):
        super().__init__('test_node')

        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value
        self.declare_parameter('threshold', 50)
        self.threshold = self.get_parameter('threshold').get_parameter_value().integer_value

        self.color_subscription = self.create_subscription(
            Image, '/vision/actual_rgbd',
            self.rgbd_callback, 10
        )

        self.color_subscription = self.create_subscription(
            Image, '/vision/actual_rgbd_norm',
            self.rgbd_norm_callback, 10
        )

        self.bridge = CvBridge()
        self.actual_rgbd_raw = None
        self.actual_rgbd_norm = None        

    def rgbd_callback(self, msg):
        try:
            self.get_logger().info("RGBD-Raw Bild empfangen!")
            self.actual_rgbd_raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            self.get_logger().info(f"{self.actual_rgbd_raw.shape}")
            # self.get_logger().info(f"{self.actual_rgbd_raw}")
        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")

    def rgbd_norm_callback(self, msg):
        try:
            self.get_logger().info("RGBD-Normalized Bild empfangen!")
            self.actual_rgbd_norm = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            # self.get_logger().info(f"{self.actual_rgbd_norm}")
        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")

    
    def visualize_rgb(self, rgb, title='RGB'):
        if self.show_img:
            cv2.imshow(title, rgb)
            cv2.waitKey(1)



def main(args=None):
    rclpy.init(args=args)
    node = TestNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
