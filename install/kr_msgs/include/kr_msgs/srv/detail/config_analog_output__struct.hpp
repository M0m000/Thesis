// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/ConfigAnalogOutput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__CONFIG_ANALOG_OUTPUT__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__CONFIG_ANALOG_OUTPUT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConfigAnalogOutput_Request_
{
  using Type = ConfigAnalogOutput_Request_<ContainerAllocator>;

  explicit ConfigAnalogOutput_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->type = 0;
    }
  }

  explicit ConfigAnalogOutput_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->type = 0;
    }
  }

  // field types and members
  using _index_type =
    int8_t;
  _index_type index;
  using _type_type =
    int8_t;
  _type_type type;

  // setters for named parameter idiom
  Type & set__index(
    const int8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__type(
    const int8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t CURRENT =
    0;
  static constexpr int8_t VOLTAGE =
    1;

  // pointer types
  using RawPtr =
    kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Request
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Request
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigAnalogOutput_Request_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigAnalogOutput_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigAnalogOutput_Request_

// alias to use template instance with default allocator
using ConfigAnalogOutput_Request =
  kr_msgs::srv::ConfigAnalogOutput_Request_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t ConfigAnalogOutput_Request_<ContainerAllocator>::CURRENT;
template<typename ContainerAllocator>
constexpr int8_t ConfigAnalogOutput_Request_<ContainerAllocator>::VOLTAGE;

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConfigAnalogOutput_Response_
{
  using Type = ConfigAnalogOutput_Response_<ContainerAllocator>;

  explicit ConfigAnalogOutput_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ConfigAnalogOutput_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Response
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__ConfigAnalogOutput_Response
    std::shared_ptr<kr_msgs::srv::ConfigAnalogOutput_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigAnalogOutput_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigAnalogOutput_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigAnalogOutput_Response_

// alias to use template instance with default allocator
using ConfigAnalogOutput_Response =
  kr_msgs::srv::ConfigAnalogOutput_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct ConfigAnalogOutput
{
  using Request = kr_msgs::srv::ConfigAnalogOutput_Request;
  using Response = kr_msgs::srv::ConfigAnalogOutput_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__CONFIG_ANALOG_OUTPUT__STRUCT_HPP_
