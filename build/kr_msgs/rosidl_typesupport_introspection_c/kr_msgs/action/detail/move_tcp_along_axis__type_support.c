// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:action/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
#include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `movement_frame`
// Member `movement_axis`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_Goal__init(message_memory);
}

void MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_member_array[3] = {
  {
    "baseline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_Goal, baseline),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "movement_frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_Goal, movement_frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "movement_axis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_Goal, movement_axis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_Goal",  // message name
  3,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_Goal),
  MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_member_array,  // message members
  MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_Goal)() {
  if (!MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_Result__init(message_memory);
}

void MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_member_array[1] = {
  {
    "current_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_Result, current_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_Result",  // message name
  1,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_Result),
  MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_member_array,  // message members
  MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_Result)() {
  if (!MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_Feedback__init(message_memory);
}

void MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_Feedback, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_Feedback",  // message name
  1,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_Feedback),
  MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_member_array,  // message members
  MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_Feedback)() {
  if (!MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "kr_msgs/action/move_tcp_along_axis.h"
// Member `goal`
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init(message_memory);
}

void MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request),
  MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_member_array,  // message members
  MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_SendGoal_Request)() {
  MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_Goal)();
  if (!MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init(message_memory);
}

void MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response),
  MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_member_array,  // message members
  MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_SendGoal_Response)() {
  MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_service_members = {
  "kr_msgs__action",  // service namespace
  "MoveTCPAlongAxis_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_service_type_support_handle = {
  0,
  &kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_SendGoal)() {
  if (!kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_service_type_support_handle.typesupport_identifier) {
    kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_SendGoal_Response)()->data;
  }

  return &kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init(message_memory);
}

void MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request),
  MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_member_array,  // message members
  MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_GetResult_Request)() {
  MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "kr_msgs/action/move_tcp_along_axis.h"
// Member `result`
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init(message_memory);
}

void MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response),
  MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_member_array,  // message members
  MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_GetResult_Response)() {
  MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_Result)();
  if (!MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_service_members = {
  "kr_msgs__action",  // service namespace
  "MoveTCPAlongAxis_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_service_type_support_handle = {
  0,
  &kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_GetResult)() {
  if (!kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_service_type_support_handle.typesupport_identifier) {
    kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_GetResult_Response)()->data;
  }

  return &kr_msgs__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "kr_msgs/action/move_tcp_along_axis.h"
// Member `feedback`
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init(message_memory);
}

void MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_fini_function(void * message_memory)
{
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_members = {
  "kr_msgs__action",  // message namespace
  "MoveTCPAlongAxis_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage),
  MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_member_array,  // message members
  MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_type_support_handle = {
  0,
  &MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_FeedbackMessage)() {
  MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, action, MoveTCPAlongAxis_Feedback)();
  if (!MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTCPAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTCPAlongAxis_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
