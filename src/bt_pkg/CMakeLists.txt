cmake_minimum_required(VERSION 3.5)
project(bt_pkg)

# Finde Abhängigkeiten
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(kr_msgs REQUIRED)  # Abhängig vom Service-Typ
find_package(robot_control REQUIRED)  # Abhängig vom robot_control-Package

# Installiere Python-Quellcode-Dateien
install(PROGRAMS
  src/bt_pkg/srv_call.py
  DESTINATION lib/${PROJECT_NAME}
)

# Installiere Python-Module
install(
  DIRECTORY src/bt_pkg/
  DESTINATION lib/python${PYTHON_VERSION}/site-packages
)

ament_package()
