# **Masterthesis Repo** <br>
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
# ROS2-Befehle

<br>

## **Sensopart Visor Package**
Package zum Hoch- bzw. Herunterfahren von SensoPart VISOR V20 <br>
<br>

### **Visor Startup** Node <br>
```bash
ros2 run sensopart_visor visor_startup
```
>Dieser Knoten schaltet die Stromversorgung für SensoPart VISOR (DOut 2) ein. <br>
<br>

### **Visor Shutdown** Node <br>
```bash
ros2 run sensopart_visor visor_shutdown
```
>Dieser Knoten schaltet die Stromversorgung für SensoPart VISOR (DOut 2) aus. <br>
<br>

<br>

## **VCnanoZ Package**
Package zum Verbindungsaufbau mit VCnanoZ Kamera. Auf Kamera muss "vcimgnetsrv &" sowie "vctp" ausgeführt werden, dass der Stream aktiv ist - wird von Startup-Node gemacht. <br>
Verbindung zu Kamera über SSH "ssh root@192.168.3.15" <br>
<br>

### **VC Startup** Node <br>
```bash
ros2 run vcnanoz vc_startup
```
>Dieser Knoten schaltet die Stromversorgung für VCnanoZ (DOut 1) ein und startet den ImgNet-Server auf der Kamera. Nachdem alles ausgeführt wurde, fährt sich der Knoten selbst runter. Die Kamera läuft weiter. <br>
<br>

### **VC Image Receiver** Node <br>
```bash
ros2 run vcnanoz vc_img_receiver --ros-args -p ipv4:="192.168.3.15" -p port:=2002 -p img_width:=1280 -p img_height:=720 -p rgb_stream:=False -p show_img:=True
```
>Dieser Knoten stellt eine Verbindung zum Socket her und streamt das Graubild der Kamera (Auflösung einstellbar) auf dem Topic "/vcnanoz/stream/image_raw". <br>
<br>

### **VC Shutdown** Node <br>
```bash
ros2 run vcnanoz vc_shutdown
```
>Dieser Knoten stellt eine SSH-Verbindung zur VCnanoZ her und fährt sie runter. Danach wird die Stromversorgung unterbrochen (DOut 1 FALSE). <br>
<br>

<br>

## **Action Interface Package**
Enthält alle Interfaces (Action-Types) für selbst geschriebene Actions - keine weiteren Aufrufe notwendig! <br>
<br>

## **Action Server Package**
Enthält alle Server für selbst geschriebene Actions - müssen gestartet werden, damit Action an deren Stellen für Clients verfügbar. <br>
<br>

### **Fibonacci Action Server** Node <br>
```bash
ros2 run action_servers fibonacci_action_server
```
>Dieser Knoten öffnet den Server für eine Test Action - hier wird beispielhaft eine Fibonacci-Folge berechnet. <br>
<br>

### **MoveTcpAlongAxis Action Server** Node <br>
```bash
ros2 run action_servers MoveTcpAlongAxis_action_server
```
>Dieser Knoten öffnet den Server für eine Action, die den TCP des Roboters entlang einer Achse (movement_axis) in einem definierten Koordinatensystem (movement_frame) linear bewegt. Die Distanz, die entlang der Achse zurückgelegt werden soll, wird mit dem Parameter Baseline übergeben. <br>
<br>

<br>

## **Behavior Tree Package**
Enthält alle Behavior Trees (Ablaufsteuerungen) als Nodes geschrieben - Kommunikation mit allen anderen Topics/Nodes/etc. möglich. <br>
<br>

### **Example Tree** Node <br>
```bash
ros2 run bt_pkg bt_example_tree
```
>Dieser Knoten erstellt einen Test-Behavior-Tree. Dabei gibt es drei Knoten. Der erste wartet auf die Eingabe der Taste 1. Der zweite wartet auf die Eingabe der Taste 2, startet dann einen Timer von 20sec und ist nach Ablauf der Zeit beednet. Der dritte Knoten wartet dann auf die Eingabe der Taste 3 und beendet den Behavior Tree. <br>
<br>

<br>

## **Robot Control Package**
Enthält alle Roboteransteuerungen - kommuniziert mit orange-ros2-Package von Kassow Robots. <br>
<br>

### **Test** Node <br>
```bash
ros2 run robot_control hello_node
```
>Dieser Knoten stellt nur eine Testverbindung zum Roboter her und gibt (wenn Verbindung erfolgreich) ein paar Statusmeldungen in der ROS-Konsole aus. <br>
<br>

### **Move Linear By Key** <br>
```bash
ros2 run robot_control move_lin_by_key --ros-args -p speed:=50.0 -p movoement_frame:='tcp'
```
>Dieser Knoten dient zur Steuerung des Roboter über Tasten. Die Geschwindigkeit in mm/s kann als Argument beim Start übergeben werden. Das Frame, in dem verfahren werden soll, kann beim Aufruf des Nodes angegeben werden - world, base oder tcp. Der TCP wird linear verfahren, wenn eine der folgenden Tasten gedrückt ist: <br>
<br>
>Taste L -> +X_tcp <br>
>Taste J -> -X_tcp <br>
>Taste I -> Z_tcp <br>
>Taste K -> -Z_tcp <br>
>Taste O -> Y_tcp <br>
>Taste N -> -Y_tcp <br>
<br>

### **Print TCP Pose** <br>
```bash
ros2 run robot_control print_tcp_pose
```
>Gibt die aktuelle Pose des TCP (Translation und Rotation) in Referenz WORLD in der Konsole aus. <br>
<br>

### **Print Frames** <br>
```bash
ros2 run robot_control print_tcp_pose --ros-args -p desired_frame:='tcp' -p reference_frame:='world'
```
>Gibt die Pose eines gewählten Koordinatensystems in gewähltem Referenz-Frame aus <br>
<br>

### **Set Frame Client** <br>
```bash
ros2 run robot_control set_frame_client --ros-args -p ref:=3 -p pos="[0.0, 0.0, 0.0]" -p rot="[0.0, 0.0, 0.0]"
```
>Dient zur Anlegung von benutzerdefinierten Frames - benannt über REF. Diese Systeme müssen im WORLD-System definiert werden. <br>
<br>

### **Transformation Snapshot** <br>
```bash
ros2 run robot_control transformation_snapshot --ros-args -p desired_frame:='tcp' -p reference_frame:='world'
```
>Kann später zur Berechnung der Baseline bei Stereo Triangulation verwendet werden. Dient zur Erfassung von Differenzen in Translation und Rotation zwischen zwei Aufnahmepunkten. Mit Taste S kann Snapshot gestartet werden und nach Verfahren des Roboters mit Taste D beendet werden. Differenzen-Vektor wird dann über Topic /robot_control/transformation_snapshot gepublisht. Welches Koordinatensystem erfasst werden soll, kann über desired_frame und reference_frame bei Aufruf des Knotens festgelegt werden. <br>
<br>

### **Read Transformation Snapshot** <br>
```bash
ros2 run robot_control read_transformation_snapshot
```
>Empfängt den Differenz-Vektor von Transformation Snapshot und gibt diesen in der ROS-Konsole aus - für Testzwecke.<br>
<br>

### **Transformation Delta** <br>
```bash
ros2 run robot_control transformation_delta --ros-args -p desired_frame:='tcp' -p reference_frame:='world'
```
>Kann später zur Berechnung der Baseline bei Stereo Triangulation verwendet werden. Macht prinzipiell das Gleiche, wie Transformation Snapshot lediglich ohne Endbedingung. Es wird permament die Differenz der Pose zwischen der Startpunkte (zum Zeitpunkt, wenn Taste s gedrückt wird bzw. wenn über Topic /robot_control/transformation_delta_trigger eine Flanke auf TRUE gepublisht wird) berechnet und über den Topic /robot_control/transformation_delta gepublisht. Welches Koordinatensystem erfasst werden soll, kann über desired_frame und reference_frame bei Aufruf des Knotens festgelegt werden. <br>
<br>

### **Read Transformation Delta** <br>
```bash
ros2 run robot_control read_transformation_delta
```
>vgl. Read Transformation Snapshot - für Testzwecke.<br>
<br>

### **Fibonacci Action Client** Node <br>
```bash
ros2 run robot_control fibonacci_action_client
```
>Dieser Knoten öffnet einen Client auf die Fibonacci-Action (Beispielprogramm) - ACHTUNG: Server unter Package action_servers (siehe oben) muss aktiviert sein! <br>
<br>

### **MoveTcpAlongAxis Action Client** Node <br>
```bash
ros2 run robot_control MoveTcpAlongAxis_action_client --ros-args -p baseline:=30.0 -p movement_axis:="axis_x" -p movement_frame:="tcp" -p speed:=30.0
```
>Client für die Action MoveTcpAlongAxis (siehe oben bei Package action_servers). <br>
<br>

### **tf2 Frames Publisher** Node <br>
```bash
ros2 run robot_control tf_frames_publisher
```
>Liest die Frames von Kassow bezogen auf WORLD aus und publisht sie als tf2-Frames. In gesamter ROS-Infrastruktur kann dann tf2-Bibliothek genutzt werden für Koordinatentransformationen und Berechnungen. <br>
<br>

### **tf2 Transformation Testnode** Node <br>
```bash
ros2 run robot_control tcp_frame_listener
```
>Test Node für Berechnung von Koordinatentransformationen aus tf2 Frames heraus. <br>
<br>

<br>

## **Intel RealSense Package**
Standardpaket von Intel RealSense - aktiviert den Kamerasystem und enthält einstellbare Parameter. <br>
<br>

### **Realsense Depth Align Camera Stream** <br>
```bash
ros2 launch realsense2_camera rs_align_depth_launch.py
```
>Startet den Kamerastream mit Tiefeninformation. <br>
<br>

### **Realsense RGB Camera Stream** <br>
```bash
ros2 launch realsense2_camera rs_launch.py align_depth.enable:=false
```
>Startet den Kamerastream ohne Tiefeninformation. <br>
<br>

<br>

## **Vision Package**
Enthält alle Programme zur Bildverarbeitung - Filterung, NNs... <br>
<br>

### **Image Receiver** <br>
```bash
ros2 run vision image_receiver --ros-args -p show_img:=False -p max_depth:=40
```
>Extrahiert den Kamerastream und publisht die Bilder über Topics. Hier kann bereits maximale Tiefe eingestellt werden -> Punkte, die weiter weg liegen, werden dann aus den Bildern entfernt. Weitere Filter, wie RANSAC zum Finden von Konturen werden hier ebenfalls schon getestet. <br>
<br>

### **Calibration** Tool <br>
```bash
ros2 run vision calibration --ros-args -p show_img:=True -p threshold:=40 -p point_distance_in_mm:=92.0
```
>Startet den Kalibrierungsknoten. Hierzu muss das Kalibrierblatt exakt horizontal in einem festen Abstand zur Kamera aufgehangen werden. Die Punktdistanz zwischen den drei Referenzpunkten des Kalibrierblatts muss beim Knotenaufruf übergeben werden. Es ist darauf zu achten, dass die Kamera orthogonal auf das Kalibrierblatt ausgerichtet ist. Das Kalibrierblatt muss ich einer senkrechten Tiefenebene befinden (alle drei Punkten sollten möglichst den gleichen Tiefenwert haben). In den Ausgabefesntern sind dann die intrinsischen Kameraparameter Brennweite fx und fy zu sehen. Diese können dann beispielsweise im Knoten Point_Finder_3D verwendet werden, um die reale Position der Punkte vom Kamerasystem aus gesehen zu berechnen. <br>
<br>

### **Point Finder 3D** <br>
```bash
ros2 run vision point_finder_3d --ros-args -p show_img:=True -p threshold:=40
```
>Dieser Knoten dient zur Berechnung von Punktkoordinaten in der realen Welt. Es detektiert schwarze Punkte im Bild (über Threshold einstellbar, wie dunkel diese Punkte sein müssen) und berechnet mit Hilfe der intrinsischen Kameraparameter die Punktkoordinaten aus dem Kamerasystem aus gesehen. Die Mittelpunktkoordinaten der schwarzen Blobs wird mit Hilfe von Canny-Konturerkennnung und Berechnung über Momente bestimmt. <br>
<br>

### **Point Finder 2D** <br>
```bash
ros2 run vision point_finder_2d --ros-args -p show_img:=True
```
>Finden von schwarzn Punkten (einstellbar über Threshold) in der Bildebene in einem 2D-Bild über OpenCV Canny und Momente. <br>
<br>

### **Stereo Triangulation** <br>
```bash
ros2 run vision stereo_triangulation
```
>Dient als Knoten für Stereo-Triangulation in einer horizontalen Baseline. Es ist jedoch bisher nur die erste Kamera integriert... <br>
<br>

### **Image Filters** <br>
```bash
ros2 run vision image_filters --ros-args -p show_img:=True -p use_sobel:=True
```
>Startet einen Knoten zum Testen von Filterfunktionen aus OpenCV. Momentan ist Canny und Vergleich von Referenzkonturen implementiert. <br>
<br>

### **Hook Detector** <br>
```bash
ros2 run vision hook_detector
```
>Startet einen Knoten zur Erkennung der Haken mit Hilfe von klassischer Bildverarbeitung (Gaussfilter, Kantenerkennung, etc.) <br>
<br>



***
***
### Links zu Repositories orange-ros2 (Kassow) und RealSense <br>

**orange-ros2 (Kassow)** <br>
https://gitlab.com/kassowrobots/orange-ros2 <br>
<br>

**RealSense** <br>
https://github.com/IntelRealSense/realsense-ros <br>
<br>
