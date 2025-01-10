// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/ConfigQuadratureInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ConfigQuadratureInput in the package kr_msgs.
typedef struct kr_msgs__srv__ConfigQuadratureInput_Request
{
  int8_t index;
  int32_t pulse_per_rev;
  bool idx_availability;
} kr_msgs__srv__ConfigQuadratureInput_Request;

// Struct for a sequence of kr_msgs__srv__ConfigQuadratureInput_Request.
typedef struct kr_msgs__srv__ConfigQuadratureInput_Request__Sequence
{
  kr_msgs__srv__ConfigQuadratureInput_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__ConfigQuadratureInput_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ConfigQuadratureInput in the package kr_msgs.
typedef struct kr_msgs__srv__ConfigQuadratureInput_Response
{
  bool success;
} kr_msgs__srv__ConfigQuadratureInput_Response;

// Struct for a sequence of kr_msgs__srv__ConfigQuadratureInput_Response.
typedef struct kr_msgs__srv__ConfigQuadratureInput_Response__Sequence
{
  kr_msgs__srv__ConfigQuadratureInput_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__ConfigQuadratureInput_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__STRUCT_H_
