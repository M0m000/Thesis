// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/SelfMotion.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SELF_MOTION__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__SELF_MOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/SelfMotion in the package kr_msgs.
typedef struct kr_msgs__msg__SelfMotion
{
  double speed;
} kr_msgs__msg__SelfMotion;

// Struct for a sequence of kr_msgs__msg__SelfMotion.
typedef struct kr_msgs__msg__SelfMotion__Sequence
{
  kr_msgs__msg__SelfMotion * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__SelfMotion__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__SELF_MOTION__STRUCT_H_
