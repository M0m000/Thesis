// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/MoveJoint.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__MOVE_JOINT__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__MOVE_JOINT__BUILDER_HPP_

#include "kr_msgs/srv/detail/move_joint__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveJoint_Request_chaining
{
public:
  explicit Init_MoveJoint_Request_chaining(::kr_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::MoveJoint_Request chaining(::kr_msgs::srv::MoveJoint_Request::_chaining_type arg)
  {
    msg_.chaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_sync
{
public:
  explicit Init_MoveJoint_Request_sync(::kr_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_chaining sync(::kr_msgs::srv::MoveJoint_Request::_sync_type arg)
  {
    msg_.sync = std::move(arg);
    return Init_MoveJoint_Request_chaining(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_bvalue
{
public:
  explicit Init_MoveJoint_Request_bvalue(::kr_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_sync bvalue(::kr_msgs::srv::MoveJoint_Request::_bvalue_type arg)
  {
    msg_.bvalue = std::move(arg);
    return Init_MoveJoint_Request_sync(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_btype
{
public:
  explicit Init_MoveJoint_Request_btype(::kr_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_bvalue btype(::kr_msgs::srv::MoveJoint_Request::_btype_type arg)
  {
    msg_.btype = std::move(arg);
    return Init_MoveJoint_Request_bvalue(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_bpoint
{
public:
  explicit Init_MoveJoint_Request_bpoint(::kr_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_btype bpoint(::kr_msgs::srv::MoveJoint_Request::_bpoint_type arg)
  {
    msg_.bpoint = std::move(arg);
    return Init_MoveJoint_Request_btype(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_tvalue
{
public:
  explicit Init_MoveJoint_Request_tvalue(::kr_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_bpoint tvalue(::kr_msgs::srv::MoveJoint_Request::_tvalue_type arg)
  {
    msg_.tvalue = std::move(arg);
    return Init_MoveJoint_Request_bpoint(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_ttype
{
public:
  explicit Init_MoveJoint_Request_ttype(::kr_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_tvalue ttype(::kr_msgs::srv::MoveJoint_Request::_ttype_type arg)
  {
    msg_.ttype = std::move(arg);
    return Init_MoveJoint_Request_tvalue(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_jsconf
{
public:
  Init_MoveJoint_Request_jsconf()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoint_Request_ttype jsconf(::kr_msgs::srv::MoveJoint_Request::_jsconf_type arg)
  {
    msg_.jsconf = std::move(arg);
    return Init_MoveJoint_Request_ttype(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::MoveJoint_Request>()
{
  return kr_msgs::srv::builder::Init_MoveJoint_Request_jsconf();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveJoint_Response_success
{
public:
  Init_MoveJoint_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::MoveJoint_Response success(::kr_msgs::srv::MoveJoint_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::MoveJoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::MoveJoint_Response>()
{
  return kr_msgs::srv::builder::Init_MoveJoint_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__MOVE_JOINT__BUILDER_HPP_
