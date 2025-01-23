// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:msg/UV.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__UV__STRUCT_H_
#define ACTION_INTERFACES__MSG__DETAIL__UV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/UV in the package action_interfaces.
typedef struct action_interfaces__msg__UV
{
  rosidl_runtime_c__float__Sequence data;
} action_interfaces__msg__UV;

// Struct for a sequence of action_interfaces__msg__UV.
typedef struct action_interfaces__msg__UV__Sequence
{
  action_interfaces__msg__UV * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__msg__UV__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__UV__STRUCT_H_
