// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include "kr_msgs/msg/detail/robot_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_str
{
public:
  explicit Init_RobotState_str(::kr_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::RobotState str(::kr_msgs::msg::RobotState::_str_type arg)
  {
    msg_.str = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::RobotState msg_;
};

class Init_RobotState_val
{
public:
  Init_RobotState_val()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_str val(::kr_msgs::msg::RobotState::_val_type arg)
  {
    msg_.val = std::move(arg);
    return Init_RobotState_str(msg_);
  }

private:
  ::kr_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::RobotState>()
{
  return kr_msgs::msg::builder::Init_RobotState_val();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
