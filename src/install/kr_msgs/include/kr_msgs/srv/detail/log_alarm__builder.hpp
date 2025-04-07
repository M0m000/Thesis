// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/LogAlarm.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__LOG_ALARM__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__LOG_ALARM__BUILDER_HPP_

#include "kr_msgs/srv/detail/log_alarm__struct.hpp"
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
auto build<::kr_msgs::srv::LogAlarm_Request>()
{
  return ::kr_msgs::srv::LogAlarm_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_LogAlarm_Response_success
{
public:
  explicit Init_LogAlarm_Response_success(::kr_msgs::srv::LogAlarm_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::LogAlarm_Response success(::kr_msgs::srv::LogAlarm_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::LogAlarm_Response msg_;
};

class Init_LogAlarm_Response_safety_events
{
public:
  Init_LogAlarm_Response_safety_events()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LogAlarm_Response_success safety_events(::kr_msgs::srv::LogAlarm_Response::_safety_events_type arg)
  {
    msg_.safety_events = std::move(arg);
    return Init_LogAlarm_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::LogAlarm_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::LogAlarm_Response>()
{
  return kr_msgs::srv::builder::Init_LogAlarm_Response_safety_events();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__LOG_ALARM__BUILDER_HPP_
