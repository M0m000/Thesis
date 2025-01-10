// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:srv/ConfigQuadratureInput.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__BUILDER_HPP_
#define KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__BUILDER_HPP_

#include "kr_msgs/srv/detail/config_quadrature_input__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigQuadratureInput_Request_idx_availability
{
public:
  explicit Init_ConfigQuadratureInput_Request_idx_availability(::kr_msgs::srv::ConfigQuadratureInput_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::srv::ConfigQuadratureInput_Request idx_availability(::kr_msgs::srv::ConfigQuadratureInput_Request::_idx_availability_type arg)
  {
    msg_.idx_availability = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::ConfigQuadratureInput_Request msg_;
};

class Init_ConfigQuadratureInput_Request_pulse_per_rev
{
public:
  explicit Init_ConfigQuadratureInput_Request_pulse_per_rev(::kr_msgs::srv::ConfigQuadratureInput_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigQuadratureInput_Request_idx_availability pulse_per_rev(::kr_msgs::srv::ConfigQuadratureInput_Request::_pulse_per_rev_type arg)
  {
    msg_.pulse_per_rev = std::move(arg);
    return Init_ConfigQuadratureInput_Request_idx_availability(msg_);
  }

private:
  ::kr_msgs::srv::ConfigQuadratureInput_Request msg_;
};

class Init_ConfigQuadratureInput_Request_index
{
public:
  Init_ConfigQuadratureInput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigQuadratureInput_Request_pulse_per_rev index(::kr_msgs::srv::ConfigQuadratureInput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_ConfigQuadratureInput_Request_pulse_per_rev(msg_);
  }

private:
  ::kr_msgs::srv::ConfigQuadratureInput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::ConfigQuadratureInput_Request>()
{
  return kr_msgs::srv::builder::Init_ConfigQuadratureInput_Request_index();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigQuadratureInput_Response_success
{
public:
  Init_ConfigQuadratureInput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::srv::ConfigQuadratureInput_Response success(::kr_msgs::srv::ConfigQuadratureInput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::srv::ConfigQuadratureInput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::srv::ConfigQuadratureInput_Response>()
{
  return kr_msgs::srv::builder::Init_ConfigQuadratureInput_Response_success();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__SRV__DETAIL__CONFIG_QUADRATURE_INPUT__BUILDER_HPP_
