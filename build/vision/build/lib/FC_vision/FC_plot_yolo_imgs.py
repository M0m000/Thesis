import cv2
import numpy as np
import matplotlib.pyplot as plt



def plot_hooks_and_bars(received_img, hooks_dict, bar_dict):
    """
    Funktion für Plot des Segmentation Img
    """
    bar_dict = bar_dict
    img_copy = received_img.copy()

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
            skeleton_mask = hook["skeleton_mask"]
            path_points = hook["path_points"]

            # Normalisiere den Index für die Farbpalette
            color = colors(idx / len(hooks_dict))  # Skaliere den Index auf [0, 1]

            # Bounding Box und Maske für Hook
            x1, y1, x2, y2 = hook_box
            cv2.rectangle(img_copy, (int(x1), int(y1)), (int(x2), int(y2)), (color[0] * 255, color[1] * 255, color[2] * 255), 2)

            # Maske
            hook_mask_color = np.zeros_like(img_copy)
            hook_mask_color[hook_mask == 1] = (color[0] * 255, color[1] * 255, color[2] * 255)
            img_copy = cv2.addWeighted(img_copy, 1, hook_mask_color, 0.5, 0)
            
            # Marker für UV-Koordinate
            p_hook = tuple(map(int, hooks_dict[hook_name]['uv_hook']))
            cv2.drawMarker(img_copy, p_hook, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
            
            # Beschriftung
            cv2.putText(img_copy, f"Hook {str(len(hooks_dict)-idx)} ({conf_hook[0]:.2f})", (int(x1), int(y1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (color[0] * 255, color[1] * 255, color[2] * 255), 2)
            
            # Bounding Box und Maske für Tip
            if tip_box is not None:
                xt1, yt1, xt2, yt2 = tip_box
                cv2.rectangle(img_copy, (int(xt1), int(yt1)), (int(xt2), int(yt2)), (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                # Maske
                tip_mask_color = np.zeros_like(img_copy)
                tip_mask_color[tip_mask == 1] = (0, 0, 255)
                img_copy = cv2.addWeighted(img_copy, 1, tip_mask_color, 0.5, 0)
                
                # Marker für UV-Koordinate
                p_tip = tuple(map(int, hooks_dict[hook_name]['uv_tip']))
                cv2.drawMarker(img_copy, p_tip, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
                
                # Beschriftung
                cv2.putText(img_copy, f"Tip {str(len(hooks_dict)-idx)} ({conf_tip[0]:.2f})", (int(xt1), int(yt1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (color[0] * 255, color[1] * 255, color[2] * 255), 2)
            
            # Bounding Box und Maske für Lowpoint
            if lowpoint_box is not None:
                xl1, yl1, xl2, yl2 = lowpoint_box
                cv2.rectangle(img_copy, (int(xl1), int(yl1)), (int(xl2), int(yl2)), (color[0] * 255, color[1] * 255, color[2] * 255), 2)

                # Maske
                lowpoint_mask_color = np.zeros_like(img_copy)
                lowpoint_mask_color[lowpoint_mask == 1] = (255, 0, 0)
                img_copy = cv2.addWeighted(img_copy, 1, lowpoint_mask_color, 0.5, 0)

                # Marker für UV-Koordinate
                p_lowpoint = tuple(map(int, hooks_dict[hook_name]['uv_lowpoint']))
                cv2.drawMarker(img_copy, p_lowpoint, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
                
                # Beschriftung
                cv2.putText(img_copy, f"Lowpoint {str(len(hooks_dict)-idx)} ({conf_lowpoint[0]:.2f})", (int(xl1), int(yl1)-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (color[0] * 255, color[1] * 255, color[2] * 255), 2)

            
            # Skelett-Maske
            if skeleton_mask is not None:
                skeleton_mask_color = np.zeros_like(img_copy)
                skeleton_mask_color[skeleton_mask == 255] = (255, 0, 255)
                img_copy = cv2.addWeighted(img_copy, 1, skeleton_mask_color, 1.0, 0)

            # Path Points
            if path_points is not None:
                for idx, point in enumerate(path_points):
                    x, y = point

                    if idx == 0:
                        continue
                    elif idx == (len(path_points) - 1):
                        cv2.circle(img_copy, (x, y), radius = 8, color = (255, 0, 0), thickness = -1)
                    else:
                        cv2.circle(img_copy, (x, y), radius = 5, color = (255, 0, 255), thickness = -1)

                for idx, point in enumerate(path_points):
                    x, y = point
                    cv2.circle(img_copy, (x, y), radius = 8, color = (0, 255, 0), thickness = -1)
                    break
    return img_copy


def plot_points(received_img, hooks_dict):
    """
    Funktion für Plot des Point Img
    """
    img_copy = received_img.copy()
    for idx, key in enumerate(hooks_dict):
        if hooks_dict[key]['hook_box'] is not None:
            bb_hook = tuple(map(int, hooks_dict[key]['hook_box']))
            cv2.rectangle(img_copy, (bb_hook[0], bb_hook[1]), (bb_hook[2], bb_hook[3]), (150, 150, 150), 2)
            text_position = (bb_hook[0], bb_hook[1] - 10)
            cv2.putText(img_copy, f"{key}", text_position, cv2.FONT_HERSHEY_SIMPLEX, 0.6, (50, 50, 50), 2)
        if hooks_dict[key]['uv_hook'] is not None:
            p_hook = tuple(map(int, hooks_dict[key]['uv_hook']))
            cv2.drawMarker(img_copy, p_hook, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
        if hooks_dict[key]['uv_tip'] is not None:
            p_tip = tuple(map(int, hooks_dict[key]['uv_tip']))
            cv2.drawMarker(img_copy, p_tip, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
        if hooks_dict[key]['uv_lowpoint'] is not None:
            p_lowpoint = tuple(map(int, hooks_dict[key]['uv_lowpoint']))
            cv2.drawMarker(img_copy, p_lowpoint, color=(0, 0, 255), markerType=cv2.MARKER_CROSS, markerSize=30, thickness=2, line_type=cv2.LINE_AA)
    return img_copy


def plot_combined_skeletons(hooks_dict):
    """
    Diese Funktion kombiniert die 'skeleton_mask' für alle Haken zu einer einzigen Maske 
    und zeigt diese mit OpenCV an. Zusätzlich werden die Pfadpunkte für alle Haken gleichzeitig eingezeichnet.
    """
    if not hooks_dict:
        return None
    
    combined_mask = None
    skeleton_img_color = None
    
    # Bestimme die maximale Bildgröße für alle Masken
    max_height = 0
    max_width = 0
    
    # Berechne die maximalen Dimensionen für die Skelettmasken
    for key in hooks_dict:
        skeleton_mask = hooks_dict[key].get('skeleton_mask', None)
        if skeleton_mask is not None:
            max_height = max(max_height, skeleton_mask.shape[0])
            max_width = max(max_width, skeleton_mask.shape[1])

    # Falls keine Masken vorhanden sind, breche ab
    if max_height == 0 or max_width == 0:
        return None

    # Initialisiere das kombinierte Bild mit einer schwarzen Maske
    combined_mask = np.zeros((max_height, max_width), dtype=np.uint8)

    # Iteriere über alle Haken im hooks_dict und kombiniere ihre Masken
    for key in hooks_dict:
        skeleton_mask = hooks_dict[key].get('skeleton_mask', None)

        if skeleton_mask is not None:
            # Prüfe, ob die Maske überhaupt Pixel enthält
            if np.any(skeleton_mask):
                # Skalieren der Maske auf die maximalen Dimensionen
                resized_mask = cv2.resize(skeleton_mask, (max_width, max_height), interpolation=cv2.INTER_NEAREST)

                # Kombiniere die Masken (überlagerung bitwise_or)
                combined_mask = cv2.bitwise_or(combined_mask, resized_mask)

    skeleton_img_color = cv2.cvtColor(combined_mask, cv2.COLOR_GRAY2BGR)
    
    # Jetzt alle Punkte für alle Haken einzeichnen
    for key in hooks_dict:
        path_points = hooks_dict[key].get('path_points', None)
        
        if path_points is None or len(path_points) == 0:
            continue

        for idx, point in enumerate(path_points):
            if not isinstance(point, (list, tuple)) or len(point) != 2:
                print(f"Fehler: Ungültiges Punktformat für {key}: {point}")
                continue

            x, y = point
            if 0 <= x < max_width and 0 <= y < max_height:
                if idx == 0:
                    continue
                elif idx == len(path_points) - 1:
                    cv2.circle(skeleton_img_color, (x, y), radius = 8, color=(255, 0, 0), thickness=-1)
                else:
                    cv2.circle(skeleton_img_color, (x, y), radius = 3, color = (255, 0, 255), thickness = -1)
            else:
                print(f"Warnung: Punkt außerhalb der Bildgrenzen ({x}, {y}) für {key}.")
        
        for idx, point in enumerate(path_points):
            if not isinstance(point, (list, tuple)) or len(point) != 2:
                print(f"Fehler: ungültiges Punktformat für {key}: {point}")
                continue

            x, y = point
            if 0 <= x < max_width and 0 <= y < max_height:
                cv2.circle(skeleton_img_color, (x, y), radius = 8, color=(0, 255, 0), thickness=-1)
            break
    
    return skeleton_img_color
