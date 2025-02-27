// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK__STRUCT_H_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK__STRUCT_H_

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
// Member 'hook_box'
// Member 'tip_box'
// Member 'lowpoint_box'
#include "action_interfaces/msg/detail/bounding_box__struct.h"
// Member 'hook_mask'
// Member 'tip_mask'
// Member 'lowpoint_mask'
// Member 'skeleton_mask'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'uv_hook'
// Member 'uv_tip'
// Member 'uv_lowpoint'
// Member 'uv_hook_img2'
// Member 'uv_tip_img2'
// Member 'uv_lowpoint_img2'
// Member 'shortest_path'
// Member 'path_points'
#include "action_interfaces/msg/detail/uv__struct.h"
// Member 'xyz_hook_in_camframe'
// Member 'xyz_tip_in_camframe'
// Member 'xyz_lowpoint_in_camframe'
// Member 'path_points_xyz_in_camframe'
#include "action_interfaces/msg/detail/xyz__struct.h"

// Struct defined in msg/Hook in the package action_interfaces.
typedef struct action_interfaces__msg__Hook
{
  rosidl_runtime_c__String name;
  action_interfaces__msg__BoundingBox hook_box;
  action_interfaces__msg__BoundingBox tip_box;
  action_interfaces__msg__BoundingBox lowpoint_box;
  sensor_msgs__msg__Image hook_mask;
  sensor_msgs__msg__Image tip_mask;
  sensor_msgs__msg__Image lowpoint_mask;
  sensor_msgs__msg__Image skeleton_mask;
  float conf_hook;
  float conf_tip;
  float conf_lowpoint;
  action_interfaces__msg__UV uv_hook;
  action_interfaces__msg__UV uv_tip;
  action_interfaces__msg__UV uv_lowpoint;
  action_interfaces__msg__UV uv_hook_img2;
  action_interfaces__msg__UV uv_tip_img2;
  action_interfaces__msg__UV uv_lowpoint_img2;
  action_interfaces__msg__UV__Sequence shortest_path;
  action_interfaces__msg__UV__Sequence path_points;
  action_interfaces__msg__XYZ__Sequence xyz_hook_in_camframe;
  action_interfaces__msg__XYZ__Sequence xyz_tip_in_camframe;
  action_interfaces__msg__XYZ__Sequence xyz_lowpoint_in_camframe;
  action_interfaces__msg__XYZ__Sequence path_points_xyz_in_camframe;
} action_interfaces__msg__Hook;

// Struct for a sequence of action_interfaces__msg__Hook.
typedef struct action_interfaces__msg__Hook__Sequence
{
  action_interfaces__msg__Hook * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__msg__Hook__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK__STRUCT_H_
