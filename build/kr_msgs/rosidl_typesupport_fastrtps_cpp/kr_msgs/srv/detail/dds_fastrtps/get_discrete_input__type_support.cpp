// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:srv/GetDiscreteInput.idl
// generated code does not contain a copyright notice
#include "kr_msgs/srv/detail/get_discrete_input__rosidl_typesupport_fastrtps_cpp.hpp"
#include "kr_msgs/srv/detail/get_discrete_input__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_serialize(
  const kr_msgs::srv::GetDiscreteInput_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: index
  cdr << ros_message.index;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  kr_msgs::srv::GetDiscreteInput_Request & ros_message)
{
  // Member: index
  cdr >> ros_message.index;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
get_serialized_size(
  const kr_msgs::srv::GetDiscreteInput_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: index
  {
    size_t item_size = sizeof(ros_message.index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
max_serialized_size_GetDiscreteInput_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _GetDiscreteInput_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const kr_msgs::srv::GetDiscreteInput_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GetDiscreteInput_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<kr_msgs::srv::GetDiscreteInput_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GetDiscreteInput_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const kr_msgs::srv::GetDiscreteInput_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GetDiscreteInput_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GetDiscreteInput_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _GetDiscreteInput_Request__callbacks = {
  "kr_msgs::srv",
  "GetDiscreteInput_Request",
  _GetDiscreteInput_Request__cdr_serialize,
  _GetDiscreteInput_Request__cdr_deserialize,
  _GetDiscreteInput_Request__get_serialized_size,
  _GetDiscreteInput_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetDiscreteInput_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GetDiscreteInput_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace kr_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_kr_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<kr_msgs::srv::GetDiscreteInput_Request>()
{
  return &kr_msgs::srv::typesupport_fastrtps_cpp::_GetDiscreteInput_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, srv, GetDiscreteInput_Request)() {
  return &kr_msgs::srv::typesupport_fastrtps_cpp::_GetDiscreteInput_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace kr_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_serialize(
  const kr_msgs::srv::GetDiscreteInput_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: value
  cdr << ros_message.value;
  // Member: success
  cdr << (ros_message.success ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  kr_msgs::srv::GetDiscreteInput_Response & ros_message)
{
  // Member: value
  cdr >> ros_message.value;

  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
get_serialized_size(
  const kr_msgs::srv::GetDiscreteInput_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: value
  {
    size_t item_size = sizeof(ros_message.value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
max_serialized_size_GetDiscreteInput_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _GetDiscreteInput_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const kr_msgs::srv::GetDiscreteInput_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GetDiscreteInput_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<kr_msgs::srv::GetDiscreteInput_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GetDiscreteInput_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const kr_msgs::srv::GetDiscreteInput_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GetDiscreteInput_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GetDiscreteInput_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _GetDiscreteInput_Response__callbacks = {
  "kr_msgs::srv",
  "GetDiscreteInput_Response",
  _GetDiscreteInput_Response__cdr_serialize,
  _GetDiscreteInput_Response__cdr_deserialize,
  _GetDiscreteInput_Response__get_serialized_size,
  _GetDiscreteInput_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetDiscreteInput_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GetDiscreteInput_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace kr_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_kr_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<kr_msgs::srv::GetDiscreteInput_Response>()
{
  return &kr_msgs::srv::typesupport_fastrtps_cpp::_GetDiscreteInput_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, srv, GetDiscreteInput_Response)() {
  return &kr_msgs::srv::typesupport_fastrtps_cpp::_GetDiscreteInput_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace kr_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _GetDiscreteInput__callbacks = {
  "kr_msgs::srv",
  "GetDiscreteInput",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, srv, GetDiscreteInput_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, srv, GetDiscreteInput_Response)(),
};

static rosidl_service_type_support_t _GetDiscreteInput__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GetDiscreteInput__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace kr_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_kr_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<kr_msgs::srv::GetDiscreteInput>()
{
  return &kr_msgs::srv::typesupport_fastrtps_cpp::_GetDiscreteInput__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, srv, GetDiscreteInput)() {
  return &kr_msgs::srv::typesupport_fastrtps_cpp::_GetDiscreteInput__handle;
}

#ifdef __cplusplus
}
#endif
