// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_

#include "kr_msgs/msg/detail/system_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_SystemState_backdrive
{
public:
  explicit Init_SystemState_backdrive(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::SystemState backdrive(::kr_msgs::msg::SystemState::_backdrive_type arg)
  {
    msg_.backdrive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_toggle
{
public:
  explicit Init_SystemState_toggle(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_backdrive toggle(::kr_msgs::msg::SystemState::_toggle_type arg)
  {
    msg_.toggle = std::move(arg);
    return Init_SystemState_backdrive(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_p_stop
{
public:
  explicit Init_SystemState_p_stop(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_toggle p_stop(::kr_msgs::msg::SystemState::_p_stop_type arg)
  {
    msg_.p_stop = std::move(arg);
    return Init_SystemState_toggle(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_e_stop
{
public:
  explicit Init_SystemState_e_stop(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_p_stop e_stop(::kr_msgs::msg::SystemState::_e_stop_type arg)
  {
    msg_.e_stop = std::move(arg);
    return Init_SystemState_p_stop(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_tio_voltage_in
{
public:
  explicit Init_SystemState_tio_voltage_in(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_e_stop tio_voltage_in(::kr_msgs::msg::SystemState::_tio_voltage_in_type arg)
  {
    msg_.tio_voltage_in = std::move(arg);
    return Init_SystemState_e_stop(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_tio_current_in
{
public:
  explicit Init_SystemState_tio_current_in(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tio_voltage_in tio_current_in(::kr_msgs::msg::SystemState::_tio_current_in_type arg)
  {
    msg_.tio_current_in = std::move(arg);
    return Init_SystemState_tio_voltage_in(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_tio_analog_out
{
public:
  explicit Init_SystemState_tio_analog_out(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tio_current_in tio_analog_out(::kr_msgs::msg::SystemState::_tio_analog_out_type arg)
  {
    msg_.tio_analog_out = std::move(arg);
    return Init_SystemState_tio_current_in(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_tio_power_supply
{
public:
  explicit Init_SystemState_tio_power_supply(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tio_analog_out tio_power_supply(::kr_msgs::msg::SystemState::_tio_power_supply_type arg)
  {
    msg_.tio_power_supply = std::move(arg);
    return Init_SystemState_tio_analog_out(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_tio_digital_out
{
public:
  explicit Init_SystemState_tio_digital_out(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tio_power_supply tio_digital_out(::kr_msgs::msg::SystemState::_tio_digital_out_type arg)
  {
    msg_.tio_digital_out = std::move(arg);
    return Init_SystemState_tio_power_supply(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_quadratures
{
public:
  explicit Init_SystemState_iob_quadratures(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tio_digital_out iob_quadratures(::kr_msgs::msg::SystemState::_iob_quadratures_type arg)
  {
    msg_.iob_quadratures = std::move(arg);
    return Init_SystemState_tio_digital_out(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_voltage_in
{
public:
  explicit Init_SystemState_iob_voltage_in(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_quadratures iob_voltage_in(::kr_msgs::msg::SystemState::_iob_voltage_in_type arg)
  {
    msg_.iob_voltage_in = std::move(arg);
    return Init_SystemState_iob_quadratures(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_current_in
{
public:
  explicit Init_SystemState_iob_current_in(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_voltage_in iob_current_in(::kr_msgs::msg::SystemState::_iob_current_in_type arg)
  {
    msg_.iob_current_in = std::move(arg);
    return Init_SystemState_iob_voltage_in(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_safe_in
{
public:
  explicit Init_SystemState_iob_safe_in(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_current_in iob_safe_in(::kr_msgs::msg::SystemState::_iob_safe_in_type arg)
  {
    msg_.iob_safe_in = std::move(arg);
    return Init_SystemState_iob_current_in(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_digital_in
{
public:
  explicit Init_SystemState_iob_digital_in(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_safe_in iob_digital_in(::kr_msgs::msg::SystemState::_iob_digital_in_type arg)
  {
    msg_.iob_digital_in = std::move(arg);
    return Init_SystemState_iob_safe_in(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_voltage_out
{
public:
  explicit Init_SystemState_iob_voltage_out(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_digital_in iob_voltage_out(::kr_msgs::msg::SystemState::_iob_voltage_out_type arg)
  {
    msg_.iob_voltage_out = std::move(arg);
    return Init_SystemState_iob_digital_in(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_current_out
{
public:
  explicit Init_SystemState_iob_current_out(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_voltage_out iob_current_out(::kr_msgs::msg::SystemState::_iob_current_out_type arg)
  {
    msg_.iob_current_out = std::move(arg);
    return Init_SystemState_iob_voltage_out(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_relays
{
public:
  explicit Init_SystemState_iob_relays(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_current_out iob_relays(::kr_msgs::msg::SystemState::_iob_relays_type arg)
  {
    msg_.iob_relays = std::move(arg);
    return Init_SystemState_iob_current_out(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_iob_digital_out
{
public:
  explicit Init_SystemState_iob_digital_out(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_relays iob_digital_out(::kr_msgs::msg::SystemState::_iob_digital_out_type arg)
  {
    msg_.iob_digital_out = std::move(arg);
    return Init_SystemState_iob_relays(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_rot
{
public:
  explicit Init_SystemState_rot(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_iob_digital_out rot(::kr_msgs::msg::SystemState::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return Init_SystemState_iob_digital_out(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_pos
{
public:
  explicit Init_SystemState_pos(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_rot pos(::kr_msgs::msg::SystemState::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_SystemState_rot(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_target_trq
{
public:
  explicit Init_SystemState_target_trq(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_pos target_trq(::kr_msgs::msg::SystemState::_target_trq_type arg)
  {
    msg_.target_trq = std::move(arg);
    return Init_SystemState_pos(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_target_vel
{
public:
  explicit Init_SystemState_target_vel(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_target_trq target_vel(::kr_msgs::msg::SystemState::_target_vel_type arg)
  {
    msg_.target_vel = std::move(arg);
    return Init_SystemState_target_trq(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_target_pos
{
public:
  explicit Init_SystemState_target_pos(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_target_vel target_pos(::kr_msgs::msg::SystemState::_target_pos_type arg)
  {
    msg_.target_pos = std::move(arg);
    return Init_SystemState_target_vel(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_sensed_trq
{
public:
  explicit Init_SystemState_sensed_trq(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_target_pos sensed_trq(::kr_msgs::msg::SystemState::_sensed_trq_type arg)
  {
    msg_.sensed_trq = std::move(arg);
    return Init_SystemState_target_pos(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_sensed_vel
{
public:
  explicit Init_SystemState_sensed_vel(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_sensed_trq sensed_vel(::kr_msgs::msg::SystemState::_sensed_vel_type arg)
  {
    msg_.sensed_vel = std::move(arg);
    return Init_SystemState_sensed_trq(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_sensed_pos
{
public:
  explicit Init_SystemState_sensed_pos(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_sensed_vel sensed_pos(::kr_msgs::msg::SystemState::_sensed_pos_type arg)
  {
    msg_.sensed_pos = std::move(arg);
    return Init_SystemState_sensed_vel(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_robot_state
{
public:
  explicit Init_SystemState_robot_state(::kr_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_sensed_pos robot_state(::kr_msgs::msg::SystemState::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return Init_SystemState_sensed_pos(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

class Init_SystemState_robot_mode
{
public:
  Init_SystemState_robot_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SystemState_robot_state robot_mode(::kr_msgs::msg::SystemState::_robot_mode_type arg)
  {
    msg_.robot_mode = std::move(arg);
    return Init_SystemState_robot_state(msg_);
  }

private:
  ::kr_msgs::msg::SystemState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::SystemState>()
{
  return kr_msgs::msg::builder::Init_SystemState_robot_mode();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_
