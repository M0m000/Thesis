// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/BoundingBox in the package action_interfaces.
typedef struct action_interfaces__msg__BoundingBox
{
  float x_min;
  float y_min;
  float x_max;
  float y_max;
} action_interfaces__msg__BoundingBox;

// Struct for a sequence of action_interfaces__msg__BoundingBox.
typedef struct action_interfaces__msg__BoundingBox__Sequence
{
  action_interfaces__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
