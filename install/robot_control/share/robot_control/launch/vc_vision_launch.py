import os
import launch
import launch_ros.actions
from ament_index_python.packages import get_package_share_directory
from launch.actions import RegisterEventHandler, TimerAction
from launch.event_handlers import OnProcessExit



def generate_launch_description():
    # Pfad zur YAML-Parameterdatei
    config_path = os.path.join(get_package_share_directory('robot_control'), 'config', 'vc_params.yaml')

    # Definition des ersten Nodes (vc_startup)
    vc_startup_node = launch_ros.actions.Node(
        package = 'vcnanoz',
        executable = 'vc_startup',
        name = 'vc_startup_node',
        parameters = [config_path],
        output = 'screen'
    )

    # Definition des zweiten Nodes (vc_img_receiver), aber noch nicht direkt gestartet
    vc_img_receiver_node = launch_ros.actions.Node(
        package = 'vcnanoz',
        executable = 'vc_img_receiver',
        name = 'vc_img_receiver_node',
        parameters = [config_path],
        output = 'screen'
    )

    # Definition YoloV8 Inference Node
    yolov8_inference_node = launch_ros.actions.Node(
        package = 'vision',
        executable = 'yolov8_inference',
        name = 'yolov8_inference_node',
        parameters = [config_path],
        output = 'screen'

    )

    return launch.LaunchDescription([
        vc_startup_node,
        
        # Receiver und YoloV8 Nodes starten 1min später
        TimerAction(
            period=60.0,
            actions=[vc_img_receiver_node, yolov8_inference_node]
        ),
    ])
