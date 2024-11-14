// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/FollowLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__BUILDER_HPP_

#include "kr_msgs/msg/detail/follow_linear__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_FollowLinear_bvalue
{
public:
  explicit Init_FollowLinear_bvalue(::kr_msgs::msg::FollowLinear & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::FollowLinear bvalue(::kr_msgs::msg::FollowLinear::_bvalue_type arg)
  {
    msg_.bvalue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

class Init_FollowLinear_btype
{
public:
  explicit Init_FollowLinear_btype(::kr_msgs::msg::FollowLinear & msg)
  : msg_(msg)
  {}
  Init_FollowLinear_bvalue btype(::kr_msgs::msg::FollowLinear::_btype_type arg)
  {
    msg_.btype = std::move(arg);
    return Init_FollowLinear_bvalue(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

class Init_FollowLinear_bpoint
{
public:
  explicit Init_FollowLinear_bpoint(::kr_msgs::msg::FollowLinear & msg)
  : msg_(msg)
  {}
  Init_FollowLinear_btype bpoint(::kr_msgs::msg::FollowLinear::_bpoint_type arg)
  {
    msg_.bpoint = std::move(arg);
    return Init_FollowLinear_btype(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

class Init_FollowLinear_tvalue
{
public:
  explicit Init_FollowLinear_tvalue(::kr_msgs::msg::FollowLinear & msg)
  : msg_(msg)
  {}
  Init_FollowLinear_bpoint tvalue(::kr_msgs::msg::FollowLinear::_tvalue_type arg)
  {
    msg_.tvalue = std::move(arg);
    return Init_FollowLinear_bpoint(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

class Init_FollowLinear_ttype
{
public:
  explicit Init_FollowLinear_ttype(::kr_msgs::msg::FollowLinear & msg)
  : msg_(msg)
  {}
  Init_FollowLinear_tvalue ttype(::kr_msgs::msg::FollowLinear::_ttype_type arg)
  {
    msg_.ttype = std::move(arg);
    return Init_FollowLinear_tvalue(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

class Init_FollowLinear_ref
{
public:
  explicit Init_FollowLinear_ref(::kr_msgs::msg::FollowLinear & msg)
  : msg_(msg)
  {}
  Init_FollowLinear_ttype ref(::kr_msgs::msg::FollowLinear::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_FollowLinear_ttype(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

class Init_FollowLinear_rot
{
public:
  explicit Init_FollowLinear_rot(::kr_msgs::msg::FollowLinear & msg)
  : msg_(msg)
  {}
  Init_FollowLinear_ref rot(::kr_msgs::msg::FollowLinear::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return Init_FollowLinear_ref(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

class Init_FollowLinear_pos
{
public:
  Init_FollowLinear_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowLinear_rot pos(::kr_msgs::msg::FollowLinear::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_FollowLinear_rot(msg_);
  }

private:
  ::kr_msgs::msg::FollowLinear msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::FollowLinear>()
{
  return kr_msgs::msg::builder::Init_FollowLinear_pos();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__BUILDER_HPP_
