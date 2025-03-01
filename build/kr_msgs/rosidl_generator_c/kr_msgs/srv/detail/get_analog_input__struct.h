// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/GetAnalogInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_ANALOG_INPUT__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__GET_ANALOG_INPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetAnalogInput in the package kr_msgs.
typedef struct kr_msgs__srv__GetAnalogInput_Request
{
  int8_t index;
} kr_msgs__srv__GetAnalogInput_Request;

// Struct for a sequence of kr_msgs__srv__GetAnalogInput_Request.
typedef struct kr_msgs__srv__GetAnalogInput_Request__Sequence
{
  kr_msgs__srv__GetAnalogInput_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetAnalogInput_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/GetAnalogInput in the package kr_msgs.
typedef struct kr_msgs__srv__GetAnalogInput_Response
{
  float value;
  bool success;
} kr_msgs__srv__GetAnalogInput_Response;

// Struct for a sequence of kr_msgs__srv__GetAnalogInput_Response.
typedef struct kr_msgs__srv__GetAnalogInput_Response__Sequence
{
  kr_msgs__srv__GetAnalogInput_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetAnalogInput_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__GET_ANALOG_INPUT__STRUCT_H_
