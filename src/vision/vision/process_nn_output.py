import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from sensor_msgs.msg import String
from cv_bridge import CvBridge
import numpy as np
import torch
import cv2
from ultralytics import YOLO
import time
import os
import sys
import matplotlib.pyplot as plt
import json


class ProcessNNOutputNode(Node):
    def __init__(self):
        super().__init__('process_nn_output')

        self.declare_parameter('print_output_dict', True)
        self.print_output_dict = self.get_parameter('print_output_dict').get_parameter_value().bool_value
        self.declare_parameter('bar_dict_topic', 'yolov8_output/bar_dict')
        self.bar_dict_topic = self.get_parameter('bar_dict_topic').get_parameter_value().string_value
        self.declare_parameter('hooks_dict_topic', 'yolov8_output/hooks_dict')
        self.hooks_dict_topic = self.get_parameter('hooks_dict_topic').get_parameter_value().string_value

        # Subscriber auf NN Output Dicts
        self.bar_dict_subscription = self.create_subscription(Image, 'yolov8_out/bar_dict', self.output_bar_dict_received_callback, 10)
        self.bar_dict_subscription
        self.hooks_dict_subscription = self.create_subscription(Image, 'yolov8_out/hooks_dict', self.output_hooks_dict_received_callback, 10)
        self.hooks_dict_subscription
        self.subscription = self.create_subscription(Image, 'vcnanoz/image_raw', self.image_callback, 1)
        self.subscription

        self.bar_dict_publisher = self.create_publisher(dict, 'yolov8_out/bar_dict_processed', 10)
        self.hook_dict_publisher = self.create_publisher(dict, 'yolov8_out/hooks_dict_processed', 10)
        self.publisher_timer = self.create_timer(0.001, self.publisher_callback)

        self.get_logger().info('NN Output Process Node started...')

        self.bar_dict = {}
        self.bar_dict_processed = {}
        self.hooks_dict = {}
        self.hooks_dict_processed = {}
        
        self.points_img = None
        self.received_img = None
    

    def image_callback(self, msg):
        try:
            self.received_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        except Exception as e:
            self.get_logger().error(f'Error in image preprocessing: {e}')
    
    
    def deserialize_json_string(self, msg):
        try:
            data_dict = json.loads(msg.data)
            return data_dict
        except json.JSONDecodeError as e:
            self.get_logger().error(f"Error at parsing JSON string: {e}")

    
    def output_bar_dict_received_callback(self, msg):
        self.bar_dict = msg
    

    def output_hooks_dict_received_callback(self, msg):
        self.hooks_dict = msg
        self.process_output_hooks_dict()
        print(self.hooks_dict)
        
        if self.show_plot:
            self.points_img = self.plot_points()
            cv2.imshow('Points in Output', self.points_img)
            cv2.waitKey(1)


    def process_output_hooks_dict(self):
        self.hooks_dict_processed = self.hooks_dict.copy()

        for idx, key in enumerate(self.hooks_dict):
            hook_mask = self.hooks_dict[key].get('hook_mask', [])
            tip_mask = self.hooks_dict[key].get('tip_mask', [])
            lowpoint_mask = self.hooks_dict[key].get('lowpoint_mask', [])

            uv_hook = self.calc_mean_of_mask(hook_mask)
            uv_tip = self.calc_mean_of_mask(tip_mask)
            uv_lowpoint = self.calc_mean_of_mask(lowpoint_mask)

            self.hooks_dict_processed[key]['uv_hook'] = uv_hook
            self.hooks_dict_processed[key]['uv_tip'] = uv_tip
            self.hooks_dict_processed[key]['uv_lowpoint'] = uv_lowpoint

    
    def calc_mean_of_mask(self, mask):
        ys, xs = np.where(mask == 1)
        cx = np.mean(xs)
        cy = np.mean(ys)
        return [cx, cy]
    

    def plot_points(self):
        img_copy = self.received_img.copy()
        for idx, key in enumerate(self.hooks_dict_processed):
            if self.hooks_dict_processed[key]['hook_box'] is not None:
                bb_hook = tuple(map(int, self.hooks_dict_processed[key]['hook_box']))
                cv2.rectangle(img_copy, (bb_hook[0], bb_hook[1]), (bb_hook[2], bb_hook[3]), (150, 150, 150), 2)
            if self.hooks_dict_processed[key]['uv_hook'] is not None:
                p_hook = tuple(map(int, self.hooks_dict_processed[key]['uv_hook']))
                cv2.drawMarker(img_copy, p_hook, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict_processed[key]['uv_tip'] is not None:
                p_tip = tuple(map(int, self.hooks_dict_processed[key]['uv_tip']))
                cv2.drawMarker(img_copy, p_tip, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict_processed[key]['uv_lowpoint'] is not None:
                p_lowpoint = tuple(map(int, self.hooks_dict_processed[key]['uv_lowpoint']))
                cv2.drawMarker(img_copy, p_lowpoint, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)  
        return img_copy


    def publisher_callback(self):
        if self.bar_dict_processed is not None:
            bar_dict_string = json.dumps(self.bar_dict_processed)
            msg_bar = String()
            msg_bar.data = bar_dict_string
            self.bar_dict_publisher._publish(msg_bar)
            self.get_logger().info("Output -> Bar Dict Processed published...")
        if self.hooks_dict_processed is not None:
            hooks_dict_string = json.dumps(self.hooks_dict_processed)
            msg_hooks = String()
            msg_hooks.data = hooks_dict_string
            self.hooks_dict_publisher._publish(msg_hooks)
            self.get_logger().info("Output -> Hooks Dict Processed published...")


def main(args=None):
    rclpy.init(args=args)

    node = ProcessNNOutputNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('shutting down Process NN Output node...')
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()

