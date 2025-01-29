import rclpy
from rclpy.node import Node
from pynput import keyboard
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from action_interfaces.msg import HookData, Hook, BoundingBox
from cv_bridge import CvBridge
import numpy as np
import cv2
from sensor_msgs.msg import Image
import time


class IBVS2DNode(Node):
    def __init__(self):
        super().__init__('ibvs_2d')

        self.declare_parameter('speed_factor', 0.05)
        self.speed_factor = self.get_parameter('speed_factor').get_parameter_value().double_value
        self.declare_parameter('target_point_in_px', [640.0, 360.0])
        self.target_point_in_px = self.get_parameter('target_point_in_px').get_parameter_value().double_array_value
        self.declare_parameter('tolerance_in_px', [0.5, 0.5])
        self.tolerance_in_px = self.get_parameter('tolerance_in_px').get_parameter_value().double_array_value
        self.declare_parameter('track_hooktip_num', 2)
        self.track_hooktip_num = self.get_parameter('track_hooktip_num').get_parameter_value().integer_value
        self.declare_parameter('show_plot', True)
        self.show_plot = self.get_parameter('show_plot').get_parameter_value().bool_value

        
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
        
        self.nn_output_segment_img_subscription = self.create_subscription(
            Image,
            'yolov8_output/output_segment_img',
            self.nn_output_segment_img_callback,
            1
        )
        self.nn_output_segment_img_subscription
        self.nn_output_segment_img = None

        self.nn_output_point_img_subscription = self.create_subscription(
            Image,
            'yolov8_output/output_point_img',
            self.nn_output_point_img_callback,
            1
        )
        self.nn_output_point_img_subscription
        self.nn_output_point_img = None

        self.received_img = None
        self.bridge = CvBridge()

        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}
        self.act_tip_pos = self.target_point_in_px
        self.bridge = CvBridge()

        self.publish_timer_period = 0.002  # Sekunden
        self.process_timer_period = 0.001  # Sekunden
        self.publish_timer = self.create_timer(self.publish_timer_period, self.publish_callback)
        self.process_timer = self.create_timer(self.process_timer_period, self.process)

        self.ibvs_active = False
        self.act_speed_cam = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        self.act_speed_tcp = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        self.gain_vector = [[self.speed_factor, 0.0], 
                            [0.0, self.speed_factor],
                            [0.0, 0.0],
                            [0.0, 0.0],
                            [0.0, 0.0],
                            [0.0, 0.0]]
        
        self.R_cam_in_tcp = self.calc_rotation_matrix(0.0, 0.0, 180.0)
        self.block_diag_matrix = self.calc_block_diag_matrix(self.R_cam_in_tcp)

        self.listener = keyboard.Listener(on_press=self.on_press)
        self.listener.start()
        


    def nn_output_segment_img_callback(self, msg):
        try:
            self.nn_output_segment_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'Error in nn_output_segment_img acquisition: {e}')

    def nn_output_point_img_callback(self, msg):
        try:
            self.nn_output_point_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'Error in nn_output_point_img acquisition: {e}')


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


    def hooks_dict_callback(self, msg: HookData):
        # starttime = time.perf_counter()
        bridge = self.bridge  # CvBridge-Instanz aus __init__ nutzen
        self.hooks_dict = {}
    
        for hook_msg in msg.hooks:
            hook_data = {
                'hook_box': None, 'hook_mask': None, 'conf_hook': None,
                'tip_box': None, 'tip_mask': None, 'conf_tip': None,
                'lowpoint_box': None, 'lowpoint_mask': None, 'conf_lowpoint': None,
                'uv_hook': None, 'uv_tip': None, 'uv_lowpoint': None
            }
    
            # Hook-Daten (immer vorhanden)
            if hook_msg.hook_box:
                hook_data['hook_box'] = [
                    hook_msg.hook_box.x_min, hook_msg.hook_box.y_min,
                    hook_msg.hook_box.x_max, hook_msg.hook_box.y_max
                ]
            if hook_msg.hook_mask and hook_msg.hook_mask.data:
                try:
                    hook_data['hook_mask'] = bridge.imgmsg_to_cv2(hook_msg.hook_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.get_logger().warn(f"Error converting hook_mask: {e}")
            hook_data['conf_hook'] = hook_msg.conf_hook
            hook_data['uv_hook'] = [hook_msg.uv_hook.u, hook_msg.uv_hook.v]
    
            # Tip-Daten (optional)
            if hook_msg.tip_box:
                hook_data['tip_box'] = [
                    hook_msg.tip_box.x_min, hook_msg.tip_box.y_min,
                    hook_msg.tip_box.x_max, hook_msg.tip_box.y_max
                ]
            if hook_msg.tip_mask and hook_msg.tip_mask.data:
                try:
                    hook_data['tip_mask'] = bridge.imgmsg_to_cv2(hook_msg.tip_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.get_logger().warn(f"Error converting tip_mask: {e}")
            hook_data['conf_tip'] = hook_msg.conf_tip
            hook_data['uv_tip'] = [hook_msg.uv_tip.u, hook_msg.uv_tip.v] if hook_msg.tip_box else None
    
            # Lowpoint-Daten (optional)
            if hook_msg.lowpoint_box:
                hook_data['lowpoint_box'] = [
                    hook_msg.lowpoint_box.x_min, hook_msg.lowpoint_box.y_min,
                    hook_msg.lowpoint_box.x_max, hook_msg.lowpoint_box.y_max
                ]
            if hook_msg.lowpoint_mask and hook_msg.lowpoint_mask.data:
                try:
                    hook_data['lowpoint_mask'] = bridge.imgmsg_to_cv2(hook_msg.lowpoint_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.get_logger().warn(f"Error converting lowpoint_mask: {e}")
            hook_data['conf_lowpoint'] = hook_msg.conf_lowpoint
            hook_data['uv_lowpoint'] = [hook_msg.uv_lowpoint.u, hook_msg.uv_lowpoint.v] if hook_msg.lowpoint_box else None
    
            # Speichere alles im Dictionary mit der Instanz-ID
            self.hooks_dict[hook_msg.name] = hook_data
    
        # endtime = time.perf_counter()
        # self.get_logger().info(f"Hooks Dict Processing time: {endtime - starttime:.4f} seconds.")

    
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
        self.publisher.publish(self.jog_msg)


    def on_press(self, key):
        if key.char == 'p':  # starte IBVS
            self.ibvs_active = True
            self.get_logger().info(f"2D IBVS started!")

        elif key.char == 'o':  # stoppe IBVS
            self.ibvs_active = False
            self.get_logger().info(f"2D IBVS stopped!")


    def process(self):
        if self.ibvs_active:
            self.get_act_hook_px_pos()
            act_error = (self.target_point_in_px - np.array(self.act_tip_pos)).reshape((2, 1))

            if abs(act_error[0]) > abs(self.tolerance_in_px[0]) and abs(act_error[1]) > abs(self.tolerance_in_px[1]):
                self.act_speed_cam = self.gain_vector @ act_error       # P-Regler -> Bewegung enthaelt I-Anteil (Geschwindigkeit -> Integral -> Weg)
                self.act_speed_cam = self.act_speed_cam.reshape((1, 6))[0].tolist()
            else:
                self.act_speed_cam = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        else:
            self.act_speed_cam = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

        self.act_speed_tcp = self.block_diag_matrix @ self.act_speed_cam
        self.act_speed_tcp = self.act_speed_tcp.reshape((1, 6))[0].tolist()
        self.get_logger().info(f"Actual Speed in CAM Frame: {self.act_speed_cam}")
        self.get_logger().info(f"Actual Speed in TCP Frame: {self.act_speed_tcp}")

        if self.show_plot and self.received_img is not None:
            img = self.plot_points()
            cv2.imshow('Control Loop Img', img)
            cv2.waitKey(1)


    def get_act_hook_px_pos(self):
        key = 'hook_' + str(self.track_hooktip_num)
        if key in self.hooks_dict:
            self.act_tip_pos = self.hooks_dict[key]['uv_tip']
            # self.get_logger().info("Hook tip position to track", self.act_tip_pos)
        else:
            self.act_tip_pos = self.target_point_in_px


    def image_callback(self, msg):
        try:
            self.received_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        except Exception as e:
            self.get_logger().error(f'Error in image acquisition: {e}')


    def plot_points(self):
        img_copy = self.nn_output_point_img.copy()
        
        target_px = (int(self.target_point_in_px[0]), int(self.target_point_in_px[1]))
        cv2.circle(img_copy, target_px, color=(0, 255, 0), radius = int(abs(self.tolerance_in_px[0])*100), thickness=2)

        for idx, key in enumerate(self.hooks_dict):
            if self.hooks_dict[key]['hook_box'] is not None:
                bb_hook = tuple(map(int, self.hooks_dict[key]['hook_box']))
                cv2.rectangle(img_copy, (bb_hook[0], bb_hook[1]), (bb_hook[2], bb_hook[3]), (150, 150, 150), 2)
            if self.hooks_dict[key]['uv_hook'] is not None:
                p_hook = tuple(map(int, self.hooks_dict[key]['uv_hook']))
                cv2.drawMarker(img_copy, p_hook, color=(255, 0, 0), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict[key]['uv_tip'] is not None:
                p_tip = tuple(map(int, self.hooks_dict[key]['uv_tip']))
                cv2.drawMarker(img_copy, p_tip, color=(255, 0, 0), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict[key]['uv_lowpoint'] is not None:
                p_lowpoint = tuple(map(int, self.hooks_dict[key]['uv_lowpoint']))
                cv2.drawMarker(img_copy, p_lowpoint, color=(255, 0, 0), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA) 
        return img_copy
    

def main(args=None):
    rclpy.init(args=args)
    move_lin_by_key = IBVS2DNode()
    rclpy.spin(move_lin_by_key)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
