import cv2
import numpy as np

# Originalbild laden
path = "/home/mo/Thesis/1.png"
image = cv2.imread(path, cv2.IMREAD_GRAYSCALE)

# Überprüfen, ob das Bild geladen wurde
if image is None:
    print(f"Fehler: Bild konnte nicht geladen werden! Überprüfe den Pfad: {path}")
    exit()

# Template (ein einzelner Haken) aus dem Bild ausschneiden
# (Hier sicherstellen, dass die Werte innerhalb der Bildgröße liegen)
h_img, w_img = image.shape
x1, y1, x2, y2 = 328, 127, 494, 354  # Anpassen je nach Haken-Position

# Falls das Template außerhalb des Bildes wäre → Fehler abfangen
if x2 > w_img or y2 > h_img:
    print("Fehler: Template-Koordinaten außerhalb des Bildbereichs!")
    exit()

template = image[y1:y2, x1:x2]

# Template Matching anwenden
result = cv2.matchTemplate(image, template, cv2.TM_CCOEFF_NORMED)

# Schwellenwert für Erkennung festlegen
threshold = 0.7
locations = np.where(result >= threshold)

# Bild in Farbe laden, um Markierungen einzuzeichnen
image_color = cv2.imread(path)  # Hier das korrekte Bild laden

# Falls `image_color` nicht geladen wurde
if image_color is None:
    print(f"Fehler: Farbbild konnte nicht geladen werden! Pfad: {path}")
    exit()

# Rechtecke um gefundene Haken zeichnen
w, h = template.shape[::-1]
for pt in zip(*locations[::-1]):
    cv2.rectangle(image_color, pt, (pt[0] + w, pt[1] + h), (0, 255, 0), 0)

# Ergebnis anzeigen
cv2.imshow("Erkannte Haken", image_color)
cv2.waitKey(0)
