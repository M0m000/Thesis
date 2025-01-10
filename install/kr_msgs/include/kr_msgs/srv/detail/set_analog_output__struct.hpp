// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/SetAnalogOutput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__SET_ANALOG_OUTPUT__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__SET_ANALOG_OUTPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__SetAnalogOutput_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__SetAnalogOutput_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetAnalogOutput_Request_
{
  using Type = SetAnalogOutput_Request_<ContainerAllocator>;

  explicit SetAnalogOutput_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->value = 0.0f;
    }
  }

  explicit SetAnalogOutput_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->value = 0.0f;
    }
  }

  // field types and members
  using _index_type =
    int8_t;
  _index_type index;
  using _value_type =
    float;
  _value_type value;

  // setters for named parameter idiom
  Type & set__index(
    const int8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__value(
    const float & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__SetAnalogOutput_Request
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__SetAnalogOutput_Request
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetAnalogOutput_Request_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetAnalogOutput_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetAnalogOutput_Request_

// alias to use template instance with default allocator
using SetAnalogOutput_Request =
  kr_msgs::srv::SetAnalogOutput_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__SetAnalogOutput_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__SetAnalogOutput_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetAnalogOutput_Response_
{
  using Type = SetAnalogOutput_Response_<ContainerAllocator>;

  explicit SetAnalogOutput_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetAnalogOutput_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__SetAnalogOutput_Response
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__SetAnalogOutput_Response
    std::shared_ptr<kr_msgs::srv::SetAnalogOutput_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetAnalogOutput_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetAnalogOutput_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetAnalogOutput_Response_

// alias to use template instance with default allocator
using SetAnalogOutput_Response =
  kr_msgs::srv::SetAnalogOutput_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct SetAnalogOutput
{
  using Request = kr_msgs::srv::SetAnalogOutput_Request;
  using Response = kr_msgs::srv::SetAnalogOutput_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__SET_ANALOG_OUTPUT__STRUCT_HPP_
