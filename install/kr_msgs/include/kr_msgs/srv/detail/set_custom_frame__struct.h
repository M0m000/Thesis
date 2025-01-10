// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/SetCustomFrame.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_CUSTOM_FRAME__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__SET_CUSTOM_FRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/SetCustomFrame in the package kr_msgs.
typedef struct kr_msgs__srv__SetCustomFrame_Request
{
  int8_t ref;
  double pos[3];
  double rot[3];
} kr_msgs__srv__SetCustomFrame_Request;

// Struct for a sequence of kr_msgs__srv__SetCustomFrame_Request.
typedef struct kr_msgs__srv__SetCustomFrame_Request__Sequence
{
  kr_msgs__srv__SetCustomFrame_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetCustomFrame_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetCustomFrame in the package kr_msgs.
typedef struct kr_msgs__srv__SetCustomFrame_Response
{
  bool success;
} kr_msgs__srv__SetCustomFrame_Response;

// Struct for a sequence of kr_msgs__srv__SetCustomFrame_Response.
typedef struct kr_msgs__srv__SetCustomFrame_Response__Sequence
{
  kr_msgs__srv__SetCustomFrame_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetCustomFrame_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__SET_CUSTOM_FRAME__STRUCT_H_
