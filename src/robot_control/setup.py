from setuptools import setup

package_name = 'robot_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'hello_node = robot_control.hello_node:main',
            'move_lin_by_key = robot_control.move_lin_by_key:main',
            'print_tcp_pose = robot_control.print_tcp_pose:main',
            'print_frames = robot_control.print_frames:main',
            'set_frame_client = robot_control.set_frame_client:main',
            'transformation_snapshot = robot_control.transformation_snapshot:main',
            'read_transformation_snapshot = robot_control.read_transformation_snapshot:main',
            'transformation_delta = robot_control.transformation_delta:main',
            'read_transformation_delta = robot_control.read_transformation_delta:main',
            'fibonacci_action_client = robot_control.fibonacci_action_client:main',
            'MoveTcpAlongAxis_action_client = robot_control.MoveTcpAlongAxis_action_client:main',
            'robot_TcpPose_node = robot_control.robot_TcpPose_node:main',
            'move_along_baseline_client = robot_control.move_along_baseline_client:main',
            'get_robot_pose_node = robot_control.get_robot_pose_node:main',
            'tf_frames_publisher = robot_control.tf_frames_publisher:main',
            'tf_test_transformation = robot_control.tf_test_transformation:main'
        ],
    },
)
