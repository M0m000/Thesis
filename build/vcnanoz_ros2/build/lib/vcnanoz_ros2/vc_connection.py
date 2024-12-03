import rclpy
from rclpy.node import Node

import socket
import os
import struct
import logging
import time
from itertools import chain
from PIL import Image
import numpy as np


class VCConnection(Node):
    def __init__(self):
        super().__init__('vc_connection')
        self.get_logger().info('Starting ROS2 Connection to VCnanoZ')

        self.declare_parameter('ipv4', '192.168.3.15')
        self.ipv4 = self.get_parameter('ipv4').get_parameter_value().string_value
        self.declare_parameter('port', 2002)
        self.port = self.get_parameter('port').get_parameter_value().integer_value

        self.get_logger().info(f'IPv4: {self.ipv4} - Port: {self.port}')


def main(args=None):
    rclpy.init(args=args)
    node = VCConnection()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
