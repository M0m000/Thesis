// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__RobotState __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__RobotState __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotState_
{
  using Type = RobotState_<ContainerAllocator>;

  explicit RobotState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->val = 0;
      this->str = "";
    }
  }

  explicit RobotState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
  static constexpr int8_t INIT =
    1;
  static constexpr int8_t STANDBY =
    2;
  static constexpr int8_t MOVING =
    3;
  static constexpr int8_t BACKDRIVE =
    4;
  static constexpr int8_t SUSPENDED =
    5;
  static constexpr int8_t ALARM =
    6;

  // pointer types
  using RawPtr =
    kr_msgs::msg::RobotState_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::RobotState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::RobotState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::RobotState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::RobotState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::RobotState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::RobotState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::RobotState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__RobotState
    std::shared_ptr<kr_msgs::msg::RobotState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__RobotState
    std::shared_ptr<kr_msgs::msg::RobotState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotState_ & other) const
  {
    if (this->val != other.val) {
      return false;
    }
    if (this->str != other.str) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotState_

// alias to use template instance with default allocator
using RobotState =
  kr_msgs::msg::RobotState_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t RobotState_<ContainerAllocator>::INIT;
template<typename ContainerAllocator>
constexpr int8_t RobotState_<ContainerAllocator>::STANDBY;
template<typename ContainerAllocator>
constexpr int8_t RobotState_<ContainerAllocator>::MOVING;
template<typename ContainerAllocator>
constexpr int8_t RobotState_<ContainerAllocator>::BACKDRIVE;
template<typename ContainerAllocator>
constexpr int8_t RobotState_<ContainerAllocator>::SUSPENDED;
template<typename ContainerAllocator>
constexpr int8_t RobotState_<ContainerAllocator>::ALARM;

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
