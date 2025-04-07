// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/msg/detail/safety_zone__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/msg/detail/safety_zone__functions.h"
#include "kr_msgs/msg/detail/safety_zone__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `planes`
#include "kr_msgs/msg/geometry_plane.h"
// Member `planes`
#include "kr_msgs/msg/detail/geometry_plane__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__msg__SafetyZone__init(message_memory);
}

void SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_fini_function(void * message_memory)
{
  kr_msgs__msg__SafetyZone__fini(message_memory);
}

size_t SafetyZone__rosidl_typesupport_introspection_c__size_function__GeometryPlane__planes(
  const void * untyped_member)
{
  const kr_msgs__msg__GeometryPlane__Sequence * member =
    (const kr_msgs__msg__GeometryPlane__Sequence *)(untyped_member);
  return member->size;
}

const void * SafetyZone__rosidl_typesupport_introspection_c__get_const_function__GeometryPlane__planes(
  const void * untyped_member, size_t index)
{
  const kr_msgs__msg__GeometryPlane__Sequence * member =
    (const kr_msgs__msg__GeometryPlane__Sequence *)(untyped_member);
  return &member->data[index];
}

void * SafetyZone__rosidl_typesupport_introspection_c__get_function__GeometryPlane__planes(
  void * untyped_member, size_t index)
{
  kr_msgs__msg__GeometryPlane__Sequence * member =
    (kr_msgs__msg__GeometryPlane__Sequence *)(untyped_member);
  return &member->data[index];
}

bool SafetyZone__rosidl_typesupport_introspection_c__resize_function__GeometryPlane__planes(
  void * untyped_member, size_t size)
{
  kr_msgs__msg__GeometryPlane__Sequence * member =
    (kr_msgs__msg__GeometryPlane__Sequence *)(untyped_member);
  kr_msgs__msg__GeometryPlane__Sequence__fini(member);
  return kr_msgs__msg__GeometryPlane__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_member_array[6] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__SafetyZone, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__SafetyZone, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "buffer",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__SafetyZone, buffer),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sensitivity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__SafetyZone, sensitivity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "safety_io",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__SafetyZone, safety_io),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "planes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__SafetyZone, planes),  // bytes offset in struct
    NULL,  // default value
    SafetyZone__rosidl_typesupport_introspection_c__size_function__GeometryPlane__planes,  // size() function pointer
    SafetyZone__rosidl_typesupport_introspection_c__get_const_function__GeometryPlane__planes,  // get_const(index) function pointer
    SafetyZone__rosidl_typesupport_introspection_c__get_function__GeometryPlane__planes,  // get(index) function pointer
    SafetyZone__rosidl_typesupport_introspection_c__resize_function__GeometryPlane__planes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_members = {
  "kr_msgs__msg",  // message namespace
  "SafetyZone",  // message name
  6,  // number of fields
  sizeof(kr_msgs__msg__SafetyZone),
  SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_member_array,  // message members
  SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_init_function,  // function to initialize message memory (memory has to be allocated)
  SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_type_support_handle = {
  0,
  &SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, msg, SafetyZone)() {
  SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, msg, GeometryPlane)();
  if (!SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_type_support_handle.typesupport_identifier) {
    SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SafetyZone__rosidl_typesupport_introspection_c__SafetyZone_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
