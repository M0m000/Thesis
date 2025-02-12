import rclpy
from rclpy.node import Node
from action_interfaces.msg import HookData
from FC.FC_dict_receive_processing import DictReceiveProcessor
from FC.FC_call_move_linear_service import MoveLinearServiceClient
from FC.FC_edge_detector import EdgeDetector
from FC.FC_frame_handler import FrameHandler
from FC.FC_stereo_triangulation_processor import StereoTriangulationProcessor
from FC.FC_save_load_global_hook_dict import save_dict_to_csv, load_csv_to_dict
from FC.FC_geometrics_handler import GeometricsHandler
from kr_msgs.msg import JogLinear
import os
import time
import numpy as np
import csv


class DummyNode(Node):
    def __init__(self):
        super().__init__('_dummy_node')
        self.geometrics_handler = GeometricsHandler()

        self.hook = self.geometrics_handler.get_hook_of_global_scan_dict(hook_num = 2)
        self.geometrics_handler.update_hook_data(hook_num = 1)
        self.geometrics_handler.calculate_hook_line()
        




def main(args=None):
    rclpy.init(args=args)
    node = DummyNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
