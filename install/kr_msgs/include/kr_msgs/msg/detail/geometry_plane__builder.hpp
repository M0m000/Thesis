// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:msg/GeometryPlane.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__BUILDER_HPP_
#define KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__BUILDER_HPP_

#include "kr_msgs/msg/detail/geometry_plane__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace msg
{

namespace builder
{

class Init_GeometryPlane_normal
{
public:
  explicit Init_GeometryPlane_normal(::kr_msgs::msg::GeometryPlane & msg)
  : msg_(msg)
  {}
  ::kr_msgs::msg::GeometryPlane normal(::kr_msgs::msg::GeometryPlane::_normal_type arg)
  {
    msg_.normal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::msg::GeometryPlane msg_;
};

class Init_GeometryPlane_point
{
public:
  explicit Init_GeometryPlane_point(::kr_msgs::msg::GeometryPlane & msg)
  : msg_(msg)
  {}
  Init_GeometryPlane_normal point(::kr_msgs::msg::GeometryPlane::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_GeometryPlane_normal(msg_);
  }

private:
  ::kr_msgs::msg::GeometryPlane msg_;
};

class Init_GeometryPlane_name
{
public:
  Init_GeometryPlane_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GeometryPlane_point name(::kr_msgs::msg::GeometryPlane::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_GeometryPlane_point(msg_);
  }

private:
  ::kr_msgs::msg::GeometryPlane msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::msg::GeometryPlane>()
{
  return kr_msgs::msg::builder::Init_GeometryPlane_name();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__MSG__DETAIL__GEOMETRY_PLANE__BUILDER_HPP_
