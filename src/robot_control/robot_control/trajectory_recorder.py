import rclpy
from rclpy.node import Node
from kr_msgs.srv import GetRobotPose
import sys
import termios
import tty
import select
from FC.FC_eval_save_trajectory_to_csv import save_trajectory_to_csv
from FC.FC_frame_handler import FrameHandler
import numpy as np


class TrajectoryRecorder(Node):
    def __init__(self):
        super().__init__('trajectory_recorder')

        self.cli = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service GetRobotPose...')

        # Instanz Frame Handler
        self.frame_handler = FrameHandler(node_name = 'frame_handler_for_trajectory_recorder_node')


        self.trajectory_recorded_in_workframe = []
        self.trajectory_recorded_in_worldframe = []
        self.get_logger().info('Press "n" to save current pose, "s" to save to CSV...')

        # Für Tastatureingaben im raw mode
        self.fd = sys.stdin.fileno()
        self.old_settings = termios.tcgetattr(self.fd)
        tty.setcbreak(self.fd)  # Wichtig: non-blocking read ermöglichen

        self.create_timer(0.1, self.timer_callback)  # 100ms Timer




    def timer_callback(self):
        if self.key_pressed():
            key = sys.stdin.read(1)
            if key == 'n':
                self.get_logger().info('Key "n" pressed – reading robot pose...')
                self.call_service()
            elif key == 's':
                self.get_logger().info('Key "s" pressed – saving trajectory to CSV...')
                try:
                    save_trajectory_to_csv(
                        self.trajectory_recorded_in_workframe,
                        filepath='/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_0_work.csv'
                    )
                    save_trajectory_to_csv(
                        self.trajectory_recorded_in_worldframe,
                        filepath='/home/mo/Thesis/Evaluation/Trajektorientests/trajectory_0.csv'
                    )
                    self.get_logger().info('Trajectory successfully saved to CSV.')
                except Exception as e:
                    self.get_logger().error(f'Failed to save trajectory: {e}')



    def key_pressed(self):
        return select.select([sys.stdin], [], [], 0)[0] != []



    def call_service(self):
        req = GetRobotPose.Request()
        future = self.cli.call_async(req)
    
        # Überprüfen, ob der Service-Call abgeschlossen ist
        def service_callback(future):
            if future.result() is not None:
                pos = list(future.result().pos)
                rot = list(future.result().rot)
                self.trajectory_recorded_in_worldframe.append((pos, rot))

                T_world_in_workframe = self.frame_handler.get_world_in_workframe()
                pos_in_workframe = T_world_in_workframe @ np.hstack((np.array(pos), 1))
                rot_in_workframe = T_world_in_workframe[:3, :3] @ np.array(rot)

                self.trajectory_recorded_in_workframe.append((pos_in_workframe[:3].tolist(), rot_in_workframe.tolist()))
                self.get_logger().info(f'Pose recorded [WORK]: pos={pos_in_workframe[:3]}, rot={rot_in_workframe}')
                self.get_logger().info(f'Pose recorded [WORLD]: pos={pos}, rot={rot}')
            else:
                self.get_logger().error('Service call failed!')
    
        future.add_done_callback(service_callback)  # Asynchrone Callback-Funktion hinzufügen



    def destroy_node(self):
        termios.tcsetattr(self.fd, termios.TCSADRAIN, self.old_settings)  # Terminal zurücksetzen
        super().destroy_node()



def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryRecorder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.get_logger().info(f'{len(node.trajectory_recorded_in_workframe)} poses recorded.')
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
