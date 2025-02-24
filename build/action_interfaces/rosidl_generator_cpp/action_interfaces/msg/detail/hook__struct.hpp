// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK__STRUCT_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'hook_box'
// Member 'tip_box'
// Member 'lowpoint_box'
#include "action_interfaces/msg/detail/bounding_box__struct.hpp"
// Member 'hook_mask'
// Member 'tip_mask'
// Member 'lowpoint_mask'
// Member 'skeleton_mask'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'uv_hook'
// Member 'uv_tip'
// Member 'uv_lowpoint'
// Member 'uv_hook_img2'
// Member 'uv_tip_img2'
// Member 'uv_lowpoint_img2'
// Member 'shortest_path'
// Member 'path_points'
#include "action_interfaces/msg/detail/uv__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interfaces__msg__Hook __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__msg__Hook __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Hook_
{
  using Type = Hook_<ContainerAllocator>;

  explicit Hook_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hook_box(_init),
    tip_box(_init),
    lowpoint_box(_init),
    hook_mask(_init),
    tip_mask(_init),
    lowpoint_mask(_init),
    skeleton_mask(_init),
    uv_hook(_init),
    uv_tip(_init),
    uv_lowpoint(_init),
    uv_hook_img2(_init),
    uv_tip_img2(_init),
    uv_lowpoint_img2(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->conf_hook = 0.0f;
      this->conf_tip = 0.0f;
      this->conf_lowpoint = 0.0f;
    }
  }

  explicit Hook_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    hook_box(_alloc, _init),
    tip_box(_alloc, _init),
    lowpoint_box(_alloc, _init),
    hook_mask(_alloc, _init),
    tip_mask(_alloc, _init),
    lowpoint_mask(_alloc, _init),
    skeleton_mask(_alloc, _init),
    uv_hook(_alloc, _init),
    uv_tip(_alloc, _init),
    uv_lowpoint(_alloc, _init),
    uv_hook_img2(_alloc, _init),
    uv_tip_img2(_alloc, _init),
    uv_lowpoint_img2(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->conf_hook = 0.0f;
      this->conf_tip = 0.0f;
      this->conf_lowpoint = 0.0f;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _hook_box_type =
    action_interfaces::msg::BoundingBox_<ContainerAllocator>;
  _hook_box_type hook_box;
  using _tip_box_type =
    action_interfaces::msg::BoundingBox_<ContainerAllocator>;
  _tip_box_type tip_box;
  using _lowpoint_box_type =
    action_interfaces::msg::BoundingBox_<ContainerAllocator>;
  _lowpoint_box_type lowpoint_box;
  using _hook_mask_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _hook_mask_type hook_mask;
  using _tip_mask_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _tip_mask_type tip_mask;
  using _lowpoint_mask_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _lowpoint_mask_type lowpoint_mask;
  using _skeleton_mask_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _skeleton_mask_type skeleton_mask;
  using _conf_hook_type =
    float;
  _conf_hook_type conf_hook;
  using _conf_tip_type =
    float;
  _conf_tip_type conf_tip;
  using _conf_lowpoint_type =
    float;
  _conf_lowpoint_type conf_lowpoint;
  using _uv_hook_type =
    action_interfaces::msg::UV_<ContainerAllocator>;
  _uv_hook_type uv_hook;
  using _uv_tip_type =
    action_interfaces::msg::UV_<ContainerAllocator>;
  _uv_tip_type uv_tip;
  using _uv_lowpoint_type =
    action_interfaces::msg::UV_<ContainerAllocator>;
  _uv_lowpoint_type uv_lowpoint;
  using _uv_hook_img2_type =
    action_interfaces::msg::UV_<ContainerAllocator>;
  _uv_hook_img2_type uv_hook_img2;
  using _uv_tip_img2_type =
    action_interfaces::msg::UV_<ContainerAllocator>;
  _uv_tip_img2_type uv_tip_img2;
  using _uv_lowpoint_img2_type =
    action_interfaces::msg::UV_<ContainerAllocator>;
  _uv_lowpoint_img2_type uv_lowpoint_img2;
  using _shortest_path_type =
    std::vector<action_interfaces::msg::UV_<ContainerAllocator>, typename ContainerAllocator::template rebind<action_interfaces::msg::UV_<ContainerAllocator>>::other>;
  _shortest_path_type shortest_path;
  using _path_points_type =
    std::vector<action_interfaces::msg::UV_<ContainerAllocator>, typename ContainerAllocator::template rebind<action_interfaces::msg::UV_<ContainerAllocator>>::other>;
  _path_points_type path_points;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__hook_box(
    const action_interfaces::msg::BoundingBox_<ContainerAllocator> & _arg)
  {
    this->hook_box = _arg;
    return *this;
  }
  Type & set__tip_box(
    const action_interfaces::msg::BoundingBox_<ContainerAllocator> & _arg)
  {
    this->tip_box = _arg;
    return *this;
  }
  Type & set__lowpoint_box(
    const action_interfaces::msg::BoundingBox_<ContainerAllocator> & _arg)
  {
    this->lowpoint_box = _arg;
    return *this;
  }
  Type & set__hook_mask(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->hook_mask = _arg;
    return *this;
  }
  Type & set__tip_mask(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->tip_mask = _arg;
    return *this;
  }
  Type & set__lowpoint_mask(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->lowpoint_mask = _arg;
    return *this;
  }
  Type & set__skeleton_mask(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->skeleton_mask = _arg;
    return *this;
  }
  Type & set__conf_hook(
    const float & _arg)
  {
    this->conf_hook = _arg;
    return *this;
  }
  Type & set__conf_tip(
    const float & _arg)
  {
    this->conf_tip = _arg;
    return *this;
  }
  Type & set__conf_lowpoint(
    const float & _arg)
  {
    this->conf_lowpoint = _arg;
    return *this;
  }
  Type & set__uv_hook(
    const action_interfaces::msg::UV_<ContainerAllocator> & _arg)
  {
    this->uv_hook = _arg;
    return *this;
  }
  Type & set__uv_tip(
    const action_interfaces::msg::UV_<ContainerAllocator> & _arg)
  {
    this->uv_tip = _arg;
    return *this;
  }
  Type & set__uv_lowpoint(
    const action_interfaces::msg::UV_<ContainerAllocator> & _arg)
  {
    this->uv_lowpoint = _arg;
    return *this;
  }
  Type & set__uv_hook_img2(
    const action_interfaces::msg::UV_<ContainerAllocator> & _arg)
  {
    this->uv_hook_img2 = _arg;
    return *this;
  }
  Type & set__uv_tip_img2(
    const action_interfaces::msg::UV_<ContainerAllocator> & _arg)
  {
    this->uv_tip_img2 = _arg;
    return *this;
  }
  Type & set__uv_lowpoint_img2(
    const action_interfaces::msg::UV_<ContainerAllocator> & _arg)
  {
    this->uv_lowpoint_img2 = _arg;
    return *this;
  }
  Type & set__shortest_path(
    const std::vector<action_interfaces::msg::UV_<ContainerAllocator>, typename ContainerAllocator::template rebind<action_interfaces::msg::UV_<ContainerAllocator>>::other> & _arg)
  {
    this->shortest_path = _arg;
    return *this;
  }
  Type & set__path_points(
    const std::vector<action_interfaces::msg::UV_<ContainerAllocator>, typename ContainerAllocator::template rebind<action_interfaces::msg::UV_<ContainerAllocator>>::other> & _arg)
  {
    this->path_points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::msg::Hook_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::msg::Hook_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::msg::Hook_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::msg::Hook_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::Hook_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::Hook_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::Hook_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::Hook_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::msg::Hook_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::msg::Hook_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__msg__Hook
    std::shared_ptr<action_interfaces::msg::Hook_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__msg__Hook
    std::shared_ptr<action_interfaces::msg::Hook_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hook_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->hook_box != other.hook_box) {
      return false;
    }
    if (this->tip_box != other.tip_box) {
      return false;
    }
    if (this->lowpoint_box != other.lowpoint_box) {
      return false;
    }
    if (this->hook_mask != other.hook_mask) {
      return false;
    }
    if (this->tip_mask != other.tip_mask) {
      return false;
    }
    if (this->lowpoint_mask != other.lowpoint_mask) {
      return false;
    }
    if (this->skeleton_mask != other.skeleton_mask) {
      return false;
    }
    if (this->conf_hook != other.conf_hook) {
      return false;
    }
    if (this->conf_tip != other.conf_tip) {
      return false;
    }
    if (this->conf_lowpoint != other.conf_lowpoint) {
      return false;
    }
    if (this->uv_hook != other.uv_hook) {
      return false;
    }
    if (this->uv_tip != other.uv_tip) {
      return false;
    }
    if (this->uv_lowpoint != other.uv_lowpoint) {
      return false;
    }
    if (this->uv_hook_img2 != other.uv_hook_img2) {
      return false;
    }
    if (this->uv_tip_img2 != other.uv_tip_img2) {
      return false;
    }
    if (this->uv_lowpoint_img2 != other.uv_lowpoint_img2) {
      return false;
    }
    if (this->shortest_path != other.shortest_path) {
      return false;
    }
    if (this->path_points != other.path_points) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hook_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hook_

// alias to use template instance with default allocator
using Hook =
  action_interfaces::msg::Hook_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK__STRUCT_HPP_
