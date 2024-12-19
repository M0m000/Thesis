import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetDiscreteOutput
import paramiko
import time

class VCStartupNode(Node):
    def __init__(self):
        super().__init__('vc_startup')
        self.client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')

        # Warten, bis der Service verfügbar ist
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('wait for service SetDigitalOutput...')

        self.call_service()

    def call_service(self):
        # Anfrage erstellen
        request = SetDiscreteOutput.Request()
        request.index = 1
        request.value = 1

        # Service-Aufruf durchführen
        future = self.client.call_async(request)
        future.add_done_callback(self.service_response_callback)

    def service_response_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f'Service call successful: {response}')

            # 30 Sekunden warten, bevor die SSH-Befehle ausgeführt werden
            self.get_logger().info('wait for 30 sec - boot time VC nano Z ...')
            time.sleep(30)
            self.execute_ssh_commands()

        except Exception as e:
            self.get_logger().error(f'Service-Aufruf fehlgeschlagen: {e}')

    def execute_ssh_commands(self):
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    
        try:
            # Verbindung herstellen
            self.get_logger().info('Try SSH connection to 192.168.3.15 ...')
            ssh.connect('192.168.3.15', username='root', password='root')
            self.get_logger().info('SSH connected.')
    
            # Erster Befehl ausführen (im Hintergrund)
            command1 = 'vcimgnetsrv &'
            self.get_logger().info(f'Send command: {command1}')
            ssh.exec_command(command1)
            self.get_logger().info(f'Command {command1} sent.')
    
            # 10 Sekunden warten
            self.get_logger().info('wait for 10 sec...')
            time.sleep(10)
    
            # Zweiten Befehl ausführen und Ausgabe lesen
            command2 = 'vctp -s 25000'
            self.get_logger().info(f'Send command: {command2}')
            stdin, stdout, stderr = ssh.exec_command(command2)
    
            # Ausgabe und Fehler kontinuierlich lesen
            self.get_logger().info('Reading command output...')
            while True:
                output_line = stdout.readline()
                if output_line:
                    self.get_logger().info(f'Command Output: {output_line.strip()}')
                error_line = stderr.readline()
                if error_line:
                    self.get_logger().error(f'Command Error: {error_line.strip()}')
                if not output_line and not error_line:
                    break
                
        except Exception as e:
            self.get_logger().error(f'SSH-ERROR: {e}')
    
        finally:
            ssh.close()
            self.get_logger().info('SSH-Connection closed.')


    def shutdown_node(self):
        self.get_logger().info('Shutting down node...')
        self.destroy_node()
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    node = VCStartupNode()

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
