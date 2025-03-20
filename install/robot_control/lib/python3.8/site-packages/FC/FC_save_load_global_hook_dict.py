import csv
import numpy as np


def save_dict_to_csv(node, data, filename="output.csv"):
    """
    Speichert ein geschachteltes Dictionary mit NumPy-Arrays und Listen als CSV-Datei.
    
    Erwartete Struktur des Dictionary:
    {
        'index': {
            'xyz_hook_in_camframe': np.array, 
            'xyz_tip_in_camframe': np.array, 
            'xyz_lowpoint_in_camframe': np.array,
            'xyz_hook_in_workframe': [x, y, z], 
            'xyz_tip_in_workframe': [x, y, z], 
            'xyz_lowpoint_in_workframe': [x, y, z],
            'xyz_hook_in_worldframe': np.array oder list,
            'xyz_tip_in_worldframe': np.array oder list,
            'xyz_lowpoint_in_worldframe': np.array oder list,
            'tfc_in_workframe': [a, b, c],
            'tfc_in_worldframe': np.array oder list,
            'xyz_path_points_in_workframe': [[x, y, z], ...]
        },
        ...
    }
    
    Parameters:
        data (dict): Dictionary mit den oben genannten Schlüsseln.
        filename (str): Name der zu speichernden CSV-Datei (optional)
    """
    with open(filename, mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)

        # Spaltenüberschriften definieren
        header = [
            "Index",
            "Hook_X_in_camframe", "Hook_Y_in_camframe", "Hook_Z_in_camframe",
            "Tip_X_in_camframe", "Tip_Y_in_camframe", "Tip_Z_in_camframe",
            "Lowpoint_X_in_camframe", "Lowpoint_Y_in_camframe", "Lowpoint_Z_in_camframe",
            "Hook_X_in_workframe", "Hook_Y_in_workframe", "Hook_Z_in_workframe",
            "Tip_X_in_workframe", "Tip_Y_in_workframe", "Tip_Z_in_workframe",
            "Lowpoint_X_in_workframe", "Lowpoint_Y_in_workframe", "Lowpoint_Z_in_workframe",
            "Hook_X_in_worldframe", "Hook_Y_in_worldframe", "Hook_Z_in_worldframe",
            "Tip_X_in_worldframe", "Tip_Y_in_worldframe", "Tip_Z_in_worldframe",
            "Lowpoint_X_in_worldframe", "Lowpoint_Y_in_worldframe", "Lowpoint_Z_in_worldframe",
            "TFC_X_in_workframe", "TFC_Y_in_workframe", "TFC_Z_in_workframe",
            "TFC_X_in_worldframe", "TFC_Y_in_worldframe", "TFC_Z_in_worldframe",
            "Path_Points_Count"
        ]
        writer.writerow(header)

        # Daten schreiben
        for key, values in data.items():
            row = [key]  # Erste Spalte: Index

            # Werte in Camframe (NumPy-Array oder Liste) hinzufügen
            for point in ["xyz_hook_in_camframe", "xyz_tip_in_camframe", "xyz_lowpoint_in_camframe"]:
                value = values[point]
                if hasattr(value, "flatten"):
                    row.extend(value.flatten())
                else:
                    row.extend(value)

            # Werte im Workframe
            for point in ["xyz_hook_in_workframe", "xyz_tip_in_workframe", "xyz_lowpoint_in_workframe"]:
                row.extend(values[point])
            
            # Werte im Worldframe
            for point in ["xyz_hook_in_worldframe", "xyz_tip_in_worldframe", "xyz_lowpoint_in_worldframe"]:
                value = values[point]
                if hasattr(value, "flatten"):
                    row.extend(value.flatten())
                else:
                    row.extend(value)
            
            # tfc-Werte
            row.extend(values["tfc_in_workframe"])
            tfc_world = values["tfc_in_worldframe"]
            if hasattr(tfc_world, "flatten"):
                row.extend(tfc_world.flatten())
            else:
                row.extend(tfc_world)
            
            # Anzahl der Path-Punkte
            path_points = values.get("xyz_path_points_in_workframe", [])
            row.append(len(path_points))
            
            # Path-Punkte (jede als (x, y, z) Tupel)
            for point in path_points:
                row.extend(point)
            
            # Zeile in die CSV schreiben
            writer.writerow(row)

    node.get_logger().info(f"CSV save as {filename}!")



def load_csv_to_dict(filename="output.csv"):
    """
    Lädt eine CSV-Datei, die mit save_dict_to_csv erzeugt wurde, und baut das ursprüngliche Dictionary wieder auf.
    
    Erwartete CSV-Struktur (Spalten):
        Index,
        Hook_X_in_camframe, Hook_Y_in_camframe, Hook_Z_in_camframe,
        Tip_X_in_camframe, Tip_Y_in_camframe, Tip_Z_in_camframe,
        Lowpoint_X_in_camframe, Lowpoint_Y_in_camframe, Lowpoint_Z_in_camframe,
        Hook_X_in_workframe, Hook_Y_in_workframe, Hook_Z_in_workframe,
        Tip_X_in_workframe, Tip_Y_in_workframe, Tip_Z_in_workframe,
        Lowpoint_X_in_workframe, Lowpoint_Y_in_workframe, Lowpoint_Z_in_workframe,
        Hook_X_in_worldframe, Hook_Y_in_worldframe, Hook_Z_in_worldframe,
        Tip_X_in_worldframe, Tip_Y_in_worldframe, Tip_Z_in_worldframe,
        Lowpoint_X_in_worldframe, Lowpoint_Y_in_worldframe, Lowpoint_Z_in_worldframe,
        TFC_X_in_workframe, TFC_Y_in_workframe, TFC_Z_in_workframe,
        TFC_X_in_worldframe, TFC_Y_in_worldframe, TFC_Z_in_worldframe,
        Path_Points_Count,
        ... (folgende 3 Spalten pro Path-Punkt)
    
    Returns:
        dict: Das rekonstruierte Dictionary mit folgender Struktur:
            {
                'Index': {
                    'xyz_hook_in_camframe': np.array, 
                    'xyz_tip_in_camframe': np.array, 
                    'xyz_lowpoint_in_camframe': np.array,
                    'xyz_hook_in_workframe': [x, y, z], 
                    'xyz_tip_in_workframe': [x, y, z], 
                    'xyz_lowpoint_in_workframe': [x, y, z],
                    'xyz_hook_in_worldframe': np.array,
                    'xyz_tip_in_worldframe': np.array,
                    'xyz_lowpoint_in_worldframe': np.array,
                    'tfc_in_workframe': [a, b, c],
                    'tfc_in_worldframe': np.array,
                    'xyz_path_points_in_workframe': [[x, y, z], ...]
                },
                ...
            }
    """
    data = {}
    
    with open(filename, mode="r", newline="", encoding="utf-8") as file:
        reader = csv.reader(file)
        header = next(reader)  # Überschrift überspringen
        
        for row in reader:
            if not row:
                continue
            
            key = row[0]
            
            # Werte aus der CSV-Zeile in numerische Listen bzw. NumPy-Arrays umwandeln
            # Camframe-Werte (ursprünglich NumPy-Arrays)
            cam_hook = np.array([float(x) for x in row[1:4]])
            cam_tip = np.array([float(x) for x in row[4:7]])
            cam_lowpoint = np.array([float(x) for x in row[7:10]])
            
            # Workframe-Werte (als Listen)
            work_hook = [float(x) for x in row[10:13]]
            work_tip = [float(x) for x in row[13:16]]
            work_lowpoint = [float(x) for x in row[16:19]]
            
            # Worldframe-Werte (ursprünglich NumPy-Arrays)
            world_hook = np.array([float(x) for x in row[19:22]])
            world_tip = np.array([float(x) for x in row[22:25]])
            world_lowpoint = np.array([float(x) for x in row[25:28]])
            
            # TFC-Werte
            tfc_work = [float(x) for x in row[28:31]]
            tfc_world = np.array([float(x) for x in row[31:34]])
            
            # Anzahl der Path-Punkte
            path_points_count = int(float(row[34]))
            
            # Path-Punkte (je 3 Werte pro Punkt)
            path_points = []
            index_start = 35
            for i in range(path_points_count):
                start = index_start + i * 3
                point = [float(x) for x in row[start:start+3]]
                path_points.append(point)
            
            data[key] = {
                "xyz_hook_in_camframe": cam_hook,
                "xyz_tip_in_camframe": cam_tip,
                "xyz_lowpoint_in_camframe": cam_lowpoint,
                "xyz_hook_in_workframe": work_hook,
                "xyz_tip_in_workframe": work_tip,
                "xyz_lowpoint_in_workframe": work_lowpoint,
                "xyz_hook_in_worldframe": world_hook,
                "xyz_tip_in_worldframe": world_tip,
                "xyz_lowpoint_in_worldframe": world_lowpoint,
                "tfc_in_workframe": tfc_work,
                "tfc_in_worldframe": tfc_world,
                "xyz_path_points_in_workframe": path_points
            }
    
    return data