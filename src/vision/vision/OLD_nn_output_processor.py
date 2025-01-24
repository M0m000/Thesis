import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData, Hook, BoundingBox
import numpy as np
from cv_bridge import CvBridge
import time
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2


class NNOutputProcessorNode(Node):
    def __init__(self):
        super().__init__('nn_output_processor')

        self.declare_parameter('show_plot', True)
        self.show_plot = self.get_parameter('show_plot').get_parameter_value().bool_value
        
        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.img_subscription = self.create_subscription(Image, 'vcnanoz/image_raw', self.image_callback, 1)
        self.img_subscription

        self.process_timer = self.create_timer(0.01, self.process_timer_callback)
        
        self.hooks_dict = {}
        self.hooks_dict_processed = {}

        self.received_img = None


    def process_timer_callback(self):
        if self.hooks_dict != {}:
            self.process_output_hooks_dict()
            if self.show_plot and self.received_img is not None:
                self.points_img = self.plot_points()
                cv2.imshow('Points in Output', self.points_img)
                cv2.waitKey(1)


    def calc_mean_of_mask(self, mask, title='none'):
        if mask is not None and mask != []:
            ys, xs = np.where(mask == 1)
            cx = np.mean(xs)
            cy = np.mean(ys)
            return [cx, cy]


    def process_output_hooks_dict(self):
        self.hooks_dict_processed = self.hooks_dict.copy()

        for idx, key in enumerate(self.hooks_dict):
            hook_mask = self.hooks_dict[key].get('hook_mask', [])
            tip_mask = self.hooks_dict[key].get('tip_mask', [])
            lowpoint_mask = self.hooks_dict[key].get('lowpoint_mask', [])

            if hook_mask is not None and hook_mask != []:
                uv_hook = self.calc_mean_of_mask(hook_mask, title='hook')
            else:
                uv_hook = None
            if tip_mask is not None and tip_mask != []:
                uv_tip = self.calc_mean_of_mask(tip_mask, title='tip')
            else:
                uv_tip = None
            if lowpoint_mask is not None and lowpoint_mask != []:
                uv_lowpoint = self.calc_mean_of_mask(lowpoint_mask, title='lowpoint')
            else:
                uv_lowpoint = None

            self.hooks_dict_processed[key]['uv_hook'] = uv_hook
            self.hooks_dict_processed[key]['uv_tip'] = uv_tip
            self.hooks_dict_processed[key]['uv_lowpoint'] = uv_lowpoint


    def plot_points(self):
        img_copy = self.received_img.copy()
        for idx, key in enumerate(self.hooks_dict_processed):
            if self.hooks_dict_processed[key]['hook_box'] is not None:
                bb_hook = tuple(map(int, self.hooks_dict_processed[key]['hook_box']))
                cv2.rectangle(img_copy, (bb_hook[0], bb_hook[1]), (bb_hook[2], bb_hook[3]), (150, 150, 150), 2)
            if self.hooks_dict_processed[key]['uv_hook'] is not None:
                p_hook = tuple(map(int, self.hooks_dict_processed[key]['uv_hook']))
                cv2.drawMarker(img_copy, p_hook, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict_processed[key]['uv_tip'] is not None:
                p_tip = tuple(map(int, self.hooks_dict_processed[key]['uv_tip']))
                cv2.drawMarker(img_copy, p_tip, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict_processed[key]['uv_lowpoint'] is not None:
                p_lowpoint = tuple(map(int, self.hooks_dict_processed[key]['uv_lowpoint']))
                cv2.drawMarker(img_copy, p_lowpoint, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)  
        return img_copy


    def hooks_dict_callback(self, msg: HookData):
        # starttime = time.perf_counter()
        bridge = CvBridge()
        self.hooks_dict = {}
        
        for hook_msg in msg.hooks:
            hook_data = {}
            if hook_msg.hook_box:
                hook_data['hook_box'] = [           # BoundingBox Hook
                    hook_msg.hook_box.x_min,
                    hook_msg.hook_box.y_min,
                    hook_msg.hook_box.x_max,
                    hook_msg.hook_box.y_max
                ]
                if hook_msg.hook_mask is not None and len(hook_msg.hook_mask.data) > 0:         # SegMask Hook
                    try:
                        hook_data['hook_mask'] = bridge.imgmsg_to_cv2(hook_msg.hook_mask, desired_encoding='32FC1')
                    except Exception as e:
                        self.get_logger().warn(f"Error at converting hook_mask: {e}")
                else:
                    hook_data['hook_mask'] = None
                hook_data['conf_hook'] = hook_msg.conf_hook     # ConfValue Hook

            
            if hook_msg.tip_box:                # BoundingBox Tip
                hook_data['tip_box'] = [
                    hook_msg.tip_box.x_min,
                    hook_msg.tip_box.y_min,
                    hook_msg.tip_box.x_max,
                    hook_msg.tip_box.y_max
                ]
                if hook_msg.tip_mask is not None and len(hook_msg.tip_mask.data) > 0:           # SegMask Tip
                    try:
                        hook_data['tip_mask'] = bridge.imgmsg_to_cv2(hook_msg.tip_mask, desired_encoding='32FC1')
                    except Exception as e:
                        self.get_logger().warn(f"Error at converting tip_mask: {e}")
                else:
                    hook_data['tip_mask'] = None
                hook_data['conf_tip'] = hook_msg.conf_tip       # ConfValue Tip


            if hook_msg.lowpoint_box:
                hook_data['lowpoint_box'] = [           # BoundingBox Lowpoint
                    hook_msg.lowpoint_box.x_min,
                    hook_msg.lowpoint_box.y_min,
                    hook_msg.lowpoint_box.x_max,
                    hook_msg.lowpoint_box.y_max
                ]
                if hook_msg.lowpoint_mask is not None and len(hook_msg.lowpoint_mask.data) > 0:           # SegMask Lowpoint
                    try:
                        hook_data['lowpoint_mask'] = bridge.imgmsg_to_cv2(hook_msg.lowpoint_mask, desired_encoding='32FC1')
                    except Exception as e:
                        self.get_logger().warn(f"Error at converting lowpoint_mask: {e}")
                hook_data['conf_lowpoint'] = hook_msg.conf_lowpoint         # ConfValue Lowpoint

            self.hooks_dict[hook_msg.name] = hook_data
        # self.get_logger().info(f'Reconstructed hooks_dict: {self.hooks_dict}')
        # endtime = time.perf_counter()
        # self.get_logger().info(f"Execution time: {endtime-starttime}:.4f seconds.")
    

    def image_callback(self, msg):
        bridge = CvBridge()
        try:
            self.received_img = bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        except Exception as e:
            self.get_logger().error(f'Error in image acquisition: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = NNOutputProcessorNode()
    
    rclpy.spin(node)
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
