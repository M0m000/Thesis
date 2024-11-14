// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kr_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/robot_pose__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/msg/detail/robot_pose__struct.h"
#include "kr_msgs/msg/detail/robot_pose__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RobotPose__ros_msg_type = kr_msgs__msg__RobotPose;

static bool _RobotPose__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotPose__ros_msg_type * ros_message = static_cast<const _RobotPose__ros_msg_type *>(untyped_ros_message);
  // Field name: pos
  {
    size_t size = 3;
    auto array_ptr = ros_message->pos;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: rot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rot;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: jsconf
  {
    size_t size = 7;
    auto array_ptr = ros_message->jsconf;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _RobotPose__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotPose__ros_msg_type * ros_message = static_cast<_RobotPose__ros_msg_type *>(untyped_ros_message);
  // Field name: pos
  {
    size_t size = 3;
    auto array_ptr = ros_message->pos;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: rot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rot;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: jsconf
  {
    size_t size = 7;
    auto array_ptr = ros_message->jsconf;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__msg__RobotPose(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotPose__ros_msg_type * ros_message = static_cast<const _RobotPose__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pos
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->rot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name jsconf
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->jsconf;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RobotPose__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__msg__RobotPose(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__msg__RobotPose(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: pos
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rot
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: jsconf
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _RobotPose__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__msg__RobotPose(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RobotPose = {
  "kr_msgs::msg",
  "RobotPose",
  _RobotPose__cdr_serialize,
  _RobotPose__cdr_deserialize,
  _RobotPose__get_serialized_size,
  _RobotPose__max_serialized_size
};

static rosidl_message_type_support_t _RobotPose__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotPose,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, RobotPose)() {
  return &_RobotPose__type_support;
}

#if defined(__cplusplus)
}
#endif
