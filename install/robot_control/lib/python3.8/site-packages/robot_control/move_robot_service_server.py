from kr_msgs.srv import MoveTCPAlongAxis
import rclpy
from rclpy.node import Node

class MoveRobotServiceServer(Node):
    def __init__(self):
        super().__init__('move_robot_service')
        self.srv = self.create_service(MoveTCPAlongAxis, 'move_tcp_along_axis', self.move_robot_callback)
        self.get_logger().info("MoveRobotServiceServer started.")
        self.response = None
        self.timer = None

    def move_robot_callback(self, request, response):
        self.get_logger().info(f"Received request: Moving {request.baseline} along {request.axis} axis")
        
        # Speichere die Antwort und starte den Timer
        self.response = response
        self.timer = self.create_timer(5.0, self.send_response)

        # Blockiere die Antwort, sie wird später im Timer zurückgesendet
        return response

    def send_response(self):
        if self.response is not None:
            # Erfolg zurückgeben
            self.response.success = True
            self.get_logger().info("5 seconds elapsed. Sending response: Success.")
            self.timer.cancel()  # Stoppe den Timer

def main(args=None):
    rclpy.init(args=args)
    move_robot_service = MoveRobotServiceServer()

    try:
        rclpy.spin(move_robot_service)
    except KeyboardInterrupt:
        move_robot_service.get_logger().info("Shutting down MoveRobotServiceServer.")
    finally:
        move_robot_service.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
