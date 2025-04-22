import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetRobotPose
from FC.FC_eval_save_trajectory_to_csv import load_csv_to_trajectory, save_trajectory_to_csv
from FC.FC_frame_handler import FrameHandler
import numpy as np


class TrajectoryFrameConverter(Node):
    def __init__(self):
        super().__init__('trajectory_frame_converter')

        self.declare_parameter('csv_load_path', '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_0.csv')
        self.csv_load_path = self.get_parameter('csv_load_path').get_parameter_value().string_value
        self.declare_parameter('csv_save_path', '/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_0.csv')
        self.csv_save_path = self.get_parameter('csv_save_path').get_parameter_value().string_value

        self.cli = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service GetRobotPose...')

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = 'frame_handler_for_trajectory_recorder_node')

        self.traj_in_worldframe = load_csv_to_trajectory(filepath = self.csv_load_path)
        
        self.traj_in_workframe = []
        T_world_in_workframe = self.frame_handler.get_world_in_workframe()

        self.get_logger().info(f"Transforming trajectory from WORLD to WORK...")
        for traj_point in self.traj_in_worldframe:
            pos_in_worldframe = traj_point[0]
            rot_in_worldframe = traj_point[1]

            pos_in_workframe = T_world_in_workframe @ np.hstack((np.array(pos_in_worldframe), 1))
            rot_in_workframe = T_world_in_workframe[:3, :3] @ np.array(rot_in_worldframe)

            self.traj_in_workframe.append((pos_in_workframe[:3], rot_in_workframe))

        save_trajectory_to_csv(trajectory = self.traj_in_workframe, filepath = self.csv_save_path)
        self.get_logger().info(f"Trajectory transformed in WORK and saved as csv in {self.csv_save_path}")



    def destroy_node(self):
        super().destroy_node()




def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryFrameConverter()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
