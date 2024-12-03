// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/ConfigAnalogOutput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__CONFIG_ANALOG_OUTPUT__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__CONFIG_ANALOG_OUTPUT__BUILDER_HPP_

#include "kr_msgs/srv/detail/config_analog_output__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigAnalogOutput_Request_type
{
public:
  explicit Init_ConfigAnalogOutput_Request_type(::kr_msgs::srv::ConfigAnalogOutput_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::ConfigAnalogOutput_Request type(::kr_msgs::srv::ConfigAnalogOutput_Request::_type_type arg)
  {
    msg_.type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::ConfigAnalogOutput_Request msg_;
};

class Init_ConfigAnalogOutput_Request_index
{
public:
  Init_ConfigAnalogOutput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigAnalogOutput_Request_type index(::kr_msgs::srv::ConfigAnalogOutput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_ConfigAnalogOutput_Request_type(msg_);
  }

private:
  ::kr_msgs::srv::ConfigAnalogOutput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::ConfigAnalogOutput_Request>()
{
  return kr_msgs::srv::builder::Init_ConfigAnalogOutput_Request_index();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigAnalogOutput_Response_success
{
public:
  Init_ConfigAnalogOutput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::ConfigAnalogOutput_Response success(::kr_msgs::srv::ConfigAnalogOutput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::ConfigAnalogOutput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::ConfigAnalogOutput_Response>()
{
  return kr_msgs::srv::builder::Init_ConfigAnalogOutput_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__CONFIG_ANALOG_OUTPUT__BUILDER_HPP_
