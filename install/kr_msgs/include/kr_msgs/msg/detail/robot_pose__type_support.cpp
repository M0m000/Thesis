// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "kr_msgs/msg/detail/robot_pose__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace kr_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotPose_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) kr_msgs::msg::RobotPose(_init);
}

void RobotPose_fini_function(void * message_memory)
{
  auto typed_message = static_cast<kr_msgs::msg::RobotPose *>(message_memory);
  typed_message->~RobotPose();
}

size_t size_function__RobotPose__pos(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__RobotPose__pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotPose__pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__RobotPose__rot(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__RobotPose__rot(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotPose__rot(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

size_t size_function__RobotPose__jsconf(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__RobotPose__jsconf(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotPose__jsconf(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotPose_message_member_array[3] = {
  {
    "pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::RobotPose, pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotPose__pos,  // size() function pointer
    get_const_function__RobotPose__pos,  // get_const(index) function pointer
    get_function__RobotPose__pos,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::RobotPose, rot),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotPose__rot,  // size() function pointer
    get_const_function__RobotPose__rot,  // get_const(index) function pointer
    get_function__RobotPose__rot,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "jsconf",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::RobotPose, jsconf),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotPose__jsconf,  // size() function pointer
    get_const_function__RobotPose__jsconf,  // get_const(index) function pointer
    get_function__RobotPose__jsconf,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotPose_message_members = {
  "kr_msgs::msg",  // message namespace
  "RobotPose",  // message name
  3,  // number of fields
  sizeof(kr_msgs::msg::RobotPose),
  RobotPose_message_member_array,  // message members
  RobotPose_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotPose_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotPose_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotPose_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace kr_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<kr_msgs::msg::RobotPose>()
{
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::RobotPose_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kr_msgs, msg, RobotPose)() {
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::RobotPose_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
