# generated from
# ament_cmake_core/cmake/symlink_install/ament_cmake_symlink_install.cmake.in

# create empty symlink install manifest before starting install step
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/symlink_install_manifest.txt")

#
# Reimplement CMake install(DIRECTORY) command to use symlinks instead of
# copying resources.
#
# :param cmake_current_source_dir: The CMAKE_CURRENT_SOURCE_DIR when install
#   was invoked
# :type cmake_current_source_dir: string
# :param ARGN: the same arguments as the CMake install command.
# :type ARGN: various
#
function(ament_cmake_symlink_install_directory cmake_current_source_dir)
  cmake_parse_arguments(ARG "OPTIONAL" "DESTINATION" "DIRECTORY;PATTERN;PATTERN_EXCLUDE" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_directory() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # make destination absolute path and ensure that it exists
  if(NOT IS_ABSOLUTE "${ARG_DESTINATION}")
    set(ARG_DESTINATION "/home/vboxuser/Thesis/install/kr_msgs/${ARG_DESTINATION}")
  endif()
  if(NOT EXISTS "${ARG_DESTINATION}")
    file(MAKE_DIRECTORY "${ARG_DESTINATION}")
  endif()

  # default pattern to include
  if(NOT ARG_PATTERN)
    set(ARG_PATTERN "*")
  endif()

  # iterate over directories
  foreach(dir ${ARG_DIRECTORY})
    # make dir an absolute path
    if(NOT IS_ABSOLUTE "${dir}")
      set(dir "${cmake_current_source_dir}/${dir}")
    endif()

    if(EXISTS "${dir}")
      # if directory has no trailing slash
      # append folder name to destination
      set(destination "${ARG_DESTINATION}")
      string(LENGTH "${dir}" length)
      math(EXPR offset "${length} - 1")
      string(SUBSTRING "${dir}" ${offset} 1 dir_last_char)
      if(NOT dir_last_char STREQUAL "/")
        get_filename_component(destination_name "${dir}" NAME)
        set(destination "${destination}/${destination_name}")
      else()
        # remove trailing slash
        string(SUBSTRING "${dir}" 0 ${offset} dir)
      endif()

      # glob recursive files
      set(relative_files "")
      foreach(pattern ${ARG_PATTERN})
        file(
          GLOB_RECURSE
          include_files
          RELATIVE "${dir}"
          "${dir}/${pattern}"
        )
        if(NOT include_files STREQUAL "")
          list(APPEND relative_files ${include_files})
        endif()
      endforeach()
      foreach(pattern ${ARG_PATTERN_EXCLUDE})
        file(
          GLOB_RECURSE
          exclude_files
          RELATIVE "${dir}"
          "${dir}/${pattern}"
        )
        if(NOT exclude_files STREQUAL "")
          list(REMOVE_ITEM relative_files ${exclude_files})
        endif()
      endforeach()
      list(SORT relative_files)

      foreach(relative_file ${relative_files})
        set(absolute_file "${dir}/${relative_file}")
        # determine link name for file including destination path
        set(symlink "${destination}/${relative_file}")

        # ensure that destination exists
        get_filename_component(symlink_dir "${symlink}" PATH)
        if(NOT EXISTS "${symlink_dir}")
          file(MAKE_DIRECTORY "${symlink_dir}")
        endif()

        _ament_cmake_symlink_install_create_symlink("${absolute_file}" "${symlink}")
      endforeach()
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_directory() can't find '${dir}'")
      endif()
    endif()
  endforeach()
endfunction()

#
# Reimplement CMake install(FILES) command to use symlinks instead of copying
# resources.
#
# :param cmake_current_source_dir: The CMAKE_CURRENT_SOURCE_DIR when install
#   was invoked
# :type cmake_current_source_dir: string
# :param ARGN: the same arguments as the CMake install command.
# :type ARGN: various
#
function(ament_cmake_symlink_install_files cmake_current_source_dir)
  cmake_parse_arguments(ARG "OPTIONAL" "DESTINATION;RENAME" "FILES" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_files() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # make destination an absolute path and ensure that it exists
  if(NOT IS_ABSOLUTE "${ARG_DESTINATION}")
    set(ARG_DESTINATION "/home/vboxuser/Thesis/install/kr_msgs/${ARG_DESTINATION}")
  endif()
  if(NOT EXISTS "${ARG_DESTINATION}")
    file(MAKE_DIRECTORY "${ARG_DESTINATION}")
  endif()

  if(ARG_RENAME)
    list(LENGTH ARG_FILES file_count)
    if(NOT file_count EQUAL 1)
    message(FATAL_ERROR "ament_cmake_symlink_install_files() called with "
      "RENAME argument but not with a single file")
    endif()
  endif()

  # iterate over files
  foreach(file ${ARG_FILES})
    # make file an absolute path
    if(NOT IS_ABSOLUTE "${file}")
      set(file "${cmake_current_source_dir}/${file}")
    endif()

    if(EXISTS "${file}")
      # determine link name for file including destination path
      get_filename_component(filename "${file}" NAME)
      if(NOT ARG_RENAME)
        set(symlink "${ARG_DESTINATION}/${filename}")
      else()
        set(symlink "${ARG_DESTINATION}/${ARG_RENAME}")
      endif()
      _ament_cmake_symlink_install_create_symlink("${file}" "${symlink}")
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_files() can't find '${file}'")
      endif()
    endif()
  endforeach()
endfunction()

#
# Reimplement CMake install(PROGRAMS) command to use symlinks instead of copying
# resources.
#
# :param cmake_current_source_dir: The CMAKE_CURRENT_SOURCE_DIR when install
#   was invoked
# :type cmake_current_source_dir: string
# :param ARGN: the same arguments as the CMake install command.
# :type ARGN: various
#
function(ament_cmake_symlink_install_programs cmake_current_source_dir)
  cmake_parse_arguments(ARG "OPTIONAL" "DESTINATION" "PROGRAMS" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_programs() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # make destination an absolute path and ensure that it exists
  if(NOT IS_ABSOLUTE "${ARG_DESTINATION}")
    set(ARG_DESTINATION "/home/vboxuser/Thesis/install/kr_msgs/${ARG_DESTINATION}")
  endif()
  if(NOT EXISTS "${ARG_DESTINATION}")
    file(MAKE_DIRECTORY "${ARG_DESTINATION}")
  endif()

  # iterate over programs
  foreach(file ${ARG_PROGRAMS})
    # make file an absolute path
    if(NOT IS_ABSOLUTE "${file}")
      set(file "${cmake_current_source_dir}/${file}")
    endif()

    if(EXISTS "${file}")
      # determine link name for file including destination path
      get_filename_component(filename "${file}" NAME)
      set(symlink "${ARG_DESTINATION}/${filename}")
      _ament_cmake_symlink_install_create_symlink("${file}" "${symlink}")
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_programs() can't find '${file}'")
      endif()
    endif()
  endforeach()
endfunction()

#
# Reimplement CMake install(TARGETS) command to use symlinks instead of copying
# resources.
#
# :param TARGET_FILES: the absolute files, replacing the name of targets passed
#   in as TARGETS
# :type TARGET_FILES: list of files
# :param ARGN: the same arguments as the CMake install command except that
#   keywords identifying the kind of type and the DESTINATION keyword must be
#   joined with an underscore, e.g. ARCHIVE_DESTINATION.
# :type ARGN: various
#
function(ament_cmake_symlink_install_targets)
  cmake_parse_arguments(ARG "OPTIONAL" "ARCHIVE_DESTINATION;DESTINATION;LIBRARY_DESTINATION;RUNTIME_DESTINATION"
    "TARGETS;TARGET_FILES" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_targets() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # iterate over target files
  foreach(file ${ARG_TARGET_FILES})
    if(NOT IS_ABSOLUTE "${file}")
      message(FATAL_ERROR "ament_cmake_symlink_install_targets() target file "
        "'${file}' must be an absolute path")
    endif()

    # determine destination of file based on extension
    set(destination "")
    get_filename_component(fileext "${file}" EXT)
    if(fileext STREQUAL ".a" OR fileext STREQUAL ".lib")
      set(destination "${ARG_ARCHIVE_DESTINATION}")
    elseif(fileext STREQUAL ".dylib" OR fileext MATCHES "\\.so(\\.[0-9]+)?(\\.[0-9]+)?(\\.[0-9]+)?$")
      set(destination "${ARG_LIBRARY_DESTINATION}")
    elseif(fileext STREQUAL "" OR fileext STREQUAL ".dll" OR fileext STREQUAL ".exe")
      set(destination "${ARG_RUNTIME_DESTINATION}")
    endif()
    if(destination STREQUAL "")
      set(destination "${ARG_DESTINATION}")
    endif()

    # make destination an absolute path and ensure that it exists
    if(NOT IS_ABSOLUTE "${destination}")
      set(destination "/home/vboxuser/Thesis/install/kr_msgs/${destination}")
    endif()
    if(NOT EXISTS "${destination}")
      file(MAKE_DIRECTORY "${destination}")
    endif()

    if(EXISTS "${file}")
      # determine link name for file including destination path
      get_filename_component(filename "${file}" NAME)
      set(symlink "${destination}/${filename}")
      _ament_cmake_symlink_install_create_symlink("${file}" "${symlink}")
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_targets() can't find '${file}'")
      endif()
    endif()
  endforeach()
endfunction()

function(_ament_cmake_symlink_install_create_symlink absolute_file symlink)
  # register symlink for being removed during install step
  file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/symlink_install_manifest.txt"
    "${symlink}\n")

  # avoid any work if correct symlink is already in place
  if(EXISTS "${symlink}" AND IS_SYMLINK "${symlink}")
    get_filename_component(destination "${symlink}" REALPATH)
    get_filename_component(real_absolute_file "${absolute_file}" REALPATH)
    if(destination STREQUAL real_absolute_file)
      message(STATUS "Up-to-date symlink: ${symlink}")
      return()
    endif()
  endif()

  message(STATUS "Symlinking: ${symlink}")
  if(EXISTS "${symlink}" OR IS_SYMLINK "${symlink}")
    file(REMOVE "${symlink}")
  endif()

  execute_process(
    COMMAND "/usr/bin/cmake" "-E" "create_symlink"
      "${absolute_file}"
      "${symlink}"
  )
  # the CMake command does not provide a return code so check manually
  if(NOT EXISTS "${symlink}" OR NOT IS_SYMLINK "${symlink}")
    get_filename_component(destination "${symlink}" REALPATH)
    message(FATAL_ERROR
      "Could not create symlink '${symlink}' pointing to '${absolute_file}'")
  endif()
endfunction()

# end of template

message(STATUS "Execute custom install script")

# begin of custom install code

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/kr_msgs" "DESTINATION" "share/ament_index/resource_index/rosidl_interfaces")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/kr_msgs" "DESTINATION" "share/ament_index/resource_index/rosidl_interfaces")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_c/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.h")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_c/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.h")

# install(FILES "/opt/ros/foxy/lib/python3.8/site-packages/ament_package/template/environment_hook/library_path.sh" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/opt/ros/foxy/lib/python3.8/site-packages/ament_package/template/environment_hook/library_path.sh" "DESTINATION" "share/kr_msgs/environment")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/library_path.dsv" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/library_path.dsv" "DESTINATION" "share/kr_msgs/environment")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_fastrtps_c/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN_EXCLUDE" "*.cpp")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_fastrtps_c/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN_EXCLUDE" "*.cpp")

# install("TARGETS" "kr_msgs__rosidl_typesupport_fastrtps_c" "ARCHIVE_DESTINATION" "lib" "LIBRARY_DESTINATION" "lib" "RUNTIME_DESTINATION" "bin")
include("/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_symlink_install_targets_0_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_fastrtps_cpp/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN_EXCLUDE" "*.cpp")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_fastrtps_cpp/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN_EXCLUDE" "*.cpp")

# install("TARGETS" "kr_msgs__rosidl_typesupport_fastrtps_cpp" "ARCHIVE_DESTINATION" "lib" "LIBRARY_DESTINATION" "lib" "RUNTIME_DESTINATION" "bin")
include("/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_symlink_install_targets_1_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_introspection_c/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.h")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_introspection_c/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.h")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_cpp/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.hpp")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_cpp/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.hpp")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_introspection_cpp/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.hpp")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_typesupport_introspection_cpp/kr_msgs/" "DESTINATION" "include/kr_msgs" "PATTERN" "*.hpp")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/pythonpath.sh" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/pythonpath.sh" "DESTINATION" "share/kr_msgs/environment")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/pythonpath.dsv" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/pythonpath.dsv" "DESTINATION" "share/kr_msgs/environment")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_py/kr_msgs/__init__.py" "DESTINATION" "lib/python3.8/site-packages/kr_msgs")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_py/kr_msgs/__init__.py" "DESTINATION" "lib/python3.8/site-packages/kr_msgs")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_py/kr_msgs/msg/" "DESTINATION" "lib/python3.8/site-packages/kr_msgs/msg" "PATTERN" "*.py")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_py/kr_msgs/msg/" "DESTINATION" "lib/python3.8/site-packages/kr_msgs/msg" "PATTERN" "*.py")

# install(DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_py/kr_msgs/srv/" "DESTINATION" "lib/python3.8/site-packages/kr_msgs/srv" "PATTERN" "*.py")
ament_cmake_symlink_install_directory("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" DIRECTORY "/home/vboxuser/Thesis/build/kr_msgs/rosidl_generator_py/kr_msgs/srv/" "DESTINATION" "lib/python3.8/site-packages/kr_msgs/srv" "PATTERN" "*.py")

# install("TARGETS" "kr_msgs__rosidl_typesupport_fastrtps_c__pyext" "DESTINATION" "lib/python3.8/site-packages/kr_msgs")
include("/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_symlink_install_targets_2_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install("TARGETS" "kr_msgs__rosidl_typesupport_introspection_c__pyext" "DESTINATION" "lib/python3.8/site-packages/kr_msgs")
include("/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_symlink_install_targets_3_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install("TARGETS" "kr_msgs__rosidl_typesupport_c__pyext" "DESTINATION" "lib/python3.8/site-packages/kr_msgs")
include("/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_symlink_install_targets_4_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install("TARGETS" "kr_msgs__python" "ARCHIVE_DESTINATION" "lib" "LIBRARY_DESTINATION" "lib" "RUNTIME_DESTINATION" "bin")
include("/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_symlink_install_targets_5_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/FollowJoint.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/FollowJoint.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/FollowLinear.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/FollowLinear.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/GeometryPlane.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/GeometryPlane.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/JogJoint.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/JogJoint.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/JogLinear.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/JogLinear.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/MotionHeartbeat.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/MotionHeartbeat.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/Number.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/Number.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/ProgramInteract.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/ProgramInteract.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/Quadrature.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/Quadrature.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/RobotMode.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/RobotMode.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/RobotPose.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/RobotPose.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/RobotState.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/RobotState.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SafetyEvent.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SafetyEvent.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SafetyMode.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SafetyMode.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SafetyZone.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SafetyZone.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SelfMotion.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SelfMotion.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SystemState.idl" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/msg/SystemState.idl" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ConfigAnalogOutput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ConfigAnalogOutput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ConfigDiscreteOutput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ConfigDiscreteOutput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ConfigQuadratureInput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ConfigQuadratureInput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetAnalogInput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetAnalogInput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetDiscreteInput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetDiscreteInput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetQuadratureInput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetQuadratureInput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetAnalogOutput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetAnalogOutput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetDiscreteOutput.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetDiscreteOutput.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/MoveJoint.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/MoveJoint.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/MoveLinear.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/MoveLinear.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/MoveSpline.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/MoveSpline.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/PauseMotion.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/PauseMotion.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ResumeMotion.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ResumeMotion.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SelectJoggingFrame.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SelectJoggingFrame.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetCustomFrame.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetCustomFrame.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetInteractivity.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetInteractivity.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/TerminateMotion.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/TerminateMotion.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetProgramState.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetProgramState.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/PauseProgram.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/PauseProgram.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ProgramRecovery.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ProgramRecovery.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ResumeProgram.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/ResumeProgram.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/StepProgram.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/StepProgram.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/StopProgram.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/StopProgram.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetRobotPose.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetRobotPose.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSystemFrame.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSystemFrame.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSystemLoad.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSystemLoad.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetSystemFrame.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetSystemFrame.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetSystemLoad.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SetSystemLoad.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetMasterSpeed.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetMasterSpeed.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetRobotMode.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetRobotMode.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetRobotState.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetRobotState.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSafetyMode.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSafetyMode.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSafetyZones.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/GetSafetyZones.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/LogAlarm.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/LogAlarm.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SuspendRobot.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/SuspendRobot.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/UnlockRobot.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/UnlockRobot.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/UnsuspendRobot.idl" "DESTINATION" "share/kr_msgs/srv")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_adapter/kr_msgs/srv/UnsuspendRobot.idl" "DESTINATION" "share/kr_msgs/srv")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/FollowJoint.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/FollowJoint.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/FollowLinear.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/FollowLinear.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/GeometryPlane.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/GeometryPlane.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/JogJoint.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/JogJoint.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/JogLinear.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/JogLinear.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/MotionHeartbeat.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/MotionHeartbeat.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/Number.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/Number.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/ProgramInteract.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/ProgramInteract.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/Quadrature.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/Quadrature.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/RobotMode.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/RobotMode.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/RobotPose.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/RobotPose.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/RobotState.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/RobotState.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SafetyEvent.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SafetyEvent.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SafetyMode.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SafetyMode.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SafetyZone.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SafetyZone.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SelfMotion.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SelfMotion.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SystemState.msg" "DESTINATION" "share/kr_msgs/msg")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/msg/SystemState.msg" "DESTINATION" "share/kr_msgs/msg")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/ConfigAnalogOutput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/ConfigAnalogOutput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigAnalogOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigAnalogOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigAnalogOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigAnalogOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/ConfigDiscreteOutput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/ConfigDiscreteOutput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigDiscreteOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigDiscreteOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigDiscreteOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigDiscreteOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/ConfigQuadratureInput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/ConfigQuadratureInput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigQuadratureInput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigQuadratureInput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigQuadratureInput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/ConfigQuadratureInput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/GetAnalogInput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/GetAnalogInput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetAnalogInput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetAnalogInput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetAnalogInput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetAnalogInput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/GetDiscreteInput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/GetDiscreteInput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetDiscreteInput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetDiscreteInput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetDiscreteInput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetDiscreteInput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/GetQuadratureInput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/GetQuadratureInput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetQuadratureInput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetQuadratureInput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetQuadratureInput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/GetQuadratureInput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/SetAnalogOutput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/SetAnalogOutput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetAnalogOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetAnalogOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetAnalogOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetAnalogOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/SetDiscreteOutput.srv" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/io/SetDiscreteOutput.srv" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetDiscreteOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetDiscreteOutput_Request.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetDiscreteOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/io/SetDiscreteOutput_Response.msg" "DESTINATION" "share/kr_msgs/io")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/MoveJoint.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/MoveJoint.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveJoint_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveJoint_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveJoint_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveJoint_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/MoveLinear.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/MoveLinear.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveLinear_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveLinear_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveLinear_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveLinear_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/MoveSpline.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/MoveSpline.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveSpline_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveSpline_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveSpline_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/MoveSpline_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/PauseMotion.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/PauseMotion.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/PauseMotion_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/PauseMotion_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/PauseMotion_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/PauseMotion_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/ResumeMotion.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/ResumeMotion.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/ResumeMotion_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/ResumeMotion_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/ResumeMotion_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/ResumeMotion_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/SelectJoggingFrame.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/SelectJoggingFrame.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SelectJoggingFrame_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SelectJoggingFrame_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SelectJoggingFrame_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SelectJoggingFrame_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/SetCustomFrame.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/SetCustomFrame.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetCustomFrame_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetCustomFrame_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetCustomFrame_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetCustomFrame_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/SetInteractivity.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/SetInteractivity.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetInteractivity_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetInteractivity_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetInteractivity_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/SetInteractivity_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/TerminateMotion.srv" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/motion/TerminateMotion.srv" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/TerminateMotion_Request.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/TerminateMotion_Request.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/TerminateMotion_Response.msg" "DESTINATION" "share/kr_msgs/motion")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/motion/TerminateMotion_Response.msg" "DESTINATION" "share/kr_msgs/motion")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/GetProgramState.srv" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/GetProgramState.srv" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/GetProgramState_Request.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/GetProgramState_Request.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/GetProgramState_Response.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/GetProgramState_Response.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/PauseProgram.srv" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/PauseProgram.srv" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/PauseProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/PauseProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/PauseProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/PauseProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/ProgramRecovery.srv" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/ProgramRecovery.srv" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ProgramRecovery_Request.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ProgramRecovery_Request.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ProgramRecovery_Response.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ProgramRecovery_Response.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/ResumeProgram.srv" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/ResumeProgram.srv" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ResumeProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ResumeProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ResumeProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/ResumeProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/StepProgram.srv" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/StepProgram.srv" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StepProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StepProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StepProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StepProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/StopProgram.srv" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/program/StopProgram.srv" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StopProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StopProgram_Request.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StopProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/program/StopProgram_Response.msg" "DESTINATION" "share/kr_msgs/program")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/GetRobotPose.srv" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/GetRobotPose.srv" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetRobotPose_Request.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetRobotPose_Request.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetRobotPose_Response.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetRobotPose_Response.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/GetSystemFrame.srv" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/GetSystemFrame.srv" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemFrame_Request.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemFrame_Request.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemFrame_Response.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemFrame_Response.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/GetSystemLoad.srv" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/GetSystemLoad.srv" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemLoad_Request.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemLoad_Request.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemLoad_Response.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/GetSystemLoad_Response.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/SetSystemFrame.srv" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/SetSystemFrame.srv" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemFrame_Request.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemFrame_Request.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemFrame_Response.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemFrame_Response.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/SetSystemLoad.srv" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/robot/SetSystemLoad.srv" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemLoad_Request.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemLoad_Request.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemLoad_Response.msg" "DESTINATION" "share/kr_msgs/robot")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/robot/SetSystemLoad_Response.msg" "DESTINATION" "share/kr_msgs/robot")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetMasterSpeed.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetMasterSpeed.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetMasterSpeed_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetMasterSpeed_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetMasterSpeed_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetMasterSpeed_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetRobotMode.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetRobotMode.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotMode_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotMode_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotMode_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotMode_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetRobotState.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetRobotState.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotState_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotState_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotState_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetRobotState_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetSafetyMode.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetSafetyMode.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyMode_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyMode_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyMode_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyMode_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetSafetyZones.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/GetSafetyZones.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyZones_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyZones_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyZones_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/GetSafetyZones_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/LogAlarm.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/LogAlarm.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/LogAlarm_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/LogAlarm_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/LogAlarm_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/LogAlarm_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/SuspendRobot.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/SuspendRobot.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/SuspendRobot_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/SuspendRobot_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/SuspendRobot_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/SuspendRobot_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/UnlockRobot.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/UnlockRobot.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnlockRobot_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnlockRobot_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnlockRobot_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnlockRobot_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/UnsuspendRobot.srv" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/srv/system/UnsuspendRobot.srv" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnsuspendRobot_Request.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnsuspendRobot_Request.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnsuspendRobot_Response.msg" "DESTINATION" "share/kr_msgs/system")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/srv/system/UnsuspendRobot_Response.msg" "DESTINATION" "share/kr_msgs/system")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/kr_msgs" "DESTINATION" "share/ament_index/resource_index/package_run_dependencies")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/kr_msgs" "DESTINATION" "share/ament_index/resource_index/package_run_dependencies")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/kr_msgs" "DESTINATION" "share/ament_index/resource_index/parent_prefix_path")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/kr_msgs" "DESTINATION" "share/ament_index/resource_index/parent_prefix_path")

# install(FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh" "DESTINATION" "share/kr_msgs/environment")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/ament_prefix_path.dsv" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/ament_prefix_path.dsv" "DESTINATION" "share/kr_msgs/environment")

# install(FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh" "DESTINATION" "share/kr_msgs/environment")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/path.dsv" "DESTINATION" "share/kr_msgs/environment")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/path.dsv" "DESTINATION" "share/kr_msgs/environment")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.bash" "DESTINATION" "share/kr_msgs")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.bash" "DESTINATION" "share/kr_msgs")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.sh" "DESTINATION" "share/kr_msgs")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.sh" "DESTINATION" "share/kr_msgs")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.zsh" "DESTINATION" "share/kr_msgs")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.zsh" "DESTINATION" "share/kr_msgs")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.dsv" "DESTINATION" "share/kr_msgs")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/local_setup.dsv" "DESTINATION" "share/kr_msgs")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/package.dsv" "DESTINATION" "share/kr_msgs")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_environment_hooks/package.dsv" "DESTINATION" "share/kr_msgs")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/packages/kr_msgs" "DESTINATION" "share/ament_index/resource_index/packages")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_index/share/ament_index/resource_index/packages/kr_msgs" "DESTINATION" "share/ament_index/resource_index/packages")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/rosidl_cmake-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/rosidl_cmake-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_core/kr_msgsConfig.cmake" "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_core/kr_msgsConfig-version.cmake" "DESTINATION" "share/kr_msgs/cmake")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_core/kr_msgsConfig.cmake" "/home/vboxuser/Thesis/build/kr_msgs/ament_cmake_core/kr_msgsConfig-version.cmake" "DESTINATION" "share/kr_msgs/cmake")

# install(FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/package.xml" "DESTINATION" "share/kr_msgs")
ament_cmake_symlink_install_files("/home/vboxuser/Thesis/src/orange-ros2/kr_msgs" FILES "/home/vboxuser/Thesis/src/orange-ros2/kr_msgs/package.xml" "DESTINATION" "share/kr_msgs")
