import rclpy
from rclpy.node import Node
from example_interfaces.srv import SetBool  # SetBool ist ein Platzhalter, ersetzt dies mit deiner richtigen Service-Schnittstelle
from vcnanoz_ros2.srv import StartVcstream  # Importiere den generierten Service
import paramiko
import time

class SSHService(Node):
    def __init__(self):
        super().__init__('ssh_service_node')

        # Service einrichten
        self.srv = self.create_service(StartVcstream, 'srv_startvcstream', self.start_vcstream_callback)
        self.get_logger().info("Service 'srv_startvcstream' bereit")

    def start_vcstream_callback(self, request, response):
        # Verbindungsparameter von der Anfrage
        hostname = request.ipv4  # IP-Adresse vom Client
        port = request.port  # Port vom Client
        username = "dein_benutzername"
        password = "dein_passwort"

        # Die Befehle
        command_1 = "echo 'Erster Befehl ausgeführt'"
        command_2 = "echo 'Zweiter Befehl ausgeführt'"

        try:
            # SSH-Client erstellen
            ssh = paramiko.SSHClient()
            ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())  # Unbekannte Hosts automatisch akzeptieren
            
            # Verbindung herstellen
            ssh.connect(hostname, port, username, password)
            self.get_logger().info(f"Erfolgreich mit {hostname} verbunden.")

            # Ersten Befehl ausführen
            self.get_logger().info(f"Führe Command_1 aus: {command_1}")
            stdin, stdout, stderr = ssh.exec_command(command_1)
            self.get_logger().info(stdout.read().decode())  # Ausgabe des ersten Befehls
            self.get_logger().info(stderr.read().decode())  # Fehler des ersten Befehls (falls vorhanden)

            # Verzögerung
            time.sleep(2)

            # Zweiten Befehl ausführen
            self.get_logger().info(f"Führe Command_2 aus: {command_2}")
            stdin, stdout, stderr = ssh.exec_command(command_2)
            self.get_logger().info(stdout.read().decode())  # Ausgabe des zweiten Befehls
            self.get_logger().info(stderr.read().decode())  # Fehler des zweiten Befehls (falls vorhanden)

            # Verbindung schließen
            ssh.close()
            self.get_logger().info("Verbindung geschlossen.")

            response.result = "Befehle erfolgreich ausgeführt."

        except Exception as e:
            self.get_logger().error(f"Fehler bei der Ausführung des Befehls: {e}")
            response.result = f"Fehler: {e}"

        return response

def main(args=None):
    rclpy.init(args=args)
    node = SSHService()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
