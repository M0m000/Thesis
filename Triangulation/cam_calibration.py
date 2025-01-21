import cv2
import numpy as np
import glob

# Checkerboard-Abmessungen
CHECKERBOARD = (8, 6)  # Anzahl der inneren Ecken (nx, ny)
square_size = 25.0      # Größe eines Quadrats in der gewünschten Maßeinheit (z. B. Millimeter)

# Termination criteria für die Subpixelgenauigkeit
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)

# Weltkoordinaten für 3D-Punkte
objp = np.zeros((CHECKERBOARD[0] * CHECKERBOARD[1], 3), np.float32)
objp[:, :2] = np.mgrid[0:CHECKERBOARD[0], 0:CHECKERBOARD[1]].T.reshape(-1, 2)
objp *= square_size  # Anpassen der Skalierung

# Arrays zum Speichern von 3D-Punkten (Weltkoordinaten) und 2D-Punkten (Bildkoordinaten)
objpoints = []  # 3D-Punkte in der realen Welt
imgpoints = []  # 2D-Punkte im Bild

# Lade alle Bilder aus einem Verzeichnis
images = glob.glob("/home/mo/Thesis/vc_imgs/*.png")  # Passe den Pfad an deine Bilder an

for fname in images:
    img = cv2.imread(fname)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Finde Ecken des Schachbretts
    ret, corners = cv2.findChessboardCorners(gray, CHECKERBOARD, None)

    if ret:
        objpoints.append(objp)
        # Verfeinern der Eckenposition
        corners2 = cv2.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)
        imgpoints.append(corners2)

        # Zeichne und zeige die Ecken
        cv2.drawChessboardCorners(img, CHECKERBOARD, corners2, ret)
        cv2.imshow('Chessboard', img)
        cv2.waitKey(100)

cv2.destroyAllWindows()

# Führe die Kamerakalibrierung durch
ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)

# Ausgabe der Ergebnisse
print("Kameramatrix (mtx):")
print(mtx)
print("\nVerzerrungskoeffizienten (dist):")
print(dist)
print("\nRotationsvektoren (rvecs):")
print(rvecs)
print("\nTranslationsvektoren (tvecs):")
print(tvecs)

# Speichere die Ergebnisse in einer Datei
np.savez("calibration_data.npz", mtx=mtx, dist=dist, rvecs=rvecs, tvecs=tvecs)

# Optional: Fehler der Kalibrierung berechnen
total_error = 0
for i in range(len(objpoints)):
    imgpoints2, _ = cv2.projectPoints(objpoints[i], rvecs[i], tvecs[i], mtx, dist)
    error = cv2.norm(imgpoints[i], imgpoints2, cv2.NORM_L2) / len(imgpoints2)
    total_error += error

print("\nKalibrierungsfehler:")
print(total_error / len(objpoints))
np.savez("calibration_data.npz", mtx=mtx, dist=dist, rvecs=rvecs, tvecs=tvecs)