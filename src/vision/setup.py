from setuptools import setup

package_name = 'vision'

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
            'image_receiver = vision.image_receiver:main',
            'point_finder_2d = vision.point_finder_2d:main',
            'point_finder_3d = vision.point_finder_3d:main',
            'test_node = vision.test_node:main',
            'calibration = vision.calibration:main',
            'stereo_triangulation = vision.stereo_triangulation:main',
            'image_filters = vision.img_filters:main',
            'stereo_triangulation_with_robot = vision.stereo_triangulation_with_robot:main'
        ],
    },
)
