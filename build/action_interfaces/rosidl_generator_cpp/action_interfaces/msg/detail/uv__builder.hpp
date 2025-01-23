// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/UV.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__UV__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__UV__BUILDER_HPP_

#include "action_interfaces/msg/detail/uv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_UV_data
{
public:
  Init_UV_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::msg::UV data(::action_interfaces::msg::UV::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::UV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::UV>()
{
  return action_interfaces::msg::builder::Init_UV_data();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__UV__BUILDER_HPP_
