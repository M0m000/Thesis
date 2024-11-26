// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kr_msgs:srv/GetRobotMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_ROBOT_MODE__TRAITS_HPP_
#define KR_MSGS__SRV__DETAIL__GET_ROBOT_MODE__TRAITS_HPP_

#include "kr_msgs/srv/detail/get_robot_mode__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::srv::GetRobotMode_Request>()
{
  return "kr_msgs::srv::GetRobotMode_Request";
}

template<>
inline const char * name<kr_msgs::srv::GetRobotMode_Request>()
{
  return "kr_msgs/srv/GetRobotMode_Request";
}

template<>
struct has_fixed_size<kr_msgs::srv::GetRobotMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kr_msgs::srv::GetRobotMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kr_msgs::srv::GetRobotMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'mode'
#include "kr_msgs/msg/detail/robot_mode__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::srv::GetRobotMode_Response>()
{
  return "kr_msgs::srv::GetRobotMode_Response";
}

template<>
inline const char * name<kr_msgs::srv::GetRobotMode_Response>()
{
  return "kr_msgs/srv/GetRobotMode_Response";
}

template<>
struct has_fixed_size<kr_msgs::srv::GetRobotMode_Response>
  : std::integral_constant<bool, has_fixed_size<kr_msgs::msg::RobotMode>::value> {};

template<>
struct has_bounded_size<kr_msgs::srv::GetRobotMode_Response>
  : std::integral_constant<bool, has_bounded_size<kr_msgs::msg::RobotMode>::value> {};

template<>
struct is_message<kr_msgs::srv::GetRobotMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::srv::GetRobotMode>()
{
  return "kr_msgs::srv::GetRobotMode";
}

template<>
inline const char * name<kr_msgs::srv::GetRobotMode>()
{
  return "kr_msgs/srv/GetRobotMode";
}

template<>
struct has_fixed_size<kr_msgs::srv::GetRobotMode>
  : std::integral_constant<
    bool,
    has_fixed_size<kr_msgs::srv::GetRobotMode_Request>::value &&
    has_fixed_size<kr_msgs::srv::GetRobotMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<kr_msgs::srv::GetRobotMode>
  : std::integral_constant<
    bool,
    has_bounded_size<kr_msgs::srv::GetRobotMode_Request>::value &&
    has_bounded_size<kr_msgs::srv::GetRobotMode_Response>::value
  >
{
};

template<>
struct is_service<kr_msgs::srv::GetRobotMode>
  : std::true_type
{
};

template<>
struct is_service_request<kr_msgs::srv::GetRobotMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kr_msgs::srv::GetRobotMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // KR_MSGS__SRV__DETAIL__GET_ROBOT_MODE__TRAITS_HPP_
