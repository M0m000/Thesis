// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:srv/ResumeProgram.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/srv/detail/resume_program__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/srv/detail/resume_program__functions.h"
#include "kr_msgs/srv/detail/resume_program__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__ResumeProgram_Request__init(message_memory);
}

void ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_fini_function(void * message_memory)
{
  kr_msgs__srv__ResumeProgram_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__ResumeProgram_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_members = {
  "kr_msgs__srv",  // message namespace
  "ResumeProgram_Request",  // message name
  1,  // number of fields
  sizeof(kr_msgs__srv__ResumeProgram_Request),
  ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_member_array,  // message members
  ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_type_support_handle = {
  0,
  &ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ResumeProgram_Request)() {
  if (!ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_type_support_handle.typesupport_identifier) {
    ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ResumeProgram_Request__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/srv/detail/resume_program__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/srv/detail/resume_program__functions.h"
// already included above
// #include "kr_msgs/srv/detail/resume_program__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__ResumeProgram_Response__init(message_memory);
}

void ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_fini_function(void * message_memory)
{
  kr_msgs__srv__ResumeProgram_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__ResumeProgram_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_members = {
  "kr_msgs__srv",  // message namespace
  "ResumeProgram_Response",  // message name
  1,  // number of fields
  sizeof(kr_msgs__srv__ResumeProgram_Response),
  ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_member_array,  // message members
  ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_type_support_handle = {
  0,
  &ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ResumeProgram_Response)() {
  if (!ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_type_support_handle.typesupport_identifier) {
    ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ResumeProgram_Response__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/srv/detail/resume_program__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_service_members = {
  "kr_msgs__srv",  // service namespace
  "ResumeProgram",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_service_type_support_handle = {
  0,
  &kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ResumeProgram_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ResumeProgram_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ResumeProgram)() {
  if (!kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_service_type_support_handle.typesupport_identifier) {
    kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ResumeProgram_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, ResumeProgram_Response)()->data;
  }

  return &kr_msgs__srv__detail__resume_program__rosidl_typesupport_introspection_c__ResumeProgram_service_type_support_handle;
}
