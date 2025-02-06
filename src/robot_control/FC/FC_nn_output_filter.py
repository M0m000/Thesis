from collections import defaultdict, deque

class HookFilter:
    def __init__(self, alpha=0.2, confirmation_frames=3, disappearance_frames=3):
        self.alpha = alpha                                  # EMA-Glättungsfaktor für UV-Koordinaten
        self.confirmation_frames = confirmation_frames      # Frames, bevor ein neuer Haken bestätigt wird
        self.disappearance_frames = disappearance_frames    # Frames, bevor ein verschwundener Haken gelöscht wird
        self.hook_history = {}                              # Speichert die Historie der Haken -> wird dann auf Beständigkeit überprüft
    
    def update(self, hooks_dict):
        """
        Nimmt das `hooks_dict`, filtert die UV-Koordinaten und entfernt unbestätigte Haken.
        Gibt das gefilterte Dict zurück.
        """
        filtered_hooks_dict = {}

        # Vorhandene Haken updaten
        for hook_key, hook_data in hooks_dict.items():
            if hook_key not in self.hook_history:
                # Neuer Haken entdeckt -> In Historie aufnehmen mit einer Bestätigungszähler
                self.hook_history[hook_key] = {
                    "frames_seen": 1,
                    "frames_missed": 0,
                    "uv_hook": deque([hook_data["uv_hook"]], maxlen=2),
                    "uv_tip": deque([hook_data["uv_tip"]], maxlen=2),
                    "uv_lowpoint": deque([hook_data["uv_lowpoint"]], maxlen=2),
                }
            else:
                self.hook_history[hook_key]["frames_seen"] += 1
                self.hook_history[hook_key]["frames_missed"] = 0

            hist = self.hook_history[hook_key]

            # UV-Koordinaten filtern mit EMA
            filtered_uv_hook = self.ema_filter_uv(hook_data["uv_hook"], hist["uv_hook"])
            filtered_uv_tip = self.ema_filter_uv(hook_data["uv_tip"], hist["uv_tip"])
            filtered_uv_lowpoint = self.ema_filter_uv(hook_data["uv_lowpoint"], hist["uv_lowpoint"])

            # Nur Haken übernehmen, die lange genug bestätigt wurden
            if hist["frames_seen"] >= self.confirmation_frames:
                filtered_hooks_dict[hook_key] = {
                    **hook_data,
                    "uv_hook": filtered_uv_hook,
                    "uv_tip": filtered_uv_tip,
                    "uv_lowpoint": filtered_uv_lowpoint,
                }

        # Entferne Haken, die länger als `disappearance_frames` nicht mehr gesehen wurden
        for hook_key in list(self.hook_history.keys()):
            if hook_key not in hooks_dict:
                self.hook_history[hook_key]["frames_missed"] += 1
                if self.hook_history[hook_key]["frames_missed"] >= self.disappearance_frames:
                    del self.hook_history[hook_key]  # Haken endgültig entfernen

        return filtered_hooks_dict

    def ema_filter_uv(self, new_uv, history):
        """Wendet einen EMA-Filter auf UV-Koordinaten an"""
        if history:
            new_uv = (
                self.alpha * new_uv[0] + (1 - self.alpha) * history[-1][0],
                self.alpha * new_uv[1] + (1 - self.alpha) * history[-1][1]
            )
        history.append(new_uv)
        return new_uv
    
    