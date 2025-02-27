import cv2
import numpy as np
import matplotlib.pyplot as plt

# Bild laden
image_path = "/home/mo/Thesis/1.png"
image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

# Kanten mit Canny-Edge-Detection erkennen
edges = cv2.Canny(image, 50, 150)

# Bild und Kanten anzeigen
fig, axes = plt.subplots(1, 2, figsize=(12, 6))
axes[0].imshow(image, cmap='gray')
axes[0].set_title("Originalbild")
axes[0].axis("off")

axes[1].imshow(edges, cmap='gray')
axes[1].set_title("Kanten mit Canny-Edge-Detection")
axes[1].axis("off")

plt.show()
