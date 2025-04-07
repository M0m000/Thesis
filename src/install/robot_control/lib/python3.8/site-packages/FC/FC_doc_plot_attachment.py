import matplotlib.pyplot as plt

class DocPlotAttachment:
    def __init__(self, plot_save_filename='attachment_plot.png', hook_num=None):
        self.hook_num = hook_num
        self.num_trajectory_point = []

        self.target_trans_x = []
        self.target_trans_y = []
        self.target_trans_z = []
        self.target_rot_x = []
        self.target_rot_y = []
        self.target_rot_z = []

        self.plot_save_filename = plot_save_filename
        self.fig = None
        self.axes = None



    def update_plot_lists(self, target_trans_list=[], target_rot_list=[], num_trajectory_point=0):
        """
        Methode für das Anhängen neuer Plot-Werte an die Listen
        """
        if target_trans_list != []:
            self.target_trans_x.append(target_trans_list[0])
            self.target_trans_y.append(target_trans_list[1])
            self.target_trans_z.append(target_trans_list[2])

        if target_rot_list != []:
            self.target_rot_x.append(target_rot_list[0])
            self.target_rot_y.append(target_rot_list[1])
            self.target_rot_z.append(target_rot_list[2])

        self.num_trajectory_point.append(num_trajectory_point)



    def initialize_plot(self):
        """
        Erstellt 2 vertikale Subplots:
        1. Translation (x, y, z)
        2. Rotation (x, y, z)
        """
        plt.ion()
        self.fig, self.axes = plt.subplots(2, 1, figsize=(10, 10), sharex=True)
        self.fig.suptitle(f"Trajektorie für Haken {self.hook_num}", fontsize=16)

        titles = ['Translation (X, Y, Z)', 'Rotation (X, Y, Z)']

        for i, ax in enumerate(self.axes):
            ax.set_title(titles[i])
            ax.set_ylabel('Sollwert Trajektorie')
            ax.grid(True)

        # self.axes[-1].set_xlabel('Trajektorienpunkt')
        # plt.tight_layout(rect=[0, 0.03, 1, 0.95])
        plt.show()



    def update_plot(self):
        """
        Aktualisiert die drei Subplots: Trajektorienpunkt, Translationen, Rotationen
        """
        if self.fig is None or self.axes is None:
            raise RuntimeError("Plot wurde noch nicht initialisiert. Bitte zuerst initialize_plot() aufrufen.")

        for ax in self.axes:
            ax.cla()

        # 2. Translation
        self.axes[0].set_title('Translation (X, Y, Z)')
        self.axes[0].plot(self.target_trans_x, label='X', marker='o')
        self.axes[0].plot(self.target_trans_y, label='Y', marker='o')
        self.axes[0].plot(self.target_trans_z, label='Z', marker='o')
        self.axes[0].legend()
        self.axes[0].grid(True)
        self.axes[0].set_xlabel('Trajektorienpunkt')
        self.axes[0].set_ylabel('Sollwert [mm]')

        # 3. Rotation
        self.axes[1].set_title('Rotation (X, Y, Z)')
        self.axes[1].plot(self.target_rot_x, label='X', marker='x')
        self.axes[1].plot(self.target_rot_y, label='Y', marker='x')
        self.axes[1].plot(self.target_rot_z, label='Z', marker='x')
        self.axes[1].legend()
        self.axes[1].grid(True)
        self.axes[1].set_xlabel('Trajektorienpunkt')
        self.axes[1].set_ylabel('Sollwert [°]')

        self.fig.canvas.draw()
        self.fig.canvas.flush_events()



    def save_plot_as_png(self):
        """
        Speichert den aktuellen Plot als PNG-Datei mit '_hook_<hook_num>' im Dateinamen.
        """
        if self.fig is None:
            raise RuntimeError("Plot wurde noch nicht initialisiert. Bitte zuerst initialize_plot() aufrufen.")
        if self.hook_num is None:
            raise ValueError("hook_num ist nicht gesetzt. Bitte vor dem Speichern setzen.")

        if self.plot_save_filename.lower().endswith('.png'):
            base_name = self.plot_save_filename[:-4]
        else:
            base_name = self.plot_save_filename

        filename_with_hook = f"{base_name}_hook_{self.hook_num}.png"
        self.fig.savefig(filename_with_hook, dpi=600, bbox_inches='tight')
        print(f"Plot gespeichert als '{filename_with_hook}'")
