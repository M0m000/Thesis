// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from action_interfaces:msg/XYZ.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "action_interfaces/msg/detail/xyz__rosidl_typesupport_introspection_c.h"
#include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "action_interfaces/msg/detail/xyz__functions.h"
#include "action_interfaces/msg/detail/xyz__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void XYZ__rosidl_typesupport_introspection_c__XYZ_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__msg__XYZ__init(message_memory);
}

void XYZ__rosidl_typesupport_introspection_c__XYZ_fini_function(void * message_memory)
{
  action_interfaces__msg__XYZ__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember XYZ__rosidl_typesupport_introspection_c__XYZ_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__XYZ, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__XYZ, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__XYZ, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers XYZ__rosidl_typesupport_introspection_c__XYZ_message_members = {
  "action_interfaces__msg",  // message namespace
  "XYZ",  // message name
  3,  // number of fields
  sizeof(action_interfaces__msg__XYZ),
  XYZ__rosidl_typesupport_introspection_c__XYZ_message_member_array,  // message members
  XYZ__rosidl_typesupport_introspection_c__XYZ_init_function,  // function to initialize message memory (memory has to be allocated)
  XYZ__rosidl_typesupport_introspection_c__XYZ_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t XYZ__rosidl_typesupport_introspection_c__XYZ_message_type_support_handle = {
  0,
  &XYZ__rosidl_typesupport_introspection_c__XYZ_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, XYZ)() {
  if (!XYZ__rosidl_typesupport_introspection_c__XYZ_message_type_support_handle.typesupport_identifier) {
    XYZ__rosidl_typesupport_introspection_c__XYZ_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &XYZ__rosidl_typesupport_introspection_c__XYZ_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
