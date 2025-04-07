// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/XYZ.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__XYZ__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__XYZ__BUILDER_HPP_

#include "action_interfaces/msg/detail/xyz__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_XYZ_z
{
public:
  explicit Init_XYZ_z(::action_interfaces::msg::XYZ & msg)
  : msg_(msg)
  {}
  ::action_interfaces::msg::XYZ z(::action_interfaces::msg::XYZ::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::XYZ msg_;
};

class Init_XYZ_y
{
public:
  explicit Init_XYZ_y(::action_interfaces::msg::XYZ & msg)
  : msg_(msg)
  {}
  Init_XYZ_z y(::action_interfaces::msg::XYZ::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_XYZ_z(msg_);
  }

private:
  ::action_interfaces::msg::XYZ msg_;
};

class Init_XYZ_x
{
public:
  Init_XYZ_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_XYZ_y x(::action_interfaces::msg::XYZ::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_XYZ_y(msg_);
  }

private:
  ::action_interfaces::msg::XYZ msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::XYZ>()
{
  return action_interfaces::msg::builder::Init_XYZ_x();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__XYZ__BUILDER_HPP_
