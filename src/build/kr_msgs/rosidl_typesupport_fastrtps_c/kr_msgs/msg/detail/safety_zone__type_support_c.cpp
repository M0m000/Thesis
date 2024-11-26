// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/safety_zone__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/msg/detail/safety_zone__struct.h"
#include "kr_msgs/msg/detail/safety_zone__functions.h"
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

#include "kr_msgs/msg/detail/geometry_plane__functions.h"  // planes
#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name

// forward declare type support functions
size_t get_serialized_size_kr_msgs__msg__GeometryPlane(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_kr_msgs__msg__GeometryPlane(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, GeometryPlane)();


using _SafetyZone__ros_msg_type = kr_msgs__msg__SafetyZone;

static bool _SafetyZone__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SafetyZone__ros_msg_type * ros_message = static_cast<const _SafetyZone__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: buffer
  {
    cdr << ros_message->buffer;
  }

  // Field name: sensitivity
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensitivity;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: safety_io
  {
    cdr << ros_message->safety_io;
  }

  // Field name: planes
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, GeometryPlane
      )()->data);
    size_t size = ros_message->planes.size;
    auto array_ptr = ros_message->planes.data;
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

static bool _SafetyZone__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SafetyZone__ros_msg_type * ros_message = static_cast<_SafetyZone__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: buffer
  {
    cdr >> ros_message->buffer;
  }

  // Field name: sensitivity
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensitivity;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: safety_io
  {
    cdr >> ros_message->safety_io;
  }

  // Field name: planes
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, GeometryPlane
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->planes.data) {
      kr_msgs__msg__GeometryPlane__Sequence__fini(&ros_message->planes);
    }
    if (!kr_msgs__msg__GeometryPlane__Sequence__init(&ros_message->planes, size)) {
      return "failed to create array for field 'planes'";
    }
    auto array_ptr = ros_message->planes.data;
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

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__msg__SafetyZone(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SafetyZone__ros_msg_type * ros_message = static_cast<const _SafetyZone__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name buffer
  {
    size_t item_size = sizeof(ros_message->buffer);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sensitivity
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->sensitivity;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name safety_io
  {
    size_t item_size = sizeof(ros_message->safety_io);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name planes
  {
    size_t array_size = ros_message->planes.size;
    auto array_ptr = ros_message->planes.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_kr_msgs__msg__GeometryPlane(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SafetyZone__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__msg__SafetyZone(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__msg__SafetyZone(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: buffer
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sensitivity
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: safety_io
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: planes
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_kr_msgs__msg__GeometryPlane(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _SafetyZone__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__msg__SafetyZone(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SafetyZone = {
  "kr_msgs::msg",
  "SafetyZone",
  _SafetyZone__cdr_serialize,
  _SafetyZone__cdr_deserialize,
  _SafetyZone__get_serialized_size,
  _SafetyZone__max_serialized_size
};

static rosidl_message_type_support_t _SafetyZone__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SafetyZone,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, SafetyZone)() {
  return &_SafetyZone__type_support;
}

#if defined(__cplusplus)
}
#endif
