// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK__BUILDER_HPP_

#include "action_interfaces/msg/detail/hook__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_Hook_uv_lowpoint
{
public:
  explicit Init_Hook_uv_lowpoint(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  ::action_interfaces::msg::Hook uv_lowpoint(::action_interfaces::msg::Hook::_uv_lowpoint_type arg)
  {
    msg_.uv_lowpoint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_uv_tip
{
public:
  explicit Init_Hook_uv_tip(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_uv_lowpoint uv_tip(::action_interfaces::msg::Hook::_uv_tip_type arg)
  {
    msg_.uv_tip = std::move(arg);
    return Init_Hook_uv_lowpoint(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_uv_hook
{
public:
  explicit Init_Hook_uv_hook(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_uv_tip uv_hook(::action_interfaces::msg::Hook::_uv_hook_type arg)
  {
    msg_.uv_hook = std::move(arg);
    return Init_Hook_uv_tip(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_conf_lowpoint
{
public:
  explicit Init_Hook_conf_lowpoint(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_uv_hook conf_lowpoint(::action_interfaces::msg::Hook::_conf_lowpoint_type arg)
  {
    msg_.conf_lowpoint = std::move(arg);
    return Init_Hook_uv_hook(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_conf_tip
{
public:
  explicit Init_Hook_conf_tip(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_conf_lowpoint conf_tip(::action_interfaces::msg::Hook::_conf_tip_type arg)
  {
    msg_.conf_tip = std::move(arg);
    return Init_Hook_conf_lowpoint(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_conf_hook
{
public:
  explicit Init_Hook_conf_hook(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_conf_tip conf_hook(::action_interfaces::msg::Hook::_conf_hook_type arg)
  {
    msg_.conf_hook = std::move(arg);
    return Init_Hook_conf_tip(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_lowpoint_mask
{
public:
  explicit Init_Hook_lowpoint_mask(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_conf_hook lowpoint_mask(::action_interfaces::msg::Hook::_lowpoint_mask_type arg)
  {
    msg_.lowpoint_mask = std::move(arg);
    return Init_Hook_conf_hook(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_tip_mask
{
public:
  explicit Init_Hook_tip_mask(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_lowpoint_mask tip_mask(::action_interfaces::msg::Hook::_tip_mask_type arg)
  {
    msg_.tip_mask = std::move(arg);
    return Init_Hook_lowpoint_mask(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_hook_mask
{
public:
  explicit Init_Hook_hook_mask(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_tip_mask hook_mask(::action_interfaces::msg::Hook::_hook_mask_type arg)
  {
    msg_.hook_mask = std::move(arg);
    return Init_Hook_tip_mask(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_lowpoint_box
{
public:
  explicit Init_Hook_lowpoint_box(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_hook_mask lowpoint_box(::action_interfaces::msg::Hook::_lowpoint_box_type arg)
  {
    msg_.lowpoint_box = std::move(arg);
    return Init_Hook_hook_mask(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_tip_box
{
public:
  explicit Init_Hook_tip_box(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_lowpoint_box tip_box(::action_interfaces::msg::Hook::_tip_box_type arg)
  {
    msg_.tip_box = std::move(arg);
    return Init_Hook_lowpoint_box(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_hook_box
{
public:
  explicit Init_Hook_hook_box(::action_interfaces::msg::Hook & msg)
  : msg_(msg)
  {}
  Init_Hook_tip_box hook_box(::action_interfaces::msg::Hook::_hook_box_type arg)
  {
    msg_.hook_box = std::move(arg);
    return Init_Hook_tip_box(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

class Init_Hook_name
{
public:
  Init_Hook_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hook_hook_box name(::action_interfaces::msg::Hook::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Hook_hook_box(msg_);
  }

private:
  ::action_interfaces::msg::Hook msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::Hook>()
{
  return action_interfaces::msg::builder::Init_Hook_name();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK__BUILDER_HPP_
