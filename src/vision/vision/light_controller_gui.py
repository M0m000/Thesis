import sys
import threading
import signal
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool, Float64
from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QLabel,
    QSlider, QCheckBox, QSpinBox
)
from PyQt5.QtCore import Qt


class LightControlGuiNode(Node):
    def __init__(self):
        super().__init__('light_controller_gui')

        # ROS2 Publisher
        self.pub_active = self.create_publisher(Bool, '/vision/light_control/active', 10)
        self.pub_manual_mode = self.create_publisher(Bool, '/vision/light_control/manual_mode', 10)
        self.pub_manual_brightness = self.create_publisher(Float64, '/vision/light_control/manual_brightness', 10)
        self.pub_desired_brightness = self.create_publisher(Float64, '/vision/light_control/desired_brightness', 10)

        # Qt GUI Setup
        self.app = QApplication(sys.argv)
        self.window = QWidget()
        self.window.setWindowTitle("Light Control GUI")

        layout = QVBoxLayout()

        # Regelung aktiv
        self.checkbox_active = QCheckBox("Regelung/Licht aktiv")
        self.checkbox_active.setChecked(True)
        self.checkbox_active.stateChanged.connect(self.toggle_active)
        layout.addWidget(self.checkbox_active)

        # Manueller Modus
        self.checkbox_manual = QCheckBox("Manueller Modus")
        self.checkbox_manual.setChecked(False)
        self.checkbox_manual.stateChanged.connect(self.toggle_manual_mode)
        layout.addWidget(self.checkbox_manual)

        # Sollwert Helligkeit
        layout.addWidget(QLabel("Sollwert Helligkeit (Regelung)"))
        self.slider_brightness = QSlider(Qt.Horizontal)
        self.slider_brightness.setMinimum(0)
        self.slider_brightness.setMaximum(255)
        self.slider_brightness.setValue(230)
        self.slider_brightness.valueChanged.connect(self.update_desired_brightness)
        layout.addWidget(self.slider_brightness)

        # Manuelle Helligkeit
        layout.addWidget(QLabel("Manuelle Helligkeit [%]"))
        self.spin_manual = QSpinBox()
        self.spin_manual.setRange(0, 100)
        self.spin_manual.setValue(50)
        self.spin_manual.valueChanged.connect(self.update_manual_brightness)
        layout.addWidget(self.spin_manual)

        self.window.setLayout(layout)
        self.window.show()

        # Starte ROS2 in separatem Thread
        self.ros_thread = threading.Thread(target=rclpy.spin, args=(self,), daemon=True)
        self.ros_thread.start()

    def toggle_active(self, state):
        msg = Bool()
        msg.data = bool(state)
        self.pub_active.publish(msg)
        self.get_logger().info(f"Regelung aktiv: {msg.data}")

    def toggle_manual_mode(self, state):
        msg = Bool()
        msg.data = bool(state)
        self.pub_manual_mode.publish(msg)
        self.get_logger().info(f"Manueller Modus: {msg.data}")

    def update_desired_brightness(self, value):
        msg = Float64()
        msg.data = float(value)
        self.pub_desired_brightness.publish(msg)
        self.get_logger().info(f"Sollwert gesetzt auf: {msg.data}")

    def update_manual_brightness(self, value):
        msg = Float64()
        msg.data = float(value)
        self.pub_manual_brightness.publish(msg)
        self.get_logger().info(f"Manuelle Helligkeit gesetzt auf: {msg.data}%")

    def run(self):
        self.app.exec_()

    def close(self):
        self.get_logger().info("GUI und Node werden geschlossen...")
        self.window.close()
        self.destroy_node()
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    gui_node = LightControlGuiNode()

    # Signal-Handler für CTRL+C
    def handle_sigint(sig, frame):
        gui_node.close()
        sys.exit(0)

    signal.signal(signal.SIGINT, handle_sigint)

    try:
        gui_node.run()
    except Exception as e:
        print(f"Fehler im GUI-Loop: {e}")
    finally:
        if rclpy.ok():
            gui_node.close()


if __name__ == '__main__':
    main()
