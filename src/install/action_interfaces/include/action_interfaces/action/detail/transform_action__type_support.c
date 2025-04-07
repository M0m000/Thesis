// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from action_interfaces:action/TransformAction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
#include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "action_interfaces/action/detail/transform_action__functions.h"
#include "action_interfaces/action/detail/transform_action__struct.h"


// Include directives for member types
// Member `ref_frame`
// Member `frame`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_Goal__init(message_memory);
}

void TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_member_array[2] = {
  {
    "ref_frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_Goal, ref_frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_Goal, frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_Goal",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__TransformAction_Goal),
  TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_member_array,  // message members
  TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_type_support_handle = {
  0,
  &TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_Goal)() {
  if (!TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_type_support_handle.typesupport_identifier) {
    TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_Goal__rosidl_typesupport_introspection_c__TransformAction_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__functions.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__struct.h"


// Include directives for member types
// Member `transform`
#include "geometry_msgs/msg/transform_stamped.h"
// Member `transform`
#include "geometry_msgs/msg/detail/transform_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_Result__init(message_memory);
}

void TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_member_array[1] = {
  {
    "transform",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_Result, transform),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_Result",  // message name
  1,  // number of fields
  sizeof(action_interfaces__action__TransformAction_Result),
  TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_member_array,  // message members
  TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_type_support_handle = {
  0,
  &TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_Result)() {
  TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, TransformStamped)();
  if (!TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_type_support_handle.typesupport_identifier) {
    TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_Result__rosidl_typesupport_introspection_c__TransformAction_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__functions.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__struct.h"


// Include directives for member types
// Member `status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_Feedback__init(message_memory);
}

void TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_member_array[1] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_Feedback, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_Feedback",  // message name
  1,  // number of fields
  sizeof(action_interfaces__action__TransformAction_Feedback),
  TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_member_array,  // message members
  TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_type_support_handle = {
  0,
  &TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_Feedback)() {
  if (!TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_type_support_handle.typesupport_identifier) {
    TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_Feedback__rosidl_typesupport_introspection_c__TransformAction_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__functions.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "action_interfaces/action/transform_action.h"
// Member `goal`
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_SendGoal_Request__init(message_memory);
}

void TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_SendGoal_Request, goal_id),  // bytes offset in struct
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
    offsetof(action_interfaces__action__TransformAction_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__TransformAction_SendGoal_Request),
  TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_member_array,  // message members
  TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_type_support_handle = {
  0,
  &TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_SendGoal_Request)() {
  TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_Goal)();
  if (!TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_SendGoal_Request__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__functions.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_SendGoal_Response__init(message_memory);
}

void TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_SendGoal_Response, accepted),  // bytes offset in struct
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
    offsetof(action_interfaces__action__TransformAction_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__TransformAction_SendGoal_Response),
  TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_member_array,  // message members
  TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_type_support_handle = {
  0,
  &TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_SendGoal_Response)() {
  TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_SendGoal_Response__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_service_members = {
  "action_interfaces__action",  // service namespace
  "TransformAction_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_service_type_support_handle = {
  0,
  &action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_SendGoal)() {
  if (!action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_service_type_support_handle.typesupport_identifier) {
    action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_SendGoal_Response)()->data;
  }

  return &action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__functions.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__struct.h"


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

void TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_GetResult_Request__init(message_memory);
}

void TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(action_interfaces__action__TransformAction_GetResult_Request),
  TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_member_array,  // message members
  TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_type_support_handle = {
  0,
  &TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_GetResult_Request)() {
  TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_GetResult_Request__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__functions.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "action_interfaces/action/transform_action.h"
// Member `result`
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_GetResult_Response__init(message_memory);
}

void TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_GetResult_Response, status),  // bytes offset in struct
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
    offsetof(action_interfaces__action__TransformAction_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__TransformAction_GetResult_Response),
  TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_member_array,  // message members
  TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_type_support_handle = {
  0,
  &TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_GetResult_Response)() {
  TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_Result)();
  if (!TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_GetResult_Response__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_service_members = {
  "action_interfaces__action",  // service namespace
  "TransformAction_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_service_type_support_handle = {
  0,
  &action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_GetResult)() {
  if (!action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_service_type_support_handle.typesupport_identifier) {
    action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_GetResult_Response)()->data;
  }

  return &action_interfaces__action__detail__transform_action__rosidl_typesupport_introspection_c__TransformAction_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__functions.h"
// already included above
// #include "action_interfaces/action/detail/transform_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "action_interfaces/action/transform_action.h"
// Member `feedback`
// already included above
// #include "action_interfaces/action/detail/transform_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__action__TransformAction_FeedbackMessage__init(message_memory);
}

void TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_fini_function(void * message_memory)
{
  action_interfaces__action__TransformAction_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__action__TransformAction_FeedbackMessage, goal_id),  // bytes offset in struct
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
    offsetof(action_interfaces__action__TransformAction_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_members = {
  "action_interfaces__action",  // message namespace
  "TransformAction_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(action_interfaces__action__TransformAction_FeedbackMessage),
  TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_member_array,  // message members
  TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_type_support_handle = {
  0,
  &TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_FeedbackMessage)() {
  TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, action, TransformAction_Feedback)();
  if (!TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TransformAction_FeedbackMessage__rosidl_typesupport_introspection_c__TransformAction_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
