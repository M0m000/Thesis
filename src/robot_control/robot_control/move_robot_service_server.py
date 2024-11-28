from kr_msgs.srv import MoveTCPAlongAxis
import rclpy
from rclpy.node import Node

class MoveRobotServiceServer(Node):
    def __init__(self):
        super().__init__('move_robot_service')
        self.srv = self.create_service(MoveTCPAlongAxis, 'move_tcp_along_axis', self.move_robot_callback)
    
    def move_robot_callback(self, request, response):
        self.get_logger().info(f"Moving {request.baseline} along {request.axis} axis")
        response.success = True  # Simuliere eine erfolgreiche Antwort
        return response

def main(args=None):
    rclpy.init(args=args)
    move_robot_service = MoveRobotServiceServer()
    rclpy.spin(move_robot_service)

if __name__ == '__main__':
    main()
