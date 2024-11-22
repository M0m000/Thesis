import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetCustomFrame

class SetFrameClient(Node):
    def __init__(self):
        super().__init__('set_frame_client')

        self.declare_parameter('ref', 2)  # TCP (ID = 2)
        self.declare_parameter('pos', [0.0, 0.0, 0.0])  # Default-Position
        self.declare_parameter('rot', [0.0, 0.0, 0.0])  # Default-Orientierung
        self.ref = self.get_parameter('ref').get_parameter_value().integer_value
        self.pos = self.get_parameter('pos').get_parameter_value().double_array_value
        self.rot = self.get_parameter('rot').get_parameter_value().double_array_value

        self.client = self.create_client(SetCustomFrame, '/kr/motion/set_custom_frame')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Warten auf Service SetCustomFrame')
        self.send_request()

    def send_request(self):
        request = SetCustomFrame.Request()
        request.ref = self.ref
        request.pos = [float(v) for v in self.pos]
        request.rot = [float(v) for v in self.rot]


        self.get_logger().info(f"Request: ref_system_ID={request.ref}, pos={request.pos}, rot={request.rot}")

        future = self.client.call_async(request)
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('Benutzerdefiniertes System erfolgreich hinzugefügt.')
            else:
                self.get_logger().warning('Fehler beim Hinzufügen des benutzerdefinierten Systems.')
        except Exception as e:
            self.get_logger().error(f'Service-Aufruf fehlgeschlagen: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = SetFrameClient()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
