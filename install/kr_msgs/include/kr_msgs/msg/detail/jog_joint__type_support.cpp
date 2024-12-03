// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:msg/JogJoint.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "kr_msgs/msg/detail/jog_joint__struct.hpp"
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

void JogJoint_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) kr_msgs::msg::JogJoint(_init);
}

void JogJoint_fini_function(void * message_memory)
{
  auto typed_message = static_cast<kr_msgs::msg::JogJoint *>(message_memory);
  typed_message->~JogJoint();
}

size_t size_function__JogJoint__jsvel(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__JogJoint__jsvel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__JogJoint__jsvel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember JogJoint_message_member_array[1] = {
  {
    "jsvel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::JogJoint, jsvel),  // bytes offset in struct
    nullptr,  // default value
    size_function__JogJoint__jsvel,  // size() function pointer
    get_const_function__JogJoint__jsvel,  // get_const(index) function pointer
    get_function__JogJoint__jsvel,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers JogJoint_message_members = {
  "kr_msgs::msg",  // message namespace
  "JogJoint",  // message name
  1,  // number of fields
  sizeof(kr_msgs::msg::JogJoint),
  JogJoint_message_member_array,  // message members
  JogJoint_init_function,  // function to initialize message memory (memory has to be allocated)
  JogJoint_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t JogJoint_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &JogJoint_message_members,
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
get_message_type_support_handle<kr_msgs::msg::JogJoint>()
{
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::JogJoint_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kr_msgs, msg, JogJoint)() {
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::JogJoint_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
