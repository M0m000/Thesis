// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/MoveLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__MOVE_LINEAR__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__MOVE_LINEAR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__MoveLinear_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__MoveLinear_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveLinear_Request_
{
  using Type = MoveLinear_Request_<ContainerAllocator>;

  explicit MoveLinear_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
      this->sync = 0.0;
      this->chaining = 0;
    }
  }

  explicit MoveLinear_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
      this->sync = 0.0;
      this->chaining = 0;
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
  using _sync_type =
    double;
  _sync_type sync;
  using _chaining_type =
    int8_t;
  _chaining_type chaining;

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
  Type & set__sync(
    const double & _arg)
  {
    this->sync = _arg;
    return *this;
  }
  Type & set__chaining(
    const int8_t & _arg)
  {
    this->chaining = _arg;
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
  static constexpr int8_t CH_INT =
    0;
  static constexpr int8_t CH_COM =
    1;

  // pointer types
  using RawPtr =
    kr_msgs::srv::MoveLinear_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::MoveLinear_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveLinear_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveLinear_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__MoveLinear_Request
    std::shared_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__MoveLinear_Request
    std::shared_ptr<kr_msgs::srv::MoveLinear_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveLinear_Request_ & other) const
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
    if (this->sync != other.sync) {
      return false;
    }
    if (this->chaining != other.chaining) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveLinear_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveLinear_Request_

// alias to use template instance with default allocator
using MoveLinear_Request =
  kr_msgs::srv::MoveLinear_Request_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::WORLD;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::BASE;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::TCP;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::TT_VEL;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::TT_TIME;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::BP_STOP;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::BP_VIA;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::BT_ACC;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::BT_TIME;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::BT_RAD;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::CH_INT;
template<typename ContainerAllocator>
constexpr int8_t MoveLinear_Request_<ContainerAllocator>::CH_COM;

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__MoveLinear_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__MoveLinear_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveLinear_Response_
{
  using Type = MoveLinear_Response_<ContainerAllocator>;

  explicit MoveLinear_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MoveLinear_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kr_msgs::srv::MoveLinear_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::MoveLinear_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveLinear_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::MoveLinear_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__MoveLinear_Response
    std::shared_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__MoveLinear_Response
    std::shared_ptr<kr_msgs::srv::MoveLinear_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveLinear_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveLinear_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveLinear_Response_

// alias to use template instance with default allocator
using MoveLinear_Response =
  kr_msgs::srv::MoveLinear_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct MoveLinear
{
  using Request = kr_msgs::srv::MoveLinear_Request;
  using Response = kr_msgs::srv::MoveLinear_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__MOVE_LINEAR__STRUCT_HPP_
