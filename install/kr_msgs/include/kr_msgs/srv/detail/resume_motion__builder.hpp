// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/ResumeMotion.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__RESUME_MOTION__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__RESUME_MOTION__BUILDER_HPP_

#include "kr_msgs/srv/detail/resume_motion__struct.hpp"
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
auto build<::kr_msgs::srv::ResumeMotion_Request>()
{
  return ::kr_msgs::srv::ResumeMotion_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_ResumeMotion_Response_success
{
public:
  Init_ResumeMotion_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::ResumeMotion_Response success(::kr_msgs::srv::ResumeMotion_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::ResumeMotion_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::ResumeMotion_Response>()
{
  return kr_msgs::srv::builder::Init_ResumeMotion_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__RESUME_MOTION__BUILDER_HPP_
