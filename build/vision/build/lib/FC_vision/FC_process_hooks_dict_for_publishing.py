from cv_bridge import CvBridge
from action_interfaces.msg import HookData, Hook, BoundingBox, UV, XYZ
import numpy as np


def process_hook_for_publisher(hook_name, hook_data, dual_camera_setup = False, publish_masks = True):
        """
        Verarbeitung für Hooks Dict als Vorbereitung für Publish
        """
        hook = Hook()
        hook.name = hook_name
        bridge = CvBridge()

        # Hook BBox
        if hook_data['hook_box'] is not None:
            hook.hook_box = BoundingBox(
                x_min=float(hook_data['hook_box'][0]),
                y_min=float(hook_data['hook_box'][1]),
                x_max=float(hook_data['hook_box'][2]),
                y_max=float(hook_data['hook_box'][3])
            )
            
            # Maske von Hook
            if hook_data['hook_mask'] is not None and publish_masks:
                hook.hook_mask = bridge.cv2_to_imgmsg(np.array(hook_data['hook_mask']), encoding="32FC1")
            
            # Maske des Skeletts
            if 'skeleton_mask' in hook_data:
                if hook_data['skeleton_mask'] is not None and publish_masks:
                    skeleton_mask = np.array(hook_data['skeleton_mask'], dtype=np.float32)  # Umwandlung in float32
                    hook.hook_mask = bridge.cv2_to_imgmsg(skeleton_mask, encoding="32FC1")
            
            # verarbeite Shortest Path (Spitze zu Senke)
            if 'shortest_path' in hook_data:
                if hook_data['shortest_path'] is not None:
                    hook.shortest_path = [UV(u = float(x), v = float(y)) for x, y in hook_data['shortest_path']]

            # verarbeite Path Points (für Interpolation zwischen Spitze und Senke)
            if 'path_points' in hook_data:
                if hook_data['path_points'] is not None:
                    hook.path_points = [UV(u = float(x), v = float(y)) for x, y in hook_data['path_points']]
            
            # Conf-Wert von Hook
            hook.conf_hook = float(hook_data['conf_hook'])

            # UV Koordinaten von Hook
            hook.uv_hook = UV(u=hook_data['uv_hook'][0], v=hook_data['uv_hook'][1])
            if dual_camera_setup == True:
                hook.uv_tip_img2 = UV(u = hook_data['uv_hook_img2'][0], 
                                      v = hook_data['uv_hook_img2'][1])
                
            # XYZ Koordinaten von Hook
            if hook_data['xyz_hook_in_camframe'] is not None:
                hook.xyz_hook_in_camframe = XYZ(x = hook_data['xyz_hook_in_camframe'][0],
                                                y = hook_data['xyz_hook_in_camframe'][1],
                                                z = hook_data['xyz_hook_in_camframe'][2])




        # Tip BBox
        if hook_data['tip_box'] is not None:
            hook.tip_box = BoundingBox(
                x_min=float(hook_data['tip_box'][0]),
                y_min=float(hook_data['tip_box'][1]),
                x_max=float(hook_data['tip_box'][2]),
                y_max=float(hook_data['tip_box'][3])
            )

            # Maske von Tip
            if hook_data['tip_mask'] is not None and publish_masks:
                hook.tip_mask = bridge.cv2_to_imgmsg(np.array(hook_data['tip_mask']), encoding="32FC1")
            
            # Conf-Wert von Tip
            hook.conf_tip = float(hook_data['conf_tip'])

            # UV Koordinaten von Tip
            hook.uv_tip = UV(u=hook_data['uv_tip'][0], v = hook_data['uv_tip'][1])
            if dual_camera_setup == True:
                hook.uv_tip_img2 = UV(u = hook_data['uv_tip_img2'][0], 
                                      v = hook_data['uv_tip_img2'][1])
            
            # XYZ Koordinaten von Tip
            if hook_data['xyz_tip_in_camframe'] is not None:
                hook.xyz_tip_in_camframe = XYZ(x = hook_data['xyz_tip_in_camframe'][0],
                                               y = hook_data['xyz_tip_in_camframe'][1],
                                               z = hook_data['xyz_tip_in_camframe'][2])




        # Lowpoint BBox
        if hook_data['lowpoint_box'] is not None:
            hook.lowpoint_box = BoundingBox(
                x_min=float(hook_data['lowpoint_box'][0]),
                y_min=float(hook_data['lowpoint_box'][1]),
                x_max=float(hook_data['lowpoint_box'][2]),
                y_max=float(hook_data['lowpoint_box'][3])
            )

            # Maske von Lowpoint
            if hook_data['lowpoint_mask'] is not None and publish_masks:
                hook.lowpoint_mask = bridge.cv2_to_imgmsg(np.array(hook_data['lowpoint_mask']), encoding="32FC1")

            # Conf-Wert von Lowpoint
            hook.conf_lowpoint = float(hook_data['conf_lowpoint'])

            # UV Koordinaten von Lowpoint
            hook.uv_lowpoint = UV(u=hook_data['uv_lowpoint'][0], v=hook_data['uv_lowpoint'][1])
            if dual_camera_setup == True:
                hook.uv_lowpoint_img2 = UV(u = hook_data['uv_lowpoint_img2'][0], 
                                           v = hook_data['uv_lowpoint_img2'][1])
            
            # XYZ Koordinaten von Lowpoint
            if hook_data['xyz_lowpoint_in_camframe'] is not None:
                hook.xyz_lowpoint_in_camframe = XYZ(x = hook_data['xyz_lowpoint_in_camframe'][0],
                                                    y = hook_data['xyz_lowpoint_in_camframe'][1],
                                                    z = hook_data['xyz_lowpoint_in_camframe'][2])
        return hook
