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
            'move_lin_by_key = robot_control.move_lin_by_key:main',
            'MoveTcpAlongAxis_action_client = robot_control.MoveTcpAlongAxis_action_client:main',
            'tf_frames_publisher = robot_control.tf_frames_publisher:main',
            'ibvs_2d = robot_control.ibvs_2d:main',
            'set_working_frame_qr = robot_control.set_working_frame_qr:main',
            'define_working_frame_needle = robot_control.define_working_frame_needle:main',
            'scan_bar = robot_control.scan_bar:main'
        ],
    },
)
