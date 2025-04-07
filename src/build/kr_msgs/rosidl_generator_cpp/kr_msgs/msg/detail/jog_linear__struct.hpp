// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/JogLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__JOG_LINEAR__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__JOG_LINEAR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__JogLinear __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__JogLinear __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JogLinear_
{
  using Type = JogLinear_<ContainerAllocator>;

  explicit JogLinear_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->vel.begin(), this->vel.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
    }
  }

  explicit JogLinear_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vel(_alloc),
    rot(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->vel.begin(), this->vel.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
    }
  }

  // field types and members
  using _vel_type =
    std::array<double, 3>;
  _vel_type vel;
  using _rot_type =
    std::array<double, 3>;
  _rot_type rot;

  // setters for named parameter idiom
  Type & set__vel(
    const std::array<double, 3> & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__rot(
    const std::array<double, 3> & _arg)
  {
    this->rot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::msg::JogLinear_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::JogLinear_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::JogLinear_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::JogLinear_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__JogLinear
    std::shared_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__JogLinear
    std::shared_ptr<kr_msgs::msg::JogLinear_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JogLinear_ & other) const
  {
    if (this->vel != other.vel) {
      return false;
    }
    if (this->rot != other.rot) {
      return false;
    }
    return true;
  }
  bool operator!=(const JogLinear_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JogLinear_

// alias to use template instance with default allocator
using JogLinear =
  kr_msgs::msg::JogLinear_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__JOG_LINEAR__STRUCT_HPP_
