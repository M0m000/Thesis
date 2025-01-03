from setuptools import setup

package_name = 'bt_pkg'

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
            'bt_example_tree = bt_pkg.bt_example_tree:main',
            'bt_scan_hookstrip = bt_pkg.bt_scan_hookstrip:main',
            'srv_call = bt_pkg.srv_call:main'
        ],
    },
)
