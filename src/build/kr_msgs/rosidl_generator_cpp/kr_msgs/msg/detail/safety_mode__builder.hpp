// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/SafetyMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_MODE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__SAFETY_MODE__BUILDER_HPP_

#include "kr_msgs/msg/detail/safety_mode__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_SafetyMode_val
{
public:
  Init_SafetyMode_val()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::msg::SafetyMode val(::kr_msgs::msg::SafetyMode::_val_type arg)
  {
    msg_.val = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::SafetyMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::SafetyMode>()
{
  return kr_msgs::msg::builder::Init_SafetyMode_val();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_MODE__BUILDER_HPP_
