import numpy as np
from scipy.spatial.transform import Rotation as R
from scipy.optimize import least_squares

def pose_to_matrix(trans, rot):
    T = np.eye(4)
    T[:3, :3] = R.from_euler('xyz', rot, degrees=True).as_matrix()
    T[:3, 3] = trans
    return T

def residuals(params, T_list):
    tcp = params[0:3]  # TCP-Position im Flansch-Frame
    target = params[3:6]  # Zielposition im Welt-Frame (z.B. Kugelmittelpunkt)

    res = []
    for T in T_list:
        R_i = T[:3, :3]
        t_i = T[:3, 3]
        tcp_world = R_i @ tcp + t_i
        res.append(tcp_world - target)
    return np.concatenate(res)

def compute_tcp_optimized(trans_list, rot_list):
    T_list = [pose_to_matrix(t, r) for t, r in zip(trans_list, rot_list)]

    # Startwerte: TCP = [0, 0, 100], Target = Mittelwert der TCPs
    x0 = np.array([0, 0, 100] + list(np.mean(trans_list, axis=0)))

    result = least_squares(residuals, x0, args=(T_list,))
    tcp = result.x[0:3]
    target_world = result.x[3:6]
    return tcp, target_world

# Beispiel-Nutzung:
if __name__ == "__main__":
    trans_list = [
        [52.14649093, 642.54542566, 693.269062],
        [-68.56129016, 666.79494523, 646.75636112],
        [-80.07006246, 723.95642484, 552.5836472],
        [66.89890735, 731.20698436, 528.58801061]
    ]
    rot_list = [
        [-84.67578928, -25.56641499, 3.60330512],
        [-75.59184062, 14.45429749, -12.20130809],
        [-54.79747107, 8.76842659, -16.70401707],
        [-44.31530248, -21.73757078, -8.23060835]
    ]

    tcp, target = compute_tcp_optimized(trans_list, rot_list)
    print("TCP im Flansch-Frame:", tcp)
    print("Zielposition im Welt-Frame:", target)
