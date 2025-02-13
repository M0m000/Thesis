import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetDiscreteOutput, SetAnalogOutput
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

        self.light_vcc_on = False
        self.light_set_brightness_done = False

        max_wait_time = 10

        # Warten, bis Service für DigOut verfügbar
        start_time = time.time()
        while not self.discrete_output_client.wait_for_service(timeout_sec=1.0):
            if time.time() - start_time > max_wait_time:
                self.get_logger().error('Service SetDigitalOutput not available! - continuing...')
                break
            self.get_logger().info('Waiting for Service SetDigitalOutput...')
        
        # Warten, bis Service für AnalogOut verfügbar
        start_time = time.time()
        while not self.analog_output_client.wait_for_service(timeout_sec=1.0):
            if time.time() - start_time > max_wait_time:
                self.get_logger().error('Service SetAnalogOutput not available! - continuing...')
                break
            self.get_logger().info('Waiting for Service SetAnalogOutput...')

        # Kamera und Beleuchtung starten
        self.powerup_vc()
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
        request_vcc.index = 3
        request_vcc.value = 1
        self.discrete_output_client.call_async(request_vcc)

        request_brightness = SetAnalogOutput.Request()
        request_brightness.index = 1
        request_brightness.value = 9.0
        self.analog_output_client.call_async(request_brightness)

    def cam_powerup_done_callback(self, future):
        try:
            response = future.result()
            self.get_logger().info("Wait for 20 sec - boot time VC nano Z ...")
            time.sleep(20)
            self.execute_ssh_commands()
        except Exception as e:
            self.get_logger().error(f'Service-Call failed: {e}')
            self.shutdown_node()

    def execute_ssh_commands(self):
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

        try:
            self.get_logger().info('Try SSH connection to 192.168.3.15 ...')
            ssh.connect('192.168.3.15', username='root', password='root')
            self.get_logger().info('SSH connected.')

            command1 = 'vcimgnetsrv &'
            self.get_logger().info(f'Send command: {command1}')
            ssh.exec_command(command1)
            self.get_logger().info(f'Command {command1} sent.')

            self.get_logger().info('Wait for 10 sec...')
            time.sleep(10)

            command2 = f'vctp -s {self.shutter_time} -g {self.gain}'
            self.get_logger().info(f'Send command: {command2}')
            stdin, stdout, stderr = ssh.exec_command(command2)

            self.get_logger().info('Reading command output...')
            while True:
                output_line = stdout.readline()
                if output_line:
                    self.get_logger().info(f'Command Output: {output_line.strip()}')
                    self.get_logger().info("VC nano Z powered up and streaming...")
                    break
                error_line = stderr.readline()
                if error_line:
                    self.get_logger().error(f'Command Error: {error_line.strip()}')
                    break
                if not output_line and not error_line:
                    break
            

        except Exception as e:
            self.get_logger().error(f'SSH-ERROR: {e}')
        '''
        finally:
            ssh.close()
            self.get_logger().info('SSH-Connection closed.')
            self.shutdown_node()
        '''

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
