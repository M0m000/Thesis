import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import torch
import cv2
from ultralytics import YOLO
import time
import sys
from action_interfaces.msg import HookData, Hook, BoundingBox, UV
from concurrent.futures import ThreadPoolExecutor
from FC_vision.FC_ema_filter import HookFilterEMA
from FC_vision.FC_moving_avg_filter import HookFilterMovingAvg
from FC_vision.FC_iir_buttoworth_filter import HooksDictLowpassFilter
from FC_vision.FC_yolo_output_processor import YoloPostprocessor
from FC_vision.FC_plot_yolo_imgs import plot_hooks_and_bars, plot_points
from FC_vision.FC_process_hooks_dict_for_publishing import process_hook_for_publisher


class YOLOv8InferenceNode(Node):
    def __init__(self):
        super().__init__('yolov8_inference')

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
        self.declare_parameter('publish_masks', True)
        self.publish_masks = self.get_parameter('publish_masks').get_parameter_value().bool_value
        self.declare_parameter('filter_alpha', 1.0)
        self.filter_alpha = self.get_parameter('filter_alpha').get_parameter_value().double_value
        self.declare_parameter('filter_windowsize', 10)
        self.filter_windowsize = self.get_parameter('filter_windowsize').get_parameter_value().integer_value

        # Subscriber auf VC Cam
        self.subscription = self.create_subscription(Image, 'vcnanoz/image_raw', self.image_callback, 1)

        # Publisher für Netz Output
        self.hooks_dict_publisher_ = self.create_publisher(HookData, 'yolov8_output/hooks_dict', 10)
        self.timer = self.create_timer(0.0001, self.publish_hooks_dict)

        # Publisher für Segmentation Img und Point Img (Output)
        self.output_segment_img_publisher = self.create_publisher(Image, 'yolov8_output/output_segment_img', 10)
        self.output_point_img_publisher = self.create_publisher(Image, 'yolov8_output/output_point_img', 10)

        # Filterinstanzen zur Filterung des Outputs
        self.ema_filter = HookFilterEMA(alpha = self.filter_alpha, confirmation_frames = 10, disappearance_frames = 5)
        self.movingavg_filter = HookFilterMovingAvg(window_size = self.filter_windowsize, confirmation_frames = 10, disappearance_frames = 5)

        # Variablen
        self.bridge = CvBridge()
        self.received_img = None
        self.output_img = None
        self.points_img = None
        self.get_logger().info('YOLOv8 Inference Node started...')

        # Laden des Modells
        self.get_logger().info("Loading YoloV8 model...")
        self.yolo_model = YOLO(self.yolo_model_path)
        self.get_logger().info("YoloV8 model loaded!")

        # Inferenzdevice auswählen - wenn möglich GPU
        self.inference_device = "cpu"
        self.set_device()

        # Dicts für Output Verarbeitung
        self.bar_dict = {}
        self.bar_dict_processed = {}
        self.hooks_dict = {}
        self.hooks_dict_processed = {}
        self.filtered_hooks_dict = {}

        # Instanz YoloPostprocessor
        self.yolo_postprocessor = YoloPostprocessor()


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

    
    def image_callback(self, msg):
        """
        Callback für Img Topic -> enthält Preprocessing, Inferenz, Postprocessing, Plots, etc.
        """
        try:
            # Bild nach Topic-Empfang konvertieren zu OpenCV Img
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

            # Preprocessing  - Teilbarkeit der Auflösung durch 32
            self.preprocess(cv_image)

            # Inferenz
            results = self.inference()

            # Postprocessing
            self.bar_dict, self.hooks_dict = self.yolo_postprocessor.postprocess(results)

            # Berechnung der Spitzen- und Senken-Punkte auf Pixelebene
            self.hooks_dict_processed = self.yolo_postprocessor.process_output_hooks_dict(hooks_dict = self.hooks_dict)

            # Filtern des Output Dicts
            self.filtered_hooks_dict = self.movingavg_filter.update(hooks_dict = self.hooks_dict_processed)
            # self.filtered_hooks_dict = self.ema_filter.update(hooks_dict = self.hooks_dict_processed)
            # self.get_logger().warn(f"Hook Tip 2 vor Filterung: {self.hooks_dict_processed['hook_2']['uv_tip']}")
            # self.get_logger().warn(f"Hooak Tip 2 nach Filterung: {self.filtered_hooks_dict['hook_2']['uv_tip']}")
            # self.filtered_hooks_dict = self.hooks_dict_processed

            # Plots
            if self.show_cam_img:
                cv2.imshow('VC Cam Img', self.received_img)
                cv2.waitKey(1)

            if self.show_output_img:
                self.output_img = plot_hooks_and_bars(received_img = self.received_img, hooks_dict = self.hooks_dict_processed, bar_dict = self.bar_dict)
                output_segment_img = self.bridge.cv2_to_imgmsg(self.output_img, encoding="bgr8")
                self.output_segment_img_publisher.publish(output_segment_img)
                cv2.imshow('YoloV8 Output Segment Img', self.output_img)
                cv2.waitKey(1)

                self.output_img = plot_hooks_and_bars(received_img = self.received_img, hooks_dict = self.filtered_hooks_dict, bar_dict = self.bar_dict)
                output_segment_img = self.bridge.cv2_to_imgmsg(self.output_img, encoding="bgr8")
                self.output_segment_img_publisher.publish(output_segment_img)
                cv2.imshow('YoloV8 Output Segment Img Filtered', self.output_img)
                cv2.waitKey(1)

            if self.show_point_img:
                self.points_img = plot_points(received_img = self.received_img, hooks_dict = self.hooks_dict_processed)
                output_point_img = self.bridge.cv2_to_imgmsg(self.points_img, encoding="bgr8")
                self.output_point_img_publisher.publish(output_point_img)
                cv2.imshow('YoloV8 Output Point Img', self.points_img)
                cv2.waitKey(1)

                self.points_img = plot_points(received_img = self.received_img, hooks_dict = self.filtered_hooks_dict)
                output_point_img = self.bridge.cv2_to_imgmsg(self.points_img, encoding="bgr8")
                self.output_point_img_publisher.publish(output_point_img)
                cv2.imshow('YoloV8 Output Point Img Filtered', self.points_img)
                cv2.waitKey(1)
                
        except Exception as e:
            self.get_logger().error(f'Error in image processing: {e}')

    

    def preprocess(self, cv_image):
        """
        Funktion für Preprocessing des Img zur Inferenz
        --- sorgt für eine Bildauflösung die durch 32 ohne Rest teilbar ist -> funktioniert stabiler mit Yolo
        """
        # cv_image[0:20, 0:300, :] = 255
        self.received_img = cv_image
        if self.do_preprocessing:
            w_units = self.received_img.shape[1] // 32
            h_units = self.received_img.shape[0] // 32
            input_img = self.received_img[0:(h_units * 32), 0:(w_units * 32), :]
            self.received_img = input_img


    def inference(self):
        """ 
        Funktion für die Inferenz des Yolo-Netzes -> Nimmt das aktuelle Bild und liefert den Output zurück
        --- wahlweise mit Zeitmessung und Berechnung der Inferenz-FPS
        """
        start_time = time.perf_counter()

        results = self.yolo_model.predict(source = self.received_img,
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


    def publish_hooks_dict(self):
        """
        Publisher des gefilterten Output Dicts mit Masken, BBoxes und uv-Punkten für Spitze, Senke und Haken
        """
        # starttime = time.perf_counter()
        msg = HookData()
        with ThreadPoolExecutor() as executor:
            results = executor.map(
                lambda item: process_hook_for_publisher(item[0], item[1], publish_masks = self.publish_masks),
                self.filtered_hooks_dict.items()
            )
            msg.hooks.extend(results)
        self.hooks_dict_publisher_.publish(msg) 

        # endtime = time.perf_counter()
        # self.get_logger().info(f"Execution time: {endtime - starttime} seconds")



def main(args=None):
    rclpy.init(args=args)
    node = YOLOv8InferenceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('shutting down YoloV8 node...')
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()


