// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'robot_mode'
#include "kr_msgs/msg/detail/robot_mode__struct.hpp"
// Member 'robot_state'
#include "kr_msgs/msg/detail/robot_state__struct.hpp"
// Member 'iob_quadratures'
#include "kr_msgs/msg/detail/quadrature__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__SystemState __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__SystemState __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SystemState_
{
  using Type = SystemState_<ContainerAllocator>;

  explicit SystemState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_mode(_init),
    robot_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensed_pos.begin(), this->sensed_pos.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensed_vel.begin(), this->sensed_vel.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensed_trq.begin(), this->sensed_trq.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_pos.begin(), this->target_pos.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_vel.begin(), this->target_vel.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_trq.begin(), this->target_trq.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
      std::fill<typename std::array<int8_t, 8>::iterator, int8_t>(this->iob_digital_out.begin(), this->iob_digital_out.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->iob_relays.begin(), this->iob_relays.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_current_out.begin(), this->iob_current_out.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_voltage_out.begin(), this->iob_voltage_out.end(), 0.0f);
      std::fill<typename std::array<int8_t, 16>::iterator, int8_t>(this->iob_digital_in.begin(), this->iob_digital_in.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->iob_safe_in.begin(), this->iob_safe_in.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_current_in.begin(), this->iob_current_in.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_voltage_in.begin(), this->iob_voltage_in.end(), 0.0f);
      this->iob_quadratures.fill(kr_msgs::msg::Quadrature_<ContainerAllocator>{_init});
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->tio_digital_out.begin(), this->tio_digital_out.end(), 0);
      std::fill<typename std::array<int8_t, 3>::iterator, int8_t>(this->tio_power_supply.begin(), this->tio_power_supply.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->tio_analog_out.begin(), this->tio_analog_out.end(), 0.0f);
      std::fill<typename std::array<float, 1>::iterator, float>(this->tio_current_in.begin(), this->tio_current_in.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->tio_voltage_in.begin(), this->tio_voltage_in.end(), 0.0f);
      this->e_stop = false;
      this->p_stop = false;
      this->toggle = false;
      this->backdrive = false;
    }
  }

  explicit SystemState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_mode(_alloc, _init),
    robot_state(_alloc, _init),
    sensed_pos(_alloc),
    sensed_vel(_alloc),
    sensed_trq(_alloc),
    target_pos(_alloc),
    target_vel(_alloc),
    target_trq(_alloc),
    pos(_alloc),
    rot(_alloc),
    iob_digital_out(_alloc),
    iob_relays(_alloc),
    iob_current_out(_alloc),
    iob_voltage_out(_alloc),
    iob_digital_in(_alloc),
    iob_safe_in(_alloc),
    iob_current_in(_alloc),
    iob_voltage_in(_alloc),
    iob_quadratures(_alloc),
    tio_digital_out(_alloc),
    tio_power_supply(_alloc),
    tio_analog_out(_alloc),
    tio_current_in(_alloc),
    tio_voltage_in(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensed_pos.begin(), this->sensed_pos.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensed_vel.begin(), this->sensed_vel.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensed_trq.begin(), this->sensed_trq.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_pos.begin(), this->target_pos.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_vel.begin(), this->target_vel.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_trq.begin(), this->target_trq.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
      std::fill<typename std::array<int8_t, 8>::iterator, int8_t>(this->iob_digital_out.begin(), this->iob_digital_out.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->iob_relays.begin(), this->iob_relays.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_current_out.begin(), this->iob_current_out.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_voltage_out.begin(), this->iob_voltage_out.end(), 0.0f);
      std::fill<typename std::array<int8_t, 16>::iterator, int8_t>(this->iob_digital_in.begin(), this->iob_digital_in.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->iob_safe_in.begin(), this->iob_safe_in.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_current_in.begin(), this->iob_current_in.end(), 0.0f);
      std::fill<typename std::array<float, 2>::iterator, float>(this->iob_voltage_in.begin(), this->iob_voltage_in.end(), 0.0f);
      this->iob_quadratures.fill(kr_msgs::msg::Quadrature_<ContainerAllocator>{_alloc, _init});
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->tio_digital_out.begin(), this->tio_digital_out.end(), 0);
      std::fill<typename std::array<int8_t, 3>::iterator, int8_t>(this->tio_power_supply.begin(), this->tio_power_supply.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->tio_analog_out.begin(), this->tio_analog_out.end(), 0.0f);
      std::fill<typename std::array<float, 1>::iterator, float>(this->tio_current_in.begin(), this->tio_current_in.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->tio_voltage_in.begin(), this->tio_voltage_in.end(), 0.0f);
      this->e_stop = false;
      this->p_stop = false;
      this->toggle = false;
      this->backdrive = false;
    }
  }

  // field types and members
  using _robot_mode_type =
    kr_msgs::msg::RobotMode_<ContainerAllocator>;
  _robot_mode_type robot_mode;
  using _robot_state_type =
    kr_msgs::msg::RobotState_<ContainerAllocator>;
  _robot_state_type robot_state;
  using _sensed_pos_type =
    std::array<double, 7>;
  _sensed_pos_type sensed_pos;
  using _sensed_vel_type =
    std::array<double, 7>;
  _sensed_vel_type sensed_vel;
  using _sensed_trq_type =
    std::array<double, 7>;
  _sensed_trq_type sensed_trq;
  using _target_pos_type =
    std::array<double, 7>;
  _target_pos_type target_pos;
  using _target_vel_type =
    std::array<double, 7>;
  _target_vel_type target_vel;
  using _target_trq_type =
    std::array<double, 7>;
  _target_trq_type target_trq;
  using _pos_type =
    std::array<double, 3>;
  _pos_type pos;
  using _rot_type =
    std::array<double, 3>;
  _rot_type rot;
  using _iob_digital_out_type =
    std::array<int8_t, 8>;
  _iob_digital_out_type iob_digital_out;
  using _iob_relays_type =
    std::array<int8_t, 4>;
  _iob_relays_type iob_relays;
  using _iob_current_out_type =
    std::array<float, 2>;
  _iob_current_out_type iob_current_out;
  using _iob_voltage_out_type =
    std::array<float, 2>;
  _iob_voltage_out_type iob_voltage_out;
  using _iob_digital_in_type =
    std::array<int8_t, 16>;
  _iob_digital_in_type iob_digital_in;
  using _iob_safe_in_type =
    std::array<int8_t, 4>;
  _iob_safe_in_type iob_safe_in;
  using _iob_current_in_type =
    std::array<float, 2>;
  _iob_current_in_type iob_current_in;
  using _iob_voltage_in_type =
    std::array<float, 2>;
  _iob_voltage_in_type iob_voltage_in;
  using _iob_quadratures_type =
    std::array<kr_msgs::msg::Quadrature_<ContainerAllocator>, 2>;
  _iob_quadratures_type iob_quadratures;
  using _tio_digital_out_type =
    std::array<int8_t, 4>;
  _tio_digital_out_type tio_digital_out;
  using _tio_power_supply_type =
    std::array<int8_t, 3>;
  _tio_power_supply_type tio_power_supply;
  using _tio_analog_out_type =
    std::array<float, 2>;
  _tio_analog_out_type tio_analog_out;
  using _tio_current_in_type =
    std::array<float, 1>;
  _tio_current_in_type tio_current_in;
  using _tio_voltage_in_type =
    std::array<float, 4>;
  _tio_voltage_in_type tio_voltage_in;
  using _e_stop_type =
    bool;
  _e_stop_type e_stop;
  using _p_stop_type =
    bool;
  _p_stop_type p_stop;
  using _toggle_type =
    bool;
  _toggle_type toggle;
  using _backdrive_type =
    bool;
  _backdrive_type backdrive;

  // setters for named parameter idiom
  Type & set__robot_mode(
    const kr_msgs::msg::RobotMode_<ContainerAllocator> & _arg)
  {
    this->robot_mode = _arg;
    return *this;
  }
  Type & set__robot_state(
    const kr_msgs::msg::RobotState_<ContainerAllocator> & _arg)
  {
    this->robot_state = _arg;
    return *this;
  }
  Type & set__sensed_pos(
    const std::array<double, 7> & _arg)
  {
    this->sensed_pos = _arg;
    return *this;
  }
  Type & set__sensed_vel(
    const std::array<double, 7> & _arg)
  {
    this->sensed_vel = _arg;
    return *this;
  }
  Type & set__sensed_trq(
    const std::array<double, 7> & _arg)
  {
    this->sensed_trq = _arg;
    return *this;
  }
  Type & set__target_pos(
    const std::array<double, 7> & _arg)
  {
    this->target_pos = _arg;
    return *this;
  }
  Type & set__target_vel(
    const std::array<double, 7> & _arg)
  {
    this->target_vel = _arg;
    return *this;
  }
  Type & set__target_trq(
    const std::array<double, 7> & _arg)
  {
    this->target_trq = _arg;
    return *this;
  }
  Type & set__pos(
    const std::array<double, 3> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__rot(
    const std::array<double, 3> & _arg)
  {
    this->rot = _arg;
    return *this;
  }
  Type & set__iob_digital_out(
    const std::array<int8_t, 8> & _arg)
  {
    this->iob_digital_out = _arg;
    return *this;
  }
  Type & set__iob_relays(
    const std::array<int8_t, 4> & _arg)
  {
    this->iob_relays = _arg;
    return *this;
  }
  Type & set__iob_current_out(
    const std::array<float, 2> & _arg)
  {
    this->iob_current_out = _arg;
    return *this;
  }
  Type & set__iob_voltage_out(
    const std::array<float, 2> & _arg)
  {
    this->iob_voltage_out = _arg;
    return *this;
  }
  Type & set__iob_digital_in(
    const std::array<int8_t, 16> & _arg)
  {
    this->iob_digital_in = _arg;
    return *this;
  }
  Type & set__iob_safe_in(
    const std::array<int8_t, 4> & _arg)
  {
    this->iob_safe_in = _arg;
    return *this;
  }
  Type & set__iob_current_in(
    const std::array<float, 2> & _arg)
  {
    this->iob_current_in = _arg;
    return *this;
  }
  Type & set__iob_voltage_in(
    const std::array<float, 2> & _arg)
  {
    this->iob_voltage_in = _arg;
    return *this;
  }
  Type & set__iob_quadratures(
    const std::array<kr_msgs::msg::Quadrature_<ContainerAllocator>, 2> & _arg)
  {
    this->iob_quadratures = _arg;
    return *this;
  }
  Type & set__tio_digital_out(
    const std::array<int8_t, 4> & _arg)
  {
    this->tio_digital_out = _arg;
    return *this;
  }
  Type & set__tio_power_supply(
    const std::array<int8_t, 3> & _arg)
  {
    this->tio_power_supply = _arg;
    return *this;
  }
  Type & set__tio_analog_out(
    const std::array<float, 2> & _arg)
  {
    this->tio_analog_out = _arg;
    return *this;
  }
  Type & set__tio_current_in(
    const std::array<float, 1> & _arg)
  {
    this->tio_current_in = _arg;
    return *this;
  }
  Type & set__tio_voltage_in(
    const std::array<float, 4> & _arg)
  {
    this->tio_voltage_in = _arg;
    return *this;
  }
  Type & set__e_stop(
    const bool & _arg)
  {
    this->e_stop = _arg;
    return *this;
  }
  Type & set__p_stop(
    const bool & _arg)
  {
    this->p_stop = _arg;
    return *this;
  }
  Type & set__toggle(
    const bool & _arg)
  {
    this->toggle = _arg;
    return *this;
  }
  Type & set__backdrive(
    const bool & _arg)
  {
    this->backdrive = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::msg::SystemState_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::SystemState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::SystemState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::SystemState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SystemState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SystemState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SystemState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SystemState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::SystemState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::SystemState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__SystemState
    std::shared_ptr<kr_msgs::msg::SystemState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__SystemState
    std::shared_ptr<kr_msgs::msg::SystemState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SystemState_ & other) const
  {
    if (this->robot_mode != other.robot_mode) {
      return false;
    }
    if (this->robot_state != other.robot_state) {
      return false;
    }
    if (this->sensed_pos != other.sensed_pos) {
      return false;
    }
    if (this->sensed_vel != other.sensed_vel) {
      return false;
    }
    if (this->sensed_trq != other.sensed_trq) {
      return false;
    }
    if (this->target_pos != other.target_pos) {
      return false;
    }
    if (this->target_vel != other.target_vel) {
      return false;
    }
    if (this->target_trq != other.target_trq) {
      return false;
    }
    if (this->pos != other.pos) {
      return false;
    }
    if (this->rot != other.rot) {
      return false;
    }
    if (this->iob_digital_out != other.iob_digital_out) {
      return false;
    }
    if (this->iob_relays != other.iob_relays) {
      return false;
    }
    if (this->iob_current_out != other.iob_current_out) {
      return false;
    }
    if (this->iob_voltage_out != other.iob_voltage_out) {
      return false;
    }
    if (this->iob_digital_in != other.iob_digital_in) {
      return false;
    }
    if (this->iob_safe_in != other.iob_safe_in) {
      return false;
    }
    if (this->iob_current_in != other.iob_current_in) {
      return false;
    }
    if (this->iob_voltage_in != other.iob_voltage_in) {
      return false;
    }
    if (this->iob_quadratures != other.iob_quadratures) {
      return false;
    }
    if (this->tio_digital_out != other.tio_digital_out) {
      return false;
    }
    if (this->tio_power_supply != other.tio_power_supply) {
      return false;
    }
    if (this->tio_analog_out != other.tio_analog_out) {
      return false;
    }
    if (this->tio_current_in != other.tio_current_in) {
      return false;
    }
    if (this->tio_voltage_in != other.tio_voltage_in) {
      return false;
    }
    if (this->e_stop != other.e_stop) {
      return false;
    }
    if (this->p_stop != other.p_stop) {
      return false;
    }
    if (this->toggle != other.toggle) {
      return false;
    }
    if (this->backdrive != other.backdrive) {
      return false;
    }
    return true;
  }
  bool operator!=(const SystemState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SystemState_

// alias to use template instance with default allocator
using SystemState =
  kr_msgs::msg::SystemState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_HPP_
