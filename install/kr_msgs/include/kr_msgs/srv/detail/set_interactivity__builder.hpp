// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/SetInteractivity.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_INTERACTIVITY__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__SET_INTERACTIVITY__BUILDER_HPP_

#include "kr_msgs/srv/detail/set_interactivity__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetInteractivity_Request_enable
{
public:
  Init_SetInteractivity_Request_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::SetInteractivity_Request enable(::kr_msgs::srv::SetInteractivity_Request::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetInteractivity_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetInteractivity_Request>()
{
  return kr_msgs::srv::builder::Init_SetInteractivity_Request_enable();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetInteractivity_Response_success
{
public:
  Init_SetInteractivity_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::SetInteractivity_Response success(::kr_msgs::srv::SetInteractivity_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetInteractivity_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetInteractivity_Response>()
{
  return kr_msgs::srv::builder::Init_SetInteractivity_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__SET_INTERACTIVITY__BUILDER_HPP_
