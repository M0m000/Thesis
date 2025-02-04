// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/MotionHeartbeat.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__MOTION_HEARTBEAT__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__MOTION_HEARTBEAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/MotionHeartbeat in the package kr_msgs.
typedef struct kr_msgs__msg__MotionHeartbeat
{
  uint8_t structure_needs_at_least_one_member;
} kr_msgs__msg__MotionHeartbeat;

// Struct for a sequence of kr_msgs__msg__MotionHeartbeat.
typedef struct kr_msgs__msg__MotionHeartbeat__Sequence
{
  kr_msgs__msg__MotionHeartbeat * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__MotionHeartbeat__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__MOTION_HEARTBEAT__STRUCT_H_
