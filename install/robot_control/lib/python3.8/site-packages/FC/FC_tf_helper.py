import rclpy
import tf2_ros
import tf2_geometry_msgs
from geometry_msgs.msg import TransformStamped, Quaternion, Vector3
from tf2_ros import Buffer, TransformListener
from rclpy.node import Node


class TFHelper:
    def __init__(self, node: Node):
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

    def transform_pose_to_world(self, translation_list, rotation_list, from_frame: str, to_frame: str):
        """
        Transformiert eine komplette Pose (Translation + Rotation) in ein anderes Koordinatensystem.
        Diese Funktion übernimmt die Umwandlung der Eingabelisten in Vector3 und Quaternion.

        :param translation_list: Liste oder Array mit 3 Werten für die Translation [x, y, z]
        :param rotation_list: Liste oder Array mit 4 Werten für das Quaternion [x, y, z, w]
        :param from_frame: Das aktuelle Koordinatensystem der Pose (z. B. 'WORK')
        :param to_frame: Das Ziel-Koordinatensystem (z. B. 'WORLD')
        :return: (Vector3, Quaternion) - Transformierte Pose in 'to_frame'
        """
        # Umwandlung der Listen in Vector3 und Quaternion
        translation = self.list_to_vector3(translation_list)
        rotation = self.list_to_quaternion(rotation_list)

        # Transformation der Pose
        transform = self.lookup_transform(from_frame, to_frame)

        if transform is None:
            self.node.get_logger().error(f"Transformation von {from_frame} nach {to_frame} fehlgeschlagen!")
            return None, None

        # Extrahiere die Translation und Rotation der Transformation
        trans = transform.transform.translation
        rot = transform.transform.rotation

        # Berechne die neue Translation, indem du sie mit der Transformationsmatrix multiplizierst
        rotated_translation = self.apply_rotation_to_translation(translation, rot)
        transformed_translation = Vector3()
        transformed_translation.x = trans.x + rotated_translation[0]
        transformed_translation.y = trans.y + rotated_translation[1]
        transformed_translation.z = trans.z + rotated_translation[2]

        # Berechne die neue Rotation (Multiplikation der Quaternionen)
        transformed_rotation = self.quaternion_multiply(rot, rotation)

        self.node.get_logger().info(f"Pose {translation} mit Rotation {rotation} von {from_frame} → {to_frame} transformiert.")
        return transformed_translation, transformed_rotation

    def apply_rotation_to_translation(self, translation, rotation):
        """
        Rotiert eine Translation mit einer Quaternion-Rotation.

        :param translation: Die Translation im 'from_frame'
        :param rotation: Die Quaternion-Rotation im 'from_frame'
        :return: Rotierte Translation
        """
        # Umrechnung der Quaternion in eine Matrix
        rot_matrix = self.quaternion_to_matrix(rotation)
        # Berechnung der rotierte Position
        rotated_translation = [rot_matrix[0][0] * translation.x + rot_matrix[0][1] * translation.y + rot_matrix[0][2] * translation.z,
                               rot_matrix[1][0] * translation.x + rot_matrix[1][1] * translation.y + rot_matrix[1][2] * translation.z,
                               rot_matrix[2][0] * translation.x + rot_matrix[2][1] * translation.y + rot_matrix[2][2] * translation.z]
        return rotated_translation

    def quaternion_to_matrix(self, quaternion):
        """
        Konvertiert eine Quaternion in eine 3x3 Rotationsmatrix.

        :param quaternion: Quaternion
        :return: 3x3 Rotationsmatrix
        """
        q = [quaternion.x, quaternion.y, quaternion.z, quaternion.w]
        q0, q1, q2, q3 = q

        return [
            [1 - 2 * (q2**2 + q3**2), 2 * (q1 * q2 - q0 * q3), 2 * (q1 * q3 + q0 * q2)],
            [2 * (q1 * q2 + q0 * q3), 1 - 2 * (q1**2 + q3**2), 2 * (q2 * q3 - q0 * q1)],
            [2 * (q1 * q3 - q0 * q2), 2 * (q2 * q3 + q0 * q1), 1 - 2 * (q1**2 + q2**2)],
        ]

    def quaternion_multiply(self, q1, q2):
        """
        Multipliziert zwei Quaternionen.

        :param q1: Erste Quaternion
        :param q2: Zweite Quaternion
        :return: Das Produkt der Quaternionen
        """
        return Quaternion(
            x=q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
            y=q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
            z=q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
            w=q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
        )

    def list_to_vector3(self, translation_list):
        """
        Wandelt eine Liste oder ein Array mit 3 Werten in ein Vector3-Objekt um.
        
        :param translation_list: Eine Liste oder ein Array mit 3 Werten für die Translation [x, y, z].
        :return: Ein Vector3-Objekt.
        """
        if len(translation_list) != 3:
            self.node.get_logger().error(f"Die Liste muss genau 3 Werte für x, y und z enthalten.")
            return None
        return Vector3(x=translation_list[0], y=translation_list[1], z=translation_list[2])

    def list_to_quaternion(self, rotation_list):
        """
        Wandelt eine Liste oder ein Array mit 4 Werten in ein Quaternion-Objekt um.
        
        :param rotation_list: Eine Liste oder ein Array mit 4 Werten für das Quaternion [x, y, z, w].
        :return: Ein Quaternion-Objekt.
        """
        if len(rotation_list) != 4:
            self.node.get_logger().error(f"Die Liste muss genau 4 Werte für x, y, z und w enthalten.")
            return None
        return Quaternion(x=rotation_list[0], y=rotation_list[1], z=rotation_list[2], w=rotation_list[3])
