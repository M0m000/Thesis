// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/Quadrature.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__QUADRATURE__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__QUADRATURE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__Quadrature __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__Quadrature __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Quadrature_
{
  using Type = Quadrature_<ContainerAllocator>;

  explicit Quadrature_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = 0;
      this->pulse_count = 0l;
      this->frequency = 0l;
      this->abs_pulse_count = 0l;
      this->pulse_per_sec = 0l;
    }
  }

  explicit Quadrature_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = 0;
      this->pulse_count = 0l;
      this->frequency = 0l;
      this->abs_pulse_count = 0l;
      this->pulse_per_sec = 0l;
    }
  }

  // field types and members
  using _direction_type =
    int8_t;
  _direction_type direction;
  using _pulse_count_type =
    int32_t;
  _pulse_count_type pulse_count;
  using _frequency_type =
    int32_t;
  _frequency_type frequency;
  using _abs_pulse_count_type =
    int32_t;
  _abs_pulse_count_type abs_pulse_count;
  using _pulse_per_sec_type =
    int32_t;
  _pulse_per_sec_type pulse_per_sec;

  // setters for named parameter idiom
  Type & set__direction(
    const int8_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__pulse_count(
    const int32_t & _arg)
  {
    this->pulse_count = _arg;
    return *this;
  }
  Type & set__frequency(
    const int32_t & _arg)
  {
    this->frequency = _arg;
    return *this;
  }
  Type & set__abs_pulse_count(
    const int32_t & _arg)
  {
    this->abs_pulse_count = _arg;
    return *this;
  }
  Type & set__pulse_per_sec(
    const int32_t & _arg)
  {
    this->pulse_per_sec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::msg::Quadrature_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::Quadrature_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::Quadrature_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::Quadrature_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__Quadrature
    std::shared_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__Quadrature
    std::shared_ptr<kr_msgs::msg::Quadrature_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Quadrature_ & other) const
  {
    if (this->direction != other.direction) {
      return false;
    }
    if (this->pulse_count != other.pulse_count) {
      return false;
    }
    if (this->frequency != other.frequency) {
      return false;
    }
    if (this->abs_pulse_count != other.abs_pulse_count) {
      return false;
    }
    if (this->pulse_per_sec != other.pulse_per_sec) {
      return false;
    }
    return true;
  }
  bool operator!=(const Quadrature_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Quadrature_

// alias to use template instance with default allocator
using Quadrature =
  kr_msgs::msg::Quadrature_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__QUADRATURE__STRUCT_HPP_
