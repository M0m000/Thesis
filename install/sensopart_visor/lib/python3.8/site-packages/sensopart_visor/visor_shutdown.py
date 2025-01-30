import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetDiscreteOutput
import time

class VisorShutdownNode(Node):
    def __init__(self):
        super().__init__('visor_shutdown')
        self.client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')

        # Warten, bis der Service verfügbar ist
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('wait for service SetDigitalOutput...')
        
        self.call_service()

    def call_service(self):
        request = SetDiscreteOutput.Request()
        request.index = 2
        request.value = 0

        future = self.client.call_async(request)
        future.add_done_callback(self.service_response_callback)

    def service_response_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f'Service call successful: {response}')

            time.sleep(3)
            self.shutdown_node()
        
        except Exception as e:
            self.get_logger().error(f'Service-Aufruf fehlgeschlagen: {e}')

    def shutdown_node(self):
        self.get_logger().info('Shutting down node...')
        self.destroy_node()
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    node = VisorShutdownNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()

if __name__ == '__name__':
    main()
