// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/SetAnalogOutput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_ANALOG_OUTPUT__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__SET_ANALOG_OUTPUT__BUILDER_HPP_

#include "kr_msgs/srv/detail/set_analog_output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetAnalogOutput_Request_value
{
public:
  explicit Init_SetAnalogOutput_Request_value(::kr_msgs::srv::SetAnalogOutput_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::SetAnalogOutput_Request value(::kr_msgs::srv::SetAnalogOutput_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetAnalogOutput_Request msg_;
};

class Init_SetAnalogOutput_Request_index
{
public:
  Init_SetAnalogOutput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetAnalogOutput_Request_value index(::kr_msgs::srv::SetAnalogOutput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_SetAnalogOutput_Request_value(msg_);
  }

private:
  ::kr_msgs::srv::SetAnalogOutput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetAnalogOutput_Request>()
{
  return kr_msgs::srv::builder::Init_SetAnalogOutput_Request_index();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetAnalogOutput_Response_success
{
public:
  Init_SetAnalogOutput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::SetAnalogOutput_Response success(::kr_msgs::srv::SetAnalogOutput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetAnalogOutput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetAnalogOutput_Response>()
{
  return kr_msgs::srv::builder::Init_SetAnalogOutput_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__SET_ANALOG_OUTPUT__BUILDER_HPP_
