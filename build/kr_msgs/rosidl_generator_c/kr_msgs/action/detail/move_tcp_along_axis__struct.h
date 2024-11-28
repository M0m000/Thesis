// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:action/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_H_
#define KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'movement_frame'
// Member 'movement_axis'
#include "rosidl_runtime_c/string.h"

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_Goal
{
  double baseline;
  rosidl_runtime_c__String movement_frame;
  rosidl_runtime_c__String movement_axis;
} kr_msgs__action__MoveTCPAlongAxis_Goal;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_Goal.
typedef struct kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence;


// Constants defined in the message

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_Result
{
  double current_time;
} kr_msgs__action__MoveTCPAlongAxis_Result;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_Result.
typedef struct kr_msgs__action__MoveTCPAlongAxis_Result__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_Result__Sequence;


// Constants defined in the message

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_Feedback
{
  bool success;
} kr_msgs__action__MoveTCPAlongAxis_Feedback;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_Feedback.
typedef struct kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  kr_msgs__action__MoveTCPAlongAxis_Goal goal;
} kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request.
typedef struct kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response.
typedef struct kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} kr_msgs__action__MoveTCPAlongAxis_GetResult_Request;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_GetResult_Request.
typedef struct kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_GetResult_Response
{
  int8_t status;
  kr_msgs__action__MoveTCPAlongAxis_Result result;
} kr_msgs__action__MoveTCPAlongAxis_GetResult_Response;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_GetResult_Response.
typedef struct kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"

// Struct defined in action/MoveTCPAlongAxis in the package kr_msgs.
typedef struct kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  kr_msgs__action__MoveTCPAlongAxis_Feedback feedback;
} kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage;

// Struct for a sequence of kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage.
typedef struct kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence
{
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_H_
