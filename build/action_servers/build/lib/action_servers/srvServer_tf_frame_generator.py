import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from tf2_ros import Buffer, TransformListener, StaticTransformBroadcaster
from tf_transformations import quaternion_from_euler
import numpy as np
from action_interfaces.srv import GenerateFrame


class SrvServiceTFFrameGenerator(Node):
    def __init__(self):
        super().__init__('srvService_tf_frame_generator')

        # tf2 Buffer and Listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # tf2 Broadcaster
        self.tf_broadcaster = StaticTransformBroadcaster(self)

        # Create service server
        self.srv = self.create_service(GenerateFrame, 'generate_frame', self.handle_generate_frame)
        self.get_logger().info('Service "generate_frame" is ready to receive requests.')

    def handle_generate_frame(self, request, response):
        frame_new = request.frame_new
        frame_ref = request.frame_ref
        translation = request.translation
        rotation_rpy = request.rotation_rpy

        try:
            # Check if the frame already exists
            try:
                existing_transform = self.tf_buffer.lookup_transform('world', frame_new, rclpy.time.Time())
                self.get_logger().info(f'Frame "{frame_new}" already exists. Overwriting its parameters.')
            except Exception:
                self.get_logger().info(f'Frame "{frame_new}" does not exist. Creating a new one.')

            # Lookup the transform of frame_ref relative to world
            transform_ref = self.tf_buffer.lookup_transform('world', frame_ref, rclpy.time.Time())

            # Combine the transform_ref with the new frame's translation and rotation
            new_transform = TransformStamped()
            new_transform.header.stamp = self.get_clock().now().to_msg()
            new_transform.header.frame_id = 'world'
            new_transform.child_frame_id = frame_new

            # Compute combined translation
            new_transform.transform.translation.x = (
                transform_ref.transform.translation.x + translation[0]
            )
            new_transform.transform.translation.y = (
                transform_ref.transform.translation.y + translation[1]
            )
            new_transform.transform.translation.z = (
                transform_ref.transform.translation.z + translation[2]
            )

            # Convert RPY to quaternion
            r, p, y = rotation_rpy
            new_quat = quaternion_from_euler(r, p, y)

            # Compute combined rotation (using quaternion multiplication)
            ref_quat = np.array([
                transform_ref.transform.rotation.x,
                transform_ref.transform.rotation.y,
                transform_ref.transform.rotation.z,
                transform_ref.transform.rotation.w
            ])
            combined_quat = self.quaternion_multiply(ref_quat, new_quat)

            new_transform.transform.rotation.x = combined_quat[0]
            new_transform.transform.rotation.y = combined_quat[1]
            new_transform.transform.rotation.z = combined_quat[2]
            new_transform.transform.rotation.w = combined_quat[3]

            # Publish the transform
            self.tf_broadcaster.sendTransform(new_transform)
            self.get_logger().info(f'Published transform for {frame_new} relative to world')

            response.success = True
            response.message = f'Transform for {frame_new} generated or updated successfully.'
        except Exception as e:
            self.get_logger().error(f'Error generating transform: {e}')
            response.success = False
            response.message = f'Failed to generate transform: {str(e)}'

        return response

    @staticmethod
    def quaternion_multiply(q1, q2):
        """
        Perform quaternion multiplication.
        :param q1: First quaternion (x, y, z, w)
        :param q2: Second quaternion (x, y, z, w)
        :return: Resulting quaternion (x, y, z, w)
        """
        x1, y1, z1, w1 = q1
        x2, y2, z2, w2 = q2
        x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
        y = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2
        z = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2
        w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
        return np.array([x, y, z, w])

def main(args=None):
    rclpy.init(args=args)
    node = SrvServiceTFFrameGenerator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
