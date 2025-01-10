// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/SafetyEvent.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_EVENT__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__SAFETY_EVENT__BUILDER_HPP_

#include "kr_msgs/msg/detail/safety_event__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_SafetyEvent_timestamp
{
public:
  explicit Init_SafetyEvent_timestamp(::kr_msgs::msg::SafetyEvent & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::SafetyEvent timestamp(::kr_msgs::msg::SafetyEvent::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::SafetyEvent msg_;
};

class Init_SafetyEvent_code
{
public:
  explicit Init_SafetyEvent_code(::kr_msgs::msg::SafetyEvent & msg)
  : msg_(msg)
  {}
  Init_SafetyEvent_timestamp code(::kr_msgs::msg::SafetyEvent::_code_type arg)
  {
    msg_.code = std::move(arg);
    return Init_SafetyEvent_timestamp(msg_);
  }

private:
  ::kr_msgs::msg::SafetyEvent msg_;
};

class Init_SafetyEvent_type
{
public:
  Init_SafetyEvent_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetyEvent_code type(::kr_msgs::msg::SafetyEvent::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_SafetyEvent_code(msg_);
  }

private:
  ::kr_msgs::msg::SafetyEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::SafetyEvent>()
{
  return kr_msgs::msg::builder::Init_SafetyEvent_type();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_EVENT__BUILDER_HPP_
