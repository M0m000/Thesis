import rclpy
from rclpy.node import Node
import numpy as np
import cv2
from skimage.morphology import skeletonize


class YoloPostprocessor(Node):
    def __init__(self):
        self.inference_results = None



    def postprocess(self, results):
        """
        Funktion mit allen Aufrufen für das Postprocessing
        """
        boxes, masks, confs, classes = self.extract_output(results)
        boxes_bar, masks_bar, confs_bar, boxes_hooks, masks_hooks, boxes_tips, masks_tips, boxes_lowpoints, masks_lowpoints, confs_hooks, confs_tips, confs_lowpoints = self.split_outputs_by_class(boxes, masks, confs, classes)
        hooks_dict = self.create_hook_instances(boxes_hooks, masks_hooks, boxes_tips, masks_tips, boxes_lowpoints, masks_lowpoints, confs_hooks, confs_tips, confs_lowpoints)
        bar_dict = self.create_bar_instance(boxes_bar, masks_bar, confs_bar)
        return bar_dict, hooks_dict
    
    def extract_output(self, results):
        """
        TEIL DES POSTPROCESSING
        Funktion zum Entpacken des Yolo Outputs
        """
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

    def split_outputs_by_class(self, boxes, masks, confs, classes):
        """
        TEIL DES POSTPROCESSING
        Unterteilt die Outputs nach ihren Klassen und ordnet dann zu Haken, Spitze, Senke, Leiste
        """
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
        """
        TEIL DES POSTPROCESSINGS
        Funktion für das Aufbauen des Hooks Dictionary mit allen Parametern, sortiert nach detektierter Hakeninstanz
        """
        hooks_dict = {}

        if boxes_hooks is not None:     
            for i, box_hook in enumerate(boxes_hooks):
                hook_midpoint = self.calc_box_midpoint(box_hook)
                
                # Finde die beste Tip, die sich innerhalb des Hook-Box befindet
                valid_tips = [
                    (idx, box_tip) for idx, box_tip in enumerate(boxes_tips)
                    if self.is_point_inside_box(self.calc_box_midpoint(box_tip), box_hook)
                ]
                
                if valid_tips:
                    best_tip_idx, box_tip = min(valid_tips, key=lambda t: np.linalg.norm(self.calc_box_midpoint(t[1]) - hook_midpoint))
                    mask_tip = masks_tips[best_tip_idx]
                    conf_tip = confs_tips[best_tip_idx]
                else:
                    box_tip, mask_tip, conf_tip = None, None, None
                
                # Finde den besten Lowpoint, der sich innerhalb des Hook-Box befindet
                valid_lowpoints = [
                    (idx, box_lowpoint) for idx, box_lowpoint in enumerate(boxes_lowpoints)
                    if self.is_point_inside_box(self.calc_box_midpoint(box_lowpoint), box_hook)
                ]
                
                if valid_lowpoints:
                    best_lowpoint_idx, box_lowpoint = min(valid_lowpoints, key=lambda l: np.linalg.norm(self.calc_box_midpoint(l[1]) - hook_midpoint))
                    mask_lowpoint = masks_lowpoints[best_lowpoint_idx]
                    conf_lowpoint = confs_lowpoints[best_lowpoint_idx]
                else:
                    box_lowpoint, mask_lowpoint, conf_lowpoint = None, None, None
                
                # Ergebnis für den aktuellen Haken speichern
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
            sorted_hooks_dict['hook_' + str(len(hooks_dict) - idx)] = hooks_dict[key]
        
        return sorted_hooks_dict
    
    def calc_box_midpoint(self, box):
        """
        Funktion zur Berechnung des Mittelpunkts einer Bounding Box
        """
        return np.array([(box[0] + box[2]) / 2, (box[1] + box[3]) / 2])
    
    def is_point_inside_box(self, point, box):
        """
        Funktion zur Prüfung, ob ein Punkt innerhalb einer Bounding Box liegt
        """
        x1, y1, x2, y2 = box
        return x1 <= point[0] <= x2 and y1 <= point[1] <= y2
    
    def create_bar_instance(self, boxes_bar, masks_bar, confs_bar):
        """
        TEIL DES OUTPUT POSTPROCESSING
        sucht alle Parameter für Bar im Bild und trägt sie in einem Dict zusammen
        """
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
    
    def process_output_hooks_dict(self, hooks_dict):
        """
        Funktion zur Berechnung der Spitze- und Senke-Punkte aus Output Dict
        """
        # starttime = time.perf_counter()
        hooks_dict_processed = hooks_dict.copy()

        for idx, key in enumerate(hooks_dict):
            hook_mask = hooks_dict[key].get('hook_mask', [])
            tip_mask = hooks_dict[key].get('tip_mask', [])
            lowpoint_mask = hooks_dict[key].get('lowpoint_mask', [])

            
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

            hooks_dict_processed[key]['uv_hook'] = uv_hook
            hooks_dict_processed[key]['uv_tip'] = uv_tip
            hooks_dict_processed[key]['uv_lowpoint'] = uv_lowpoint

        # endtime = time.perf_counter()
        # self.get_logger().info(f"Time of Point Calculation: {(endtime-starttime):.4f} sec")
        return hooks_dict_processed
    
    def calc_mean_of_mask(self, mask, title='none'):
        """
        Funktion zur Berechnung des Mittelpunkts einer Binärmaske
        (benötigt für Berechnung der Spitze- und Senke-Punkte auf Pixelebene aus den Masken heraus)
        """
        if mask is not None and mask != []:
            ys, xs = np.where(mask == 1)
            cx = np.mean(xs)
            cy = np.mean(ys)
            return [cx, cy]
    
    def find_hooks_shape(self, hooks_dict):
        for idx, key in enumerate(hooks_dict):
            mask = hooks_dict[key]['hook_mask']
            bbox = hooks_dict[key]['hook_box']

            # Setze alles außerhalb des BBox-Bereichs auf 0
            mask[:int(bbox[1]), :] = 0  # Oben
            mask[int(bbox[3]):, :] = 0  # Unten
            mask[:, :int(bbox[0])] = 0  # Links
            mask[:, int(bbox[2]):] = 0  # Rechts

            # Skelettierung des Hakens
            skeleton_mask = skeletonize(mask).astype(np.uint8) * 255

            hooks_dict[key]['skeleton_mask'] = {}
            hooks_dict[key]['skeleton_mask'] = skeleton_mask
        return hooks_dict
