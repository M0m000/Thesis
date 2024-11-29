// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:srv/GetSystemLoad.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/srv/detail/get_system_load__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/srv/detail/get_system_load__functions.h"
#include "kr_msgs/srv/detail/get_system_load__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__GetSystemLoad_Request__init(message_memory);
}

void GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_fini_function(void * message_memory)
{
  kr_msgs__srv__GetSystemLoad_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_member_array[1] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetSystemLoad_Request, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_members = {
  "kr_msgs__srv",  // message namespace
  "GetSystemLoad_Request",  // message name
  1,  // number of fields
  sizeof(kr_msgs__srv__GetSystemLoad_Request),
  GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_member_array,  // message members
  GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_type_support_handle = {
  0,
  &GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSystemLoad_Request)() {
  if (!GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_type_support_handle.typesupport_identifier) {
    GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GetSystemLoad_Request__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/srv/detail/get_system_load__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/srv/detail/get_system_load__functions.h"
// already included above
// #include "kr_msgs/srv/detail/get_system_load__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__GetSystemLoad_Response__init(message_memory);
}

void GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_fini_function(void * message_memory)
{
  kr_msgs__srv__GetSystemLoad_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_member_array[4] = {
  {
    "mass",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetSystemLoad_Response, mass),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cog",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetSystemLoad_Response, cog),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetSystemLoad_Response, imx),  // bytes offset in struct
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
    offsetof(kr_msgs__srv__GetSystemLoad_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_members = {
  "kr_msgs__srv",  // message namespace
  "GetSystemLoad_Response",  // message name
  4,  // number of fields
  sizeof(kr_msgs__srv__GetSystemLoad_Response),
  GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_member_array,  // message members
  GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_type_support_handle = {
  0,
  &GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSystemLoad_Response)() {
  if (!GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_type_support_handle.typesupport_identifier) {
    GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GetSystemLoad_Response__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/srv/detail/get_system_load__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_service_members = {
  "kr_msgs__srv",  // service namespace
  "GetSystemLoad",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_service_type_support_handle = {
  0,
  &kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSystemLoad_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSystemLoad_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSystemLoad)() {
  if (!kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_service_type_support_handle.typesupport_identifier) {
    kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSystemLoad_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSystemLoad_Response)()->data;
  }

  return &kr_msgs__srv__detail__get_system_load__rosidl_typesupport_introspection_c__GetSystemLoad_service_type_support_handle;
}
