// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/JogJoint.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__JOG_JOINT__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__JOG_JOINT__BUILDER_HPP_

#include "kr_msgs/msg/detail/jog_joint__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_JogJoint_jsvel
{
public:
  Init_JogJoint_jsvel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::msg::JogJoint jsvel(::kr_msgs::msg::JogJoint::_jsvel_type arg)
  {
    msg_.jsvel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::JogJoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::JogJoint>()
{
  return kr_msgs::msg::builder::Init_JogJoint_jsvel();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__JOG_JOINT__BUILDER_HPP_
