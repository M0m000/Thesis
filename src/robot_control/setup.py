from setuptools import setup

package_name = 'robot_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name, 'FC'],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/vc_vision_launch.py']),
        ('share/' + package_name + '/launch', ['launch/vc_vision_dualcam_launch.py']),
        ('share/' + package_name + '/launch', ['launch/scan_bar_launch.py']),
        ('share/' + package_name + '/launch', ['launch/robot_launch.py']),
        ('share/' + package_name + '/launch', ['launch/test_7dof.launch.py']),
        ('share/' + package_name + '/config', ['config/vc_params.yaml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='vboxuser',
    maintainer_email='vboxuser@todo.todo',
    keywords=['ROS'],
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python',
        'Topic :: Software Development',
    ],
    description='TODO: Package description',
    license='TODO: License declaration',
    entry_points={
        'console_scripts': [
            'MoveTcpAlongAxis_action_client = robot_control.MoveTcpAlongAxis_action_client:main',
            'tf_frames_publisher = robot_control.tf_frames_publisher:main',
            'ibvs_2d = robot_control.ibvs_2d:main',
            'set_working_frame_qr = robot_control.set_working_frame_qr:main',
            'define_working_frame_needle = robot_control.define_working_frame_needle:main',
            'scan_bar_horizontal_triangulation = robot_control.scan_bar_horizontal_triangulation:main',
            'scan_bar_vertical_triangulation = robot_control.scan_bar_vertical_triangulation:main',
            'scan_bar_combined_triangulation = robot_control.scan_bar_combined_triangulation:main',
            'scan_bar = robot_control.scan_bar:main',
            'hook_data_listener = robot_control.hook_data_listener:main',
            'attachment_control_trajectory = robot_control.attachment_control_trajectory:main',
            'attachment_control_servoing = robot_control.attachment_control_servoing:main',
            'scan_bar_horizontal_triangulation_pxmm = robot_control.scan_bar_horizontal_triangulation_pxmm:main',
            'ptp_movement_node = robot_control.ptp_movement_node:main',
            'ik_solver_node = robot_control.ik_solver_node:main',
            'seven_dof_ik_node = robot_control.seven_dof_ik_node:main',
            'ik_example_node = robot_control.ik_example_node:main',
            'tcp_calibration = robot_control.tcp_calibration:main'
        ],
    },
)
