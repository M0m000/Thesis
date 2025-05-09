// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/PauseProgram.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__PAUSE_PROGRAM__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__PAUSE_PROGRAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/PauseProgram in the package kr_msgs.
typedef struct kr_msgs__srv__PauseProgram_Request
{
  uint8_t structure_needs_at_least_one_member;
} kr_msgs__srv__PauseProgram_Request;

// Struct for a sequence of kr_msgs__srv__PauseProgram_Request.
typedef struct kr_msgs__srv__PauseProgram_Request__Sequence
{
  kr_msgs__srv__PauseProgram_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__PauseProgram_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/PauseProgram in the package kr_msgs.
typedef struct kr_msgs__srv__PauseProgram_Response
{
  bool success;
} kr_msgs__srv__PauseProgram_Response;

// Struct for a sequence of kr_msgs__srv__PauseProgram_Response.
typedef struct kr_msgs__srv__PauseProgram_Response__Sequence
{
  kr_msgs__srv__PauseProgram_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__PauseProgram_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__PAUSE_PROGRAM__STRUCT_H_
