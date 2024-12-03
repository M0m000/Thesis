// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "kr_msgs/msg/detail/system_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace kr_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SystemState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) kr_msgs::msg::SystemState(_init);
}

void SystemState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<kr_msgs::msg::SystemState *>(message_memory);
  typed_message->~SystemState();
}

size_t size_function__SystemState__sensed_pos(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__SystemState__sensed_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__sensed_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__sensed_vel(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__SystemState__sensed_vel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__sensed_vel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__sensed_trq(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__SystemState__sensed_trq(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__sensed_trq(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__target_pos(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__SystemState__target_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__target_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__target_vel(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__SystemState__target_vel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__target_vel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__target_trq(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__SystemState__target_trq(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__target_trq(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__pos(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__SystemState__pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__rot(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__SystemState__rot(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__rot(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_digital_out(const void * untyped_member)
{
  (void)untyped_member;
  return 8;
}

const void * get_const_function__SystemState__iob_digital_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 8> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_digital_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 8> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_relays(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__iob_relays(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_relays(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_current_out(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__iob_current_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_current_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_voltage_out(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__iob_voltage_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_voltage_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_digital_in(const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * get_const_function__SystemState__iob_digital_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 16> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_digital_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 16> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_safe_in(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__iob_safe_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_safe_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_current_in(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__iob_current_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_current_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_voltage_in(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__iob_voltage_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_voltage_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__iob_quadratures(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__iob_quadratures(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<kr_msgs::msg::Quadrature, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__iob_quadratures(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<kr_msgs::msg::Quadrature, 2> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__tio_digital_out(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__tio_digital_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tio_digital_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__tio_power_supply(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__SystemState__tio_power_supply(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tio_power_supply(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__tio_analog_out(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__tio_analog_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tio_analog_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__tio_current_in(const void * untyped_member)
{
  (void)untyped_member;
  return 1;
}

const void * get_const_function__SystemState__tio_current_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 1> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tio_current_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 1> *>(untyped_member);
  return &member[index];
}

size_t size_function__SystemState__tio_voltage_in(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__tio_voltage_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tio_voltage_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SystemState_message_member_array[28] = {
  {
    "robot_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<kr_msgs::msg::RobotMode>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, robot_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "robot_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<kr_msgs::msg::RobotState>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, robot_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sensed_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, sensed_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__sensed_pos,  // size() function pointer
    get_const_function__SystemState__sensed_pos,  // get_const(index) function pointer
    get_function__SystemState__sensed_pos,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sensed_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, sensed_vel),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__sensed_vel,  // size() function pointer
    get_const_function__SystemState__sensed_vel,  // get_const(index) function pointer
    get_function__SystemState__sensed_vel,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sensed_trq",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, sensed_trq),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__sensed_trq,  // size() function pointer
    get_const_function__SystemState__sensed_trq,  // get_const(index) function pointer
    get_function__SystemState__sensed_trq,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, target_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__target_pos,  // size() function pointer
    get_const_function__SystemState__target_pos,  // get_const(index) function pointer
    get_function__SystemState__target_pos,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, target_vel),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__target_vel,  // size() function pointer
    get_const_function__SystemState__target_vel,  // get_const(index) function pointer
    get_function__SystemState__target_vel,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_trq",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, target_trq),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__target_trq,  // size() function pointer
    get_const_function__SystemState__target_trq,  // get_const(index) function pointer
    get_function__SystemState__target_trq,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__pos,  // size() function pointer
    get_const_function__SystemState__pos,  // get_const(index) function pointer
    get_function__SystemState__pos,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, rot),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__rot,  // size() function pointer
    get_const_function__SystemState__rot,  // get_const(index) function pointer
    get_function__SystemState__rot,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_digital_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    8,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_digital_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_digital_out,  // size() function pointer
    get_const_function__SystemState__iob_digital_out,  // get_const(index) function pointer
    get_function__SystemState__iob_digital_out,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_relays",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_relays),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_relays,  // size() function pointer
    get_const_function__SystemState__iob_relays,  // get_const(index) function pointer
    get_function__SystemState__iob_relays,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_current_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_current_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_current_out,  // size() function pointer
    get_const_function__SystemState__iob_current_out,  // get_const(index) function pointer
    get_function__SystemState__iob_current_out,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_voltage_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_voltage_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_voltage_out,  // size() function pointer
    get_const_function__SystemState__iob_voltage_out,  // get_const(index) function pointer
    get_function__SystemState__iob_voltage_out,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_digital_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_digital_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_digital_in,  // size() function pointer
    get_const_function__SystemState__iob_digital_in,  // get_const(index) function pointer
    get_function__SystemState__iob_digital_in,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_safe_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_safe_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_safe_in,  // size() function pointer
    get_const_function__SystemState__iob_safe_in,  // get_const(index) function pointer
    get_function__SystemState__iob_safe_in,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_current_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_current_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_current_in,  // size() function pointer
    get_const_function__SystemState__iob_current_in,  // get_const(index) function pointer
    get_function__SystemState__iob_current_in,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_voltage_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_voltage_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_voltage_in,  // size() function pointer
    get_const_function__SystemState__iob_voltage_in,  // get_const(index) function pointer
    get_function__SystemState__iob_voltage_in,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "iob_quadratures",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<kr_msgs::msg::Quadrature>(),  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, iob_quadratures),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__iob_quadratures,  // size() function pointer
    get_const_function__SystemState__iob_quadratures,  // get_const(index) function pointer
    get_function__SystemState__iob_quadratures,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tio_digital_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, tio_digital_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tio_digital_out,  // size() function pointer
    get_const_function__SystemState__tio_digital_out,  // get_const(index) function pointer
    get_function__SystemState__tio_digital_out,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tio_power_supply",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, tio_power_supply),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tio_power_supply,  // size() function pointer
    get_const_function__SystemState__tio_power_supply,  // get_const(index) function pointer
    get_function__SystemState__tio_power_supply,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tio_analog_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, tio_analog_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tio_analog_out,  // size() function pointer
    get_const_function__SystemState__tio_analog_out,  // get_const(index) function pointer
    get_function__SystemState__tio_analog_out,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tio_current_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    1,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, tio_current_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tio_current_in,  // size() function pointer
    get_const_function__SystemState__tio_current_in,  // get_const(index) function pointer
    get_function__SystemState__tio_current_in,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tio_voltage_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, tio_voltage_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tio_voltage_in,  // size() function pointer
    get_const_function__SystemState__tio_voltage_in,  // get_const(index) function pointer
    get_function__SystemState__tio_voltage_in,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "e_stop",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, e_stop),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "p_stop",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, p_stop),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "toggle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, toggle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "backdrive",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SystemState, backdrive),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SystemState_message_members = {
  "kr_msgs::msg",  // message namespace
  "SystemState",  // message name
  28,  // number of fields
  sizeof(kr_msgs::msg::SystemState),
  SystemState_message_member_array,  // message members
  SystemState_init_function,  // function to initialize message memory (memory has to be allocated)
  SystemState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SystemState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SystemState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace kr_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<kr_msgs::msg::SystemState>()
{
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::SystemState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kr_msgs, msg, SystemState)() {
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::SystemState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
