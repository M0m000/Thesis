from collections import deque
import numpy as np


class HookFilterMovingAvg:
    def __init__(self, window_size=5, confirmation_frames=5, disappearance_frames=1, size_tolerance=0.1):
        self.window_size = window_size
        self.confirmation_frames = confirmation_frames
        self.disappearance_frames = disappearance_frames
        self.size_tolerance = size_tolerance
        self.hook_history = {}
        self.enabled = True

    def update(self, hooks_dict):
        if not self.enabled:
            return hooks_dict

        filtered_hooks_dict = {}

        # Berechne durchschnittliche Boxgröße existierender Haken
        avg_box_size = self.calculate_average_box_size()

        for hook_key, hook_data in hooks_dict.items():
            if hook_key not in self.hook_history:
                # Neuer Haken
                self.hook_history[hook_key] = {
                    "frames_seen": 1,
                    "frames_missed": 0,
                    "uv_hook": deque(maxlen=self.window_size),
                    "uv_tip": deque(maxlen=self.window_size),
                    "uv_lowpoint": deque(maxlen=self.window_size),
                    "hook_box": deque(maxlen=self.window_size),
                    "tip_box": deque(maxlen=self.window_size),
                    "lowpoint_box": deque(maxlen=self.window_size),
                }
            else:
                self.hook_history[hook_key]["frames_seen"] += 1
                self.hook_history[hook_key]["frames_missed"] = 0

            hist = self.hook_history[hook_key]

            # UV-Koordinaten filtern
            filtered_uv_hook = self.ma_filter_uv(hook_data["uv_hook"], hist["uv_hook"])
            filtered_uv_tip = self.ma_filter_uv(hook_data["uv_tip"], hist["uv_tip"])
            filtered_uv_lowpoint = self.ma_filter_uv(hook_data["uv_lowpoint"], hist["uv_lowpoint"])

            # Bounding Box-Koordinaten filtern
            filtered_hook_box = self.ma_filter_box(hook_data["hook_box"], hist["hook_box"])
            filtered_tip_box = self.ma_filter_box(hook_data["tip_box"], hist["tip_box"])
            filtered_lowpoint_box = self.ma_filter_box(hook_data["lowpoint_box"], hist["lowpoint_box"])

            passes_size_check = self.check_box_size(filtered_hook_box, avg_box_size)

            if hist["frames_seen"] >= self.confirmation_frames and passes_size_check:
                filtered_hooks_dict[hook_key] = {
                    **hook_data,
                    "uv_hook": filtered_uv_hook,
                    "uv_tip": filtered_uv_tip,
                    "uv_lowpoint": filtered_uv_lowpoint,
                    "hook_box": filtered_hook_box,
                    "tip_box": filtered_tip_box,
                    "lowpoint_box": filtered_lowpoint_box,
                }
            else:
                # Noch nicht bestätigt oder Größencheck nicht bestanden
                if hook_key not in filtered_hooks_dict:
                    filtered_hooks_dict[hook_key] = hook_data

        # Entferne verschwundene Haken
        for hook_key in list(self.hook_history.keys()):
            if hook_key not in hooks_dict:
                self.hook_history[hook_key]["frames_missed"] += 1
                if self.hook_history[hook_key]["frames_missed"] >= self.disappearance_frames:
                    del self.hook_history[hook_key]

        return filtered_hooks_dict

    def calculate_average_box_size(self):
        boxes = []
        for hist in self.hook_history.values():
            if hist["hook_box"]:
                # Nehme die letzte bekannte Box zur Berechnung
                last_box = hist["hook_box"][-1]
                if last_box is not None:
                    w, h = last_box[2], last_box[3]
                    boxes.append(w * h)
        if len(boxes) >= 2:
            return np.mean(boxes)
        else:
            return None

    def check_box_size(self, box, avg_box_size):
        if box is None:
            return False
        if avg_box_size is None:
            # Noch nicht genug Daten -> keine Größenprüfung nötig
            return True

        w, h = box[2], box[3]
        area = w * h
        lower_bound = avg_box_size * (1 - self.size_tolerance)
        upper_bound = avg_box_size * (1 + self.size_tolerance)
        return lower_bound <= area <= upper_bound

    def ma_filter_uv(self, new_uv, history):
        if new_uv is None:
            return None
        history.append(new_uv)
        avg_uv = tuple(np.mean(history, axis=0))
        return avg_uv

    def ma_filter_box(self, new_box, history):
        if new_box is None:
            return None
        history.append(new_box)
        avg_box = tuple(np.mean(history, axis=0))
        return avg_box

    def reset(self):
        self.hook_history.clear()

    def set_enabled(self, enabled: bool):
        self.enabled = enabled