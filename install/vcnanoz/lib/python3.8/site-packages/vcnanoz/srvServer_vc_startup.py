import rclpy
from rclpy.node import Node
from vcnanoz.srv import StartVC
import paramiko
import time

class VCStartupServiceServer(Node):
    def __init__(self):
        super().__init__('vc_startup_service_server')
        self.srv = self.create_service(StartVC, 'start_vc', self.start_vc_callback)

    def start_vc_callback(self, request, response):
        self.get_logger().info('Service request received: Start VC Nano Z')

        # 30 Sekunden warten, um sicherzustellen, dass die Kamera hochgefahren ist
        self.get_logger().info('Warte 30 Sekunden, um sicherzustellen, dass die Kamera hochgefahren ist...')
        time.sleep(30)

        # SSH-Verbindung herstellen
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

        try:
            # Verbindung herstellen
            self.get_logger().info('Versuche, SSH-Verbindung zu 192.168.3.15 herzustellen...')
            ssh.connect('192.168.3.15', username='root', password='root')
            self.get_logger().info('SSH-Verbindung hergestellt.')

            # Erster Befehl ausführen (im Hintergrund)
            command1 = 'vcimgnetsrv &'
            self.get_logger().info(f'Sende Befehl: {command1}')
            ssh.exec_command(command1)
            self.get_logger().info(f'Befehl {command1} gesendet.')

            # 10 Sekunden warten
            self.get_logger().info('Warte 10 Sekunden...')
            time.sleep(10)

            # Zweiten Befehl ausführen
            command2 = 'vctp'
            self.get_logger().info(f'Sende Befehl: {command2}')
            stdin, stdout, stderr = ssh.exec_command(command2)
            
            # Ausgabe und Fehler abholen
            output = stdout.read().decode()
            error = stderr.read().decode()

            if output:
                self.get_logger().info(f'Befehl: {command2} Ausgabe: {output.strip()}')
            if error:
                self.get_logger().error(f'Befehl: {command2} Fehler: {error.strip()}')

            response.success = True
            response.message = 'VC Nano Z erfolgreich gestartet.'

        except Exception as e:
            self.get_logger().error(f'SSH-Fehler: {e}')
            response.success = False
            response.message = f'SSH-Fehler: {e}'

        finally:
            ssh.close()
            self.get_logger().info('SSH-Verbindung geschlossen.')

        return response

def main(args=None):
    rclpy.init(args=args)
    node = VCStartupServiceServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
