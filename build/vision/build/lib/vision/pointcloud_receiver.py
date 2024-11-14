import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2
import struct
import numpy as np
import open3d as o3d

class PointCloudReceiver(Node):
    def __init__(self):
        super().__init__('pointcloud_receiver')
        self.subscription = self.create_subscription(
            PointCloud2,
            '/camera/camera/depth/color/points',  # Das Topic, von dem die Punktwolke empfangen wird
            self.listener_callback,
            10
        )
        self.pcloud = None

    def listener_callback(self, msg):
        # Versuche, die Punktwolke zu extrahieren
        try:
            point_array = self.extract_points(msg)
            self.pcloud = point_array  # Speichert die Punktwolke als numpy-Array
            self.visualize_pointcloud(self.pcloud)
        except Exception as e:
            self.get_logger().error(f"Fehler bei der Extraktion der Punktwolke: {e}")

    def extract_points(self, msg):
        # Extrahiere die Breite, Höhe und das Byte-Array aus der PointCloud2 Nachricht
        width = msg.width
        height = msg.height
        data = msg.data

        # Logge die Länge der Daten, um sicherzustellen, dass sie korrekt ist
        self.get_logger().info(f"Breite: {width}, Höhe: {height}, Datenlänge: {len(data)}")

        # Bestimmen der Struktur der Punktwolke (typischerweise 3 Felder: x, y, z)
        point_list = []

        # Angenommene Struktur: Jeder Punkt besteht aus 3 Fließkommazahlen (x, y, z)
        # Überprüfe, wie viele Bytes ein Punkt beansprucht
        bytes_per_point = 16  # Standardmäßig 16 Byte pro Punkt (4 Byte für x, y, z)
        
        for i in range(0, len(data), bytes_per_point):  # 16 Byte pro Punkt
            if i + 12 < len(data):  # Stelle sicher, dass genug Bytes vorhanden sind
                x = struct.unpack('f', data[i:i+4])[0]
                y = struct.unpack('f', data[i+4:i+8])[0]
                z = struct.unpack('f', data[i+8:i+12])[0]
                point_list.append([x, y, z])
            else:
                # Wenn weniger als 16 Bytes für einen Punkt übrig sind, breche ab
                break

        # Überprüfe, ob Punkte extrahiert wurden und gebe sie als numpy-Array zurück
        if len(point_list) == 0:
            raise ValueError("Keine gültigen Punktdaten gefunden.")
        
        return np.array(point_list)

    def visualize_pointcloud(self, pointcloud):
        # Erstelle ein Open3D PointCloud-Objekt
        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(pointcloud)  # Setze die Punkte der Punktwolke

        # Visualisiere die Punktwolke
        o3d.visualization.draw_geometries([pcd])  # Visualisiere die Punktwolke mit Open3D

def main(args=None):
    rclpy.init(args=args)
    node = PointCloudReceiver()
    rclpy.spin(node)  # Blockiert den Node, damit er Nachrichten empfangen kann
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
