// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/GetProgramState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_PROGRAM_STATE__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__GET_PROGRAM_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetProgramState_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetProgramState_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetProgramState_Request_
{
  using Type = GetProgramState_Request_<ContainerAllocator>;

  explicit GetProgramState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetProgramState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kr_msgs::srv::GetProgramState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetProgramState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetProgramState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetProgramState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetProgramState_Request
    std::shared_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetProgramState_Request
    std::shared_ptr<kr_msgs::srv::GetProgramState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetProgramState_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetProgramState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetProgramState_Request_

// alias to use template instance with default allocator
using GetProgramState_Request =
  kr_msgs::srv::GetProgramState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetProgramState_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetProgramState_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetProgramState_Response_
{
  using Type = GetProgramState_Response_<ContainerAllocator>;

  explicit GetProgramState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0ul;
      this->success = false;
    }
  }

  explicit GetProgramState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0ul;
      this->success = false;
    }
  }

  // field types and members
  using _state_type =
    uint32_t;
  _state_type state;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__state(
    const uint32_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t NONE =
    0;
  static constexpr int8_t RUNNING =
    1;
  static constexpr int8_t PAUSED =
    2;
  static constexpr int8_t HALTED =
    3;

  // pointer types
  using RawPtr =
    kr_msgs::srv::GetProgramState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetProgramState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetProgramState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetProgramState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetProgramState_Response
    std::shared_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetProgramState_Response
    std::shared_ptr<kr_msgs::srv::GetProgramState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetProgramState_Response_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetProgramState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetProgramState_Response_

// alias to use template instance with default allocator
using GetProgramState_Response =
  kr_msgs::srv::GetProgramState_Response_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t GetProgramState_Response_<ContainerAllocator>::NONE;
template<typename ContainerAllocator>
constexpr int8_t GetProgramState_Response_<ContainerAllocator>::RUNNING;
template<typename ContainerAllocator>
constexpr int8_t GetProgramState_Response_<ContainerAllocator>::PAUSED;
template<typename ContainerAllocator>
constexpr int8_t GetProgramState_Response_<ContainerAllocator>::HALTED;

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct GetProgramState
{
  using Request = kr_msgs::srv::GetProgramState_Request;
  using Response = kr_msgs::srv::GetProgramState_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_PROGRAM_STATE__STRUCT_HPP_
