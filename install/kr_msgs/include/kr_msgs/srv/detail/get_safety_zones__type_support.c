// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:srv/GetSafetyZones.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/srv/detail/get_safety_zones__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/srv/detail/get_safety_zones__functions.h"
#include "kr_msgs/srv/detail/get_safety_zones__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__GetSafetyZones_Request__init(message_memory);
}

void GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_fini_function(void * message_memory)
{
  kr_msgs__srv__GetSafetyZones_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetSafetyZones_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_members = {
  "kr_msgs__srv",  // message namespace
  "GetSafetyZones_Request",  // message name
  1,  // number of fields
  sizeof(kr_msgs__srv__GetSafetyZones_Request),
  GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_member_array,  // message members
  GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_type_support_handle = {
  0,
  &GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSafetyZones_Request)() {
  if (!GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_type_support_handle.typesupport_identifier) {
    GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GetSafetyZones_Request__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kr_msgs/srv/detail/get_safety_zones__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kr_msgs/srv/detail/get_safety_zones__functions.h"
// already included above
// #include "kr_msgs/srv/detail/get_safety_zones__struct.h"


// Include directives for member types
// Member `zones`
#include "kr_msgs/msg/safety_zone.h"
// Member `zones`
#include "kr_msgs/msg/detail/safety_zone__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__srv__GetSafetyZones_Response__init(message_memory);
}

void GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_fini_function(void * message_memory)
{
  kr_msgs__srv__GetSafetyZones_Response__fini(message_memory);
}

size_t GetSafetyZones_Response__rosidl_typesupport_introspection_c__size_function__SafetyZone__zones(
  const void * untyped_member)
{
  const kr_msgs__msg__SafetyZone__Sequence * member =
    (const kr_msgs__msg__SafetyZone__Sequence *)(untyped_member);
  return member->size;
}

const void * GetSafetyZones_Response__rosidl_typesupport_introspection_c__get_const_function__SafetyZone__zones(
  const void * untyped_member, size_t index)
{
  const kr_msgs__msg__SafetyZone__Sequence * member =
    (const kr_msgs__msg__SafetyZone__Sequence *)(untyped_member);
  return &member->data[index];
}

void * GetSafetyZones_Response__rosidl_typesupport_introspection_c__get_function__SafetyZone__zones(
  void * untyped_member, size_t index)
{
  kr_msgs__msg__SafetyZone__Sequence * member =
    (kr_msgs__msg__SafetyZone__Sequence *)(untyped_member);
  return &member->data[index];
}

bool GetSafetyZones_Response__rosidl_typesupport_introspection_c__resize_function__SafetyZone__zones(
  void * untyped_member, size_t size)
{
  kr_msgs__msg__SafetyZone__Sequence * member =
    (kr_msgs__msg__SafetyZone__Sequence *)(untyped_member);
  kr_msgs__msg__SafetyZone__Sequence__fini(member);
  return kr_msgs__msg__SafetyZone__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_member_array[2] = {
  {
    "zones",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetSafetyZones_Response, zones),  // bytes offset in struct
    NULL,  // default value
    GetSafetyZones_Response__rosidl_typesupport_introspection_c__size_function__SafetyZone__zones,  // size() function pointer
    GetSafetyZones_Response__rosidl_typesupport_introspection_c__get_const_function__SafetyZone__zones,  // get_const(index) function pointer
    GetSafetyZones_Response__rosidl_typesupport_introspection_c__get_function__SafetyZone__zones,  // get(index) function pointer
    GetSafetyZones_Response__rosidl_typesupport_introspection_c__resize_function__SafetyZone__zones  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__srv__GetSafetyZones_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_members = {
  "kr_msgs__srv",  // message namespace
  "GetSafetyZones_Response",  // message name
  2,  // number of fields
  sizeof(kr_msgs__srv__GetSafetyZones_Response),
  GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_member_array,  // message members
  GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_type_support_handle = {
  0,
  &GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSafetyZones_Response)() {
  GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, msg, SafetyZone)();
  if (!GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_type_support_handle.typesupport_identifier) {
    GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GetSafetyZones_Response__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kr_msgs/srv/detail/get_safety_zones__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_service_members = {
  "kr_msgs__srv",  // service namespace
  "GetSafetyZones",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_Request_message_type_support_handle,
  NULL  // response message
  // kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_Response_message_type_support_handle
};

static rosidl_service_type_support_t kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_service_type_support_handle = {
  0,
  &kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSafetyZones_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSafetyZones_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSafetyZones)() {
  if (!kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_service_type_support_handle.typesupport_identifier) {
    kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSafetyZones_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, srv, GetSafetyZones_Response)()->data;
  }

  return &kr_msgs__srv__detail__get_safety_zones__rosidl_typesupport_introspection_c__GetSafetyZones_service_type_support_handle;
}
