// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/GetSystemLoad.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_SYSTEM_LOAD__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__GET_SYSTEM_LOAD__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetSystemLoad_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetSystemLoad_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSystemLoad_Request_
{
  using Type = GetSystemLoad_Request_<ContainerAllocator>;

  explicit GetSystemLoad_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit GetSystemLoad_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> TOOLLOAD;
  static const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> PAYLOAD;

  // pointer types
  using RawPtr =
    kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetSystemLoad_Request
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetSystemLoad_Request
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSystemLoad_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSystemLoad_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSystemLoad_Request_

// alias to use template instance with default allocator
using GetSystemLoad_Request =
  kr_msgs::srv::GetSystemLoad_Request_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>
GetSystemLoad_Request_<ContainerAllocator>::TOOLLOAD = "toolload";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>
GetSystemLoad_Request_<ContainerAllocator>::PAYLOAD = "payload";

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetSystemLoad_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetSystemLoad_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSystemLoad_Response_
{
  using Type = GetSystemLoad_Response_<ContainerAllocator>;

  explicit GetSystemLoad_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mass = 0.0;
      std::fill<typename std::array<double, 3>::iterator, double>(this->cog.begin(), this->cog.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->imx.begin(), this->imx.end(), 0.0);
      this->success = false;
    }
  }

  explicit GetSystemLoad_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cog(_alloc),
    imx(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mass = 0.0;
      std::fill<typename std::array<double, 3>::iterator, double>(this->cog.begin(), this->cog.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->imx.begin(), this->imx.end(), 0.0);
      this->success = false;
    }
  }

  // field types and members
  using _mass_type =
    double;
  _mass_type mass;
  using _cog_type =
    std::array<double, 3>;
  _cog_type cog;
  using _imx_type =
    std::array<double, 6>;
  _imx_type imx;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__mass(
    const double & _arg)
  {
    this->mass = _arg;
    return *this;
  }
  Type & set__cog(
    const std::array<double, 3> & _arg)
  {
    this->cog = _arg;
    return *this;
  }
  Type & set__imx(
    const std::array<double, 6> & _arg)
  {
    this->imx = _arg;
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
    kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetSystemLoad_Response
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetSystemLoad_Response
    std::shared_ptr<kr_msgs::srv::GetSystemLoad_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSystemLoad_Response_ & other) const
  {
    if (this->mass != other.mass) {
      return false;
    }
    if (this->cog != other.cog) {
      return false;
    }
    if (this->imx != other.imx) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSystemLoad_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSystemLoad_Response_

// alias to use template instance with default allocator
using GetSystemLoad_Response =
  kr_msgs::srv::GetSystemLoad_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct GetSystemLoad
{
  using Request = kr_msgs::srv::GetSystemLoad_Request;
  using Response = kr_msgs::srv::GetSystemLoad_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_SYSTEM_LOAD__STRUCT_HPP_
