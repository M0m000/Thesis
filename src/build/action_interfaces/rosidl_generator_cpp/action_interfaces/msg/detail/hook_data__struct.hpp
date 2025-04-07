// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__STRUCT_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'hooks'
#include "action_interfaces/msg/detail/hook__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interfaces__msg__HookData __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__msg__HookData __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HookData_
{
  using Type = HookData_<ContainerAllocator>;

  explicit HookData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit HookData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _hooks_type =
    std::vector<action_interfaces::msg::Hook_<ContainerAllocator>, typename ContainerAllocator::template rebind<action_interfaces::msg::Hook_<ContainerAllocator>>::other>;
  _hooks_type hooks;

  // setters for named parameter idiom
  Type & set__hooks(
    const std::vector<action_interfaces::msg::Hook_<ContainerAllocator>, typename ContainerAllocator::template rebind<action_interfaces::msg::Hook_<ContainerAllocator>>::other> & _arg)
  {
    this->hooks = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::msg::HookData_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::msg::HookData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::msg::HookData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::msg::HookData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::HookData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::HookData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::HookData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::HookData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::msg::HookData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::msg::HookData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__msg__HookData
    std::shared_ptr<action_interfaces::msg::HookData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__msg__HookData
    std::shared_ptr<action_interfaces::msg::HookData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HookData_ & other) const
  {
    if (this->hooks != other.hooks) {
      return false;
    }
    return true;
  }
  bool operator!=(const HookData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HookData_

// alias to use template instance with default allocator
using HookData =
  action_interfaces::msg::HookData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK_DATA__STRUCT_HPP_
