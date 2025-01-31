import rclpy
from rclpy.node import Node
import numpy as np
from kr_msgs.srv import GetSystemFrame
from kr_msgs.srv import SetSystemFrame


class DefineWorkingFrameNeedle(Node):
    def __init__(self):
        super().__init__('define_working_frame_needle')

        self.get_kassow_frame_client = self.create_client(GetSystemFrame, '/kr/robot/get_system_frame')
        while not self.get_kassow_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Service GetSystemFrame...")
        self.get_logger().info("Service GetSystemFrame available!")

        self.set_kassow_frame_client = self.create_client(SetSystemFrame, '/kr/robot/set_system_frame')
        while not self.set_kassow_frame_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for Service SetSystemFrame...")
        self.get_logger().info("Service SetSystemFrame available!")

        self.Trans_needle_tfc = [0.0, 0.0, 73.0]        # in mm
        self.Rot_needle_tfc = [0.0, 0.0, 0.0]           # in Grad
        
        self.set_frame(self.Rot_needle_tfc, self.Trans_needle_tfc, frame="tcp", ref_frame="tfc")        # setze Frame TCP auf die Nadel

        self.stations = ['Init', 'REF', 'POS1', 'POS2']
        self.current_station = 0
        self.get_logger().info(f'Start at {self.stations[self.current_station]}')
        self.run_sequence()


    def set_frame(self, R, T, frame="tcp", ref_frame="tfc"):
        request = SetSystemFrame.Request()
        request.name = frame
        request.ref = ref_frame
        request.pos = T
        request.rot = R

        future = self.set_kassow_frame_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Frame '{frame}' set successfully!")
            else:
                self.get_logger().warn(f"Failed to set frame '{frame}'!")
        except Exception as e:
            self.get_logger().error(f"Service call of SetSystemFrame failed: {e}")


    def get_frame(self, frame="tcp", ref_frame="world"):
        request = GetSystemFrame.Request()
        request.name = frame
        request.ref = ref_frame

        future = self.get_kassow_frame_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Read Frame '{frame}' successfully!")
                return self.create_transform_matrix(translation=response.pos, rotation=response.rot)
            else:
                self.get_logger().warn(f"Failed to read Frame '{frame}'!")
        except Exception as e:
            self.get_logger().error(f"Service call of GetSystemFrame failed: {e}")
            return None


    def calc_rotation_matrix_from_rpy(self, rotation=[0.0, 0.0, 0.0]):
        ax, ay, az = np.radians(rotation)

        R_x = np.array([[1.0, 0.0, 0.0],
                        [0.0, np.cos(ax), -np.sin(ax)],
                        [0.0, np.sin(ax), np.cos(ax)]])
        R_y = np.array([[np.cos(ay), 0.0, np.sin(ay)],
                        [0.0, 1.0, 0.0],
                        [-np.sin(ay), 0.0, np.cos(ay)]])
        R_z = np.array([[np.cos(az), -np.sin(az), 0.0],
                        [np.sin(az), np.cos(az), 0.0],
                        [0.0, 0.0, 1.0]])
        return R_z @ R_y @ R_x
    
    def create_transform_matrix(self, translation=[0.0, 0.0, 0.0], rotation=[0.0, 0.0, 0.0]):
        T = np.eye(4)
        T[:3, :3] = self.calc_rotation_matrix_from_rpy(rotation=rotation)
        T[:3, 3] = translation
        return T



    def run_sequence(self):
        while self.current_station < (len(self.stations)-1):
            if self.stations[self.current_station] == 'Init':
                self.Init()
            elif self.stations[self.current_station] == 'REF':
                self.save_REF()
            elif self.stations[self.current_station] == 'POS1':
                self.save_POS1()            
            
            user_input = input()

            if user_input.strip().lower() == 'done':
                self.current_station += 1
            else:
                self.get_logger().info('Ungültige Eingabe. Bitte "done" eingeben.')
        self.save_POS2_and_calculate_transform()
        self.get_logger().info("Done!")

    def Init(self):
        self.get_logger().info("Move Robot Needle to <REF>... then type <done>")
        
    def save_REF(self):
        # speichere REF System Punkt in Bezug auf WORLD
        self.T_ref_world = self.get_frame(frame="tcp", ref_frame="world")
        self.get_logger().info("Move Robot Needle to <POS1>... then type <done>")
        
    def save_POS1(self):
        # speichere POS1 System Punkt in Bezug auf WORLD
        self.T_pos1_world = self.get_frame(frame="tcp", ref_frame="world")
        self.get_logger().info("Move Robot Needle to <POS2>... then type <done>")
        
    def save_POS2_and_calculate_transform(self):
        # speichere POS2 System Punkt in Bezug auf WORLD
        self.T_pos2_world = self.get_frame(frame="tcp", ref_frame="world")
        self.get_logger().info("Calculating Transformation between WORLD and REF...")
        trans_ref_world = self.T_ref_world[:3, 3]
        trans_ref_pos1 = self.T_pos1_world[:3, 3] - self.T_ref_world[:3, 3]
        trans_ref_pos2 = self.T_pos2_world[:3, 3] - self.T_ref_world[:3, 3]
        
        # normieren der Achsenvektoren
        trans_ref_pos1_norm = np.linalg.norm(trans_ref_pos1)
        trans_ref_pos2_norm = np.linalg.norm(trans_ref_pos2)
        trans_ref_pos1 /= trans_ref_pos1_norm if trans_ref_pos1_norm != 0 else 1
        trans_ref_pos2 /= trans_ref_pos2_norm if trans_ref_pos2_norm != 0 else 1

        # z-Achse als Kreuzprodukt
        y = np.cross(-trans_ref_pos1, trans_ref_pos2)
        y_norm = np.linalg.norm(y)
        y /= y_norm if y_norm != 0 else 1  

        # in T_work_world einsortieren -> spaltenweise
        T_work_world = np.eye(4)
        T_work_world[:3, 0] = trans_ref_pos1        # neue x-Achse
        T_work_world[:3, 1] = y                     # neue y-Achse
        T_work_world[:3, 2] = trans_ref_pos2        # neue z-Achse
        T_work_world[:3, 3] = trans_ref_world       # Translation von WORLD zu WORK
        
        np.savetxt('/home/mo/Thesis/src/robot_control/robot_control/data/WORK_frame_in_world.csv', T_work_world, delimiter=",", fmt="%.6f")
        self.get_logger().info("Transformation between WORLD and REF saved as <WORK_frame_in_world.csv>")
        
        

def main(args=None):
    rclpy.init(args=args)
    node = DefineWorkingFrameNeedle()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
