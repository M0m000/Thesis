import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetSystemFrame
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
import math
import numpy as np
import os
import csv
from scipy.spatial.transform import Rotation as R


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
        self.read_csv_timer = self.create_timer(0.1, self.load_transformation_matrix_from_csv)
        self.save_csv_timer = self.create_timer(1.0, self.save_frames_to_csv)  # Speichern alle 1 Sekunde

    def euler_to_quaternion(self, roll, pitch, yaw):
        qx = math.sin(roll / 2) * math.cos(pitch / 2) * math.cos(yaw / 2) - math.cos(roll / 2) * math.sin(pitch / 2) * math.sin(yaw / 2)
        qy = math.cos(roll / 2) * math.sin(pitch / 2) * math.cos(yaw / 2) + math.sin(roll / 2) * math.cos(pitch / 2) * math.sin(yaw / 2)
        qz = math.cos(roll / 2) * math.cos(pitch / 2) * math.sin(yaw / 2) - math.sin(roll / 2) * math.sin(pitch / 2) * math.cos(yaw / 2)
        qw = math.cos(roll / 2) * math.cos(pitch / 2) * math.cos(yaw / 2) + math.sin(roll / 2) * math.sin(pitch / 2) * math.sin(yaw / 2)
        return qx, qy, qz, qw
    

    def calculate_quaternions_from_rotation_matrix(self, rotation_matrix):
        trace = np.trace(rotation_matrix)       # Summe Hauptdiagonale

        if trace > 0:       # Normalfall Trace > 0
            s = 0.5 / math.sqrt(trace + 1.0)
            qw = 0.25 / s
            qx = (rotation_matrix[2, 1] - rotation_matrix[1, 2]) * s
            qy = (rotation_matrix[0, 2] - rotation_matrix[2, 0]) * s
            qz = (rotation_matrix[1, 0] - rotation_matrix[0, 1]) * s
        else:               # Sonderfälle
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


    def load_transformation_matrix_from_csv(self, filename="/home/mo/Thesis/src/robot_control/robot_control/data/WORK_frame_in_world.csv"):
        try:
            matrix = np.loadtxt(filename, delimiter=",")
            if matrix.shape != (4, 4):
                self.get_logger().warn("Loaded Matrix in CSV has wrong shape!")
                return None
            print(f"Transformation Matrix loaded successfully from '{filename}'!")
            quaternion = R.from_matrix(matrix[:3, :3]).as_quat()  # In Quaternion umwandeln
            self.frames_data['work'] = {
                    'position': matrix[:3, 3],
                    'orientation' : quaternion
                }
            return matrix
        except Exception as e:
            self.get_logger().error(f"Failed to load Matrix from path '{filename}': {e}")
            return None
        

    def query_and_calculate_frames(self):
        frames = ['world', 'base', 'elbow', 'tfc', 'tcp']

        for frame in frames:
            request = GetSystemFrame.Request()
            request.name = frame
            request.ref = 'world'

            future = self.client.call_async(request)
            future.add_done_callback(lambda future, frame=frame: self.service_callback(future, frame))


    def service_callback(self, future, frame):
        try:
            response = future.result()
            if response is not None and response.success:
                position = response.pos     # [x, y, z]
                orientation = response.rot  # [roll, pitch, yaw] in Grad

                alpha = math.radians(orientation[0])  # roll
                beta = math.radians(orientation[1])   # pitch
                gamma = math.radians(orientation[2])  # yaw

                qx, qy, qz, qw = self.euler_to_quaternion(alpha, beta, gamma)

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

            self.tf_broadcaster.sendTransform(transform)
            self.get_logger().info(f"Published transform for {frame}")

    def save_frames_to_csv(self):
        """ Speichert für jedes Frame eine eigene CSV-Datei mit der 4x4 homogenen Transformationsmatrix """
        save_path = os.path.expanduser("~/Thesis/src/robot_control/robot_control/data")
        
        try:
            for frame, data in self.frames_data.items():
                # Erstelle für jedes Frame einen eigenen Dateinamen
                filename = os.path.join(save_path, f"{frame}_world.csv")
                
                position = data['position']
                orientation = data['orientation']
                
                # Erstelle die 4x4 Transformationsmatrix
                rotation_matrix = R.from_quat(orientation).as_matrix()
                transformation_matrix = np.eye(4)  # 4x4 Identitätsmatrix
                transformation_matrix[:3, :3] = rotation_matrix
                transformation_matrix[:3, 3] = position
                
                # Speichern der Matrix als 4x4 CSV
                with open(filename, mode='w', newline='') as file:
                    writer = csv.writer(file)
                    # Speichern der Matrix (4x4 Anordnung)
                    writer.writerows(transformation_matrix)
                
                self.get_logger().info(f"Transformation matrix for {frame} saved to '{filename}'!")

        except Exception as e:
            self.get_logger().error(f"Error while saving transformation matrices to CSV: {e}")


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
