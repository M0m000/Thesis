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
import matplotlib.pyplot as plt
from action_interfaces.msg import HookData, Hook, BoundingBox, UV
from concurrent.futures import ThreadPoolExecutor


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

        # Subscriber auf VC Cam
        self.subscription = self.create_subscription(
            Image,
            'vcnanoz/image_raw',
            self.image_callback,
            1
        )
        self.subscription

        self.hooks_dict_publisher_ = self.create_publisher(HookData, 'yolov8_output/hooks_dict', 10)
        self.timer = self.create_timer(0.01, self.publish_hooks_dict)

        self.bridge = CvBridge()
        self.received_img = None
        self.output_img = None
        self.points_img = None
        self.get_logger().info('YOLOv8 Inference Node started...')

        self.get_logger().info("Loading YoloV8 model...")
        self.yolo_model = YOLO(self.yolo_model_path)
        self.get_logger().info("YoloV8 model loaded!")

        self.inference_device = "cpu"
        self.set_device()

        self.bar_dict = {}
        self.bar_dict_processed = {}
        self.hooks_dict = {}
        self.hooks_dict_processed = {}


    def set_device(self):
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
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            self.preprocess(cv_image)
            results = self.inference()
            self.bar_dict, self.hooks_dict = self.postprocess(results)
            self.process_output_hooks_dict()

            if self.show_cam_img:
                cv2.imshow('VC Cam Img', self.received_img)
                cv2.waitKey(1)

            if self.show_output_img:
                self.output_img = self.plot_hooks_and_bars()
                cv2.imshow('YoloV8 Output Img', self.output_img)
                cv2.waitKey(1)

            if self.show_point_img:
                self.points_img = self.plot_points()
                cv2.imshow('Point Output Img', self.points_img)
                cv2.waitKey(1)
        except Exception as e:
            self.get_logger().error(f'Error in image processing: {e}')


    def plot_points(self):
        img_copy = self.received_img.copy()
        for idx, key in enumerate(self.hooks_dict_processed):
            if self.hooks_dict_processed[key]['hook_box'] is not None:
                bb_hook = tuple(map(int, self.hooks_dict_processed[key]['hook_box']))
                cv2.rectangle(img_copy, (bb_hook[0], bb_hook[1]), (bb_hook[2], bb_hook[3]), (150, 150, 150), 2)
            if self.hooks_dict_processed[key]['uv_hook'] is not None:
                p_hook = tuple(map(int, self.hooks_dict_processed[key]['uv_hook']))
                cv2.drawMarker(img_copy, p_hook, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict_processed[key]['uv_tip'] is not None:
                p_tip = tuple(map(int, self.hooks_dict_processed[key]['uv_tip']))
                cv2.drawMarker(img_copy, p_tip, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            if self.hooks_dict_processed[key]['uv_lowpoint'] is not None:
                p_lowpoint = tuple(map(int, self.hooks_dict_processed[key]['uv_lowpoint']))
                cv2.drawMarker(img_copy, p_lowpoint, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)  
        return img_copy
    

    def process_output_hooks_dict(self):
        self.hooks_dict_processed = self.hooks_dict.copy()

        for idx, key in enumerate(self.hooks_dict):
            hook_mask = self.hooks_dict[key].get('hook_mask', [])
            tip_mask = self.hooks_dict[key].get('tip_mask', [])
            lowpoint_mask = self.hooks_dict[key].get('lowpoint_mask', [])

            if hook_mask is not None and hook_mask != []:
                uv_hook = self.calc_mean_of_mask(hook_mask, title='hook')
            else:
                uv_hook = None
            if tip_mask is not None and tip_mask != []:
                uv_tip = self.calc_mean_of_mask(tip_mask, title='tip')
            else:
                uv_tip = None
            if lowpoint_mask is not None and lowpoint_mask != []:
                uv_lowpoint = self.calc_mean_of_mask(lowpoint_mask, title='lowpoint')
            else:
                uv_lowpoint = None

            self.hooks_dict_processed[key]['uv_hook'] = uv_hook
            self.hooks_dict_processed[key]['uv_tip'] = uv_tip
            self.hooks_dict_processed[key]['uv_lowpoint'] = uv_lowpoint

    
    def calc_mean_of_mask(self, mask, title='none'):
        if mask is not None and mask != []:
            ys, xs = np.where(mask == 1)
            cx = np.mean(xs)
            cy = np.mean(ys)
            return [cx, cy]
    

    def preprocess(self, cv_image):
        # cv_image[0:20, 0:300, :] = 255
        self.received_img = cv_image
        if self.do_preprocessing:
            w_units = self.received_img.shape[1] // 32
            h_units = self.received_img.shape[0] // 32
            input_img = self.received_img[0:(h_units * 32), 0:(w_units * 32), :]
            self.received_img = input_img


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


    def postprocess(self, results):
        boxes, masks, confs, classes = self.extract_output(results)
        boxes_bar, masks_bar, confs_bar, boxes_hooks, masks_hooks, boxes_tips, masks_tips, boxes_lowpoints, masks_lowpoints, confs_hooks, confs_tips, confs_lowpoints = self.split_outputs_by_class(boxes, masks, confs, classes)
        hooks_dict = self.create_hook_instances(boxes_hooks, masks_hooks, boxes_tips, masks_tips, boxes_lowpoints, masks_lowpoints, confs_hooks, confs_tips, confs_lowpoints)
        bar_dict = self.create_bar_instance(boxes_bar, masks_bar, confs_bar)
        return bar_dict, hooks_dict


    def extract_output(self, results):
        res = results[0]
        if len(res.boxes.data.cpu().numpy()) != 0:
            boxes = res.boxes.data.cpu().numpy()
            confs = [0, 0, 0, 0, 1, 0] * boxes
            confs = confs[:, 4:5]
            classes = [0, 0, 0, 0, 0, 1] * boxes
            classes = classes[:, 5:6]
            boxes = boxes[:, 0:4]
        else:
            boxes = None
            confs = None
            classes = None

        if res.masks:
            masks = res.masks.data.cpu().numpy()
        else:
            masks = None
        return boxes, masks, confs, classes


    def calc_box_midpoint(self, box):
        return np.array([(box[0] + box[2]) / 2, (box[1] + box[3]) / 2])


    def box_distance(self, box1, box2):
        m1 = self.calc_box_midpoint(box1)
        m2 = self.calc_box_midpoint(box2)
        return abs(np.linalg.norm(m1, m2))


    def split_outputs_by_class(self, boxes, masks, confs, classes):
        if boxes is not None and masks is not None and confs is not None and classes is not None:
            idx_bar = np.where(classes == 0)[0]
            idx_hooks = np.where(classes == 1)[0]
            idx_tips = np.where(classes == 2)[0]
            idx_lowpoints = np.where(classes == 3)[0]

            boxes_bar = boxes[idx_bar]
            boxes_hooks = boxes[idx_hooks]
            boxes_tips = boxes[idx_tips]
            boxes_lowpoints = boxes[idx_lowpoints]

            masks_bar = masks[idx_bar]
            masks_hooks = masks[idx_hooks]
            masks_tips = masks[idx_tips]
            masks_lowpoints = masks[idx_lowpoints]

            confs_bar = confs[idx_bar]
            confs_hooks = confs[idx_hooks]
            confs_tips = confs[idx_tips]
            confs_lowpoints = confs[idx_lowpoints]

            return boxes_bar, masks_bar, confs_bar, boxes_hooks, masks_hooks, boxes_tips, masks_tips, boxes_lowpoints, masks_lowpoints, confs_hooks, confs_tips, confs_lowpoints
        else:
            return None, None, None, None, None, None, None, None, None, None, None, None


    def create_hook_instances(self, boxes_hooks, masks_hooks, 
                              boxes_tips, masks_tips, 
                              boxes_lowpoints, masks_lowpoints, 
                              confs_hooks, confs_tips, confs_lowpoints):
        hooks_dict = {}

        if boxes_hooks is not None:     
            for i, box_hook in enumerate(boxes_hooks):
                hook_midpoint = self.calc_box_midpoint(box_hook)
                tip_distances = [np.linalg.norm(self.calc_box_midpoint(box_tip) - hook_midpoint) 
                                 for box_tip in boxes_tips]

                # Wähle die Spitze, die am nächsten zum Haken ist
                best_tip_idx = np.argmin(tip_distances) if tip_distances else None
                if best_tip_idx is not None:
                    box_tip = boxes_tips[best_tip_idx]
                    mask_tip = masks_tips[best_tip_idx]
                    conf_tip = confs_tips[best_tip_idx]
                else:
                    # Kein Tip gefunden
                    box_tip, mask_tip, conf_tip = None, None, None

                # Berechne Abstände zu allen Lowpoints
                lowpoint_distances = [np.linalg.norm(self.calc_box_midpoint(box_lowpoint) - hook_midpoint) 
                                      for box_lowpoint in boxes_lowpoints]

                # Wähle den Lowpoint, der am nächsten zum Haken ist
                best_lowpoint_idx = np.argmin(lowpoint_distances) if lowpoint_distances else None
                if best_lowpoint_idx is not None:
                    box_lowpoint = boxes_lowpoints[best_lowpoint_idx]
                    mask_lowpoint = masks_lowpoints[best_lowpoint_idx]
                    conf_lowpoint = confs_lowpoints[best_lowpoint_idx]
                else:
                    # Kein Lowpoint gefunden
                    box_lowpoint, mask_lowpoint, conf_lowpoint = None, None, None

                # Ergebnis für den aktuellen Haken zusammenstellen
                hooks_dict[f"hook_{i + 1}"] = {
                    "hook_box": box_hook,
                    "hook_mask": masks_hooks[i],
                    "conf_hook": confs_hooks[i],
                    "tip_box": box_tip,
                    "tip_mask": mask_tip,
                    "conf_tip": conf_tip,
                    "lowpoint_box": box_lowpoint,
                    "lowpoint_mask": mask_lowpoint,
                    "conf_lowpoint": conf_lowpoint,
                }

        # Sortiere das Dictionary nach der x1, y1 Koordinate der Bounding Box
        hooks_dict = dict(sorted(hooks_dict.items(), key=lambda item: (item[1]['hook_box'][0], item[1]['hook_box'][1])))

        sorted_hooks_dict = {}
        for idx, key in enumerate(hooks_dict):
            sorted_hooks_dict['hook_' + str(idx + 1)] = hooks_dict[key]
        return sorted_hooks_dict


    def create_bar_instance(self, boxes_bar, masks_bar, confs_bar):
        bar_dict = {}

        if boxes_bar is not None:
            if len(boxes_bar) != 0:
                bar_dict["bar"] = {
                    "bar_box": boxes_bar[np.argmax(confs_bar)] if boxes_bar is not None else None,
                    "bar_mask": masks_bar[np.argmax(confs_bar)] if masks_bar is not None else None,
                    "conf_bar": confs_bar[np.argmax(confs_bar)] if confs_bar is not None else None
                }
            else:
                bar_dict["bar"] = {
                    "bar_box": None,
                    "bar_mask": None,
                    "conf_bar": None
                }
        else:
            bar_dict["bar"] = {
                "bar_box": None,
                "bar_mask": None,
                "conf_bar": None
                }
        return bar_dict


    def plot_hooks_and_bars(self):
        hooks_dict = self.hooks_dict
        bar_dict = self.bar_dict
        img_copy = self.received_img.copy()

        # Bar (nur eine Instanz)
        if bar_dict['bar']['bar_box'] is not None:
            bar = bar_dict["bar"]
            bar_box = bar["bar_box"]
            bar_mask = bar["bar_mask"]
            conf_bar = bar["conf_bar"][0]

            # Bounding Box
            x1, y1, x2, y2 = bar_box
            cv2.rectangle(img_copy, (int(x1), int(y1)), (int(x2), int(y2)), (0, 255, 0), 2)  # Rote Box für Bar

            # Maske
            bar_mask_color = np.zeros_like(img_copy)
            bar_mask_color[bar_mask == 1] = (0, 255, 0)  # Maske in Blau
            img_copy = cv2.addWeighted(img_copy, 1, bar_mask_color, 0.5, 0)

            # Konfidenz
            cv2.putText(img_copy, f"Bar ({conf_bar:.2f})", (int(x1), int(y1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)

        # Hooks (farblich segmentiert)
        if hooks_dict != {}:
            colors = plt.cm.get_cmap("tab20", len(hooks_dict))  # Farbpalette
            for idx, hook_name in enumerate(hooks_dict):
                hook = hooks_dict[hook_name]
                hook_box = hook["hook_box"]
                hook_mask = hook["hook_mask"]
                conf_hook = hook["conf_hook"]
                tip_box = hook["tip_box"]
                tip_mask = hook["tip_mask"]
                conf_tip = hook["conf_tip"]
                lowpoint_box = hook["lowpoint_box"]
                lowpoint_mask = hook["lowpoint_mask"]
                conf_lowpoint = hook["conf_lowpoint"]

                # Normalisiere den Index für die Farbpalette
                color = colors(idx / len(hooks_dict))  # Skaliere den Index auf [0, 1]

                # Bounding Box und Maske für Hook
                x1, y1, x2, y2 = hook_box
                cv2.rectangle(img_copy, (int(x1), int(y1)), (int(x2), int(y2)), (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                hook_mask_color = np.zeros_like(img_copy)
                hook_mask_color[hook_mask == 1] = (color[0] * 255, color[1] * 255, color[2] * 255)
                img_copy = cv2.addWeighted(img_copy, 1, hook_mask_color, 0.5, 0)
                cv2.putText(img_copy, f"Hook {idx+1} ({conf_hook[0]:.2f})", (int(x1), int(y1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                # Bounding Box und Maske für Tip
                if tip_box is not None:
                    xt1, yt1, xt2, yt2 = tip_box
                    cv2.rectangle(img_copy, (int(xt1), int(yt1)), (int(xt2), int(yt2)), (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                    tip_mask_color = np.zeros_like(img_copy)
                    tip_mask_color[tip_mask == 1] = (0, 0, 255)
                    img_copy = cv2.addWeighted(img_copy, 1, tip_mask_color, 0.5, 0)
                    cv2.putText(img_copy, f"Tip {idx+1} ({conf_tip[0]:.2f})", (int(xt1), int(yt1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                # Bounding Box und Maske für Lowpoint
                if lowpoint_box is not None:
                    xl1, yl1, xl2, yl2 = lowpoint_box
                    cv2.rectangle(img_copy, (int(xl1), int(yl1)), (int(xl2), int(yl2)), (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                    lowpoint_mask_color = np.zeros_like(img_copy)
                    lowpoint_mask_color[lowpoint_mask == 1] = (255, 0, 0)
                    img_copy = cv2.addWeighted(img_copy, 1, lowpoint_mask_color, 0.5, 0)
                    cv2.putText(img_copy, f"Lowpoint {idx+1} ({conf_lowpoint[0]:.2f})", (int(xl1), int(yl1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (color[0] * 255, color[1] * 255, color[2] * 255), 2)
        return img_copy
    

    def process_hook(self, hook_name, hook_data):
        hook = Hook()
        hook.name = hook_name
        bridge = CvBridge()

        # Setze Hook Bounding Box
        if hook_data['hook_box'] is not None:
            hook.hook_box = BoundingBox(
                x_min=float(hook_data['hook_box'][0]),
                y_min=float(hook_data['hook_box'][1]),
                x_max=float(hook_data['hook_box'][2]),
                y_max=float(hook_data['hook_box'][3])
            )
            if hook_data['hook_mask'] is not None and self.publish_masks:
                hook.hook_mask = bridge.cv2_to_imgmsg(np.array(hook_data['hook_mask']), encoding="32FC1")
            hook.conf_hook = float(hook_data['conf_hook'])
            hook.uv_hook = UV(data=[hook_data['uv_hook'][0], hook_data['uv_hook'][1]])

        # Setze Tip Box und Mask als Image, falls verfügbar
        if hook_data['tip_box'] is not None:
            hook.tip_box = BoundingBox(
                x_min=float(hook_data['tip_box'][0]),
                y_min=float(hook_data['tip_box'][1]),
                x_max=float(hook_data['tip_box'][2]),
                y_max=float(hook_data['tip_box'][3])
            )
            if hook_data['tip_mask'] is not None and self.publish_masks:
                hook.tip_mask = bridge.cv2_to_imgmsg(np.array(hook_data['tip_mask']), encoding="32FC1")
            hook.conf_tip = float(hook_data['conf_tip'])
            hook.uv_tip = UV(data=[hook_data['uv_tip'][0], hook_data['uv_tip'][1]])

        # Setze Lowpoint Box und Mask als Image, falls verfügbar
        if hook_data['lowpoint_box'] is not None:
            hook.lowpoint_box = BoundingBox(
                x_min=float(hook_data['lowpoint_box'][0]),
                y_min=float(hook_data['lowpoint_box'][1]),
                x_max=float(hook_data['lowpoint_box'][2]),
                y_max=float(hook_data['lowpoint_box'][3])
            )
            if hook_data['lowpoint_mask'] is not None and self.publish_masks:
                hook.lowpoint_mask = bridge.cv2_to_imgmsg(np.array(hook_data['lowpoint_mask']), encoding="32FC1")
            hook.conf_lowpoint = float(hook_data['conf_lowpoint'])
            hook.uv_lowpoint = UV(data=[hook_data['uv_lowpoint'][0], hook_data['uv_lowpoint'][1]])
        return hook


    def publish_hooks_dict(self):
        # starttime = time.perf_counter()

        msg = HookData()
        with ThreadPoolExecutor() as executor:
            results = executor.map(
                lambda item: self.process_hook(item[0], item[1]),
                self.hooks_dict_processed.items()
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


