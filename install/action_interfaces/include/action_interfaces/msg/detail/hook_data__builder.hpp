// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__BUILDER_HPP_

#include "action_interfaces/msg/detail/hook_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_HookData_hooks
{
public:
  Init_HookData_hooks()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::msg::HookData hooks(::action_interfaces::msg::HookData::_hooks_type arg)
  {
    msg_.hooks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::HookData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::HookData>()
{
  return action_interfaces::msg::builder::Init_HookData_hooks();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__BUILDER_HPP_
