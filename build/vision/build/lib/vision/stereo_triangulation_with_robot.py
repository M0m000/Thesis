import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
from kr_msgs.msg import JogLinear


class StereoTriangulationWithRobot(Node):
    def __init__(self):
        super().__init__('stereo_triangulation_with_robot')

        # Topics
        self.subscription1 = self.create_subscription(Image, '/vision/camera_1/point_mask_rgbd', self.cam_1_callback, 10)
        self.robot_tcp_twist = self.create_subscription(JogLinear, '/kr/motion/jog_linear', self.tcp_twist_callback, 10)

        # Parameter
        self.declare_parameter('triangulation_axis_tcp', 'axis_x')
        self.triangulation_axis_tcp = self.get_parameter('triangulation_axis_tcp').get_parameter_value().string_value
        self.declare_parameter('baseline_dist_in_mm', 10.0)
        self.baseline_dist_in_mm = self.get_parameter('baseline_dist_in_mm').get_parameter_value().double_value

        # Bridge für Bildverarbeitung
        self.bridge = CvBridge()

        # Kamera 1 Parameter
        self.cam_1_fx = 619.3136
        self.cam_1_fy = 620.4985
        self.cam_1_cx = 318.262176513672
        self.cam_1_cy = 242.990539550781

        # Daten für Punktmasken
        self.cam_1_depth = None
        self.cam_1_point_mask = None

        # Geschwindigkeit und Triggerzeit
        self.current_velocity = 0.0  # Initiale Geschwindigkeit
        self.trigger_time_in_s = None  # Initial keine Triggerzeit

        # Start eines kontinuierlichen Timers mit festem Intervall
        self.timer_interval = 0.005  # Intervall in Sekunden
        self.timer = self.create_timer(self.timer_interval, self.continuous_timer_callback)

    def tcp_twist_callback(self, msg):
        if self.triangulation_axis_tcp == 'axis_x':
            self.current_velocity = msg.vel[0]
        elif self.triangulation_axis_tcp == 'axis_y':
            self.current_velocity = msg.vel[1]
        elif self.triangulation_axis_tcp == 'axis_z':
            self.current_velocity = msg.vel[2]
        else:
            self.get_logger().error(f"Ungültiger Wert für triangulation_axis_tcp: {self.triangulation_axis_tcp}")
            return

        # Berechnung der Triggerzeit basierend auf aktueller Geschwindigkeit
        if self.current_velocity != 0:
            self.trigger_time_in_s = self.baseline_dist_in_mm / abs(self.current_velocity)
            # self.get_logger().info(f"Neue Triggerzeit berechnet: {self.trigger_time_in_s} Sekunden")

    def cam_1_callback(self, msg):
        try:
            mask = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            self.cam_1_point_mask = mask[:, :, 0]
            self.cam_1_depth = mask[:, :, 1]
        except Exception as e:
            self.get_logger().error(f"Fehler beim Verarbeiten der Kameradaten: {e}")

    def continuous_timer_callback(self):
        if self.trigger_time_in_s is not None:
            self.trigger_time_in_s -= self.timer_interval  # Countdown
            if self.trigger_time_in_s <= 0:
                self.get_logger().info("Trigger!")
                self.trigger_cam_1_callback()
                self.trigger_time_in_s = None  # Zurücksetzen der Triggerzeit

    def trigger_cam_1_callback(self):
        # Aktionen, die normalerweise beim Timer-Trigger passieren
        if self.cam_1_point_mask is not None and self.cam_1_depth is not None:
            self.get_logger().info("Verarbeitung der Punktmaske und Tiefe beginnt.")
        else:
            self.get_logger().warning("Keine Daten für Kamera 1 verfügbar.")


def main(args=None):
    rclpy.init(args=args)
    stereo_triangulation = StereoTriangulationWithRobot()

    try:
        rclpy.spin(stereo_triangulation)
    except KeyboardInterrupt:
        pass
    finally:
        stereo_triangulation.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
