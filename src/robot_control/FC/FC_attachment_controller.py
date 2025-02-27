import rclpy
from rclpy.node import Node
from FC.FC_save_load_global_hook_dict import load_csv_to_dict
from FC.FC_hook_geometrics_handler import HookGeometricsHandler
from FC.FC_cam_geometrics_handler import CamGeometricsHandler
from FC.FC_frame_handler import FrameHandler
import numpy as np



class TrajectoryController(Node):
    def __init__(self, logging_active = False, p_gain_translation = 0.0, p_gain_rotation = 0.0, img_width = 896, img_height = 450):
        super().__init__("trajectory_controller")

        # Logging
        self.logging_active = logging_active

        # Instanzen HookGeometricsHandler, FrameHandler und CamGeometricsHandler
        self.hook_geometrics_handler = HookGeometricsHandler()
        self.frame_handler = FrameHandler(node_name = "frame_handler_for_attachment_controller")
        self.cam_geometrics_handler = CamGeometricsHandler(img_width = img_width, img_height = img_height)

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

        # Zykluszeit für die Regelung
        self.controller_cycle_time = 0.001

        # Regler-Output Stellgroesse
        self.velocity_trans = [0.0, 0.0, 0.0]
        self.velocity_rot = [0.0, 0.0, 0.0]




    def set_control(self, activate = False):
        """
        Setzt Regelung auf Aktiv oder Inaktiv
        """
        if activate:
            self.controller_active = True
            self.set_controller_timer()
        else:
            self.controller_active = False
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
        if self.controller_timer_active == True:
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



    def trajectory_controller(self, path_point_act, path_point_seq):
        """
        Funktion für Trajectory Controller -> Regelung basierend auf Path Points aus Global CSV Dict (nach einmaligem Scan-Vorgang)
        """
        # Falls Lochebene noch nicht berechnet wurde, berechne Lochebene
        if self.plane_trans_in_tfcframe is None or self.plane_rot_in_tfcframe is None:
            self.set_plane_parameters()     # falls noch keine Plane-Parameter definiert sind, nehme default-Werte

        if self.plane is None and self.plane_trans_in_tfcframe is not None and self.plane_rot_in_tfcframe is not None:
            self.plane = self.hook_geometrics_handler.calculate_plane(
                trans_in_tfcframe = self.plane_trans_in_tfcframe, 
                rot_in_tfcframe = self.plane_rot_in_tfcframe)


        # Update Haken Koordinaten und Berechnung Haken-Gerade im TFC-Frame -> muss zyklisch wiederholt werden
        self.hook_geometrics_handler.update_hook_data(hook_num = self.global_hook_num)
        self.hook_geometrics_handler.calculate_hook_line(p_0 = path_point_seq, p_1 = path_point_act)


        # Berechne aktuellen Regelfehler
        adjustment_angles = self.hook_geometrics_handler.calculate_adjustment_angles()
        translation_diff = self.hook_geometrics_handler.calculate_translation_difference()


        # Rechne Regelfeher von TFC-Frame ins WORLD-Frame um
        translation_diff_worldframe = self.frame_handler.tansform_velocity_to_world(vel = translation_diff, from_frame = 'tfc')
        rotation_diff_worldframe = self.frame_handler.tansform_velocity_to_world(vel = adjustment_angles, from_frame = 'tfc')


        # Logge, falls gewünscht
        if self.logging_active:
            self.get_logger().info(f"Controller Output: {translation_diff_worldframe}, {rotation_diff_worldframe}")
        
        
        # P-Regler
        self.velocity_trans = translation_diff_worldframe * self.p_gain_translation
        self.velocity_rot = rotation_diff_worldframe * self.p_gain_rotation



    def control_feedback_algorithm(self, act_path_point = None, seq_path_point = None, hook_num = 1, plane = None):
        """
        Berechnet die aktuelle Regelabweichung
        """
        if act_path_point is not None:
            # Hook-Daten mit gewuenschtem Index aktualisieren
            self.hook_geometrics_handler.update_hook_data(hook_num = hook_num)

            x = act_path_point[0]
            y = act_path_point[1]
            z = act_path_point[2]
            
            # Differenz zwischen aktuellem Path Point und Mittelpunkt der Lochebene
            trans_diff_in_tfcframe = self.hook_geometrics_handler.calculate_translation_difference(target_position = [x, y, z])

            # Aktualisierung der Geraden (zwischen jetzigem PPoint und nachfolgendem PPoint)
            if seq_path_point is not None:
                self.hook_geometrics_handler.calculate_hook_line(p_1 = act_path_point, p_0 = seq_path_point)

            # Berechnung der rotatorischen Stellgröße
            rot_diff_in_tfcframe = self.hook_geometrics_handler.calculate_adjustment_angles(plane = plane, line_dir = self.hook_line['p_dir'])
            return trans_diff_in_tfcframe, rot_diff_in_tfcframe



    def visual_servoing_control(self, hook_num = 1, plane = None):
        """
        Enthält den Regelungs-Ablauf für das Einfädeln
        """
        for idx in range(len(self.path_points_in_tfcframe)):
            # Aktueller Status des Einfädelvorgangs
            if idx == 0:
                self.control_state = "tip"                          # Spitze
            elif idx == (len(self.path_points_in_tfcframe) - 1):
                self.control_state == "lowpoint"                    # Senke
            else:
                self.control_state == "pp_" + str(idx)              # Zwischenpunkt n

            # Extraktion des Zielpunkts und des nachfolgenden Zielpunkts
            act_path_point = self.path_points_in_tfcframe[idx]

            if self.control_state != "lowpoint":
                seq_path_point = self.path_points_in_tfcframe[idx + 1]
            
            # Erlaubte Toleranzen für Translation und Rotation
            translation_tolerance = [0.5, 0.5, 0.5]
            rotation_tolerance = [2.0, 2.0, 2.0]

            while True:
                # Regelfehler berechnen
                self.trans_diff_in_tfcframe, self.rot_diff_in_tfcframe = self.hook_geometrics_handler.control_feedback_algorithm(
                    act_path_point=act_path_point,
                    seq_path_point=seq_path_point,
                    hook_num=hook_num,
                    plane=plane)

                # Absolutwerte der Fehler berechnen
                abs__trans_diff_in_tfcframe = np.abs(self.trans_diff_in_tfcframe)
                abs__rot_diff_in_tfcframe = np.abs(self.rot_diff_in_tfcframe)

                # Toleranzprüfung
                if np.all(abs__trans_diff_in_tfcframe <= translation_tolerance) and np.all(abs__rot_diff_in_tfcframe <= rotation_tolerance):
                    break  # Fehler innerhalb der Toleranz, zum nächsten Path Point übergehen




def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
