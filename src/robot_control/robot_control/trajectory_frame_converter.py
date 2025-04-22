import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetRobotPose
from FC.FC_eval_save_trajectory_to_csv import load_csv_to_trajectory, save_trajectory_to_csv
from FC.FC_frame_handler import FrameHandler
import numpy as np
import os
import glob


class TrajectoryBatchConverter(Node):
    def __init__(self):
        super().__init__('trajectory_batch_converter')

        self.declare_parameter('csv_directory', '/home/mo/Thesis/Evaluation/Trajektorientests')
        self.csv_directory = self.get_parameter('csv_directory').get_parameter_value().string_value

        self.cli = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service GetRobotPose...')

        # Instanz FrameHandler
        self.frame_handler = FrameHandler(node_name='frame_handler_for_trajectory_converter')

        # Transformation holen
        T_world_in_workframe = self.frame_handler.get_world_in_workframe()

        # Alle CSV-Dateien im Ordner finden
        csv_files = glob.glob(os.path.join(self.csv_directory, '*.csv'))

        for csv_file in csv_files:
            if csv_file.endswith('_work.csv'):
                continue  # Bereits transformierte Dateien überspringen

            self.get_logger().info(f"Loading trajectory from {csv_file}")
            traj_in_worldframe = load_csv_to_trajectory(filepath=csv_file)

            traj_in_workframe = []
            for traj_point in traj_in_worldframe:
                pos_in_worldframe = traj_point[0]
                rot_in_worldframe = traj_point[1]

                pos_in_workframe = T_world_in_workframe @ np.hstack((np.array(pos_in_worldframe), 1))
                rot_in_workframe = T_world_in_workframe[:3, :3] @ np.array(rot_in_worldframe)

                traj_in_workframe.append((pos_in_workframe[:3].tolist(), rot_in_workframe.tolist()))

            # Neuen Dateinamen mit _work generieren
            base, ext = os.path.splitext(csv_file)
            new_filename = f"{base}_work{ext}"

            save_trajectory_to_csv(trajectory=traj_in_workframe, filepath=new_filename)
            self.get_logger().info(f"Saved transformed trajectory to {new_filename}")


def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryBatchConverter()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
