import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetSystemFrame
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
import math
import numpy as np
import os


class TFFramesPublisher(Node):
    def __init__(self):
        super().__init__('tf_frames_publisher')

        self.tf_broadcaster = TransformBroadcaster(self)
        self.client = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')
        self.get_logger().info('Service GetSystemFrame available!')

        self.frames_data = {}
        package_path = os.path.expanduser("~/ros2_ws/src/robot_control/robot_control/data")
        self.filepath = os.path.join(package_path, "WORK_frame_in_world.csv")

        self.service_timer = self.create_timer(0.1, self.query_and_calculate_frames)
        self.publish_timer = self.create_timer(0.1, self.publish_transforms)


    def euler_to_quaternion(self, roll, pitch, yaw):
        """
        Convert Euler angles to Quaternion.
        Roll  = Rotation around X-axis
        Pitch = Rotation around Y-axis
        Yaw   = Rotation around Z-axis
        """
        qx = math.sin(roll / 2) * math.cos(pitch / 2) * math.cos(yaw / 2) - math.cos(roll / 2) * math.sin(pitch / 2) * math.sin(yaw / 2)
        qy = math.cos(roll / 2) * math.sin(pitch / 2) * math.cos(yaw / 2) + math.sin(roll / 2) * math.cos(pitch / 2) * math.sin(yaw / 2)
        qz = math.cos(roll / 2) * math.cos(pitch / 2) * math.sin(yaw / 2) - math.sin(roll / 2) * math.sin(pitch / 2) * math.cos(yaw / 2)
        qw = math.cos(roll / 2) * math.cos(pitch / 2) * math.cos(yaw / 2) + math.sin(roll / 2) * math.sin(pitch / 2) * math.sin(yaw / 2)
        return qx, qy, qz, qw
    

    def calculate_quaternions_from_rotation_matrix(rotation_matrix):
        # Berechne den Trace der Rotationsmatrix
        trace = np.trace(rotation_matrix)

        # Berechne die Quaternionen basierend auf dem Trace
        if trace > 0:
            s = 0.5 / math.sqrt(trace + 1.0)
            qw = 0.25 / s
            qx = (rotation_matrix[2, 1] - rotation_matrix[1, 2]) * s
            qy = (rotation_matrix[0, 2] - rotation_matrix[2, 0]) * s
            qz = (rotation_matrix[1, 0] - rotation_matrix[0, 1]) * s
        else:
            # Wenn der Trace nicht positiv ist, dann bestimme das größte Element in der Diagonalen
            if rotation_matrix[0, 0] > rotation_matrix[1, 1] and rotation_matrix[0, 0] > rotation_matrix[2, 2]:
                t = 1.0 + rotation_matrix[0, 0] - rotation_matrix[1, 1] - rotation_matrix[2, 2]
                s = 2.0 * math.sqrt(t)
                qw = (rotation_matrix[2, 1] - rotation_matrix[1, 2]) / s
                qx = 0.25 * s
                qy = (rotation_matrix[0, 1] + rotation_matrix[1, 0]) / s
                qz = (rotation_matrix[0, 2] + rotation_matrix[2, 0]) / s
            elif rotation_matrix[1, 1] > rotation_matrix[2, 2]:
                t = 1.0 + rotation_matrix[1, 1] - rotation_matrix[0, 0] - rotation_matrix[2, 2]
                s = 2.0 * math.sqrt(t)
                qw = (rotation_matrix[0, 2] - rotation_matrix[2, 0]) / s
                qx = (rotation_matrix[0, 1] + rotation_matrix[1, 0]) / s
                qy = 0.25 * s
                qz = (rotation_matrix[1, 2] + rotation_matrix[2, 1]) / s
            else:
                t = 1.0 + rotation_matrix[2, 2] - rotation_matrix[0, 0] - rotation_matrix[1, 1]
                s = 2.0 * math.sqrt(t)
                qw = (rotation_matrix[1, 0] - rotation_matrix[0, 1]) / s
                qx = (rotation_matrix[0, 2] + rotation_matrix[2, 0]) / s
                qy = (rotation_matrix[1, 2] + rotation_matrix[2, 1]) / s
                qz = 0.25 * s
        return [qx, qy, qz, qw]


    def load_transformation_matrix_from_csv(self, filename="/src/robot_control/robot_control/data/WORK_frame_in_world.csv"):
        try:
            matrix = np.loadtxt(filename, delimiter=",")
            if matrix.shape != (4, 4):
                self.get_logger().warn("Loaded Matrix in CSV has wrong shape!")
                return None
            print(f"Transformation Matrix loaded successfully from '{filename}'!")
            self.frames_data['ref'] = {
                    'position': matrix[:3, 3],
                    'orientation': self.calculate_quaternions_from_rotation_matrix(matrix[:3, :3])
                }
            return matrix
        except Exception as e:
            self.get_logger().error(f"Failed to load Matrix from path '{filename}': {e}")
            return None
        

    def query_and_calculate_frames(self):
        frames = ['base', 'elbow', 'tfc', 'tcp', 'target']

        for frame in frames:
            request = GetSystemFrame.Request()
            request.name = frame
            request.ref = 'world'

            # Asynchroner Service-Aufruf
            future = self.client.call_async(request)

            # Wir speichern den Frame-Namen mit der Future, damit wir ihn später im Callback verwenden können
            future.add_done_callback(lambda future, frame=frame: self.service_callback(future, frame))


    def service_callback(self, future, frame):
        try:
            response = future.result()

            if response is not None and response.success:
                position = response.pos     # [x, y, z]
                orientation = response.rot  # [roll, pitch, yaw] in Grad

                # Umwandlung von Grad zu Bogenmaß
                alpha = math.radians(orientation[0])  # roll
                beta = math.radians(orientation[1])   # pitch
                gamma = math.radians(orientation[2])  # yaw

                qx, qy, qz, qw = self.euler_to_quaternion(alpha, beta, gamma)

                # Speichern der berechneten Daten
                self.frames_data[frame] = {
                    'position': position,
                    'orientation': (qx, qy, qz, qw)
                }
            else:
                self.get_logger().warn(f"Service call failed for frame: {frame}")
        except Exception as e:
            self.get_logger().error(f"Error in service callback: {e}")


    def publish_transforms(self):
        for frame, data in self.frames_data.items():
            position = data['position']
            orientation = data['orientation']

            transform = TransformStamped()
            transform.header.stamp = self.get_clock().now().to_msg()
            transform.header.frame_id = 'world'
            transform.child_frame_id = frame

            # Translation
            transform.transform.translation.x = position[0]
            transform.transform.translation.y = position[1]
            transform.transform.translation.z = position[2]

            # Rotation (Quaternion)
            transform.transform.rotation.x = orientation[0]
            transform.transform.rotation.y = orientation[1]
            transform.transform.rotation.z = orientation[2]
            transform.transform.rotation.w = orientation[3]

            # Senden der Transformation
            self.tf_broadcaster.sendTransform(transform)

            self.get_logger().info(f"Published transform for {frame}")


def main(args=None):
    rclpy.init(args=args)
    node = TFFramesPublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
