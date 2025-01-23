// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from action_interfaces:msg/HookData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "action_interfaces/msg/detail/hook_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace action_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HookData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) action_interfaces::msg::HookData(_init);
}

void HookData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<action_interfaces::msg::HookData *>(message_memory);
  typed_message->~HookData();
}

size_t size_function__HookData__hooks(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<action_interfaces::msg::Hook> *>(untyped_member);
  return member->size();
}

const void * get_const_function__HookData__hooks(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<action_interfaces::msg::Hook> *>(untyped_member);
  return &member[index];
}

void * get_function__HookData__hooks(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<action_interfaces::msg::Hook> *>(untyped_member);
  return &member[index];
}

void resize_function__HookData__hooks(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<action_interfaces::msg::Hook> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HookData_message_member_array[1] = {
  {
    "hooks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<action_interfaces::msg::Hook>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interfaces::msg::HookData, hooks),  // bytes offset in struct
    nullptr,  // default value
    size_function__HookData__hooks,  // size() function pointer
    get_const_function__HookData__hooks,  // get_const(index) function pointer
    get_function__HookData__hooks,  // get(index) function pointer
    resize_function__HookData__hooks  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HookData_message_members = {
  "action_interfaces::msg",  // message namespace
  "HookData",  // message name
  1,  // number of fields
  sizeof(action_interfaces::msg::HookData),
  HookData_message_member_array,  // message members
  HookData_init_function,  // function to initialize message memory (memory has to be allocated)
  HookData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HookData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HookData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace action_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::msg::HookData>()
{
  return &::action_interfaces::msg::rosidl_typesupport_introspection_cpp::HookData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, msg, HookData)() {
  return &::action_interfaces::msg::rosidl_typesupport_introspection_cpp::HookData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
