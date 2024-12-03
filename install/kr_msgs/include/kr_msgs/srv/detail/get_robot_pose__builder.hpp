// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/GetRobotPose.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_ROBOT_POSE__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__GET_ROBOT_POSE__BUILDER_HPP_

#include "kr_msgs/srv/detail/get_robot_pose__struct.hpp"
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
auto build<::kr_msgs::srv::GetRobotPose_Request>()
{
  return ::kr_msgs::srv::GetRobotPose_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetRobotPose_Response_success
{
public:
  explicit Init_GetRobotPose_Response_success(::kr_msgs::srv::GetRobotPose_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetRobotPose_Response success(::kr_msgs::srv::GetRobotPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetRobotPose_Response msg_;
};

class Init_GetRobotPose_Response_jsconf
{
public:
  explicit Init_GetRobotPose_Response_jsconf(::kr_msgs::srv::GetRobotPose_Response & msg)
  : msg_(msg)
  {}
  Init_GetRobotPose_Response_success jsconf(::kr_msgs::srv::GetRobotPose_Response::_jsconf_type arg)
  {
    msg_.jsconf = std::move(arg);
    return Init_GetRobotPose_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::GetRobotPose_Response msg_;
};

class Init_GetRobotPose_Response_rot
{
public:
  explicit Init_GetRobotPose_Response_rot(::kr_msgs::srv::GetRobotPose_Response & msg)
  : msg_(msg)
  {}
  Init_GetRobotPose_Response_jsconf rot(::kr_msgs::srv::GetRobotPose_Response::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return Init_GetRobotPose_Response_jsconf(msg_);
  }

private:
  ::kr_msgs::srv::GetRobotPose_Response msg_;
};

class Init_GetRobotPose_Response_pos
{
public:
  Init_GetRobotPose_Response_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRobotPose_Response_rot pos(::kr_msgs::srv::GetRobotPose_Response::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_GetRobotPose_Response_rot(msg_);
  }

private:
  ::kr_msgs::srv::GetRobotPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetRobotPose_Response>()
{
  return kr_msgs::srv::builder::Init_GetRobotPose_Response_pos();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_ROBOT_POSE__BUILDER_HPP_
