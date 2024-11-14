import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2



class ImageProcessor(Node):
    def __init__(self, max_depth=500):
        super().__init__('image_processor')

        self.declare_parameter('max_depth', 500)
        self.max_depth = self.get_parameter('max_depth').get_parameter_value().integer_value
        self.get_logger().info(f"Maximale Tiefe für Filterung: {self.max_depth} mm")

        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value

        self.depth_subscription = self.create_subscription(Image, '/processed/depth/image', self.img_callback, 10)
        self.color_subscription = self.create_subscription(Image, '/processed/color/image', self.img_callback, 10)

        self.bridge = CvBridge()
        self.actual_rgb_img = None
        self.actual_depth_img = None
        self.actual_depth_cutout = None
        self.actual_rgbd_img = None


    def img_callback(self, msg):
        try:
            self.get_logger().info("Bild empfangen")
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

            if msg.encoding == 'mono8' or msg.encoding == 'passthrough':
                # self.get_logger().info(f"Tiefenbild empfangen: {cv_image.shape}")
                self.actual_depth_img = cv_image

            elif msg.encoding == 'bgr8':
                # self.get_logger().info(f"RGB-Bild empfangen: {cv_image.shape}")
                self.actual_rgb_img = cv_image


            if self.actual_rgb_img is not None and self.actual_depth_img is not None:
                # self.get_logger().info("Erzeuge RGBD")
                h, w, _ = self.actual_rgb_img.shape
                rgbd = np.zeros((h, w, 4), dtype = np.uint8)
                rgbd[:, :, 0] = self.actual_rgb_img[:, :, 0]    # R
                rgbd[:, :, 1] = self.actual_rgb_img[:, :, 1]    # G
                rgbd[:, :, 2] = self.actual_rgb_img[:, :, 2]    # B
                rgbd[:, :, 3] = self.actual_depth_img

                self.actual_rgbd_img = rgbd
                self.image_show(self.actual_rgb_img, window_name="RGB Image")
                self.image_show(self.actual_depth_img, window_name='Depth Image')

                self.process_img()
                
        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung der Bilder: {e}")



    def image_show(self, img, window_name="Image"):
        if self.show_img:
            cv2.imshow(window_name, img)
            cv2.waitKey(1)



    def process_img(self):
        self.depth_cutout()
        # self.canny_rgb(self.actual_rgb_img)
        # self.canny_depth(self.actual_depth_img)



    def depth_cutout(self):
        rgbd = self.actual_rgbd_img
        print(rgbd[:, :, 3])
        mask = rgbd[:, :, 3] >= self.max_depth
        num_true = np.sum(mask)

        rgbd[mask] = 0
        self.image_show(rgbd[:, :, 0:3], window_name='RGB Image Cutout')
    
    
    
    def canny_rgb(self, canny_rgb_thresholds=[220, 240]):
        gray = cv2.cvtColor(self.actual_rgb_img, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, canny_rgb_thresholds[0], canny_rgb_thresholds[1])
        self.image_show(edges, window_name="RGB Canny Edges")

    def canny_depth(self, canny_depth_thresholds=[100, 200]):
        edges = cv2.Canny(self.actual_depth_img, canny_depth_thresholds[0], canny_depth_thresholds[1])
        self.image_show(edges, window_name="Depth Canny Edges")




def main(args=None):
    rclpy.init(args=args)

    node = ImageProcessor()

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
