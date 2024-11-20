import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2


class ImageReceiver(Node):
    def __init__(self, max_depth=500):
        super().__init__('image_receiver')

        self.declare_parameter('max_depth', 500)
        self.max_depth = self.get_parameter('max_depth').get_parameter_value().integer_value
        self.get_logger().info(f"Maximale Tiefe für Filterung: {self.max_depth} mm")

        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value

        self.depth_subscription = self.create_subscription(
            Image, '/camera/camera/aligned_depth_to_color/image_raw',
            lambda msg: self.img_callback(msg, 'depth'), 10
        )
        self.color_subscription = self.create_subscription(
            Image, '/camera/camera/color/image_raw',
            lambda msg: self.img_callback(msg, 'color'), 10
        )

        self.publisher_rgbd = self.create_publisher(Image, 'vision/actual_rgbd', 10)
        self.publisher_rgbd_norm = self.create_publisher(Image, 'vision/actual_rgbd_norm', 10)
        
        self.bridge = CvBridge()

        self.actual_rgb = None
        self.actual_depth_raw = None
        self.actual_depthcut_raw = None
        self.actual_depth_norm = None
        self.actual_depthcut_norm = None
        self.actual_rgbd_raw = None
        self.actual_rgbd_raw_norm = None

    def img_callback(self, msg, image_type):
        try:
            if image_type == 'depth':
                self.get_logger().info("Tiefenbild empfangen!")

                depth_raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
                self.actual_depth_raw = depth_raw

                depth_norm = self.normalize_depth_to_rgb(depth_raw)
                self.actual_depth_norm = depth_norm

                self.visualize_depth(depth_norm, title='Depth')

            elif image_type == 'color':
                self.get_logger().info(f"RGB-Bild empfangen!")

                rgb_raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
                self.actual_rgb = rgb_raw

                self.visualize_rgb(rgb_raw, title='RGB')

            if self.actual_rgb is not None and self.actual_depth_raw is not None:
                self.create_rgbd_tensor()
                self.process_img()

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des Bildes: {e}")

    def visualize_depth(self, depth_normalized, title='Depth'):
        if self.show_img:
            cv2.imshow(title, depth_normalized)
            cv2.waitKey(1)

    def visualize_rgb(self, rgb, title='RGB'):
        if self.show_img:
            cv2.imshow(title, rgb)
            cv2.waitKey(1)

    def normalize_depth_to_rgb(self, depth_raw):
        mask_zeros = depth_raw == 0

        min_value = depth_raw.min()
        max_value = depth_raw.max()

        if max_value > min_value:
            cv_depth_image_normalized = ((depth_raw - min_value) / (max_value - min_value)) * 255
        else:
            cv_depth_image_normalized = np.zeros_like(depth_raw, dtype=np.float32)

        cv_depth_image_normalized = np.uint8(np.round(cv_depth_image_normalized))

        depth_colormap = cv2.applyColorMap(cv_depth_image_normalized, cv2.COLORMAP_JET)
        depth_colormap[mask_zeros] = [0, 0, 0]

        return depth_colormap

    def process_img(self):
        ##### Ausschneiden des relevanten Tiefenbereich #####
        depth_cut_raw = self.depth_cutout()
        depth_cut_norm = self.normalize_depth_to_rgb(depth_cut_raw)

        self.actual_depthcut_raw = depth_cut_raw
        self.actual_depthcut_norm = depth_cut_norm
        self.visualize_depth(depth_cut_norm, title='Depth Cutout')

    def depth_cutout(self):
        d = self.actual_depth_raw
        d[np.where(d >= self.max_depth)] = 0
        return d

    def create_rgbd_tensor(self):
        # Hier wird der RGBD-Tensor mit uint16 für die Tiefenschicht erstellt
        rgbd_raw = np.zeros((self.actual_rgb.shape[0], self.actual_rgb.shape[1], (self.actual_rgb.shape[2] + 1)), dtype=np.uint16)
        rgbd_norm = np.ones((self.actual_rgb.shape[0], self.actual_rgb.shape[1], (self.actual_rgb.shape[2] + self.actual_depth_norm.shape[2])), dtype=np.uint8)

        rgbd_raw[:, :, 0:3] = self.actual_rgb
        rgbd_raw[:, :, 3] = self.actual_depth_raw.astype(np.uint16)  # Tiefenwerte als uint16 speichern
        rgbd_norm[:, :, 0:3] = self.actual_rgb
        rgbd_norm[:, :, 3:6] = self.actual_depth_norm

        self.actual_rgbd_raw = rgbd_raw
        self.actual_rgbd_norm = rgbd_norm

        msg_rgbd_raw = self.bridge.cv2_to_imgmsg(self.actual_rgbd_raw, encoding="passthrough")
        self.publisher_rgbd.publish(msg_rgbd_raw)
        self.get_logger().info('Actual RGBD Raw Image published via /vision/actual_rgbd')

        msg_rgbd_norm = self.bridge.cv2_to_imgmsg(self.actual_rgbd_norm, encoding="passthrough")
        self.publisher_rgbd_norm.publish(msg_rgbd_norm)
        self.get_logger().info('Actual RGBD Normalized Image published via /vision/actual_rgbd_norm')



def main(args=None):
    rclpy.init(args=args)

    node = ImageReceiver()

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
