import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

class ReadDeltaTransformation(Node):
    def __init__(self):
        super().__init__('read_delta_transformation')
        
        self.depth_subscription = self.create_subscription(Image, '/robot_control/transformation_snapshot', self.callback, 10)
        
        self.bridge = CvBridge()
        self.diff_vector = None
    
    def callback(self, msg):
        self.diff_vector = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        self.get_logger().info(f"Transformation Snapshot: {self.diff_vector}")

def main(args=None):
    rclpy.init(args=args)
    node = ReadDeltaTransformation()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()