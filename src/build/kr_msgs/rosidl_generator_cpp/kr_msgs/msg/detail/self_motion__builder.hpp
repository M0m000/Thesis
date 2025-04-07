// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/SelfMotion.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SELF_MOTION__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__SELF_MOTION__BUILDER_HPP_

#include "kr_msgs/msg/detail/self_motion__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_SelfMotion_speed
{
public:
  Init_SelfMotion_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::msg::SelfMotion speed(::kr_msgs::msg::SelfMotion::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::SelfMotion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::SelfMotion>()
{
  return kr_msgs::msg::builder::Init_SelfMotion_speed();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SELF_MOTION__BUILDER_HPP_
