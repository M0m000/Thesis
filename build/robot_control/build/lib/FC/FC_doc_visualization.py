import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import cv2
from io import BytesIO
from PIL import Image

class DocVisualization:
    def __init__(self, plot_save_filename = 'plot.png'):
        self.hook_points = []
        self.lowpoint_points = []
        self.tip_points = []
        
        # Plot-Objekte
        self.fig = None
        self.ax3d = None
        self.scatter_hook = None
        self.scatter_lowpoint = None
        self.scatter_tip = None

        self.plot_save_filename = plot_save_filename

    def update_lists(self, hook_point, lowpoint_point, tip_point):
        self.hook_points.append(hook_point)
        self.lowpoint_points.append(lowpoint_point)
        self.tip_points.append(tip_point)

    def init_plot(self):
        self.fig = plt.figure(figsize=(10, 6))
        self.ax3d = self.fig.add_subplot(projection='3d')

        # Leere Scatterplots erzeugen
        self.scatter_hook = self.ax3d.scatter([], [], [], color='red', s=60, label='Haken')
        self.scatter_lowpoint = self.ax3d.scatter([], [], [], color='green', s=60, label='Spitze')
        self.scatter_tip = self.ax3d.scatter([], [], [], color='blue', s=60, label='Senke')

        self.ax3d.set_xlabel("X")
        self.ax3d.set_ylabel("Z")
        self.ax3d.set_zlabel("Y")
        self.ax3d.set_title("Vergleich Triangulationsverfahren Hakenspitze")
        self.ax3d.set_xlim([0, 1000])
        self.ax3d.set_ylim([200, 380])
        self.ax3d.set_zlim([0, 600])
        self.ax3d.legend()

    def update_plot(self):
        if self.fig is None or self.ax3d is None:
            self.init_plot()

        def extract_xyz(points):
            x = [p[0] for p in points]
            y = [-p[1] for p in points]
            z = [p[2] for p in points]
            return x, y, z

        # Update Daten der Scatterplots
        xh, yh, zh = extract_xyz(self.hook_points)
        xl, yl, zl = extract_xyz(self.lowpoint_points)
        xt, yt, zt = extract_xyz(self.tip_points)

        # Damit matplotlib nicht alles übereinander zeichnet: clear
        self.ax3d.cla()

        # Achsen & Labels neu setzen
        self.ax3d.set_xlabel("X")
        self.ax3d.set_ylabel("Z")
        self.ax3d.set_zlabel("Y")
        self.ax3d.set_title("Vergleich Triangulationsverfahren Hakenspitze")
        self.ax3d.set_xlim([0, 1000])
        self.ax3d.set_ylim([200, 380])
        self.ax3d.set_zlim([0, 600])

        # Neue Daten setzen
        self.ax3d.scatter(xh, yh, zh, color='red', s=60, label='Haken')
        self.ax3d.scatter(xl, yl, zl, color='green', s=60, label='Spitze')
        self.ax3d.scatter(xt, yt, zt, color='blue', s=60, label='Senke')
        self.ax3d.legend()

    def _show_plot_cv2(self):
        buf = BytesIO()
        self.fig.tight_layout()
        self.fig.savefig(buf, format='png')
        buf.seek(0)
        img = np.array(Image.open(buf))
        img_cv = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)

        cv2.imshow("3D Plot", img_cv)
        cv2.waitKey(1)  # Nur kurzes Warten (z. B. für Live-Update)

    def save_plot_as_png(self):
        """
        Speichert den aktuellen Plot als PNG-Datei.
        """
        # In OpenCV anzeigen
        self._show_plot_cv2()
        
        if self.fig is None or self.ax3d is None:
            print("Plot wurde noch nicht initialisiert. Wird nun erstellt.")
            self.update_plot()  # Erstellt automatisch initialen Plot

        self.fig.tight_layout()
        self.fig.savefig(self.plot_save_filename, format='png')
        print(f"Plot gespeichert als: {self.plot_save_filename}")

    def show_interactive_plot(self):
        """
        Zeigt den Plot in einem interaktiven Matplotlib-Fenster (mit Mausnavigation).
        """
        if self.fig is None or self.ax3d is None:
            self.update_plot()

        plt.show()