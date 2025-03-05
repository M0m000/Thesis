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
***
# Klonen des Repositorys
```bash
git clone https://github.com/M0m000/Thesis.git
```
>Klont das Repository in einen Ordner "Thesis" (wird automatisch im gewählten Verzeichnis erstellt) <br>
<br>


# ROS2 Inital Build
```bash
source /opt/ros/foxy/setup.bash
```
>Sourcen der ROS2-Umgebung (sonst kann Build nicht funktionieren) <br>

```bash
colcon build
```
>Build aller ROS2-Packages im Git. <br>

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
ros2 run vcnanoz vc_startup --ros-args -p shutter_time:=20000 -p gain:=50
```
>Dieser Knoten schaltet die Stromversorgung für VCnanoZ (DOut 1) ein und startet den ImgNet-Server auf der Kamera. Nachdem alles ausgeführt wurde, fährt sich der Knoten selbst runter. Die Kamera läuft weiter. <br>
<br>

### **VC Image Receiver** Node <br>
```bash
ros2 run vcnanoz vc_img_receiver --ros-args -p ipv4:="192.168.3.15" -p port:=2002 -p img_width:=1280 -p img_height:=720 -p rgb_stream:=False -p show_img:=False -p take_pitcures:=False
```
>Dieser Knoten stellt eine Verbindung zum Socket her und streamt das Graubild der Kamera (Auflösung einstellbar) auf dem Topic "/vcnanoz/stream/image_raw". Wenn das Argument "take_pitcures" auf True gesetzt ist. Kann mit der Taste z ein Bild aufgenommen und gespeichert werden, sobald der Stream läuft. Das Bildfenster von OpenCV muss dazu aktiv sein -> dort z druecken. Der Speicherpfad kann ebenfalls mit dem Argument "save_path" übergeben werden - standardmäßig auf '/home/vboxuser/Thesis/vc_imgs'. <br>
<br>

### **VC Two Image Receiver** Node <br>
```bash
ros2 run vcnanoz vc_img2_receiver --ros-args -p ipv4:="192.168.3.15" -p port:=2002 -p rgb_stream:=False -p show_img:=False -p take_pitcures:=False
```
>Dieser Knoten stellt eine Verbindung zu einer zweiten VC nano Kamera her. Die Bildauflösung wird automatisch an den ersten Knoten angepasst. Die Bilder werden über den Topic "/vcnanoz/stream/image_raw2" veröffentlicht. <br>
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

### **MoveTcpAlongAxis Action Server** Node <br>
```bash
ros2 run action_servers MoveTcpAlongAxis_action_server
```
>Dieser Knoten öffnet den Server für eine Action, die den TCP des Roboters entlang einer Achse (movement_axis) in einem definierten Koordinatensystem (movement_frame) linear bewegt. Die Distanz, die entlang der Achse zurückgelegt werden soll, wird mit dem Parameter Baseline übergeben. <br>
<br>

<br>

## **Robot Control Package**
Enthält alle Roboteransteuerungen - kommuniziert mit orange-ros2-Package von Kassow Robots. <br>
<br>

### **VC Vision Launch File** <br>
```bash
ros2 launch robot_control vc_vision_launch.py
```
>Launchfile für Hochfahren von VC Cam, Regelung Ringlicht, Starten von Img-Receiver und Yolo-Inferenz-Node. <br>
<br>

### **Scan Bar Launch File** <br>
```bash
ros2 launch robot_control scan_bar_launch.py
```
>Launchfile für Hochfahren von VC Cam, Regelung Ringlicht, Starten von Img-Receiver und Yolo-Inferenz-Node. Anschließend wird Scan-Prozess gestartet. <br>
<br>

### **Attachment Trajectory Controller** Node <br>
```bash
ros2 run robot_control attachment_control_trajectory --ros-args -p hook_num:=10 -p manual_mode:=True
```
>Enthält das Anfahren und genaue Positionieren (durch eine Regelung) an der Hakenspitze. Die Orientierung wird so ausgeregelt, dass die Lochebene des Bauteils senkrecht von der verlängerten Hakengerade durchstoßen wird. Somit kann ein ortogonales Einfädeln erfolgen. Nutzt die FC-trajectory-controller Funktion zur Regelung.<br>
<br>

### **Attachment Servoing Controller** Node <br>
```bash
ros2 run robot_control attachment_control_servoing --ros-args -p hook_num:=10 -p manual_mode:=True
```
>Enthält das Anfahren und genaue Positionieren (durch eine Regelung) an der Hakenspitze. Die Orientierung wird so ausgeregelt, dass die Lochebene des Bauteils senkrecht von der verlängerten Hakengerade durchstoßen wird. Somit kann ein ortogonales Einfädeln erfolgen. Nutzt die FC-trajectory-controller Funktion zur Regelung.<br>
<br>

### **Scan Bar Horizontal Triangulation** Node <br>
```bash
ros2 run robot_control scan_bar_horizontal_triangulation --ros-args -p do_vibration_test:=False -p speed_in_mm_per_s:=10.0 -p num_hooks_existing:=20
```
>Enthält den gesammten Scan-Mechanismus. Die Referenzierfahrt für das WORK-Frame muss hierzu beendet sein und der tf frame pulisher Node muss aktiv sein und die Frames inkl. WORLD publishen. Dieser Knoten führt den gesamten Scan-Mechanismus inklusive horizontaler Triangulation durch und liefert am Ende ein Dict, welches alle Hakeninstanzen mit WORK-Position und CAM-Position in realen Koordinaten XYZ enthält. <br>
<br>

### **Scan Bar Vertical Triangulation** Node <br>
```bash
ros2 run robot_control scan_bar_vertical_triangulation --ros-args -p do_vibration_test:=False -p speed_in_mm_per_s:=10.0 -p num_hooks_existing:=20
```
>Enthält den gesammten Scan-Mechanismus. Die Referenzierfahrt für das WORK-Frame muss hierzu beendet sein und der tf frame pulisher Node muss aktiv sein und die Frames inkl. WORLD publishen. Dieser Knoten führt den gesamten Scan-Mechanismus inklusive veritkaler Triangulation durch und liefert am Ende ein Dict, welches alle Hakeninstanzen mit WORK-Position und CAM-Position in realen Koordinaten XYZ enthält. <br>
<br>

### **Scan Bar Combined Triangulation** Node <br>
```bash
ros2 run robot_control scan_bar_combined_triangulation --ros-args -p do_vibration_test:=False -p speed_in_mm_per_s:=10.0 -p num_hooks_existing:=20
```
>Enthält den gesammten Scan-Mechanismus. Die Referenzierfahrt für das WORK-Frame muss hierzu beendet sein und der tf frame pulisher Node muss aktiv sein und die Frames inkl. WORLD publishen. Dieser Knoten führt den gesamten Scan-Mechanismus inklusive kombinierter Triangulation durch und liefert am Ende ein Dict, welches alle Hakeninstanzen mit WORK-Position und CAM-Position in realen Koordinaten XYZ enthält. <br>
<br>

### **Hook Data Listener** Node <br>
```bash
ros2 run robot_control hook_data_listener
```
>Node für Tests von Hooks-Dict Publishing (Yolo Output Dict).  <br>
<br>

### **Define Working Frame Needle** Node <br>
```bash
ros2 run robot_control define_working_frame_needle
```
>Zur Erstellung des Working-Frames - sitzt links oben im Rahmen des Gestells. Muss mit Hilfe der Nadel und der drei Fassungen am Gestell manuell durchgeführt werden. Dieser Knoten berechnet am Ende die Transformation von WORLD zu WORK und speichert diese als CSV. Der "tf frames publisher" Node greift wiederum auf diese CSV zu und publisht die Transform als tf2-Frame zur weiteren Verwendung. WICHTIG: Um dieses Frame zu verwenden, muss der tf frame publisher aktiv sein. <br>
<br>

### **Set Working Frame QR** Node <br>
```bash
ros2 run robot_control set_working_frame_qr
```
>Node zur Herstellung der Beziehung zwischen Roboter und Gestell. Roboter muss dazu vor QR-Plate platziert werden, sodass alle drei QR-Codes mittig im Bild mit ausreichend Abstand zu den Bildrändern sind. Dann Node starten und P drücken -> Roboter positioniert sich dann selbst rechtwinklig zur Plate und speichert das Frame, welches mittig im QR-Code links oben liegt als Arbeitsframe mit der ID 3. <br>
<br>

### **2D IBVS** Node <br>
```bash
ros2 run robot_control ibvs_2d --ros-args -p speed_factor:=0.1 -p target_point_in_px:=[640.0, 360.0] -p tolerance_in_px:=[5.0, 5.0] -p track_hooktip_num:=2 -p show_plot:=True
```
>Image Based Visual Servoing -> Regelung von x_tcp und y_tcp, bis Punkt Hakenspitze in angegebenem Target Punkt liegt -> Regelung auf Bildebene. <br>
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

## **Vision Package**
Enthält alle Programme zur Bildverarbeitung - Filterung, NNs... <br>
<br>

### **YoloV8 Inference Node**
```bash
ros2 run vision yolov8_inference --ros-args -p confidence_threshold:=0.4 -p do_preprocessing:=True -p do_postprocessing:=True -p show_cam_img:=False -p show_output_img:=True -p show_point_img:=True -p show_skeleton_img:=True
```
>Lädt ein vortrainiertes Instance Segmentation Model YoloV8 (Segmentiert das Bild nach Instanzen auf die Klassen "bar", "hook", "tip" und "lowpoint"). Training des Models kann mit Jupyter-Notebook in Verzeichnis YoloV8_InstanceSeg/yolov8.ipynb gemacht werden. Dieser Knoten subscribed den Kameratopic der VC-Cam und führt in Echtzeit die Inferenz der Bilder durch. Beide Bilder werden in extra Fenstern angezeigt. Mit dem confidence threshold kann festgelegt werden, wie sicher sich das Netz bei der Erkennung der Objekte sein muss -> je höher, umso strenger. Des Weiteren wird der Output direkt in Dictionaries verarbeiten. Jeder erkannte Haken erhält seinen eigenen Eintrag -> von rechts nach links durchnummeriert. Pro Haken gibt es die Maske des Hakens, der Spitze, der Senke und die Mittelpunkt dieser drei Masken. Des weiteren wird mit Hilfe von Skelettierung und anschleießendem A*-Planer der kürzeste Pfad zwischen Spitze und Senke mit 10 Punkten modelliert. Dieser Pfad liegt exakt in der Mitte des Hakens (berechnet mit Skelettierung aus Maske). Im Dict sind hieraus noch für jeden Haken die Einträge skeleton mask, shortest path und path points vorhanden. Path points sind dabei die 10 Punkte, die die Form von Spitze zu Senke modellieren und nachfolgend zur Tiefenrekonstruktion interpoliert werden können. <br>
<br>

### **YoloV8 Dual Cam Inference Node**
```bash
ros2 run vision yolov8_dualcam_inference --ros-args -p confidence_threshold:=0.4 -p do_preprocessing:=True -p do_postprocessing:=True -p show_cam_img:=False -p show_output_img:=True -p show_point_img:=True -p show_skeleton_img:=True
```
>Inferenz-Node mit Yolo-Architektur. Verarbeitet automatisch beide Bilder der beiden VC-Cams. Der Output ist ebenfalls ein Dict mit zusätzlichen Keys (uv_hook_img2, uv_tip_img2, uv_lowpoint_img2). Zudem werden hier direkt die realen 3D-Koordinaten durch Triangulation berechnet und unter den Keys (xyz_hook_in_camframe, xyz_tip_in_camframe, xyz_lowpoint_in_camframe) im Dict gespeichert. Das fertige Dict wird veröffentlicht. <br>
<br>

### **MaskRCNN Inference Node**
```bash
ros2 run vision maskrcnn_inference --ros-args -p maskrcnn_model_path:="/home/mo/MaskRCNN_InstanceSeg/maskrcnn_trained_model.pth" -p confidence_threshold:=0.4 -p do_preprocessing:=True -p do_postprocessing:=True -p show_cam_img:=True -p show_output_img:=True
```
>Lädt ein vortrainiertes Instance Segmentation Model MaskRCNN (Segmentiert das Bild nach Instanzen auf die Klassen "bar", "hook", "tip" und "lowpoint"). Training des Models kann mit Jupyter-Notebook in Verzeichnis MaskRCNN_InstanceSeg/maskrcnn.ipynb gemacht werden. Dieser Knoten subscribed den Kameratopic der VC-Cam und führt in Echtzeit die Inferenz der Bilder durch. Beide Bilder werden in extra Fenstern angezeigt. Mit dem confidence threshold kann festgelegt werden, wie sicher sich das Netz bei der Erkennung der Objekte sein muss -> je höher, umso strenger. <br>
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

***
***
### Links zu Repositories orange-ros2 (Kassow) und RealSense <br>

**orange-ros2 (Kassow)** <br>
https://gitlab.com/kassowrobots/orange-ros2 <br>
<br>

**RealSense** <br>
https://github.com/IntelRealSense/realsense-ros <br>
<br>
