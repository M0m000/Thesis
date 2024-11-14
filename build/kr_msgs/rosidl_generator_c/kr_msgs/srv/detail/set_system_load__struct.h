// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/SetSystemLoad.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_SYSTEM_LOAD__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__SET_SYSTEM_LOAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TOOLLOAD'.
static const char * const kr_msgs__srv__SetSystemLoad_Request__TOOLLOAD = "toolload";

/// Constant 'PAYLOAD'.
static const char * const kr_msgs__srv__SetSystemLoad_Request__PAYLOAD = "payload";

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/SetSystemLoad in the package kr_msgs.
typedef struct kr_msgs__srv__SetSystemLoad_Request
{
  rosidl_runtime_c__String name;
  double mass;
  double cog[3];
  double imx[6];
} kr_msgs__srv__SetSystemLoad_Request;

// Struct for a sequence of kr_msgs__srv__SetSystemLoad_Request.
typedef struct kr_msgs__srv__SetSystemLoad_Request__Sequence
{
  kr_msgs__srv__SetSystemLoad_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetSystemLoad_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetSystemLoad in the package kr_msgs.
typedef struct kr_msgs__srv__SetSystemLoad_Response
{
  bool success;
} kr_msgs__srv__SetSystemLoad_Response;

// Struct for a sequence of kr_msgs__srv__SetSystemLoad_Response.
typedef struct kr_msgs__srv__SetSystemLoad_Response__Sequence
{
  kr_msgs__srv__SetSystemLoad_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetSystemLoad_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__SET_SYSTEM_LOAD__STRUCT_H_
