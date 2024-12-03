// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/Quadrature.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__QUADRATURE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__QUADRATURE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Quadrature in the package kr_msgs.
typedef struct kr_msgs__msg__Quadrature
{
  int8_t direction;
  int32_t pulse_count;
  int32_t frequency;
  int32_t abs_pulse_count;
  int32_t pulse_per_sec;
} kr_msgs__msg__Quadrature;

// Struct for a sequence of kr_msgs__msg__Quadrature.
typedef struct kr_msgs__msg__Quadrature__Sequence
{
  kr_msgs__msg__Quadrature * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__Quadrature__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__QUADRATURE__STRUCT_H_
