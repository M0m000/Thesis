import rclpy
from rclpy.node import Node
from FC.FC_gripper_handler import GripperHandler
from FC.FC_hook_geometrics_handler import HookGeometricsHandler
from FC.FC_frame_handler import FrameHandler
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from FC.FC_trajectory_controller import TrajectoryController
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame
from kr_msgs.srv import SetSystemFrame
from pynput import keyboard



class Attachment(Node):
    def __init__(self):
        super().__init__('trajectory_control')
        
        self.declare_parameter('hook_num', 10)
        self.hook_num = self.get_parameter('hook_num').get_parameter_value().integer_value
        self.declare_parameter('manual_mode', False)
        self.manual_mode = self.get_parameter('manual_mode').get_parameter_value().bool_value

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
        self.trans_needle_tfc = [0.0, 0.0, 0.0]       # in mm
        self.rot_needle_tfc = [0.0, 0.0, 0.0]         # in Grad
        self.set_frame(self.rot_needle_tfc, self.trans_needle_tfc, frame="tcp", ref_frame="tfc")

        # Starte den Keyboard-Listener (für das Starten der Regelung und weiterschalten der Path Points)
        self.keyboard_listener = keyboard.Listener(on_release = self.keyboard_input)
        self.keyboard_listener.start()

        # Instanz Geometrics Handler
        self.hook_geometrics_handler = HookGeometricsHandler()
        self.hook = self.hook_geometrics_handler.get_hook_of_global_scan_dict(hook_num=self.hook_num)
        self.hook_geometrics_handler.update_hook_data(hook_num=self.hook_num)
        self.hook_geometrics_handler.calculate_hook_line()

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = 'frame_handler_for_dummy_node')

        # Instanz Trajectory Controller
        self.trajectory_controller = TrajectoryController(logging_active = True,
                                                          controller_output_logging_active = True,
                                                          p_gain_translation = 0.5,
                                                          p_gain_rotation = 0.3)

        # Instanz Gripper Handler
        # self.gripper_handler = GripperHandler()
        # self.gripper_handler.gripper_startup()
        # self.gripper_handler.open_gripper()

        # Instanz des MoveLinearServiceClient
        self.move_lin_client = MoveLinearServiceClient()

        # Position Grip in WORK Frame
        self.grip_pre_pos_in_workframe = [1018.0, -100.0, -50.0]
        self.grip_pre_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pre_pos_in_worldframe, self.grip_pre_rot_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = self.grip_pre_pos_in_workframe,
            rot = self.grip_pre_rot_in_workframe,
            pose_ref_frame = "work")
        
        # Preposition Grip in WORK Frame
        self.grip_pos_in_workframe = [1018.0, -100.0, 20.0]
        self.grip_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pos_in_worldframe, self.grip_rot_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = self.grip_pos_in_workframe,
            rot = self.grip_rot_in_workframe,
            pose_ref_frame = "work")
        
        # Position zum Rausnehmen des Bauteils
        self.grip_post_pos_in_workframe = [1018.0, -200.0, 20.0]
        self.grip_post_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_post_pos_in_worldframe, self.grip_post_rot_in_worldframe = self.frame_handler.transform_pose_to_world(
            trans = self.grip_post_pos_in_workframe,
            rot = self.grip_post_rot_in_workframe,
            pose_ref_frame = "work")
        
        '''
        self.grip_pre_pos_movement_done = False
        self.grip_pre_pos_movement_done = self.move_lin_client.call_move_linear_service(
            pos = self.grip_pre_pos_in_worldframe,
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
        self.grip_pos_movement_done = self.move_lin_client.call_move_linear_service(
            pos = self.grip_pos_in_worldframe,
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
            self.grip_post_movement_done = self.move_lin_client.call_move_linear_service(
            pos = self.grip_post_pos_in_worldframe,
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

        # Lineares Anfahren der Position - erste grobe Positionierung
        self.plane = None
        self.hook_geometrics_handler.update_hook_data(hook_num = self.hook_num)
        self.hook_geometrics_handler.calculate_hook_line()
        self.plane = self.hook_geometrics_handler.calculate_plane(trans_in_tfcframe = [0.0, 0.0, 112.0], rot_in_tfcframe = [0.0, 0.0, 0.0])

        endpos_trans_in_worldframe, endpos_rot_in_worldframe = self.hook_geometrics_handler.calculate_targetpose_in_worldframe()
        self.grip_post_movement_done = self.move_lin_client.call_move_linear_service(
            pos = endpos_trans_in_worldframe,
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

        # Setze Hakennummer und aktiviere Regelung
        self.trajectory_controller.set_hook_num(global_hook_num = self.hook_num)
        self.trajectory_controller.set_control(activate=True, manual_mode = self.manual_mode)



    def keyboard_input(self, key):
        """
        Funktion für Keyboard-Eingabe -> hier wird auf Taste n überprüft -> dann wird der nächste Path Point genommmen
        """
        try:
            if key.char == 'n' and self.manual_mode == True:
                self.take_next_path_point = True
                self.get_logger().info("take_next_path_point set to TRUE")
            
            if key.char == 'r':
                if self.manual_mode == True:
                    self.trajectory_controller.set_control(activate = True, manual_mode = True)
                    self.get_logger().info("Trajectory controller activated in manual mode...")
                else:
                    self.trajectory_controller.set_control(activate = True, manual_mode = False)
                    self.get_logger().info("Trajectory controller activated in automatic mode...")
            
            if key.char == 't':
                self.trajectory_controller.set_control(activate = False)
                self.get_logger().info("Trajectory controller stopped...")
        except AttributeError:
            pass



    def select_jogging_frame_callback(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('Service call SelectJoggingFrame successful!')
            else:
                self.get_logger().info('Service call SelectJoggingFrame failed!')
        except Exception as e:
            self.get_logger().error(f'Error calling service SelectJoggingFrame: {e}')



    def publish_velocity(self):
        msg = JogLinear()
        msg.vel = self.velocity_trans
        msg.rot = self.velocity_rot

        self.jog_publisher.publish(msg = msg)



    def set_frame(self, rot, trans, frame="tcp", ref_frame="tfc"):
        request = SetSystemFrame.Request()
        request.name = frame
        request.ref = ref_frame
        request.pos = trans
        request.rot = rot

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



    def shutdown(self):
        """Gibt alle Ressourcen frei, bevor der Node beendet wird."""
        self.jog_publisher_timer.cancel()
        self.control_timer.cancel()
        self.destroy_node()



def main(args=None):
    rclpy.init(args=args)
    node = Attachment()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down...")
    finally:
        node.keyboard_listener.stop()
        node.shutdown()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
