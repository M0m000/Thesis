// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kr_msgs:msg/FollowLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__TRAITS_HPP_
#define KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__TRAITS_HPP_

#include "kr_msgs/msg/detail/follow_linear__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::msg::FollowLinear>()
{
  return "kr_msgs::msg::FollowLinear";
}

template<>
inline const char * name<kr_msgs::msg::FollowLinear>()
{
  return "kr_msgs/msg/FollowLinear";
}

template<>
struct has_fixed_size<kr_msgs::msg::FollowLinear>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kr_msgs::msg::FollowLinear>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kr_msgs::msg::FollowLinear>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__TRAITS_HPP_
