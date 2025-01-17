// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kr_msgs:srv/SelectJoggingFrame.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__TRAITS_HPP_
#define KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__TRAITS_HPP_

#include "kr_msgs/srv/detail/select_jogging_frame__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::srv::SelectJoggingFrame_Request>()
{
  return "kr_msgs::srv::SelectJoggingFrame_Request";
}

template<>
inline const char * name<kr_msgs::srv::SelectJoggingFrame_Request>()
{
  return "kr_msgs/srv/SelectJoggingFrame_Request";
}

template<>
struct has_fixed_size<kr_msgs::srv::SelectJoggingFrame_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kr_msgs::srv::SelectJoggingFrame_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kr_msgs::srv::SelectJoggingFrame_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::srv::SelectJoggingFrame_Response>()
{
  return "kr_msgs::srv::SelectJoggingFrame_Response";
}

template<>
inline const char * name<kr_msgs::srv::SelectJoggingFrame_Response>()
{
  return "kr_msgs/srv/SelectJoggingFrame_Response";
}

template<>
struct has_fixed_size<kr_msgs::srv::SelectJoggingFrame_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kr_msgs::srv::SelectJoggingFrame_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kr_msgs::srv::SelectJoggingFrame_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::srv::SelectJoggingFrame>()
{
  return "kr_msgs::srv::SelectJoggingFrame";
}

template<>
inline const char * name<kr_msgs::srv::SelectJoggingFrame>()
{
  return "kr_msgs/srv/SelectJoggingFrame";
}

template<>
struct has_fixed_size<kr_msgs::srv::SelectJoggingFrame>
  : std::integral_constant<
    bool,
    has_fixed_size<kr_msgs::srv::SelectJoggingFrame_Request>::value &&
    has_fixed_size<kr_msgs::srv::SelectJoggingFrame_Response>::value
  >
{
};

template<>
struct has_bounded_size<kr_msgs::srv::SelectJoggingFrame>
  : std::integral_constant<
    bool,
    has_bounded_size<kr_msgs::srv::SelectJoggingFrame_Request>::value &&
    has_bounded_size<kr_msgs::srv::SelectJoggingFrame_Response>::value
  >
{
};

template<>
struct is_service<kr_msgs::srv::SelectJoggingFrame>
  : std::true_type
{
};

template<>
struct is_service_request<kr_msgs::srv::SelectJoggingFrame_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kr_msgs::srv::SelectJoggingFrame_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__TRAITS_HPP_
