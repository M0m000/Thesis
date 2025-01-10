// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/GetSystemLoad.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_SYSTEM_LOAD__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__GET_SYSTEM_LOAD__BUILDER_HPP_

#include "kr_msgs/srv/detail/get_system_load__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSystemLoad_Request_name
{
public:
  Init_GetSystemLoad_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::GetSystemLoad_Request name(::kr_msgs::srv::GetSystemLoad_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemLoad_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetSystemLoad_Request>()
{
  return kr_msgs::srv::builder::Init_GetSystemLoad_Request_name();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSystemLoad_Response_success
{
public:
  explicit Init_GetSystemLoad_Response_success(::kr_msgs::srv::GetSystemLoad_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetSystemLoad_Response success(::kr_msgs::srv::GetSystemLoad_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemLoad_Response msg_;
};

class Init_GetSystemLoad_Response_imx
{
public:
  explicit Init_GetSystemLoad_Response_imx(::kr_msgs::srv::GetSystemLoad_Response & msg)
  : msg_(msg)
  {}
  Init_GetSystemLoad_Response_success imx(::kr_msgs::srv::GetSystemLoad_Response::_imx_type arg)
  {
    msg_.imx = std::move(arg);
    return Init_GetSystemLoad_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemLoad_Response msg_;
};

class Init_GetSystemLoad_Response_cog
{
public:
  explicit Init_GetSystemLoad_Response_cog(::kr_msgs::srv::GetSystemLoad_Response & msg)
  : msg_(msg)
  {}
  Init_GetSystemLoad_Response_imx cog(::kr_msgs::srv::GetSystemLoad_Response::_cog_type arg)
  {
    msg_.cog = std::move(arg);
    return Init_GetSystemLoad_Response_imx(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemLoad_Response msg_;
};

class Init_GetSystemLoad_Response_mass
{
public:
  Init_GetSystemLoad_Response_mass()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSystemLoad_Response_cog mass(::kr_msgs::srv::GetSystemLoad_Response::_mass_type arg)
  {
    msg_.mass = std::move(arg);
    return Init_GetSystemLoad_Response_cog(msg_);
  }

private:
  ::kr_msgs::srv::GetSystemLoad_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetSystemLoad_Response>()
{
  return kr_msgs::srv::builder::Init_GetSystemLoad_Response_mass();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_SYSTEM_LOAD__BUILDER_HPP_
