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
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'hello_node = robot_control.hello_node:main',
            'move_lin_by_key = robot_control.move_lin_by_key:main',
            'print_tcp_pose = robot_control.print_tcp_pose:main',
            'print_frames = robot_control.print_frames:main',
            'set_frame_client = robot_control.set_frame_client:main'
        ],
    },
)

