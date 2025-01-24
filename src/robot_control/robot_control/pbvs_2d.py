import rclpy
from rclpy.node import Node
from pynput import keyboard
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from action_interfaces.msg import HookData, Hook, BoundingBox
from cv_bridge import CvBridge
import numpy as np



class PBVS2DNode(Node):
    def __init__(self):
        super().__init__('pbvs_2d')

        self.declare_parameter('speed_factor', 0.1)
        self.speed_factor = self.get_parameter('speed_factor').get_parameter_value().double_value
        self.declare_parameter('target_point_in_px', [100.0, 100.0])
        self.target_point_in_px = self.get_parameter('target_point_in_px').get_parameter_value().double_array_value
        self.declare_parameter('track_hooktip_num', 1)
        self.track_hooktip_num = self.get_parameter('track_hooktip_num').get_parameter_value().integer_value

        '''
        self.client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Wait for service SelectJoggingFrame...')
        self.get_logger().info('Service SelectJoggingFrame available!')
        '''
        self.publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}
        self.act_tip_pos = self.target_point_in_px

        self.publish_timer_period = 0.002  # Sekunden
        self.process_timer_period = 0.001  # Sekunden
        self.publish_timer = self.create_timer(self.publish_timer_period, self.publish_callback)
        self.process_timer = self.create_timer(self.process_timer_period, self.process)

        self.jog_msg = JogLinear()
        self.jog_msg.vel = [0.0, 0.0, 0.0]

        # self.srv_select_jogging_frame()     # rufe Service SelectJoggingFrame auf

        self.pbvs_active = False
        self.act_speed = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        self.track_hooktip_num = 1


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
                hook_data['uv_hook'] = [hook_msg.uv_hook.u, hook_msg.uv_hook.v]     # Pixelposition Hook

            
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
                hook_data['uv_tip'] = [hook_msg.uv_tip.u, hook_msg.uv_tip.v]     # Pixelposition Tip


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
                hook_data['uv_lowpoint'] = [hook_msg.uv_lowpoint.u, hook_msg.uv_lowpoint.v]     # Pixelposition Lowpoint

            self.hooks_dict[hook_msg.name] = hook_data
        # self.get_logger().info(f'Reconstructed hooks_dict: {self.hooks_dict}')
        # endtime = time.perf_counter()
        # self.get_logger().info(f"Execution time: {endtime-starttime}:.4f seconds.")

    
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
                self.listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
                self.listener.start()
            else:
                self.get_logger().warn('Jogging Frame Selection failed!')
        except Exception as e:
            self.get_logger().error(f'Error Service-Call: {e}')


    def publish_callback(self):
        # self.get_logger().info(f"Publishing: {self.jog_msg}")
        self.publisher.publish(self.jog_msg)


    def on_press(self, key):
        if key.char == 'p':  # starte PBVS
            self.pbvs_active = True
            self.get_logger().info(f"2D PBVS started!")

        elif key.char == 'o':  # stoppe PBVS
            self.pbvs_active = False
            self.get_logger().info(f"2D PBVS stopped!")


    def process(self):
        self.get_act_hook_px_pos()
        w = self.target_point_in_px
        act_error = self.target_point_in_px - np.array(self.act_tip_pos)
        self.act_speed = self.speed_factor * act_error
        print("Aktuelle Regelgroesse: ", self.act_speed)


    def get_act_hook_px_pos(self):
        key = 'hook_' + str(self.track_hooktip_num)
        if key in self.hooks_dict:
            self.act_tip_pos = self.hooks_dict[key]['uv_tip']
            # print("Hook tip position to track", self.act_tip_pos)
        else:
            self.act_tip_pos = self.target_point_in_px
    

def main(args=None):
    rclpy.init(args=args)
    move_lin_by_key = PBVS2DNode()
    rclpy.spin(move_lin_by_key)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
