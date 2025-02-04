// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/FollowJoint.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__FOLLOW_JOINT__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__FOLLOW_JOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TT_VEL'.
enum
{
  kr_msgs__msg__FollowJoint__TT_VEL = 0
};

/// Constant 'TT_TIME'.
enum
{
  kr_msgs__msg__FollowJoint__TT_TIME = 1
};

/// Constant 'BP_STOP'.
enum
{
  kr_msgs__msg__FollowJoint__BP_STOP = 0
};

/// Constant 'BP_VIA'.
enum
{
  kr_msgs__msg__FollowJoint__BP_VIA = 1
};

/// Constant 'BT_ACC'.
enum
{
  kr_msgs__msg__FollowJoint__BT_ACC = 0
};

/// Constant 'BT_TIME'.
enum
{
  kr_msgs__msg__FollowJoint__BT_TIME = 1
};

/// Constant 'CH_INT'.
enum
{
  kr_msgs__msg__FollowJoint__CH_INT = 0
};

/// Constant 'CH_COM'.
enum
{
  kr_msgs__msg__FollowJoint__CH_COM = 1
};

// Struct defined in msg/FollowJoint in the package kr_msgs.
typedef struct kr_msgs__msg__FollowJoint
{
  double jsconf[7];
  int8_t ttype;
  double tvalue;
  int8_t bpoint;
  int8_t btype;
  double bvalue;
} kr_msgs__msg__FollowJoint;

// Struct for a sequence of kr_msgs__msg__FollowJoint.
typedef struct kr_msgs__msg__FollowJoint__Sequence
{
  kr_msgs__msg__FollowJoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__FollowJoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__FOLLOW_JOINT__STRUCT_H_
