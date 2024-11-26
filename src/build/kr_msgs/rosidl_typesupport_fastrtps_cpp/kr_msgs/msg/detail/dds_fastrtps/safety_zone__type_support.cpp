// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/safety_zone__rosidl_typesupport_fastrtps_cpp.hpp"
#include "kr_msgs/msg/detail/safety_zone__struct.hpp"

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
bool cdr_serialize(
  const kr_msgs::msg::GeometryPlane &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  kr_msgs::msg::GeometryPlane &);
size_t get_serialized_size(
  const kr_msgs::msg::GeometryPlane &,
  size_t current_alignment);
size_t
max_serialized_size_GeometryPlane(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace kr_msgs


namespace kr_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_serialize(
  const kr_msgs::msg::SafetyZone & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;
  // Member: speed
  cdr << ros_message.speed;
  // Member: buffer
  cdr << ros_message.buffer;
  // Member: sensitivity
  {
    cdr << ros_message.sensitivity;
  }
  // Member: safety_io
  cdr << ros_message.safety_io;
  // Member: planes
  {
    size_t size = ros_message.planes.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      kr_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.planes[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  kr_msgs::msg::SafetyZone & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: speed
  cdr >> ros_message.speed;

  // Member: buffer
  cdr >> ros_message.buffer;

  // Member: sensitivity
  {
    cdr >> ros_message.sensitivity;
  }

  // Member: safety_io
  cdr >> ros_message.safety_io;

  // Member: planes
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.planes.resize(size);
    for (size_t i = 0; i < size; i++) {
      kr_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.planes[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
get_serialized_size(
  const kr_msgs::msg::SafetyZone & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);
  // Member: speed
  {
    size_t item_size = sizeof(ros_message.speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: buffer
  {
    size_t item_size = sizeof(ros_message.buffer);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sensitivity
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.sensitivity[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: safety_io
  {
    size_t item_size = sizeof(ros_message.safety_io);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: planes
  {
    size_t array_size = ros_message.planes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        kr_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.planes[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
max_serialized_size_SafetyZone(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: buffer
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: sensitivity
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: safety_io
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: planes
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        kr_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_GeometryPlane(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _SafetyZone__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const kr_msgs::msg::SafetyZone *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SafetyZone__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<kr_msgs::msg::SafetyZone *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SafetyZone__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const kr_msgs::msg::SafetyZone *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SafetyZone__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SafetyZone(full_bounded, 0);
}

static message_type_support_callbacks_t _SafetyZone__callbacks = {
  "kr_msgs::msg",
  "SafetyZone",
  _SafetyZone__cdr_serialize,
  _SafetyZone__cdr_deserialize,
  _SafetyZone__get_serialized_size,
  _SafetyZone__max_serialized_size
};

static rosidl_message_type_support_t _SafetyZone__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SafetyZone__callbacks,
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
get_message_type_support_handle<kr_msgs::msg::SafetyZone>()
{
  return &kr_msgs::msg::typesupport_fastrtps_cpp::_SafetyZone__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, msg, SafetyZone)() {
  return &kr_msgs::msg::typesupport_fastrtps_cpp::_SafetyZone__handle;
}

#ifdef __cplusplus
}
#endif
