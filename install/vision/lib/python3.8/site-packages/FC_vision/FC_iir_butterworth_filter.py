from scipy.signal import butter, filtfilt
import numpy as np
import copy


class LowPassFilter:
    def __init__(self, cutoff_freq=0.05, sample_rate=30, order=2, min_samples=10):
        """
        Erstellt einen Butterworth-Tiefpassfilter für eine gleichmäßige Glättung der Werte.

        :param cutoff_freq: Grenzfrequenz des Filters (je niedriger, desto stärker die Glättung)
        :param sample_rate: Abtastrate (Bildrate der Kamera in Hz)
        :param order: Ordnung des Filters (höhere Werte = stärkere Filterung)
        :param min_samples: Minimale Anzahl an Werten, bevor gefiltert wird
        """
        nyquist = 0.5 * sample_rate  # Nyquist-Frequenz
        normal_cutoff = cutoff_freq / nyquist  # Normierte Grenzfrequenz
        self.b, self.a = butter(order, normal_cutoff, btype='low', analog=False)
        self.history = {}
        self.min_samples = min_samples      # Mindestanzahl Samples bis Filter beginnen kann

    def update(self, key, value):
        """
        Filtert einen neuen Wert für eine bestimmte Schlüssel-ID.

        :param key: Einzigartiger Schlüssel (z. B. 'hook_1_uv_hook')
        :param value: Neuer Wert als NumPy-Array oder Liste
        :return: Gefilterter Wert
        """
        value = np.array(value)

        if key not in self.history:
            self.history[key] = []
        self.history[key].append(value)

        # Falls nicht genug Werte vorhanden sind, ungefilterten Wert zurückgeben
        if len(self.history[key]) < self.min_samples:
            print("No Filtering")
            return value

        # Nur die letzten min_samples Werte für die Filterung nehmen
        data = np.array(self.history[key][-self.min_samples:])
        filtered_value = filtfilt(self.b, self.a, data, axis=0)[-1]
        self.history[key][-1] = filtered_value
        return filtered_value

    

class HooksDictLowpassFilter:
    def __init__(self, cutoff_freq = 0.05, sample_rate = 30, order = 4, min_samples = 10):
        """
        Klasse zur Filterung von Haken-Daten mit einem Tiefpassfilter.

        :param cutoff_freq: Grenzfrequenz für den Tiefpassfilter
        :param sample_rate: Abtastrate (Bildrate der Kamera)
        """
        self.filter = LowPassFilter(cutoff_freq, sample_rate, order, min_samples)

    def update(self, hooks_dict):
        """
        Wendet den Tiefpassfilter auf ein Dictionary mit Haken-Daten an.

        :param hooks_dict: Das originale hooks_dict
        :return: Gefiltertes hooks_dict
        """
        filtered_hooks_dict = copy.deepcopy(hooks_dict)

        for hook_id, hook_data in hooks_dict.items():
            # Koordinaten von uv_hook, uv_tip, uv_lowpoint filtern
            for key in ['uv_hook', 'uv_tip', 'uv_lowpoint']:
                if key in hook_data and hook_data[key] is not None:
                    filtered_hooks_dict[hook_id][key] = self.filter.update(f"{hook_id}_{key}", hook_data[key])

            # Bounding-Box-Koordinaten filtern (wenn vorhanden)
            if 'hook_box' in hook_data and hook_data['hook_box'] is not None:
                filtered_hooks_dict[hook_id]['hook_box'] = self.filter.update(f"{hook_id}_hook_box", hook_data['hook_box'])

        return filtered_hooks_dict
