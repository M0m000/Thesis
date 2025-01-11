import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import torch
import cv2
from ultralytics import YOLO
import time
import os


class YOLOv8InferenceNode(Node):
    def __init__(self):
        super().__init__('yolov8_inference')

        # Subscriber auf VC Cam
        self.subscription = self.create_subscription(
            Image,
            'vcnanoz/image_raw',
            self.image_callback,
            1
        )
        self.subscription

        self.bridge = CvBridge()
        self.received_img = None
        self.get_logger().info('YOLOv8 Inference Node started...')

        self.declare_parameter('yolo_model_path', '/home/mo/Thesis/YoloV8_InstanceSeg/models/20250110_2023_yolo8nano_pruned.pt')
        self.yolo_model_path = self.get_parameter('yolo_model_path').get_parameter_value().string_value

        self.declare_parameter('confidence_threshold', 0.2)
        self.confidence_threshold = self.get_parameter('confidence_threshold').get_parameter_value().double_value

        self.get_logger().info("Loading YoloV8 model...")
        self.yolo_model = YOLO(self.yolo_model_path)
        self.get_logger().info("YoloV8 model loaded!")

        self.inference_device = "cpu"
        self.set_device()

        

    def set_device(self):
        self.get_logger().info("Setting device for neural network inferences...")
        if torch.cuda.is_available():
            self.inference_device = "cuda"
            self.get_logger().info("GPU available - using GPU as inference device.")
        else:
            self.inference_device = "cpu"
            self.get_logger().info("No GPU available - using CPU as inference device.")
    
    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            cv_image_cropped = cv_image[20:, :]
            self.received_img = cv_image_cropped

            cv2.imshow('VC Cam Img', cv_image_cropped)
            cv2.waitKey(1)

            yolo_output_img = self.inference()
            cv2.imshow('YoloV8 Output', yolo_output_img)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f'Error in image processing: {e}')

    def inference(self):
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
                                box = False)
        end_time = time.perf_counter()
        self.get_logger().info(f"Inference time: {(end_time - start_time):.4f} sec")

        annotated_frame = self.annotate_frame(self.received_img, results)
        return annotated_frame

    def annotate_frame(self, frame, results):
        annotated_frame = frame.copy()

        class_colors = {
            0: (255, 0, 0),         # bar -> rot
            1: (0, 255, 0),         # hook -> grün
            2: (0, 0, 255),         # tip -> blau
            3: (255, 255, 0),       # lowpoint -> cyan
        }

        labelnames = ["bar", "hook", "tip", "lowpoint"]

        for result in results:
            # Bounding Boxes
            if result.boxes is not None:
                for box in result.boxes:
                    x1, y1, x2, y2 = map(int, box.xyxy[0])  # Boxkoordinaten
                    conf = box.conf[0]                      # Konfidenzwert
                    label = int(box.cls[0])                 # Klassenindex
                    color = class_colors.get(label, (255, 255, 255))

                    # Zeichne Rechteck und Beschriftung
                    cv2.rectangle(annotated_frame, (x1, y1), (x2, y2), color, 2)
                    cv2.putText(annotated_frame, f"{labelnames[label]} ({conf:.2f})",
                                (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1)

            # Masken
            if result.masks is not None:
                for i, mask in enumerate(result.masks.data):
                    mask = mask.cpu().numpy()
                    mask = (mask > 0.5).astype(np.uint8)  # Binärmaske (0 und 1)

                    # Skaliere Maske auf Größe des Originalbildes
                    mask_resized = cv2.resize(mask, (frame.shape[1], frame.shape[0]))

                    # Erzeuge farbige Maske
                    label = int(result.boxes.cls[i])                    # Klasse der Maske
                    color = class_colors.get(label, (255, 255, 255))
                    colored_mask = np.zeros_like(annotated_frame)
                    for c in range(3):                                  # Maske auf alle Kanäle anwenden
                        colored_mask[:, :, c] = mask_resized * color[c]

                    # Füge farbige Maske zum annotierten Bild hinzu
                    annotated_frame = cv2.addWeighted(annotated_frame, 1.0, colored_mask, 0.5, 0)

        return annotated_frame




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
        cv2.destroyAllWindows()  # Schließe alle OpenCV-Fenster

if __name__ == '__main__':
    main()
