// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/GetMasterSpeed.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_MASTER_SPEED__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__GET_MASTER_SPEED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetMasterSpeed in the package kr_msgs.
typedef struct kr_msgs__srv__GetMasterSpeed_Request
{
  uint8_t structure_needs_at_least_one_member;
} kr_msgs__srv__GetMasterSpeed_Request;

// Struct for a sequence of kr_msgs__srv__GetMasterSpeed_Request.
typedef struct kr_msgs__srv__GetMasterSpeed_Request__Sequence
{
  kr_msgs__srv__GetMasterSpeed_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetMasterSpeed_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/GetMasterSpeed in the package kr_msgs.
typedef struct kr_msgs__srv__GetMasterSpeed_Response
{
  double speed;
  bool success;
} kr_msgs__srv__GetMasterSpeed_Response;

// Struct for a sequence of kr_msgs__srv__GetMasterSpeed_Response.
typedef struct kr_msgs__srv__GetMasterSpeed_Response__Sequence
{
  kr_msgs__srv__GetMasterSpeed_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetMasterSpeed_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__GET_MASTER_SPEED__STRUCT_H_
