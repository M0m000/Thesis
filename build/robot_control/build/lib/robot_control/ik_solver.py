import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Float64MultiArray

import PyKDL
from urdf_parser_py.urdf import URDF
from kdl_parser_py.urdf import treeFromUrdfModel

class IKSolverNode(Node):
    def __init__(self):
        super().__init__('ik_solver_node')

        # URDF laden
        urdf_path = "/home/mo/Thesis/src/robot_control/urdf/kr1205.urdf"
        with open(urdf_path, "r") as f:
            robot = URDF.from_xml_string(f.read())

        ok, tree = treeFromUrdfModel(robot)
        if not ok:
            self.get_logger().error("Konnte KDL-Baum nicht aus URDF erzeugen")
            return

        self.chain = tree.getChain("base_link", "link_7")
        self.fk_solver = PyKDL.ChainFkSolverPos_recursive(self.chain)
        self.ik_solver_vel = PyKDL.ChainIkSolverVel_pinv(self.chain)
        self.ik_solver_pos = PyKDL.ChainIkSolverPos_NR(self.chain, self.fk_solver, self.ik_solver_vel)

        # Subscriber für Zielpose
        self.create_subscription(PoseStamped, 'ik_target_pose', self.pose_callback, 10)
        # Publisher für Gelenkwinkel
        self.joint_pub = self.create_publisher(Float64MultiArray, 'ik_joint_solution', 10)

        self.get_logger().info("IK Solver Node gestartet")

    def pose_callback(self, msg):
        target = msg.pose

        goal_frame = PyKDL.Frame(
            PyKDL.Rotation.Quaternion(target.orientation.x, target.orientation.y,
                                       target.orientation.z, target.orientation.w),
            PyKDL.Vector(target.position.x, target.position.y, target.position.z)
        )

        q_init = PyKDL.JntArray(self.chain.getNrOfJoints())
        q_out = PyKDL.JntArray(self.chain.getNrOfJoints())

        result = self.ik_solver_pos.CartToJnt(q_init, goal_frame, q_out)

        if result >= 0:
            joint_msg = Float64MultiArray()
            joint_msg.data = [q_out[i] for i in range(q_out.rows())]
            self.joint_pub.publish(joint_msg)
            self.get_logger().info(f"IK erfolgreich: {joint_msg.data}")
        else:
            self.get_logger().warn("IK fehlgeschlagen")

def main(args=None):
    rclpy.init(args=args)
    node = IKSolverNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()