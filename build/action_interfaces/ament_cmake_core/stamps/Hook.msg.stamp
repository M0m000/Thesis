# Hook.msg
string name  # Name des Haken
BoundingBox hook_box
BoundingBox tip_box
BoundingBox lowpoint_box

sensor_msgs/Image hook_mask  # Masken für den Hook als Image
sensor_msgs/Image tip_mask   # Masken für den Tip als Image
sensor_msgs/Image lowpoint_mask  # Masken für den Lowpoint als Image
sensor_msgs/Image skeleton_mask  # Masken für das Skelett als Image

float32 conf_hook  # Konfidenz für Hook
float32 conf_tip   # Konfidenz für Tip
float32 conf_lowpoint  # Konfidenz für Lowpoint

UV uv_hook
UV uv_tip
UV uv_lowpoint

UV[] shortest_path
UV[] path_points