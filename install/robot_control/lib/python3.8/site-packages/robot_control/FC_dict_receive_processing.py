import numpy as np
from cv_bridge import CvBridge

class DictReceiveProcessor:
    def __init__(self, node_class):
        """
        Initialisiert den Dictionary-Prozessor für die Verarbeitung der Hook-Daten.
        """
        self.bridge = CvBridge()
        self.hooks_dict = {}
        self.node = node_class

    def process_hooks_dict(self, msg):
        """
        Verarbeitet eine eingehende HookData-Nachricht und speichert sie als Dictionary.
        :param msg: HookData-Nachricht aus ROS2
        """
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
                    hook_data['hook_mask'] = self.bridge.imgmsg_to_cv2(hook_msg.hook_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.node.get_logger().warn(f"Error converting hook_mask: {e}")
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
                    hook_data['tip_mask'] = self.bridge.imgmsg_to_cv2(hook_msg.tip_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.node.get_logger().warn(f"Error converting tip_mask: {e}")
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
                    hook_data['lowpoint_mask'] = self.bridge.imgmsg_to_cv2(hook_msg.lowpoint_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.node.get_logger().warn(f"Error converting lowpoint_mask: {e}")
            hook_data['conf_lowpoint'] = hook_msg.conf_lowpoint
            hook_data['uv_lowpoint'] = [hook_msg.uv_lowpoint.u, hook_msg.uv_lowpoint.v] if hook_msg.lowpoint_box else None

            # Speichere alles im Dictionary mit der Instanz-ID
            self.hooks_dict[hook_msg.name] = hook_data
        return self.hooks_dict
