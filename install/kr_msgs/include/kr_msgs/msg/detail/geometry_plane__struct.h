// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/GeometryPlane.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/GeometryPlane in the package kr_msgs.
typedef struct kr_msgs__msg__GeometryPlane
{
  rosidl_runtime_c__String name;
  double point[3];
  double normal[3];
} kr_msgs__msg__GeometryPlane;

// Struct for a sequence of kr_msgs__msg__GeometryPlane.
typedef struct kr_msgs__msg__GeometryPlane__Sequence
{
  kr_msgs__msg__GeometryPlane * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__GeometryPlane__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__STRUCT_H_
