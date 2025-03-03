import os
import csv
import rclpy
from rclpy.node import Node



class ControllerDataLogger(Node):
    def __init__(self, directory = "/home/mo/Thesis/src/robot_control/robot_control/data/controller_output_logging"):
        super().__init__('logging_node')
        self.directory = directory
        self.new_path_point_selected = False
        
        self.log_iterations = []
        self.log_vel_trans_x = []
        self.log_vel_trans_y = []
        self.log_vel_trans_z = []
        self.log_vel_rot_x = []
        self.log_vel_rot_y = []
        self.log_vel_rot_z = []
        self.log_path_points = []



    def log_controller_output(self, velocity_trans = [0.0, 0.0, 0.0], velocity_rot = [0.0, 0.0, 0.0]):
        """
        Logging der Stellgrößen in Listen
        """
        self.log_iterations.append(len(self.log_iterations) + 1)
        self.log_vel_trans_x.append(velocity_trans[0])
        self.log_vel_trans_y.append(velocity_trans[1])
        self.log_vel_trans_z.append(velocity_trans[2])
        self.log_vel_rot_x.append(velocity_rot[0])
        self.log_vel_rot_y.append(velocity_rot[1])
        self.log_vel_rot_z.append(velocity_rot[2])

        if not self.new_path_point_selected:
            self.log_path_points.append(0)
        else:
            self.log_path_points.append(1)
            self.new_path_point_selected = False



    def reset_logging_lists(self):
        """
        Leert die Logging-Listen
        """
        self.log_iterations.clear()
        self.log_vel_trans_x.clear()
        self.log_vel_trans_y.clear()
        self.log_vel_trans_z.clear()
        self.log_vel_rot_x.clear()
        self.log_vel_rot_y.clear()
        self.log_vel_rot_z.clear()
        self.log_path_points.clear()
    


    def save_logging_lists(self):
        """
        Speichert die Logging-Listen als CSV-Datei
        """
        os.makedirs(self.directory, exist_ok=True)
        
        data_dict = {
            "iterations": self.log_iterations,
            "vel_trans_x": self.log_vel_trans_x,
            "vel_trans_y": self.log_vel_trans_y,
            "vel_trans_z": self.log_vel_trans_z,
            "vel_rot_x": self.log_vel_rot_x,
            "vel_rot_y": self.log_vel_rot_y,
            "vel_rot_z": self.log_vel_rot_z,
            "path_points": self.log_path_points
        }
        
        file_path = os.path.join(self.directory, "controller_output_log.csv")
        
        try:
            with open(file_path, mode='w', newline='') as file:
                writer = csv.writer(file)
                writer.writerow(data_dict.keys())
                for row in zip(*data_dict.values()):
                    writer.writerow(row)
            
            self.get_logger().info(f"Logging-Daten erfolgreich gespeichert unter: {file_path}")
        except Exception as e:
            self.get_logger().error(f"Fehler beim Speichern der Logging-Daten: {e}")



    def load_logging_lists(self):
        """
        Lädt die Logging-Daten aus einer CSV-Datei zurück in die Listen.
        """
        file_path = os.path.join(self.directory, "controller_output_log.csv")
        
        if not os.path.exists(file_path):
            self.get_logger().error(f"Datei nicht gefunden: {file_path}")
            return
        
        try:
            with open(file_path, mode='r', newline='') as file:
                reader = csv.reader(file)
                headers = next(reader)
                data = list(reader)
            
            if not data:
                self.get_logger().error("Die CSV-Datei enthält keine Daten.")
                return
            
            data_dict = {key: [] for key in headers}
            for row in data:
                for key, value in zip(headers, row):
                    data_dict[key].append(float(value))
            
            self.log_iterations = data_dict["iterations"]
            self.log_vel_trans_x = data_dict["vel_trans_x"]
            self.log_vel_trans_y = data_dict["vel_trans_y"]
            self.log_vel_trans_z = data_dict["vel_trans_z"]
            self.log_vel_rot_x = data_dict["vel_rot_x"]
            self.log_vel_rot_y = data_dict["vel_rot_y"]
            self.log_vel_rot_z = data_dict["vel_rot_z"]
            self.log_path_points = data_dict["path_points"]
            
            self.get_logger().info(f"Logging-Daten erfolgreich geladen aus: {file_path}")
        except Exception as e:
            self.get_logger().error(f"Fehler beim Laden der Logging-Daten: {e}")




def main(args=None):
    rclpy.init(args=args)
    node = ControllerDataLogger()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
