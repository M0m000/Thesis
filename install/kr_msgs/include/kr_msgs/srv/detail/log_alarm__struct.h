// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/LogAlarm.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__LOG_ALARM__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__LOG_ALARM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/LogAlarm in the package kr_msgs.
typedef struct kr_msgs__srv__LogAlarm_Request
{
  uint8_t structure_needs_at_least_one_member;
} kr_msgs__srv__LogAlarm_Request;

// Struct for a sequence of kr_msgs__srv__LogAlarm_Request.
typedef struct kr_msgs__srv__LogAlarm_Request__Sequence
{
  kr_msgs__srv__LogAlarm_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__LogAlarm_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'safety_events'
#include "kr_msgs/msg/detail/safety_event__struct.h"

// Struct defined in srv/LogAlarm in the package kr_msgs.
typedef struct kr_msgs__srv__LogAlarm_Response
{
  kr_msgs__msg__SafetyEvent__Sequence safety_events;
  bool success;
} kr_msgs__srv__LogAlarm_Response;

// Struct for a sequence of kr_msgs__srv__LogAlarm_Response.
typedef struct kr_msgs__srv__LogAlarm_Response__Sequence
{
  kr_msgs__srv__LogAlarm_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__LogAlarm_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__LOG_ALARM__STRUCT_H_
