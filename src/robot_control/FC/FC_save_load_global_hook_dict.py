import csv
import numpy as np

def save_dict_to_csv(node, data, filename="output.csv"):
    """
    Speichert ein geschachteltes Dictionary mit NumPy-Arrays und Listen als CSV-Datei.

    Parameters:
        data (dict): Dictionary mit Struktur {'index': {'xyz_hook': np.array, 'xyz_tip': np.array, 'xyz_lowpoint': np.array, ...}}
        filename (str): Name der zu speichernden CSV-Datei (optional)
    """
    with open(filename, mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)

        # Spaltenüberschriften definieren
        header = ["Index",
                  "Hook_X", "Hook_Y", "Hook_Z",
                  "Tip_X", "Tip_Y", "Tip_Z",
                  "Lowpoint_X", "Lowpoint_Y", "Lowpoint_Z",
                  "Hook_WF_X", "Hook_WF_Y", "Hook_WF_Z",
                  "Tip_WF_X", "Tip_WF_Y", "Tip_WF_Z",
                  "Lowpoint_WF_X", "Lowpoint_WF_Y", "Lowpoint_WF_Z"]
        writer.writerow(header)

        # Daten schreiben
        for key, values in data.items():
            row = [key]  # Erste Spalte: Index
            for point in ["xyz_hook", "xyz_tip", "xyz_lowpoint"]:
                row.extend(values[point].flatten())  # x, y, z Werte hinzufügen
            
            for point in ["xyz_hook_workframe", "xyz_tip_workframe", "xyz_lowpoint_workframe"]:
                row.extend(values[point])  # x, y, z Werte hinzufügen
            
            writer.writerow(row)

    node.get_logger().info(f"CSV gespeichert als {filename}!")


def load_csv_to_dict(node, filename="output.csv"):
    """
    Lädt eine CSV-Datei und wandelt sie zurück in das ursprüngliche Dictionary-Format mit NumPy-Arrays und Listen.

    Parameters:
        filename (str): Name der zu ladenden CSV-Datei (optional)

    Returns:
        dict: Wiederhergestelltes Dictionary mit NumPy-Arrays und Listen
    """
    data = {}

    with open(filename, mode="r", newline="", encoding="utf-8") as file:
        reader = csv.reader(file)
        header = next(reader)  # Erste Zeile überspringen (Spaltennamen)

        for row in reader:
            key = row[0]  # Erster Wert ist der Index
            values = list(map(float, row[1:]))  # Restliche Werte in Float umwandeln

            # Dictionary mit NumPy-Arrays und Listen erstellen
            data[key] = {
                "xyz_hook": np.array([[values[0]], [values[1]], [values[2]]]),
                "xyz_tip": np.array([[values[3]], [values[4]], [values[5]]]),
                "xyz_lowpoint": np.array([[values[6]], [values[7]], [values[8]]]),
                "xyz_hook_workframe": values[9:12],
                "xyz_tip_workframe": values[12:15],
                "xyz_lowpoint_workframe": values[15:18]
            }

    node.get_logger().info(f"CSV erfolgreich aus {filename} geladen!")
    return data


# Beispiel-Daten
data = {
    '1': {'xyz_hook': np.array([[-43.23], [-1.95], [166.69]]), 
          'xyz_tip': np.array([[-32.07], [1.72], [157.09]]), 
          'xyz_lowpoint': np.array([[-38.79], [9.33], [161.48]]),
          'xyz_hook_workframe': [958.75, -421.93, 266.87],
          'xyz_tip_workframe': [970.18, -418.26, 257.26],
          'xyz_lowpoint_workframe': [963.34, -410.64, 261.66]},
    '2': {'xyz_hook': np.array([[-42.60], [-1.55], [166.25]]), 
          'xyz_tip': np.array([[-30.89], [3.87], [158.68]]), 
          'xyz_lowpoint': np.array([[-38.49], [10.33], [163.43]]),
          'xyz_hook_workframe': [959.40, -421.53, 266.42],
          'xyz_tip_workframe': [971.32, -416.10, 258.85],
          'xyz_lowpoint_workframe': [963.58, -409.64, 263.60]}
}
