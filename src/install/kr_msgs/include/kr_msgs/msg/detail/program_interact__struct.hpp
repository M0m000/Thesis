// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/ProgramInteract.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__PROGRAM_INTERACT__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__PROGRAM_INTERACT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__ProgramInteract __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__ProgramInteract __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProgramInteract_
{
  using Type = ProgramInteract_<ContainerAllocator>;

  explicit ProgramInteract_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ProgramInteract_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::msg::ProgramInteract_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::ProgramInteract_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::ProgramInteract_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::ProgramInteract_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__ProgramInteract
    std::shared_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__ProgramInteract
    std::shared_ptr<kr_msgs::msg::ProgramInteract_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProgramInteract_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProgramInteract_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProgramInteract_

// alias to use template instance with default allocator
using ProgramInteract =
  kr_msgs::msg::ProgramInteract_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__PROGRAM_INTERACT__STRUCT_HPP_
