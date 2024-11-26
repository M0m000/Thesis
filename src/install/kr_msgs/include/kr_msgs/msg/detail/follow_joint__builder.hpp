// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/FollowJoint.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__FOLLOW_JOINT__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__FOLLOW_JOINT__BUILDER_HPP_

#include "kr_msgs/msg/detail/follow_joint__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_FollowJoint_bvalue
{
public:
  explicit Init_FollowJoint_bvalue(::kr_msgs::msg::FollowJoint & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::FollowJoint bvalue(::kr_msgs::msg::FollowJoint::_bvalue_type arg)
  {
    msg_.bvalue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::FollowJoint msg_;
};

class Init_FollowJoint_btype
{
public:
  explicit Init_FollowJoint_btype(::kr_msgs::msg::FollowJoint & msg)
  : msg_(msg)
  {}
  Init_FollowJoint_bvalue btype(::kr_msgs::msg::FollowJoint::_btype_type arg)
  {
    msg_.btype = std::move(arg);
    return Init_FollowJoint_bvalue(msg_);
  }

private:
  ::kr_msgs::msg::FollowJoint msg_;
};

class Init_FollowJoint_bpoint
{
public:
  explicit Init_FollowJoint_bpoint(::kr_msgs::msg::FollowJoint & msg)
  : msg_(msg)
  {}
  Init_FollowJoint_btype bpoint(::kr_msgs::msg::FollowJoint::_bpoint_type arg)
  {
    msg_.bpoint = std::move(arg);
    return Init_FollowJoint_btype(msg_);
  }

private:
  ::kr_msgs::msg::FollowJoint msg_;
};

class Init_FollowJoint_tvalue
{
public:
  explicit Init_FollowJoint_tvalue(::kr_msgs::msg::FollowJoint & msg)
  : msg_(msg)
  {}
  Init_FollowJoint_bpoint tvalue(::kr_msgs::msg::FollowJoint::_tvalue_type arg)
  {
    msg_.tvalue = std::move(arg);
    return Init_FollowJoint_bpoint(msg_);
  }

private:
  ::kr_msgs::msg::FollowJoint msg_;
};

class Init_FollowJoint_ttype
{
public:
  explicit Init_FollowJoint_ttype(::kr_msgs::msg::FollowJoint & msg)
  : msg_(msg)
  {}
  Init_FollowJoint_tvalue ttype(::kr_msgs::msg::FollowJoint::_ttype_type arg)
  {
    msg_.ttype = std::move(arg);
    return Init_FollowJoint_tvalue(msg_);
  }

private:
  ::kr_msgs::msg::FollowJoint msg_;
};

class Init_FollowJoint_jsconf
{
public:
  Init_FollowJoint_jsconf()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowJoint_ttype jsconf(::kr_msgs::msg::FollowJoint::_jsconf_type arg)
  {
    msg_.jsconf = std::move(arg);
    return Init_FollowJoint_ttype(msg_);
  }

private:
  ::kr_msgs::msg::FollowJoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::FollowJoint>()
{
  return kr_msgs::msg::builder::Init_FollowJoint_jsconf();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__FOLLOW_JOINT__BUILDER_HPP_
