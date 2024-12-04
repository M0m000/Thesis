// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:action/MoveTcpAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_H_
#define ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_H_

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

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_Goal
{
  double baseline;
  rosidl_runtime_c__String movement_frame;
  rosidl_runtime_c__String movement_axis;
  double speed_in_mm_per_s;
} action_interfaces__action__MoveTcpAlongAxis_Goal;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_Goal.
typedef struct action_interfaces__action__MoveTcpAlongAxis_Goal__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_Goal__Sequence;


// Constants defined in the message

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_Result
{
  bool success;
} action_interfaces__action__MoveTcpAlongAxis_Result;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_Result.
typedef struct action_interfaces__action__MoveTcpAlongAxis_Result__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_position'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_Feedback
{
  rosidl_runtime_c__double__Sequence current_position;
  double current_diff;
} action_interfaces__action__MoveTcpAlongAxis_Feedback;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_Feedback.
typedef struct action_interfaces__action__MoveTcpAlongAxis_Feedback__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interfaces__action__MoveTcpAlongAxis_Goal goal;
} action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request.
typedef struct action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response.
typedef struct action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} action_interfaces__action__MoveTcpAlongAxis_GetResult_Request;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_GetResult_Request.
typedef struct action_interfaces__action__MoveTcpAlongAxis_GetResult_Request__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_GetResult_Response
{
  int8_t status;
  action_interfaces__action__MoveTcpAlongAxis_Result result;
} action_interfaces__action__MoveTcpAlongAxis_GetResult_Response;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_GetResult_Response.
typedef struct action_interfaces__action__MoveTcpAlongAxis_GetResult_Response__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"

// Struct defined in action/MoveTcpAlongAxis in the package action_interfaces.
typedef struct action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interfaces__action__MoveTcpAlongAxis_Feedback feedback;
} action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage;

// Struct for a sequence of action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage.
typedef struct action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage__Sequence
{
  action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_H_
