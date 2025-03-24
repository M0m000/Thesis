from setuptools import setup

package_name = 'vcnanoz'

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
    entry_points={
        'console_scripts': [
            'vc_img_receiver = vcnanoz.vc_img_receiver:main',
            'vc_startup = vcnanoz.vc_startup:main',
            'vc_shutdown = vcnanoz.vc_shutdown:main',
            'srvServer_vc_startup = vcnanoz.srvServer_vc_startup.py:main',
            'srvClient_vc_startup = vcnanoz.srvClient_vc_startup.py:main',
            'vc_img2_receiver = vcnanoz.vc_img2_receiver:main'
        ],
    },
)
