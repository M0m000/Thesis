// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveTCPAlongAxis_Request_
{
  using Type = MoveTCPAlongAxis_Request_<ContainerAllocator>;

  explicit MoveTCPAlongAxis_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->baseline = 0.0f;
      this->frame = "";
      this->axis = "";
    }
  }

  explicit MoveTCPAlongAxis_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : frame(_alloc),
    axis(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->baseline = 0.0f;
      this->frame = "";
      this->axis = "";
    }
  }

  // field types and members
  using _baseline_type =
    float;
  _baseline_type baseline;
  using _frame_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _frame_type frame;
  using _axis_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _axis_type axis;

  // setters for named parameter idiom
  Type & set__baseline(
    const float & _arg)
  {
    this->baseline = _arg;
    return *this;
  }
  Type & set__frame(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->frame = _arg;
    return *this;
  }
  Type & set__axis(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->axis = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Request
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Request
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveTCPAlongAxis_Request_ & other) const
  {
    if (this->baseline != other.baseline) {
      return false;
    }
    if (this->frame != other.frame) {
      return false;
    }
    if (this->axis != other.axis) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveTCPAlongAxis_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveTCPAlongAxis_Request_

// alias to use template instance with default allocator
using MoveTCPAlongAxis_Request =
  kr_msgs::srv::MoveTCPAlongAxis_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveTCPAlongAxis_Response_
{
  using Type = MoveTCPAlongAxis_Response_<ContainerAllocator>;

  explicit MoveTCPAlongAxis_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MoveTCPAlongAxis_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Response
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__MoveTCPAlongAxis_Response
    std::shared_ptr<kr_msgs::srv::MoveTCPAlongAxis_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveTCPAlongAxis_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveTCPAlongAxis_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveTCPAlongAxis_Response_

// alias to use template instance with default allocator
using MoveTCPAlongAxis_Response =
  kr_msgs::srv::MoveTCPAlongAxis_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct MoveTCPAlongAxis
{
  using Request = kr_msgs::srv::MoveTCPAlongAxis_Request;
  using Response = kr_msgs::srv::MoveTCPAlongAxis_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__MOVE_TCP_ALONG_AXIS__STRUCT_HPP_
