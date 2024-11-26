// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_ZONE__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__SAFETY_ZONE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'planes'
#include "kr_msgs/msg/detail/geometry_plane__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__SafetyZone __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__SafetyZone __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SafetyZone_
{
  using Type = SafetyZone_<ContainerAllocator>;

  explicit SafetyZone_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->speed = 0.0;
      this->buffer = 0.0;
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensitivity.begin(), this->sensitivity.end(), 0.0);
      this->safety_io = 0;
    }
  }

  explicit SafetyZone_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    sensitivity(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->speed = 0.0;
      this->buffer = 0.0;
      std::fill<typename std::array<double, 7>::iterator, double>(this->sensitivity.begin(), this->sensitivity.end(), 0.0);
      this->safety_io = 0;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _speed_type =
    double;
  _speed_type speed;
  using _buffer_type =
    double;
  _buffer_type buffer;
  using _sensitivity_type =
    std::array<double, 7>;
  _sensitivity_type sensitivity;
  using _safety_io_type =
    int8_t;
  _safety_io_type safety_io;
  using _planes_type =
    std::vector<kr_msgs::msg::GeometryPlane_<ContainerAllocator>, typename ContainerAllocator::template rebind<kr_msgs::msg::GeometryPlane_<ContainerAllocator>>::other>;
  _planes_type planes;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__buffer(
    const double & _arg)
  {
    this->buffer = _arg;
    return *this;
  }
  Type & set__sensitivity(
    const std::array<double, 7> & _arg)
  {
    this->sensitivity = _arg;
    return *this;
  }
  Type & set__safety_io(
    const int8_t & _arg)
  {
    this->safety_io = _arg;
    return *this;
  }
  Type & set__planes(
    const std::vector<kr_msgs::msg::GeometryPlane_<ContainerAllocator>, typename ContainerAllocator::template rebind<kr_msgs::msg::GeometryPlane_<ContainerAllocator>>::other> & _arg)
  {
    this->planes = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t SDIO01 =
    1;
  static constexpr int8_t SDIO02 =
    2;
  static constexpr int8_t SDIO03 =
    3;
  static constexpr int8_t SDIO04 =
    4;

  // pointer types
  using RawPtr =
    kr_msgs::msg::SafetyZone_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::SafetyZone_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SafetyZone_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SafetyZone_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__SafetyZone
    std::shared_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__SafetyZone
    std::shared_ptr<kr_msgs::msg::SafetyZone_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SafetyZone_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->buffer != other.buffer) {
      return false;
    }
    if (this->sensitivity != other.sensitivity) {
      return false;
    }
    if (this->safety_io != other.safety_io) {
      return false;
    }
    if (this->planes != other.planes) {
      return false;
    }
    return true;
  }
  bool operator!=(const SafetyZone_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SafetyZone_

// alias to use template instance with default allocator
using SafetyZone =
  kr_msgs::msg::SafetyZone_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t SafetyZone_<ContainerAllocator>::SDIO01;
template<typename ContainerAllocator>
constexpr int8_t SafetyZone_<ContainerAllocator>::SDIO02;
template<typename ContainerAllocator>
constexpr int8_t SafetyZone_<ContainerAllocator>::SDIO03;
template<typename ContainerAllocator>
constexpr int8_t SafetyZone_<ContainerAllocator>::SDIO04;

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_ZONE__STRUCT_HPP_
