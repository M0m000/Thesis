import csv
import numpy as np


def save_dict_to_csv(node, data, filename="output.csv"):
    """
    Speichert ein geschachteltes Dictionary mit NumPy-Arrays und Listen als CSV-Datei.

    Parameters:
        data (dict): Dictionary mit Struktur {'index': {'xyz_hook': np.array, ..., 'tfc_workframe': list, 'tfc_worldframe': np.array, 'xyz_path_points_in_workframe': [(x, y, z), ...]}}
        filename (str): Name der zu speichernden CSV-Datei (optional)
    """
    with open(filename, mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)

        # Spaltenüberschriften definieren
        header = ["Index",
                  "Hook_X_in_camframe", "Hook_Y_in_camframe", "Hook_Z_in_camframe",
                  "Tip_X_in_camframe", "Tip_Y_in_camframe", "Tip_Z_in_camframe",
                  "Lowpoint_X_in_camframe", "Lowpoint_Y_in_camframe", "Lowpoint_Z_in_camframe",
                  "Hook_X_in_workframe", "Hook_Y_in_workframe", "Hook_Z_in_workframe",
                  "Tip_X_in_workframe", "Tip_Y_in_workframe", "Tip_Z_in_workframe",
                  "Lowpoint_X_in_workframe", "Lowpoint_Y_in_workframe", "Lowpoint_Z_in_workframe",
                  "TFC_X_in_workframe", "TFC_Y_in_workframe", "TFC_Z_in_workframe",
                  "TFC_X_in_worldframe", "TFC_Y_in_worldframe", "TFC_Z_in_worldframe",
                  "Path_Points_Count"]  # Zählt die Anzahl der Path-Punkte
        writer.writerow(header)

        # Daten schreiben
        for key, values in data.items():
            row = [key]  # Erste Spalte: Index
            
            # Schreibe die bekannten Punkte xyz_hook, xyz_tip, xyz_lowpoint
            for point in ["xyz_hook_in_camframe", "xyz_tip_in_camframe", "xyz_lowpoint_in_camframe"]:
                row.extend(values[point].flatten())  # x, y, z Werte hinzufügen
            
            # Schreibe die Workframe-Punkte xyz_hook_workframe, xyz_tip_workframe, xyz_lowpoint_workframe
            for point in ["xyz_hook_in_workframe", "xyz_tip_in_workframe", "xyz_lowpoint_in_workframe"]:
                row.extend(values[point])  # x, y, z Werte hinzufügen

            # Schreibe die Worldframe-Punkte
            for point in ["xyz_hook_in_worldframe", "xyz_hook_in_worldframe", "xyz_hook_in_worldframe"]:
                row.extend(values[point])
            
            # Schreibe tfc_workframe und tfc_worldframe
            row.extend(values["tfc_workframe"])  # Liste mit drei Werten
            row.extend(values["tfc_worldframe"])  # NumPy-Array mit drei Werten

            # Anzahl der Path-Punkte
            path_points = values.get("xyz_path_points_in_workframe", [])
            row.append(len(path_points))  # Füge die Anzahl der Path-Punkte als Zahl hinzu

            # Schreibe die Path-Punkte (x, y, z) in eine Zeile
            for point in path_points:
                row.extend(point)  # Füge jeden (x, y, z) Tupel zu der Zeile hinzu

            # Schreibe die Zeile in die CSV
            writer.writerow(row)

    node.get_logger().info(f"CSV gespeichert als {filename}!")

'''
def save_dict_to_csv(node, data, filename="output.csv"):
    """
    Speichert ein geschachteltes Dictionary mit NumPy-Arrays und Listen als CSV-Datei.

    Parameters:
        data (dict): Dictionary mit Struktur {'index': {'xyz_hook': np.array, ..., 'tfc_workframe': list, 'tfc_worldframe': np.array}}
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
                  "Lowpoint_WF_X", "Lowpoint_WF_Y", "Lowpoint_WF_Z",
                  "TFC_WF_X", "TFC_WF_Y", "TFC_WF_Z",
                  "TFC_World_X", "TFC_World_Y", "TFC_World_Z"]
        writer.writerow(header)

        # Daten schreiben
        for key, values in data.items():
            row = [key]  # Erste Spalte: Index
            for point in ["xyz_hook", "xyz_tip", "xyz_lowpoint"]:
                row.extend(values[point].flatten())  # x, y, z Werte hinzufügen
            
            for point in ["xyz_hook_workframe", "xyz_tip_workframe", "xyz_lowpoint_workframe"]:
                row.extend(values[point])  # x, y, z Werte hinzufügen
            
            row.extend(values["tfc_workframe"])  # Liste mit drei Werten
            row.extend(values["tfc_worldframe"])  # NumPy-Array mit drei Werten
            
            writer.writerow(row)

    node.get_logger().info(f"CSV gespeichert als {filename}!")
'''





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
            key = int(row[0])  # Erster Wert ist der Index
            values = list(map(float, row[1:]))  # Restliche Werte in Float umwandeln

            # Extrahiere die Path-Punkte-Daten
            path_points_count = int(row[26])  # Anzahl der Path-Punkte ist in der 27. Spalte
            xyz_path_points_in_workframe = []

            # Die Path-Punkte beginnen nach den festen Spalten
            # Jede Path-Punkt besteht aus 3 Werten (x, y, z)
            for i in range(path_points_count):
                offset = 27 + i * 3  # Start-Index für die Path-Punkte (nach den festen Spalten)
                xyz_path_points_in_workframe.append((values[offset], values[offset + 1], values[offset + 2]))

            # Dictionary mit NumPy-Arrays und Listen erstellen
            data[key] = {
                "xyz_hook_in_camframe": np.array([[values[0]], [values[1]], [values[2]]]),
                "xyz_tip_in_camframe": np.array([[values[3]], [values[4]], [values[5]]]),
                "xyz_lowpoint_in_camframe": np.array([[values[6]], [values[7]], [values[8]]]),
                "xyz_hook_in_workframe": values[9:12],
                "xyz_tip_in_workframe": values[12:15],
                "xyz_lowpoint_in_workframe": values[15:18],
                "tfc_in_workframe": values[18:21],
                "tfc_in_worldframe": np.array(values[21:24]),
                "xyz_path_points_in_workframe": xyz_path_points_in_workframe  # Path-Punkte als Liste von Tupeln (x, y, z)
            }

    node.get_logger().info(f"CSV loaded successfully from {filename}!")
    return data

'''
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
                "xyz_lowpoint_workframe": values[15:18],
                "tfc_workframe": values[18:21],
                "tfc_worldframe": np.array(values[21:24])
            }
    
    node.get_logger().info(f"CSV loaded successfully from {filename}!")
    return data
'''
