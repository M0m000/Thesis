// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:srv/GetRobotState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/srv/detail/get_robot_state__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/srv/detail/get_robot_state__functions.h"
#include "kr_msgs/srv/detail/get_robot_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__GetRobotState_Request__init(message_memory);
}

void GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_fini_function(void * message_memory)
{
  kr_msgs__srv__GetRobotState_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetRobotState_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_members = {
  "kr_msgs__srv",  // message namespace
  "GetRobotState_Request",  // message name
  1,  // number of fields
  sizeof(kr_msgs__srv__GetRobotState_Request),
  GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_member_array,  // message members
  GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_type_support_handle = {
  0,
  &GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetRobotState_Request)() {
  if (!GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_type_support_handle.typesupport_identifier) {
    GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GetRobotState_Request__rosidl_typesupport_introspection_c__GetRobotState_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/srv/detail/get_robot_state__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/srv/detail/get_robot_state__functions.h"
// already included above
// #include "kr_msgs/srv/detail/get_robot_state__struct.h"


// Include directives for member types
// Member `state`
#include "kr_msgs/msg/robot_state.h"
// Member `state`
#include "kr_msgs/msg/detail/robot_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__GetRobotState_Response__init(message_memory);
}

void GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_fini_function(void * message_memory)
{
  kr_msgs__srv__GetRobotState_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_member_array[2] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetRobotState_Response, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetRobotState_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_members = {
  "kr_msgs__srv",  // message namespace
  "GetRobotState_Response",  // message name
  2,  // number of fields
  sizeof(kr_msgs__srv__GetRobotState_Response),
  GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_member_array,  // message members
  GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_type_support_handle = {
  0,
  &GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetRobotState_Response)() {
  GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, msg, RobotState)();
  if (!GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_type_support_handle.typesupport_identifier) {
    GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GetRobotState_Response__rosidl_typesupport_introspection_c__GetRobotState_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/srv/detail/get_robot_state__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_service_members = {
  "kr_msgs__srv",  // service namespace
  "GetRobotState",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_service_type_support_handle = {
  0,
  &kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetRobotState_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetRobotState_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetRobotState)() {
  if (!kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_service_type_support_handle.typesupport_identifier) {
    kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetRobotState_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetRobotState_Response)()->data;
  }

  return &kr_msgs__srv__detail__get_robot_state__rosidl_typesupport_introspection_c__GetRobotState_service_type_support_handle;
}
