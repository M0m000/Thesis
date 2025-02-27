import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import TransformAction
from geometry_msgs.msg import TransformStamped
import tf2_ros
from tf2_ros import Buffer, TransformListener

class TransformActionServer(Node):

    def __init__(self):
        super().__init__('transform_action_server')
        self._action_server = ActionServer(self, TransformAction, 'transform', self.execute_callback)
        
        # TF2 setup
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.get_logger().info("Action Server started and TF listener initialized.")

    def execute_callback(self, goal_handle):
        ref_frame = goal_handle.request.ref_frame
        frame = goal_handle.request.frame

        # Versuch, die Transformation zu holen
        transform = self.get_transform(ref_frame, frame)

        if transform:
            # Wenn die Transformation erfolgreich ist, sendet der Server das Ergebnis
            result = TransformAction.Result()
            result.transform = transform
            goal_handle.succeed()
            self.get_logger().info(f"Transformation from {ref_frame} to {frame} completed successfully.")
            return result
        else:
            # Wenn keine Transformation verfügbar ist, sende eine Fehlermeldung
            goal_handle.abort()
            self.get_logger().error(f"Failed to get transform from {ref_frame} to {frame}.")
            return TransformAction.Result()

    def get_transform(self, ref_frame, frame):
        try:
            # Warte auf die Transformationsdaten (kann auch als Blocking-Aufruf erfolgen)
            transform = self.tf_buffer.lookup_transform(ref_frame, frame, rclpy.time.Time())
            return transform
        except tf2_ros.TransformException as e:
            self.get_logger().warn(f"Transform error: {e}")
            return None

def main(args=None):
    rclpy.init(args=args)
    action_server = TransformActionServer()

    # Server starten
    rclpy.spin(action_server)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
