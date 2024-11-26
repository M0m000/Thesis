// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/GetSystemFrame.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_SYSTEM_FRAME__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__GET_SYSTEM_FRAME__BUILDER_HPP_

#include "kr_msgs/srv/detail/get_system_frame__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSystemFrame_Request_ref
{
public:
  explicit Init_GetSystemFrame_Request_ref(::kr_msgs::srv::GetSystemFrame_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetSystemFrame_Request ref(::kr_msgs::srv::GetSystemFrame_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemFrame_Request msg_;
};

class Init_GetSystemFrame_Request_name
{
public:
  Init_GetSystemFrame_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSystemFrame_Request_ref name(::kr_msgs::srv::GetSystemFrame_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_GetSystemFrame_Request_ref(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemFrame_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetSystemFrame_Request>()
{
  return kr_msgs::srv::builder::Init_GetSystemFrame_Request_name();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSystemFrame_Response_success
{
public:
  explicit Init_GetSystemFrame_Response_success(::kr_msgs::srv::GetSystemFrame_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetSystemFrame_Response success(::kr_msgs::srv::GetSystemFrame_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemFrame_Response msg_;
};

class Init_GetSystemFrame_Response_rot
{
public:
  explicit Init_GetSystemFrame_Response_rot(::kr_msgs::srv::GetSystemFrame_Response & msg)
  : msg_(msg)
  {}
  Init_GetSystemFrame_Response_success rot(::kr_msgs::srv::GetSystemFrame_Response::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return Init_GetSystemFrame_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemFrame_Response msg_;
};

class Init_GetSystemFrame_Response_pos
{
public:
  Init_GetSystemFrame_Response_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSystemFrame_Response_rot pos(::kr_msgs::srv::GetSystemFrame_Response::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_GetSystemFrame_Response_rot(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemFrame_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetSystemFrame_Response>()
{
  return kr_msgs::srv::builder::Init_GetSystemFrame_Response_pos();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_SYSTEM_FRAME__BUILDER_HPP_
