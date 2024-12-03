// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/ConfigDiscreteOutput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__CONFIG_DISCRETE_OUTPUT__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__CONFIG_DISCRETE_OUTPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'RANGE_12V'.
enum
{
  kr_msgs__srv__ConfigDiscreteOutput_Request__RANGE_12V = 0
};

/// Constant 'RANGE_24V'.
enum
{
  kr_msgs__srv__ConfigDiscreteOutput_Request__RANGE_24V = 1
};

// Struct defined in srv/ConfigDiscreteOutput in the package kr_msgs.
typedef struct kr_msgs__srv__ConfigDiscreteOutput_Request
{
  int8_t index;
  int8_t range;
} kr_msgs__srv__ConfigDiscreteOutput_Request;

// Struct for a sequence of kr_msgs__srv__ConfigDiscreteOutput_Request.
typedef struct kr_msgs__srv__ConfigDiscreteOutput_Request__Sequence
{
  kr_msgs__srv__ConfigDiscreteOutput_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__ConfigDiscreteOutput_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ConfigDiscreteOutput in the package kr_msgs.
typedef struct kr_msgs__srv__ConfigDiscreteOutput_Response
{
  bool success;
} kr_msgs__srv__ConfigDiscreteOutput_Response;

// Struct for a sequence of kr_msgs__srv__ConfigDiscreteOutput_Response.
typedef struct kr_msgs__srv__ConfigDiscreteOutput_Response__Sequence
{
  kr_msgs__srv__ConfigDiscreteOutput_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__ConfigDiscreteOutput_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__CONFIG_DISCRETE_OUTPUT__STRUCT_H_
