// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/FollowLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__FollowLinear __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__FollowLinear __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FollowLinear_
{
  using Type = FollowLinear_<ContainerAllocator>;

  explicit FollowLinear_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
      this->ref = 0;
      this->ttype = 0;
      this->tvalue = 0.0;
      this->bpoint = 0;
      this->btype = 0;
      this->bvalue = 0.0;
    }
  }

  explicit FollowLinear_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc),
    rot(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
      this->ref = 0;
      this->ttype = 0;
      this->tvalue = 0.0;
      this->bpoint = 0;
      this->btype = 0;
      this->bvalue = 0.0;
    }
  }

  // field types and members
  using _pos_type =
    std::array<double, 3>;
  _pos_type pos;
  using _rot_type =
    std::array<double, 3>;
  _rot_type rot;
  using _ref_type =
    int8_t;
  _ref_type ref;
  using _ttype_type =
    int8_t;
  _ttype_type ttype;
  using _tvalue_type =
    double;
  _tvalue_type tvalue;
  using _bpoint_type =
    int8_t;
  _bpoint_type bpoint;
  using _btype_type =
    int8_t;
  _btype_type btype;
  using _bvalue_type =
    double;
  _bvalue_type bvalue;

  // setters for named parameter idiom
  Type & set__pos(
    const std::array<double, 3> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__rot(
    const std::array<double, 3> & _arg)
  {
    this->rot = _arg;
    return *this;
  }
  Type & set__ref(
    const int8_t & _arg)
  {
    this->ref = _arg;
    return *this;
  }
  Type & set__ttype(
    const int8_t & _arg)
  {
    this->ttype = _arg;
    return *this;
  }
  Type & set__tvalue(
    const double & _arg)
  {
    this->tvalue = _arg;
    return *this;
  }
  Type & set__bpoint(
    const int8_t & _arg)
  {
    this->bpoint = _arg;
    return *this;
  }
  Type & set__btype(
    const int8_t & _arg)
  {
    this->btype = _arg;
    return *this;
  }
  Type & set__bvalue(
    const double & _arg)
  {
    this->bvalue = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t WORLD =
    0;
  static constexpr int8_t BASE =
    1;
  static constexpr int8_t TCP =
    2;
  static constexpr int8_t TT_VEL =
    0;
  static constexpr int8_t TT_TIME =
    1;
  static constexpr int8_t BP_STOP =
    0;
  static constexpr int8_t BP_VIA =
    1;
  static constexpr int8_t BT_ACC =
    0;
  static constexpr int8_t BT_TIME =
    1;
  static constexpr int8_t BT_RAD =
    2;

  // pointer types
  using RawPtr =
    kr_msgs::msg::FollowLinear_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::FollowLinear_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::FollowLinear_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::FollowLinear_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__FollowLinear
    std::shared_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__FollowLinear
    std::shared_ptr<kr_msgs::msg::FollowLinear_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FollowLinear_ & other) const
  {
    if (this->pos != other.pos) {
      return false;
    }
    if (this->rot != other.rot) {
      return false;
    }
    if (this->ref != other.ref) {
      return false;
    }
    if (this->ttype != other.ttype) {
      return false;
    }
    if (this->tvalue != other.tvalue) {
      return false;
    }
    if (this->bpoint != other.bpoint) {
      return false;
    }
    if (this->btype != other.btype) {
      return false;
    }
    if (this->bvalue != other.bvalue) {
      return false;
    }
    return true;
  }
  bool operator!=(const FollowLinear_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FollowLinear_

// alias to use template instance with default allocator
using FollowLinear =
  kr_msgs::msg::FollowLinear_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::WORLD;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::BASE;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::TCP;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::TT_VEL;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::TT_TIME;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::BP_STOP;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::BP_VIA;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::BT_ACC;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::BT_TIME;
template<typename ContainerAllocator>
constexpr int8_t FollowLinear_<ContainerAllocator>::BT_RAD;

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__STRUCT_HPP_
