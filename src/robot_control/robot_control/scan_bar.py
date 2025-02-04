import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_quaternion_to_euler import quaternion_to_euler
from FC.FC_dict_receive_processing import DictReceiveProcessor
from FC.FC_call_move_linear_service import call_move_linear_service
from FC.FC_frame_handler import FrameHandler
import os


class ScanBar(Node):
    def __init__(self):
        super().__init__('scan_bar')

        # Sub Yolov8 Output
        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}

        # Instanz zum Entacken der Yolo Outputs
        self.hooks_dict_processor = DictReceiveProcessor(self)
        self.yolo_hooks_dict = {}

        frame_csv_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
        self.frame_handler = FrameHandler(node=self, save_path=frame_csv_path)
        self.world_to_work_transform = self.load_frame(frame='work', ref_frame='world')
        self.global_hooks_dict = {}

        startpoint_trans_in_workframe = [600.0, -500.0, 0.0]
        startpoint_rot_in_workframe = [0.0, 0.0, 0.0]
        startpoint_trans_worldframe, startpoint_rot_worldframe = self.frame_handler.transform_pose_to_world(trans = startpoint_trans_in_workframe,
                                                                                                            rot = startpoint_rot_in_workframe,
                                                                                                            pose_ref_frame = 'work')
        
        # Timer für Prozess
        self.process_timer = self.create_timer(0.001, self.process_main)
        self.process_step = None
        
        ########## Bewege Roboter auf die Startposition ##########
        self.startpoint_movement_done = False
        if startpoint_rot_worldframe is not None and startpoint_trans_worldframe is not None:
            self.startpoint_movement_done = None
            self.startpoint_movement_done = call_move_linear_service(node = self,
                                                                    pos = startpoint_trans_worldframe,
                                                                    rot = startpoint_rot_worldframe,
                                                                    ref = 0,
                                                                    ttype = 0,
                                                                    tvalue = 150.0,
                                                                    bpoint = 0,
                                                                    btype = 0,
                                                                    bvalue = 100.0,
                                                                    sync = 0.0,
                                                                    chaining = 0)
        while self.startpoint_movement_done is None:
            self.get_logger().warn("Waiting for init movement to complete...")
        if self.startpoint_movement_done:
            self.get_logger.info("Init movement done successfully!")
            self.process_step = "move_until_2_hooks_visible"
        else:
            self.get_logger().error("Init movement failed!")
        ###########################################################

        


    def process_main(self):
        self.get_logger().info("Process active!")
        if self.process_step == "move_until_2_hooks_visible":
            self.get_logger().info("Process step <move_until_2_hooks_visible> active!")


    def load_frame(self, frame, ref_frame):
        csv_name = str(frame) + '_' + str(ref_frame) + '.csv'
        """Lädt die Transformationsmatrix für ein bestimmtes Frame."""
        transformation_matrix = self.frame_handler.query_and_load_frame(csv_name)

        if transformation_matrix is not None:
            self.get_logger().info(f"Loaded matrix for frame '{csv_name}' successfully!")
            return transformation_matrix
        else:
            self.get_logger().error(f"Error while loading matrix for frame '{csv_name}'!")
            return None


    def hooks_dict_callback(self, msg):
        self.yolo_hooks_dict = self.hooks_dict_processor(msg)
        self.get_logger().info(f"Hooks_Dict: {self.yolo_hooks_dict}")

    



def main(args=None):
    rclpy.init(args=args)
    node = ScanBar()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
