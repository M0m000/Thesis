from setuptools import setup
from glob import glob

package_name = 'vision'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (f'share/{package_name}/msg', glob('msg/*.msg')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mo',
    maintainer_email='mo@todo.todo',
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
            'stereo_triangulation_with_robot = vision.stereo_triangulation_with_robot:main',
            'hook_detector = vision.hook_detector:main',
            'yolov8_inference = vision.yolov8_inference:main',
            'maskrcnn_inference = vision.maskrcnn_inference:main',
            'nn_output_processor = vision.nn_output_processor:main',
        ],
    },
)
