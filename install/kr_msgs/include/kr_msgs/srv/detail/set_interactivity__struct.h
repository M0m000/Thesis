// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/SetInteractivity.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_INTERACTIVITY__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__SET_INTERACTIVITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/SetInteractivity in the package kr_msgs.
typedef struct kr_msgs__srv__SetInteractivity_Request
{
  bool enable;
} kr_msgs__srv__SetInteractivity_Request;

// Struct for a sequence of kr_msgs__srv__SetInteractivity_Request.
typedef struct kr_msgs__srv__SetInteractivity_Request__Sequence
{
  kr_msgs__srv__SetInteractivity_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetInteractivity_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetInteractivity in the package kr_msgs.
typedef struct kr_msgs__srv__SetInteractivity_Response
{
  bool success;
} kr_msgs__srv__SetInteractivity_Response;

// Struct for a sequence of kr_msgs__srv__SetInteractivity_Response.
typedef struct kr_msgs__srv__SetInteractivity_Response__Sequence
{
  kr_msgs__srv__SetInteractivity_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetInteractivity_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__SET_INTERACTIVITY__STRUCT_H_
