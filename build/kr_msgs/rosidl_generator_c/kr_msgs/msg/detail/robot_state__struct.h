// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'INIT'.
enum
{
  kr_msgs__msg__RobotState__INIT = 1
};

/// Constant 'STANDBY'.
enum
{
  kr_msgs__msg__RobotState__STANDBY = 2
};

/// Constant 'MOVING'.
enum
{
  kr_msgs__msg__RobotState__MOVING = 3
};

/// Constant 'BACKDRIVE'.
enum
{
  kr_msgs__msg__RobotState__BACKDRIVE = 4
};

/// Constant 'SUSPENDED'.
enum
{
  kr_msgs__msg__RobotState__SUSPENDED = 5
};

/// Constant 'ALARM'.
enum
{
  kr_msgs__msg__RobotState__ALARM = 6
};

// Include directives for member types
// Member 'str'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/RobotState in the package kr_msgs.
typedef struct kr_msgs__msg__RobotState
{
  int8_t val;
  rosidl_runtime_c__String str;
} kr_msgs__msg__RobotState;

// Struct for a sequence of kr_msgs__msg__RobotState.
typedef struct kr_msgs__msg__RobotState__Sequence
{
  kr_msgs__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
