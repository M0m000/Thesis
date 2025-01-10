// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/RobotMode.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_MODE__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__ROBOT_MODE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__RobotMode __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__RobotMode __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotMode_
{
  using Type = RobotMode_<ContainerAllocator>;

  explicit RobotMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->val = 0;
      this->str = "";
    }
  }

  explicit RobotMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : str(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->val = 0;
      this->str = "";
    }
  }

  // field types and members
  using _val_type =
    int8_t;
  _val_type val;
  using _str_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _str_type str;

  // setters for named parameter idiom
  Type & set__val(
    const int8_t & _arg)
  {
    this->val = _arg;
    return *this;
  }
  Type & set__str(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->str = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t MANUAL =
    0;
  static constexpr int8_t AUTONOMOUS =
    1;

  // pointer types
  using RawPtr =
    kr_msgs::msg::RobotMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::RobotMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::RobotMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::RobotMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__RobotMode
    std::shared_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__RobotMode
    std::shared_ptr<kr_msgs::msg::RobotMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMode_ & other) const
  {
    if (this->val != other.val) {
      return false;
    }
    if (this->str != other.str) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMode_

// alias to use template instance with default allocator
using RobotMode =
  kr_msgs::msg::RobotMode_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t RobotMode_<ContainerAllocator>::MANUAL;
template<typename ContainerAllocator>
constexpr int8_t RobotMode_<ContainerAllocator>::AUTONOMOUS;

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_MODE__STRUCT_HPP_
