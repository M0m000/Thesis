# **Masterthesis Repo** <br>
***
### *Konzeption und Implementierung eines kameragestützten Robotersystems zur vollautomatisierten Aufhängung von Strukturbauteilen für Kathodische Tauchlackierungen* <br>
<br>

<p align="center">
  <img src="/imgs/1.png" alt="Abb. 1 - Kathodische Tauchlackierung" width="400"/>
</p>
<p align="center"><em>Abb. 1 - Kathodische Tauchlackierung</em></p>

<br>

Die Kathodische Tauchlackierung (Abb. 1) ist ein in der Industrie bekannter elektrochemischer Prozess zur Lackierung von komplizierten Strukturen in großen Stückzahlen. Zu Beginn des Prozesses werden die zu lackierenden Teile dabei an einer Gitterstruktur (Abb. 2) aufgehängt. Dies geschieht zum jetzigen Zeitpunkt ausschließlich von Hand und stellt einen für den Menschen monotonen Bewegungsablauf dar. Zur Entlastung soll dieser Vorgang durch einen Roboterarm realisiert werden, welcher sowohl das Aufnehmen der Teile aus einer Kiste als auch das korrekte Platzieren an den Vorrichtungen übernimmt. Die hier beschriebene Aufgabenstellung lässt sich dabei prinzipiell auch auf andere Beschichtungsverfahren, wie Sprühlackierungen oder Pulverbeschichtungen übertragen. <br>
<br>

Während das Aufnehmen eines Teils aus einer Kiste mit bereits bekannten Bin-Picking-Lösungen realisiert werden kann, stellt die Vermessung des Gitters und das anschließende Aufhängen aufgrund der hohen Varianz an Teilen und Vorrichtungen eine Herausforderung dar. <br>
<br>

<p align="center">
  <img src="/imgs/2.png" alt="Abb 2 - Gitteranordnung" width="400"/>
</p>
<p align="center"><em>Abb. 2 - Gitteranordnung</em></p>


<br>

Wie in Abb. 2 zu sehen, befinden sich an einem Gitter mehrere feste Haken, an denen die Teile aufgehängt werden sollen. Durch Verschleiß und mechanische Beanspruchung entstehen hier Verbiegungen oder weitergehende Beschädigungen durch abgebrochene Haken oder Ösen. Die Vorrichtungen können daher nicht als identisch angesehen werden. Sie weisen darüber hinaus Fertigungstoleranzen auf und können wegen ihres mechanischen Aufbaus nicht hinreichend exakt platziert werden. Da möglichst viele Vorrichtungen trotzdem verwendet werden sollen, scheidet eine Steuerung des Roboters mit festen Koordinaten aus. Abb. 3 gibt einen ersten Überblick über mögliche Fehlstellungen und Abweichungen der Vorrichtungen. <br>
<br>

<p align="center">
  <img src="/imgs/3.png" alt="Mögliche Abweichungen an Aufhängevorrichtungen" width="600"/>
</p>
<p align="center"><em>Abb. 3 - Mögliche Abweichungen an Aufhängevorrichtungen</em></p>

<br>

Mit Hilfe geeigneter Sensoren und entsprechender Datenverarbeitung sollen diese Fehlstellungen ermittelt werden, sodass ein erfolgreiches Aufhängen des Teils am Haken durch den Roboterarm möglich ist. Die Art der Sensorik und das Konzept zur Vermessung der Vorrichtung und der Repräsentation auf Koordinatenebene soll im Rahmen der Thesis erarbeitet werden und stellt den Kern der Aufgabenstellung dar. Denkbar wäre beispielsweise die Verwendung von Tiefenkameras, um ein dreidimensionales Bild der Vorrichtung aufnehmen zu können. Auf Basis dieses Bildes kann nach weiterer Verarbeitung schlussendlich die Trajektorie für ein geeignetes Anfahren der Vorrichtung gebildet werden. <br>
<br>

Weiterhin stellen das Einfädeln und Aufhängen der Teile eine Herausforderung dar. Auch für diesen Teil des Prozesses sollen geeignete Sensoren gewählt und ein sinnvolles Verfahren zur Ansteuerung bzw. Regelung des Roboterarms entwickelt werden. Eine mehrdimensionale Messung der Kräfte am TCP kann hier dazu beitragen, das Einfädeln des Teils am Gitter zu optimieren und den Roboter auf Basis dieser Kräftewerte zu regeln. Abschließend soll kontrolliert werden, ob das Teil sicher in der Vorrichtung eingehängt wurde. <br>
<br>

Ebenfalls zu berücksichtigen ist die Vorbereitung der Teile, nachdem der Griff in die Kiste erfolgt ist. Hier stellt sich die Frage nach einem geeigneten Handling zur Vorbereitung der Teile. Dies könnte eine Zentrierung, Arretierung und ein erneutes optimiertes Greifen umfassen, bevor der eigentliche Vorgang des Aufhängens starten kann. <br>
<br>

Als Roboter kommt ein kollaborativer siebenachsiger Roboterarm des Herstellers Kassow Robots (Abbildung 4) zum Einsatz. Die für die Anwendung notwendigen Algorithmen zur Verarbeitung der Sensordaten, eventuellen Regelungen und Ansteuerungen des Roboterarms sollen in einer ROS2-Umgebung integriert werden. <br>
<br>

<p align="center">
  <img src="/imgs/4.png" alt="Kassow Robots KR810 (7 Achsen)" width="400"/>
</p>
<p align="center"><em>Abb. 4 - Kassow Robots KR810 (7 Achsen)</em></p>

<br>
<br>

### **Folgende inhaltliche Anforderungen sind im Rahmen der Thesis zu erfüllen:** <br>
-	Analyse zu möglichen Fehlerfällen an den Vorrichtungen und dem damit erforderlichen Umgang im Kontext der Anwendung <br>
-	Recherchen zu möglichen Ansätzen für die Vermessung der Vorrichtungen inklusive erforderlicher Sensorik <br>
-	Finden von geeigneten Methoden zur Weiterverarbeitung der Sensorwerte mit dem Ziel, die vermessene Vorrichtung auf Koordinatenebene repräsentieren zu können, sodass anschließend eine Planung der Robotertrajektorie erfolgen kann. (Bspw. Bildverarbeitung, Machine Learning, …) <br>
-	Planung einer Robotertrajektorie von Aufnahme des Teils bis zur Vorrichtung, an der das Teil eingehängt werden soll <br>
-	Erarbeiten einer Strategie für das Einhängen der Teile an den Vorrichtungen <br>
-	Erarbeiten einer sinnvollen Möglichkeit zur abschließenden Kontrolle des Aufhängvorgangs <br>
-	Konzept für das Handling von Teilen mit verschiedenen Formen anschließend an das Bin-Picking, sodass der Aufhängvorgang starten kann <br>
-	Testen und Optimieren der Konzepte in einem praktischen Aufbau <br>
-	Bewertung und Evaluierung in Bezug auf das Ziel der Aufgabenstellung <br>

<br>
<br>
<br>

***
## **Robot Control Package**
### Start **Test** Node (Robot Control Package) in ROS2 <br>
```bash
ros2 run robot_control hello_node
```
>Dieser Knoten stellt nur eine Testverbindung zum Roboter her und gibt (wenn Verbindung erfolgreich) ein paar Statusmeldungen in der ROS-Konsole aus. <br>
<br>


### Start **Move Linear By Key** Node (Robot Control Package) in ROS2 <br>
```bash
ros2 run robot_control move_lin_by_key --ros-args -p speed:=50.0
```
>Dieser Knoten dient zur Steuerung des Roboter über Tasten. Die Geschwindigkeit in mm/s kann als Argument beim Start übergeben werden. Der TCP wird linear verfahren, wenn eine der folgenden Tasten gedrückt ist: <br>
<br>
>Taste L -> +X_tcp <br>
>Taste J -> -X_tcp <br>
Taste I -> Z_tcp <br>
Taste K -> -Z_tcp <br>
Taste O -> Y_tcp <br>
Taste N -> -Y_tcp <br>
<br>


### Start **Print TCP Pose** Node (Robot Control Package) in ROS2 <br>
```bash
ros2 run robot_control print_tcp_pose
```
>Gibt die aktuelle Pose des TCP (Translation und Rotation) in Referenz WORLD in der Konsole aus. <br>
<br>


### Start **Print Frames** Node (Robot Control Package) in ROS2 <br>
```bash
ros2 run robot_control print_tcp_pose --ros-args -p desired_frame:='tcp' -p reference_frame:='world
```
>Gibt die Pose eines gewählten Koordinatensystems in gewähltem Referenz-Frame aus <br>
<br>

### Start **Set Frame Client** Node (Robot Control Package) in ROS2 <br>
```bash
ros2 run robot_control set_frame_client --ros-args -p ref:=3 -p pos="[0.0, 0.0, 0.0]" -p rot="[0.0, 0.0, 0.0]"
```
>Dient zur Anlegung von benutzerdefinierten Frames - benannt über REF. Diese Systeme müssen im WORLD-System definiert werden. <br>
<br>

## **RealSense Package**
### Start **Realsense Depth Align** Node (RealSense Package) in ROS2 <br>
```bash
ros2 launch realsense2_camera rs_align_depth_launch.py
```
>Startet den Kamerastream mit Tiefeninformation. <br>
<br>

## **Vision Package**
### Start **Image Receiver** (Vision Package) in ROS2 <br>
```bash
ros2 run vision image_receiver --ros-args -p show_img:=False -p max_depth:=40
```
>Extrahiert den Kamerastream und publisht die Bilder über Topics. Hier kann bereits maximale Tiefe eingestellt werden -> Punkte, die weiter weg liegen, werden dann aus den Bildern entfernt. Weitere Filter, wie RANSAC zum Finden von Konturen werden hier ebenfalls schon getestet. <br>
<br>

### Start **Calibration** Tool (Vision Package) in ROS2 <br>
```bash
ros2 run vision calibration --ros-args -p show_img:=True -p threshold:=40 -p point_distance_in_mm:=92.0
```
>Startet den Kalibrierungsknoten. Hierzu muss das Kalibrierblatt exakt horizontal in einem festen Abstand zur Kamera aufgehangen werden. Die Punktdistanz zwischen den drei Referenzpunkten des Kalibrierblatts muss beim Knotenaufruf übergeben werden. Es ist darauf zu achten, dass die Kamera orthogonal auf das Kalibrierblatt ausgerichtet ist. Das Kalibrierblatt muss ich einer senkrechten Tiefenebene befinden (alle drei Punkten sollten möglichst den gleichen Tiefenwert haben). In den Ausgabefesntern sind dann die intrinsischen Kameraparameter Brennweite fx und fy zu sehen. Diese können dann beispielsweise im Knoten Point_Finder_3D verwendet werden, um die reale Position der Punkte vom Kamerasystem aus gesehen zu berechnen. <br>
<br>

### Start **Point Finder 3D** (Vision Package) in ROS2 <br>
```bash
ros2 run vision point_finder_3d --ros-args -p show_img:=True -p threshold:=40
```
>Dieser Knoten dient zur Berechnung von Punktkoordinaten in der realen Welt. Es detektiert schwarze Punkte im Bild (über Threshold einstellbar, wie dunkel diese Punkte sein müssen) und berechnet mit Hilfe der intrinsischen Kameraparameter die Punktkoordinaten aus dem Kamerasystem aus gesehen. Die Mittelpunktkoordinaten der schwarzen Blobs wird mit Hilfe von Canny-Konturerkennnung und Berechnung über Momente bestimmt. <br>
<br>

### Start **Point Finder 2D** (Vision Package) in ROS2 <br>
```bash
ros2 run vision point_finder_2d --ros-args -p show_img:=True
```
>Finden von schwarzn Punkten (einstellbar über Threshold) in der Bildebene in einem 2D-Bild über OpenCV Canny und Momente. <br>
<br>

### Start **Stereo Triangulation** (Vision Package) in ROS2 <br>
```bash
ros2 run vision stereo_triangulation
```
>Dient als Knoten für Stereo-Triangulation in einer horizontalen Baseline. Es ist jedoch bisher nur die erste Kamera integriert... <br>
<br>

### Start **Image Filter** Node (Vision Package) in ROS2 <br>
```bash
ros2 run vision image_filters --ros-args -p show_img:=True -p use_sobel:=True
```
>Startet einen Knoten zum Testen von Filterfunktionen aus OpenCV. Momentan ist Canny und Vergleich von Referenzkonturen implementiert. <br>
<br>
