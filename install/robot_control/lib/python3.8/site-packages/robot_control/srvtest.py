import rclpy
from rclpy.node import Node
from kr_msgs.srv import MoveTCPAlongAxis

class Srvtest(Node):
    def __init__(self):
        super().__init__('srvtest')
        
        # Service-Client für den Service "move_tcp_along_axis" erstellen
        self.client = self.create_client(MoveTCPAlongAxis, 'move_tcp_along_axis')

        # Warten, bis der Service verfügbar ist
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        
        # Service-Anfrage auslösen
        self.call_service(100.0, 'x')  # Beispielwerte: 100 mm und Achse 'x'

    def call_service(self, baseline, axis):
        # Anfrage erstellen
        request = MoveTCPAlongAxis.Request()
        request.baseline = baseline
        request.frame = "base_link"  # Hier könnte auch ein anderes Koordinatensystem verwendet werden
        request.axis = axis
        
        # Asynchronen Service-Aufruf starten
        future = self.client.call_async(request)

        # Warten auf das Ergebnis
        rclpy.spin_until_future_complete(self, future)
        
        if future.result() is not None:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Successfully moved robot by {baseline} mm along {axis}-axis.")
            else:
                self.get_logger().error(f"Failed to move robot along {axis}-axis.")
        else:
            self.get_logger().error('Service call failed')

def main(args=None):
    rclpy.init(args=args)
    
    move_robot_node = Srvtest()
    
    rclpy.spin(move_robot_node)
    
    # Beim Beenden des Knotens
    move_robot_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
