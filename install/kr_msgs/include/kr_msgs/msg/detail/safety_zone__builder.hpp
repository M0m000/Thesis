// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_ZONE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__SAFETY_ZONE__BUILDER_HPP_

#include "kr_msgs/msg/detail/safety_zone__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_SafetyZone_planes
{
public:
  explicit Init_SafetyZone_planes(::kr_msgs::msg::SafetyZone & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::SafetyZone planes(::kr_msgs::msg::SafetyZone::_planes_type arg)
  {
    msg_.planes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::SafetyZone msg_;
};

class Init_SafetyZone_safety_io
{
public:
  explicit Init_SafetyZone_safety_io(::kr_msgs::msg::SafetyZone & msg)
  : msg_(msg)
  {}
  Init_SafetyZone_planes safety_io(::kr_msgs::msg::SafetyZone::_safety_io_type arg)
  {
    msg_.safety_io = std::move(arg);
    return Init_SafetyZone_planes(msg_);
  }

private:
  ::kr_msgs::msg::SafetyZone msg_;
};

class Init_SafetyZone_sensitivity
{
public:
  explicit Init_SafetyZone_sensitivity(::kr_msgs::msg::SafetyZone & msg)
  : msg_(msg)
  {}
  Init_SafetyZone_safety_io sensitivity(::kr_msgs::msg::SafetyZone::_sensitivity_type arg)
  {
    msg_.sensitivity = std::move(arg);
    return Init_SafetyZone_safety_io(msg_);
  }

private:
  ::kr_msgs::msg::SafetyZone msg_;
};

class Init_SafetyZone_buffer
{
public:
  explicit Init_SafetyZone_buffer(::kr_msgs::msg::SafetyZone & msg)
  : msg_(msg)
  {}
  Init_SafetyZone_sensitivity buffer(::kr_msgs::msg::SafetyZone::_buffer_type arg)
  {
    msg_.buffer = std::move(arg);
    return Init_SafetyZone_sensitivity(msg_);
  }

private:
  ::kr_msgs::msg::SafetyZone msg_;
};

class Init_SafetyZone_speed
{
public:
  explicit Init_SafetyZone_speed(::kr_msgs::msg::SafetyZone & msg)
  : msg_(msg)
  {}
  Init_SafetyZone_buffer speed(::kr_msgs::msg::SafetyZone::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_SafetyZone_buffer(msg_);
  }

private:
  ::kr_msgs::msg::SafetyZone msg_;
};

class Init_SafetyZone_name
{
public:
  Init_SafetyZone_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetyZone_speed name(::kr_msgs::msg::SafetyZone::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_SafetyZone_speed(msg_);
  }

private:
  ::kr_msgs::msg::SafetyZone msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::SafetyZone>()
{
  return kr_msgs::msg::builder::Init_SafetyZone_name();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_ZONE__BUILDER_HPP_
