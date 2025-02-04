// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/MoveSpline.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__MOVE_SPLINE__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__MOVE_SPLINE__BUILDER_HPP_

#include "kr_msgs/srv/detail/move_spline__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveSpline_Request_horizon
{
public:
  explicit Init_MoveSpline_Request_horizon(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::MoveSpline_Request horizon(::kr_msgs::srv::MoveSpline_Request::_horizon_type arg)
  {
    msg_.horizon = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_orient
{
public:
  explicit Init_MoveSpline_Request_orient(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_horizon orient(::kr_msgs::srv::MoveSpline_Request::_orient_type arg)
  {
    msg_.orient = std::move(arg);
    return Init_MoveSpline_Request_horizon(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_sync
{
public:
  explicit Init_MoveSpline_Request_sync(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_orient sync(::kr_msgs::srv::MoveSpline_Request::_sync_type arg)
  {
    msg_.sync = std::move(arg);
    return Init_MoveSpline_Request_orient(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_bvalue
{
public:
  explicit Init_MoveSpline_Request_bvalue(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_sync bvalue(::kr_msgs::srv::MoveSpline_Request::_bvalue_type arg)
  {
    msg_.bvalue = std::move(arg);
    return Init_MoveSpline_Request_sync(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_btype
{
public:
  explicit Init_MoveSpline_Request_btype(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_bvalue btype(::kr_msgs::srv::MoveSpline_Request::_btype_type arg)
  {
    msg_.btype = std::move(arg);
    return Init_MoveSpline_Request_bvalue(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_bpoint
{
public:
  explicit Init_MoveSpline_Request_bpoint(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_btype bpoint(::kr_msgs::srv::MoveSpline_Request::_bpoint_type arg)
  {
    msg_.bpoint = std::move(arg);
    return Init_MoveSpline_Request_btype(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_tvalue
{
public:
  explicit Init_MoveSpline_Request_tvalue(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_bpoint tvalue(::kr_msgs::srv::MoveSpline_Request::_tvalue_type arg)
  {
    msg_.tvalue = std::move(arg);
    return Init_MoveSpline_Request_bpoint(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_ttype
{
public:
  explicit Init_MoveSpline_Request_ttype(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_tvalue ttype(::kr_msgs::srv::MoveSpline_Request::_ttype_type arg)
  {
    msg_.ttype = std::move(arg);
    return Init_MoveSpline_Request_tvalue(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_ref
{
public:
  explicit Init_MoveSpline_Request_ref(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_ttype ref(::kr_msgs::srv::MoveSpline_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_MoveSpline_Request_ttype(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_rot
{
public:
  explicit Init_MoveSpline_Request_rot(::kr_msgs::srv::MoveSpline_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpline_Request_ref rot(::kr_msgs::srv::MoveSpline_Request::_rot_type arg)
  {
    msg_.rot = std::move(arg);
    return Init_MoveSpline_Request_ref(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

class Init_MoveSpline_Request_pos
{
public:
  Init_MoveSpline_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveSpline_Request_rot pos(::kr_msgs::srv::MoveSpline_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_MoveSpline_Request_rot(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::MoveSpline_Request>()
{
  return kr_msgs::srv::builder::Init_MoveSpline_Request_pos();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveSpline_Response_success
{
public:
  Init_MoveSpline_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::MoveSpline_Response success(::kr_msgs::srv::MoveSpline_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::MoveSpline_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::MoveSpline_Response>()
{
  return kr_msgs::srv::builder::Init_MoveSpline_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__MOVE_SPLINE__BUILDER_HPP_
