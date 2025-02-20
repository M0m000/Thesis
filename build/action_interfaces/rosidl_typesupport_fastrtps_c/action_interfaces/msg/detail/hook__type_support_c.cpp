// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice
#include "action_interfaces/msg/detail/hook__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "action_interfaces/msg/detail/hook__struct.h"
#include "action_interfaces/msg/detail/hook__functions.h"
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

#include "action_interfaces/msg/detail/bounding_box__functions.h"  // hook_box, lowpoint_box, tip_box
#include "action_interfaces/msg/detail/uv__functions.h"  // uv_hook, uv_lowpoint, uv_tip
#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name
#include "sensor_msgs/msg/detail/image__functions.h"  // hook_mask, lowpoint_mask, skeleton_mask, tip_mask

// forward declare type support functions
size_t get_serialized_size_action_interfaces__msg__BoundingBox(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_action_interfaces__msg__BoundingBox(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interfaces, msg, BoundingBox)();
size_t get_serialized_size_action_interfaces__msg__UV(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_action_interfaces__msg__UV(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interfaces, msg, UV)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_action_interfaces
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_action_interfaces
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();


using _Hook__ros_msg_type = action_interfaces__msg__Hook;

static bool _Hook__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Hook__ros_msg_type * ros_message = static_cast<const _Hook__ros_msg_type *>(untyped_ros_message);
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

  // Field name: hook_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, BoundingBox
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->hook_box, cdr))
    {
      return false;
    }
  }

  // Field name: tip_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, BoundingBox
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tip_box, cdr))
    {
      return false;
    }
  }

  // Field name: lowpoint_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, BoundingBox
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->lowpoint_box, cdr))
    {
      return false;
    }
  }

  // Field name: hook_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->hook_mask, cdr))
    {
      return false;
    }
  }

  // Field name: tip_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tip_mask, cdr))
    {
      return false;
    }
  }

  // Field name: lowpoint_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->lowpoint_mask, cdr))
    {
      return false;
    }
  }

  // Field name: skeleton_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->skeleton_mask, cdr))
    {
      return false;
    }
  }

  // Field name: conf_hook
  {
    cdr << ros_message->conf_hook;
  }

  // Field name: conf_tip
  {
    cdr << ros_message->conf_tip;
  }

  // Field name: conf_lowpoint
  {
    cdr << ros_message->conf_lowpoint;
  }

  // Field name: uv_hook
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, UV
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->uv_hook, cdr))
    {
      return false;
    }
  }

  // Field name: uv_tip
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, UV
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->uv_tip, cdr))
    {
      return false;
    }
  }

  // Field name: uv_lowpoint
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, UV
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->uv_lowpoint, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Hook__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Hook__ros_msg_type * ros_message = static_cast<_Hook__ros_msg_type *>(untyped_ros_message);
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

  // Field name: hook_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, BoundingBox
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->hook_box))
    {
      return false;
    }
  }

  // Field name: tip_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, BoundingBox
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tip_box))
    {
      return false;
    }
  }

  // Field name: lowpoint_box
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, BoundingBox
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->lowpoint_box))
    {
      return false;
    }
  }

  // Field name: hook_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->hook_mask))
    {
      return false;
    }
  }

  // Field name: tip_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tip_mask))
    {
      return false;
    }
  }

  // Field name: lowpoint_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->lowpoint_mask))
    {
      return false;
    }
  }

  // Field name: skeleton_mask
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->skeleton_mask))
    {
      return false;
    }
  }

  // Field name: conf_hook
  {
    cdr >> ros_message->conf_hook;
  }

  // Field name: conf_tip
  {
    cdr >> ros_message->conf_tip;
  }

  // Field name: conf_lowpoint
  {
    cdr >> ros_message->conf_lowpoint;
  }

  // Field name: uv_hook
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, UV
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->uv_hook))
    {
      return false;
    }
  }

  // Field name: uv_tip
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, UV
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->uv_tip))
    {
      return false;
    }
  }

  // Field name: uv_lowpoint
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, action_interfaces, msg, UV
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->uv_lowpoint))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_action_interfaces
size_t get_serialized_size_action_interfaces__msg__Hook(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Hook__ros_msg_type * ros_message = static_cast<const _Hook__ros_msg_type *>(untyped_ros_message);
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
  // field.name hook_box

  current_alignment += get_serialized_size_action_interfaces__msg__BoundingBox(
    &(ros_message->hook_box), current_alignment);
  // field.name tip_box

  current_alignment += get_serialized_size_action_interfaces__msg__BoundingBox(
    &(ros_message->tip_box), current_alignment);
  // field.name lowpoint_box

  current_alignment += get_serialized_size_action_interfaces__msg__BoundingBox(
    &(ros_message->lowpoint_box), current_alignment);
  // field.name hook_mask

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->hook_mask), current_alignment);
  // field.name tip_mask

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->tip_mask), current_alignment);
  // field.name lowpoint_mask

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->lowpoint_mask), current_alignment);
  // field.name skeleton_mask

  current_alignment += get_serialized_size_sensor_msgs__msg__Image(
    &(ros_message->skeleton_mask), current_alignment);
  // field.name conf_hook
  {
    size_t item_size = sizeof(ros_message->conf_hook);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name conf_tip
  {
    size_t item_size = sizeof(ros_message->conf_tip);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name conf_lowpoint
  {
    size_t item_size = sizeof(ros_message->conf_lowpoint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name uv_hook

  current_alignment += get_serialized_size_action_interfaces__msg__UV(
    &(ros_message->uv_hook), current_alignment);
  // field.name uv_tip

  current_alignment += get_serialized_size_action_interfaces__msg__UV(
    &(ros_message->uv_tip), current_alignment);
  // field.name uv_lowpoint

  current_alignment += get_serialized_size_action_interfaces__msg__UV(
    &(ros_message->uv_lowpoint), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Hook__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_action_interfaces__msg__Hook(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_action_interfaces
size_t max_serialized_size_action_interfaces__msg__Hook(
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
  // member: hook_box
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_action_interfaces__msg__BoundingBox(
        full_bounded, current_alignment);
    }
  }
  // member: tip_box
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_action_interfaces__msg__BoundingBox(
        full_bounded, current_alignment);
    }
  }
  // member: lowpoint_box
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_action_interfaces__msg__BoundingBox(
        full_bounded, current_alignment);
    }
  }
  // member: hook_mask
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }
  // member: tip_mask
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }
  // member: lowpoint_mask
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }
  // member: skeleton_mask
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }
  // member: conf_hook
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: conf_tip
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: conf_lowpoint
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: uv_hook
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_action_interfaces__msg__UV(
        full_bounded, current_alignment);
    }
  }
  // member: uv_tip
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_action_interfaces__msg__UV(
        full_bounded, current_alignment);
    }
  }
  // member: uv_lowpoint
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_action_interfaces__msg__UV(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Hook__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_action_interfaces__msg__Hook(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Hook = {
  "action_interfaces::msg",
  "Hook",
  _Hook__cdr_serialize,
  _Hook__cdr_deserialize,
  _Hook__get_serialized_size,
  _Hook__max_serialized_size
};

static rosidl_message_type_support_t _Hook__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Hook,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interfaces, msg, Hook)() {
  return &_Hook__type_support;
}

#if defined(__cplusplus)
}
#endif
