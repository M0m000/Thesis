// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:srv/ConfigAnalogOutput.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/srv/detail/config_analog_output__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/srv/detail/config_analog_output__functions.h"
#include "kr_msgs/srv/detail/config_analog_output__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__ConfigAnalogOutput_Request__init(message_memory);
}

void ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_fini_function(void * message_memory)
{
  kr_msgs__srv__ConfigAnalogOutput_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_member_array[2] = {
  {
    "index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__ConfigAnalogOutput_Request, index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__ConfigAnalogOutput_Request, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_members = {
  "kr_msgs__srv",  // message namespace
  "ConfigAnalogOutput_Request",  // message name
  2,  // number of fields
  sizeof(kr_msgs__srv__ConfigAnalogOutput_Request),
  ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_member_array,  // message members
  ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_type_support_handle = {
  0,
  &ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ConfigAnalogOutput_Request)() {
  if (!ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_type_support_handle.typesupport_identifier) {
    ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ConfigAnalogOutput_Request__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/srv/detail/config_analog_output__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/srv/detail/config_analog_output__functions.h"
// already included above
// #include "kr_msgs/srv/detail/config_analog_output__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__ConfigAnalogOutput_Response__init(message_memory);
}

void ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_fini_function(void * message_memory)
{
  kr_msgs__srv__ConfigAnalogOutput_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__ConfigAnalogOutput_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_members = {
  "kr_msgs__srv",  // message namespace
  "ConfigAnalogOutput_Response",  // message name
  1,  // number of fields
  sizeof(kr_msgs__srv__ConfigAnalogOutput_Response),
  ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_member_array,  // message members
  ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_type_support_handle = {
  0,
  &ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ConfigAnalogOutput_Response)() {
  if (!ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_type_support_handle.typesupport_identifier) {
    ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ConfigAnalogOutput_Response__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/srv/detail/config_analog_output__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_service_members = {
  "kr_msgs__srv",  // service namespace
  "ConfigAnalogOutput",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_service_type_support_handle = {
  0,
  &kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ConfigAnalogOutput_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ConfigAnalogOutput_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ConfigAnalogOutput)() {
  if (!kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_service_type_support_handle.typesupport_identifier) {
    kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ConfigAnalogOutput_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ConfigAnalogOutput_Response)()->data;
  }

  return &kr_msgs__srv__detail__config_analog_output__rosidl_typesupport_introspection_c__ConfigAnalogOutput_service_type_support_handle;
}
