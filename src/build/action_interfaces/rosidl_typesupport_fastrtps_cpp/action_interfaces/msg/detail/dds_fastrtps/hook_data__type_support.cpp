// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice
#include "action_interfaces/msg/detail/hook_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "action_interfaces/msg/detail/hook_data__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace action_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const action_interfaces::msg::Hook &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  action_interfaces::msg::Hook &);
size_t get_serialized_size(
  const action_interfaces::msg::Hook &,
  size_t current_alignment);
size_t
max_serialized_size_Hook(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace action_interfaces


namespace action_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_action_interfaces
cdr_serialize(
  const action_interfaces::msg::HookData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: hooks
  {
    size_t size = ros_message.hooks.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      action_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.hooks[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_action_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  action_interfaces::msg::HookData & ros_message)
{
  // Member: hooks
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.hooks.resize(size);
    for (size_t i = 0; i < size; i++) {
      action_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.hooks[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_action_interfaces
get_serialized_size(
  const action_interfaces::msg::HookData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: hooks
  {
    size_t array_size = ros_message.hooks.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        action_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.hooks[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_action_interfaces
max_serialized_size_HookData(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: hooks
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        action_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Hook(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _HookData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const action_interfaces::msg::HookData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HookData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<action_interfaces::msg::HookData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HookData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const action_interfaces::msg::HookData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HookData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_HookData(full_bounded, 0);
}

static message_type_support_callbacks_t _HookData__callbacks = {
  "action_interfaces::msg",
  "HookData",
  _HookData__cdr_serialize,
  _HookData__cdr_deserialize,
  _HookData__get_serialized_size,
  _HookData__max_serialized_size
};

static rosidl_message_type_support_t _HookData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HookData__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace action_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_action_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::msg::HookData>()
{
  return &action_interfaces::msg::typesupport_fastrtps_cpp::_HookData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, msg, HookData)() {
  return &action_interfaces::msg::typesupport_fastrtps_cpp::_HookData__handle;
}

#ifdef __cplusplus
}
#endif
