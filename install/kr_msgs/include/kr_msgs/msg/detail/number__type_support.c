// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:msg/Number.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/msg/detail/number__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/msg/detail/number__functions.h"
#include "kr_msgs/msg/detail/number__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Number__rosidl_typesupport_introspection_c__Number_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__msg__Number__init(message_memory);
}

void Number__rosidl_typesupport_introspection_c__Number_fini_function(void * message_memory)
{
  kr_msgs__msg__Number__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Number__rosidl_typesupport_introspection_c__Number_message_member_array[1] = {
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__Number, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Number__rosidl_typesupport_introspection_c__Number_message_members = {
  "kr_msgs__msg",  // message namespace
  "Number",  // message name
  1,  // number of fields
  sizeof(kr_msgs__msg__Number),
  Number__rosidl_typesupport_introspection_c__Number_message_member_array,  // message members
  Number__rosidl_typesupport_introspection_c__Number_init_function,  // function to initialize message memory (memory has to be allocated)
  Number__rosidl_typesupport_introspection_c__Number_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Number__rosidl_typesupport_introspection_c__Number_message_type_support_handle = {
  0,
  &Number__rosidl_typesupport_introspection_c__Number_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, msg, Number)() {
  if (!Number__rosidl_typesupport_introspection_c__Number_message_type_support_handle.typesupport_identifier) {
    Number__rosidl_typesupport_introspection_c__Number_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Number__rosidl_typesupport_introspection_c__Number_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
