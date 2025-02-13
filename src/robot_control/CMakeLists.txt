cmake_minimum_required(VERSION 3.5)
project(robot_control)

# Finde Abhängigkeiten
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(kr_msgs REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(action_interfaces REQUIRED)

ament_target_dependencies(target_name action_interfaces)
install(DIRECTORY launch/
    DESTINATION share/${PROJECT_NAME}/launch
)

install(DIRECTORY config/
    DESTINATION share/${PROJECT_NAME}/config
)

# Installiere Python-Quellcode-Dateien
install(PROGRAMS
  src/robot_control/move_robot_service_server.py
  src/robot_control/move_robot_service_client.py
  DESTINATION lib/${PROJECT_NAME}
)

# Installiere Python-Module
install(
  DIRECTORY src/robot_control/
  DESTINATION lib/python${PYTHON_VERSION}/site-packages
)

ament_package()
