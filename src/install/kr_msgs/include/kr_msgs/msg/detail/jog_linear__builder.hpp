// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/JogLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__JOG_LINEAR__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__JOG_LINEAR__BUILDER_HPP_

#include "kr_msgs/msg/detail/jog_linear__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_JogLinear_rot
{
public:
  explicit Init_JogLinear_rot(::kr_msgs::msg::JogLinear & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::JogLinear rot(::kr_msgs::msg::JogLinear::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::JogLinear msg_;
};

class Init_JogLinear_vel
{
public:
  Init_JogLinear_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JogLinear_rot vel(::kr_msgs::msg::JogLinear::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_JogLinear_rot(msg_);
  }

private:
  ::kr_msgs::msg::JogLinear msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::JogLinear>()
{
  return kr_msgs::msg::builder::Init_JogLinear_vel();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__JOG_LINEAR__BUILDER_HPP_
