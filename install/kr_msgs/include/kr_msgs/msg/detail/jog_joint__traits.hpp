// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kr_msgs:msg/JogJoint.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__JOG_JOINT__TRAITS_HPP_
#define KR_MSGS__MSG__DETAIL__JOG_JOINT__TRAITS_HPP_

#include "kr_msgs/msg/detail/jog_joint__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::msg::JogJoint>()
{
  return "kr_msgs::msg::JogJoint";
}

template<>
inline const char * name<kr_msgs::msg::JogJoint>()
{
  return "kr_msgs/msg/JogJoint";
}

template<>
struct has_fixed_size<kr_msgs::msg::JogJoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kr_msgs::msg::JogJoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kr_msgs::msg::JogJoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KR_MSGS__MSG__DETAIL__JOG_JOINT__TRAITS_HPP_
