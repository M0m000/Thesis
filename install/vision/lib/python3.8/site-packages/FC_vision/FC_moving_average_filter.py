from collections import deque
import numpy as np


class MovingAverageFilter:
    def __init__(self, window_size=10, confirmation_frames=5, disappearance_frames=1):
        self.window_size = window_size  # Anzahl der letzten Werte für den Mittelwert
        self.confirmation_frames = confirmation_frames  # Bestätigungs-Frames
        self.disappearance_frames = disappearance_frames  # Frames nach denen der Haken entfernt wird, falls er nicht bestätigt wurde
        self.history = {}  # Speichert die letzten N Werte für jeden Key
        self.frames_seen = {}  # Speichert die Anzahl der Frames, in denen ein Wert gesehen wurde
        self.frames_missed = {}  # Speichert die Anzahl der Frames, in denen der Wert nicht mehr gesehen wurde

    def update(self, hooks_dict):
        """
        Berechnet den Mittelwert der letzten N Werte für jeden Hook in hooks_dict.
        :param hooks_dict: Eingabewerte für die Haken, die gefiltert werden müssen.
        :return: Gefiltertes Dictionary mit den neuen Werten.
        """
        filtered_hooks_dict = {}

        # Vorhandene Haken updaten oder neu hinzufügen
        for hook_key, hook_data in hooks_dict.items():
            if hook_key not in self.history:
                # Neuer Haken: Initialisiere Historie
                self.history[hook_key] = {
                    "uv_hook": deque([hook_data["uv_hook"]], maxlen=self.window_size),
                    "uv_tip": deque([hook_data["uv_tip"]], maxlen=self.window_size),
                    "uv_lowpoint": deque([hook_data["uv_lowpoint"]], maxlen=self.window_size),
                    "hook_box": deque([hook_data["hook_box"]], maxlen=self.window_size),
                    "tip_box": deque([hook_data["tip_box"]], maxlen=self.window_size),
                    "lowpoint_box": deque([hook_data["lowpoint_box"]], maxlen=self.window_size),
                }
                self.frames_seen[hook_key] = 1
                self.frames_missed[hook_key] = 0
            else:
                self.frames_seen[hook_key] += 1
                self.frames_missed[hook_key] = 0

            hist = self.history[hook_key]

            # UV-Koordinaten filtern
            filtered_uv_hook = self.moving_average_filter(hook_data["uv_hook"], hist["uv_hook"])
            filtered_uv_tip = self.moving_average_filter(hook_data["uv_tip"], hist["uv_tip"])
            filtered_uv_lowpoint = self.moving_average_filter(hook_data["uv_lowpoint"], hist["uv_lowpoint"])

            # Bounding Box-Koordinaten filtern
            filtered_hook_box = self.moving_average_filter(hook_data["hook_box"], hist["hook_box"])
            filtered_tip_box = self.moving_average_filter(hook_data["tip_box"], hist["tip_box"])
            filtered_lowpoint_box = self.moving_average_filter(hook_data["lowpoint_box"], hist["lowpoint_box"])

            # Übernehmen nur, wenn der Haken ausreichend lange bestätigt ist
            if self.frames_seen[hook_key] >= self.confirmation_frames:
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
        for hook_key in list(self.history.keys()):
            if hook_key not in hooks_dict:
                self.frames_missed[hook_key] += 1
                if self.frames_missed[hook_key] >= self.disappearance_frames:
                    del self.history[hook_key]
                    del self.frames_seen[hook_key]
                    del self.frames_missed[hook_key]

        return filtered_hooks_dict

    def moving_average_filter(self, new_value, history):
        """
        Wendet einen Moving Average-Filter auf den neuen Wert an.
        Wenn der Wert None ist, wird None zurückgegeben.
        """
        if new_value is None:
            history.append(None)
            return None

        # Falls noch kein gültiger Wert vorhanden, einfach den neuen Wert übernehmen
        if not history or history[-1] is None:
            filtered_value = new_value
        else:
            # Berechne den Mittelwert der letzten 'window_size' Werte
            data = np.array(history)
            mean_value = np.mean(data, axis=0)
            filtered_value = mean_value

        history.append(filtered_value)
        return filtered_value
