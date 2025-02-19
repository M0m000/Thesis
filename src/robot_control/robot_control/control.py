import rclpy
from rclpy.node import Node
from FC.FC_gripper_handler import GripperHandler
from FC.FC_geometrics_handler import GeometricsHandler
from FC.FC_frame_handler import FrameHandler
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.srv import SetSystemFrame


class Control(Node):
    def __init__(self):
        super().__init__('control')
        
        self.declare_parameter('hook_num', 10)
        self.hook_num = self.get_parameter('hook_num').get_parameter_value().integer_value

        # Publisher für Linear Servoing
        self.jog_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)
        self.jog_publisher_timer = self.create_timer(0.01, self.publish_velocity)
        self.velocity_trans = [0.0, 0.0, 0.0]
        self.velocity_rot = [0.0, 0.0, 0.0]

        # Client für Auswahl von Servoing Frame
        self.select_jog_frame_client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.select_jog_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SelectJoggingFrame...")
        self.get_logger().info("Service SelectJoggingFrame available!")
        req = SelectJoggingFrame.Request()
        req.ref = 0     # Servoing passiert in WORLD Frame
        future = self.select_jog_frame_client.call_async(req)
        future.add_done_callback(self.select_jogging_frame_callback)

        # Setze TCP auf Tool
        self.set_kassow_frame_client = self.create_client(SetSystemFrame, '/kr/robot/set_system_frame')
        while not self.set_kassow_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Service SetSystemFrame...")
        self.get_logger().info("Service SetSystemFrame available!")

        self.Trans_needle_tfc = [0.0, 0.0, 0.0]       # in mm
        self.Rot_needle_tfc = [0.0, 0.0, 0.0]           # in Grad
        
        self.set_frame(self.Rot_needle_tfc, self.Trans_needle_tfc, frame="tcp", ref_frame="tfc")        # setze Frame TCP auf die Nadel


        # Instanz Geometrics Handler
        self.geometrics_handler = GeometricsHandler()
        self.hook = self.geometrics_handler.get_hook_of_global_scan_dict(hook_num=self.hook_num)
        self.geometrics_handler.update_hook_data(hook_num=self.hook_num)
        self.geometrics_handler.calculate_hook_line()

        # Instanz Gripper Handler
        # self.gripper_handler = GripperHandler()
        # self.gripper_handler.gripper_startup()
        # self.gripper_handler.open_gripper()

        # Instanz des MoveLinearServiceClient
        self.move_lin_client = MoveLinearServiceClient()

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = 'frame_handler_for_dummy_node')

        # Position Grip in WORK Frame
        self.grip_pre_pos_in_workframe = [1018.0, -100.0, -50.0]
        self.grip_pre_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pre_pos_in_worldframe, self.grip_pre_rot_in_worldframe = self.frame_handler.transform_pose_to_world(trans = self.grip_pre_pos_in_workframe,
                                                                                                                      rot = self.grip_pre_rot_in_workframe,
                                                                                                                      pose_ref_frame = "work")
        
        # Preposition Grip in WORK Frame
        self.grip_pos_in_workframe = [1018.0, -100.0, 20.0]
        self.grip_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pos_in_worldframe, self.grip_rot_in_worldframe = self.frame_handler.transform_pose_to_world(trans = self.grip_pos_in_workframe,
                                                                                                              rot = self.grip_rot_in_workframe,
                                                                                                              pose_ref_frame = "work")
        
        # Position zum rausnehmen des Bauteils
        self.grip_post_pos_in_workframe = [1018.0, -200.0, 20.0]
        self.grip_post_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_post_pos_in_worldframe, self.grip_post_rot_in_worldframe = self.frame_handler.transform_pose_to_world(trans = self.grip_post_pos_in_workframe,
                                                                                                                        rot = self.grip_post_rot_in_workframe,
                                                                                                                        pose_ref_frame = "work")
        '''
        self.grip_pre_pos_movement_done = False
        self.grip_pre_pos_movement_done = self.move_lin_client.call_move_linear_service(pos = self.grip_pre_pos_in_worldframe,
                                                                                        rot = self.grip_pre_rot_in_worldframe,
                                                                                        ref = 0,
                                                                                        ttype = 0,
                                                                                        tvalue = 20.0,
                                                                                        bpoint = 0,
                                                                                        btype = 0,
                                                                                        bvalue = 100.0,
                                                                                        sync = 0.0,
                                                                                        chaining = 0)
        if self.grip_pre_pos_movement_done:
            time.sleep(1)
        
        self.grip_pos_movement_done = False
        self.grip_pos_movement_done = self.move_lin_client.call_move_linear_service(pos = self.grip_pos_in_worldframe,
                                                                                    rot = self.grip_rot_in_worldframe,
                                                                                    ref = 0,
                                                                                    ttype = 0,
                                                                                    tvalue = 20.0,
                                                                                    bpoint = 0,
                                                                                    btype = 0,
                                                                                    bvalue = 100.0,
                                                                                    sync = 0.0,
                                                                                    chaining = 0)
        if self.grip_pos_movement_done:
            time.sleep(2)
        self.gripper_handler.close_gripper()
        
        if self.gripper_handler.gripper_closed:
            self.grip_post_movement_done = False
            self.grip_post_movement_done = self.move_lin_client.call_move_linear_service(pos = self.grip_post_pos_in_worldframe,
                                                                                         rot = self.grip_post_rot_in_worldframe,
                                                                                         ref = 0,
                                                                                         ttype = 0,
                                                                                         tvalue = 20.0,
                                                                                         bpoint = 0,
                                                                                         btype = 0,
                                                                                         bvalue = 100.0,
                                                                                         sync = 0.0,
                                                                                         chaining = 0)
        '''
        self.plane = None
        self.geometrics_handler.update_hook_data(hook_num = self.hook_num)
        self.geometrics_handler.calculate_hook_line()
        self.plane = self.geometrics_handler.calculate_plane(trans_in_tfcframe = [0, 0, 112.0], rot_in_tfcframe = [0, 0, 0])

        # Lineares Anfahren der Position - erste grobe Positionierung
        endpos_trans_in_worldframe, endpos_rot_in_worldframe = self.geometrics_handler.calculate_targetpose_in_worldframe()
        self.grip_post_movement_done = self.move_lin_client.call_move_linear_service(pos = endpos_trans_in_worldframe,
                                                                                     rot = endpos_rot_in_worldframe,
                                                                                     ref = 0,
                                                                                     ttype = 0,
                                                                                     tvalue = 30.0,
                                                                                     bpoint = 0,
                                                                                     btype = 0,
                                                                                     bvalue = 100.0,
                                                                                     sync = 0.0,
                                                                                     chaining = 0)
        print(endpos_trans_in_worldframe, endpos_rot_in_worldframe)

        # Timer für Regelungsalgorithmus
        self.control_timer = self.create_timer(0.001, self.control)



    def select_jogging_frame_callback(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('Service call SelectJoggingFrame successful!')
            else:
                self.get_logger().info('Service call SelectJoggingFrame failed!')
        except Exception as e:
            self.get_logger().error(f'Error calling service SelectJoggingFrame: {e}')


    def control(self):
        self.geometrics_handler.update_hook_data(hook_num = self.hook_num)
        self.geometrics_handler.calculate_hook_line()
        adjustment_angles = self.geometrics_handler.calculate_adjustment_angles()
        translation_diff = self.geometrics_handler.calculate_translation_difference()

        rotation_diff_worldframe = self.frame_handler.tansform_velocity_to_world(vel = adjustment_angles, from_frame = 'tfc')
        translation_diff_worldframe = self.frame_handler.tansform_velocity_to_world(vel = translation_diff, from_frame = 'tfc')

        print(translation_diff_worldframe, rotation_diff_worldframe)
        
        self.velocity_trans = translation_diff_worldframe * 0.5
        self.velocity_rot = rotation_diff_worldframe * 0.3


    def publish_velocity(self):
        msg = JogLinear()
        msg.vel = self.velocity_trans
        msg.rot = self.velocity_rot

        self.jog_publisher.publish(msg = msg)


    def set_frame(self, R, T, frame="tcp", ref_frame="tfc"):
        request = SetSystemFrame.Request()
        request.name = frame
        request.ref = ref_frame
        request.pos = T
        request.rot = R

        future = self.set_kassow_frame_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Frame '{frame}' set successfully!")
            else:
                self.get_logger().warn(f"Failed to set frame '{frame}'!")
        except Exception as e:
            self.get_logger().error(f"Service call of SetSystemFrame failed: {e}")



    def destroy(self):
        """Gibt alle Ressourcen frei, bevor der Node beendet wird."""
        self.get_logger().info("Beende Control Node...")
        self.jog_publisher_timer.cancel()
        self.control_timer.cancel()
        self.destroy_node()
        self.get_logger().info("Control Node erfolgreich gestoppt.")




def main(args=None):
    rclpy.init(args=args)
    node = Control()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down...")
    finally:
        node.destroy()
        rclpy.shutdown()

if __name__ == '__main__':
    main()