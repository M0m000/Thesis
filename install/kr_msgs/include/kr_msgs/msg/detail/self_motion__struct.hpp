// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/SelfMotion.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SELF_MOTION__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__SELF_MOTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__SelfMotion __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__SelfMotion __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SelfMotion_
{
  using Type = SelfMotion_<ContainerAllocator>;

  explicit SelfMotion_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
    }
  }

  explicit SelfMotion_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
    }
  }

  // field types and members
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::msg::SelfMotion_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::SelfMotion_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SelfMotion_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SelfMotion_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__SelfMotion
    std::shared_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__SelfMotion
    std::shared_ptr<kr_msgs::msg::SelfMotion_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SelfMotion_ & other) const
  {
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const SelfMotion_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SelfMotion_

// alias to use template instance with default allocator
using SelfMotion =
  kr_msgs::msg::SelfMotion_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SELF_MOTION__STRUCT_HPP_
