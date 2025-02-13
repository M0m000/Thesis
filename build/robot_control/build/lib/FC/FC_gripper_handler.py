import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetDiscreteOutput

class GripperHandler(Node):
    def __init__(self):
        super().__init__('gripper_handler')

        self.set_output_client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')

        # Warte, bis der Service verfügbar ist
        while not self.set_output_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SetDiscreteOutput...")
        self.get_logger().info("Service SetDiscreteOutput available!")

        self.gripper_initialized = False
        self.gripper_startup()
        self.gripper_closed = None



    def gripper_startup(self):
        if self.set_output(6):
            self.gripper_initialized = True
            self.get_logger().info("Gripper initialized...")
        else:
            self.gripper_initialized = False
            self.get_logger().error("Error initializing gripper!")



    def get_gripper_state(self):
        """ Gibt den aktuellen Zustand des Greifers zurück (offen/geschlossen) """
        return self.gripper_closed



    def set_output(self, dout_index):
        """ Setzt einen digitalen Ausgang asynchron """
        request = SetDiscreteOutput.Request()
        request.index = dout_index
        request.value = 1

        future = self.set_output_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None and future.result().success:
            # self.get_logger().info(f"Digital output {dout_index} set successfully.")
            return True
        else:
            self.get_logger().error(f"Error setting digital output {dout_index}!")
            return False



    def reset_output(self, dout_index):
        """ Setzt einen digitalen Ausgang zurück (auf 0) """
        request = SetDiscreteOutput.Request()
        request.index = dout_index
        request.value = 0

        future = self.set_output_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None and future.result().success:
            # self.get_logger().info(f"Digital output {dout_index} set successfully.")
            return True
        else:
            self.get_logger().error(f"Error setting digital output {dout_index}!")
            return False



    def close_gripper(self):
        """ Schließt den Greifer """
        if self.reset_output(8) and self.set_output(7):
            self.gripper_closed = True
            self.get_logger().info("Gripper closed.")
        else:
            self.gripper_closed = None
            self.get_logger().error("Error closing gripper!")



    def open_gripper(self):
        """ Öffnet den Greifer """
        if self.reset_output(7) and self.set_output(8):
            self.gripper_closed = False
            self.get_logger().info("Gripper opened.")
        else:
            self.gripper_closed = None
            self.get_logger().error("Error opening gripper!")





def main(args=None):
    rclpy.init(args=args)
    node = GripperHandler()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
