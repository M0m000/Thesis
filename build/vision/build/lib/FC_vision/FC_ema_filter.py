from collections import deque

class HookFilter:
    def __init__(self, alpha=0.2, confirmation_frames=5, disappearance_frames=1):
        self.alpha = alpha  # EMA-Glättungsfaktor (z. B. 0.01 für einen trägen Filter)
        self.confirmation_frames = confirmation_frames
        self.disappearance_frames = disappearance_frames
        self.hook_history = {}  # Speichert Historie pro Haken (für UV-Koordinaten und Boxen)

    def update(self, hooks_dict):
        """
        Nimmt das hooks_dict (mit allen Haken und deren Parametern) und gibt ein gefiltertes Dict zurück.
        Filtert die UV-Koordinaten und zusätzlich die Bounding Box-Koordinaten.
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
    
            # UV-Koordinaten filtern
            filtered_uv_hook = self.ema_filter_uv(hook_data["uv_hook"], hist["uv_hook"])
            filtered_uv_tip = self.ema_filter_uv(hook_data["uv_tip"], hist["uv_tip"])
            filtered_uv_lowpoint = self.ema_filter_uv(hook_data["uv_lowpoint"], hist["uv_lowpoint"])
    
            # Bounding Box-Koordinaten filtern
            filtered_hook_box = self.ema_filter_box(hook_data["hook_box"], hist["hook_box"])
            filtered_tip_box = self.ema_filter_box(hook_data["tip_box"], hist["tip_box"])
            filtered_lowpoint_box = self.ema_filter_box(hook_data["lowpoint_box"], hist["lowpoint_box"])
    
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

    def ema_filter_uv(self, new_uv, history):
        """
        Wendet einen EMA-Filter auf UV-Koordinaten an.
        Falls new_uv None ist, wird None zurückgegeben.
        """
        if new_uv is None:
            history.append(None)
            return None

        # Falls in der Historie kein gültiger Wert vorliegt, einfach new_uv übernehmen
        if not history or history[-1] is None:
            filtered_uv = new_uv
        else:
            last_uv = history[-1]
            filtered_uv = (
                self.alpha * new_uv[0] + (1 - self.alpha) * last_uv[0],
                self.alpha * new_uv[1] + (1 - self.alpha) * last_uv[1]
            )
        history.append(filtered_uv)
        return filtered_uv

    def ema_filter_box(self, new_box, history):
        """
        Wendet einen EMA-Filter auf Bounding Box-Koordinaten an.
        new_box wird angenommen als Tuple (x, y, w, h).
        Falls new_box None ist, wird None zurückgegeben.
        """
        if new_box is None:
            history.append(None)
            return None

        # Falls noch kein gültiger Wert vorhanden, einfach new_box übernehmen
        if not history or history[-1] is None:
            filtered_box = new_box
        else:
            last_box = history[-1]
            # Filtere jede Komponente der Box separat
            filtered_box = tuple(
                self.alpha * new_val + (1 - self.alpha) * last_val
                for new_val, last_val in zip(new_box, last_box)
            )
        history.append(filtered_box)
        return filtered_box
