import rclpy
from rclpy.node import Node
from kr_msgs.srv import MoveTCPAlongAxis  # Der Service-Typ aus kr_msgs

class SrvCallClient(Node):
    def __init__(self):
        super().__init__('srv_call_client')
        self.cli = self.create_client(MoveTCPAlongAxis, 'move_tcp_along_axis')

        # Warten darauf, dass der Service verfügbar wird
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')

    def call_service(self, baseline, frame, axis):
        request = MoveTCPAlongAxis.Request()
        request.baseline = baseline
        request.frame = frame
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
    srv_call_client = SrvCallClient()

    # Beispielaufruf des Services
    success = srv_call_client.call_service(10.0, 'world', 'x')
    if success:
        srv_call_client.get_logger().info("Movement successful!")
    else:
        srv_call_client.get_logger().info("Movement failed!")

    rclpy.shutdown()


if __name__ == '__main__':
    main()
