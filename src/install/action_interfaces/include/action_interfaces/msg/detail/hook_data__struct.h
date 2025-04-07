// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__STRUCT_H_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'hooks'
#include "action_interfaces/msg/detail/hook__struct.h"

// Struct defined in msg/HookData in the package action_interfaces.
typedef struct action_interfaces__msg__HookData
{
  action_interfaces__msg__Hook__Sequence hooks;
} action_interfaces__msg__HookData;

// Struct for a sequence of action_interfaces__msg__HookData.
typedef struct action_interfaces__msg__HookData__Sequence
{
  action_interfaces__msg__HookData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__msg__HookData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__STRUCT_H_
