// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/GetDiscreteInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_DISCRETE_INPUT__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__GET_DISCRETE_INPUT__STRUCT_H_

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
  kr_msgs__srv__GetDiscreteInput_Request__OFF = 0
};

/// Constant 'ON'.
enum
{
  kr_msgs__srv__GetDiscreteInput_Request__ON = 1
};

// Struct defined in srv/GetDiscreteInput in the package kr_msgs.
typedef struct kr_msgs__srv__GetDiscreteInput_Request
{
  int8_t index;
} kr_msgs__srv__GetDiscreteInput_Request;

// Struct for a sequence of kr_msgs__srv__GetDiscreteInput_Request.
typedef struct kr_msgs__srv__GetDiscreteInput_Request__Sequence
{
  kr_msgs__srv__GetDiscreteInput_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetDiscreteInput_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/GetDiscreteInput in the package kr_msgs.
typedef struct kr_msgs__srv__GetDiscreteInput_Response
{
  int8_t value;
  bool success;
} kr_msgs__srv__GetDiscreteInput_Response;

// Struct for a sequence of kr_msgs__srv__GetDiscreteInput_Response.
typedef struct kr_msgs__srv__GetDiscreteInput_Response__Sequence
{
  kr_msgs__srv__GetDiscreteInput_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetDiscreteInput_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__GET_DISCRETE_INPUT__STRUCT_H_
