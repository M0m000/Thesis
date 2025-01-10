// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SYSTEM_STATE__TRAITS_HPP_
#define KR_MSGS__MSG__DETAIL__SYSTEM_STATE__TRAITS_HPP_

#include "kr_msgs/msg/detail/system_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'robot_mode'
#include "kr_msgs/msg/detail/robot_mode__traits.hpp"
// Member 'robot_state'
#include "kr_msgs/msg/detail/robot_state__traits.hpp"
// Member 'iob_quadratures'
#include "kr_msgs/msg/detail/quadrature__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::msg::SystemState>()
{
  return "kr_msgs::msg::SystemState";
}

template<>
inline const char * name<kr_msgs::msg::SystemState>()
{
  return "kr_msgs/msg/SystemState";
}

template<>
struct has_fixed_size<kr_msgs::msg::SystemState>
  : std::integral_constant<bool, has_fixed_size<kr_msgs::msg::Quadrature>::value && has_fixed_size<kr_msgs::msg::RobotMode>::value && has_fixed_size<kr_msgs::msg::RobotState>::value> {};

template<>
struct has_bounded_size<kr_msgs::msg::SystemState>
  : std::integral_constant<bool, has_bounded_size<kr_msgs::msg::Quadrature>::value && has_bounded_size<kr_msgs::msg::RobotMode>::value && has_bounded_size<kr_msgs::msg::RobotState>::value> {};

template<>
struct is_message<kr_msgs::msg::SystemState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KR_MSGS__MSG__DETAIL__SYSTEM_STATE__TRAITS_HPP_
