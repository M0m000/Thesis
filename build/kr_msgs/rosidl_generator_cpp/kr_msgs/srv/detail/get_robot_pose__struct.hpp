// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:srv/GetRobotPose.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_ROBOT_POSE__STRUCT_HPP_
#define KR_MSGS__SRV__DETAIL__GET_ROBOT_POSE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetRobotPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetRobotPose_Request __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRobotPose_Request_
{
  using Type = GetRobotPose_Request_<ContainerAllocator>;

  explicit GetRobotPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetRobotPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetRobotPose_Request
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetRobotPose_Request
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRobotPose_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRobotPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRobotPose_Request_

// alias to use template instance with default allocator
using GetRobotPose_Request =
  kr_msgs::srv::GetRobotPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs


#ifndef _WIN32
# define DEPRECATED__kr_msgs__srv__GetRobotPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__srv__GetRobotPose_Response __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRobotPose_Response_
{
  using Type = GetRobotPose_Response_<ContainerAllocator>;

  explicit GetRobotPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->jsconf.begin(), this->jsconf.end(), 0.0);
      this->success = false;
    }
  }

  explicit GetRobotPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc),
    rot(_alloc),
    jsconf(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->rot.begin(), this->rot.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->jsconf.begin(), this->jsconf.end(), 0.0);
      this->success = false;
    }
  }

  // field types and members
  using _pos_type =
    std::array<double, 3>;
  _pos_type pos;
  using _rot_type =
    std::array<double, 3>;
  _rot_type rot;
  using _jsconf_type =
    std::array<double, 7>;
  _jsconf_type jsconf;
  using _success_type =
    bool;
  _success_type success;

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
  Type & set__jsconf(
    const std::array<double, 7> & _arg)
  {
    this->jsconf = _arg;
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
    kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__srv__GetRobotPose_Response
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__srv__GetRobotPose_Response
    std::shared_ptr<kr_msgs::srv::GetRobotPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRobotPose_Response_ & other) const
  {
    if (this->pos != other.pos) {
      return false;
    }
    if (this->rot != other.rot) {
      return false;
    }
    if (this->jsconf != other.jsconf) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRobotPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRobotPose_Response_

// alias to use template instance with default allocator
using GetRobotPose_Response =
  kr_msgs::srv::GetRobotPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kr_msgs

namespace kr_msgs
{

namespace srv
{

struct GetRobotPose
{
  using Request = kr_msgs::srv::GetRobotPose_Request;
  using Response = kr_msgs::srv::GetRobotPose_Response;
};

}  // namespace srv

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_ROBOT_POSE__STRUCT_HPP_
