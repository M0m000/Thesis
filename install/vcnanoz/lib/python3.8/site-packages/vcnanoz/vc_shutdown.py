import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetDiscreteOutput
import paramiko
import time

class VCShutdownNode(Node):
    def __init__(self):
        super().__init__('vc_shutdown')
        self.client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')
        self.ssh_client = paramiko.SSHClient()
        self.ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

        self.execute_ssh_shutdown()

    def execute_ssh_shutdown(self):
        try:
            # Verbindung herstellen
            self.get_logger().info('Connecting to SSH root@192.168.3.15...')
            self.ssh_client.connect('192.168.3.15', username='root', password='root')
            self.get_logger().info('SSH connection established.')

            # Shutdown-Befehl senden
            command = 'shutdown -h 0'
            self.get_logger().info(f'Sending command: {command}')
            self.ssh_client.exec_command(command)

            # Warten, bis die Verbindung geschlossen wird
            self.get_logger().info('Waiting for remote host to shut down...')
            while True:
                try:
                    transport = self.ssh_client.get_transport()
                    if transport is None or not transport.is_active():
                        self.get_logger().info('SSH connection closed by remote host.')
                        break
                    time.sleep(1)
                except Exception:
                    self.get_logger().info('Error while checking SSH connection status. Assuming closed.')
                    break

            # 10 Sekunden warten
            self.get_logger().info('Waiting for 10 seconds after SSH disconnection...')
            time.sleep(10)

        except Exception as e:
            self.get_logger().error(f'SSH connection failed: {e}')

        finally:
            self.ssh_client.close()
            self.get_logger().info('SSH client closed.')
            # Nach dem Schließen der SSH-Verbindung den Service aufrufen
            self.call_service()

    def call_service(self):
        # Anfrage erstellen
        request = SetDiscreteOutput.Request()
        request.index = 1
        request.value = 0

        # Warten, bis der Service verfügbar ist
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service SetDigitalOutput...')
        self.get_logger().info('Service SetDigitalOutput available!')

        # Service-Aufruf durchführen
        self.get_logger().info(f'Reset Digital Output...')
        future = self.client.call_async(request)
        future.add_done_callback(self.service_response_callback)

    def service_response_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f'Service call successful: {response}')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')
        finally:
            self.shutdown_node()

    def shutdown_node(self):
        self.get_logger().info('Shutting down vc_shutdown node...')
        self.destroy_node()
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    node = VCShutdownNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    main()
