import rclpy
from rclpy.node import Node
from pynput import keyboard  # Modul für Tastatureingaben
from FC.FC_gripper_handler import GripperHandler
from FC.FC_geometrics_handler import GeometricsHandler
from FC.FC_frame_handler import FrameHandler
from FC.FC_call_move_linear_service import MoveLinearServiceClient
import time


class DummyNode(Node):
    def __init__(self):
        super().__init__('_dummy_node')

        # Instanz Geometrics Handler
        self.geometrics_handler = GeometricsHandler()
        self.hook = self.geometrics_handler.get_hook_of_global_scan_dict(hook_num=2)
        self.geometrics_handler.update_hook_data(hook_num=1)
        self.geometrics_handler.calculate_hook_line()

        # Instanz Gripper Handler
        self.gripper_handler = GripperHandler()
        self.gripper_handler.gripper_startup()
        self.gripper_handler.open_gripper()

        # Instanz des MoveLinearServiceClient
        self.move_lin_client = MoveLinearServiceClient()

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = 'frame_handler_for_dummy_node')

        # Position Grip in WORK Frame
        self.grip_pre_pos_in_workframe = [1015.0, -100.0, -50.0]
        self.grip_pre_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pre_pos_in_worldframe, self.grip_pre_rot_in_worldframe = self.frame_handler.transform_pose_to_world(trans = self.grip_pre_pos_in_workframe,
                                                                                                                      rot = self.grip_pre_rot_in_workframe,
                                                                                                                      pose_ref_frame = "work")
        
        # Preposition Grip in WORK Frame
        self.grip_pos_in_workframe = [1015.0, -100.0, 20.0]
        self.grip_rot_in_workframe = [-45.0, 0.0, 0.0]
        self.grip_pos_in_worldframe, self.grip_rot_in_worldframe = self.frame_handler.transform_pose_to_world(trans = self.grip_pos_in_workframe,
                                                                                                              rot = self.grip_rot_in_workframe,
                                                                                                              pose_ref_frame = "work")

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

        # Tastatur-Listener starten
        # self.listener = keyboard.Listener(on_release=self.on_key_press)
        # self.listener.start()




    def on_key_press(self, key):
        """ Wird aufgerufen, wenn eine Taste gedrückt wird """
        try:
            if key.char == 'c':  # Greifer schließen
                self.get_logger().info("Schließe den Greifer...")
                self.create_task(self.gripper_handler.close_gripper)

            elif key.char == 'v':  # Greifer öffnen
                self.get_logger().info("Öffne den Greifer...")
                self.create_task(self.gripper_handler.open_gripper)

            elif key.char == 'q':  # Programm beenden
                self.get_logger().info("Beende das Programm...")
                self.listener.stop()
                rclpy.shutdown()

        except AttributeError:
            pass  # Sondertasten ignorieren

    def create_task(self, function):
        """ Führt eine ROS-Funktion sicher im ROS-Executor aus """
        future = self.executor.create_task(function)
        future.add_done_callback(self.task_callback)

    def task_callback(self, future):
        """ Callback-Funktion für abgeschlossene Tasks """
        try:
            result = future.result()
            self.get_logger().info(f"Task abgeschlossen: {result}")
        except Exception as e:
            self.get_logger().error(f"Task-Fehler: {e}")




def main(args=None):
    rclpy.init(args=args)
    node = DummyNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.listener.stop()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
