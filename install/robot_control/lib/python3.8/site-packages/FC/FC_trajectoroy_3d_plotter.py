import plotly.graph_objects as go
import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial.transform import Rotation as R
import threading
import dash
from dash import dcc, html
from dash.dependencies import Input, Output



class TrajectoryPlotter:
    def __init__(self, interp_step_size = 0.1, hole_width = 8, hole_height = 12, hook_num = 1, hook_type = 'A', trajectory_process = 1):
        self.fig = go.Figure()
        
        self.interp_step_size = interp_step_size
        self.hole_width = hole_width
        self.hole_height = hole_height
        self.hook_num = hook_num
        self.hook_type = hook_type
        self.trajectory_process = trajectory_process

        self.interpolated_trajectory = None
        self.trajectory_rectangles = None
        self.magenta_rect_trace_index = None
        self.raw_trajectory = None
        


    def process_trajectory_for_plot(self, trajectory):
        """
        Methode zum Berechnen des Plots aus Trajektorie
        """
        self.raw_trajectory = trajectory
        self.interpolated_trajectory = self._interpolate_and_package(trajectory = trajectory)
        self._compute_rectangle_corners()


    
    def _interpolate_trajectory_by_distance(self, traj):
        """
        Interpoliert eine Trajektorie ab Punkt 1 mit gleichmäßigem Abstand (step_size), 
        wobei Punkt 0 unverändert erhalten bleibt.
        """
        positions = np.array([p[0] for p in traj])
        rotations = np.array([p[1] for p in traj])

        # Segment ab Punkt 1
        positions_tail = positions[1:]
        rotations_tail = rotations[1:]

        deltas_trans = np.linalg.norm(np.diff(positions_tail, axis=0), axis=1)
        cumulative_dist_trans = np.concatenate([[0], np.cumsum(deltas_trans)])
        total_length = cumulative_dist_trans[-1]

        # Punkte ab Punkt 1 in step_size-Abständen
        target_distances_trans = np.arange(0, total_length + self.interp_step_size, self.interp_step_size)
        if target_distances_trans[-1] > total_length:
            target_distances_trans[-1] = total_length

        interp_positions = [positions[0]]  # Originalpunkt 0
        for dist in target_distances_trans:
            idx = np.searchsorted(cumulative_dist_trans, dist) - 1
            idx = np.clip(idx, 0, len(positions_tail) - 2)
            t = (dist - cumulative_dist_trans[idx]) / (cumulative_dist_trans[idx + 1] - cumulative_dist_trans[idx])
            point = (1 - t) * positions_tail[idx] + t * positions_tail[idx + 1]
            interp_positions.append(point)

        # Interpolation der Rotationen ab Punkt 1
        interp_rotations = [rotations[0]]  # Rotation für Punkt 0
        if np.allclose(rotations_tail, rotations_tail[0]):
            interp_rotations += [rotations_tail[0]] * (len(interp_positions) - 1)
        else:
            deltas_rot = np.linalg.norm(np.diff(rotations_tail, axis=0), axis=1)
            cumulative_dist_rot = np.concatenate([[0], np.cumsum(deltas_rot)])
            target_distances_rot = np.linspace(0, cumulative_dist_rot[-1], len(interp_positions) - 1)

            for rot in target_distances_rot:
                idx = np.searchsorted(cumulative_dist_rot, rot) - 1
                idx = np.clip(idx, 0, len(rotations_tail) - 2)
                denom = cumulative_dist_rot[idx + 1] - cumulative_dist_rot[idx]
                t = 0 if denom == 0 else (rot - cumulative_dist_rot[idx]) / denom
                point = (1 - t) * rotations_tail[idx] + t * rotations_tail[idx + 1]
                interp_rotations.append(point)
        return np.array(interp_positions), np.array(interp_rotations)
    
    

    def _compute_rectangle_corners(self, trajectory = None):
        rectangles = []

        half_w = self.hole_width / 2
        half_h = self.hole_height / 2

        # Rechteck immer in der XZ-Ebene
        local_corners = np.array([
            [-half_w, 0, -half_h],      # links unten
            [ half_w, 0, -half_h],      # rechts unten
            [ half_w, 0,  half_h],      # rechts oben
            [-half_w, 0,  half_h]       # links oben
        ])

        if trajectory is None:
            trajectory = self.interpolated_trajectory

        for pos, rpy in trajectory:
            rot = R.from_euler('xyz', rpy, degrees=True)
            rotated_corners = rot.apply(local_corners)
            translated_corners = rotated_corners + np.array(pos)
            rectangles.append(translated_corners.tolist())
        self.trajectory_rectangles = rectangles
        return rectangles



    def _interpolate_and_package(self, trajectory):
        interp_pos, interp_rot = self._interpolate_trajectory_by_distance(trajectory)
        return list(zip(interp_pos, interp_rot))



    def create_static_plot(self):
        """
        Erstellt den statischen Plot: Alle Rechtecke, Linien und festen Elemente.
        """
    
        ##### Berechnete Trajektorie (farbig)
        centers = []
        if self.trajectory_rectangles:
            for i, rect in enumerate(self.trajectory_rectangles):
                color = 'blue'
                x, y, z = zip(*rect)

                self.fig.add_trace(go.Mesh3d(x=x, y=y, z=z, color=color, opacity=0.05, 
                                       name=f'P{i+1}'))

                center = np.mean(np.array(rect), axis=0)
                centers.append(center)

                self.fig.add_trace(go.Scatter3d(x=[center[0]], y=[center[1]], z=[center[2]], 
                                           mode='markers+text', marker=dict(size=3, color='blue'),
                                           text='', textposition="top center", textfont=dict(size=12), showlegend=False))

                if i == 0 or i == 1 or i == (len(self.trajectory_rectangles) - 1):
                    for j in range(4):
                        x0, y0, z0 = rect[j]
                        x1, y1, z1 = rect[(j + 1) % 4]
                        self.fig.add_trace(go.Scatter3d(x=[x0, x1], y=[y0, y1], z=[z0, z1], 
                                                   mode='lines', 
                                                   line=dict(color=color, width=4),
                                                   showlegend=False))

            centers = np.array(centers)
            self.fig.add_trace(go.Scatter3d(x=centers[:, 0], y=centers[:, 1], z=centers[:, 2],
                                       mode='lines', line=dict(color='black', width=2), name='Berechnete Hakenlinie'))

            if len(centers) > 0:
                self.fig.add_trace(go.Scatter3d(x=[centers[0, 0]], y=[centers[0, 1]], z=[centers[0, 2]],
                                           mode='text', text=['Pre-Position'], textposition="top center", textfont=dict(size=10), showlegend=False))
            if len(centers) > 2:
                self.fig.add_trace(go.Scatter3d(x=[centers[-1, 0]+1], y=[centers[-1, 1]+1], z=[centers[-1, 2]+1],
                                           mode='text', text=['Loslassen'], textposition="top center", textfont=dict(size=10), showlegend=False))

            num_corners = 4
            for corner_idx in range(num_corners):
                x_line, y_line, z_line = [], [], []
                for rect in self.trajectory_rectangles:
                    x, y, z = rect[corner_idx]
                    x_line.append(x)
                    y_line.append(y)
                    z_line.append(z)

                self.fig.add_trace(go.Scatter3d(x=x_line, y=y_line, z=z_line,
                                           mode='lines',
                                           line=dict(color='blue', width=3),
                                           showlegend=False))

        ##### Spitze und Senke (berechnet)
        connect_points = (self.raw_trajectory[1][0], self.raw_trajectory[-1][0])
        if connect_points:
            p1, p2 = np.array(connect_points[0]), np.array(connect_points[1])
            self.fig.add_trace(go.Scatter3d(x=[p1[0], p2[0]], y=[p1[1], p2[1]], z=[p1[2], p2[2]], 
                                       mode='lines', line=dict(color='gray', dash='dash'), name='Direkte Gerade Spitze -> Senke'))
            self.fig.add_trace(go.Scatter3d(x=[p1[0]], y=[p1[1]], z=[p1[2]], mode='markers', 
                                       marker=dict(size=8, color='magenta'), name='Spitze (berechnet)'))
            self.fig.add_trace(go.Scatter3d(x=[p2[0]], y=[p2[1]], z=[p2[2]], mode='markers', 
                                       marker=dict(size=8, color='magenta'), name='Senke (berechnet)'))

            self.fig.add_trace(go.Scatter3d(x=[p1[0]], y=[p1[1]], z=[p1[2]], mode='text', 
                                       text=['Spitze (berechnet)'], textposition="top center", textfont=dict(size=10), showlegend=False))
            self.fig.add_trace(go.Scatter3d(x=[p2[0]], y=[p2[1]], z=[p2[2]], mode='text', 
                                       text=['Senke (berechnet)'], textposition="top center", textfont=dict(size=10), showlegend=False))

        ##### Layout Einstellungen
        self.fig.update_layout(
            width=1200,   # Breite in Pixel
            height=800,   # Höhe in Pixel
            scene=dict(
                xaxis_title='X',
                yaxis_title='Y',
                zaxis_title='Z',
                aspectmode='data',
                camera=dict(
                    up=dict(x=0, y=0, z=1),  # Z-Achse zeigt nach oben
                    eye=dict(x=-1.2, y=-1.2, z=0.3)  # schräg von oben vorne
                )
            ),
            title=f'Haken {self.hook_num} (Modell {self.hook_type}), Trajektorien-Ansatz {self.trajectory_process}',
            legend=dict(title="Legende")
        )



    def update_3d_plot(self, act_traj_rectangle):
        x, y, z = zip(*act_traj_rectangle)
        
        # Wenn schon ein magenta-Rechteck existiert, lösche es
        if self.magenta_rect_trace_index is not None:
            self.fig.data = tuple(trace for i, trace in enumerate(self.fig.data) if i != self.magenta_rect_trace_index)
        
        # Neuen magenta Trace einfügen
        new_trace = go.Mesh3d(
            x=x, y=y, z=z,
            color='magenta',
            opacity=0.8,
            name='Aktuelle Pose'
        )
        self.fig.add_trace(new_trace)

        # Index vom neuen Trace speichern
        self.magenta_rect_trace_index = len(self.fig.data) - 1

        # Update-Trigger für Browser erhöhen
        if hasattr(self, '_update_trigger'):
            self._update_trigger += 1



    def start_live_server(self, port=8050, update_interval=500):
        """
        Startet einen Dash-Server, der den Plot live im Browser anzeigt.
        update_interval in Millisekunden.
        """
        self._update_trigger = 0  # Zähler für Updates
        self._last_update_trigger = -1

        app = dash.Dash(__name__)
        self._app = app  # merken

        app.layout = html.Div([
            dcc.Graph(id='live-plot', figure=self.fig),
            dcc.Interval(id='interval-component', interval=update_interval, n_intervals=0)
        ])

        @app.callback(
            Output('live-plot', 'figure'),
            Input('interval-component', 'n_intervals')
        )
        def update_graph(n):
            # Nur aktualisieren, wenn sich der Trigger geändert hat
            if self._update_trigger != self._last_update_trigger:
                self._last_update_trigger = self._update_trigger
                return self.fig
            else:
                raise dash.exceptions.PreventUpdate  # Spart Ressourcen, wenn nichts neu ist

        # Dash-Server in eigenem Thread starten
        def run_dash():
            app.run(debug=False, port=port, use_reloader=False)
            # app.run_server(debug=False, port=port, use_reloader=False)

        threading.Thread(target=run_dash, daemon=True).start()
        print(f"Dash Server läuft auf http://127.0.0.1:{port}")



    def show(self):
        self.fig.show()



    def save_html(self, filename):
        self.fig.write_html(filename)
        print(f"Gespeichert unter: {filename}")
