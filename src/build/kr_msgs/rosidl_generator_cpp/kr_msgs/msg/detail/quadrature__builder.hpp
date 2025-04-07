// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/Quadrature.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__QUADRATURE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__QUADRATURE__BUILDER_HPP_

#include "kr_msgs/msg/detail/quadrature__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_Quadrature_pulse_per_sec
{
public:
  explicit Init_Quadrature_pulse_per_sec(::kr_msgs::msg::Quadrature & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::Quadrature pulse_per_sec(::kr_msgs::msg::Quadrature::_pulse_per_sec_type arg)
  {
    msg_.pulse_per_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::Quadrature msg_;
};

class Init_Quadrature_abs_pulse_count
{
public:
  explicit Init_Quadrature_abs_pulse_count(::kr_msgs::msg::Quadrature & msg)
  : msg_(msg)
  {}
  Init_Quadrature_pulse_per_sec abs_pulse_count(::kr_msgs::msg::Quadrature::_abs_pulse_count_type arg)
  {
    msg_.abs_pulse_count = std::move(arg);
    return Init_Quadrature_pulse_per_sec(msg_);
  }

private:
  ::kr_msgs::msg::Quadrature msg_;
};

class Init_Quadrature_frequency
{
public:
  explicit Init_Quadrature_frequency(::kr_msgs::msg::Quadrature & msg)
  : msg_(msg)
  {}
  Init_Quadrature_abs_pulse_count frequency(::kr_msgs::msg::Quadrature::_frequency_type arg)
  {
    msg_.frequency = std::move(arg);
    return Init_Quadrature_abs_pulse_count(msg_);
  }

private:
  ::kr_msgs::msg::Quadrature msg_;
};

class Init_Quadrature_pulse_count
{
public:
  explicit Init_Quadrature_pulse_count(::kr_msgs::msg::Quadrature & msg)
  : msg_(msg)
  {}
  Init_Quadrature_frequency pulse_count(::kr_msgs::msg::Quadrature::_pulse_count_type arg)
  {
    msg_.pulse_count = std::move(arg);
    return Init_Quadrature_frequency(msg_);
  }

private:
  ::kr_msgs::msg::Quadrature msg_;
};

class Init_Quadrature_direction
{
public:
  Init_Quadrature_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Quadrature_pulse_count direction(::kr_msgs::msg::Quadrature::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Quadrature_pulse_count(msg_);
  }

private:
  ::kr_msgs::msg::Quadrature msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::Quadrature>()
{
  return kr_msgs::msg::builder::Init_Quadrature_direction();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__QUADRATURE__BUILDER_HPP_
