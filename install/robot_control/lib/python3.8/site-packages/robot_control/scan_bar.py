import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_tf_helper import TFHelper
from FC.FC_quaternion_to_euler import quaternion_to_euler
from FC.FC_dict_receive_processing import DictReceiveProcessor
from FC.FC_call_move_joint_service import call_move_joint_service
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
from tf2_ros import TransformException
from geometry_msgs.msg import TransformStamped


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

        self.tf_helper = TFHelper(node=self)
        self.future = self.tf_helper.lookup_transform(ref_frame="world", frame="work", callback=self.handle_transform)
        rclpy.spin_until_future_complete(self, self.future)

        '''
        # Startpunkt für Scan in WORLD berechnen
        startpoint_work_trans = [0.0, -300.0, 0.0]           # Translation in WORK
        startpoint_work_rot = [0.0, 0.0, 0.0, 1.0]           # Rotation in WORK (Quaternionen)
        startpoint_world_trans, startpoint_world_rot = self.tf_helper.transform_pose_to_world(startpoint_work_trans, 
                                                                                                        startpoint_work_rot, 
                                                                                                        from_frame='world', 
                                                                                                        to_frame='work')
        startpoint_world_rot = quaternion_to_euler(startpoint_world_rot)
        print(startpoint_world_rot)
        '''
        '''
        # Bewege Roboter auf die Startposition
        self.startpoint_movement_done = False
        if startpoint_world_rot is not None:
            self.startpoint_movement_done = call_move_joint_service(node = self,
                                                                    pos = startpoint_world_trans,
                                                                    rot = startpoint_world_rot,
                                                                    ref = 0,
                                                                    ttype = 0,
                                                                    tvalue = 30.0,
                                                                    bpoint = 0,
                                                                    btype = 0,
                                                                    bvalue = 100.0,
                                                                    sync = 0.0,
                                                                    chaining = 0)
        '''
    
    def handle_transform(self, transform: TransformStamped):
        """
        Callback, wenn die Transformation erfolgreich abgerufen wurde.
        """
        self.get_logger().info(f"Transformation erhalten: {transform}")
        self.world_to_work_transform = transform  # Speichere die Transformation
        self.process_start()

    def process_start(self):
        """
        Nächster Schritt im Ablauf.
        """
        if self.world_to_work_transform:
            self.get_logger().info("Die Transformation ist jetzt verfügbar. Fortfahren mit dem nächsten Prozess.")
        else:
            self.get_logger().warn("Transformation nicht verfügbar.")




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
