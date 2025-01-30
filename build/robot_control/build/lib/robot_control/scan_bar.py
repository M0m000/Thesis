import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from geometry_msgs.msg import Vector3, Quaternion
from FC_tf_helper import TFHelper
from FC_quaternion_to_euler import quaternion_to_euler
from FC_dict_receive_processing import DictReceiveProcessor


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

        # Instanz TFHelper-Klasse
        self.tf_helper = TFHelper(self)
        self.world_to_work_transform = self.get_transform(frame="work", ref_frame="world")

        # Startpunkt für Scan in WORLD berechnen
        startpoint_work_trans = [0.0, 200.0, -300.0]           # Translation in WORK
        startpoint_work_rot = [0.0, 0.0, 0.0, 1.0]             # Rotation in WORK (Quaternionen)
        self.startpoint_world_trans, self.startpoint_world_rot = self.tf_helper.transform_pose_to_world(startpoint_work_trans, 
                                                                                                        startpoint_work_rot, 
                                                                                                        from_frame="work", 
                                                                                                        to_frame="world")
        self.startpoint_world_rot = quaternion_to_euler(self.startpoint_world_rot)

    

    def get_transform(self, frame="tcp", ref_frame="world"):
        transform = self.tf_helper.lookup_transform(frame, ref_frame)
        if transform:
            self.get_logger().info(f"Transformation '{frame}' to '{ref_frame}' found!")
            return transform
        else:
            self.get_logger().error(f"Transformation '{frame}' to '{ref_frame}' not found!")
            return None

    def hooks_dict_callback(self, msg):
        self.yolo_hooks_dict = self.hooks_dict_processor(msg)
        self.get_logger().info(f"Hooks_Dict: {self.hooks_dict}")


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
