// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/GetSystemFrame.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_SYSTEM_FRAME__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__GET_SYSTEM_FRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'WORLD'.
static const char * const kr_msgs__srv__GetSystemFrame_Request__WORLD = "world";

/// Constant 'BASE'.
static const char * const kr_msgs__srv__GetSystemFrame_Request__BASE = "base";

/// Constant 'ELBOW'.
static const char * const kr_msgs__srv__GetSystemFrame_Request__ELBOW = "elbow";

/// Constant 'FLANGE'.
static const char * const kr_msgs__srv__GetSystemFrame_Request__FLANGE = "tfc";

/// Constant 'TCP'.
static const char * const kr_msgs__srv__GetSystemFrame_Request__TCP = "tcp";

/// Constant 'TARGET'.
static const char * const kr_msgs__srv__GetSystemFrame_Request__TARGET = "target";

// Include directives for member types
// Member 'name'
// Member 'ref'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/GetSystemFrame in the package kr_msgs.
typedef struct kr_msgs__srv__GetSystemFrame_Request
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String ref;
} kr_msgs__srv__GetSystemFrame_Request;

// Struct for a sequence of kr_msgs__srv__GetSystemFrame_Request.
typedef struct kr_msgs__srv__GetSystemFrame_Request__Sequence
{
  kr_msgs__srv__GetSystemFrame_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetSystemFrame_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/GetSystemFrame in the package kr_msgs.
typedef struct kr_msgs__srv__GetSystemFrame_Response
{
  double pos[3];
  double rot[3];
  bool success;
} kr_msgs__srv__GetSystemFrame_Response;

// Struct for a sequence of kr_msgs__srv__GetSystemFrame_Response.
typedef struct kr_msgs__srv__GetSystemFrame_Response__Sequence
{
  kr_msgs__srv__GetSystemFrame_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetSystemFrame_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__GET_SYSTEM_FRAME__STRUCT_H_
