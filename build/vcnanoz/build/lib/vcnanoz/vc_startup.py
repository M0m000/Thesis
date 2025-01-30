import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetDiscreteOutput
from kr_msgs.srv import SetAnalogOutput
import paramiko
import time

class VCStartupNode(Node):
    def __init__(self):
        super().__init__('vc_startup')
        self.discrete_output_client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')
        self.analog_output_client = self.create_client(SetAnalogOutput, '/kr/iob/set_voltage_output')

        self.declare_parameter('shutter_time', 20000)
        self.shutter_time = self.get_parameter('shutter_time').get_parameter_value().integer_value
        self.declare_parameter('gain', 1)
        self.gain = self.get_parameter('gain').get_parameter_value().integer_value

        discrete_out_srv_available = False
        analog_out_srv_available = False
        self.light_vcc_on = False
        self.light_set_brightness_done = False

        max_wait_time = 10

        # Warten, bis Service für DigOut verfügbar
        start_time = time.time()
        while not self.discrete_output_client.wait_for_service(timeout_sec=1.0):
            elapsed_time = time.time() - start_time
            if elapsed_time > max_wait_time:
                self.get_logger().error('Service SetDigitalOutput not available! - conitnuing...')
                break
            self.get_logger().info('Waiting for Service SetDigitalOutput...')
        else:
            discrete_out_srv_available = True

        # Warten, bis Service für AnalogOut verfügbar
        start_time = time.time()
        while not self.analog_output_client.wait_for_service(timeout_sec=1.0):
            elapsed_time = time.time() - start_time
            if elapsed_time > max_wait_time:
                self.get_logger().error('Service SetAnalogOutput not available! - conitnuing...')
                break
            self.get_logger().info('Waiting for Service SetAnalogOutput...')
        else:
            analog_out_srv_available = True

        # wenn Services verfügbar -> Kamera und Beleuchtung starten
        if discrete_out_srv_available:
            self.powerup_vc()
        if discrete_out_srv_available and analog_out_srv_available:
            self.powerup_light()
        
    def powerup_vc(self):
        self.get_logger().info("Power Up VC nano Z...")
        request = SetDiscreteOutput.Request()
        request.index = 1
        request.value = 1
        future = self.discrete_output_client.call_async(request)
        future.add_done_callback(self.cam_powerup_done_callback)

    def powerup_light(self):
        self.get_logger().info("Power Up camera light...")
        request_vcc = SetDiscreteOutput.Request()
        request_vcc.index = 3       # DOut 3
        request_vcc.value = 1
        future = self.discrete_output_client.call_async(request_vcc)
        future.add_done_callback(self.light_powerup_vcc_done_callback)

        request_brightness = SetAnalogOutput.Request()
        request_brightness.index = 1        # AOut 1
        request_brightness.value = 9.0      # 90% Helligkeit
        future = self.analog_output_client.call_async(request_brightness)
        future.add_done_callback(self.light_set_brightness_done_callback)

        if self.light_vcc_on and self.light_set_brightness_done:
            self.get_logger().info("Power Up camera light done!")

    def light_powerup_vcc_done_callback(self, future):
        response = future.result()
        if response:
            self.light_vcc_on = True
        else:
            self.light_vcc_on = False
    
    def light_set_brightness_done_callback(self, future):
        response = future.result()
        if response:
            self.light_set_brightness_done = True
        else:
            self.light_set_brightness_done = False

    def cam_powerup_done_callback(self, future):
        try:
            response = future.result()
            # 20 Sekunden warten, bevor die SSH-Befehle ausgeführt werden -> Bootzeit
            self.get_logger().info("wait for 20 sec - boot time VC nano Z ...")
            time.sleep(20)
            self.execute_ssh_commands()
            self.get_logger().info("VC nano Z powered up and streaming...")

        except Exception as e:
            self.get_logger().error(f'Service-Call failed: {e}')

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
            command2 = 'vctp -s '+ str(self.shutter_time) + ' -g ' + str(self.gain)
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
