import numpy as np

class MovingAverageFilter:
    def __init__(self, window_size=100):
        self.window_size = window_size
        self.history = {}  # Speichert die letzten N Werte für jeden Key

    def update(self, key, value):
        print(value)
        """
        Berechnet den Mittelwert der letzten N Werte für einen bestimmten Key.
        
        :param key: Einzigartiger Schlüssel (z. B. 'hook_1_uv_hook')
        :param value: Neuer Wert, der dem Filter hinzugefügt wird.
        :return: Gefilterter Mittelwert
        """
        # Überprüfe, ob der Wert None ist
        if value is None:
            print(f"Warning: None value received for {key}")
            return value  # Rückgabe von None oder ein Standardwert, je nach Bedarf

        print("Filtering")
        value = np.array(value)

        if key not in self.history:
            self.history[key] = []

        self.history[key].append(value)

        # Falls weniger Werte als das Fenster vorhanden sind, gib den aktuellen Wert zurück
        if len(self.history[key]) < self.window_size:
            return value

        # Nur die letzten window_size Werte für den Mittelwert verwenden
        data = np.array(self.history[key][-self.window_size:])
        mean_value = np.mean(data, axis=0)
        self.history[key][-1] = mean_value

        return mean_value