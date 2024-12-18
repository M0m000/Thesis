// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:srv/GenerateFrame.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__TRAITS_HPP_
#define ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__TRAITS_HPP_

#include "action_interfaces/srv/detail/generate_frame__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::srv::GenerateFrame_Request>()
{
  return "action_interfaces::srv::GenerateFrame_Request";
}

template<>
inline const char * name<action_interfaces::srv::GenerateFrame_Request>()
{
  return "action_interfaces/srv/GenerateFrame_Request";
}

template<>
struct has_fixed_size<action_interfaces::srv::GenerateFrame_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::srv::GenerateFrame_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::srv::GenerateFrame_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::srv::GenerateFrame_Response>()
{
  return "action_interfaces::srv::GenerateFrame_Response";
}

template<>
inline const char * name<action_interfaces::srv::GenerateFrame_Response>()
{
  return "action_interfaces/srv/GenerateFrame_Response";
}

template<>
struct has_fixed_size<action_interfaces::srv::GenerateFrame_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::srv::GenerateFrame_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::srv::GenerateFrame_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::srv::GenerateFrame>()
{
  return "action_interfaces::srv::GenerateFrame";
}

template<>
inline const char * name<action_interfaces::srv::GenerateFrame>()
{
  return "action_interfaces/srv/GenerateFrame";
}

template<>
struct has_fixed_size<action_interfaces::srv::GenerateFrame>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interfaces::srv::GenerateFrame_Request>::value &&
    has_fixed_size<action_interfaces::srv::GenerateFrame_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interfaces::srv::GenerateFrame>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interfaces::srv::GenerateFrame_Request>::value &&
    has_bounded_size<action_interfaces::srv::GenerateFrame_Response>::value
  >
{
};

template<>
struct is_service<action_interfaces::srv::GenerateFrame>
  : std::true_type
{
};

template<>
struct is_service_request<action_interfaces::srv::GenerateFrame_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interfaces::srv::GenerateFrame_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__TRAITS_HPP_
