// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kr_msgs:msg/FollowLinear.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/follow_linear__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/msg/detail/follow_linear__struct.h"
#include "kr_msgs/msg/detail/follow_linear__functions.h"
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


// forward declare type support functions


using _FollowLinear__ros_msg_type = kr_msgs__msg__FollowLinear;

static bool _FollowLinear__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FollowLinear__ros_msg_type * ros_message = static_cast<const _FollowLinear__ros_msg_type *>(untyped_ros_message);
  // Field name: pos
  {
    size_t size = 3;
    auto array_ptr = ros_message->pos;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: rot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rot;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: ref
  {
    cdr << ros_message->ref;
  }

  // Field name: ttype
  {
    cdr << ros_message->ttype;
  }

  // Field name: tvalue
  {
    cdr << ros_message->tvalue;
  }

  // Field name: bpoint
  {
    cdr << ros_message->bpoint;
  }

  // Field name: btype
  {
    cdr << ros_message->btype;
  }

  // Field name: bvalue
  {
    cdr << ros_message->bvalue;
  }

  return true;
}

static bool _FollowLinear__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FollowLinear__ros_msg_type * ros_message = static_cast<_FollowLinear__ros_msg_type *>(untyped_ros_message);
  // Field name: pos
  {
    size_t size = 3;
    auto array_ptr = ros_message->pos;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: rot
  {
    size_t size = 3;
    auto array_ptr = ros_message->rot;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: ref
  {
    cdr >> ros_message->ref;
  }

  // Field name: ttype
  {
    cdr >> ros_message->ttype;
  }

  // Field name: tvalue
  {
    cdr >> ros_message->tvalue;
  }

  // Field name: bpoint
  {
    cdr >> ros_message->bpoint;
  }

  // Field name: btype
  {
    cdr >> ros_message->btype;
  }

  // Field name: bvalue
  {
    cdr >> ros_message->bvalue;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__msg__FollowLinear(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FollowLinear__ros_msg_type * ros_message = static_cast<const _FollowLinear__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pos
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rot
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->rot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ref
  {
    size_t item_size = sizeof(ros_message->ref);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ttype
  {
    size_t item_size = sizeof(ros_message->ttype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tvalue
  {
    size_t item_size = sizeof(ros_message->tvalue);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bpoint
  {
    size_t item_size = sizeof(ros_message->bpoint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name btype
  {
    size_t item_size = sizeof(ros_message->btype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name bvalue
  {
    size_t item_size = sizeof(ros_message->bvalue);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FollowLinear__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__msg__FollowLinear(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__msg__FollowLinear(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: pos
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rot
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ref
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ttype
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: tvalue
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: bpoint
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: btype
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: bvalue
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _FollowLinear__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__msg__FollowLinear(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_FollowLinear = {
  "kr_msgs::msg",
  "FollowLinear",
  _FollowLinear__cdr_serialize,
  _FollowLinear__cdr_deserialize,
  _FollowLinear__get_serialized_size,
  _FollowLinear__max_serialized_size
};

static rosidl_message_type_support_t _FollowLinear__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FollowLinear,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, FollowLinear)() {
  return &_FollowLinear__type_support;
}

#if defined(__cplusplus)
}
#endif
