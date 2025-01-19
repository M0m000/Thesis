import numpy as np
import matplotlib.pyplot as plt
import cv2

def extract_output(results):
    res = results[0]

    if len(res.boxes.data.cpu().numpy()) != 0:
        # print("Bounding Boxes found!")
        boxes = res.boxes.data.cpu().numpy()
        confs = [0, 0, 0, 0, 1, 0] * boxes
        confs = confs[:, 4:5]
        classes = [0, 0, 0, 0, 0, 1] * boxes
        classes = classes[:, 5:6]
        boxes = boxes[:, 0:4]
    else:
        # print("No Bounding Boxes found!")
        boxes = None
        confs = None
        classes = None

    if res.masks:
        # print("Masks found!")
        masks = res.masks.data.cpu().numpy()
    else:
        # print("No Masks found!")
        masks = None
    return boxes, masks, confs, classes

def calc_box_midpoint(box):
    return np.array([(box[0] + box[2]) / 2, (box[1] + box[3]) / 2])

def box_distance(box1, box2):
    m1 = calc_box_midpoint(box1)
    m2 = calc_box_midpoint(box2)
    return abs(np.linalg.norm(m1, m2))

def split_outputs_by_class(boxes, masks, confs, classes):
    # Klassen Indizes finden
    if boxes is not None and masks is not None and confs is not None and classes is not None:
        idx_bar = np.where(classes == 0)[0]
        idx_hooks = np.where(classes == 1)[0]
        idx_tips = np.where(classes == 2)[0]
        idx_lowpoints = np.where(classes == 3)[0]

        # Boxes splitten
        boxes_bar = boxes[idx_bar]
        boxes_hooks = boxes[idx_hooks]
        boxes_tips = boxes[idx_tips]
        boxes_lowpoints = boxes[idx_lowpoints]

        # Masks splitten
        masks_bar = masks[idx_bar]
        masks_hooks = masks[idx_hooks]
        masks_tips = masks[idx_tips]
        masks_lowpoints = masks[idx_lowpoints]

        # Confidences splitten
        confs_bar = confs[idx_bar]
        confs_hooks = confs[idx_hooks]
        confs_tips = confs[idx_tips]
        confs_lowpoints = confs[idx_lowpoints]

        return boxes_bar, masks_bar, confs_bar, boxes_hooks, masks_hooks, boxes_tips, masks_tips, boxes_lowpoints, masks_lowpoints, confs_hooks, confs_tips, confs_lowpoints
    else:
        # print("No Classes found for Split!")
        return None, None, None, None, None, None, None, None, None, None, None, None

def create_hook_instances(boxes_hooks, masks_hooks, 
                          boxes_tips, masks_tips, 
                          boxes_lowpoints, masks_lowpoints, 
                          confs_hooks, confs_tips, confs_lowpoints):
    hooks_dict = {}

    if boxes_hooks is not None:     # nur wenn es ueberhaupt Haken im Bild gibt
        for i, box_hook in enumerate(boxes_hooks):
            # Berechne den Mittelpunkt des aktuellen Hakens
            hook_midpoint = calc_box_midpoint(box_hook)

            # Berechne Abstände zu allen Spitzen ("tips")
            tip_distances = [np.linalg.norm(calc_box_midpoint(box_tip) - hook_midpoint) 
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
            lowpoint_distances = [np.linalg.norm(calc_box_midpoint(box_lowpoint) - hook_midpoint) 
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

def create_bar_instance(boxes_bar, masks_bar, confs_bar):
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

def plot_hooks_and_bars(img_orig, hooks_dict, bar_dict):
    img_copy = img_orig.copy()

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
    else:
        print("No bar instances to plot!")

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
            else:
                print("No tip instances to plot!")

            # Bounding Box und Maske für Lowpoint
            if lowpoint_box is not None:
                xl1, yl1, xl2, yl2 = lowpoint_box
                cv2.rectangle(img_copy, (int(xl1), int(yl1)), (int(xl2), int(yl2)), (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                lowpoint_mask_color = np.zeros_like(img_copy)
                lowpoint_mask_color[lowpoint_mask == 1] = (255, 0, 0)
                img_copy = cv2.addWeighted(img_copy, 1, lowpoint_mask_color, 0.5, 0)
                cv2.putText(img_copy, f"Lowpoint {idx+1} ({conf_lowpoint[0]:.2f})", (int(xl1), int(yl1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (color[0] * 255, color[1] * 255, color[2] * 255), 2)
            else:
                print("No lowpoint instances to plot!")
    else:
        print("No hook instances to plot!")

    plt.figure(figsize=(16, 16))
    plt.imshow(cv2.cvtColor(img_copy, cv2.COLOR_BGR2RGB))
    plt.axis('off')
    plt.show()


def postprocess(results, input, plot_result=False):
    boxes, masks, confs, classes = extract_output(results)
    boxes_bar, masks_bar, confs_bar, boxes_hooks, masks_hooks, boxes_tips, masks_tips, boxes_lowpoints, masks_lowpoints, confs_hooks, confs_tips, confs_lowpoints = split_outputs_by_class(boxes, masks, confs, classes)
    hooks_dict = create_hook_instances(boxes_hooks, masks_hooks, 
                          boxes_tips, masks_tips, 
                          boxes_lowpoints, masks_lowpoints, 
                          confs_hooks, confs_tips, confs_lowpoints)
    bar_dict = create_bar_instance(boxes_bar, masks_bar, confs_bar)

    if plot_result:
        plot_hooks_and_bars(input, hooks_dict, bar_dict)
    return bar_dict, hooks_dict
