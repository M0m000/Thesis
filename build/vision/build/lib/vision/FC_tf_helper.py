import rclpy
from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import TransformStamped, PointStamped
from tf2_geometry_msgs.tf2_geometry_msgs import do_transform_point

class TFHelper:
    def __init__(self, node):
        """
        Klasse zur Verwendung von tf2 in einer bestehenden ROS 2 Node.
        
        :param node: Instanz einer rclpy Node, die tf2 nutzen will.
        """
        self.node = node
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self.node)

    def lookup_transform(self, from_frame: str, to_frame: str) -> TransformStamped:
        """
        Holt die Transformation zwischen zwei Frames.
        
        :param from_frame: Quell-Frame (z. B. 'camera_link')
        :param to_frame: Ziel-Frame (z. B. 'base_link')
        :return: TransformStamped oder None, falls die Transformation nicht existiert.
        """
        try:
            transform = self.tf_buffer.lookup_transform(
                to_frame, from_frame, rclpy.time.Time()
            )
            self.node.get_logger().info(f"Transformation gefunden: {from_frame} → {to_frame}")
            return transform
        except Exception as e:
            self.node.get_logger().warn(f"Keine Transformation gefunden: {str(e)}")
            return None

    def transform_point(self, x: float, y: float, z: float, from_frame: str, to_frame: str) -> PointStamped:
        """
        Transformiert einen Punkt von einem Frame in einen anderen.
        
        :param x: X-Koordinate des Punkts
        :param y: Y-Koordinate des Punkts
        :param z: Z-Koordinate des Punkts
        :param from_frame: Ursprungs-Koordinatensystem
        :param to_frame: Ziel-Koordinatensystem
        :return: Transformierter Punkt oder None, falls keine Transformation möglich ist.
        """
        point = PointStamped()
        point.header.frame_id = from_frame
        point.header.stamp = self.node.get_clock().now().to_msg()
        point.point.x = x
        point.point.y = y
        point.point.z = z

        transform = self.lookup_transform(from_frame, to_frame)
        if transform:
            transformed_point = do_transform_point(point, transform)
            self.node.get_logger().info(f"Punkt transformiert: {transformed_point.point}")
            return transformed_point
        else:
            self.node.get_logger().warn("Transformation fehlgeschlagen.")
            return None
