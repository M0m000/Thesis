// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from action_interfaces:srv/GenerateFrame.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "action_interfaces/srv/detail/generate_frame__rosidl_typesupport_introspection_c.h"
#include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "action_interfaces/srv/detail/generate_frame__functions.h"
#include "action_interfaces/srv/detail/generate_frame__struct.h"


// Include directives for member types
// Member `frame_new`
// Member `frame_ref`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__srv__GenerateFrame_Request__init(message_memory);
}

void GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_fini_function(void * message_memory)
{
  action_interfaces__srv__GenerateFrame_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_member_array[4] = {
  {
    "frame_new",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__srv__GenerateFrame_Request, frame_new),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_ref",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__srv__GenerateFrame_Request, frame_ref),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "translation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__srv__GenerateFrame_Request, translation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotation_rpy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__srv__GenerateFrame_Request, rotation_rpy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_members = {
  "action_interfaces__srv",  // message namespace
  "GenerateFrame_Request",  // message name
  4,  // number of fields
  sizeof(action_interfaces__srv__GenerateFrame_Request),
  GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_member_array,  // message members
  GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_type_support_handle = {
  0,
  &GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, srv, GenerateFrame_Request)() {
  if (!GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_type_support_handle.typesupport_identifier) {
    GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GenerateFrame_Request__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interfaces/srv/detail/generate_frame__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interfaces/srv/detail/generate_frame__functions.h"
// already included above
// #include "action_interfaces/srv/detail/generate_frame__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__srv__GenerateFrame_Response__init(message_memory);
}

void GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_fini_function(void * message_memory)
{
  action_interfaces__srv__GenerateFrame_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__srv__GenerateFrame_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__srv__GenerateFrame_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_members = {
  "action_interfaces__srv",  // message namespace
  "GenerateFrame_Response",  // message name
  2,  // number of fields
  sizeof(action_interfaces__srv__GenerateFrame_Response),
  GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_member_array,  // message members
  GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_type_support_handle = {
  0,
  &GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, srv, GenerateFrame_Response)() {
  if (!GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_type_support_handle.typesupport_identifier) {
    GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GenerateFrame_Response__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "action_interfaces/srv/detail/generate_frame__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_service_members = {
  "action_interfaces__srv",  // service namespace
  "GenerateFrame",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_Request_message_type_support_handle,
  NULL  // response message
  // action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_Response_message_type_support_handle
};

static rosidl_service_type_support_t action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_service_type_support_handle = {
  0,
  &action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, srv, GenerateFrame_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, srv, GenerateFrame_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, srv, GenerateFrame)() {
  if (!action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_service_type_support_handle.typesupport_identifier) {
    action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, srv, GenerateFrame_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, srv, GenerateFrame_Response)()->data;
  }

  return &action_interfaces__srv__detail__generate_frame__rosidl_typesupport_introspection_c__GenerateFrame_service_type_support_handle;
}