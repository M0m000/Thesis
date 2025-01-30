import rclpy
import numpy as np
import cv2
from rclpy.node import Node
from action_interfaces import HookData
from geometry_msgs.msg import PointStamped
from FC_tf_helper import TFHelper


class LocalTracking(Node):
    def __init__(self):
        super().__init__('local_tracking')

        self.hooks_dict_subscription = self.create_subscription(HookData, 'yolov8_output/hooks_dict', self.hooks_dict_callback, 10)
        self.hooks_dict_subscription
        self.hooks_dict = {}

