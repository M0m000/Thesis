// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "action_interfaces/msg/detail/hook_data__rosidl_typesupport_introspection_c.h"
#include "action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "action_interfaces/msg/detail/hook_data__functions.h"
#include "action_interfaces/msg/detail/hook_data__struct.h"


// Include directives for member types
// Member `hooks`
#include "action_interfaces/msg/hook.h"
// Member `hooks`
#include "action_interfaces/msg/detail/hook__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HookData__rosidl_typesupport_introspection_c__HookData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interfaces__msg__HookData__init(message_memory);
}

void HookData__rosidl_typesupport_introspection_c__HookData_fini_function(void * message_memory)
{
  action_interfaces__msg__HookData__fini(message_memory);
}

size_t HookData__rosidl_typesupport_introspection_c__size_function__Hook__hooks(
  const void * untyped_member)
{
  const action_interfaces__msg__Hook__Sequence * member =
    (const action_interfaces__msg__Hook__Sequence *)(untyped_member);
  return member->size;
}

const void * HookData__rosidl_typesupport_introspection_c__get_const_function__Hook__hooks(
  const void * untyped_member, size_t index)
{
  const action_interfaces__msg__Hook__Sequence * member =
    (const action_interfaces__msg__Hook__Sequence *)(untyped_member);
  return &member->data[index];
}

void * HookData__rosidl_typesupport_introspection_c__get_function__Hook__hooks(
  void * untyped_member, size_t index)
{
  action_interfaces__msg__Hook__Sequence * member =
    (action_interfaces__msg__Hook__Sequence *)(untyped_member);
  return &member->data[index];
}

bool HookData__rosidl_typesupport_introspection_c__resize_function__Hook__hooks(
  void * untyped_member, size_t size)
{
  action_interfaces__msg__Hook__Sequence * member =
    (action_interfaces__msg__Hook__Sequence *)(untyped_member);
  action_interfaces__msg__Hook__Sequence__fini(member);
  return action_interfaces__msg__Hook__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember HookData__rosidl_typesupport_introspection_c__HookData_message_member_array[1] = {
  {
    "hooks",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces__msg__HookData, hooks),  // bytes offset in struct
    NULL,  // default value
    HookData__rosidl_typesupport_introspection_c__size_function__Hook__hooks,  // size() function pointer
    HookData__rosidl_typesupport_introspection_c__get_const_function__Hook__hooks,  // get_const(index) function pointer
    HookData__rosidl_typesupport_introspection_c__get_function__Hook__hooks,  // get(index) function pointer
    HookData__rosidl_typesupport_introspection_c__resize_function__Hook__hooks  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HookData__rosidl_typesupport_introspection_c__HookData_message_members = {
  "action_interfaces__msg",  // message namespace
  "HookData",  // message name
  1,  // number of fields
  sizeof(action_interfaces__msg__HookData),
  HookData__rosidl_typesupport_introspection_c__HookData_message_member_array,  // message members
  HookData__rosidl_typesupport_introspection_c__HookData_init_function,  // function to initialize message memory (memory has to be allocated)
  HookData__rosidl_typesupport_introspection_c__HookData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HookData__rosidl_typesupport_introspection_c__HookData_message_type_support_handle = {
  0,
  &HookData__rosidl_typesupport_introspection_c__HookData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, HookData)() {
  HookData__rosidl_typesupport_introspection_c__HookData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interfaces, msg, Hook)();
  if (!HookData__rosidl_typesupport_introspection_c__HookData_message_type_support_handle.typesupport_identifier) {
    HookData__rosidl_typesupport_introspection_c__HookData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HookData__rosidl_typesupport_introspection_c__HookData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
