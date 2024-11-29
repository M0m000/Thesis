// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/ConfigQuadratureInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConfigQuadratureInput_Request_
{
  using Type = ConfigQuadratureInput_Request_<ContainerAllocator>;

  explicit ConfigQuadratureInput_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->pulse_per_rev = 0l;
      this->idx_availability = false;
    }
  }

  explicit ConfigQuadratureInput_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->pulse_per_rev = 0l;
      this->idx_availability = false;
    }
  }

  // field types and members
  using _index_type =
    int8_t;
  _index_type index;
  using _pulse_per_rev_type =
    int32_t;
  _pulse_per_rev_type pulse_per_rev;
  using _idx_availability_type =
    bool;
  _idx_availability_type idx_availability;

  // setters for named parameter idiom
  Type & set__index(
    const int8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__pulse_per_rev(
    const int32_t & _arg)
  {
    this->pulse_per_rev = _arg;
    return *this;
  }
  Type & set__idx_availability(
    const bool & _arg)
  {
    this->idx_availability = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Request
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Request
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigQuadratureInput_Request_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    if (this->pulse_per_rev != other.pulse_per_rev) {
      return false;
    }
    if (this->idx_availability != other.idx_availability) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigQuadratureInput_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigQuadratureInput_Request_

// alias to use template instance with default allocator
using ConfigQuadratureInput_Request =
  kr_msgs::srv::ConfigQuadratureInput_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConfigQuadratureInput_Response_
{
  using Type = ConfigQuadratureInput_Response_<ContainerAllocator>;

  explicit ConfigQuadratureInput_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ConfigQuadratureInput_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Response
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__ConfigQuadratureInput_Response
    std::shared_ptr<kr_msgs::srv::ConfigQuadratureInput_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigQuadratureInput_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigQuadratureInput_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigQuadratureInput_Response_

// alias to use template instance with default allocator
using ConfigQuadratureInput_Response =
  kr_msgs::srv::ConfigQuadratureInput_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct ConfigQuadratureInput
{
  using Request = kr_msgs::srv::ConfigQuadratureInput_Request;
  using Response = kr_msgs::srv::ConfigQuadratureInput_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__STRUCT_HPP_
