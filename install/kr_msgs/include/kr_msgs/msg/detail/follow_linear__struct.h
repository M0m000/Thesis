// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/FollowLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'WORLD'.
enum
{
  kr_msgs__msg__FollowLinear__WORLD = 0
};

/// Constant 'BASE'.
enum
{
  kr_msgs__msg__FollowLinear__BASE = 1
};

/// Constant 'TCP'.
enum
{
  kr_msgs__msg__FollowLinear__TCP = 2
};

/// Constant 'TT_VEL'.
enum
{
  kr_msgs__msg__FollowLinear__TT_VEL = 0
};

/// Constant 'TT_TIME'.
enum
{
  kr_msgs__msg__FollowLinear__TT_TIME = 1
};

/// Constant 'BP_STOP'.
enum
{
  kr_msgs__msg__FollowLinear__BP_STOP = 0
};

/// Constant 'BP_VIA'.
enum
{
  kr_msgs__msg__FollowLinear__BP_VIA = 1
};

/// Constant 'BT_ACC'.
enum
{
  kr_msgs__msg__FollowLinear__BT_ACC = 0
};

/// Constant 'BT_TIME'.
enum
{
  kr_msgs__msg__FollowLinear__BT_TIME = 1
};

/// Constant 'BT_RAD'.
enum
{
  kr_msgs__msg__FollowLinear__BT_RAD = 2
};

// Struct defined in msg/FollowLinear in the package kr_msgs.
typedef struct kr_msgs__msg__FollowLinear
{
  double pos[3];
  double rot[3];
  int8_t ref;
  int8_t ttype;
  double tvalue;
  int8_t bpoint;
  int8_t btype;
  double bvalue;
} kr_msgs__msg__FollowLinear;

// Struct for a sequence of kr_msgs__msg__FollowLinear.
typedef struct kr_msgs__msg__FollowLinear__Sequence
{
  kr_msgs__msg__FollowLinear * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__FollowLinear__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__STRUCT_H_
