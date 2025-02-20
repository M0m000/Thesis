from cv_bridge import CvBridge
from action_interfaces.msg import HookData, Hook, BoundingBox, UV
import numpy as np


def process_hook_for_publisher(hook_name, hook_data, publish_masks = True):
        """
        Verarbeitung für Hooks Dict als Vorbereitung für Publish
        """
        hook = Hook()
        hook.name = hook_name
        bridge = CvBridge()

        # Setze Hook Bounding Box
        if hook_data['hook_box'] is not None:
            hook.hook_box = BoundingBox(
                x_min=float(hook_data['hook_box'][0]),
                y_min=float(hook_data['hook_box'][1]),
                x_max=float(hook_data['hook_box'][2]),
                y_max=float(hook_data['hook_box'][3])
            )
            if hook_data['hook_mask'] is not None and publish_masks:
                hook.hook_mask = bridge.cv2_to_imgmsg(np.array(hook_data['hook_mask']), encoding="32FC1")
            if 'skeleton_mask' in hook_data:
                if hook_data['skeleton_mask'] is not None and publish_masks:
                    skeleton_mask = np.array(hook_data['skeleton_mask'], dtype=np.float32)  # Umwandlung in float32
                    hook.hook_mask = bridge.cv2_to_imgmsg(skeleton_mask, encoding="32FC1")
            hook.conf_hook = float(hook_data['conf_hook'])
            hook.uv_hook = UV(u=hook_data['uv_hook'][0], v=hook_data['uv_hook'][1])

        # Setze Tip Box und Mask als Image, falls verfügbar
        if hook_data['tip_box'] is not None:
            hook.tip_box = BoundingBox(
                x_min=float(hook_data['tip_box'][0]),
                y_min=float(hook_data['tip_box'][1]),
                x_max=float(hook_data['tip_box'][2]),
                y_max=float(hook_data['tip_box'][3])
            )
            if hook_data['tip_mask'] is not None and publish_masks:
                hook.tip_mask = bridge.cv2_to_imgmsg(np.array(hook_data['tip_mask']), encoding="32FC1")
            hook.conf_tip = float(hook_data['conf_tip'])
            hook.uv_tip = UV(u=hook_data['uv_tip'][0], v = hook_data['uv_tip'][1])

        # Setze Lowpoint Box und Mask als Image, falls verfügbar
        if hook_data['lowpoint_box'] is not None:
            hook.lowpoint_box = BoundingBox(
                x_min=float(hook_data['lowpoint_box'][0]),
                y_min=float(hook_data['lowpoint_box'][1]),
                x_max=float(hook_data['lowpoint_box'][2]),
                y_max=float(hook_data['lowpoint_box'][3])
            )
            if hook_data['lowpoint_mask'] is not None and publish_masks:
                hook.lowpoint_mask = bridge.cv2_to_imgmsg(np.array(hook_data['lowpoint_mask']), encoding="32FC1")
            hook.conf_lowpoint = float(hook_data['conf_lowpoint'])
            hook.uv_lowpoint = UV(u=hook_data['uv_lowpoint'][0], v=hook_data['uv_lowpoint'][1])
        return hook
