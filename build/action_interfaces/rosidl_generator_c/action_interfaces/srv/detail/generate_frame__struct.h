// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:srv/GenerateFrame.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__STRUCT_H_
#define ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'frame_new'
// Member 'frame_ref'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/GenerateFrame in the package action_interfaces.
typedef struct action_interfaces__srv__GenerateFrame_Request
{
  rosidl_runtime_c__String frame_new;
  rosidl_runtime_c__String frame_ref;
  double translation[3];
  double rotation_rpy[3];
} action_interfaces__srv__GenerateFrame_Request;

// Struct for a sequence of action_interfaces__srv__GenerateFrame_Request.
typedef struct action_interfaces__srv__GenerateFrame_Request__Sequence
{
  action_interfaces__srv__GenerateFrame_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__srv__GenerateFrame_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/GenerateFrame in the package action_interfaces.
typedef struct action_interfaces__srv__GenerateFrame_Response
{
  bool success;
  rosidl_runtime_c__String message;
} action_interfaces__srv__GenerateFrame_Response;

// Struct for a sequence of action_interfaces__srv__GenerateFrame_Response.
typedef struct action_interfaces__srv__GenerateFrame_Response__Sequence
{
  action_interfaces__srv__GenerateFrame_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__srv__GenerateFrame_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__STRUCT_H_
