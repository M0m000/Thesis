// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/GetAnalogInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_ANALOG_INPUT__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__GET_ANALOG_INPUT__BUILDER_HPP_

#include "kr_msgs/srv/detail/get_analog_input__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetAnalogInput_Request_index
{
public:
  Init_GetAnalogInput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::GetAnalogInput_Request index(::kr_msgs::srv::GetAnalogInput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetAnalogInput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetAnalogInput_Request>()
{
  return kr_msgs::srv::builder::Init_GetAnalogInput_Request_index();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetAnalogInput_Response_success
{
public:
  explicit Init_GetAnalogInput_Response_success(::kr_msgs::srv::GetAnalogInput_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetAnalogInput_Response success(::kr_msgs::srv::GetAnalogInput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetAnalogInput_Response msg_;
};

class Init_GetAnalogInput_Response_value
{
public:
  Init_GetAnalogInput_Response_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetAnalogInput_Response_success value(::kr_msgs::srv::GetAnalogInput_Response::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_GetAnalogInput_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::GetAnalogInput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetAnalogInput_Response>()
{
  return kr_msgs::srv::builder::Init_GetAnalogInput_Response_value();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_ANALOG_INPUT__BUILDER_HPP_
