import rclpy
from rclpy.node import Node
from kr_msgs.srv import SetDiscreteOutput
from kr_msgs.srv import SetSystemFrame

class GripperHandler(Node):
    def __init__(self):
        super().__init__('gripper_handler')

        self.set_output_client = self.create_client(SetDiscreteOutput, '/kr/iob/set_digital_output')
        while not self.set_output_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for service SetDiscreteOutput...")

        self.set_kassow_frame_client = self.create_client(SetSystemFrame, '/kr/robot/set_system_frame')
        while not self.set_kassow_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Service SetSystemFrame...")

        self.gripper_initialized = False
        self.gripper_closed = None

        self.tcp_pos_in_tfc_frame = [0.0, 0.0, 230.0]
        self.tcp_rot_in_tfc_frame = [0.0, 0.0, 29.0]
        self.set_frame(trans=self.tcp_pos_in_tfc_frame,
                       rot=self.tcp_rot_in_tfc_frame,
                       frame='tcp',
                       ref_frame='tfc')



    def gripper_startup(self):
        """Manuelle Initialisierung des Greifers"""
        if self.set_output(6):
            self.gripper_initialized = True
            self.reset_output(7)    # unbestimmter Zustand bei Startup
            self.reset_output(8)    # unbestimmter Zustand bei Startup
            self.get_logger().info("Gripper initialized...")
        else:
            self.gripper_initialized = False
            self.get_logger().error("Error initializing gripper!")



    def set_frame(self, trans, rot, frame="tcp", ref_frame="tfc"):
        request = SetSystemFrame.Request()
        request.name = frame
        request.ref = ref_frame
        request.pos = trans
        request.rot = rot

        future = self.set_kassow_frame_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Frame '{frame}' set successfully!")
            else:
                self.get_logger().warn(f"Failed to set frame '{frame}'!")
        except Exception as e:
            self.get_logger().error(f"Service call of SetSystemFrame failed: {e}")



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

        self.get_logger().info(f"Sending request to set digital output {dout_index}...")

        future = self.set_output_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None and future.result().success:
            self.get_logger().info(f"Digital output {dout_index} set successfully.")
            return True
        else:
            self.get_logger().error(f"Error setting digital output {dout_index}! Response: {future.result()}")
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
            self.gripper_closed = False  # Setze explizit auf False, wenn es fehlschlägt
            self.get_logger().error("Error closing gripper!")



    def open_gripper(self):
        """ Öffnet den Greifer """
        if self.reset_output(7) and self.set_output(8):
            self.gripper_closed = False
            self.get_logger().info("Gripper opened.")
        else:
            self.gripper_closed = True  # Falls der Befehl fehlschlägt, bleibt der Greifer geschlossen
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
