// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/GetProgramState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_PROGRAM_STATE__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__GET_PROGRAM_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetProgramState in the package kr_msgs.
typedef struct kr_msgs__srv__GetProgramState_Request
{
  uint8_t structure_needs_at_least_one_member;
} kr_msgs__srv__GetProgramState_Request;

// Struct for a sequence of kr_msgs__srv__GetProgramState_Request.
typedef struct kr_msgs__srv__GetProgramState_Request__Sequence
{
  kr_msgs__srv__GetProgramState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetProgramState_Request__Sequence;


// Constants defined in the message

/// Constant 'NONE'.
enum
{
  kr_msgs__srv__GetProgramState_Response__NONE = 0
};

/// Constant 'RUNNING'.
enum
{
  kr_msgs__srv__GetProgramState_Response__RUNNING = 1
};

/// Constant 'PAUSED'.
enum
{
  kr_msgs__srv__GetProgramState_Response__PAUSED = 2
};

/// Constant 'HALTED'.
enum
{
  kr_msgs__srv__GetProgramState_Response__HALTED = 3
};

// Struct defined in srv/GetProgramState in the package kr_msgs.
typedef struct kr_msgs__srv__GetProgramState_Response
{
  uint32_t state;
  bool success;
} kr_msgs__srv__GetProgramState_Response;

// Struct for a sequence of kr_msgs__srv__GetProgramState_Response.
typedef struct kr_msgs__srv__GetProgramState_Response__Sequence
{
  kr_msgs__srv__GetProgramState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__GetProgramState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__GET_PROGRAM_STATE__STRUCT_H_
