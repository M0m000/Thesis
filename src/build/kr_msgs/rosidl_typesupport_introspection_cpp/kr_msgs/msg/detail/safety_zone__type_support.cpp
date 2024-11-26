// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "kr_msgs/msg/detail/safety_zone__struct.hpp"
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

void SafetyZone_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) kr_msgs::msg::SafetyZone(_init);
}

void SafetyZone_fini_function(void * message_memory)
{
  auto typed_message = static_cast<kr_msgs::msg::SafetyZone *>(message_memory);
  typed_message->~SafetyZone();
}

size_t size_function__SafetyZone__sensitivity(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__SafetyZone__sensitivity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__SafetyZone__sensitivity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

size_t size_function__SafetyZone__planes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<kr_msgs::msg::GeometryPlane> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SafetyZone__planes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<kr_msgs::msg::GeometryPlane> *>(untyped_member);
  return &member[index];
}

void * get_function__SafetyZone__planes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<kr_msgs::msg::GeometryPlane> *>(untyped_member);
  return &member[index];
}

void resize_function__SafetyZone__planes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<kr_msgs::msg::GeometryPlane> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SafetyZone_message_member_array[6] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SafetyZone, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SafetyZone, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "buffer",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SafetyZone, buffer),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sensitivity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SafetyZone, sensitivity),  // bytes offset in struct
    nullptr,  // default value
    size_function__SafetyZone__sensitivity,  // size() function pointer
    get_const_function__SafetyZone__sensitivity,  // get_const(index) function pointer
    get_function__SafetyZone__sensitivity,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "safety_io",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SafetyZone, safety_io),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "planes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<kr_msgs::msg::GeometryPlane>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kr_msgs::msg::SafetyZone, planes),  // bytes offset in struct
    nullptr,  // default value
    size_function__SafetyZone__planes,  // size() function pointer
    get_const_function__SafetyZone__planes,  // get_const(index) function pointer
    get_function__SafetyZone__planes,  // get(index) function pointer
    resize_function__SafetyZone__planes  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SafetyZone_message_members = {
  "kr_msgs::msg",  // message namespace
  "SafetyZone",  // message name
  6,  // number of fields
  sizeof(kr_msgs::msg::SafetyZone),
  SafetyZone_message_member_array,  // message members
  SafetyZone_init_function,  // function to initialize message memory (memory has to be allocated)
  SafetyZone_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SafetyZone_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SafetyZone_message_members,
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
get_message_type_support_handle<kr_msgs::msg::SafetyZone>()
{
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::SafetyZone_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, kr_msgs, msg, SafetyZone)() {
  return &::kr_msgs::msg::rosidl_typesupport_introspection_cpp::SafetyZone_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
