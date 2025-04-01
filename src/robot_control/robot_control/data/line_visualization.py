import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def plot_3d_lines_between_points(point_pairs):
    """
    Zeichnet 3D-Gerade zwischen mehreren Punktpaaren in einem breiten 20x5-Plot
    mit den Achsenrichtungen:
        x → rechts
        y → unten
        z → hinten
    """
    fig = plt.figure(figsize=(10, 10))
    ax = fig.add_subplot(111, projection='3d')

    for i, (P1, P2) in enumerate(point_pairs):
        # y und z invertieren
        X = [P1[0], P2[0]]
        Y = [-P1[1], -P2[1]]  # y umdrehen
        Z = [P1[2], P2[2]]  # z umdrehen

        ax.plot(X, Y, Z, linewidth=2, label=f'Linie {i+1}')
        ax.scatter(P1[0], -P1[1], P1[2], color='red', s=30)
        ax.scatter(P2[0], -P2[1], P2[2], color='green', s=30)

    ax.set_xlabel('X (rechts)')
    ax.set_ylabel('Y (unten)')
    ax.set_zlabel('Z (hinten)')
    ax.set_title('Trajektorie - Geraden (angepasste Achsen)')

    ax.legend()
    plt.grid(True)
    plt.show()


lines = [
    ([-173.69569033,  831.98224138,  737.13064452], [-180.37176785,  837.88333193,  732.41665942]),
    ([-180.37176785,  837.88333193,  732.41665942], [-180.75789583,  839.02174189,  731.70127995]),
    ([-180.75789583,  839.02174189,  731.70127995], [-181.65181934,  839.15195573,  730.87255754]),
    ([-181.65181934,  839.15195573,  730.87255754], [-182.39659621,  839.25684986,  730.27033526]),
    ([-182.39659621,  839.25684986,  730.27033526], [-183.0905307 ,  840.44117502,  729.54589902]),
    ([-183.0905307 ,  840.44117502,  729.54589902], [-183.98909832,  840.55364739,  728.71142794]),
    ([-183.98909832,  840.55364739,  728.71142794], [-184.69243059,  841.73942454,  727.97690449]),
    ([-184.69243059,  841.73942454,  727.97690449], [-185.59323154,  841.85800265,  727.44681285]),
    ([-185.59323154,  841.85800265,  727.44681285], [-186.60150931,  843.1131024 ,  727.48135849]),
    ([-186.60150931,  843.1131024 ,  727.48135849], [-187.65326761,  843.25938578,  727.41459437]),
]

plot_3d_lines_between_points(lines)