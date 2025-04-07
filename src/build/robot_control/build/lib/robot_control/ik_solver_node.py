import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

import numpy as np
from scipy.optimize import minimize
from scipy.spatial.transform import Rotation as R

class IKSolverNode(Node):
    def __init__(self):
        super().__init__('ik_solver_node')

        self.joint_pub = self.create_publisher(JointState, '/ik_solution', 10)

        # Zielpose direkt im Code definieren
        trans = [0.0, 0.4, 1.14]  # x, y, z in Metern
        rot = [0.0, 0.0, 0.0]  # roll, pitch, yaw in Radiant

        print("Vorwärtskinematik")
        print(self.forward_kinematics([0, 0, 0, 0, 0, 0, 0]))

        try:
            joint_angles = self.inverse_kinematics(trans, rot)

            joint_msg = JointState()
            joint_msg.header.stamp = self.get_clock().now().to_msg()
            joint_msg.name = [f"joint_{i+1}" for i in range(7)]
            joint_msg.position = joint_angles.tolist()
            self.joint_pub.publish(joint_msg)

            self.get_logger().info(f"IK gelöst:\n{np.round(joint_angles, 3)}")

        except Exception as e:
            self.get_logger().warn(f"IK Fehler: {e}")

        # Node direkt wieder schließen
        rclpy.shutdown()

    # ---------- IK Code ----------

    dh_params = [
        {"d": 0.3087,   "a": 0.0, "alpha": 0.0},
        {"d": 0.857,   "a": 0.50, "alpha": -np.pi/2},
        {"d": 0.4222,  "a": 0.50, "alpha": -np.pi/2},
        {"d": 0.8405,   "a": 0.40, "alpha": -np.pi/2},
        {"d": 0.3775,  "a": 0.40, "alpha": -np.pi/2},
        {"d": 0.11135,   "a": 0.0, "alpha": -np.pi/2},
        {"d": 0.6635,   "a": 0.0, "alpha": np.pi/2},
    ]

    def dh_transform(self, theta, d, a, alpha):
        return np.array([
            [np.cos(theta), -np.sin(theta)*np.cos(alpha),  np.sin(theta)*np.sin(alpha), a*np.cos(theta)],
            [np.sin(theta),  np.cos(theta)*np.cos(alpha), -np.cos(theta)*np.sin(alpha), a*np.sin(theta)],
            [0,              np.sin(alpha),                np.cos(alpha),               d],
            [0,              0,                            0,                           1]
        ])

    def forward_kinematics(self, joint_angles):
        T = np.eye(4)
        for i in range(len(joint_angles)):
            theta = joint_angles[i]
            d = self.dh_params[i]["d"]
            a = self.dh_params[i]["a"]
            alpha = self.dh_params[i]["alpha"]
            T = T @ self.dh_transform(theta, d, a, alpha)
        return T

    def pose_error(self, joint_angles, target_pos, target_rot):
        T = self.forward_kinematics(joint_angles)
        pos_error = np.linalg.norm(T[:3, 3] - target_pos)
        rot_diff = T[:3, :3] @ target_rot.T
        angle_error = np.arccos((np.trace(rot_diff) - 1) / 2.0)
        return pos_error + 0.5 * angle_error  # 0.5 gewichtet Rotation sanfter

    def inverse_kinematics(self, target_position, target_orientation_rpy):
        initial_guess = np.array([0.0, 0.1, -0.2, 0.1, 0.0, 0.2, 0.0])
        target_rot = R.from_euler('xyz', target_orientation_rpy).as_matrix()

        res = minimize(
            self.pose_error,
            initial_guess,
            args=(np.array(target_position), target_rot),
            method='SLSQP',
            options={'disp': True, 'maxiter': 10000, 'ftol': 1e-9}
        )

        if res.success:
            return np.degrees(res.x)
        else:
            raise ValueError("IK konnte nicht gelöst werden.")

def main(args=None):
    rclpy.init(args=args)
    IKSolverNode()  # kein spin() notwendig