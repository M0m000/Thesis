// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/system_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kr_msgs/msg/detail/system_state__struct.h"
#include "kr_msgs/msg/detail/system_state__functions.h"
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

#include "kr_msgs/msg/detail/quadrature__functions.h"  // iob_quadratures
#include "kr_msgs/msg/detail/robot_mode__functions.h"  // robot_mode
#include "kr_msgs/msg/detail/robot_state__functions.h"  // robot_state

// forward declare type support functions
size_t get_serialized_size_kr_msgs__msg__Quadrature(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_kr_msgs__msg__Quadrature(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, Quadrature)();
size_t get_serialized_size_kr_msgs__msg__RobotMode(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_kr_msgs__msg__RobotMode(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, RobotMode)();
size_t get_serialized_size_kr_msgs__msg__RobotState(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_kr_msgs__msg__RobotState(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, RobotState)();


using _SystemState__ros_msg_type = kr_msgs__msg__SystemState;

static bool _SystemState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SystemState__ros_msg_type * ros_message = static_cast<const _SystemState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_mode
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, RobotMode
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->robot_mode, cdr))
    {
      return false;
    }
  }

  // Field name: robot_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, RobotState
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->robot_state, cdr))
    {
      return false;
    }
  }

  // Field name: sensed_pos
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensed_pos;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: sensed_vel
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensed_vel;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: sensed_trq
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensed_trq;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_pos
  {
    size_t size = 7;
    auto array_ptr = ros_message->target_pos;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_vel
  {
    size_t size = 7;
    auto array_ptr = ros_message->target_vel;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_trq
  {
    size_t size = 7;
    auto array_ptr = ros_message->target_trq;
    cdr.serializeArray(array_ptr, size);
  }

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

  // Field name: iob_digital_out
  {
    size_t size = 8;
    auto array_ptr = ros_message->iob_digital_out;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_relays
  {
    size_t size = 4;
    auto array_ptr = ros_message->iob_relays;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_current_out
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_current_out;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_voltage_out
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_voltage_out;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_digital_in
  {
    size_t size = 16;
    auto array_ptr = ros_message->iob_digital_in;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_safe_in
  {
    size_t size = 4;
    auto array_ptr = ros_message->iob_safe_in;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_current_in
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_current_in;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_voltage_in
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_voltage_in;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: iob_quadratures
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, Quadrature
      )()->data);
    size_t size = 2;
    auto array_ptr = ros_message->iob_quadratures;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: tio_digital_out
  {
    size_t size = 4;
    auto array_ptr = ros_message->tio_digital_out;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tio_power_supply
  {
    size_t size = 3;
    auto array_ptr = ros_message->tio_power_supply;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tio_analog_out
  {
    size_t size = 2;
    auto array_ptr = ros_message->tio_analog_out;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tio_current_in
  {
    size_t size = 1;
    auto array_ptr = ros_message->tio_current_in;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tio_voltage_in
  {
    size_t size = 4;
    auto array_ptr = ros_message->tio_voltage_in;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: e_stop
  {
    cdr << (ros_message->e_stop ? true : false);
  }

  // Field name: p_stop
  {
    cdr << (ros_message->p_stop ? true : false);
  }

  // Field name: toggle
  {
    cdr << (ros_message->toggle ? true : false);
  }

  // Field name: backdrive
  {
    cdr << (ros_message->backdrive ? true : false);
  }

  return true;
}

static bool _SystemState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SystemState__ros_msg_type * ros_message = static_cast<_SystemState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_mode
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, RobotMode
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->robot_mode))
    {
      return false;
    }
  }

  // Field name: robot_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, RobotState
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->robot_state))
    {
      return false;
    }
  }

  // Field name: sensed_pos
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensed_pos;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: sensed_vel
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensed_vel;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: sensed_trq
  {
    size_t size = 7;
    auto array_ptr = ros_message->sensed_trq;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_pos
  {
    size_t size = 7;
    auto array_ptr = ros_message->target_pos;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_vel
  {
    size_t size = 7;
    auto array_ptr = ros_message->target_vel;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_trq
  {
    size_t size = 7;
    auto array_ptr = ros_message->target_trq;
    cdr.deserializeArray(array_ptr, size);
  }

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

  // Field name: iob_digital_out
  {
    size_t size = 8;
    auto array_ptr = ros_message->iob_digital_out;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_relays
  {
    size_t size = 4;
    auto array_ptr = ros_message->iob_relays;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_current_out
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_current_out;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_voltage_out
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_voltage_out;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_digital_in
  {
    size_t size = 16;
    auto array_ptr = ros_message->iob_digital_in;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_safe_in
  {
    size_t size = 4;
    auto array_ptr = ros_message->iob_safe_in;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_current_in
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_current_in;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_voltage_in
  {
    size_t size = 2;
    auto array_ptr = ros_message->iob_voltage_in;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: iob_quadratures
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, kr_msgs, msg, Quadrature
      )()->data);
    size_t size = 2;
    auto array_ptr = ros_message->iob_quadratures;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: tio_digital_out
  {
    size_t size = 4;
    auto array_ptr = ros_message->tio_digital_out;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tio_power_supply
  {
    size_t size = 3;
    auto array_ptr = ros_message->tio_power_supply;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tio_analog_out
  {
    size_t size = 2;
    auto array_ptr = ros_message->tio_analog_out;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tio_current_in
  {
    size_t size = 1;
    auto array_ptr = ros_message->tio_current_in;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tio_voltage_in
  {
    size_t size = 4;
    auto array_ptr = ros_message->tio_voltage_in;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: e_stop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->e_stop = tmp ? true : false;
  }

  // Field name: p_stop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->p_stop = tmp ? true : false;
  }

  // Field name: toggle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->toggle = tmp ? true : false;
  }

  // Field name: backdrive
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->backdrive = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t get_serialized_size_kr_msgs__msg__SystemState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SystemState__ros_msg_type * ros_message = static_cast<const _SystemState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name robot_mode

  current_alignment += get_serialized_size_kr_msgs__msg__RobotMode(
    &(ros_message->robot_mode), current_alignment);
  // field.name robot_state

  current_alignment += get_serialized_size_kr_msgs__msg__RobotState(
    &(ros_message->robot_state), current_alignment);
  // field.name sensed_pos
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->sensed_pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sensed_vel
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->sensed_vel;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sensed_trq
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->sensed_trq;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_pos
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->target_pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_vel
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->target_vel;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_trq
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->target_trq;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
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
  // field.name iob_digital_out
  {
    size_t array_size = 8;
    auto array_ptr = ros_message->iob_digital_out;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_relays
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->iob_relays;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_current_out
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->iob_current_out;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_voltage_out
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->iob_voltage_out;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_digital_in
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->iob_digital_in;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_safe_in
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->iob_safe_in;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_current_in
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->iob_current_in;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_voltage_in
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->iob_voltage_in;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name iob_quadratures
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->iob_quadratures;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_kr_msgs__msg__Quadrature(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name tio_digital_out
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->tio_digital_out;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tio_power_supply
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->tio_power_supply;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tio_analog_out
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->tio_analog_out;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tio_current_in
  {
    size_t array_size = 1;
    auto array_ptr = ros_message->tio_current_in;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tio_voltage_in
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->tio_voltage_in;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name e_stop
  {
    size_t item_size = sizeof(ros_message->e_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_stop
  {
    size_t item_size = sizeof(ros_message->p_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name toggle
  {
    size_t item_size = sizeof(ros_message->toggle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name backdrive
  {
    size_t item_size = sizeof(ros_message->backdrive);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SystemState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kr_msgs__msg__SystemState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kr_msgs
size_t max_serialized_size_kr_msgs__msg__SystemState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: robot_mode
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_kr_msgs__msg__RobotMode(
        full_bounded, current_alignment);
    }
  }
  // member: robot_state
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_kr_msgs__msg__RobotState(
        full_bounded, current_alignment);
    }
  }
  // member: sensed_pos
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sensed_vel
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sensed_trq
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: target_pos
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: target_vel
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: target_trq
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
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
  // member: iob_digital_out
  {
    size_t array_size = 8;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: iob_relays
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: iob_current_out
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: iob_voltage_out
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: iob_digital_in
  {
    size_t array_size = 16;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: iob_safe_in
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: iob_current_in
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: iob_voltage_in
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: iob_quadratures
  {
    size_t array_size = 2;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_kr_msgs__msg__Quadrature(
        full_bounded, current_alignment);
    }
  }
  // member: tio_digital_out
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: tio_power_supply
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: tio_analog_out
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: tio_current_in
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: tio_voltage_in
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: e_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: p_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: toggle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: backdrive
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _SystemState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_kr_msgs__msg__SystemState(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SystemState = {
  "kr_msgs::msg",
  "SystemState",
  _SystemState__cdr_serialize,
  _SystemState__cdr_deserialize,
  _SystemState__get_serialized_size,
  _SystemState__max_serialized_size
};

static rosidl_message_type_support_t _SystemState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SystemState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kr_msgs, msg, SystemState)() {
  return &_SystemState__type_support;
}

#if defined(__cplusplus)
}
#endif
