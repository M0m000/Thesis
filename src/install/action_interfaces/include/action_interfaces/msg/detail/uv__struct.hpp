// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interfaces:msg/UV.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__UV__STRUCT_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__UV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__action_interfaces__msg__UV __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__msg__UV __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UV_
{
  using Type = UV_<ContainerAllocator>;

  explicit UV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
    }
  }

  explicit UV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
    }
  }

  // field types and members
  using _u_type =
    float;
  _u_type u;
  using _v_type =
    float;
  _v_type v;

  // setters for named parameter idiom
  Type & set__u(
    const float & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const float & _arg)
  {
    this->v = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::msg::UV_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::msg::UV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::msg::UV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::msg::UV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::UV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::UV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::UV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::UV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::msg::UV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::msg::UV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__msg__UV
    std::shared_ptr<action_interfaces::msg::UV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__msg__UV
    std::shared_ptr<action_interfaces::msg::UV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UV_ & other) const
  {
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    return true;
  }
  bool operator!=(const UV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UV_

// alias to use template instance with default allocator
using UV =
  action_interfaces::msg::UV_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__UV__STRUCT_HPP_
