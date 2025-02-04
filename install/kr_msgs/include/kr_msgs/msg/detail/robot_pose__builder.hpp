// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_

#include "kr_msgs/msg/detail/robot_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotPose_jsconf
{
public:
  explicit Init_RobotPose_jsconf(::kr_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::RobotPose jsconf(::kr_msgs::msg::RobotPose::_jsconf_type arg)
  {
    msg_.jsconf = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_rot
{
public:
  explicit Init_RobotPose_rot(::kr_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  Init_RobotPose_jsconf rot(::kr_msgs::msg::RobotPose::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return Init_RobotPose_jsconf(msg_);
  }

private:
  ::kr_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_pos
{
public:
  Init_RobotPose_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotPose_rot pos(::kr_msgs::msg::RobotPose::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_RobotPose_rot(msg_);
  }

private:
  ::kr_msgs::msg::RobotPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::RobotPose>()
{
  return kr_msgs::msg::builder::Init_RobotPose_pos();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
