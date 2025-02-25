from cv_bridge import CvBridge
from rclpy.node import Node



class DictReceiveProcessor(Node):
    def __init__(self, dual_cam_setup = False):
        """
        Initialisiert den Dictionary-Prozessor für die Verarbeitung der Hook-Daten.
        """
        self.bridge = CvBridge()
        self.hooks_dict = {}
        self.dual_camera_setup = dual_cam_setup

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
                'uv_hook': None, 'uv_tip': None, 'uv_lowpoint': None,
                'uv_hook_img2': None, 'uv_tip_img2': None, "uv_lowpoint_img2": None,
                'skeleton_mask': None, 'shortest_path': None, 'path_points': None
            }

            # Hook BBox
            if hook_msg.hook_box:
                hook_data['hook_box'] = [
                    hook_msg.hook_box.x_min, hook_msg.hook_box.y_min,
                    hook_msg.hook_box.x_max, hook_msg.hook_box.y_max
                ]

            # Maske des Skeletts
            if hook_msg.skeleton_mask and hook_msg.skeleton_mask.data:
                try:
                    hook_data['skeleton_mask'] = self.bridge.imgmsg_to_cv2(hook_msg.skeleton_mask, desired_encoding="32FC1")
                except Exception as e:
                    self.get_logger().warn(f"Error converting skeleton_mask: {e}")

            # Maske des Hakens
            if hook_msg.hook_mask and hook_msg.hook_mask.data:
                try:
                    hook_data['hook_mask'] = self.bridge.imgmsg_to_cv2(hook_msg.hook_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.get_logger().warn(f"Error converting hook_mask: {e}")

            # Conf-Wert von Hook
            hook_data['conf_hook'] = hook_msg.conf_hook

            # UV Koordinaten von Hook
            hook_data['uv_hook'] = [hook_msg.uv_hook.u, hook_msg.uv_hook.v]
            if self.dual_camera_setup:
                hook_data['uv_hook_img2'] = [hook_msg.uv_hook_img2.u, hook_msg.uv_hook_img2.v]

            # XYZ Koordinaten von Hook
            hook_data['xyz_hook_in_camframe'] = [hook_msg.xyz_hook_in_camframe.x,
                                                 hook_msg.xyz_hook_in_camframe.y,
                                                 hook_msg.xyz_hook_in_camframe.z] if hook_msg.xyz_hook_in_camframe else None



            # Tip BBox
            if hook_msg.tip_box:
                hook_data['tip_box'] = [
                    hook_msg.tip_box.x_min, hook_msg.tip_box.y_min,
                    hook_msg.tip_box.x_max, hook_msg.tip_box.y_max
                ]

            # Maske von Tip
            if hook_msg.tip_mask and hook_msg.tip_mask.data:
                try:
                    hook_data['tip_mask'] = self.bridge.imgmsg_to_cv2(hook_msg.tip_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.get_logger().warn(f"Error converting tip_mask: {e}")
            
            # Conf-Wert von Tip
            hook_data['conf_tip'] = hook_msg.conf_tip

            # UV Koordinaten von Tip
            hook_data['uv_tip'] = [hook_msg.uv_tip.u, hook_msg.uv_tip.v] if hook_msg.tip_box else None
            if self.dual_camera_setup:
                hook_data['uv_tip_img2'] = [hook_msg.uv_tip_img2.u, hook_msg.uv_tip_img2.v]

            # XYZ Koordinaten von Tip
            hook_data['xyz_tip_in_camframe'] = [hook_msg.xyz_tip_in_camframe.x,
                                                hook_msg.xyz_tip_in_camframe.y,
                                                hook_msg.xyz_tip_in_camframe.z] if hook_msg.xyz_tip_in_camframe else None


            # Lowpoint BBox
            if hook_msg.lowpoint_box:
                hook_data['lowpoint_box'] = [
                    hook_msg.lowpoint_box.x_min, hook_msg.lowpoint_box.y_min,
                    hook_msg.lowpoint_box.x_max, hook_msg.lowpoint_box.y_max
                ]

            # Maske von Lowpoint
            if hook_msg.lowpoint_mask and hook_msg.lowpoint_mask.data:
                try:
                    hook_data['lowpoint_mask'] = self.bridge.imgmsg_to_cv2(hook_msg.lowpoint_mask, desired_encoding='32FC1')
                except Exception as e:
                    self.get_logger().warn(f"Error converting lowpoint_mask: {e}")

            # Conf-Wert von Lowpoint
            hook_data['conf_lowpoint'] = hook_msg.conf_lowpoint

            # UV Koordinaten Lowpoint
            hook_data['uv_lowpoint'] = [hook_msg.uv_lowpoint.u, hook_msg.uv_lowpoint.v] if hook_msg.lowpoint_box else None
            if self.dual_camera_setup:
                hook_data['uv_lowpoint_img2'] = [hook_msg.uv_lowpoint_img2.u, hook_msg.uv_lowpoint_img2.v]
            
            # XYZ Koordinaten von Lowpoint
            hook_data['xyz_lowpoint_in_camframe'] = [hook_msg.xyz_lowpoint_in_camframe.x,
                                                     hook_msg.xyz_lowpoint_in_camframe.y,
                                                     hook_msg.xyz_lowpoint_in_camframe.z] if hook_msg.xyz_lowpoint_in_camframe else None
            


            # Shortest Path und Path Points
            if hook_msg.shortest_path:
                hook_data['shortest_path'] = [(pt.u, pt.v) for pt in hook_msg.shortest_path]
            if hook_msg.path_points:
                hook_data['path_points'] = [(pt.u, pt.v) for pt in hook_msg.path_points]



            # Speichere alles im Dictionary mit der Instanz-ID
            self.hooks_dict[hook_msg.name] = hook_data
        return self.hooks_dict
