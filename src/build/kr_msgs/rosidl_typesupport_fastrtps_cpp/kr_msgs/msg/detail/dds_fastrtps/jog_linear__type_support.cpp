// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:msg/JogLinear.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/jog_linear__rosidl_typesupport_fastrtps_cpp.hpp"
#include "kr_msgs/msg/detail/jog_linear__struct.hpp"

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

namespace kr_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_serialize(
  const kr_msgs::msg::JogLinear & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: vel
  {
    cdr << ros_message.vel;
  }
  // Member: rot
  {
    cdr << ros_message.rot;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  kr_msgs::msg::JogLinear & ros_message)
{
  // Member: vel
  {
    cdr >> ros_message.vel;
  }

  // Member: rot
  {
    cdr >> ros_message.rot;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
get_serialized_size(
  const kr_msgs::msg::JogLinear & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: vel
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.vel[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rot
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.rot[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
max_serialized_size_JogLinear(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: vel
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: rot
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _JogLinear__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const kr_msgs::msg::JogLinear *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _JogLinear__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<kr_msgs::msg::JogLinear *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _JogLinear__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const kr_msgs::msg::JogLinear *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _JogLinear__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_JogLinear(full_bounded, 0);
}

static message_type_support_callbacks_t _JogLinear__callbacks = {
  "kr_msgs::msg",
  "JogLinear",
  _JogLinear__cdr_serialize,
  _JogLinear__cdr_deserialize,
  _JogLinear__get_serialized_size,
  _JogLinear__max_serialized_size
};

static rosidl_message_type_support_t _JogLinear__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_JogLinear__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace kr_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_kr_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<kr_msgs::msg::JogLinear>()
{
  return &kr_msgs::msg::typesupport_fastrtps_cpp::_JogLinear__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, msg, JogLinear)() {
  return &kr_msgs::msg::typesupport_fastrtps_cpp::_JogLinear__handle;
}

#ifdef __cplusplus
}
#endif