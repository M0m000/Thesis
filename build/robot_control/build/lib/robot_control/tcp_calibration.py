import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetSystemFrame
import numpy as np
from scipy.spatial.transform import Rotation as R
from scipy.optimize import least_squares



def pose_to_matrix(trans, rot):
    T = np.eye(4)
    T[:3, :3] = R.from_euler('xyz', rot, degrees=True).as_matrix()
    T[:3, 3] = trans
    return T


def residuals(params, T_list):
    tcp_trans = params[0:3]
    tcp_rot = params[3:6]
    target = params[6:9]

    tcp_T = pose_to_matrix(tcp_trans, tcp_rot)

    res = []
    for T in T_list:
        tcp_world = T @ tcp_T
        res.append(tcp_world[:3, 3] - target)
    return np.concatenate(res)


def compute_tcp_optimized(trans_list, rot_list):
    T_list = [pose_to_matrix(t, r) for t, r in zip(trans_list, rot_list)]
    x0 = np.array([0, 0, 0, 0, 0, 0] + list(np.mean(trans_list, axis=0)))
    result = least_squares(residuals, x0, args=(T_list,))
    tcp_trans = result.x[0:3]
    tcp_rot = result.x[3:6]
    target_world = result.x[6:9]
    return tcp_trans, tcp_rot, target_world


def build_frame_from_points(p1, p2, p3):
    x_axis = p2 - p1
    x_axis /= np.linalg.norm(x_axis)
    z_axis = p3 - p1
    z_axis /= np.linalg.norm(z_axis)
    y_axis = np.cross(z_axis, x_axis)
    y_axis /= np.linalg.norm(y_axis)
    
    # Orthogonalität herstellen
    z_axis = np.cross(x_axis, y_axis)
    return np.stack([x_axis, y_axis, z_axis], axis=1)



class TCPCalibrationNode(Node):
    def __init__(self):
        super().__init__('tcp_calibration')
        self.cli = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service GetSystemFrame')
        self.get_logger().info('Service GetSystemFrame available.')    

        self.trans_list = []
        self.rot_list = []
        self.tip_points = []

        self.step = 0
        self.run()


    def run(self):
        self.get_logger().info("TCP calibration started!")
        self.get_logger().info("1 - TRANSLATION")

        while self.step < 4:
            if input(f"[{self.step+1}/4] Place TCP on one tip and type 'done': ").strip().lower() == 'done':
                self.capture_pose('tfc', 'world', store_in='translation')
                self.step += 1

        self.get_logger().info("Position values collected. Calculating TCP position...")
        tcp_trans, tcp_rot_dummy, target = compute_tcp_optimized(self.trans_list, self.rot_list)
        self.get_logger().info(f"TCP position in TFC [mm]: {tcp_trans * 1000.0}")

        self.get_logger().info("2 - ROTATION")
        for label in ['A', 'B', 'C']:
            while True:
                if input(f"[{label}] Place tcp on tip {label} and then type 'done': ").strip().lower() == 'done':
                    self.capture_pose('tcp', 'world', store_in='rotation')
                    break

        self.get_logger().info("Rotation values collected. Calculating orientation...")

        # TFC-Orientierung im WORLD-Frame = Erste Pose aus Translationsteil
        R_world_tfc = R.from_euler('xyz', self.rot_list[0], degrees=True).as_matrix()
        tcp_points_world = np.array(self.tip_points)
        tcp_frame_world = build_frame_from_points(*tcp_points_world)

        # R_tcp_in_tfc = R_tfc.T @ R_tcp
        R_tcp_in_tfc = R_world_tfc.T @ tcp_frame_world
        euler_tcp_in_tfc = R.from_matrix(R_tcp_in_tfc).as_euler('xyz', degrees=True)

        self.get_logger().info(f"TCP Position [mm]: {tcp_trans * 1000.0}")
        self.get_logger().info(f"TCP Rotation [deg, RPY]: {euler_tcp_in_tfc}")


    def capture_pose(self, name, ref, store_in):
        req = GetSystemFrame.Request()
        req.name = name
        req.ref = ref

        future = self.cli.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        res = future.result()

        if res and res.success:
            pos = np.array(res.pos) / 1000.0  # mm → m
            rot = list(res.rot)
            if store_in == 'translation':
                self.trans_list.append(pos)
                self.rot_list.append(rot)
            elif store_in == 'rotation':
                self.tip_points.append(pos)
            self.get_logger().info(f"Got pose: Pos={pos}, Rot={rot}")
        else:
            self.get_logger().error("Service call failed!")



def main(args=None):
    rclpy.init(args=args)
    node = TCPCalibrationNode()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
