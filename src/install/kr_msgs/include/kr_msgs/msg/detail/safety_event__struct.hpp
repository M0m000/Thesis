// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kr_msgs:msg/SafetyEvent.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_EVENT__STRUCT_HPP_
#define KR_MSGS__MSG__DETAIL__SAFETY_EVENT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__kr_msgs__msg__SafetyEvent __attribute__((deprecated))
#else
# define DEPRECATED__kr_msgs__msg__SafetyEvent __declspec(deprecated)
#endif

namespace kr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SafetyEvent_
{
  using Type = SafetyEvent_<ContainerAllocator>;

  explicit SafetyEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->code = 0l;
      this->timestamp = 0ul;
    }
  }

  explicit SafetyEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->code = 0l;
      this->timestamp = 0ul;
    }
  }

  // field types and members
  using _type_type =
    int8_t;
  _type_type type;
  using _code_type =
    int32_t;
  _code_type code;
  using _timestamp_type =
    uint32_t;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__type(
    const int8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__code(
    const int32_t & _arg)
  {
    this->code = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint32_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t TYPE_ESTOP =
    1;
  static constexpr int8_t TYPE_PSTOP =
    2;
  static constexpr int8_t TYPE_SSTOP =
    3;
  static constexpr int32_t CODE_EXT_E_STOP_ACTIVATED =
    1;
  static constexpr int32_t CODE_EXT_P_STOP_ACTIVATED =
    2;
  static constexpr int32_t CODE_IOB_NOT_RESPONDING =
    3;
  static constexpr int32_t CODE_JBS_NOT_RESPONDING =
    4;
  static constexpr int32_t CODE_J_RATED_X_SENSOR_POS_SPAN =
    5;
  static constexpr int32_t CODE_J_RATED_POS_DELTA_SPAN =
    6;
  static constexpr int32_t CODE_J_RATED_SPEED_EXCEEDED =
    7;
  static constexpr int32_t CODE_J_RATED_TORQUE_EXCEEDED =
    8;
  static constexpr int32_t CODE_J_RATED_STATIC_TORQUE_EXCEEDED =
    9;
  static constexpr int32_t CODE_J_RATED_TEMPERATURE_EXCEEDED =
    10;
  static constexpr int32_t CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED =
    11;
  static constexpr int32_t CODE_MODEL_JS_SPAN_EXCEEDED =
    12;
  static constexpr int32_t CODE_MODEL_WS_SPAN_EXCEEDED =
    13;
  static constexpr int32_t CODE_MODEL_FRAME_SPEED_EXCEEDED =
    14;
  static constexpr int32_t CODE_TRQ_MODE_JSPEED_EXCEEDED =
    15;
  static constexpr int32_t CODE_INVALID_MODEL_STATE =
    21;
  static constexpr int32_t CODE_J_MODEL_VELOCITY_EXCEEDED =
    22;
  static constexpr int32_t CODE_J_MODEL_TORQUE_EXCEEDED =
    23;
  static constexpr int32_t CODE_J_MODEL_STATIC_TORQUE_EXCEEDED =
    24;
  static constexpr int32_t CODE_J_MODEL_LIMIT_ESTIMATION =
    25;

  // pointer types
  using RawPtr =
    kr_msgs::msg::SafetyEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const kr_msgs::msg::SafetyEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SafetyEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kr_msgs::msg::SafetyEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kr_msgs__msg__SafetyEvent
    std::shared_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kr_msgs__msg__SafetyEvent
    std::shared_ptr<kr_msgs::msg::SafetyEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SafetyEvent_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->code != other.code) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const SafetyEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SafetyEvent_

// alias to use template instance with default allocator
using SafetyEvent =
  kr_msgs::msg::SafetyEvent_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t SafetyEvent_<ContainerAllocator>::TYPE_ESTOP;
template<typename ContainerAllocator>
constexpr int8_t SafetyEvent_<ContainerAllocator>::TYPE_PSTOP;
template<typename ContainerAllocator>
constexpr int8_t SafetyEvent_<ContainerAllocator>::TYPE_SSTOP;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_EXT_E_STOP_ACTIVATED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_EXT_P_STOP_ACTIVATED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_IOB_NOT_RESPONDING;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_JBS_NOT_RESPONDING;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_RATED_X_SENSOR_POS_SPAN;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_RATED_POS_DELTA_SPAN;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_RATED_SPEED_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_RATED_TORQUE_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_RATED_STATIC_TORQUE_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_RATED_TEMPERATURE_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_MODEL_JS_SPAN_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_MODEL_WS_SPAN_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_MODEL_FRAME_SPEED_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_TRQ_MODE_JSPEED_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_INVALID_MODEL_STATE;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_MODEL_VELOCITY_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_MODEL_TORQUE_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_MODEL_STATIC_TORQUE_EXCEEDED;
template<typename ContainerAllocator>
constexpr int32_t SafetyEvent_<ContainerAllocator>::CODE_J_MODEL_LIMIT_ESTIMATION;

}  // namespace msg

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_EVENT__STRUCT_HPP_
