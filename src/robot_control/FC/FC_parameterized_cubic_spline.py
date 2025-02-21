import rclpy
from rclpy.node import Node
import numpy as np
from scipy.interpolate import CubicSpline


class ParameterizedCubicSplineCalculator(Node):
    def __init__(self):
        super().__init__("cubic_spline")
        self.xy_points = None
        self.start_point = None
        self.end_point = None
        self.distance = None
        self.num_points = None
        self.xyz_points = None



    def _calculate_euclidean(self, start_point, end_point):
        x_startpt = start_point[0]
        y_startpt = start_point[1]
        x_endpt = end_point[0]
        y_endpt = end_point[1]
        return np.sqrt((x_endpt - x_startpt)**2 + (y_endpt - y_startpt)**2)



    def _calculate_distance_for_path_points(self):
        self.distance = []
        for i in range(1, len(self.xy_points)):
            # Berechne die Distanz zwischen aufeinanderfolgendem Punkt
            dist = self._calculate_euclidean(self.xy_points[i-1], self.xy_points[i])
            self.distance.append(dist)
        # Am Ende noch die Distanz für den letzten Punkt berechnen
        self.distance.append(self._calculate_euclidean(self.xy_points[-1], self.xy_points[-1]))



    def interpolate(self, xy_points, start_point_with_depth, end_point_with_depth):
        self.xy_points = xy_points
        self.num_points = len(xy_points)
        self.start_point = start_point_with_depth
        self.end_point = end_point_with_depth

        # Lege Liste für Ergebnisse an (erste Position ist Start-Tiefenwert, letzte Position ist End-Tiefenwert)
        depth_results = [None] * self.num_points
        depth_results[0] = self.start_point[2]
        depth_results[-1] = self.end_point[2]

        self._calculate_distance_for_path_points()      # Berechne Distanz als Laufparameter für Interpolation

        # Berechne die kubische Spline-Interpolation
        # 'self.distance' sind die x-Werte, 'depth_results' sind die y-Werte
        cs = CubicSpline(self.distance, depth_results, bc_type='natural')

        # Berechne den interpolierten Wert für jede Position in der xy_points
        interpolated_depths = cs(self.distance)

        # Ergebnis in depth_results eintragen
        for i in range(1, self.num_points - 1):
            depth_results[i] = interpolated_depths[i]

        # Fertige Liste mit XYZ-Werten aufbauen
        self.xyz_points = [(self.xy_points[i][0], self.xy_points[i][1], depth_results[i]) for i in range(self.num_points)]
        return self.xyz_points


        

def main(args=None):
    rclpy.init(args=args)
    node = ParameterizedCubicSplineCalculator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
