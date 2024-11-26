// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kr_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define KR_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include "kr_msgs/msg/detail/robot_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::msg::RobotState>()
{
  return "kr_msgs::msg::RobotState";
}

template<>
inline const char * name<kr_msgs::msg::RobotState>()
{
  return "kr_msgs/msg/RobotState";
}

template<>
struct has_fixed_size<kr_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<kr_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<kr_msgs::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
