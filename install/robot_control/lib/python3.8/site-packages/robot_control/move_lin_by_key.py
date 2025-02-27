import rclpy
from rclpy.node import Node
from pynput import keyboard
from kr_msgs.msg import JogLinear
from kr_msgs.srv import SelectJoggingFrame


class MoveLinByKey(Node):
    def __init__(self):
        super().__init__('move_lin_by_key')

        self.declare_parameter('speed', 10.0)
        self.speed = self.get_parameter('speed').get_parameter_value().double_value

        self.declare_parameter('movement_frame', 'tcp')
        self.movement_frame = self.get_parameter('movement_frame').get_parameter_value().string_value

        self.client = self.create_client(SelectJoggingFrame, '/kr/motion/select_jogging_frame')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Wait for service SelectJoggingFrame...')
        self.get_logger().info('Service SelectJoggingFrame available!')
        
        ### Publisher für Twist Msg
        self.publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

        self.timer_period = 0.002  # Sekunden
        self.timer = self.create_timer(self.timer_period, self.publish_callback)

        self.jog_msg = JogLinear()
        self.jog_msg.vel = [0.0, 0.0, 0.0]

        self.set_frame_idx()
        self.call_service()     # rufe Service SelectJoggingFrame auf

    
    def call_service(self):
        request = SelectJoggingFrame.Request()
        request.ref = self.frame_idx if self.frame_idx is not None else 0
        future = self.client.call_async(request)
        future.add_done_callback(self.service_response_callback)

    def service_response_callback(self, future):
        try:
            response = future.result()
            if response.success:        # wenn Frame gesetzt -> Tastensteuerung kann beginnen
                self.get_logger().info('Jogging Frame Selection successful.')
                self.listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
                self.listener.start()
            else:
                self.get_logger().warn('Jogging Frame Selection failed!')
        except Exception as e:
            self.get_logger().error(f'Error Service-Call: {e}')


    def set_frame_idx(self):
        if self.movement_frame == 'world':
            self.frame_idx = 0
        elif self.movement_frame == 'base':
            self.frame_idx = 1
        elif self.movement_frame == 'tcp':
            self.frame_idx = 2


    def publish_callback(self):
        # self.get_logger().info(f"Publishing: {self.jog_msg}")
        self.publisher.publish(self.jog_msg)


    def on_press(self, key):
        try:
            if key.char == 'l':  # Bewegung in X_tcp
                self.jog_msg.vel = [self.speed, 0.0, 0.0]
                self.get_logger().info(f"Key 'l'   X_tcp   {self.speed} mm/s.")

            elif key.char == 'j':  # Bewegung in -X_tcp
                self.jog_msg.vel = [-self.speed, 0.0, 0.0]
                self.get_logger().info(f"Key 'j'   -X_tcp   {-self.speed} mm/s.")

            elif key.char == 'o':  # Bewegung in Y_tcp
                self.jog_msg.vel = [0.0, self.speed, 0.0]
                self.get_logger().info(f"Key 'i'   Y_tcp   {self.speed} mm/s.")

            elif key.char == 'n':  # Bewegung in -Y_tcp
                self.jog_msg.vel = [0.0, -self.speed, 0.0]
                self.get_logger().info(f"Key 'k'   -Y_tcp   {-self.speed} mm/s.")

            elif key.char == 'i':  # Bewegung in Z_tcp
                self.jog_msg.vel = [0.0, 0.0, self.speed]
                self.get_logger().info(f"Key 'n'   Z_tcp   {self.speed} mm/s.")

            elif key.char == 'k':  # Bewegung in -Z_tcp
                self.jog_msg.vel = [0.0, 0.0, -self.speed]
                self.get_logger().info(f"Key 'o'   -Z_tcp   {-self.speed} mm/s.")

        except AttributeError:
            self.get_logger().info(f"Taste {key} gedrückt")

    def on_release(self, key):
        self.jog_msg.vel = [0.0, 0.0, 0.0]  # Roboter stoppt

def main(args=None):
    rclpy.init(args=args)
    move_lin_by_key = MoveLinByKey()
    rclpy.spin(move_lin_by_key)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

