// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kr_msgs:srv/MoveSpline.idl
// generated code does not contain a copyright notice
#include "kr_msgs/srv/detail/move_spline__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/srv/detail/move_spline__struct.h"
#include "kr_msgs/srv/detail/move_spline__functions.h"
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


using _MoveSpline_Request__ros_msg_type = kr_msgs__srv__MoveSpline_Request;

static bool _MoveSpline_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MoveSpline_Request__ros_msg_type * ros_message = static_cast<const _MoveSpline_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: sync
  {
    cdr << ros_message->sync;
  }

  // Field name: orient
  {
    cdr << ros_message->orient;
  }

  // Field name: horizon
  {
    cdr << ros_message->horizon;
  }

  return true;
}

static bool _MoveSpline_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MoveSpline_Request__ros_msg_type * ros_message = static_cast<_MoveSpline_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: sync
  {
    cdr >> ros_message->sync;
  }

  // Field name: orient
  {
    cdr >> ros_message->orient;
  }

  // Field name: horizon
  {
    cdr >> ros_message->horizon;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__srv__MoveSpline_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MoveSpline_Request__ros_msg_type * ros_message = static_cast<const _MoveSpline_Request__ros_msg_type *>(untyped_ros_message);
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
  // field.name sync
  {
    size_t item_size = sizeof(ros_message->sync);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name orient
  {
    size_t item_size = sizeof(ros_message->orient);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name horizon
  {
    size_t item_size = sizeof(ros_message->horizon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MoveSpline_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__srv__MoveSpline_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__srv__MoveSpline_Request(
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
  // member: sync
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: orient
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: horizon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _MoveSpline_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__srv__MoveSpline_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MoveSpline_Request = {
  "kr_msgs::srv",
  "MoveSpline_Request",
  _MoveSpline_Request__cdr_serialize,
  _MoveSpline_Request__cdr_deserialize,
  _MoveSpline_Request__get_serialized_size,
  _MoveSpline_Request__max_serialized_size
};

static rosidl_message_type_support_t _MoveSpline_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MoveSpline_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveSpline_Request)() {
  return &_MoveSpline_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "kr_msgs/srv/detail/move_spline__struct.h"
// already included above
// #include "kr_msgs/srv/detail/move_spline__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


using _MoveSpline_Response__ros_msg_type = kr_msgs__srv__MoveSpline_Response;

static bool _MoveSpline_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MoveSpline_Response__ros_msg_type * ros_message = static_cast<const _MoveSpline_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _MoveSpline_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MoveSpline_Response__ros_msg_type * ros_message = static_cast<_MoveSpline_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__srv__MoveSpline_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MoveSpline_Response__ros_msg_type * ros_message = static_cast<const _MoveSpline_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MoveSpline_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__srv__MoveSpline_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__srv__MoveSpline_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _MoveSpline_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__srv__MoveSpline_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MoveSpline_Response = {
  "kr_msgs::srv",
  "MoveSpline_Response",
  _MoveSpline_Response__cdr_serialize,
  _MoveSpline_Response__cdr_deserialize,
  _MoveSpline_Response__get_serialized_size,
  _MoveSpline_Response__max_serialized_size
};

static rosidl_message_type_support_t _MoveSpline_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MoveSpline_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveSpline_Response)() {
  return &_MoveSpline_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/srv/move_spline.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MoveSpline__callbacks = {
  "kr_msgs::srv",
  "MoveSpline",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveSpline_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveSpline_Response)(),
};

static rosidl_service_type_support_t MoveSpline__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &MoveSpline__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveSpline)() {
  return &MoveSpline__handle;
}

#if defined(__cplusplus)
}
#endif
