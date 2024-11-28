// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kr_msgs:srv/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice
#include "kr_msgs/srv/detail/move_tcp_along_axis__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/srv/detail/move_tcp_along_axis__struct.h"
#include "kr_msgs/srv/detail/move_tcp_along_axis__functions.h"
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

#include "rosidl_runtime_c/string.h"  // axis, frame
#include "rosidl_runtime_c/string_functions.h"  // axis, frame

// forward declare type support functions


using _MoveTCPAlongAxis_Request__ros_msg_type = kr_msgs__srv__MoveTCPAlongAxis_Request;

static bool _MoveTCPAlongAxis_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MoveTCPAlongAxis_Request__ros_msg_type * ros_message = static_cast<const _MoveTCPAlongAxis_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: baseline
  {
    cdr << ros_message->baseline;
  }

  // Field name: frame
  {
    const rosidl_runtime_c__String * str = &ros_message->frame;
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

  // Field name: axis
  {
    const rosidl_runtime_c__String * str = &ros_message->axis;
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

  return true;
}

static bool _MoveTCPAlongAxis_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MoveTCPAlongAxis_Request__ros_msg_type * ros_message = static_cast<_MoveTCPAlongAxis_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: baseline
  {
    cdr >> ros_message->baseline;
  }

  // Field name: frame
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->frame.data) {
      rosidl_runtime_c__String__init(&ros_message->frame);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->frame,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'frame'\n");
      return false;
    }
  }

  // Field name: axis
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->axis.data) {
      rosidl_runtime_c__String__init(&ros_message->axis);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->axis,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'axis'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MoveTCPAlongAxis_Request__ros_msg_type * ros_message = static_cast<const _MoveTCPAlongAxis_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name baseline
  {
    size_t item_size = sizeof(ros_message->baseline);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name frame
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->frame.size + 1);
  // field.name axis
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->axis.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _MoveTCPAlongAxis_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: baseline
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: frame
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: axis
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _MoveTCPAlongAxis_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MoveTCPAlongAxis_Request = {
  "kr_msgs::srv",
  "MoveTCPAlongAxis_Request",
  _MoveTCPAlongAxis_Request__cdr_serialize,
  _MoveTCPAlongAxis_Request__cdr_deserialize,
  _MoveTCPAlongAxis_Request__get_serialized_size,
  _MoveTCPAlongAxis_Request__max_serialized_size
};

static rosidl_message_type_support_t _MoveTCPAlongAxis_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MoveTCPAlongAxis_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveTCPAlongAxis_Request)() {
  return &_MoveTCPAlongAxis_Request__type_support;
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
// #include "kr_msgs/srv/detail/move_tcp_along_axis__struct.h"
// already included above
// #include "kr_msgs/srv/detail/move_tcp_along_axis__functions.h"
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


using _MoveTCPAlongAxis_Response__ros_msg_type = kr_msgs__srv__MoveTCPAlongAxis_Response;

static bool _MoveTCPAlongAxis_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MoveTCPAlongAxis_Response__ros_msg_type * ros_message = static_cast<const _MoveTCPAlongAxis_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _MoveTCPAlongAxis_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MoveTCPAlongAxis_Response__ros_msg_type * ros_message = static_cast<_MoveTCPAlongAxis_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MoveTCPAlongAxis_Response__ros_msg_type * ros_message = static_cast<const _MoveTCPAlongAxis_Response__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _MoveTCPAlongAxis_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Response(
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

static size_t _MoveTCPAlongAxis_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__srv__MoveTCPAlongAxis_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MoveTCPAlongAxis_Response = {
  "kr_msgs::srv",
  "MoveTCPAlongAxis_Response",
  _MoveTCPAlongAxis_Response__cdr_serialize,
  _MoveTCPAlongAxis_Response__cdr_deserialize,
  _MoveTCPAlongAxis_Response__get_serialized_size,
  _MoveTCPAlongAxis_Response__max_serialized_size
};

static rosidl_message_type_support_t _MoveTCPAlongAxis_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MoveTCPAlongAxis_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveTCPAlongAxis_Response)() {
  return &_MoveTCPAlongAxis_Response__type_support;
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
#include "kr_msgs/srv/move_tcp_along_axis.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MoveTCPAlongAxis__callbacks = {
  "kr_msgs::srv",
  "MoveTCPAlongAxis",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveTCPAlongAxis_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveTCPAlongAxis_Response)(),
};

static rosidl_service_type_support_t MoveTCPAlongAxis__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &MoveTCPAlongAxis__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, MoveTCPAlongAxis)() {
  return &MoveTCPAlongAxis__handle;
}

#if defined(__cplusplus)
}
#endif
