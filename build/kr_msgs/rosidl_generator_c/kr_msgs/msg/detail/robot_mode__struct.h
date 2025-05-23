// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/RobotMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_MODE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__ROBOT_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MANUAL'.
enum
{
  kr_msgs__msg__RobotMode__MANUAL = 0
};

/// Constant 'AUTONOMOUS'.
enum
{
  kr_msgs__msg__RobotMode__AUTONOMOUS = 1
};

// Include directives for member types
// Member 'str'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/RobotMode in the package kr_msgs.
typedef struct kr_msgs__msg__RobotMode
{
  int8_t val;
  rosidl_runtime_c__String str;
} kr_msgs__msg__RobotMode;

// Struct for a sequence of kr_msgs__msg__RobotMode.
typedef struct kr_msgs__msg__RobotMode__Sequence
{
  kr_msgs__msg__RobotMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__RobotMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_MODE__STRUCT_H_
