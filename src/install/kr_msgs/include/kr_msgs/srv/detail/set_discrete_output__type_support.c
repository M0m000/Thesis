// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:srv/SetDiscreteOutput.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/srv/detail/set_discrete_output__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/srv/detail/set_discrete_output__functions.h"
#include "kr_msgs/srv/detail/set_discrete_output__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__SetDiscreteOutput_Request__init(message_memory);
}

void SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_fini_function(void * message_memory)
{
  kr_msgs__srv__SetDiscreteOutput_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_member_array[2] = {
  {
    "index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__SetDiscreteOutput_Request, index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__SetDiscreteOutput_Request, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_members = {
  "kr_msgs__srv",  // message namespace
  "SetDiscreteOutput_Request",  // message name
  2,  // number of fields
  sizeof(kr_msgs__srv__SetDiscreteOutput_Request),
  SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_member_array,  // message members
  SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_type_support_handle = {
  0,
  &SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, SetDiscreteOutput_Request)() {
  if (!SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_type_support_handle.typesupport_identifier) {
    SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SetDiscreteOutput_Request__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/srv/detail/set_discrete_output__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/srv/detail/set_discrete_output__functions.h"
// already included above
// #include "kr_msgs/srv/detail/set_discrete_output__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__SetDiscreteOutput_Response__init(message_memory);
}

void SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_fini_function(void * message_memory)
{
  kr_msgs__srv__SetDiscreteOutput_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__SetDiscreteOutput_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_members = {
  "kr_msgs__srv",  // message namespace
  "SetDiscreteOutput_Response",  // message name
  1,  // number of fields
  sizeof(kr_msgs__srv__SetDiscreteOutput_Response),
  SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_member_array,  // message members
  SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_type_support_handle = {
  0,
  &SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, SetDiscreteOutput_Response)() {
  if (!SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_type_support_handle.typesupport_identifier) {
    SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SetDiscreteOutput_Response__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/srv/detail/set_discrete_output__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_service_members = {
  "kr_msgs__srv",  // service namespace
  "SetDiscreteOutput",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_service_type_support_handle = {
  0,
  &kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, SetDiscreteOutput_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, SetDiscreteOutput_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, SetDiscreteOutput)() {
  if (!kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_service_type_support_handle.typesupport_identifier) {
    kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, SetDiscreteOutput_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, SetDiscreteOutput_Response)()->data;
  }

  return &kr_msgs__srv__detail__set_discrete_output__rosidl_typesupport_introspection_c__SetDiscreteOutput_service_type_support_handle;
}