// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/GetMasterSpeed.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_MASTER_SPEED__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__GET_MASTER_SPEED__BUILDER_HPP_

#include "kr_msgs/srv/detail/get_master_speed__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetMasterSpeed_Request>()
{
  return ::kr_msgs::srv::GetMasterSpeed_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetMasterSpeed_Response_success
{
public:
  explicit Init_GetMasterSpeed_Response_success(::kr_msgs::srv::GetMasterSpeed_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetMasterSpeed_Response success(::kr_msgs::srv::GetMasterSpeed_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetMasterSpeed_Response msg_;
};

class Init_GetMasterSpeed_Response_speed
{
public:
  Init_GetMasterSpeed_Response_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetMasterSpeed_Response_success speed(::kr_msgs::srv::GetMasterSpeed_Response::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_GetMasterSpeed_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::GetMasterSpeed_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetMasterSpeed_Response>()
{
  return kr_msgs::srv::builder::Init_GetMasterSpeed_Response_speed();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_MASTER_SPEED__BUILDER_HPP_
