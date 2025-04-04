// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include "action_interfaces/msg/detail/bounding_box__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_y_max
{
public:
  explicit Init_BoundingBox_y_max(::action_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::action_interfaces::msg::BoundingBox y_max(::action_interfaces::msg::BoundingBox::_y_max_type arg)
  {
    msg_.y_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_x_max
{
public:
  explicit Init_BoundingBox_x_max(::action_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_y_max x_max(::action_interfaces::msg::BoundingBox::_x_max_type arg)
  {
    msg_.x_max = std::move(arg);
    return Init_BoundingBox_y_max(msg_);
  }

private:
  ::action_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_y_min
{
public:
  explicit Init_BoundingBox_y_min(::action_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_x_max y_min(::action_interfaces::msg::BoundingBox::_y_min_type arg)
  {
    msg_.y_min = std::move(arg);
    return Init_BoundingBox_x_max(msg_);
  }

private:
  ::action_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_x_min
{
public:
  Init_BoundingBox_x_min()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_y_min x_min(::action_interfaces::msg::BoundingBox::_x_min_type arg)
  {
    msg_.x_min = std::move(arg);
    return Init_BoundingBox_y_min(msg_);
  }

private:
  ::action_interfaces::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::BoundingBox>()
{
  return action_interfaces::msg::builder::Init_BoundingBox_x_min();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
