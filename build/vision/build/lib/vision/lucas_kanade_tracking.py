import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
from action_interfaces.msg import HookData, Hook, BoundingBox, UV


class LucasKanadeTrackingNode(Node):
    def __init__(self):
        super().__init__('lucas_kanade_tracking')

        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value

        self.subscription = self.create_subscription(Image, 'vcnanoz/image_raw', self.image_callback, 1)
        self.subscription
        self.received_img = None
        self.bridge = CvBridge()

        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}


    def hooks_dict_callback(self, msg: HookData):
        # starttime = time.perf_counter()
        bridge = CvBridge()
        self.hooks_dict = {}
        
        for hook_msg in msg.hooks:
            hook_data = {}
            if hook_msg.hook_box:
                hook_data['hook_box'] = [       # BoundingBox Hook
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
                hook_data['uv_hook'] = [hook_msg.uv_hook.u, hook_msg.uv_hook.v]     # Pixelposition Hook

            
            if hook_msg.tip_box:
                hook_data['tip_box'] = [        # BoundingBox Tip
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
                hook_data['uv_tip'] = [hook_msg.uv_tip.u, hook_msg.uv_tip.v]     # Pixelposition Tip


            if hook_msg.lowpoint_box:
                hook_data['lowpoint_box'] = [       # BoundingBox Lowpoint
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
                hook_data['uv_lowpoint'] = [hook_msg.uv_lowpoint.u, hook_msg.uv_lowpoint.v]     # Pixelposition Lowpoint

            self.hooks_dict[hook_msg.name] = hook_data
        # self.get_logger().info(f'Reconstructed hooks_dict: {self.hooks_dict}')
        # endtime = time.perf_counter()
        # self.get_logger().info(f"Execution time: {endtime-starttime}:.4f seconds.")


    


def main(args=None):
    rclpy.init(args=args)
    node = LucasKanadeTrackingNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
