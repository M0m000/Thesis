from collections import deque
import numpy as np

class LowpassFilter:
    def __init__(self, f_g, T_s):
        self.f_g = f_g  # Grenzfrequenz des Filters (in Hz)
        self.T_s = T_s  # Abtastzeit (Samplingrate)
        self.T = 1 / ((2 / self.T_s) * np.tan((self.T_s * self.f_g) / 2))  # Filterzeitkonstante
        self.nyquist_shannon_okay = self.check_nyquist_shannon()

        self.prev_input = 0
        self.prev_output = 0
    
    def check_nyquist_shannon(self):
        if (1 / self.T_s) >= 2 * self.f_g:
            print("Lowpass Filter initialized correctly.")
            return True
        else:
            print("ERROR - Nyquist Shannon Theorem -> decrease sample time!!")
            return False
        
    def update(self, input_value):
        if self.nyquist_shannon_okay:
            K = 1 / (1 + 2 * self.T / self.T_s)
            y_k = K * (input_value + self.prev_input - (1 - 2 * self.T / self.T_s) * self.prev_output)
            self.prev_output = y_k
            self.prev_input = input_value
            return y_k

class HookFilter:
    def __init__(self, f_g=1.0, T_s=0.01, confirmation_frames=5, disappearance_frames=1):
        self.f_g = f_g  # Grenzfrequenz des Tiefpassfilters (in Hz)
        self.T_s = T_s  # Samplingrate (in Hz)
        self.confirmation_frames = confirmation_frames
        self.disappearance_frames = disappearance_frames
        self.hook_history = {}  # Speichert Historie pro Haken (für UV-Koordinaten und Boxen)

    def update(self, hooks_dict):
        """
        Nimmt das hooks_dict (mit allen Haken und deren Parametern) und gibt ein gefiltertes Dict zurück.
        Filtert die UV-Koordinaten und zusätzlich die Bounding Box-Koordinaten mit einem Tiefpassfilter.
        """
        filtered_hooks_dict = {}
    
        # Vorhandene Haken updaten oder neu hinzufügen
        for hook_key, hook_data in hooks_dict.items():
            if hook_key not in self.hook_history:
                # Neuer Haken: Initialisiere Historie
                self.hook_history[hook_key] = {
                    "frames_seen": 1,
                    "frames_missed": 0,
                    "uv_hook": deque([hook_data["uv_hook"]], maxlen=2),
                    "uv_tip": deque([hook_data["uv_tip"]], maxlen=2),
                    "uv_lowpoint": deque([hook_data["uv_lowpoint"]], maxlen=2),
                    "hook_box": deque([hook_data["hook_box"]], maxlen=2),
                    "tip_box": deque([hook_data["tip_box"]], maxlen=2),
                    "lowpoint_box": deque([hook_data["lowpoint_box"]], maxlen=2),
                }
            else:
                self.hook_history[hook_key]["frames_seen"] += 1
                self.hook_history[hook_key]["frames_missed"] = 0
    
            hist = self.hook_history[hook_key]
    
            # Initialisiere Tiefpassfilter für UV-Koordinaten und Bounding Box-Koordinaten
            uv_filter = LowpassFilter(self.f_g, self.T_s)
            box_filter = LowpassFilter(self.f_g, self.T_s)
    
            # UV-Koordinaten filtern
            filtered_uv_hook = self.lowpass_filter_uv(hook_data["uv_hook"], uv_filter)
            filtered_uv_tip = self.lowpass_filter_uv(hook_data["uv_tip"], uv_filter)
            filtered_uv_lowpoint = self.lowpass_filter_uv(hook_data["uv_lowpoint"], uv_filter)
    
            # Bounding Box-Koordinaten filtern
            filtered_hook_box = self.lowpass_filter_box(hook_data["hook_box"], box_filter)
            filtered_tip_box = self.lowpass_filter_box(hook_data["tip_box"], box_filter)
            filtered_lowpoint_box = self.lowpass_filter_box(hook_data["lowpoint_box"], box_filter)
    
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

    def lowpass_filter_uv(self, new_uv, filter_instance):
        """
        Wendet den Tiefpassfilter auf UV-Koordinaten an.
        Falls new_uv None ist, wird None zurückgegeben.
        """
        if new_uv is None:
            return None

        # Filtere jede Komponente der UV-Koordinaten separat
        filtered_uv = (
            filter_instance.update(new_uv[0]),
            filter_instance.update(new_uv[1])
        )
        return filtered_uv

    def lowpass_filter_box(self, new_box, filter_instance):
        """
        Wendet den Tiefpassfilter auf Bounding Box-Koordinaten an.
        new_box wird angenommen als Tuple (x, y, w, h).
        Falls new_box None ist, wird None zurückgegeben.
        """
        if new_box is None:
            return None

        # Filtere jede Komponente der Box separat
        filtered_box = tuple(
            filter_instance.update(new_val)
            for new_val in new_box
        )
        return filtered_box
