from kr_msgs.srv import MoveTCPAlongAxis
import rclpy
from rclpy.node import Node

class MoveRobotServiceClient(Node):
    def __init__(self):
        super().__init__('move_robot_service_client')
        self.cli = self.create_client(MoveTCPAlongAxis, 'move_tcp_along_axis')

        # Warte darauf, dass der Service verfügbar wird
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')

    def call_service(self, baseline, axis):
        request = MoveTCPAlongAxis.Request()
        request.baseline = baseline
        request.axis = axis
        future = self.cli.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        
        if future.result() is not None:
            self.get_logger().info(f"Service response: {future.result().success}")
            return future.result().success
        else:
            self.get_logger().error("Service call failed")
            return False

def main(args=None):
    rclpy.init(args=args)
    move_robot_service_client = MoveRobotServiceClient()

    # Beispielaufruf des Services
    success = move_robot_service_client.call_service(10.0, 'x')
    if success:
        move_robot_service_client.get_logger().info("Movement successful!")
    else:
        move_robot_service_client.get_logger().info("Movement failed!")

    rclpy.shutdown()

if __name__ == '__main__':
    main()
