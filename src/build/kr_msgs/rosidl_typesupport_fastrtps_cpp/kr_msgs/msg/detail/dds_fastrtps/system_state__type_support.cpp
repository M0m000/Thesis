// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/system_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "kr_msgs/msg/detail/system_state__struct.hpp"

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
  const kr_msgs::msg::RobotMode &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  kr_msgs::msg::RobotMode &);
size_t get_serialized_size(
  const kr_msgs::msg::RobotMode &,
  size_t current_alignment);
size_t
max_serialized_size_RobotMode(
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
bool cdr_serialize(
  const kr_msgs::msg::RobotState &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  kr_msgs::msg::RobotState &);
size_t get_serialized_size(
  const kr_msgs::msg::RobotState &,
  size_t current_alignment);
size_t
max_serialized_size_RobotState(
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
bool cdr_serialize(
  const kr_msgs::msg::Quadrature &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  kr_msgs::msg::Quadrature &);
size_t get_serialized_size(
  const kr_msgs::msg::Quadrature &,
  size_t current_alignment);
size_t
max_serialized_size_Quadrature(
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
  const kr_msgs::msg::SystemState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: robot_mode
  kr_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.robot_mode,
    cdr);
  // Member: robot_state
  kr_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.robot_state,
    cdr);
  // Member: sensed_pos
  {
    cdr << ros_message.sensed_pos;
  }
  // Member: sensed_vel
  {
    cdr << ros_message.sensed_vel;
  }
  // Member: sensed_trq
  {
    cdr << ros_message.sensed_trq;
  }
  // Member: target_pos
  {
    cdr << ros_message.target_pos;
  }
  // Member: target_vel
  {
    cdr << ros_message.target_vel;
  }
  // Member: target_trq
  {
    cdr << ros_message.target_trq;
  }
  // Member: pos
  {
    cdr << ros_message.pos;
  }
  // Member: rot
  {
    cdr << ros_message.rot;
  }
  // Member: iob_digital_out
  {
    cdr << ros_message.iob_digital_out;
  }
  // Member: iob_relays
  {
    cdr << ros_message.iob_relays;
  }
  // Member: iob_current_out
  {
    cdr << ros_message.iob_current_out;
  }
  // Member: iob_voltage_out
  {
    cdr << ros_message.iob_voltage_out;
  }
  // Member: iob_digital_in
  {
    cdr << ros_message.iob_digital_in;
  }
  // Member: iob_safe_in
  {
    cdr << ros_message.iob_safe_in;
  }
  // Member: iob_current_in
  {
    cdr << ros_message.iob_current_in;
  }
  // Member: iob_voltage_in
  {
    cdr << ros_message.iob_voltage_in;
  }
  // Member: iob_quadratures
  {
    for (size_t i = 0; i < 2; i++) {
      kr_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.iob_quadratures[i],
        cdr);
    }
  }
  // Member: tio_digital_out
  {
    cdr << ros_message.tio_digital_out;
  }
  // Member: tio_power_supply
  {
    cdr << ros_message.tio_power_supply;
  }
  // Member: tio_analog_out
  {
    cdr << ros_message.tio_analog_out;
  }
  // Member: tio_current_in
  {
    cdr << ros_message.tio_current_in;
  }
  // Member: tio_voltage_in
  {
    cdr << ros_message.tio_voltage_in;
  }
  // Member: e_stop
  cdr << (ros_message.e_stop ? true : false);
  // Member: p_stop
  cdr << (ros_message.p_stop ? true : false);
  // Member: toggle
  cdr << (ros_message.toggle ? true : false);
  // Member: backdrive
  cdr << (ros_message.backdrive ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  kr_msgs::msg::SystemState & ros_message)
{
  // Member: robot_mode
  kr_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.robot_mode);

  // Member: robot_state
  kr_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.robot_state);

  // Member: sensed_pos
  {
    cdr >> ros_message.sensed_pos;
  }

  // Member: sensed_vel
  {
    cdr >> ros_message.sensed_vel;
  }

  // Member: sensed_trq
  {
    cdr >> ros_message.sensed_trq;
  }

  // Member: target_pos
  {
    cdr >> ros_message.target_pos;
  }

  // Member: target_vel
  {
    cdr >> ros_message.target_vel;
  }

  // Member: target_trq
  {
    cdr >> ros_message.target_trq;
  }

  // Member: pos
  {
    cdr >> ros_message.pos;
  }

  // Member: rot
  {
    cdr >> ros_message.rot;
  }

  // Member: iob_digital_out
  {
    cdr >> ros_message.iob_digital_out;
  }

  // Member: iob_relays
  {
    cdr >> ros_message.iob_relays;
  }

  // Member: iob_current_out
  {
    cdr >> ros_message.iob_current_out;
  }

  // Member: iob_voltage_out
  {
    cdr >> ros_message.iob_voltage_out;
  }

  // Member: iob_digital_in
  {
    cdr >> ros_message.iob_digital_in;
  }

  // Member: iob_safe_in
  {
    cdr >> ros_message.iob_safe_in;
  }

  // Member: iob_current_in
  {
    cdr >> ros_message.iob_current_in;
  }

  // Member: iob_voltage_in
  {
    cdr >> ros_message.iob_voltage_in;
  }

  // Member: iob_quadratures
  {
    for (size_t i = 0; i < 2; i++) {
      kr_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.iob_quadratures[i]);
    }
  }

  // Member: tio_digital_out
  {
    cdr >> ros_message.tio_digital_out;
  }

  // Member: tio_power_supply
  {
    cdr >> ros_message.tio_power_supply;
  }

  // Member: tio_analog_out
  {
    cdr >> ros_message.tio_analog_out;
  }

  // Member: tio_current_in
  {
    cdr >> ros_message.tio_current_in;
  }

  // Member: tio_voltage_in
  {
    cdr >> ros_message.tio_voltage_in;
  }

  // Member: e_stop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.e_stop = tmp ? true : false;
  }

  // Member: p_stop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.p_stop = tmp ? true : false;
  }

  // Member: toggle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.toggle = tmp ? true : false;
  }

  // Member: backdrive
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.backdrive = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
get_serialized_size(
  const kr_msgs::msg::SystemState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: robot_mode

  current_alignment +=
    kr_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.robot_mode, current_alignment);
  // Member: robot_state

  current_alignment +=
    kr_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.robot_state, current_alignment);
  // Member: sensed_pos
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.sensed_pos[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sensed_vel
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.sensed_vel[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sensed_trq
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.sensed_trq[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_pos
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.target_pos[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_vel
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.target_vel[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_trq
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.target_trq[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.pos[0]);
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
  // Member: iob_digital_out
  {
    size_t array_size = 8;
    size_t item_size = sizeof(ros_message.iob_digital_out[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_relays
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.iob_relays[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_current_out
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.iob_current_out[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_voltage_out
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.iob_voltage_out[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_digital_in
  {
    size_t array_size = 16;
    size_t item_size = sizeof(ros_message.iob_digital_in[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_safe_in
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.iob_safe_in[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_current_in
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.iob_current_in[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_voltage_in
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.iob_voltage_in[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: iob_quadratures
  {
    size_t array_size = 2;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        kr_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.iob_quadratures[index], current_alignment);
    }
  }
  // Member: tio_digital_out
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.tio_digital_out[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tio_power_supply
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.tio_power_supply[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tio_analog_out
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.tio_analog_out[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tio_current_in
  {
    size_t array_size = 1;
    size_t item_size = sizeof(ros_message.tio_current_in[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tio_voltage_in
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.tio_voltage_in[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: e_stop
  {
    size_t item_size = sizeof(ros_message.e_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_stop
  {
    size_t item_size = sizeof(ros_message.p_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: toggle
  {
    size_t item_size = sizeof(ros_message.toggle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: backdrive
  {
    size_t item_size = sizeof(ros_message.backdrive);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kr_msgs
max_serialized_size_SystemState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: robot_mode
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        kr_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_RobotMode(
        full_bounded, current_alignment);
    }
  }

  // Member: robot_state
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        kr_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_RobotState(
        full_bounded, current_alignment);
    }
  }

  // Member: sensed_pos
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: sensed_vel
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: sensed_trq
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: target_pos
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: target_vel
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: target_trq
  {
    size_t array_size = 7;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pos
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

  // Member: iob_digital_out
  {
    size_t array_size = 8;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: iob_relays
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: iob_current_out
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: iob_voltage_out
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: iob_digital_in
  {
    size_t array_size = 16;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: iob_safe_in
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: iob_current_in
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: iob_voltage_in
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: iob_quadratures
  {
    size_t array_size = 2;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        kr_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Quadrature(
        full_bounded, current_alignment);
    }
  }

  // Member: tio_digital_out
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: tio_power_supply
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: tio_analog_out
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: tio_current_in
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: tio_voltage_in
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: e_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: p_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: toggle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: backdrive
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _SystemState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const kr_msgs::msg::SystemState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SystemState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<kr_msgs::msg::SystemState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SystemState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const kr_msgs::msg::SystemState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SystemState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SystemState(full_bounded, 0);
}

static message_type_support_callbacks_t _SystemState__callbacks = {
  "kr_msgs::msg",
  "SystemState",
  _SystemState__cdr_serialize,
  _SystemState__cdr_deserialize,
  _SystemState__get_serialized_size,
  _SystemState__max_serialized_size
};

static rosidl_message_type_support_t _SystemState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SystemState__callbacks,
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
get_message_type_support_handle<kr_msgs::msg::SystemState>()
{
  return &kr_msgs::msg::typesupport_fastrtps_cpp::_SystemState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kr_msgs, msg, SystemState)() {
  return &kr_msgs::msg::typesupport_fastrtps_cpp::_SystemState__handle;
}

#ifdef __cplusplus
}
#endif
