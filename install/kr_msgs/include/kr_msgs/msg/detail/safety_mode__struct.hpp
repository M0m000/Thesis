// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/SafetyMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_MODE__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__SAFETY_MODE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__SafetyMode __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__SafetyMode __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SafetyMode_
{
  using Type = SafetyMode_<ContainerAllocator>;

  explicit SafetyMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->val = 0;
    }
  }

  explicit SafetyMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->val = 0;
    }
  }

  // field types and members
  using _val_type =
    int8_t;
  _val_type val;

  // setters for named parameter idiom
  Type & set__val(
    const int8_t & _arg)
  {
    this->val = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t SAFE =
    0;
  static constexpr int8_t REDUCED =
    1;
  static constexpr int8_t NORMAL =
    2;

  // pointer types
  using RawPtr =
    kr_msgs::msg::SafetyMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::SafetyMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SafetyMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SafetyMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__SafetyMode
    std::shared_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__SafetyMode
    std::shared_ptr<kr_msgs::msg::SafetyMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SafetyMode_ & other) const
  {
    if (this->val != other.val) {
      return false;
    }
    return true;
  }
  bool operator!=(const SafetyMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SafetyMode_

// alias to use template instance with default allocator
using SafetyMode =
  kr_msgs::msg::SafetyMode_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t SafetyMode_<ContainerAllocator>::SAFE;
template<typename ContainerAllocator>
constexpr int8_t SafetyMode_<ContainerAllocator>::REDUCED;
template<typename ContainerAllocator>
constexpr int8_t SafetyMode_<ContainerAllocator>::NORMAL;

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_MODE__STRUCT_HPP_
