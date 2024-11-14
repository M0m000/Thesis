// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/JogLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__JOG_LINEAR__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__JOG_LINEAR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/JogLinear in the package kr_msgs.
typedef struct kr_msgs__msg__JogLinear
{
  double vel[3];
  double rot[3];
} kr_msgs__msg__JogLinear;

// Struct for a sequence of kr_msgs__msg__JogLinear.
typedef struct kr_msgs__msg__JogLinear__Sequence
{
  kr_msgs__msg__JogLinear * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__JogLinear__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__JOG_LINEAR__STRUCT_H_
