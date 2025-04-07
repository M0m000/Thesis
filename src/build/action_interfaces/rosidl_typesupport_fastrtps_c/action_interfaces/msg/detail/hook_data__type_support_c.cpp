// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice
#include "action_interfaces/msg/detail/hook_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "action_interfaces/msg/detail/hook_data__struct.h"
#include "action_interfaces/msg/detail/hook_data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "action_interfaces/msg/detail/hook__functions.h"  // hooks

// forward declare type support functions
size_t get_serialized_size_action_interfaces__msg__Hook(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_action_interfaces__msg__Hook(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interfaces, msg, Hook)();


using _HookData__ros_msg_type = action_interfaces__msg__HookData;

static bool _HookData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HookData__ros_msg_type * ros_message = static_cast<const _HookData__ros_msg_type *>(untyped_ros_message);
  // Field name: hooks
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, Hook
      )()->data);
    size_t size = ros_message->hooks.size;
    auto array_ptr = ros_message->hooks.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _HookData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HookData__ros_msg_type * ros_message = static_cast<_HookData__ros_msg_type *>(untyped_ros_message);
  // Field name: hooks
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, Hook
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->hooks.data) {
      action_interfaces__msg__Hook__Sequence__fini(&ros_message->hooks);
    }
    if (!action_interfaces__msg__Hook__Sequence__init(&ros_message->hooks, size)) {
      return "failed to create array for field 'hooks'";
    }
    auto array_ptr = ros_message->hooks.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_action_interfaces
size_t get_serialized_size_action_interfaces__msg__HookData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HookData__ros_msg_type * ros_message = static_cast<const _HookData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name hooks
  {
    size_t array_size = ros_message->hooks.size;
    auto array_ptr = ros_message->hooks.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_action_interfaces__msg__Hook(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HookData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_action_interfaces__msg__HookData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_action_interfaces
size_t max_serialized_size_action_interfaces__msg__HookData(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: hooks
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_action_interfaces__msg__Hook(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _HookData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_action_interfaces__msg__HookData(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HookData = {
  "action_interfaces::msg",
  "HookData",
  _HookData__cdr_serialize,
  _HookData__cdr_deserialize,
  _HookData__get_serialized_size,
  _HookData__max_serialized_size
};

static rosidl_message_type_support_t _HookData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HookData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interfaces, msg, HookData)() {
  return &_HookData__type_support;
}

#if defined(__cplusplus)
}
#endif
