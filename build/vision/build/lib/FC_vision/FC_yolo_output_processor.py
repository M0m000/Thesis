import rclpy
from rclpy.node import Node
import numpy as np
import cv2
from skimage.morphology import skeletonize
from collections import deque
from skimage.morphology import closing, square
import heapq
import time



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
                    "skeleton_mask": None,
                    "shortest_path": None,
                    "path_points": None,
                    "path_points_xyz_in_camframe": None,
                    "xyz_hook_in_camframe": None,
                    "xyz_tip_in_camframe": None,
                    "xyz_lowpoint_in_camframe": None,
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

                coords = np.argwhere(np.array(hook_mask) == 1)  # y,x Koordinaten
                if coords.size > 0:
                    # Finde Pixel mit größtem y-Wert (am weitesten unten)
                    lowest_idx = np.argmax(coords[:, 0])  # Index mit größtem y
                    y, x = coords[lowest_idx]
                    # in der Spalte von x soll der mittelwert aller y-Werte mit 1 in der Binärmaske genommen werden
                    uv_lowpoint = [float(x), float(y)]  # (x, y) als floats
            else:
                uv_hook = None
                uv_lowpoint = None
            if tip_mask is not None and tip_mask != []:
                uv_tip = self.calc_mean_of_mask(tip_mask, title='tip')
                # uv_tip = self.calc_center_between_extreme_points(tip_mask, title='tip')
                # uv_tip = self.get_top_edge_midpoint(tip_mask, top_fraction=0.25)
                # if uv_tip is None:
                #     uv_tip = self.calc_center_between_extreme_points(tip_mask, title='tip')
            else:
                uv_tip = None
            
            if lowpoint_mask is not None and lowpoint_mask != []:
                # uv_lowpoint = self.calc_mean_of_mask(lowpoint_mask, title='lowpoint')
                uv_lowpoint = self.calc_center_between_extreme_points(lowpoint_mask, title='lowpoint')
                # uv_lowpoint = self.get_top_edge_midpoint(lowpoint_mask, top_fraction=0.25)
                # if uv_lowpoint is None:
                #     uv_lowpoint = self.calc_center_between_extreme_points(lowpoint_mask, title='lowpoint')
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
        

    def calc_center_between_extreme_points(self, mask, title='none'):
        """
        Berechnet den Mittelpunkt der Verbindungslinie zwischen den beiden
        am weitesten voneinander entfernten Punkten auf der Maskenkontur.
        """
        if mask is None or mask == []:
            return None

        mask = np.array(mask, dtype=np.uint8)
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        if not contours or len(contours[0]) < 2:
            return None

        contour = contours[0]
        max_dist = 0
        p1, p2 = None, None

        for i in range(len(contour)):
            for j in range(i + 1, len(contour)):
                d = np.linalg.norm(contour[i][0] - contour[j][0])
                if d > max_dist:
                    max_dist = d
                    p1 = contour[i][0]
                    p2 = contour[j][0]

        if p1 is None or p2 is None:
            return None
        midpoint = ((p1 + p2) / 2).astype(float)
        return [midpoint[0], midpoint[1]]
    

    def get_top_edge_midpoint(self, mask, top_fraction=0.3):
        if mask is None or mask == []:
            return None
    
        mask = np.array(mask, dtype=np.uint8)
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
        if not contours or len(contours[0]) < 2:
            return None
    
        contour = contours[0].reshape(-1, 2)
    
        min_y = np.min(contour[:, 1])
        max_y = np.max(contour[:, 1])
        y_thresh = min_y + (max_y - min_y) * top_fraction
    
        # Manuelle Filterung
        top_x = []
        top_y = []
        for pt in contour:
            if pt[1] <= y_thresh:
                top_x.append(pt[0])
                top_y.append(pt[1])
    
        if len(top_x) < 2:
            return None
    
        cx = sum(top_x) / len(top_x)
        cy = sum(top_y) / len(top_y)
        return [float(cx), float(cy)]

    

    def find_hooks_shape(self, hooks_dict, num_interpolation_points=5):
        """
        Funktion, um die Form des Hakens als Pfad von Spitze zu Senke zu berechnen.
        Dabei wird sichergestellt, dass uv_tip und uv_lowpoint direkt mit dem Skelett verbunden sind.
        """
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

            # Endpunkte (Spitze und Senke)
            uv_tip = hooks_dict[key]['uv_tip']
            uv_lowpoint = hooks_dict[key]['uv_lowpoint']

            if uv_tip is not None and uv_lowpoint is not None:
                # Konvertiere uv-Koordinaten in Integer (Format: (Zeile, Spalte))
                uv_tip_int = (int(round(uv_tip[1])), int(round(uv_tip[0])))
                uv_lowpoint_int = (int(round(uv_lowpoint[1])), int(round(uv_lowpoint[0])))

                '''
                # Schließen von Lücken im Skelett
                kernel_size = 20
                kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (kernel_size, kernel_size))
                skeleton_mask = cv2.morphologyEx(skeleton_mask, cv2.MORPH_CLOSE, kernel)
                '''

                # Verbreitern des Skeletts
                skeleton_thickness = 3
                kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (skeleton_thickness, skeleton_thickness))  # oder eine andere Größe wählen
                skeleton_mask = cv2.dilate(skeleton_mask, kernel, iterations=1)

                # Erneut sicherstellen, dass uv_tip und uv_lowpoint gesetzt sind
                skeleton_mask[uv_tip_int[0], uv_tip_int[1]] = 255
                skeleton_mask[uv_lowpoint_int[0], uv_lowpoint_int[1]] = 255

                # Hilfsfunktion: Zeichnet eine Linie von 'endpoint' zum nächsten weißen Pixel im Skelett.
                def connect_endpoint(skel_mask, endpoint):
                    # Stelle sicher, dass der Endpunkt enthalten ist
                    skel_mask[endpoint[0], endpoint[1]] = 255

                    # Finde alle weißen Pixel im Skelett
                    ys, xs = np.where(skel_mask == 255)
                    candidates = list(zip(ys, xs))

                    # Entferne den Endpunkt selbst
                    candidates = [pt for pt in candidates if pt != endpoint]
                    if candidates:
                        # Finde den Kandidaten mit minimaler euklidischer Distanz
                        distances = [np.linalg.norm(np.array(pt) - np.array(endpoint)) for pt in candidates]
                        nearest_point = candidates[np.argmin(distances)]
                        # Zeichne eine direkte Linie zwischen dem Endpunkt und dem nächsten Skelettpunkt
                        cv2.line(skel_mask, (endpoint[1], endpoint[0]),
                                 (nearest_point[1], nearest_point[0]), 255, thickness=skeleton_thickness)
                    return skel_mask

                # Verbinde uv_tip und uv_lowpoint jeweils mit dem nächstgelegenen Punkt im Skelett
                skeleton_mask = connect_endpoint(skeleton_mask, uv_tip_int)
                skeleton_mask = connect_endpoint(skeleton_mask, uv_lowpoint_int)

                # Speichern der modifizierten Skelett-Maske in hooks_dict
                hooks_dict[key]['skeleton_mask'] = skeleton_mask

                # Den Pfad mit A* (oder alternativ BFS) finden
                shortest_path = self.astar_shortest_path(skeleton_mask=skeleton_mask,
                                                         start=uv_tip_int,
                                                         end=uv_lowpoint_int)

                if shortest_path:
                    hooks_dict[key]['shortest_path'] = shortest_path  # Pfad speichern

                    # Erzeuge gleichmäßig verteilte Punkte entlang des Pfads
                    path_points = self.get_evenly_spaced_points_on_path(path=shortest_path,
                                                                         num_points=num_interpolation_points)
                    hooks_dict[key]['path_points'] = path_points
                else:
                    print("ERROR - no shortest path found!")
        return hooks_dict


    def crop_skeleton_to_path(self, skeleton_mask, uv_tip, uv_lowpoint):
        # Extrahiere die Y- und X-Koordinaten der beiden Punkte (uv_tip und uv_lowpoint)
        y_tip, x_tip = uv_tip
        y_lowpoint, x_lowpoint = uv_lowpoint

        # Bestimme die minimale und maximale Y-Koordinate, um den Bereich zu beschränken
        min_y = min(y_tip, y_lowpoint)
        max_y = max(y_tip, y_lowpoint)
        min_x = min(x_tip, x_lowpoint)
        max_x = max(x_tip, x_lowpoint)

        # Zuschneiden der Skelettmaske entlang des Bereichs
        cropped_skeleton = skeleton_mask[min_y:max_y+1, min_x:max_x+1]  # Behalte nur den Y-Bereich zwischen den Punkten
        return cropped_skeleton


    def bfs_shortest_path(self, skeleton_mask, start, end):
        """
        Findet den kürzesten Pfad auf der Skelettmaske unter Verwendung von BFS.
        :param skeleton_mask: 2D NumPy Array der Skelettmaske (1px breite Linie)
        :param start: Tuple (y, x) des Startpunkts auf der Maske
        :param end: Tuple (y, x) des Endpunkts auf der Maske
        :return: Liste von Punkten [(x1, y1), (x2, y2), ..., (xn, yn)] oder None, wenn kein Pfad gefunden wurde
        """
        time_start = time.perf_counter()
        rows, cols = skeleton_mask.shape

        # Überprüfen, ob die Start- und Endpunkte im Skelett liegen
        if skeleton_mask[start[0], start[1]] != 255 or skeleton_mask[end[0], end[1]] != 255:
            print(f"Tip or lowpoint not appearing in skeleton!")
            return None

        # Nachbar-Richtungen: 8 Richtungen (horizontal, vertikal und diagonal)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

        # BFS Queue und Visited Set
        queue = deque([start])
        parent = {start: None}  # Um Vorgänger für Pfadrekonstruktion zu speichern
        visited = set([start])

        while queue:
            current = queue.popleft()

            # Wenn das Ziel erreicht ist, den Pfad rekonstruieren
            if current == end:
                path = []
                while current is not None:
                    path.append((current[1], current[0]))  # (x, y) statt (y, x)
                    current = parent[current]
                return path[::-1]  # Pfad umdrehen, da wir ihn vom Endpunkt zum Start rekonstruiert haben

            # Untersuche benachbarte Pixel
            for dr, dc in directions:
                nr, nc = current[0] + dr, current[1] + dc
                if 0 <= nr < rows and 0 <= nc < cols and skeleton_mask[nr, nc] == 255 and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    parent[(nr, nc)] = current
                    queue.append((nr, nc))

        time_end = time.perf_counter()
        time_token = time_end - time_start
        print(f"Time for BFS: {time_token:.6f} sec")
        return None  # Kein Pfad gefunden
    

    def astar_shortest_path(self, skeleton_mask, start, end):
        """
        Findet den kürzesten Pfad auf der Skelettmaske mit A*.

        :param skeleton_mask: 2D NumPy Array der Skelettmaske (1px breite Linie)
        :param start: Tuple (y, x) des Startpunkts
        :param end: Tuple (y, x) des Endpunkts
        :return: Liste von Punkten [(x1, y1), (x2, y2), ..., (xn, yn)] oder None, wenn kein Pfad gefunden wurde
        """
        time_start = time.perf_counter()
        rows, cols = skeleton_mask.shape

        # Überprüfen, ob Start- und Endpunkt auf dem Skelett liegen
        if skeleton_mask[start] != 255 or skeleton_mask[end] != 255:
            print("Tip or Lowpoint can not be found on skeleton!")
            return None

        # Bewegungsmöglichkeiten (8 Richtungen)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

        # Priority Queue für A*
        open_set = []
        heapq.heappush(open_set, (0, start))  # (f-Wert, Knoten)

        # Vorgänger speichern für die Pfadrekonstruktion
        parent = {start: None}

        # Kosten vom Start bis zu einem bestimmten Punkt
        g_score = {start: 0}

        while open_set:
            _, current = heapq.heappop(open_set)  # Knoten mit dem niedrigsten f-Wert holen

            # Ziel erreicht → Pfad zurückverfolgen
            if current == end:
                path = []
                while current is not None:
                    path.append((current[1], current[0]))  # (x, y) statt (y, x)
                    current = parent[current]
                return path[::-1]  # Umkehren, da Rückverfolgung von Ende zu Start erfolgt

            # Nachbarn untersuchen
            for dr, dc in directions:
                nr, nc = current[0] + dr, current[1] + dc
                neighbor = (nr, nc)

                if 0 <= nr < rows and 0 <= nc < cols and skeleton_mask[nr, nc] == 255:
                    # g-Wert: tatsächliche Kosten vom Start bis zu diesem Pixel
                    new_g = g_score[current] + 1  # +1 für jeden Pixel-Schritt

                    if neighbor not in g_score or new_g < g_score[neighbor]:
                        g_score[neighbor] = new_g
                        parent[neighbor] = current
                        # f-Wert = g-Wert + Heuristik (Manhattan-Distanz)
                        f_score = new_g + abs(nr - end[0]) + abs(nc - end[1])
                        heapq.heappush(open_set, (f_score, neighbor))

        time_end = time.perf_counter()
        time_token = time_end - time_start
        print(f"Time for A*: {time_token:.6f} sec")
        return None  # Kein Pfad gefunden


    def get_evenly_spaced_points_on_path(self, path, num_points):
        """
        Berechnet N gleichmäßig verteilte Punkte entlang des Pfads.

        :param path: Liste von Punkten [(y1, x1), (y2, x2), ...]
        :param num_points: Anzahl der Punkte, die gleichmäßig auf dem Pfad verteilt werden sollen.
        :return: Liste von N Punkten [(y1, x1), (y2, x2), ...]
        """
        # Gesamtlänge des Pfads berechnen
        total_length = 0

        for i in range(1, len(path)):
            y1, x1 = path[i-1]      # vorheriger Punkt
            y2, x2 = path[i]        # jetziger Punkt
            total_length += np.linalg.norm([y2 - y1, x2 - x1])      # kummulierte Summe aller Distanzen

        # Berechne den Abstand zwischen den Punkten
        if num_points < 2:      # es muessen mindestens 2 Path Points gefordert werden (Spitze und Senke)
            num_points = 2
        step_size = total_length / (num_points - 1)  # Da der erste Punkt am Startpunkt liegt, (num_points-1) Schritte

        # Punkte entlang des Pfads berechnen
        spaced_points = [path[0]]       # Startpunkt hinzufügen
        current_length = 0

        for i in range(1, len(path)):
            y1, x1 = path[i-1]
            y2, x2 = path[i]

            # Berechne die Distanz zwischen den Punkten
            segment_length = np.linalg.norm([y2 - y1, x2 - x1])

            # Solange der aktuelle Abstand das gewünschte step_size erreicht, füge neue Punkte hinzu
            while current_length + segment_length >= step_size:
                # Bestimme den Punkt auf diesem Segment, der den gewünschten Abstand erfüllt
                remaining_length = step_size - current_length
                ratio = remaining_length / segment_length
                new_point = (int(round(y1 + ratio * (y2 - y1))),
                             int(round(x1 + ratio * (x2 - x1))))
                spaced_points.append(new_point)

                # Update die verbleibende Länge und setze den aktuellen Abstand zurück
                segment_length -= remaining_length
                current_length = 0
            current_length += segment_length
        return spaced_points
