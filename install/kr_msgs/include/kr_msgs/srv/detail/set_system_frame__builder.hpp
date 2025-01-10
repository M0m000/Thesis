// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/SetSystemFrame.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_SYSTEM_FRAME__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__SET_SYSTEM_FRAME__BUILDER_HPP_

#include "kr_msgs/srv/detail/set_system_frame__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSystemFrame_Request_ref
{
public:
  explicit Init_SetSystemFrame_Request_ref(::kr_msgs::srv::SetSystemFrame_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::SetSystemFrame_Request ref(::kr_msgs::srv::SetSystemFrame_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemFrame_Request msg_;
};

class Init_SetSystemFrame_Request_rot
{
public:
  explicit Init_SetSystemFrame_Request_rot(::kr_msgs::srv::SetSystemFrame_Request & msg)
  : msg_(msg)
  {}
  Init_SetSystemFrame_Request_ref rot(::kr_msgs::srv::SetSystemFrame_Request::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return Init_SetSystemFrame_Request_ref(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemFrame_Request msg_;
};

class Init_SetSystemFrame_Request_pos
{
public:
  explicit Init_SetSystemFrame_Request_pos(::kr_msgs::srv::SetSystemFrame_Request & msg)
  : msg_(msg)
  {}
  Init_SetSystemFrame_Request_rot pos(::kr_msgs::srv::SetSystemFrame_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_SetSystemFrame_Request_rot(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemFrame_Request msg_;
};

class Init_SetSystemFrame_Request_name
{
public:
  Init_SetSystemFrame_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetSystemFrame_Request_pos name(::kr_msgs::srv::SetSystemFrame_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_SetSystemFrame_Request_pos(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemFrame_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetSystemFrame_Request>()
{
  return kr_msgs::srv::builder::Init_SetSystemFrame_Request_name();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSystemFrame_Response_success
{
public:
  Init_SetSystemFrame_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::SetSystemFrame_Response success(::kr_msgs::srv::SetSystemFrame_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemFrame_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetSystemFrame_Response>()
{
  return kr_msgs::srv::builder::Init_SetSystemFrame_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__SET_SYSTEM_FRAME__BUILDER_HPP_
