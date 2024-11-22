# **Masterthesis Repo**

## **Robot Control Package**
### Start **Test** Node (Robot Control Package) in ROS2 <br>
```ros2 run robot_control hello_node``` <br>
<br>
### Start **Move Linear By Key** Node (Robot Control Package) in ROS2 <br>
```ros2 run robot_control move_lin_by_key --ros-args -p speed:=50.0``` <br>
<br>
### Start **Print TCP Pose** Node (Robot Control Package) in ROS2 <br>
```ros2 run robot_control print_tcp_pose``` <br>
<br>
### Start **Print Frames** Node (Robot Control Package) in ROS2 <br>
```ros2 run robot_control print_tcp_pose --ros-args -p desired_frame:='tcp' -p reference_frame:='world``` <br>
<br>
### Start **Set Frame Client** Node (Robot Control Package) in ROS2 <br>
```ros2 run robot_control set_frame_client --ros-args -p ref:=3 -p pos="[0.0, 0.0, 0.0]" -p rot="[0.0, 0.0, 0.0]"``` <br>
<br>

## **RealSense Package**
### Start **Realsense Depth Align** Node (RealSense Package) in ROS2 <br>
```ros2 launch realsense2_camera rs_align_depth_launch.py``` <br>
<br>

## **Vision Package**
### Start **Image Receiver** (Vision Package) in ROS2 <br>
```ros2 run vision image_receiver --ros-args -p show_img:=False -p max_depth:=40``` <br>
<br>
### Start **Calibration** Tool (Vision Package) in ROS2 <br>
```ros2 run vision calibration --ros-args -p show_img:=True -p threshold:=40 -p point_distance_in_mm:=92.0``` <br>
<br>
### Start **Point Finder 3D** (Vision Package) in ROS2 <br>
```ros2 run vision point_finder_3d --ros-args -p show_img:=True -p threshold:=40``` <br>
<br>
### Start **Point Finder 2D** (Vision Package) in ROS2 <br>
```ros2 run vision point_finder_2d --ros-args -p show_img:=True``` <br>
<br>
### Start **Stereo Triangulation** (Vision Package) in ROS2 <br>
```ros2 run vision stereo_triangulation``` <br>
<br>
### Start **Image Filter** Node (Vision Package) in ROS2 <br>
```ros2 run vision image_filters --ros-args -p show_img:=True -p use_sobel:=True``` <br>
<br>
