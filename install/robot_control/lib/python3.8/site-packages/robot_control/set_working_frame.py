import rclpy
from rclpy.node import Node
from pynput import keyboard
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from cv_bridge import CvBridge
import numpy as np
import cv2
from sensor_msgs.msg import Image


class SetWorkingFrame(Node):
    def __init__(self):
        super().__init__('set_working_frame')

        self.declare_parameter('trans_speed_factor', 0.05)
        self.trans_speed_factor = self.get_parameter('trans_speed_factor').get_parameter_value().double_value
        self.declare_parameter('rot_speed_factor', 0.05)
        self.rot_speed_factor = self.get_parameter('rot_speed_factor').get_parameter_value().double_value
        self.declare_parameter('tolerance', [0.1, 0.1, 0.1, 0.1, 0.1, 0.1])
        self.tolerance = self.get_parameter('tolerance').get_parameter_value().double_array_value
        self.declare_parameter('show_plot', True)
        self.show_plot = self.get_parameter('show_plot').get_parameter_value().bool_value
        self.declare_parameter('target_pos_in_px', [400.0, 580.0])
        self.target_pos_in_px = self.get_parameter('target_pos_in_px').get_parameter_value().double_array_value
        self.declare_parameter('target_width_in_px', 400.0)
        self.target_width_in_px = self.get_parameter('target_width_in_px').get_parameter_value().double_value
        self.declare_parameter('target_angle', [90.0, 90.0, 90.0, 90.0])
        self.target_angle = self.get_parameter('target_angle').get_parameter_value().double_array_value

        
        self.client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Wait for service SelectJoggingFrame...')
        self.get_logger().info('Service SelectJoggingFrame available!')
        self.srv_select_jogging_frame()     # rufe Service SelectJoggingFrame auf
        
        self.publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
        self.jog_msg = JogLinear()
        self.jog_msg.vel = [0.0, 0.0, 0.0]
        self.jog_msg.rot = [0.0, 0.0, 0.0]

        self.subscription = self.create_subscription(
            Image,
            'vcnanoz/image_raw',
            self.image_callback,
            1
        )
        self.subscription
        self.received_img = None
        self.bridge = CvBridge()

        self.publish_timer_period = 0.002
        self.publish_timer = self.create_timer(self.publish_timer_period, self.publish_callback)

        self.ibvs_active = False
        self.act_speed_cam = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        self.act_speed_tcp = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        self.gain_vector = [[self.trans_speed_factor, 0.0, 0.0, 0.0, 0.0, 0.0], 
                            [0.0, self.trans_speed_factor, 0.0, 0.0, 0.0, 0.0],
                            [0.0, 0.0, self.trans_speed_factor, 0.0, 0.0, 0.0],
                            [0.0, 0.0, 0.0, self.rot_speed_factor, 0.0, 0.0],
                            [0.0, 0.0, 0.0, 0.0, self.rot_speed_factor, 0.0],
                            [0.0, 0.0, 0.0, 0.0, 0.0, self.rot_speed_factor]]
        
        self.R_cam_in_tcp = self.calc_rotation_matrix(0.0, 0.0, 180.0)
        self.block_diag_matrix = self.calc_block_diag_matrix(self.R_cam_in_tcp)
        self.qr = []

        self.listener = keyboard.Listener(on_press=self.on_press)
        self.listener.start()

        self.detector = QRCodeDetector()
        self.movements_done = False


    def calc_block_diag_matrix(self, R):
        return np.array([[R[0][0], R[0][1], R[0][2], 0.0, 0.0, 0.0],
                [R[1][0], R[1][1], R[1][2], 0.0, 0.0, 0.0],
                [R[2][0], R[2][1], R[2][2], 0.0, 0.0, 0.0],
                [0.0, 0.0, 0.0, R[0][0], R[0][1], R[0][2]],
                [0.0, 0.0, 0.0, R[1][0], R[1][1], R[1][2]],
                [0.0, 0.0, 0.0, R[2][0], R[2][1], R[2][2]]])
    

    def calc_rotation_matrix(self, angle_x, angle_y, angle_z):
        angle_x = np.deg2rad(angle_x)
        angle_y = np.deg2rad(angle_y)
        angle_z = np.deg2rad(angle_z)

        R_x = [[1.0, 0.0, 0.0],
               [0.0, np.cos(angle_x), -np.sin(angle_x)],
               [0.0, np.sin(angle_x), np.cos(angle_x)]]
        
        R_y = [[np.cos(angle_y), 0.0, np.sin(angle_y)],
               [0.0, 1.0, 0.0],
               [-np.sin(angle_y), 0.0, np.cos(angle_y)]]
        
        R_z = [[np.cos(angle_z), -np.sin(angle_z), 0.0],
               [np.sin(angle_z), np.cos(angle_z), 0.0],
               [0.0, 0.0, 1.0]]
        return np.array(R_z) @ (np.array(R_y) @ np.array(R_x))

    
    def srv_select_jogging_frame(self):
        request = SelectJoggingFrame.Request()
        request.ref = 2
        future = self.client.call_async(request)
        future.add_done_callback(self.service_response_callback)


    def service_response_callback(self, future):
        try:
            response = future.result()
            if response.success:        # wenn Frame gesetzt -> Tastensteuerung kann beginnen
                self.get_logger().info('Jogging Frame set to TPC.')
            else:
                self.get_logger().warn('Jogging Frame Selection failed!')
        except Exception as e:
            self.get_logger().error(f'Error Service-Call: {e}')


    def publish_callback(self):
        # self.get_logger().info(f"Publishing: {self.jog_msg}")
        self.jog_msg.vel = self.act_speed_tcp[0:3]
        self.jog_msg.rot = self.act_speed_tcp[3:6]
        if self.ibvs_active:
            self.publisher.publish(self.jog_msg)


    def on_press(self, key):
        if key.char == 'p':  # starte IBVS
            self.ibvs_active = True
            self.get_logger().info(f"2D IBVS started!")

        elif key.char == 'o':  # stoppe IBVS
            self.ibvs_active = False
            self.get_logger().info(f"2D IBVS stopped!")
        

    def image_callback(self, msg):
        try:
            self.received_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            qrs = self.detector.detect_qr_codes(img=self.received_img)
            act_error = self.process_qrs(qrs)
            
            if act_error is not None:
                if not self.movements_done:
                    self.act_speed_cam = self.gain_vector @ act_error
                    self.act_speed_cam = self.act_speed_cam.reshape((1, 6))[0].tolist()
                    self.movements_done = False

                if all(abs(act_error[i]) < abs(self.tolerance[i]) for i in range(6)):
                    self.act_speed_cam = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
                    self.movements_done = True
                    # self.get_logger().info(f"Movement done: {self.movements_done}")
            else:
                self.act_speed_cam = [0.0 ,0.0, 0.0, 0.0, 0.0, 0.0]
            
            self.act_speed_tcp = self.block_diag_matrix @ self.act_speed_cam
            self.act_speed_tcp = self.act_speed_tcp.reshape((1, 6))[0].tolist()
            self.get_logger().info(f"\nActual Speed in CAM Frame: {self.act_speed_cam}\n")
            self.get_logger().info(f"Actual Speed in TCP Frame: {self.act_speed_tcp}\n")
            
            if self.show_plot:
                self.plot_image_with_qr(self.received_img, qrs)     # Plot-Bild mit QR-Codes
        except Exception as e:
            self.get_logger().error(f'Error in image acquisition: {e}')


    def plot_image_with_qr(self, img, qr_codes):
        img_copy = img.copy()
        for qr in qr_codes:
            center = qr.get_center()
            cv2.circle(img_copy, tuple(center.astype(int)), 10, (0, 0, 255), -1)
        cv2.imshow("QR Code Detection", img_copy)
        cv2.waitKey(1)


    def process_qrs(self, qrs):
        if len(qrs) == 3:
            qr_ref = qrs[0]
            qr_upper = qrs[1]
            qr_right = qrs[2]

            e_trans_x = self.target_pos_in_px[0] - qr_ref.get_center()[0]
            e_trans_y = self.target_pos_in_px[1] - qr_ref.get_center()[1]
            w_ref_ru = self.calc_width_between_qrs(qr_ref.get_center(), qr_right.get_center())
            e_trans_z = self.target_width_in_px - w_ref_ru
            
            e_rot_z = 0.0 - ( - self.calc_z_angle_between_qrs(qr_ref.get_center(), qr_right.get_center()))
            w_diff_ref_upper = qr_ref.get_width() - qr_upper.get_width()
            w_diff_ref_right = qr_ref.get_height() - qr_right.get_height()

            e_rot_x = w_diff_ref_upper
            e_rot_y = w_diff_ref_right
            
            e = [e_trans_x,
                 e_trans_y,
                 e_trans_z,
                 e_rot_x,
                 e_rot_y,
                 e_rot_z]
            e = np.array(e).reshape((6, 1))
            # self.get_logger().info(f"Act Error: {e}")
            return e


    def calc_width_between_qrs(self, c_ref, c_right):
        return np.linalg.norm((c_right - c_ref))

    def calc_z_angle_between_qrs(self, c_ref, c_right):
        vector = np.array([c_right[0] - c_ref[0], c_right[1] - c_ref[1]])
        x_axis = np.array([1, 0])

        dot_product = np.dot(vector, x_axis)
        cross_product = np.cross(x_axis, vector)
        angle_rad = np.arctan2(cross_product, dot_product)
        angle_deg = np.degrees(angle_rad)
        return angle_deg


class QRCode:
    def __init__(self, corners, center, width, height):
        self.corners = corners
        self.center = center
        self.width = width
        self.height = height

    def get_corners(self):
        return self.corners

    def get_center(self):
        return self.center
    
    def get_width(self):
        return self.width
    
    def get_height(self):
        return self.height


class QRCodeDetector:
    def __init__(self):
        self.qr_codes = []
        self.sorted_qr_codes = []

    def detect_qr_codes(self, img):
        qr_code_detector = cv2.QRCodeDetector()
        retval, decoded_info, corners, straight_qrcode = qr_code_detector.detectAndDecodeMulti(img)
        
        self.qr_codes = []
        if corners is not None:
            for qr_corners in corners:
                center = np.mean(qr_corners, axis=0)
                width = self.calc_width_of_qr(qr_corners)
                height = self.calc_height_of_qr(qr_corners)
                qr_code = QRCode(qr_corners, center, width, height)
                self.qr_codes.append(qr_code)
        self._sort_qr_codes()
        return self.sorted_qr_codes
    
    def calc_width_of_qr(self, corners):
        top_left, top_right, bottom_right, bottom_left = corners
        w_1 = np.linalg.norm((top_right - top_left))
        w_2 = np.linalg.norm((bottom_right - bottom_left))
        return (w_1 + w_2) / 2
    
    def calc_height_of_qr(self, corners):
        top_left, top_right, bottom_right, bottom_left = corners
        h_1 = np.linalg.norm((top_left - bottom_left))
        h_2 = np.linalg.norm((top_right - bottom_right))
        return (h_1 + h_2) / 2

    def _sort_qr_codes(self):
        if len(self.qr_codes) != 3:
            print(f"Es sollten genau 3 QR-Codes im Bild sein! - aktuell: {len(self.qr_codes)}")
            return []
        # Sortiere die QR-Codes basierend auf der x-Koordinate
        self.sorted_qr_codes = sorted(self.qr_codes, key=lambda qr: qr.get_center()[0])

    

def main(args=None):
    rclpy.init(args=args)
    move_lin_by_key = SetWorkingFrame()
    rclpy.spin(move_lin_by_key)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
