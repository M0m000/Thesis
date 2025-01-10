// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/JogJoint.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__JOG_JOINT__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__JOG_JOINT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__JogJoint __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__JogJoint __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JogJoint_
{
  using Type = JogJoint_<ContainerAllocator>;

  explicit JogJoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->jsvel.begin(), this->jsvel.end(), 0.0);
    }
  }

  explicit JogJoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : jsvel(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->jsvel.begin(), this->jsvel.end(), 0.0);
    }
  }

  // field types and members
  using _jsvel_type =
    std::array<double, 7>;
  _jsvel_type jsvel;

  // setters for named parameter idiom
  Type & set__jsvel(
    const std::array<double, 7> & _arg)
  {
    this->jsvel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::msg::JogJoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::JogJoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::JogJoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::JogJoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__JogJoint
    std::shared_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__JogJoint
    std::shared_ptr<kr_msgs::msg::JogJoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JogJoint_ & other) const
  {
    if (this->jsvel != other.jsvel) {
      return false;
    }
    return true;
  }
  bool operator!=(const JogJoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JogJoint_

// alias to use template instance with default allocator
using JogJoint =
  kr_msgs::msg::JogJoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__JOG_JOINT__STRUCT_HPP_
