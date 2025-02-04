// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/GetQuadratureInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_QUADRATURE_INPUT__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__GET_QUADRATURE_INPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetQuadratureInput_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetQuadratureInput_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetQuadratureInput_Request_
{
  using Type = GetQuadratureInput_Request_<ContainerAllocator>;

  explicit GetQuadratureInput_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
    }
  }

  explicit GetQuadratureInput_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
    }
  }

  // field types and members
  using _index_type =
    int8_t;
  _index_type index;

  // setters for named parameter idiom
  Type & set__index(
    const int8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetQuadratureInput_Request
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetQuadratureInput_Request
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetQuadratureInput_Request_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetQuadratureInput_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetQuadratureInput_Request_

// alias to use template instance with default allocator
using GetQuadratureInput_Request =
  kr_msgs::srv::GetQuadratureInput_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs


// Include directives for member types
// Member 'quad'
#include "kr_msgs/msg/detail/quadrature__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetQuadratureInput_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetQuadratureInput_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetQuadratureInput_Response_
{
  using Type = GetQuadratureInput_Response_<ContainerAllocator>;

  explicit GetQuadratureInput_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : quad(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit GetQuadratureInput_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : quad(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _quad_type =
    kr_msgs::msg::Quadrature_<ContainerAllocator>;
  _quad_type quad;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__quad(
    const kr_msgs::msg::Quadrature_<ContainerAllocator> & _arg)
  {
    this->quad = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetQuadratureInput_Response
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetQuadratureInput_Response
    std::shared_ptr<kr_msgs::srv::GetQuadratureInput_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetQuadratureInput_Response_ & other) const
  {
    if (this->quad != other.quad) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetQuadratureInput_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetQuadratureInput_Response_

// alias to use template instance with default allocator
using GetQuadratureInput_Response =
  kr_msgs::srv::GetQuadratureInput_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct GetQuadratureInput
{
  using Request = kr_msgs::srv::GetQuadratureInput_Request;
  using Response = kr_msgs::srv::GetQuadratureInput_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_QUADRATURE_INPUT__STRUCT_HPP_
