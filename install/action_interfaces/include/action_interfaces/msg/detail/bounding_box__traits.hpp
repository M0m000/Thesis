// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_

#include "action_interfaces/msg/detail/bounding_box__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::msg::BoundingBox>()
{
  return "action_interfaces::msg::BoundingBox";
}

template<>
inline const char * name<action_interfaces::msg::BoundingBox>()
{
  return "action_interfaces/msg/BoundingBox";
}

template<>
struct has_fixed_size<action_interfaces::msg::BoundingBox>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interfaces::msg::BoundingBox>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interfaces::msg::BoundingBox>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
