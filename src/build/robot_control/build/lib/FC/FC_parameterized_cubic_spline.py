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
        # Berechne die kumulative Distanz entlang der xy-Punkte
        self.distance = [0.0]
        for i in range(1, len(self.xy_points)):
            dist = self._calculate_euclidean(self.xy_points[i-1], self.xy_points[i])
            self.distance.append(self.distance[-1] + dist)



    def interpolate(self, xy_points, start_point_with_depth, end_point_with_depth):
        self.xy_points = xy_points
        print(f"xy_points vor Interpolation: {self.xy_points}")
        self.num_points = len(xy_points)
        self.start_point = start_point_with_depth
        self.end_point = end_point_with_depth

        self._calculate_distance_for_path_points()      # Berechne Distanz als Laufparameter für Interpolation
        x_known = [self.distance[0], self.distance[-1]]
        y_known = [self.start_point[2], self.end_point[2]]
        
        # Berechne die kubische Spline-Interpolation
        if x_known == [0.0, 0.0]:
            interpolated_depths = [[0.0]] * len(self.xy_points)
        else:
            cs = CubicSpline(x_known, y_known, bc_type='natural')

            # Berechne den interpolierten Wert für jede Position in der xy_points
            interpolated_depths = cs(self.distance)
        
        # Fertige Liste mit XYZ-Werten aufbauen
        self.xyz_points = [(self.xy_points[i][0], self.xy_points[i][1], interpolated_depths[i][0]) for i in range(self.num_points)]
        return self.xyz_points


        

def main(args=None):
    rclpy.init(args=args)
    node = ParameterizedCubicSplineCalculator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
