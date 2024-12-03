// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from action_interfaces:action/MoveTcpAlongAxis.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
#include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
#include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `movement_frame`
// Member `movement_axis`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_Goal__init(message_memory);
}

void MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_member_array[3] = {
  {
    "baseline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_Goal, baseline),  // bytes offset in struct
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
    offsetof(action_interfaces__action__MoveTcpAlongAxis_Goal, movement_frame),  // bytes offset in struct
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
    offsetof(action_interfaces__action__MoveTcpAlongAxis_Goal, movement_axis),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_Goal",  // message name
  3,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_Goal),
  MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_member_array,  // message members
  MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_Goal)() {
  if (!MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_Goal__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_Result__init(message_memory);
}

void MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_Result",  // message name
  1,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_Result),
  MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_member_array,  // message members
  MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_Result)() {
  if (!MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_Result__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_Feedback__init(message_memory);
}

void MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_member_array[1] = {
  {
    "current_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_Feedback, current_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_Feedback",  // message name
  1,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_Feedback),
  MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_member_array,  // message members
  MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_Feedback)() {
  if (!MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_Feedback__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "action_interfaces/action/move_tcp_along_axis.h"
// Member `goal`
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request__init(message_memory);
}

void MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request, goal_id),  // bytes offset in struct
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
    offsetof(action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_SendGoal_Request),
  MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_member_array,  // message members
  MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_SendGoal_Request)() {
  MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_Goal)();
  if (!MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_SendGoal_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response__init(message_memory);
}

void MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response, accepted),  // bytes offset in struct
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
    offsetof(action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_SendGoal_Response),
  MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_member_array,  // message members
  MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_SendGoal_Response)() {
  MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_SendGoal_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_service_members = {
  "action_interfaces__action",  // service namespace
  "MoveTcpAlongAxis_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_service_type_support_handle = {
  0,
  &action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_SendGoal)() {
  if (!action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_service_type_support_handle.typesupport_identifier) {
    action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_SendGoal_Response)()->data;
  }

  return &action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


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

void MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_GetResult_Request__init(message_memory);
}

void MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_GetResult_Request),
  MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_member_array,  // message members
  MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_GetResult_Request)() {
  MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_GetResult_Request__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "action_interfaces/action/move_tcp_along_axis.h"
// Member `result`
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_GetResult_Response__init(message_memory);
}

void MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_GetResult_Response, status),  // bytes offset in struct
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
    offsetof(action_interfaces__action__MoveTcpAlongAxis_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_GetResult_Response),
  MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_member_array,  // message members
  MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_GetResult_Response)() {
  MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_Result)();
  if (!MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_GetResult_Response__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_service_members = {
  "action_interfaces__action",  // service namespace
  "MoveTcpAlongAxis_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_service_type_support_handle = {
  0,
  &action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_GetResult)() {
  if (!action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_service_type_support_handle.typesupport_identifier) {
    action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_GetResult_Response)()->data;
  }

  return &action_interfaces__action__detail__move_tcp_along_axis__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__functions.h"
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "action_interfaces/action/move_tcp_along_axis.h"
// Member `feedback`
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage__init(message_memory);
}

void MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_fini_function(void * message_memory)
{
  action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage, goal_id),  // bytes offset in struct
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
    offsetof(action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_members = {
  "action_interfaces__action",  // message namespace
  "MoveTcpAlongAxis_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__MoveTcpAlongAxis_FeedbackMessage),
  MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_member_array,  // message members
  MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_type_support_handle = {
  0,
  &MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_FeedbackMessage)() {
  MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, MoveTcpAlongAxis_Feedback)();
  if (!MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveTcpAlongAxis_FeedbackMessage__rosidl_typesupport_introspection_c__MoveTcpAlongAxis_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
