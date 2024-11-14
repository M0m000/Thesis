// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kr_msgs:srv/ConfigAnalogOutput.idl
// generated code does not contain a copyright notice
#include "kr_msgs/srv/detail/config_analog_output__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/srv/detail/config_analog_output__struct.h"
#include "kr_msgs/srv/detail/config_analog_output__functions.h"
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


using _ConfigAnalogOutput_Request__ros_msg_type = kr_msgs__srv__ConfigAnalogOutput_Request;

static bool _ConfigAnalogOutput_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ConfigAnalogOutput_Request__ros_msg_type * ros_message = static_cast<const _ConfigAnalogOutput_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: index
  {
    cdr << ros_message->index;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  return true;
}

static bool _ConfigAnalogOutput_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ConfigAnalogOutput_Request__ros_msg_type * ros_message = static_cast<_ConfigAnalogOutput_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: index
  {
    cdr >> ros_message->index;
  }

  // Field name: type
  {
    cdr >> ros_message->type;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ConfigAnalogOutput_Request__ros_msg_type * ros_message = static_cast<const _ConfigAnalogOutput_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name index
  {
    size_t item_size = sizeof(ros_message->index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ConfigAnalogOutput_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: type
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ConfigAnalogOutput_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ConfigAnalogOutput_Request = {
  "kr_msgs::srv",
  "ConfigAnalogOutput_Request",
  _ConfigAnalogOutput_Request__cdr_serialize,
  _ConfigAnalogOutput_Request__cdr_deserialize,
  _ConfigAnalogOutput_Request__get_serialized_size,
  _ConfigAnalogOutput_Request__max_serialized_size
};

static rosidl_message_type_support_t _ConfigAnalogOutput_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ConfigAnalogOutput_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, ConfigAnalogOutput_Request)() {
  return &_ConfigAnalogOutput_Request__type_support;
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
// #include "kr_msgs/srv/detail/config_analog_output__struct.h"
// already included above
// #include "kr_msgs/srv/detail/config_analog_output__functions.h"
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


using _ConfigAnalogOutput_Response__ros_msg_type = kr_msgs__srv__ConfigAnalogOutput_Response;

static bool _ConfigAnalogOutput_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ConfigAnalogOutput_Response__ros_msg_type * ros_message = static_cast<const _ConfigAnalogOutput_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _ConfigAnalogOutput_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ConfigAnalogOutput_Response__ros_msg_type * ros_message = static_cast<_ConfigAnalogOutput_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ConfigAnalogOutput_Response__ros_msg_type * ros_message = static_cast<const _ConfigAnalogOutput_Response__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _ConfigAnalogOutput_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Response(
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

static size_t _ConfigAnalogOutput_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__srv__ConfigAnalogOutput_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ConfigAnalogOutput_Response = {
  "kr_msgs::srv",
  "ConfigAnalogOutput_Response",
  _ConfigAnalogOutput_Response__cdr_serialize,
  _ConfigAnalogOutput_Response__cdr_deserialize,
  _ConfigAnalogOutput_Response__get_serialized_size,
  _ConfigAnalogOutput_Response__max_serialized_size
};

static rosidl_message_type_support_t _ConfigAnalogOutput_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ConfigAnalogOutput_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, ConfigAnalogOutput_Response)() {
  return &_ConfigAnalogOutput_Response__type_support;
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
#include "kr_msgs/srv/config_analog_output.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ConfigAnalogOutput__callbacks = {
  "kr_msgs::srv",
  "ConfigAnalogOutput",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, ConfigAnalogOutput_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, ConfigAnalogOutput_Response)(),
};

static rosidl_service_type_support_t ConfigAnalogOutput__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ConfigAnalogOutput__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, srv, ConfigAnalogOutput)() {
  return &ConfigAnalogOutput__handle;
}

#if defined(__cplusplus)
}
#endif
