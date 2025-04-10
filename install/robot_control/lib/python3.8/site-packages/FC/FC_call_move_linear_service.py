import rclpy
from rclpy.node import Node
from kr_msgs.srv import MoveLinear
from time import time

class MoveLinearServiceClient(Node):
    def __init__(self):
        super().__init__('move_linear_service_client')
        self.client = self.create_client(MoveLinear, '/kr/motion/move_linear')

    def call_move_linear_service(self, pos, rot, ttype, tvalue, bpoint, btype, bvalue, sync, chaining):
        # Warte, bis der Service verfügbar ist
        while not self.client.wait_for_service(timeout_sec = 1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.get_logger().info('Service MoveLinear available, making service call...')
        
        # Erstelle Service Request
        request = MoveLinear.Request()
        request.pos = pos
        request.rot = rot
        request.ttype = ttype
        request.tvalue = tvalue
        request.bpoint = bpoint
        request.btype = btype
        request.bvalue = bvalue
        request.sync = sync
        request.chaining = chaining

        # Sende Service-Request und warte auf Antwort
        start_time = time()
        while True:
            future = self.client.call_async(request)
            rclpy.spin_until_future_complete(self, future)
            
            if future.result() is not None:
                # Warte auf eine erfolgreiche Antwort (success=True)
                if future.result().success:
                    self.get_logger().info("Movement completed successfully")
                    return True  # Erfolgreiche Bewegung
                else:
                    self.get_logger().warn("Movement failed!")
                    return False  # Bewegung fehlgeschlagen
            elif time() - start_time > 10:  # Timeout nach 10 Sekunden
                self.get_logger().warn("Service call timed out!")
                return False  # Timeout, falls keine Antwort innerhalb von 10 Sekunden
