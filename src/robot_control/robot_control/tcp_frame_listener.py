import rclpy
from rclpy.node import Node
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np
from scipy.spatial.transform import Rotation as R

class TCPFrameListener(Node):

    def __init__(self):
        super().__init__('tcp_frame_listener')

        # Declare parameters for source and target frames
        self.target_frame = self.declare_parameter(
            'target_frame', 'world').get_parameter_value().string_value
        self.source_frame = self.declare_parameter(
            'source_frame', 'tcp').get_parameter_value().string_value

        # Initialize the tf2 buffer and listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Timer to periodically query the transform
        self.timer = self.create_timer(1.0, self.on_timer)

    def on_timer(self):
        try:
            # Query the transformation between source_frame and target_frame
            transform = self.tf_buffer.lookup_transform(
                self.target_frame,
                self.source_frame,
                rclpy.time.Time()
            )

            # Extract translation and rotation
            translation = transform.transform.translation
            rotation = transform.transform.rotation

            # Log the translation and rotation of the transform
            self.get_logger().info(f"Translation: x={translation.x}, y={translation.y}, z={translation.z}")
            self.get_logger().info(f"Rotation (Quaternion): x={rotation.x}, y={rotation.y}, z={rotation.z}, w={rotation.w}")

            # Define the point in the TCP frame
            point_in_tcp = np.array([50.0, 0.0, 0.0])

            # Convert the quaternion to a rotation matrix
            quat = [rotation.x, rotation.y, rotation.z, rotation.w]
            rot_matrix = R.from_quat(quat).as_matrix()

            # Transform the point to the base_link frame
            point_in_base = rot_matrix @ point_in_tcp + np.array([translation.x, translation.y, translation.z])

            # Log the transformed point
            self.get_logger().info(f"Point in {self.target_frame}: x={point_in_base[0]}, y={point_in_base[1]}, z={point_in_base[2]}")

        except TransformException as ex:
            self.get_logger().warn(f"Could not transform {self.source_frame} to {self.target_frame}: {ex}")


def main():
    rclpy.init()
    node = TCPFrameListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

