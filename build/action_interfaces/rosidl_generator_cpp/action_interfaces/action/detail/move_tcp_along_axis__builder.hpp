// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:action/MoveTcpAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_
#define ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_

#include "action_interfaces/action/detail/move_tcp_along_axis__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_Goal_speed_in_mm_per_s
{
public:
  explicit Init_MoveTcpAlongAxis_Goal_speed_in_mm_per_s(::action_interfaces::action::MoveTcpAlongAxis_Goal & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_Goal speed_in_mm_per_s(::action_interfaces::action::MoveTcpAlongAxis_Goal::_speed_in_mm_per_s_type arg)
  {
    msg_.speed_in_mm_per_s = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_Goal msg_;
};

class Init_MoveTcpAlongAxis_Goal_movement_axis
{
public:
  explicit Init_MoveTcpAlongAxis_Goal_movement_axis(::action_interfaces::action::MoveTcpAlongAxis_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveTcpAlongAxis_Goal_speed_in_mm_per_s movement_axis(::action_interfaces::action::MoveTcpAlongAxis_Goal::_movement_axis_type arg)
  {
    msg_.movement_axis = std::move(arg);
    return Init_MoveTcpAlongAxis_Goal_speed_in_mm_per_s(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_Goal msg_;
};

class Init_MoveTcpAlongAxis_Goal_movement_frame
{
public:
  explicit Init_MoveTcpAlongAxis_Goal_movement_frame(::action_interfaces::action::MoveTcpAlongAxis_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveTcpAlongAxis_Goal_movement_axis movement_frame(::action_interfaces::action::MoveTcpAlongAxis_Goal::_movement_frame_type arg)
  {
    msg_.movement_frame = std::move(arg);
    return Init_MoveTcpAlongAxis_Goal_movement_axis(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_Goal msg_;
};

class Init_MoveTcpAlongAxis_Goal_baseline
{
public:
  Init_MoveTcpAlongAxis_Goal_baseline()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTcpAlongAxis_Goal_movement_frame baseline(::action_interfaces::action::MoveTcpAlongAxis_Goal::_baseline_type arg)
  {
    msg_.baseline = std::move(arg);
    return Init_MoveTcpAlongAxis_Goal_movement_frame(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_Goal>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_Goal_baseline();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_Result_success
{
public:
  Init_MoveTcpAlongAxis_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_Result success(::action_interfaces::action::MoveTcpAlongAxis_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_Result>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_Result_success();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_Feedback_currently_moving
{
public:
  Init_MoveTcpAlongAxis_Feedback_currently_moving()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_Feedback currently_moving(::action_interfaces::action::MoveTcpAlongAxis_Feedback::_currently_moving_type arg)
  {
    msg_.currently_moving = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_Feedback>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_Feedback_currently_moving();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_SendGoal_Request_goal
{
public:
  explicit Init_MoveTcpAlongAxis_SendGoal_Request_goal(::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request goal(::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request msg_;
};

class Init_MoveTcpAlongAxis_SendGoal_Request_goal_id
{
public:
  Init_MoveTcpAlongAxis_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTcpAlongAxis_SendGoal_Request_goal goal_id(::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveTcpAlongAxis_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_SendGoal_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_SendGoal_Response_stamp
{
public:
  explicit Init_MoveTcpAlongAxis_SendGoal_Response_stamp(::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response stamp(::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response msg_;
};

class Init_MoveTcpAlongAxis_SendGoal_Response_accepted
{
public:
  Init_MoveTcpAlongAxis_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTcpAlongAxis_SendGoal_Response_stamp accepted(::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveTcpAlongAxis_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_SendGoal_Response_accepted();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_GetResult_Request_goal_id
{
public:
  Init_MoveTcpAlongAxis_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_GetResult_Request goal_id(::action_interfaces::action::MoveTcpAlongAxis_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_GetResult_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_GetResult_Response_result
{
public:
  explicit Init_MoveTcpAlongAxis_GetResult_Response_result(::action_interfaces::action::MoveTcpAlongAxis_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_GetResult_Response result(::action_interfaces::action::MoveTcpAlongAxis_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_GetResult_Response msg_;
};

class Init_MoveTcpAlongAxis_GetResult_Response_status
{
public:
  Init_MoveTcpAlongAxis_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTcpAlongAxis_GetResult_Response_result status(::action_interfaces::action::MoveTcpAlongAxis_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveTcpAlongAxis_GetResult_Response_result(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_GetResult_Response_status();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTcpAlongAxis_FeedbackMessage_feedback
{
public:
  explicit Init_MoveTcpAlongAxis_FeedbackMessage_feedback(::action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage feedback(::action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage msg_;
};

class Init_MoveTcpAlongAxis_FeedbackMessage_goal_id
{
public:
  Init_MoveTcpAlongAxis_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTcpAlongAxis_FeedbackMessage_feedback goal_id(::action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveTcpAlongAxis_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage>()
{
  return action_interfaces::action::builder::Init_MoveTcpAlongAxis_FeedbackMessage_goal_id();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_
