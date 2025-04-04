// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/GetSafetyMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_SAFETY_MODE__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__GET_SAFETY_MODE__BUILDER_HPP_

#include "kr_msgs/srv/detail/get_safety_mode__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetSafetyMode_Request>()
{
  return ::kr_msgs::srv::GetSafetyMode_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSafetyMode_Response_success
{
public:
  explicit Init_GetSafetyMode_Response_success(::kr_msgs::srv::GetSafetyMode_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetSafetyMode_Response success(::kr_msgs::srv::GetSafetyMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetSafetyMode_Response msg_;
};

class Init_GetSafetyMode_Response_mode
{
public:
  Init_GetSafetyMode_Response_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSafetyMode_Response_success mode(::kr_msgs::srv::GetSafetyMode_Response::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_GetSafetyMode_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::GetSafetyMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetSafetyMode_Response>()
{
  return kr_msgs::srv::builder::Init_GetSafetyMode_Response_mode();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_SAFETY_MODE__BUILDER_HPP_
