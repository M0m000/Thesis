// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/SetSystemLoad.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_SYSTEM_LOAD__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__SET_SYSTEM_LOAD__BUILDER_HPP_

#include "kr_msgs/srv/detail/set_system_load__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSystemLoad_Request_imx
{
public:
  explicit Init_SetSystemLoad_Request_imx(::kr_msgs::srv::SetSystemLoad_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::SetSystemLoad_Request imx(::kr_msgs::srv::SetSystemLoad_Request::_imx_type arg)
  {
    msg_.imx = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemLoad_Request msg_;
};

class Init_SetSystemLoad_Request_cog
{
public:
  explicit Init_SetSystemLoad_Request_cog(::kr_msgs::srv::SetSystemLoad_Request & msg)
  : msg_(msg)
  {}
  Init_SetSystemLoad_Request_imx cog(::kr_msgs::srv::SetSystemLoad_Request::_cog_type arg)
  {
    msg_.cog = std::move(arg);
    return Init_SetSystemLoad_Request_imx(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemLoad_Request msg_;
};

class Init_SetSystemLoad_Request_mass
{
public:
  explicit Init_SetSystemLoad_Request_mass(::kr_msgs::srv::SetSystemLoad_Request & msg)
  : msg_(msg)
  {}
  Init_SetSystemLoad_Request_cog mass(::kr_msgs::srv::SetSystemLoad_Request::_mass_type arg)
  {
    msg_.mass = std::move(arg);
    return Init_SetSystemLoad_Request_cog(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemLoad_Request msg_;
};

class Init_SetSystemLoad_Request_name
{
public:
  Init_SetSystemLoad_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetSystemLoad_Request_mass name(::kr_msgs::srv::SetSystemLoad_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_SetSystemLoad_Request_mass(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemLoad_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetSystemLoad_Request>()
{
  return kr_msgs::srv::builder::Init_SetSystemLoad_Request_name();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSystemLoad_Response_success
{
public:
  Init_SetSystemLoad_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::SetSystemLoad_Response success(::kr_msgs::srv::SetSystemLoad_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::SetSystemLoad_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::SetSystemLoad_Response>()
{
  return kr_msgs::srv::builder::Init_SetSystemLoad_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__SET_SYSTEM_LOAD__BUILDER_HPP_
