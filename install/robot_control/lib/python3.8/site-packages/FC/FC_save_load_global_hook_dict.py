import csv
import numpy as np

def save_dict_to_csv(node, data, filename="output.csv"):
    """
    Speichert ein geschachteltes Dictionary mit NumPy-Arrays als CSV-Datei.

    Parameters:
        data (dict): Dictionary mit Struktur {'index': {'xyz_hook': np.array, 'xyz_tip': np.array, 'xyz_lowpoint': np.array}}
        filename (str): Name der zu speichernden CSV-Datei (optional)
    """
    with open(filename, mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)

        header = ["Index",
                  "Hook_X", "Hook_Y", "Hook_Z",
                  "Tip_X", "Tip_Y", "Tip_Z",
                  "Lowpoint_X", "Lowpoint_Y", "Lowpoint_Z"]
        writer.writerow(header)

        for key, values in data.items():
            row = [key]
            for point in ["xyz_hook", "xyz_tip", "xyz_lowpoint"]:
                row.extend(values[point].flatten())
            
            writer.writerow(row)

    node.get_logger().info(f"CSV gespeichert als {filename}!")


def load_csv_to_dict(node, filename="output.csv"):
    """
    Lädt eine CSV-Datei und wandelt sie zurück in das ursprüngliche Dictionary-Format mit NumPy-Arrays.

    Parameters:
        filename (str): Name der zu ladenden CSV-Datei (optional)

    Returns:
        dict: Wiederhergestelltes Dictionary mit NumPy-Arrays
    """
    data = {}

    with open(filename, mode="r", newline="", encoding="utf-8") as file:
        reader = csv.reader(file)
        header = next(reader)

        for row in reader:
            key = row[0]
            values = list(map(float, row[1:]))

            data[key] = {
                "xyz_hook": np.array([[values[0]], [values[1]], [values[2]]]),
                "xyz_tip": np.array([[values[3]], [values[4]], [values[5]]]),
                "xyz_lowpoint": np.array([[values[6]], [values[7]], [values[8]]])
            }

    node.get_logger().info(f"CSV erfolgreich aus {filename} geladen!")
    return data