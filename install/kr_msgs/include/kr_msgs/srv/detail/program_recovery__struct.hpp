// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/ProgramRecovery.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__PROGRAM_RECOVERY__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__PROGRAM_RECOVERY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__ProgramRecovery_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__ProgramRecovery_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ProgramRecovery_Request_
{
  using Type = ProgramRecovery_Request_<ContainerAllocator>;

  explicit ProgramRecovery_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action = 0;
    }
  }

  explicit ProgramRecovery_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action = 0;
    }
  }

  // field types and members
  using _action_type =
    int8_t;
  _action_type action;

  // setters for named parameter idiom
  Type & set__action(
    const int8_t & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t RECOVER =
    0;
  static constexpr int8_t SKIP =
    1;

  // pointer types
  using RawPtr =
    kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__ProgramRecovery_Request
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__ProgramRecovery_Request
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProgramRecovery_Request_ & other) const
  {
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProgramRecovery_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProgramRecovery_Request_

// alias to use template instance with default allocator
using ProgramRecovery_Request =
  kr_msgs::srv::ProgramRecovery_Request_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t ProgramRecovery_Request_<ContainerAllocator>::RECOVER;
template<typename ContainerAllocator>
constexpr int8_t ProgramRecovery_Request_<ContainerAllocator>::SKIP;

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__ProgramRecovery_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__ProgramRecovery_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ProgramRecovery_Response_
{
  using Type = ProgramRecovery_Response_<ContainerAllocator>;

  explicit ProgramRecovery_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ProgramRecovery_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__ProgramRecovery_Response
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__ProgramRecovery_Response
    std::shared_ptr<kr_msgs::srv::ProgramRecovery_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProgramRecovery_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProgramRecovery_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProgramRecovery_Response_

// alias to use template instance with default allocator
using ProgramRecovery_Response =
  kr_msgs::srv::ProgramRecovery_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct ProgramRecovery
{
  using Request = kr_msgs::srv::ProgramRecovery_Request;
  using Response = kr_msgs::srv::ProgramRecovery_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__PROGRAM_RECOVERY__STRUCT_HPP_
