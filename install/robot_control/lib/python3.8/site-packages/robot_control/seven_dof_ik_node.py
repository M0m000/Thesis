#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import PyKDL
from urdf_parser_py.urdf import URDF
from kdl_parser_py.urdf import treeFromUrdfModel

class IKNode(Node):
    def __init__(self):
        super().__init__('seven_dof_ik_node')
        self.get_logger().info("7DOF IK Node gestartet")

        # URDF laden
        self.robot = URDF.from_xml_file('/home/mo/Thesis/src/robot_control/urdf/seven_dof.urdf')
        ok, tree = treeFromUrdfModel(self.robot)
        if not ok:
            self.get_logger().error("Fehler beim Parsen des URDF")
            return

        # Kette erzeugen
        self.chain = tree.getChain("base_link", "ee_link")

        # Solver erstellen
        self.fk_solver = PyKDL.ChainFkSolverPos_recursive(self.chain)
        self.ik_solver_vel = PyKDL.ChainIkSolverVel_pinv(self.chain)
        self.ik_solver = PyKDL.ChainIkSolverPos_NR(self.chain, self.fk_solver, self.ik_solver_vel)

        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        # Test: Vorwärtstransformation
        q = PyKDL.JntArray(7)
        for i in range(7):
            q[i] = 0.1 * i

        end_frame = PyKDL.Frame()
        self.fk_solver.JntToCart(q, end_frame)
        self.get_logger().info(f"FK Endeffektor-Position: x={end_frame.p[0]:.3f}, y={end_frame.p[1]:.3f}, z={end_frame.p[2]:.3f}")

        # Inverse Kinematik testen
        target_frame = PyKDL.Frame(PyKDL.Vector(0.1, 0.1, 0.9))
        q_init = PyKDL.JntArray(7)
        q_result = PyKDL.JntArray(7)

        ret = self.ik_solver.CartToJnt(q_init, target_frame, q_result)
        if ret >= 0:
            joints = [f"{q_result[i]:.3f}" for i in range(7)]
            self.get_logger().info(f"IK erfolgreich. Gelenkwinkel: {', '.join(joints)}")
        else:
            self.get_logger().warn("IK fehlgeschlagen")


def main(args=None):
    rclpy.init(args=args)
    node = IKNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
