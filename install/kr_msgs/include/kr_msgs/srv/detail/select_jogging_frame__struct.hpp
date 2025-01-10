// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/SelectJoggingFrame.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SelectJoggingFrame_Request_
{
  using Type = SelectJoggingFrame_Request_<ContainerAllocator>;

  explicit SelectJoggingFrame_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ref = 0;
    }
  }

  explicit SelectJoggingFrame_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ref = 0;
    }
  }

  // field types and members
  using _ref_type =
    int8_t;
  _ref_type ref;

  // setters for named parameter idiom
  Type & set__ref(
    const int8_t & _arg)
  {
    this->ref = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t WORLD =
    0;
  static constexpr int8_t BASE =
    1;
  static constexpr int8_t TCP =
    2;

  // pointer types
  using RawPtr =
    kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Request
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Request
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SelectJoggingFrame_Request_ & other) const
  {
    if (this->ref != other.ref) {
      return false;
    }
    return true;
  }
  bool operator!=(const SelectJoggingFrame_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SelectJoggingFrame_Request_

// alias to use template instance with default allocator
using SelectJoggingFrame_Request =
  kr_msgs::srv::SelectJoggingFrame_Request_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t SelectJoggingFrame_Request_<ContainerAllocator>::WORLD;
template<typename ContainerAllocator>
constexpr int8_t SelectJoggingFrame_Request_<ContainerAllocator>::BASE;
template<typename ContainerAllocator>
constexpr int8_t SelectJoggingFrame_Request_<ContainerAllocator>::TCP;

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SelectJoggingFrame_Response_
{
  using Type = SelectJoggingFrame_Response_<ContainerAllocator>;

  explicit SelectJoggingFrame_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SelectJoggingFrame_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Response
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__SelectJoggingFrame_Response
    std::shared_ptr<kr_msgs::srv::SelectJoggingFrame_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SelectJoggingFrame_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SelectJoggingFrame_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SelectJoggingFrame_Response_

// alias to use template instance with default allocator
using SelectJoggingFrame_Response =
  kr_msgs::srv::SelectJoggingFrame_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct SelectJoggingFrame
{
  using Request = kr_msgs::srv::SelectJoggingFrame_Request;
  using Response = kr_msgs::srv::SelectJoggingFrame_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__SELECT_JOGGING_FRAME__STRUCT_HPP_
