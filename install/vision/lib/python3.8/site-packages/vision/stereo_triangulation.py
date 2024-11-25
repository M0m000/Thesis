import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
import matplotlib.pyplot as plt



class StereoTriangulation(Node):
    def __init__(self):
        super().__init__('stereo_triangulation')

        # Abonnieren der Kamera 1
        self.subscription1 = self.create_subscription(Image, 'vision/camera_1/point_mask_rgbd', self.cam_1_callback, 10)

        self.bridge = CvBridge()

        # Kamera 1 Parameter
        self.cam_1_fx = 619.3136
        self.cam_1_fy = 620.4985
        self.cam_1_cx = 318.262176513672
        self.cam_1_cy = 242.990539550781
        self.cam_1_intrinsic_matrix = [[self.cam_1_fx, 0, self.cam_1_cx],
                                       [0, self.cam_1_fy, self.cam_1_cy],
                                       [0, 0, 1]]

        # Kamera 2 Parameter
        self.cam_2_fx = 619.3136
        self.cam_2_fy = 620.4985
        self.cam_2_cx = 318.262176513672
        self.cam_2_cy = 242.990539550781
        self.cam_2_intrinsic_matrix = [[self.cam_2_fx, 0, self.cam_2_cx],
                                       [0, self.cam_2_fy, self.cam_2_cy],
                                       [0, 0, 1]]

        # Punktmasken und Tiefenbilder
        self.cam_1_depth = None
        self.cam_1_point_mask = None
        self.cam_1_img_coords = []
        self.cam_1_real_coords = []
        self.cam_2_depth = None
        self.cam_2_point_mask = None
        self.cam_2_img_coords = []
        self.cam_2_real_coords = []

    def cam_1_callback(self, msg):
        try:
            self.get_logger().info(f"Kamera 1 Punkte empfangen!")
            mask = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

            if mask is not None:
                self.cam_1_point_mask = mask[:, :, 0]
                self.cam_1_depth = mask[:, :, 1]
                self.cam_1_img_coords = self.process_mask(point_mask=self.cam_1_point_mask, depth=self.cam_1_depth, cam_name='Kamera 1')

                self.cam_1_real_coords = []
                for point in self.cam_1_img_coords:
                    Z = self.cam_1_depth[point[0]][point[1]]
                    if Z != 0:
                        real_coords = self.calc_cam_to_real_point(point=(point[0], point[1], Z), cam=1)
                        self.cam_1_real_coords.append(real_coords)
                        ### Weiterverarbeitung der Punkte
                self.visualize_points()
            else:
                self.get_logger().warning(f"Fehler bei Empfang des Bildes von Kamera 1!")
        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")
    
    def cam_2_callback(self, msg):
        try:
            self.get_logger().info(f"Kamera 2 Punkte empfangen!")
            mask = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            
            if mask is not None:
                self.cam_2_point_mask = mask[:, :, 0]
                self.cam_2_depth = mask[:, :, 1]
                self.cam_2_img_coords = self.process_mask(point_mask=self.cam_2_point_mask, depth=self.cam_2_depth, cam_name='Kamera 2')

                self.cam_2_real_coords = []
                for point in self.cam_2_img_coords:
                    Z = self.cam_2_depth[point[0]][point[1]]
                    if Z != 0:
                        real_coords = self.calc_cam_to_real_point(point=(point[0], point[1], Z), cam=2)
                        self.cam_2_real_coords.append(real_coords)
                        ### Weiterverarbeitung der Punkte

            else:
                self.get_logger().warning(f"Fehler bei Empfang des Bildes von Kamera 1!")
        except Exception as e:
            self.get_logger().error(f"Fehler bei der Verarbeitung des RGB-Bildes: {e}")

    def process_mask(self, point_mask, depth, cam_name):
        if point_mask is not None and depth is not None:
            indices = np.where(point_mask == True)
            img_coords = list(zip(indices[0], indices[1]))
            self.get_logger().info(f"Verarbeite Masken für {cam_name}, Anzahl der Punkte: {len(img_coords)}")
            return img_coords

    def calc_cam_to_real_point(self, point=(0, 0, 0), cam=1):
        u, v, Z = point

        if cam == 1:
            K_inv = np.linalg.inv(self.cam_1_intrinsic_matrix)
        else:
            K_inv = np.linalg.inv(self.cam_2_intrinsic_matrix)

        p = np.array([[u * Z], [v * Z], [Z]])
        real_coords = np.dot(K_inv, p)

        return (real_coords[0][0], real_coords[1][0], real_coords[2][0])

    def visualize_points(self):
        try:
            height, width = self.cam_1_point_mask.shape
            black_img = np.zeros((height, width, 3), dtype=np.uint8)

            for point in self.cam_1_img_coords:
                cx, cy = point
                cv2.drawMarker(black_img, (cy, cx), (0, 0, 255), cv2.MARKER_CROSS, 10, 2)

            cv2.imshow("Punkte auf schwarzem Hintergrund", black_img)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Visualisierung der Punkte: {e}")




def main(args=None):
    rclpy.init(args=args)
    stereo_triangulation = StereoTriangulation()

    try:
        rclpy.spin(stereo_triangulation)
    except KeyboardInterrupt:
        pass
    finally:
        stereo_triangulation.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
