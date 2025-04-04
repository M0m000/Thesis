// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/RobotMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_MODE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__ROBOT_MODE__BUILDER_HPP_

#include "kr_msgs/msg/detail/robot_mode__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotMode_str
{
public:
  explicit Init_RobotMode_str(::kr_msgs::msg::RobotMode & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::RobotMode str(::kr_msgs::msg::RobotMode::_str_type arg)
  {
    msg_.str = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::RobotMode msg_;
};

class Init_RobotMode_val
{
public:
  Init_RobotMode_val()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMode_str val(::kr_msgs::msg::RobotMode::_val_type arg)
  {
    msg_.val = std::move(arg);
    return Init_RobotMode_str(msg_);
  }

private:
  ::kr_msgs::msg::RobotMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::RobotMode>()
{
  return kr_msgs::msg::builder::Init_RobotMode_val();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_MODE__BUILDER_HPP_
