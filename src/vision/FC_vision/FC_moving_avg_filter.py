from collections import deque
import numpy as np


class HookFilterMovingAvg:
    def __init__(self, window_size=5, confirmation_frames=5, disappearance_frames=1):
        self.window_size = window_size  # Fenstergröße für den Moving Average Filter
        self.confirmation_frames = confirmation_frames
        self.disappearance_frames = disappearance_frames
        self.hook_history = {}  # Speichert Historie pro Haken (für UV-Koordinaten und Boxen)
        self.enabled = True

    def update(self, hooks_dict):
        """
        Nimmt das hooks_dict (mit allen Haken und deren Parametern) und gibt ein gefiltertes Dict zurück.
        Filtert die UV-Koordinaten und zusätzlich die Bounding Box-Koordinaten.
        """
        if not self.enabled:
            # Wenn der Filter deaktiviert ist, einfach alles durchreichen
            return hooks_dict
        
        filtered_hooks_dict = {}
    
        # Vorhandene Haken updaten oder neu hinzufügen
        for hook_key, hook_data in hooks_dict.items():
            if hook_key not in self.hook_history:
                # Neuer Haken: Initialisiere Historie mit Moving Average Puffer
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
    
            # Übernehmen nur, wenn der Haken ausreichend lange bestätigt ist
            if hist["frames_seen"] >= self.confirmation_frames:
                filtered_hooks_dict[hook_key] = {
                    **hook_data,  # alle anderen Parameter werden übernommen
                    "uv_hook": filtered_uv_hook,
                    "uv_tip": filtered_uv_tip,
                    "uv_lowpoint": filtered_uv_lowpoint,
                    "hook_box": filtered_hook_box,
                    "tip_box": filtered_tip_box,
                    "lowpoint_box": filtered_lowpoint_box,
                }
            else:
                # Solange der Haken noch nicht bestätigt ist, verbleibt er weiterhin in der Historie,
                # auch wenn er nicht im finalen Output ist.
                if hook_key not in filtered_hooks_dict:
                    filtered_hooks_dict[hook_key] = hook_data
    
        # Entferne Haken, die im aktuellen hooks_dict nicht mehr vorhanden sind
        for hook_key in list(self.hook_history.keys()):
            if hook_key not in hooks_dict:
                self.hook_history[hook_key]["frames_missed"] += 1
                if self.hook_history[hook_key]["frames_missed"] >= self.disappearance_frames:
                    del self.hook_history[hook_key]
    
        return filtered_hooks_dict

    def ma_filter_uv(self, new_uv, history):
        """
        Wendet einen Moving Average Filter auf UV-Koordinaten an.
        Falls new_uv None ist, wird None zurückgegeben.
        """
        if new_uv is None:
            return None

        history.append(new_uv)

        avg_uv = tuple(np.mean(history, axis=0))
        return avg_uv


    def ma_filter_box(self, new_box, history):
        """
        Wendet einen Moving Average Filter auf Bounding Box-Koordinaten an.
        new_box wird angenommen als Tuple (x, y, w, h).
        Falls new_box None ist, wird None zurückgegeben.
        """
        if new_box is None:
            return None

        history.append(new_box)  # Neuen Wert zum Puffer hinzufügen

        # Mittelwert über gespeicherte Werte berechnen
        avg_box = tuple(np.mean(history, axis=0))
        return avg_box
    
    def reset(self):
        self.hook_history.clear()

    def set_enabled(self, enabled: bool):
        """Methode für das Ein- bzw. Ausschalten des Filters"""
        self.enabled = enabled

    