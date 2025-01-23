// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK__TRAITS_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK__TRAITS_HPP_

#include "action_interfaces/msg/detail/hook__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'hook_box'
// Member 'tip_box'
// Member 'lowpoint_box'
#include "action_interfaces/msg/detail/bounding_box__traits.hpp"
// Member 'hook_mask'
// Member 'tip_mask'
// Member 'lowpoint_mask'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'uv_hook'
// Member 'uv_tip'
// Member 'uv_lowpoint'
#include "action_interfaces/msg/detail/uv__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::msg::Hook>()
{
  return "action_interfaces::msg::Hook";
}

template<>
inline const char * name<action_interfaces::msg::Hook>()
{
  return "action_interfaces/msg/Hook";
}

template<>
struct has_fixed_size<action_interfaces::msg::Hook>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::msg::Hook>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::msg::Hook>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK__TRAITS_HPP_
