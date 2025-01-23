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
    (void)_init;
  }

  explicit UV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _data_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->data = _arg;
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
    if (this->data != other.data) {
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
