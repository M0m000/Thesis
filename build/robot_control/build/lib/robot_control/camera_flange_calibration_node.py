import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from FC.FC_frame_handler import FrameHandler

class CameraFlangeCalibration(Node):
    def __init__(self):
        super().__init__('camera_flange_calibration_node')

        # Bild-Abo
        self.subscription = self.create_subscription(
            Image,
            'vcnanoz/image_raw',
            self.image_callback,
            10)
        self.bridge = CvBridge()
        self.latest_image = None

        # Checkerboard-Parameter
        self.checkerboard_size = (8, 6)    # Anzahl Innenpunkte (Ecken)
        self.square_size = 0.025           # Quadratgröße in Metern (25 mm)

        # Kalibrierdaten laden
        calib_data = np.load("/home/mo/Thesis/calibration_data.npz")
        self.K = calib_data["mtx"]
        self.dist_coeffs = calib_data["dist"]

        # Instanz Frame Handler
        self.frame_handler = FrameHandler()

        # Datenspeicher
        self.all_flange_poses = []  # (R, t)
        self.all_rvecs = []
        self.all_tvecs = []

        self.get_logger().info("Kamerakalibrierung geladen. Node bereit.")


    def image_callback(self, msg):
        self.latest_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')


    def run(self):
        while rclpy.ok():
            user_input = input("Drücke Enter zum Erfassen, 'q' zum Beenden: ")
            if user_input.strip().lower() == 'q':
                break

            if self.latest_image is None:
                self.get_logger().warn("Noch kein Bild empfangen.")
                continue

            # Checkerboard erkennen
            gray = cv2.cvtColor(self.latest_image, cv2.COLOR_BGR2GRAY)
            found, corners = cv2.findChessboardCorners(gray, self.checkerboard_size, None)

            if not found:
                self.get_logger().warn("Checkerboard nicht erkannt.")
                continue

            # 3D-Objektpunkte generieren
            objp = np.zeros((np.prod(self.checkerboard_size), 3), np.float32)
            objp[:, :2] = np.indices(self.checkerboard_size).T.reshape(-1, 2)
            objp *= self.square_size

            # Ecken verfeinern
            criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
            corners2 = cv2.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)

            # Pose mit solvePnP berechnen
            success, rvec, tvec = cv2.solvePnP(objp, corners2, self.K, self.dist_coeffs)
            if not success:
                self.get_logger().warn("solvePnP fehlgeschlagen.")
                continue

            # Roboterflanschpose abrufen
            pos, rpy = self.get_current_flange_pose()  # <- DU IMPLEMENTIERST DAS
            R_flange = self.rpy_to_matrix(rpy)

            # Speichern
            self.all_flange_poses.append((R_flange, np.array(pos)))
            self.all_rvecs.append(rvec)
            self.all_tvecs.append(tvec)

            self.get_logger().info("Messung gespeichert.")

        self.compute_hand_eye()

    def get_current_flange_pose(self):
        pos, rpy = self.frame_handler.get_system_frame(name = 'tfc', ref = 'world')
        self.get_logger().info(f"Flanschpose: pos={pos}, rpy={rpy}")
        return pos, rpy

    def rpy_to_matrix(self, rpy):
        roll, pitch, yaw = rpy
        Rx = np.array([[1, 0, 0],
                       [0, np.cos(roll), -np.sin(roll)],
                       [0, np.sin(roll),  np.cos(roll)]])
        Ry = np.array([[np.cos(pitch), 0, np.sin(pitch)],
                       [0, 1, 0],
                       [-np.sin(pitch), 0, np.cos(pitch)]])
        Rz = np.array([[np.cos(yaw), -np.sin(yaw), 0],
                       [np.sin(yaw),  np.cos(yaw), 0],
                       [0, 0, 1]])
        return Rz @ Ry @ Rx

    def compute_hand_eye(self):
        R_gripper2base = [R for R, t in self.all_flange_poses]
        t_gripper2base = [t for R, t in self.all_flange_poses]

        R_target2cam = []
        t_target2cam = []

        for rvec, tvec in zip(self.all_rvecs, self.all_tvecs):
            R, _ = cv2.Rodrigues(rvec)
            R_target2cam.append(R)
            t_target2cam.append(tvec)

        R_cam2gripper, t_cam2gripper = cv2.calibrateHandEye(
            R_gripper2base, t_gripper2base,
            R_target2cam, t_target2cam,
            method=cv2.CALIB_HAND_EYE_TSAI
        )

        self.get_logger().info("✅ Hand-Eye-Kalibrierung abgeschlossen.")
        self.get_logger().info(f"📍 Translation Kamera → Flansch (Meter): {t_cam2gripper.flatten()}")
        self.get_logger().info(f"🔄 Rotation Kamera → Flansch (Matrix):\n{R_cam2gripper}")

        # Optional: speichern
        np.savez("handeye_result.npz", R=R_cam2gripper, t=t_cam2gripper)

def main(args=None):
    rclpy.init(args=args)
    node = CameraFlangeCalibration()
    try:
        node.run()
    finally:
        node.destroy_node()
        rclpy.shutdown()
