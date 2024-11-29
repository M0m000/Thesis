// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/SafetyMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_MODE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__SAFETY_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SAFE'.
enum
{
  kr_msgs__msg__SafetyMode__SAFE = 0
};

/// Constant 'REDUCED'.
enum
{
  kr_msgs__msg__SafetyMode__REDUCED = 1
};

/// Constant 'NORMAL'.
enum
{
  kr_msgs__msg__SafetyMode__NORMAL = 2
};

// Struct defined in msg/SafetyMode in the package kr_msgs.
typedef struct kr_msgs__msg__SafetyMode
{
  int8_t val;
} kr_msgs__msg__SafetyMode;

// Struct for a sequence of kr_msgs__msg__SafetyMode.
typedef struct kr_msgs__msg__SafetyMode__Sequence
{
  kr_msgs__msg__SafetyMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__SafetyMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_MODE__STRUCT_H_
