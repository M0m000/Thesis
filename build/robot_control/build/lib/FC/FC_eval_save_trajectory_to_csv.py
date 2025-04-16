import csv

def save_trajectory_to_csv(trajectory, filepath):
    """Speichert die Trajektorie-Liste als CSV unter angegebenem Pfad"""
    with open(filepath, mode='w', newline = '') as file:
        writer = csv.writer(file)
        writer.writerow(['x', 'y', 'z', 'roll', 'pitch', 'yaw'])

        for trans, rot in trajectory:
            row = trans + rot
            writer.writerow(row)


def load_csv_to_trajectory(filepath):
    """Lädt die CSV und stellt Trajektorie-Liste wieder her"""
    trajectory = []
    with open(filepath, mode='r', newline='') as file:
        reader = csv.reader(file)
        next(reader)  # Überspringe Kopfzeile

        for row in reader:
            numbers = list(map(float, row))
            trans = numbers[:3]
            rot = numbers[3:]
            trajectory.append((trans, rot))
    return trajectory