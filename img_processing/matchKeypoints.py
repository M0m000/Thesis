import cv2
import numpy as np

# Originalbild und Template laden
image_path = "/home/mo/Thesis/1.png"
image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

template_coords = (328, 127, 494, 354)  # Anpassen je nach Template-Position
x1, y1, x2, y2 = template_coords
template = image[y1:y2, x1:x2]

# SIFT-Detektor erstellen
sift = cv2.SIFT_create()

# Keypoints und Deskriptoren für Template und Originalbild berechnen
keypoints_template, descriptors_template = sift.detectAndCompute(template, None)
keypoints_image, descriptors_image = sift.detectAndCompute(image, None)

# FLANN-Feature-Matcher einrichten
FLANN_INDEX_KDTREE = 1
index_params = dict(algorithm=FLANN_INDEX_KDTREE, trees=5)
search_params = dict(checks=50)
flann = cv2.FlannBasedMatcher(index_params, search_params)

# Features matchen
matches = flann.knnMatch(descriptors_template, descriptors_image, k=2)

# Gute Matches filtern (Lowe’s ratio test)
good_matches = []
for m, n in matches:
    if m.distance < 0.7 * n.distance:  # Niedrigere Distanz = besserer Match
        good_matches.append(m)

# Keypoints im großen Bild markieren
image_matches = cv2.drawMatches(template, keypoints_template, image, keypoints_image, good_matches, None, flags=cv2.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)

# Ergebnis anzeigen
cv2.imshow("SIFT Matches", image_matches)
cv2.waitKey(0)
cv2.destroyAllWindows()
