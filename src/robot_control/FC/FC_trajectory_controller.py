import rclpy
from rclpy.node import Node
from FC.FC_hook_geometrics_handler import HookGeometricsHandler
from FC.FC_cam_geometrics_handler import CamGeometricsHandler
from FC.FC_frame_handler import FrameHandler
from FC.FC_controller_data_logger import ControllerDataLogger



class TrajectoryController(Node):
    def __init__(self, logging_active = False, 
                 controller_output_logging_active = False, 
                 p_gain_translation = 0.0, 
                 p_gain_rotation = 0.0, 
                 img_width = 896, 
                 img_height = 450):
        
        super().__init__("trajectory_controller")

        # Logging
        self.logging_active = logging_active
        self.controller_output_logging_active = controller_output_logging_active
        self.controller_data_logger = ControllerDataLogger()

        # Instanzen HookGeometricsHandler, FrameHandler und CamGeometricsHandler
        self.hook_geometrics_handler = HookGeometricsHandler()
        self.frame_handler = FrameHandler(node_name = "frame_handler_for_attachment_controller")
        # self.cam_geometrics_handler = CamGeometricsHandler(img_width = img_width, img_height = img_height)

        # Variablen für P-Regler translatorisch und rotatorisch
        self.p_gain_translation = p_gain_translation
        self.p_gain_rotation = p_gain_rotation

        # Prozess-Variablen
        self.global_hook_num = None
        self.controller_active = False
        self.controller_callback_timer = None
        self.controller_timer_active = False
        self.act_point = None
        self.seq_point = None
        self.plane = None
        self.plane_trans_in_tfcframe = None
        self.plane_rot_in_tfcframe = None
        self.hook_line_p_0 = None
        self.hook_line_p_1 = None
        self.act_path_point_idx = None
        self.translation_diff_worldframe = None
        self.rotation_diff_worldframe = None
        self.handle_last_trajectory_point = False

        # Tolearnz-Werte für Translation und Rotation
        self.translation_tolerance = 0.01  # Beispielwert
        self.rotation_tolerance = 0.01  # Beispielwert


        # Zykluszeit für die Regelung
        self.controller_cycle_time = 0.001

        # Regler-Output Stellgroesse
        self.velocity_trans = [0.0, 0.0, 0.0]
        self.velocity_rot = [0.0, 0.0, 0.0]

        # Logging Listen für Controller Output
        self.log_iterations = []
        self.log_vel_trans_x = []
        self.log_vel_trans_y = []
        self.log_vel_trans_z = []
        self.log_vel_rot_x = []
        self.log_vel_rot_y = []
        self.log_vel_rot_z = []
        self.log_path_points = []




    def set_control(self, activate = False):
        """
        Setzt Regelung auf Aktiv oder Inaktiv
        """
        if activate:
            self.controller_active = True
            self.handle_last_trajectory_point = False
            self.set_controller_timer()
        else:
            self.controller_active = False
            self.handle_last_trajectory_point = False
            self.stop_controller_timer()


    def set_controller_parameters(self, p_gain_translation = 0.0, p_gain_rotation = 0.0):
        """
        Setzt die Parameter der P-Regler
        """
        self.p_gain_translation = p_gain_translation
        self.p_gain_rotation = p_gain_rotation

    
    def set_controller_timer(self):
        """
        Startet den Callback-Timer für die Regelung
        """
        if self.controller_timer_active == False:
            self.controller_callback_timer = self.create_timer(timer_period_sec = self.controller_cycle_time, callback = self.trajectory_controller)
            self.controller_timer_active = True
    

    def stop_controller_timer(self):
        """
        Stoppt den Callback-Timer für die Regelung
        """
        if self.controller_timer_active and self.controller_callback_timer is not None:
            self.controller_callback_timer.cancel()
            self.controller_timer_active = False


    def set_hook_num(self, global_hook_num):
        """
        Setzt die Regelung auf die Hakennummer (global)
        """
        self.global_hook_num = global_hook_num


    def reset_plane(self):
        """
        Funktion für das Rücksetzen der Lochebene -> wird dann zu Beginn des nächsten Regelungszyklus neu berechnet
        """
        self.plane = None

    
    def set_plane_parameters(self, trans_in_tfcframe = [0.0, 0.0, 112.0], rot_in_tfcframe = [0.0, 0.0, 0.0]):
        """
        Funktion für das Setzen der aktuellen Parameter der Loch-Ebene
        """
        self.plane_trans_in_tfcframe = trans_in_tfcframe
        self.plane_rot_in_tfcframe = rot_in_tfcframe

    
    def update_path_point_idx(self, idx = 0):
        """
        Funktion zur Aktualisierung des Path Point Index -> für Vorgabe vor Beginn der Regelung sinnvoll
        """
        self.act_path_point_idx = idx

    
    def shift_path_points(self):
        """
        Funktion zum Überprüfen, ob Vorgabepunkt (Path Point) erreicht wurde -> wenn ja, nächster Path Point
        """
        # Überprüfe aktuelle Punkte für Geradenberechnung (Path Points) -> wenn aktuelle Stellgroesse nahe Null, dann nächster Punkt
        if self.act_path_point_idx is None:
            self.update_path_point_idx(idx = 0)     # falls nicht anders festgelegt, beginne bei erstem Path-Point
        
        # Überprüfen, ob Regelfehler unter Toleranz liegt
        if abs(self.translation_diff_worldframe) <= self.translation_tolerance and abs(self.rotation_diff_worldframe) <= self.rotation_tolerance:
            self.act_path_point_idx += 1
            self.controller_data_logger.new_path_point_selected = True

        # Extraktion der Punkte in Abhängigkeit des Index
        if self.act_path_point_idx + 1 < len(self.hook_geometrics_handler.path_points_in_tfcframe):
            self.hook_line_p_1 = self.hook_geometrics_handler.path_points_in_tfcframe[self.act_path_point_idx]
            self.hook_line_p_0 = self.hook_geometrics_handler.path_points_in_tfcframe[self.act_path_point_idx + 1]
        elif self.act_path_point_idx == len(self.hook_geometrics_handler.path_points_in_tfcframe):
            self.get_logger().info("Trajectory control done.")
            if self.controller_output_logging_active == True:
                self.controller_data_logger.save_logging_lists()
                self.controller_data_logger.reset_logging_lists()
        else:
            self.get_logger().info("Handling last point of trajectory.")
            self.handle_last_trajectory_point = True


    def trajectory_controller(self):
        """
        Funktion für Trajectory Controller -> Regelung basierend auf Path Points aus Global CSV Dict (nach einmaligem Scan-Vorgang)
        """
        # Falls noch keine Plane-Parameter definiert sind, nehme default-Werte
        if self.plane_trans_in_tfcframe is None or self.plane_rot_in_tfcframe is None:
            self.set_plane_parameters()
            
        # Falls Lochebene noch nicht berechnet wurde, berechne Lochebene
        if self.plane is None and self.plane_trans_in_tfcframe is not None and self.plane_rot_in_tfcframe is not None:
            self.plane = self.hook_geometrics_handler.calculate_plane(trans_in_tfcframe = self.plane_trans_in_tfcframe, rot_in_tfcframe = self.plane_rot_in_tfcframe)

        # Path Points überprüfen und ggf eins weiter shiften
        self.shift_path_points()

        # Update Haken Koordinaten und Berechnung Haken-Gerade im TFC-Frame -> muss zyklisch wiederholt werden
        self.hook_geometrics_handler.update_hook_data(hook_num = self.global_hook_num)
        self.hook_geometrics_handler.calculate_hook_line(p_0 = self.hook_line_p_0, p_1 = self.hook_line_p_1)


        # Berechne aktuellen Regelfehler
        adjustment_angles = self.hook_geometrics_handler.calculate_adjustment_angles()

        # Translation -- Falls Trajektorie fertig -> Positionierung an Senke
        if self.handle_last_trajectory_point == True:
            translation_diff = self.hook_geometrics_handler.calculate_translation_difference(calculate_translation_difference = True)
        else:       # ansonsten -> fahre die Trajektorie-Punkte an
            translation_diff = self.hook_geometrics_handler.calculate_translation_difference(calculate_translation_difference = False)


        # Rechne Regelfeher von TFC-Frame ins WORLD-Frame um
        self.translation_diff_worldframe = self.frame_handler.transform_velocity_to_world(vel = translation_diff, from_frame = 'tfc')
        self.rotation_diff_worldframe = self.frame_handler.transform_velocity_to_world(vel = adjustment_angles, from_frame = 'tfc')

        # Logge, falls gewünscht
        if self.logging_active:
            self.get_logger().info(f"Controller Output: {self.translation_diff_worldframe}, {self.rotation_diff_worldframe}")

        # P-Regler
        self.velocity_trans = self.translation_diff_worldframe * self.p_gain_translation
        self.velocity_rot = self.rotation_diff_worldframe * self.p_gain_rotation

        # Falls aktiv -> logging der Stellgroessen
        if self.controller_output_logging_active == True:
            self.controller_data_logger.log_controller_output()





def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("TrajectoryController wird beendet.")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
