// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/Number.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__NUMBER__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__NUMBER__BUILDER_HPP_

#include "kr_msgs/msg/detail/number__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_Number_value
{
public:
  Init_Number_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::msg::Number value(::kr_msgs::msg::Number::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::Number msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::Number>()
{
  return kr_msgs::msg::builder::Init_Number_value();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__NUMBER__BUILDER_HPP_
