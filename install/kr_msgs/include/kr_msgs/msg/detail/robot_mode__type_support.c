// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kr_msgs:msg/RobotMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kr_msgs/msg/detail/robot_mode__rosidl_typesupport_introspection_c.h"
#include "kr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kr_msgs/msg/detail/robot_mode__functions.h"
#include "kr_msgs/msg/detail/robot_mode__struct.h"


// Include directives for member types
// Member `str`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RobotMode__rosidl_typesupport_introspection_c__RobotMode_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kr_msgs__msg__RobotMode__init(message_memory);
}

void RobotMode__rosidl_typesupport_introspection_c__RobotMode_fini_function(void * message_memory)
{
  kr_msgs__msg__RobotMode__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_member_array[2] = {
  {
    "val",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__RobotMode, val),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "str",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs__msg__RobotMode, str),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_members = {
  "kr_msgs__msg",  // message namespace
  "RobotMode",  // message name
  2,  // number of fields
  sizeof(kr_msgs__msg__RobotMode),
  RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_member_array,  // message members
  RobotMode__rosidl_typesupport_introspection_c__RobotMode_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotMode__rosidl_typesupport_introspection_c__RobotMode_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_type_support_handle = {
  0,
  &RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kr_msgs, msg, RobotMode)() {
  if (!RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_type_support_handle.typesupport_identifier) {
    RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RobotMode__rosidl_typesupport_introspection_c__RobotMode_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
