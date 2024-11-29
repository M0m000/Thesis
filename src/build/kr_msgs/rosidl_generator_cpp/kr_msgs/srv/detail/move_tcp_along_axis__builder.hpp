// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_

#include "kr_msgs/srv/detail/move_tcp_along_axis__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveTCPAlongAxis_Request_axis
{
public:
  explicit Init_MoveTCPAlongAxis_Request_axis(::kr_msgs::srv::MoveTCPAlongAxis_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::MoveTCPAlongAxis_Request axis(::kr_msgs::srv::MoveTCPAlongAxis_Request::_axis_type arg)
  {
    msg_.axis = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::MoveTCPAlongAxis_Request msg_;
};

class Init_MoveTCPAlongAxis_Request_frame
{
public:
  explicit Init_MoveTCPAlongAxis_Request_frame(::kr_msgs::srv::MoveTCPAlongAxis_Request & msg)
  : msg_(msg)
  {}
  Init_MoveTCPAlongAxis_Request_axis frame(::kr_msgs::srv::MoveTCPAlongAxis_Request::_frame_type arg)
  {
    msg_.frame = std::move(arg);
    return Init_MoveTCPAlongAxis_Request_axis(msg_);
  }

private:
  ::kr_msgs::srv::MoveTCPAlongAxis_Request msg_;
};

class Init_MoveTCPAlongAxis_Request_baseline
{
public:
  Init_MoveTCPAlongAxis_Request_baseline()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTCPAlongAxis_Request_frame baseline(::kr_msgs::srv::MoveTCPAlongAxis_Request::_baseline_type arg)
  {
    msg_.baseline = std::move(arg);
    return Init_MoveTCPAlongAxis_Request_frame(msg_);
  }

private:
  ::kr_msgs::srv::MoveTCPAlongAxis_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::MoveTCPAlongAxis_Request>()
{
  return kr_msgs::srv::builder::Init_MoveTCPAlongAxis_Request_baseline();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveTCPAlongAxis_Response_success
{
public:
  Init_MoveTCPAlongAxis_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::MoveTCPAlongAxis_Response success(::kr_msgs::srv::MoveTCPAlongAxis_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::MoveTCPAlongAxis_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::MoveTCPAlongAxis_Response>()
{
  return kr_msgs::srv::builder::Init_MoveTCPAlongAxis_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_
