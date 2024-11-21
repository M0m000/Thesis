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
        self.publisher.publish(self.jog_msg)

    def on_press(self, key):
        try:
            if key == keyboard.Key.right:
                self.jog_msg.vel = [self.speed, 0.0, 0.0]  # Geschwindigkeit in x-Richtung
                self.get_logger().info(f"Pfeiltaste nach rechts gedrückt! Roboter bewegt sich mit {self.speed} mm/s in x-Richtung.")

            elif key == keyboard.Key.left:
                self.jog_msg.vel = [-self.speed, 0.0, 0.0]  # Geschwindigkeit in negative x-Richtung
                self.get_logger().info(f"Pfeiltaste nach links gedrückt! Roboter bewegt sich mit {-self.speed} mm/s in negative x-Richtung.")

            elif key == keyboard.Key.up:
                self.jog_msg.vel = [0.0, self.speed, 0.0]  # Geschwindigkeit in y-Richtung
                self.get_logger().info(f"Pfeiltaste nach oben gedrückt! Roboter bewegt sich mit {self.speed} mm/s in y-Richtung.")

            elif key == keyboard.Key.down:
                self.jog_msg.vel = [0.0, -self.speed, 0.0]  # Geschwindigkeit in negative y-Richtung
                self.get_logger().info(f"Pfeiltaste nach unten gedrückt! Roboter bewegt sich mit {-self.speed} mm/s in negative y-Richtung.")

        except AttributeError:
            self.get_logger().info(f"Taste {key} gedrückt")

    def on_release(self, key):
        self.jog_msg.vel = [0.0, 0.0, 0.0]  # Roboter stoppt
        self.get_logger().info("Keine Taste gedrückt. Roboter stoppt.")

def main(args=None):
    rclpy.init(args=args)
    move_lin_by_key = MoveLinByKey()
    rclpy.spin(move_lin_by_key)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
