// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RobotPose in the package kr_msgs.
typedef struct kr_msgs__msg__RobotPose
{
  double pos[3];
  double rot[3];
  double jsconf[7];
} kr_msgs__msg__RobotPose;

// Struct for a sequence of kr_msgs__msg__RobotPose.
typedef struct kr_msgs__msg__RobotPose__Sequence
{
  kr_msgs__msg__RobotPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__RobotPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_