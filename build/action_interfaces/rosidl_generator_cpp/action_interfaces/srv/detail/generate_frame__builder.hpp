// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:srv/GenerateFrame.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__BUILDER_HPP_
#define ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__BUILDER_HPP_

#include "action_interfaces/srv/detail/generate_frame__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace action_interfaces
{

namespace srv
{

namespace builder
{

class Init_GenerateFrame_Request_rotation_rpy
{
public:
  explicit Init_GenerateFrame_Request_rotation_rpy(::action_interfaces::srv::GenerateFrame_Request & msg)
  : msg_(msg)
  {}
  ::action_interfaces::srv::GenerateFrame_Request rotation_rpy(::action_interfaces::srv::GenerateFrame_Request::_rotation_rpy_type arg)
  {
    msg_.rotation_rpy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::srv::GenerateFrame_Request msg_;
};

class Init_GenerateFrame_Request_translation
{
public:
  explicit Init_GenerateFrame_Request_translation(::action_interfaces::srv::GenerateFrame_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateFrame_Request_rotation_rpy translation(::action_interfaces::srv::GenerateFrame_Request::_translation_type arg)
  {
    msg_.translation = std::move(arg);
    return Init_GenerateFrame_Request_rotation_rpy(msg_);
  }

private:
  ::action_interfaces::srv::GenerateFrame_Request msg_;
};

class Init_GenerateFrame_Request_frame_ref
{
public:
  explicit Init_GenerateFrame_Request_frame_ref(::action_interfaces::srv::GenerateFrame_Request & msg)
  : msg_(msg)
  {}
  Init_GenerateFrame_Request_translation frame_ref(::action_interfaces::srv::GenerateFrame_Request::_frame_ref_type arg)
  {
    msg_.frame_ref = std::move(arg);
    return Init_GenerateFrame_Request_translation(msg_);
  }

private:
  ::action_interfaces::srv::GenerateFrame_Request msg_;
};

class Init_GenerateFrame_Request_frame_new
{
public:
  Init_GenerateFrame_Request_frame_new()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GenerateFrame_Request_frame_ref frame_new(::action_interfaces::srv::GenerateFrame_Request::_frame_new_type arg)
  {
    msg_.frame_new = std::move(arg);
    return Init_GenerateFrame_Request_frame_ref(msg_);
  }

private:
  ::action_interfaces::srv::GenerateFrame_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::srv::GenerateFrame_Request>()
{
  return action_interfaces::srv::builder::Init_GenerateFrame_Request_frame_new();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace srv
{

namespace builder
{

class Init_GenerateFrame_Response_message
{
public:
  explicit Init_GenerateFrame_Response_message(::action_interfaces::srv::GenerateFrame_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::srv::GenerateFrame_Response message(::action_interfaces::srv::GenerateFrame_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::srv::GenerateFrame_Response msg_;
};

class Init_GenerateFrame_Response_success
{
public:
  Init_GenerateFrame_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GenerateFrame_Response_message success(::action_interfaces::srv::GenerateFrame_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GenerateFrame_Response_message(msg_);
  }

private:
  ::action_interfaces::srv::GenerateFrame_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::srv::GenerateFrame_Response>()
{
  return action_interfaces::srv::builder::Init_GenerateFrame_Response_success();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__SRV__DETAIL__GENERATE_FRAME__BUILDER_HPP_
