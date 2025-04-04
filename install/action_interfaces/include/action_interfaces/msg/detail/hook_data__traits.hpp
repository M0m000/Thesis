// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__TRAITS_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__TRAITS_HPP_

#include "action_interfaces/msg/detail/hook_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::msg::HookData>()
{
  return "action_interfaces::msg::HookData";
}

template<>
inline const char * name<action_interfaces::msg::HookData>()
{
  return "action_interfaces/msg/HookData";
}

template<>
struct has_fixed_size<action_interfaces::msg::HookData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::msg::HookData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::msg::HookData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__TRAITS_HPP_
