import math
from geometry_msgs.msg import Quaternion

def quaternion_to_euler(quaternion):
    """
    Konvertiert eine einzelne Quaternion in Roll, Pitch und Yaw Winkel.

    quaternion: Eine Liste in Form von [qx, qy, qz, qw]
    return: Liste [Roll, Pitch, Yaw] für die gegebene Quaternion
    """
    if quaternion is not None:
        qx = quaternion[0]
        qy = quaternion[1]
        qz = quaternion[2]
        qw = quaternion[3]

        # Berechne Roll, Pitch, Yaw (Euler-Winkel) aus der Quaternion
        # Roll (X-Achse Rotation)
        sinr_cosp = 2 * (qw * qx + qy * qz)
        cosr_cosp = 1 - 2 * (qx * qx + qy * qy)
        roll = math.atan2(sinr_cosp, cosr_cosp)

        # Pitch (Y-Achse Rotation)
        sinp = 2 * (qw * qy - qz * qx)
        pitch = math.asin(sinp) if abs(sinp) <= 1 else math.copysign(math.pi / 2, sinp)

        # Yaw (Z-Achse Rotation)
        siny_cosp = 2 * (qw * qz + qx * qy)
        cosy_cosp = 1 - 2 * (qy * qy + qz * qz)
        yaw = math.atan2(siny_cosp, cosy_cosp)

        return [roll, pitch, yaw]
    else:
        return None