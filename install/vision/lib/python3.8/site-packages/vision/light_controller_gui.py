# light_control_gui_node.py

import sys
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool, Float64
from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QLabel,
    QSlider, QCheckBox, QSpinBox
)
from PyQt5.QtCore import Qt, QTimer


class LightControlGuiNode(Node):
    def __init__(self):
        super().__init__('light_control_gui')

        # Publisher
        self.pub_active = self.create_publisher(Bool, '/vision/light_control/active', 10)
        self.pub_manual_mode = self.create_publisher(Bool, '/vision/light_control/manual_mode', 10)
        self.pub_manual_brightness = self.create_publisher(Float64, '/vision/light_control/manual_brightness', 10)
        self.pub_desired_brightness = self.create_publisher(Float64, '/vision/light_control/desired_brightness', 10)

        # Start GUI
        self.app = QApplication(sys.argv)
        self.window = QWidget()
        self.window.setWindowTitle("Light Control GUI")

        layout = QVBoxLayout()

        # Regelung aktiv
        self.checkbox_active = QCheckBox("Regelung/Licht aktiv")
        self.checkbox_active.setChecked(True)
        self.checkbox_active.stateChanged.connect(self.toggle_active)
        layout.addWidget(self.checkbox_active)

        # Manual Mode
        self.checkbox_manual = QCheckBox("Manueller Modus")
        self.checkbox_manual.setChecked(False)
        self.checkbox_manual.stateChanged.connect(self.toggle_manual_mode)
        layout.addWidget(self.checkbox_manual)

        # Desired Brightness
        layout.addWidget(QLabel("Sollwert Helligkeit (Regelung)"))
        self.slider_brightness = QSlider(Qt.Horizontal)
        self.slider_brightness.setMinimum(0)
        self.slider_brightness.setMaximum(255)
        self.slider_brightness.setValue(230)
        self.slider_brightness.valueChanged.connect(self.update_desired_brightness)
        layout.addWidget(self.slider_brightness)

        # Manual Brightness
        layout.addWidget(QLabel("Manuelle Helligkeit [%]"))
        self.spin_manual = QSpinBox()
        self.spin_manual.setRange(0, 100)
        self.spin_manual.setValue(50)
        self.spin_manual.valueChanged.connect(self.update_manual_brightness)
        layout.addWidget(self.spin_manual)

        self.window.setLayout(layout)
        self.window.show()

        # Timer to spin ROS node periodically
        self.timer = QTimer()
        self.timer.timeout.connect(self.ros_spin_once)
        self.timer.start(50)  # every 50 ms

    def toggle_active(self, state):
        msg = Bool()
        msg.data = bool(state)
        self.pub_active.publish(msg)
        self.get_logger().info(f"Regelung aktiv: {msg.data}")

    def toggle_manual_mode(self, state):
        msg = Bool()
        msg.data = bool(state)
        self.pub_manual_mode.publish(msg)
        self.get_logger().info(f"Manual Mode: {msg.data}")

    def update_desired_brightness(self, value):
        msg = Float64()
        msg.data = float(value)
        self.pub_desired_brightness.publish(msg)
        self.get_logger().info(f"Desired Brightness gesetzt auf: {msg.data}")

    def update_manual_brightness(self, value):
        msg = Float64()
        msg.data = float(value)
        self.pub_manual_brightness.publish(msg)
        self.get_logger().info(f"Manual Brightness gesetzt auf: {msg.data}%")

    def ros_spin_once(self):
        rclpy.spin_once(self, timeout_sec=0)

    def run(self):
        sys.exit(self.app.exec_())


def main(args=None):
    rclpy.init(args=args)
    gui_node = LightControlGuiNode()
    try:
        gui_node.run()
    finally:
        gui_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

