cmake_minimum_required(VERSION 3.8)
project(my_python_msgs)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/HookData.msg"
  "msg/Hook.msg"
  "msg/BoundingBox.msg"
  "msg/Mask.msg"
)

ament_package()
