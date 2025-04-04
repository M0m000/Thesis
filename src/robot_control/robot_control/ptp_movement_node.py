import rclpy
from rclpy.node import Node
from example_interfaces.msg import Float64MultiArray
from kr_msgs.msg import RobotPose
from kr_msgs.msg import Number
import numpy as np

class PTPMovementNode(Node):
    def __init__(self):
        super().__init__('ptp_movement_node')
        self.pose_publisher = self.create_publisher(RobotPose, 'ptp_movements/cartesian_target_pose', 10)
        self.start_flag_publisher = self.create_publisher(Number, 'ptp_movements/start_flag', 10)
        timer_period = 0.001
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info("RobotPose Publisher gestartet")

    def timer_callback(self):
        msg = RobotPose()
        msg.pos = [111.38807096, 165.31715605, 892.60883048]  # Beispielwerte in mm
        msg.rot = [-9.10904006e+01, -9.34049597e-01, -2.65766291e-02]      # Beispielwerte in Grad

        self.pose_publisher.publish(msg)
        self.get_logger().info(f'Publiziert: pos={msg.pos}, rot={msg.rot}\n')


def main(args=None):
    rclpy.init(args=args)
    node = PTPMovementNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
