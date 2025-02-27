import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Int32
from cv_bridge import CvBridge
import numpy as np
import torch
import cv2
from ultralytics import YOLO
import time
import sys
from action_interfaces.msg import HookData
from concurrent.futures import ThreadPoolExecutor
from FC_vision.FC_ema_filter import HookFilterEMA
from FC_vision.FC_moving_avg_filter import HookFilterMovingAvg
from FC_vision.FC_yolo_output_processor import YoloPostprocessor
from FC_vision.FC_plot_yolo_imgs import plot_hooks_and_bars, plot_points, plot_combined_skeletons
from FC_vision.FC_process_hooks_dict_for_publishing import process_hook_for_publisher
from FC_vision.FC_two_cam_stereo_triangulation_processor import TwoCamStereoTriangulationProcessor
from FC_vision.FC_parameterized_cubic_spline import ParameterizedCubicSplineCalculator



class YOLOv8TwoImgInferenceNode(Node):
    def __init__(self):
        super().__init__('yolov8_dualcam_inference')

        self.declare_parameter('yolo_model_path', '/home/mo/Thesis/YoloV8_InstanceSeg/runs/train/medium/full_set/20250118_1640/weights/best.pt')
        self.yolo_model_path = self.get_parameter('yolo_model_path').get_parameter_value().string_value
        self.declare_parameter('confidence_threshold', 0.2)
        self.confidence_threshold = self.get_parameter('confidence_threshold').get_parameter_value().double_value
        self.declare_parameter('do_preprocessing', True)
        self.do_preprocessing = self.get_parameter('do_preprocessing').get_parameter_value().bool_value
        self.declare_parameter('show_cam_img', True)
        self.show_cam_img = self.get_parameter('show_cam_img').get_parameter_value().bool_value
        self.declare_parameter('show_output_img', True)
        self.show_output_img = self.get_parameter('show_output_img').get_parameter_value().bool_value
        self.declare_parameter('show_point_img', True)
        self.show_point_img = self.get_parameter('show_point_img').get_parameter_value().bool_value
        self.declare_parameter('show_skeleton_img', True)
        self.show_skeleton_img = self.get_parameter('show_skeleton_img').get_parameter_value().bool_value
        self.declare_parameter('publish_masks', True)
        self.publish_masks = self.get_parameter('publish_masks').get_parameter_value().bool_value
        self.declare_parameter('filter_alpha', 1.0)
        self.filter_alpha = self.get_parameter('filter_alpha').get_parameter_value().double_value
        self.declare_parameter('filter_windowsize', 10)
        self.filter_windowsize = self.get_parameter('filter_windowsize').get_parameter_value().integer_value

        # Subscriber auf VC Cam
        self.subscription = self.create_subscription(Image, 'vcnanoz/image_raw', self.image_1_callback, 1)

        # Subscriber auf VC Cam 2
        self.img_2_subscription = self.create_subscription(Image, 'vcnanoz/image_raw_2', self.image_2_callback, 1)

        # Subscriber für Bildaufloesung
        self.img_width = 896
        self.img_height = 450
        self.img_width_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/width', callback = self.img_width_receive_callback)
        self.img_height_sub = self.create_subscription(Int32, 'vcnanoz/image_raw/height', callback = self.img_height_receive_callback)

        # Publisher für Netz Output
        self.hooks_dict_publisher_ = self.create_publisher(HookData, 'yolov8_output/hooks_dict', 10)
        self.timer = self.create_timer(0.0001, self.publish_hooks_dict)

        # Publisher für Segmentation Img und Point Img (Output)
        self.output_segment_img_publisher = self.create_publisher(Image, 'yolov8_output/output_segment_img', 10)
        self.output_point_img_publisher = self.create_publisher(Image, 'yolov8_output/output_point_img', 10)

        # Filterinstanzen zur Filterung des Outputs
        # self.img1_ema_filter = HookFilterEMA(alpha = self.filter_alpha, confirmation_frames = 10, disappearance_frames = 5)
        # self.img2_ema_filter = HookFilterEMA(alpha = self.filter_alpha, confirmation_frames = 10, disappearance_frames = 5)
        self.img1_movingavg_filter = HookFilterMovingAvg(window_size = self.filter_windowsize, confirmation_frames = 10, disappearance_frames = 5)
        self.img2_movingavg_filter = HookFilterMovingAvg(window_size = self.filter_windowsize, confirmation_frames = 10, disappearance_frames = 5)

        # Variablen
        self.bridge = CvBridge()
        self.input_img_1 = None
        self.input_img_2 = None
        self.output_img = None
        self.points_img = None
        self.skeleton_img = None
        self.get_logger().info('YOLOv8 Inference Node started...')

        # Laden des Modells
        self.get_logger().info("Loading YoloV8 model...")
        self.yolo_model = YOLO(self.yolo_model_path)
        self.get_logger().info("YoloV8 model loaded!")

        # Inferenzdevice auswählen - wenn möglich GPU
        self.inference_device = "cpu"
        self.set_device()

        # Dicts für Output Verarbeitung
        self.img1_bar_dict = {}
        self.img2_bar_dict = {}
        self.img1_hooks_dict = {}
        self.img2_hooks_dict = {}
        self.img1_hooks_dict_processed = {}
        self.img2_hooks_dict_processed = {}
        self.img1_filtered_hooks_dict = {}
        self.img2_filtered_hooks_dict = {}

        # Instanz des Spline-Calculator
        self.spline_calculator = ParameterizedCubicSplineCalculator()

        # Instanz YoloPostprocessor
        self.yolo_postprocessor = YoloPostprocessor()

        # Instanz Triangulation Processor
        self.triangulation_processor = TwoCamStereoTriangulationProcessor(extrinsic_data = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
                                                                          measure_time = True,
                                                                          img_width = self.img_width,
                                                                          img_height = self.img_height)
        
        

    def img_width_receive_callback(self, msg):
        self.img_width = msg.data
    
    def img_height_receive_callback(self, msg):
        self.img_height = msg.data


    def set_device(self):
        """
        Wählt das Gerät (GPU oder CPU) für die Inferenz aus
        """
        self.get_logger().info("Setting device for neural network inferences...")

        if torch.cuda.is_available():
            self.inference_device = "cuda"

            # Begrenze Speicher auf 60%
            torch.cuda.set_per_process_memory_fraction(0.6, 0)

            # Begrenzung der Speicherwachstumsstrategie aktivieren
            gpus = torch.cuda.device_count()
            for gpu_id in range(gpus):
                torch.cuda.set_device(gpu_id)
                torch.cuda.empty_cache()  # Cache leeren, um Speicher freizugeben
                torch.cuda.memory.set_per_process_memory_fraction(0.6, gpu_id)

            self.get_logger().info(f"GPU available - using GPU as inference device. Total GPUs: {gpus}")
        else:
            self.inference_device = "cpu"
            self.get_logger().info("No GPU available - using CPU as inference device.")



    def image_1_callback(self, msg):
        """
        Callback für Img 1 Topic mit Preprocessing für Inferenz
        """
        try:
            # Bild nach Topic-Empfang konvertieren zu OpenCV Img
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

            # Preprocessing  - Teilbarkeit der Auflösung durch 32
            self.input_img_1 = self.preprocess(cv_image)
        except Exception as e:
            self.get_logger().error(f'Error in image 1 callback: {e}')



    def image_2_callback(self, msg):
        """
        Callback für Img 2 Topic mit Preprocessing für Inferenz
        """
        try:
            # Bild zurückwandeln
            cv_image = self.bridge_2.imgmsg_to_cv2(msg, desired_encoding = 'passthrough')
        
            # Proprocessing - Teilbarkeit der Auflösung durch 32
            self.input_img_2 = self.preprocess(cv_image)
        except Exception as e:
            self.get_logger().error(f'Error in image 2 callback: {e}')



    def inference_process(self):
        """
        Funktion für Inferenz mit 2 Bildern
        """
        try:
            # Inferenz
            if self.input_img_1 is not None and self.input_img_2 is not None:
                inp = [self.input_img_1, self.input_img_2]
                results = self.inference(input = inp)

            # Postprocessing
            results_1 = results[0]
            results_2 = results[1]

            self.img1_bar_dict, self.img1_hooks_dict = self.yolo_postprocessor.postprocess(results_1)
            self.img2_bar_dict, self.img2_hooks_dict = self.yolo_postprocessor.postprocess(results_2)

            # Berechnung der Spitzen- und Senken-Punkte auf Pixelebene
            self.img1_hooks_dict_processed = self.yolo_postprocessor.process_output_hooks_dict(hooks_dict = self.img1_hooks_dict)
            self.img2_hooks_dict_processed = self.yolo_postprocessor.process_output_hooks_dict(hooks_dict = self.img2_hooks_dict)

            '''
            ### Zuerst filtern und dann Pfad berechnen
            self.img1_filtered_hooks_dict = self.img1_movingavg_filter.update(hooks_dict = self.img1_hooks_dict_processed)
            self.img2_filtered_hooks_dict = self.img2_movingavg_filter.update(hooks_dict = self.img2_hooks_dict_processed)
            self.img1_filtered_hooks_dict = self.yolo_postprocessor.find_hooks_shape(hooks_dict = self.img1_filtered_hooks_dict, num_interpolation_points = 10)
            self.img2_filtered_hooks_dict = self.yolo_postprocessor.find_hooks_shape(hooks_dict = self.img2_filtered_hooks_dict, num_interpolation_points = 10)
            '''
            
            ### Zuerst Pfad berechnen und dann filtern (Pfad wird aber nicht mitgefiltert)
            self.img1_hooks_dict_processed = self.yolo_postprocessor.find_hooks_shape(hooks_dict = self.img1_hooks_dict_processed, num_interpolation_points = 10)
            self.img2_hooks_dict_processed = self.yolo_postprocessor.find_hooks_shape(hooks_dict = self.img2_hooks_dict_processed, num_interpolation_points = 10)
            self.img1_filtered_hooks_dict = self.movingavg_filter.update(hooks_dict = self.img1_hooks_dict_processed)
            self.img2_filtered_hooks_dict = self.movingavg_filter.update(hooks_dict = self.img2_hooks_dict_processed)
            

            # Zusammenführen der Dicts zu einem Output Dict (von Cam 1 aus gesehen) -> wird dann auch gepublisht
            self.filtered_hooks_dict = self.merge_output_hook_dicts(hooks_dict_1 = self.img1_filtered_hooks_dict,
                                                                    hooks_dict_2 = self.img2_filtered_hooks_dict)
            
            # Berechnung der Triangulation mit fertigem Dict und anhängen der XYZ-Daten an Dict
            self.filtered_hooks_dict = self.do_triangulation(hooks_dict = self.filtered_hooks_dict)

            # Berechne Path Point zwischen Spitze -> Senke und interpoliere XYZ-Werte
            self.filtered_hooks_dict = self.interpolate_depth_shape(hooks_dict = self.filtered_hooks_dict)
                    
            # Plots
            if self.show_cam_img:
                cv2.imshow('VC Cam 1 Img', self.input_img_1)
                cv2.waitKey(1)
                cv2.imshow('VC Cam 2 Img', self.input_img_2)
                cv2.waitKey(1)

            if self.show_output_img:
                '''
                self.output_img = plot_hooks_and_bars(received_img = self.received_img, hooks_dict = self.hooks_dict_processed, bar_dict = self.bar_dict)
                output_segment_img = self.bridge.cv2_to_imgmsg(self.output_img, encoding="bgr8")
                self.output_segment_img_publisher.publish(output_segment_img)
                cv2.imshow('YoloV8 Output Segment Img', self.output_img)
                cv2.waitKey(1)
                '''

                self.output_img1 = plot_hooks_and_bars(received_img = self.input_img_1, hooks_dict = self.img1_filtered_hooks_dict, bar_dict = self.img1_bar_dict)
                self.output_img2 = plot_hooks_and_bars(received_img = self.input_img_2, hooks_dict = self.img2_filtered_hooks_dict, bar_dict = self.img2_bar_dict)
                # output_segment_img1 = self.bridge.cv2_to_imgmsg(self.output_img1, encoding="bgr8")
                # self.output_segment_img_publisher.publish(output_segment_img1)
                cv2.imshow('YoloV8 Output Segment Img 1 Filtered', self.output_img1)
                cv2.waitKey(1)
                cv2.imshow('YoloV8 Output Segment Img 2 Filtered', self.output_img2)
                cv2.waitKey(1)

            '''
            if self.show_point_img:
                self.points_img = plot_points(received_img = self.received_img, hooks_dict = self.hooks_dict_processed)
                output_point_img = self.bridge.cv2_to_imgmsg(self.points_img, encoding="bgr8")
                self.output_point_img_publisher.publish(output_point_img)
                cv2.imshow('YoloV8 Output Point Img', self.points_img)
                cv2.waitKey(1)

                self.points_img1 = plot_points(received_img = self.input_img_1, hooks_dict = self.img1_filtered_hooks_dict)
                self.points_img2 = plot_points(received_img = self.input_img_2, hooks_dict = self.img2_filtered_hooks_dict)
                # output_point_img = self.bridge.cv2_to_imgmsg(self.points_img, encoding="bgr8")
                # self.output_point_img_publisher.publish(output_point_img)
                cv2.imshow('YoloV8 Output Point Img 1 Filtered', self.points_img1)
                cv2.waitKey(1)
                cv2.imshow('YoloV8 Output Point Img 2 Filtered', self.points_img2)
                cv2.waitKey(1)
            '''

            if self.show_skeleton_img:
                self.skeleton_img1 = plot_combined_skeletons(hooks_dict = self.img1_filtered_hooks_dict)
                if self.skeleton_img is not None:
                    cv2.imshow("Skeleton Mask Img 1", self.skeleton_img1)
                    cv2.waitKey(1)
                
        except Exception as e:
            self.get_logger().error(f'Error in inference process: {e}')

            

    def preprocess(self, cv_image):
        """
        Funktion für Preprocessing des Img zur Inferenz
        --- sorgt für eine Bildauflösung die durch 32 ohne Rest teilbar ist -> funktioniert stabiler mit Yolo
        """
        # cv_image[0:20, 0:300, :] = 255        # Ausblenden der VC-Cam-Schrift links oben im Eck -> nur bei Nutzung der vollen Kamerauflösung notwendig
        if self.do_preprocessing:
            w_units = cv_image.shape[1] // 32
            h_units = cv_image.shape[0] // 32
            input_img = cv_image[0:(h_units * 32), 0:(w_units * 32), :]
            return input_img


    def inference(self, input = None):
        """ 
        Funktion für die Inferenz des Yolo-Netzes -> Nimmt das aktuelle Bild und liefert den Output zurück
        --- wahlweise mit Zeitmessung und Berechnung der Inferenz-FPS
        """
        start_time = time.perf_counter()

        results = self.yolo_model.predict(source = input,
                                device = self.inference_device,
                                conf = self.confidence_threshold,
                                iou = 0.7,
                                max_det = 100,
                                visualize = False,
                                classes = [0, 1, 2, 3],
                                retina_masks = True,
                                show_conf = True,
                                show_boxes = True,
                                show_labels = True,
                                save = False,
                                show = False,
                                save_txt = False,
                                save_crop = False,
                                line_width = 2,
                                box = False,
                                verbose = False)
            
        end_time = time.perf_counter()
        inference_time = end_time - start_time
        fps = 1 / inference_time if inference_time > 0 else 0

        sys.stdout.write(f"\rInference time: {inference_time:.4f} sec | FPS: {fps:.4f}\n")
        sys.stdout.flush()
        # self.get_logger().info(f"\rInference time: {(end_time - start_time):.4f} sec")
        # self.get_logger().info(f"\rInference FPS: {(1/(end_time - start_time)):.4f} FPS")
        return results
    

    def merge_output_hook_dicts(self, hooks_dict_1, hooks_dict_2):
        """
        Überträgt die Koordinaten für Hook, Tip und Lowpoint aus Bild 2 in das Dict von Bild 1
        """
        for idx, key in enumerate(hooks_dict_1):
            hooks_dict_1[key]['uv_hook_img2'] = {}
            hooks_dict_1[key]['uv_hook_img2'] = hooks_dict_2[key]['uv_hook']
            hooks_dict_1[key]['uv_tip_img2'] = {}
            hooks_dict_1[key]['uv_tip_img2'] = hooks_dict_2[key]['uv_tip']
            hooks_dict_1[key]['uv_lowpoint_img2'] = {}
            hooks_dict_1[key]['uv_lowpoint_img2'] = hooks_dict_2[key]['uv_lowpoint']
        return hooks_dict_1
    

    def do_triangulation(self, hooks_dict):
        """
        Berechnet permanent nach jeder Inferenz die XYZ-Koordinaten im CAM-Frame für Hook, Tip und Lowpoint
        """
        for idx, key in enumerate(hooks_dict):
            hook = hooks_dict[key]
            [hook_xyz, tip_xyz, lowpoint_xyz], time_token = self.triangulation_processor.triangulate_3_points(point_1_1_uv = hook['uv_hook'], point_2_1_uv = hook['uv_hook_img2'],
                                                                                                              point_1_2_uv = hook['uv_tip'], point_2_2_uv = hook['uv_tip_img2'],
                                                                                                              point_1_3_uv = hook['uv_lowpoint'], point_2_3_uv = hook['uv_lowpoint_img2'])
            hooks_dict[key]['xyz_hook_in_camframe'] = {}
            hooks_dict[key]['xyz_hook_in_camframe'] = hook_xyz
            hooks_dict[key]['xyz_tip_in_camframe'] = {}
            hooks_dict[key]['xyz_tip_in_camframe'] = tip_xyz
            hooks_dict[key]['xyz_lowpoint_in_camframe'] = {}
            hooks_dict[key]['xyz_lowpoint_in_camframe'] = lowpoint_xyz
        return hooks_dict
    


    def interpolate_depth_shape(self, hooks_dict):
        """
        Berechnet die Path Points und interpoliert deren Tiefenwert -> Path Points in XYZ
        """
        for idx, key in enumerate(hooks_dict):
            hook = hooks_dict[key]

            # Hole uv_tip und uv_lowpoint aus Dict
            uv_tip_img1 = hook['uv_tip']
            uv_lowpoint_img1 = hook['uv_lowpoint']
            uv_tip_img2 = hook['uv_tip_img2']
            uv_lowpoint_img2 = hook['uv_lowpoint_img2']
            xyz_tip_in_camframe = hook['xyz_tip_in_camframe']
            xyz_lowpoint_in_camframe = hook['xyz_lowpoint_in_camframe']

            # Falls Daten fehlen, diesen Hook überspringen
            if not all([uv_tip_img1, uv_lowpoint_img1, uv_tip_img2, uv_lowpoint_img2, xyz_tip_in_camframe, xyz_lowpoint_in_camframe]):
                continue

            # Berechnung der Pixelstrecke von Tip bis Lowpoint für u und v
            u_diff_ref = abs(uv_tip_img1[0] - uv_lowpoint_img1[0])
            v_diff_ref = abs(uv_tip_img1[1] - uv_lowpoint_img1[1])
            u_diff_horizontal = abs(uv_tip_img2[0] - uv_lowpoint_img2[0])
            v_diff_horizontal = abs(uv_tip_img2[1] - uv_lowpoint_img2[1])
            u_diff = (u_diff_ref + u_diff_horizontal) // 2 or 1  # Differenz von u_tip bis u_lowpoint in px - Falls 0, auf 1 setzen
            v_diff = (v_diff_ref + v_diff_horizontal) // 2 or 1  # Differenz von v_tip bis v_lowpoint in px - Falls 0, auf 1 setzen

            # Berechnung von mm_per_px in x- und y-Richtung
            x_tip, y_tip, z_tip = xyz_tip_in_camframe
            x_lowpoint, y_lowpoint, z_lowpoint = xyz_lowpoint_in_camframe
            x_diff = abs(x_tip - x_lowpoint)
            y_diff = abs(y_tip - y_lowpoint)
            mm_per_px_x = x_diff / v_diff if v_diff != 0 else 0     # Übersetzung mm pro Pixel in x-Richtung
            mm_per_px_y = y_diff / u_diff if u_diff != 0 else 0     # Übersetzung mm pro Pixel in y-Richtung 

            # Berechnung von realen XY-Koordinaten der Path points
            uv_path_points = hook.get('path_points', [])
            if not uv_path_points:
                hooks_dict[key]['path_points_xyz_in_camframe'] = []
                continue

            u_center = self.img_height / 2
            v_center = self.img_width / 2
            xy_path_points = [((p[1] - v_center) * mm_per_px_x, (p[0] - u_center) * mm_per_px_y) for p in uv_path_points]

            # Berechnung von interpolierten Tiefenwerten für path_points
            path_points_xyz_in_camframe = self.spline_calculator.interpolate(xy_points = xy_path_points, 
                                                                             start_point_with_depth = xyz_tip_in_camframe, 
                                                                             end_point_with_depth = xyz_lowpoint_in_camframe)
            hooks_dict[key]['path_points_xyz_in_camframe'] = path_points_xyz_in_camframe
            

    def publish_hooks_dict(self):
        """
        Publisher des gefilterten Output Dicts mit Masken, BBoxes und uv-Punkten für Spitze, Senke und Haken
        """
        # starttime = time.perf_counter()

        msg = HookData()
        with ThreadPoolExecutor() as executor:
            results = executor.map(
                lambda item: process_hook_for_publisher(item[0], item[1], dual_camera_setup = True, publish_masks = self.publish_masks),
                self.filtered_hooks_dict.items()
            )
            msg.hooks.extend(results)
        self.hooks_dict_publisher_.publish(msg)

        # endtime = time.perf_counter()
        # self.get_logger().info(f"Execution time: {endtime - starttime} seconds")



def main(args=None):
    rclpy.init(args=args)
    node = YOLOv8TwoImgInferenceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('shutting down YoloV8 Two Img Inference node...')
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()

