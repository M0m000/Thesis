from kr_msgs.msg import JogLinear
import rclpy
from rclpy.node import Node

class MoveLinearByKey(Node):
    def __init__(self):
        super().__init__('move_linear_by_key')
        # self.publisher_ = self.create_publisher(Twist, 'robot/tcp_command', 10)
        self.timer = self.create_timer(0.1, self.send_command)
        self.jog_linear = JogLinear()

    def send_command(self):
        # Publish the current twist command
        # self.publisher_.publish(self.current_twist)
        print('send_command')


def main(args=None):
    rclpy.init(args=args)
    node = MoveLinearByKey()
    node.run()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
