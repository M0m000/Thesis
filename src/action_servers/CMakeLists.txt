cmake_minimum_required(VERSION 3.5)
project(action_servers)

# Finde Abhängigkeiten
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(kr_msgs REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(action_interfaces REQUIRED)

ament_target_dependencies(target_name action_interfaces)

# Installiere Python-Module
install(
  DIRECTORY src/robot_control/
  DESTINATION lib/python${PYTHON_VERSION}/site-packages
)

ament_package()
