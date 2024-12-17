import rclpy
from rclpy.node import Node
from kr_msgs.srv import StartVC

class VCStartupServiceClient(Node):
    def __init__(self):
        super().__init__('vc_startup_service_client')
        self.cli = self.create_client(StartVC, 'start_vc')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warte auf Service /start_vc...')
        self.req = StartVC.Request()

    def send_request(self):
        self.get_logger().info('Sende Anfrage an Service /start_vc...')
        future = self.cli.call_async(self.req)
        future.add_done_callback(self.service_response_callback)

    def service_response_callback(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f'Service erfolgreich ausgeführt: {response.message}')
            else:
                self.get_logger().error(f'Service fehlgeschlagen: {response.message}')
        except Exception as e:
            self.get_logger().error(f'Service-Aufruf fehlgeschlagen: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = VCStartupServiceClient()
    node.send_request()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
