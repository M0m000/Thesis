import pyqtgraph as pg
import pyqtgraph.opengl as gl
from PyQt5 import QtWidgets
import numpy as np
import sys
from PIL import Image

# pg.setConfigOption('background', 'w')
# pg.setConfigOption('foreground', 'k')

class DocVisualization:
    def __init__(self, plot_save_filename='3d_graphic.png'):

        self.plot_save_filename = plot_save_filename

        self.hook_points = []
        self.lowpoint_points = []
        self.tip_points = []
        self.path_points = []

        # Qt-Init
        self.app = QtWidgets.QApplication(sys.argv)
        self.window = gl.GLViewWidget()
        self.window.setWindowTitle('3D Visualisierung')
        self.window.setGeometry(0, 110, 1200, 800)
        self.window.show()
        self.window.setCameraPosition(elevation=30, azimuth=260)

        # Achsen hinzufügen
        grid = gl.GLGridItem()
        # grid.setColor((0.5, 0.5, 0.5, 1))
        grid.scale(1000, 1000, 1000)
        self.window.addItem(grid)
        self.window.opts['distance'] = 2000

        # Scatter-Objekte
        self.scatter_hook = gl.GLScatterPlotItem()
        self.scatter_lowpoint = gl.GLScatterPlotItem()
        self.scatter_tip = gl.GLScatterPlotItem()
        self.scatter_path = gl.GLScatterPlotItem()
        self.scatter_fixed_points = gl.GLScatterPlotItem()
        self.window.addItem(self.scatter_fixed_points)

        # Linienliste
        self.line_items = []

        self.window.addItem(self.scatter_hook)
        self.window.addItem(self.scatter_lowpoint)
        self.window.addItem(self.scatter_tip)
        self.window.addItem(self.scatter_path)

        # Feste Punkte vorbereiten -> Gestell
        fixed_points_raw = [
            [0, 0, 0],
            [0, 0, 500],
            [1050, 0, 500],
            [1050, 0, 0],
            [0, -600, 500],
            [1050, -600, 500]
        ]

        self.p_down = [
            [0, 0, 0],     # p_down_1
            [0, 0, 500],   # p_down_2
            [1050, 0, 500],  # p_down_3
            [1050, 0, 0], # p_down_4
            [0, 0, 0]
        ]

        p_down_line_points = np.array([[p[0], p[2], -p[1]] for p in self.p_down])
        self.line_p_down = gl.GLLinePlotItem(
            pos=p_down_line_points,
            color=(1, 1, 1, 1),  # schwarz
            width=4,
            antialias=True,
            mode='line_strip'
        )
        self.window.addItem(self.line_p_down)

        self.p_up = [
            [0, 0, 500],
            [0, -600, 500],
            [1050, -600, 500],
            [1050, 0, 500]
        ]

        p_up_line_points = np.array([[p[0], p[2], -p[1]] for p in self.p_up])
        self.line_p_up = gl.GLLinePlotItem(
            pos=p_up_line_points,
            color=(1, 1, 1, 1),  # schwarz
            width=4,
            antialias=True,
            mode='line_strip'
        )
        self.window.addItem(self.line_p_up)

        # Umrechnen: [x, z, -y]
        self.fixed_points = np.array([[p[0], p[2], -p[1]] for p in fixed_points_raw])

        # Plot setzen
        self.scatter_fixed_points.setData(pos=self.fixed_points, color=(1, 1, 1, 1), size=10)

    def update_lists(self, hook_point, lowpoint_point, tip_point, path_points):
        self.hook_points.append(hook_point)
        self.lowpoint_points.append(lowpoint_point)
        self.tip_points.append(tip_point)
        self.path_points.append(path_points)

    def update_plot(self):
        def convert_points(points):
            return np.array([[p[0], p[2], -p[1]] for p in points])  # x, y, z (negiertes y → z)

        hook_array = convert_points(self.hook_points)
        low_array = convert_points(self.lowpoint_points)
        tip_array = convert_points(self.tip_points)
        path_array = np.vstack([convert_points(p) for p in self.path_points]) if self.path_points else np.empty((0, 3))

        # Update Scatter
        self.scatter_hook.setData(pos=hook_array, color=(1, 0, 0, 1), size=10)      # rot
        self.scatter_lowpoint.setData(pos=low_array, color=(0, 0, 1, 1), size=10)   # blau
        self.scatter_tip.setData(pos=tip_array, color=(0, 1, 0, 1), size=10)        # grün
        self.scatter_path.setData(pos=path_array, color=(1, 0, 1, 1), size=5)       # magenta

        # Alte Linien entfernen
        for line in self.line_items:
            self.window.removeItem(line)
        self.line_items.clear()

        # Neue Linien (Hook → Lowpoint → Tip)
        for i in range(len(self.hook_points)):
            if i < len(self.lowpoint_points) and i < len(self.tip_points):
                h = self.hook_points[i]
                l = self.lowpoint_points[i]
                t = self.tip_points[i]

                hl = np.array([[h[0], h[2], -h[1]], [l[0], l[2], -l[1]]])
                lt = np.array([[l[0], l[2], -l[1]], [t[0], t[2], -t[1]]])

                line1 = gl.GLLinePlotItem(pos=hl, color=(0.5, 0.5, 0.5, 1), width=2, antialias=True)
                line2 = gl.GLLinePlotItem(pos=lt, color=(0.5, 0.5, 0.5, 1), width=2, antialias=True)
                self.window.addItem(line1)
                self.window.addItem(line2)
                self.line_items.extend([line1, line2])

        # Automatische Kamerazentrierung & Skalierung
        all_points = np.concatenate([
            hook_array,
            low_array,
            tip_array,
            path_array,
            self.fixed_points
        ]) if len(path_array) > 0 else np.concatenate([
            hook_array,
            low_array,
            tip_array,
            self.fixed_points
        ])

        if all_points.size > 0:
            min_vals = np.min(all_points, axis=0)
            max_vals = np.max(all_points, axis=0)
            center = (min_vals + max_vals) / 2
            max_range = np.max(max_vals - min_vals)

            # Kamera zentrieren
            self.window.setCameraPosition(
                pos=pg.Vector(*center),
                distance=max_range * 2.0,
                elevation=self.window.opts['elevation'],
                azimuth=self.window.opts['azimuth']
            )

            # Dynamisches Koordinatensystem anzeigen
            axis_len = max_range * 0.1

            if hasattr(self, 'axis_items'):
                for item in self.axis_items:
                    self.window.removeItem(item)

            origin = center
            self.axis_items = []

            # X-Achse (rot)
            x_axis = gl.GLLinePlotItem(pos=np.array([
                origin,
                origin + np.array([axis_len, 0, 0])
            ]), color=(1, 0, 0, 0.7), width=2)
            self.window.addItem(x_axis)
            self.axis_items.append(x_axis)

            # Y-Achse (grün)
            y_axis = gl.GLLinePlotItem(pos=np.array([
                origin,
                origin + np.array([0, 0, -axis_len])
            ]), color=(0, 1, 0, 0.7), width=2)
            self.window.addItem(y_axis)
            self.axis_items.append(y_axis)

            # Z-Achse (blau)
            z_axis = gl.GLLinePlotItem(pos=np.array([
                origin,
                origin + np.array([0, axis_len, 0])
            ]), color=(0, 0, 1, 0.7), width=2)
            self.window.addItem(z_axis)
            self.axis_items.append(z_axis)

        self.app.processEvents()

    def save_plot_as_png(self):
        screenshot = self.window.grabFramebuffer()
        success = screenshot.save(self.plot_save_filename, 'PNG')
        if success:
            print(f"3D Plot saved as: {self.plot_save_filename}")
        else:
            print("Error at saving 3D Plot!")
    