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
        Erstellt 2x3 Subplots mit individuellen Achsenbeschriftungen und sauberer Gruppierung.
        """
        plt.ion()
        self.fig, self.axes = plt.subplots(2, 3, figsize=(15, 8), sharex=True)

        # Haupttitel oben
        self.fig.suptitle(f"Trajektorie für Haken {self.hook_num}", fontsize=16, y=0.98)

        # Gruppentitel
        # self.fig.text(0.5, 0.91, "Translatorisch", ha='center', fontsize=14, weight='bold')
        # self.fig.text(0.5, 0.46, "Rotatorisch", ha='center', fontsize=14, weight='bold')

        y_labels_trans = ['Translation - X [mm]', 'Translation - Y [mm]', 'Translation - Z [mm]']
        y_labels_rot = ['Rotation - X [°]', 'Rotation - Y [°]', 'Rotation - Z [°]']

        for col in range(3):
            # Obere Zeile: Translation
            ax_trans = self.axes[0][col]
            ax_trans.set_ylabel(y_labels_trans[col])
            ax_trans.set_xlabel('Trajektorienpunkt')
            ax_trans.grid(True)

            # Untere Zeile: Rotation
            ax_rot = self.axes[1][col]
            ax_rot.set_ylabel(y_labels_rot[col])
            ax_rot.set_xlabel('Trajektorienpunkt')
            ax_rot.grid(True)

        # Platzanpassung für sauberes Layout
        # plt.subplots_adjust(top=0.92, hspace=0.4)
        plt.tight_layout()
        plt.show()



    def update_plot(self):
        """
        Aktualisiert die 2x3 Subplots: jede Achse bekommt ihren eigenen Plot.
        """
        if self.fig is None or self.axes is None:
            raise RuntimeError("Plot wurde noch nicht initialisiert. Bitte zuerst initialize_plot() aufrufen.")

        for row in self.axes:
            for ax in row:
                ax.cla()

        x_values = self.num_trajectory_point

        # Translation
        self.axes[0][0].plot(x_values, self.target_trans_x, label='Translation X', marker='o')
        self.axes[0][1].plot(x_values, self.target_trans_y, label='Translation Y', marker='o')
        self.axes[0][2].plot(x_values, self.target_trans_z, label='Translation Z', marker='o')

        # Rotation
        self.axes[1][0].plot(x_values, self.target_rot_x, label='Rotation X', marker='x')
        self.axes[1][1].plot(x_values, self.target_rot_y, label='Rotation Y', marker='x')
        self.axes[1][2].plot(x_values, self.target_rot_z, label='Rotation Z', marker='x')

        y_labels_trans = ['Translation - X [mm]', 'Translation - Y [mm]', 'Translation - Z [mm]']
        y_labels_rot = ['Rotation - X [°]', 'Rotation - Y [°]', 'Rotation - Z [°]']

        for col in range(3):
            # Obere Reihe
            self.axes[0][col].set_ylabel(y_labels_trans[col])
            self.axes[0][col].set_xlabel('Trajektorienpunkt')
            self.axes[0][col].legend()
            self.axes[0][col].grid(True)

            # Untere Reihe
            self.axes[1][col].set_ylabel(y_labels_rot[col])
            self.axes[1][col].set_xlabel('Trajektorienpunkt')
            self.axes[1][col].legend()
            self.axes[1][col].grid(True)

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
