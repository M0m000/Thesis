import rclpy
from vcnanoz_ros2.srv import StartVcstream  # Importiere den generierten Service

def main(args=None):
    rclpy.init(args=args)

    node = rclpy.create_node('ssh_service_client')
    client = node.create_client(StartVcstream, 'srv_startvcstream')

    # Warten, bis der Service verfügbar ist
    while not client.wait_for_service(timeout_sec=1.0):
        node.get_logger().info('Warte auf den Service...')

    # Anfrage erstellen und Parameter setzen
    request = StartVcstream.Request()
    request.ipv4 = "192.168.1.100"  # Ziel-IP-Adresse
    request.port = 22  # Ziel-Port (Standard-SSH-Port)

    # Anfrage senden und Antwort empfangen
    response = client.call(request)

    # Ausgabe der Antwort des Servers
    node.get_logger().info(f"Service antwortete: {response.result}")

    rclpy.shutdown()

if __name__ == '__main__':
    main()
