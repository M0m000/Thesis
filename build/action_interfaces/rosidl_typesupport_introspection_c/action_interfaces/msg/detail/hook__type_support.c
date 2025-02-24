// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "action_interfaces/msg/detail/hook__rosidl_typesupport_introspection_c.h"
#include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "action_interfaces/msg/detail/hook__functions.h"
#include "action_interfaces/msg/detail/hook__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `hook_box`
// Member `tip_box`
// Member `lowpoint_box`
#include "action_interfaces/msg/bounding_box.h"
// Member `hook_box`
// Member `tip_box`
// Member `lowpoint_box`
#include "action_interfaces/msg/detail/bounding_box__rosidl_typesupport_introspection_c.h"
// Member `hook_mask`
// Member `tip_mask`
// Member `lowpoint_mask`
// Member `skeleton_mask`
#include "sensor_msgs/msg/image.h"
// Member `hook_mask`
// Member `tip_mask`
// Member `lowpoint_mask`
// Member `skeleton_mask`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `uv_hook`
// Member `uv_tip`
// Member `uv_lowpoint`
// Member `uv_hook_img2`
// Member `uv_tip_img2`
// Member `uv_lowpoint_img2`
// Member `shortest_path`
// Member `path_points`
#include "action_interfaces/msg/uv.h"
// Member `uv_hook`
// Member `uv_tip`
// Member `uv_lowpoint`
// Member `uv_hook_img2`
// Member `uv_tip_img2`
// Member `uv_lowpoint_img2`
// Member `shortest_path`
// Member `path_points`
#include "action_interfaces/msg/detail/uv__rosidl_typesupport_introspection_c.h"
// Member `xyz_hook_in_camframe`
// Member `xyz_tip_in_camframe`
// Member `xyz_lowpoint_in_camframe`
#include "action_interfaces/msg/xyz.h"
// Member `xyz_hook_in_camframe`
// Member `xyz_tip_in_camframe`
// Member `xyz_lowpoint_in_camframe`
#include "action_interfaces/msg/detail/xyz__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Hook__rosidl_typesupport_introspection_c__Hook_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__msg__Hook__init(message_memory);
}

void Hook__rosidl_typesupport_introspection_c__Hook_fini_function(void * message_memory)
{
  action_interfaces__msg__Hook__fini(message_memory);
}

size_t Hook__rosidl_typesupport_introspection_c__size_function__UV__shortest_path(
  const void * untyped_member)
{
  const action_interfaces__msg__UV__Sequence * member =
    (const action_interfaces__msg__UV__Sequence *)(untyped_member);
  return member->size;
}

const void * Hook__rosidl_typesupport_introspection_c__get_const_function__UV__shortest_path(
  const void * untyped_member, size_t index)
{
  const action_interfaces__msg__UV__Sequence * member =
    (const action_interfaces__msg__UV__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Hook__rosidl_typesupport_introspection_c__get_function__UV__shortest_path(
  void * untyped_member, size_t index)
{
  action_interfaces__msg__UV__Sequence * member =
    (action_interfaces__msg__UV__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Hook__rosidl_typesupport_introspection_c__resize_function__UV__shortest_path(
  void * untyped_member, size_t size)
{
  action_interfaces__msg__UV__Sequence * member =
    (action_interfaces__msg__UV__Sequence *)(untyped_member);
  action_interfaces__msg__UV__Sequence__fini(member);
  return action_interfaces__msg__UV__Sequence__init(member, size);
}

size_t Hook__rosidl_typesupport_introspection_c__size_function__UV__path_points(
  const void * untyped_member)
{
  const action_interfaces__msg__UV__Sequence * member =
    (const action_interfaces__msg__UV__Sequence *)(untyped_member);
  return member->size;
}

const void * Hook__rosidl_typesupport_introspection_c__get_const_function__UV__path_points(
  const void * untyped_member, size_t index)
{
  const action_interfaces__msg__UV__Sequence * member =
    (const action_interfaces__msg__UV__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Hook__rosidl_typesupport_introspection_c__get_function__UV__path_points(
  void * untyped_member, size_t index)
{
  action_interfaces__msg__UV__Sequence * member =
    (action_interfaces__msg__UV__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Hook__rosidl_typesupport_introspection_c__resize_function__UV__path_points(
  void * untyped_member, size_t size)
{
  action_interfaces__msg__UV__Sequence * member =
    (action_interfaces__msg__UV__Sequence *)(untyped_member);
  action_interfaces__msg__UV__Sequence__fini(member);
  return action_interfaces__msg__UV__Sequence__init(member, size);
}

size_t Hook__rosidl_typesupport_introspection_c__size_function__XYZ__xyz_hook_in_camframe(
  const void * untyped_member)
{
  const action_interfaces__msg__XYZ__Sequence * member =
    (const action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return member->size;
}

const void * Hook__rosidl_typesupport_introspection_c__get_const_function__XYZ__xyz_hook_in_camframe(
  const void * untyped_member, size_t index)
{
  const action_interfaces__msg__XYZ__Sequence * member =
    (const action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Hook__rosidl_typesupport_introspection_c__get_function__XYZ__xyz_hook_in_camframe(
  void * untyped_member, size_t index)
{
  action_interfaces__msg__XYZ__Sequence * member =
    (action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Hook__rosidl_typesupport_introspection_c__resize_function__XYZ__xyz_hook_in_camframe(
  void * untyped_member, size_t size)
{
  action_interfaces__msg__XYZ__Sequence * member =
    (action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  action_interfaces__msg__XYZ__Sequence__fini(member);
  return action_interfaces__msg__XYZ__Sequence__init(member, size);
}

size_t Hook__rosidl_typesupport_introspection_c__size_function__XYZ__xyz_tip_in_camframe(
  const void * untyped_member)
{
  const action_interfaces__msg__XYZ__Sequence * member =
    (const action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return member->size;
}

const void * Hook__rosidl_typesupport_introspection_c__get_const_function__XYZ__xyz_tip_in_camframe(
  const void * untyped_member, size_t index)
{
  const action_interfaces__msg__XYZ__Sequence * member =
    (const action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Hook__rosidl_typesupport_introspection_c__get_function__XYZ__xyz_tip_in_camframe(
  void * untyped_member, size_t index)
{
  action_interfaces__msg__XYZ__Sequence * member =
    (action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Hook__rosidl_typesupport_introspection_c__resize_function__XYZ__xyz_tip_in_camframe(
  void * untyped_member, size_t size)
{
  action_interfaces__msg__XYZ__Sequence * member =
    (action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  action_interfaces__msg__XYZ__Sequence__fini(member);
  return action_interfaces__msg__XYZ__Sequence__init(member, size);
}

size_t Hook__rosidl_typesupport_introspection_c__size_function__XYZ__xyz_lowpoint_in_camframe(
  const void * untyped_member)
{
  const action_interfaces__msg__XYZ__Sequence * member =
    (const action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return member->size;
}

const void * Hook__rosidl_typesupport_introspection_c__get_const_function__XYZ__xyz_lowpoint_in_camframe(
  const void * untyped_member, size_t index)
{
  const action_interfaces__msg__XYZ__Sequence * member =
    (const action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Hook__rosidl_typesupport_introspection_c__get_function__XYZ__xyz_lowpoint_in_camframe(
  void * untyped_member, size_t index)
{
  action_interfaces__msg__XYZ__Sequence * member =
    (action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Hook__rosidl_typesupport_introspection_c__resize_function__XYZ__xyz_lowpoint_in_camframe(
  void * untyped_member, size_t size)
{
  action_interfaces__msg__XYZ__Sequence * member =
    (action_interfaces__msg__XYZ__Sequence *)(untyped_member);
  action_interfaces__msg__XYZ__Sequence__fini(member);
  return action_interfaces__msg__XYZ__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[22] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hook_box",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, hook_box),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tip_box",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, tip_box),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lowpoint_box",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, lowpoint_box),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hook_mask",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, hook_mask),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tip_mask",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, tip_mask),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lowpoint_mask",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, lowpoint_mask),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "skeleton_mask",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, skeleton_mask),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "conf_hook",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, conf_hook),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "conf_tip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, conf_tip),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "conf_lowpoint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, conf_lowpoint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "uv_hook",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, uv_hook),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "uv_tip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, uv_tip),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "uv_lowpoint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, uv_lowpoint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "uv_hook_img2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, uv_hook_img2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "uv_tip_img2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, uv_tip_img2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "uv_lowpoint_img2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, uv_lowpoint_img2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "shortest_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, shortest_path),  // bytes offset in struct
    NULL,  // default value
    Hook__rosidl_typesupport_introspection_c__size_function__UV__shortest_path,  // size() function pointer
    Hook__rosidl_typesupport_introspection_c__get_const_function__UV__shortest_path,  // get_const(index) function pointer
    Hook__rosidl_typesupport_introspection_c__get_function__UV__shortest_path,  // get(index) function pointer
    Hook__rosidl_typesupport_introspection_c__resize_function__UV__shortest_path  // resize(index) function pointer
  },
  {
    "path_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, path_points),  // bytes offset in struct
    NULL,  // default value
    Hook__rosidl_typesupport_introspection_c__size_function__UV__path_points,  // size() function pointer
    Hook__rosidl_typesupport_introspection_c__get_const_function__UV__path_points,  // get_const(index) function pointer
    Hook__rosidl_typesupport_introspection_c__get_function__UV__path_points,  // get(index) function pointer
    Hook__rosidl_typesupport_introspection_c__resize_function__UV__path_points  // resize(index) function pointer
  },
  {
    "xyz_hook_in_camframe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, xyz_hook_in_camframe),  // bytes offset in struct
    NULL,  // default value
    Hook__rosidl_typesupport_introspection_c__size_function__XYZ__xyz_hook_in_camframe,  // size() function pointer
    Hook__rosidl_typesupport_introspection_c__get_const_function__XYZ__xyz_hook_in_camframe,  // get_const(index) function pointer
    Hook__rosidl_typesupport_introspection_c__get_function__XYZ__xyz_hook_in_camframe,  // get(index) function pointer
    Hook__rosidl_typesupport_introspection_c__resize_function__XYZ__xyz_hook_in_camframe  // resize(index) function pointer
  },
  {
    "xyz_tip_in_camframe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, xyz_tip_in_camframe),  // bytes offset in struct
    NULL,  // default value
    Hook__rosidl_typesupport_introspection_c__size_function__XYZ__xyz_tip_in_camframe,  // size() function pointer
    Hook__rosidl_typesupport_introspection_c__get_const_function__XYZ__xyz_tip_in_camframe,  // get_const(index) function pointer
    Hook__rosidl_typesupport_introspection_c__get_function__XYZ__xyz_tip_in_camframe,  // get(index) function pointer
    Hook__rosidl_typesupport_introspection_c__resize_function__XYZ__xyz_tip_in_camframe  // resize(index) function pointer
  },
  {
    "xyz_lowpoint_in_camframe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__Hook, xyz_lowpoint_in_camframe),  // bytes offset in struct
    NULL,  // default value
    Hook__rosidl_typesupport_introspection_c__size_function__XYZ__xyz_lowpoint_in_camframe,  // size() function pointer
    Hook__rosidl_typesupport_introspection_c__get_const_function__XYZ__xyz_lowpoint_in_camframe,  // get_const(index) function pointer
    Hook__rosidl_typesupport_introspection_c__get_function__XYZ__xyz_lowpoint_in_camframe,  // get(index) function pointer
    Hook__rosidl_typesupport_introspection_c__resize_function__XYZ__xyz_lowpoint_in_camframe  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Hook__rosidl_typesupport_introspection_c__Hook_message_members = {
  "action_interfaces__msg",  // message namespace
  "Hook",  // message name
  22,  // number of fields
  sizeof(action_interfaces__msg__Hook),
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array,  // message members
  Hook__rosidl_typesupport_introspection_c__Hook_init_function,  // function to initialize message memory (memory has to be allocated)
  Hook__rosidl_typesupport_introspection_c__Hook_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Hook__rosidl_typesupport_introspection_c__Hook_message_type_support_handle = {
  0,
  &Hook__rosidl_typesupport_introspection_c__Hook_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, Hook)() {
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, BoundingBox)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, BoundingBox)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, BoundingBox)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[11].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[12].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[13].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[14].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[15].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[16].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[17].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[18].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, UV)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[19].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, XYZ)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[20].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, XYZ)();
  Hook__rosidl_typesupport_introspection_c__Hook_message_member_array[21].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, XYZ)();
  if (!Hook__rosidl_typesupport_introspection_c__Hook_message_type_support_handle.typesupport_identifier) {
    Hook__rosidl_typesupport_introspection_c__Hook_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Hook__rosidl_typesupport_introspection_c__Hook_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
