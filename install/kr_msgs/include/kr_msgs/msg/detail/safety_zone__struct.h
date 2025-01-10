// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_ZONE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__SAFETY_ZONE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SDIO01'.
enum
{
  kr_msgs__msg__SafetyZone__SDIO01 = 1
};

/// Constant 'SDIO02'.
enum
{
  kr_msgs__msg__SafetyZone__SDIO02 = 2
};

/// Constant 'SDIO03'.
enum
{
  kr_msgs__msg__SafetyZone__SDIO03 = 3
};

/// Constant 'SDIO04'.
enum
{
  kr_msgs__msg__SafetyZone__SDIO04 = 4
};

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'planes'
#include "kr_msgs/msg/detail/geometry_plane__struct.h"

// Struct defined in msg/SafetyZone in the package kr_msgs.
typedef struct kr_msgs__msg__SafetyZone
{
  rosidl_runtime_c__String name;
  double speed;
  double buffer;
  double sensitivity[7];
  int8_t safety_io;
  kr_msgs__msg__GeometryPlane__Sequence planes;
} kr_msgs__msg__SafetyZone;

// Struct for a sequence of kr_msgs__msg__SafetyZone.
typedef struct kr_msgs__msg__SafetyZone__Sequence
{
  kr_msgs__msg__SafetyZone * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__SafetyZone__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_ZONE__STRUCT_H_
