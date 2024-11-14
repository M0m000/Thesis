// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/GetQuadratureInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__GET_QUADRATURE_INPUT__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__GET_QUADRATURE_INPUT__BUILDER_HPP_

#include "kr_msgs/srv/detail/get_quadrature_input__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetQuadratureInput_Request_index
{
public:
  Init_GetQuadratureInput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::GetQuadratureInput_Request index(::kr_msgs::srv::GetQuadratureInput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetQuadratureInput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetQuadratureInput_Request>()
{
  return kr_msgs::srv::builder::Init_GetQuadratureInput_Request_index();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_GetQuadratureInput_Response_success
{
public:
  explicit Init_GetQuadratureInput_Response_success(::kr_msgs::srv::GetQuadratureInput_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::GetQuadratureInput_Response success(::kr_msgs::srv::GetQuadratureInput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::GetQuadratureInput_Response msg_;
};

class Init_GetQuadratureInput_Response_quad
{
public:
  Init_GetQuadratureInput_Response_quad()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetQuadratureInput_Response_success quad(::kr_msgs::srv::GetQuadratureInput_Response::_quad_type arg)
  {
    msg_.quad = std::move(arg);
    return Init_GetQuadratureInput_Response_success(msg_);
  }

private:
  ::kr_msgs::srv::GetQuadratureInput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::GetQuadratureInput_Response>()
{
  return kr_msgs::srv::builder::Init_GetQuadratureInput_Response_quad();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__GET_QUADRATURE_INPUT__BUILDER_HPP_
