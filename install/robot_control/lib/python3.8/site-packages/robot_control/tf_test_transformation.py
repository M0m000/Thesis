import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener
import tf_transformations  # Für die Umwandlung zwischen Quaternionen und Matrizen
from geometry_msgs.msg import TransformStamped

class TestTransformation(Node):
    def __init__(self):
        super().__init__('test_transformation')

        # Buffer und Listener für tf2
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Timer zum Abrufen der Transformationen
        self.timer = self.create_timer(1.0, self.get_and_compute_transformation)

    def get_and_compute_transformation(self):
        try:
            # Abrufen der Transformationen von 'world' nach 'tcp' und von 'world' nach 'elbow'
            transform_tcp = self.tf_buffer.lookup_transform('world', 'tcp', rclpy.time.Time())
            transform_elbow = self.tf_buffer.lookup_transform('world', 'elbow', rclpy.time.Time())

            # Berechnung der Transformation von 'tcp' nach 'elbow'
            transform_tcp_to_elbow = self.compute_relative_transform(transform_tcp, transform_elbow)

            # Extrahieren der Translation und Rotation der berechneten Transformation
            translation = transform_tcp_to_elbow.transform.translation
            rotation = transform_tcp_to_elbow.transform.rotation

            # Umwandlung von Quaternionen in eine Transformationsmatrix (4x4)
            transform_matrix = self.quaternion_to_matrix(rotation.x, rotation.y, rotation.z, rotation.w, translation.x, translation.y, translation.z)

            # Ausgabe der Transformationsmatrix
            self.get_logger().info(f"Transformation Matrix from tcp to elbow:\n{transform_matrix}")
        except Exception as e:
            self.get_logger().warn(f"Could not get transform: {e}")

    def compute_relative_transform(self, transform_a: TransformStamped, transform_b: TransformStamped) -> TransformStamped:
        """
        Berechnet die relative Transformation zwischen zwei Frames.
        Hier berechnen wir die Transformation von 'tcp' nach 'elbow' basierend auf den
        Transformationen von 'world' nach 'tcp' und 'world' nach 'elbow'.
        """
        # Um die relative Transformation zu berechnen, invertieren wir die Transformation von 'b' (elbow)
        inverted_transform_b = self.invert_transform(transform_b)

        # Multiplizieren der beiden Transformationen
        # result = transform_a * inverted_transform_b
        return self.multiply_transforms(transform_a, inverted_transform_b)

    def invert_transform(self, transform: TransformStamped) -> TransformStamped:
        """
        Invertiert eine gegebene Transformation.
        """
        inverted_transform = TransformStamped()
        inverted_transform.header = transform.header
        inverted_transform.header.stamp = self.get_clock().now().to_msg()
        inverted_transform.header.frame_id = transform.child_frame_id
        inverted_transform.child_frame_id = transform.header.frame_id

        # Invertiere die Translation
        inverted_transform.transform.translation.x = -transform.transform.translation.x
        inverted_transform.transform.translation.y = -transform.transform.translation.y
        inverted_transform.transform.translation.z = -transform.transform.translation.z

        # Invertiere die Rotation
        inverted_transform.transform.rotation = tf_transformations.quaternion_inverse([
            transform.transform.rotation.x,
            transform.transform.rotation.y,
            transform.transform.rotation.z,
            transform.transform.rotation.w
        ])

        return inverted_transform

    def multiply_transforms(self, transform_a: TransformStamped, transform_b: TransformStamped) -> TransformStamped:
        """
        Multipliziert zwei Transformationen (d.h., kombiniert sie).
        """
        result_transform = TransformStamped()

        # Multiplizieren der Translation
        result_transform.transform.translation.x = transform_a.transform.translation.x + transform_b.transform.translation.x
        result_transform.transform.translation.y = transform_a.transform.translation.y + transform_b.transform.translation.y
        result_transform.transform.translation.z = transform_a.transform.translation.z + transform_b.transform.translation.z

        # Multiplizieren der Rotation (Quaternionen)
        result_rotation = tf_transformations.quaternion_multiply(
            [transform_a.transform.rotation.x, transform_a.transform.rotation.y, transform_a.transform.rotation.z, transform_a.transform.rotation.w],
            [transform_b.transform.rotation.x, transform_b.transform.rotation.y, transform_b.transform.rotation.z, transform_b.transform.rotation.w]
        )

        result_transform.transform.rotation.x = result_rotation[0]
        result_transform.transform.rotation.y = result_rotation[1]
        result_transform.transform.rotation.z = result_rotation[2]
        result_transform.transform.rotation.w = result_rotation[3]

        return result_transform

    def quaternion_to_matrix(self, qx, qy, qz, qw, tx, ty, tz):
        """
        Umwandlung von Quaternion und Translation in eine 4x4 Transformationsmatrix.
        """
        # Rotation-Matrix aus Quaternion
        rotation_matrix = tf_transformations.quaternion_matrix([qx, qy, qz, qw])

        # Setze Translation in die Matrix
        rotation_matrix[0, 3] = tx
        rotation_matrix[1, 3] = ty
        rotation_matrix[2, 3] = tz

        return rotation_matrix

def main(args=None):
    rclpy.init(args=args)
    node = TestTransformation()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
