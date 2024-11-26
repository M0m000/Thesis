// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/SelectJoggingFrame.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'WORLD'.
enum
{
  kr_msgs__srv__SelectJoggingFrame_Request__WORLD = 0
};

/// Constant 'BASE'.
enum
{
  kr_msgs__srv__SelectJoggingFrame_Request__BASE = 1
};

/// Constant 'TCP'.
enum
{
  kr_msgs__srv__SelectJoggingFrame_Request__TCP = 2
};

// Struct defined in srv/SelectJoggingFrame in the package kr_msgs.
typedef struct kr_msgs__srv__SelectJoggingFrame_Request
{
  int8_t ref;
} kr_msgs__srv__SelectJoggingFrame_Request;

// Struct for a sequence of kr_msgs__srv__SelectJoggingFrame_Request.
typedef struct kr_msgs__srv__SelectJoggingFrame_Request__Sequence
{
  kr_msgs__srv__SelectJoggingFrame_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SelectJoggingFrame_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SelectJoggingFrame in the package kr_msgs.
typedef struct kr_msgs__srv__SelectJoggingFrame_Response
{
  bool success;
} kr_msgs__srv__SelectJoggingFrame_Response;

// Struct for a sequence of kr_msgs__srv__SelectJoggingFrame_Response.
typedef struct kr_msgs__srv__SelectJoggingFrame_Response__Sequence
{
  kr_msgs__srv__SelectJoggingFrame_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__SelectJoggingFrame_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__STRUCT_H_
