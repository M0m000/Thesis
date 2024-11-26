// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/SetDiscreteOutput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_DISCRETE_OUTPUT__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__SET_DISCRETE_OUTPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'OFF'.
enum
{
  kr_msgs__srv__SetDiscreteOutput_Request__OFF = 0
};

/// Constant 'ON'.
enum
{
  kr_msgs__srv__SetDiscreteOutput_Request__ON = 1
};

// Struct defined in srv/SetDiscreteOutput in the package kr_msgs.
typedef struct kr_msgs__srv__SetDiscreteOutput_Request
{
  int8_t index;
  int8_t value;
} kr_msgs__srv__SetDiscreteOutput_Request;

// Struct for a sequence of kr_msgs__srv__SetDiscreteOutput_Request.
typedef struct kr_msgs__srv__SetDiscreteOutput_Request__Sequence
{
  kr_msgs__srv__SetDiscreteOutput_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetDiscreteOutput_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetDiscreteOutput in the package kr_msgs.
typedef struct kr_msgs__srv__SetDiscreteOutput_Response
{
  bool success;
} kr_msgs__srv__SetDiscreteOutput_Response;

// Struct for a sequence of kr_msgs__srv__SetDiscreteOutput_Response.
typedef struct kr_msgs__srv__SetDiscreteOutput_Response__Sequence
{
  kr_msgs__srv__SetDiscreteOutput_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SetDiscreteOutput_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__SET_DISCRETE_OUTPUT__STRUCT_H_
