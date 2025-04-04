// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/ProgramRecovery.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__PROGRAM_RECOVERY__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__PROGRAM_RECOVERY__BUILDER_HPP_

#include "kr_msgs/srv/detail/program_recovery__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_ProgramRecovery_Request_action
{
public:
  Init_ProgramRecovery_Request_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::ProgramRecovery_Request action(::kr_msgs::srv::ProgramRecovery_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::ProgramRecovery_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::ProgramRecovery_Request>()
{
  return kr_msgs::srv::builder::Init_ProgramRecovery_Request_action();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_ProgramRecovery_Response_success
{
public:
  Init_ProgramRecovery_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::ProgramRecovery_Response success(::kr_msgs::srv::ProgramRecovery_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::ProgramRecovery_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::ProgramRecovery_Response>()
{
  return kr_msgs::srv::builder::Init_ProgramRecovery_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__PROGRAM_RECOVERY__BUILDER_HPP_
