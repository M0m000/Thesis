import rclpy
from rclpy.node import Node
from pynput import keyboard
from kr_msgs.msg import JogLinear


class MoveLinByKey(Node):
    def __init__(self):
        super().__init__('move_lin_by_key')

        self.declare_parameter('speed', 10.0)
        self.speed = self.get_parameter('speed').get_parameter_value().double_value

        self.publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

        self.timer_period = 0.002  # Sekunden
        self.timer = self.create_timer(self.timer_period, self.publish_callback)

        self.listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.listener.start()

        self.jog_msg = JogLinear()
        self.jog_msg.vel = [0.0, 0.0, 0.0]

    def publish_callback(self):
        self.get_logger().info(f"Publishing: {self.jog_msg}")
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

