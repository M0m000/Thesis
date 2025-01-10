// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/GeometryPlane.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__GeometryPlane __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__GeometryPlane __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GeometryPlane_
{
  using Type = GeometryPlane_<ContainerAllocator>;

  explicit GeometryPlane_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      std::fill<typename std::array<double, 3>::iterator, double>(this->point.begin(), this->point.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->normal.begin(), this->normal.end(), 0.0);
    }
  }

  explicit GeometryPlane_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    point(_alloc),
    normal(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      std::fill<typename std::array<double, 3>::iterator, double>(this->point.begin(), this->point.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->normal.begin(), this->normal.end(), 0.0);
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _point_type =
    std::array<double, 3>;
  _point_type point;
  using _normal_type =
    std::array<double, 3>;
  _normal_type normal;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__point(
    const std::array<double, 3> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__normal(
    const std::array<double, 3> & _arg)
  {
    this->normal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::msg::GeometryPlane_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::GeometryPlane_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::GeometryPlane_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::GeometryPlane_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__GeometryPlane
    std::shared_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__GeometryPlane
    std::shared_ptr<kr_msgs::msg::GeometryPlane_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GeometryPlane_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    if (this->normal != other.normal) {
      return false;
    }
    return true;
  }
  bool operator!=(const GeometryPlane_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GeometryPlane_

// alias to use template instance with default allocator
using GeometryPlane =
  kr_msgs::msg::GeometryPlane_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__STRUCT_HPP_
