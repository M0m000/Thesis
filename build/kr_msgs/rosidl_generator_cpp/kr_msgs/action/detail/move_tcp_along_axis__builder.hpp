// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kr_msgs:action/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_
#define KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_

#include "kr_msgs/action/detail/move_tcp_along_axis__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_Goal_movement_axis
{
public:
  explicit Init_MoveTCPAlongAxis_Goal_movement_axis(::kr_msgs::action::MoveTCPAlongAxis_Goal & msg)
  : msg_(msg)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_Goal movement_axis(::kr_msgs::action::MoveTCPAlongAxis_Goal::_movement_axis_type arg)
  {
    msg_.movement_axis = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_Goal msg_;
};

class Init_MoveTCPAlongAxis_Goal_movement_frame
{
public:
  explicit Init_MoveTCPAlongAxis_Goal_movement_frame(::kr_msgs::action::MoveTCPAlongAxis_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveTCPAlongAxis_Goal_movement_axis movement_frame(::kr_msgs::action::MoveTCPAlongAxis_Goal::_movement_frame_type arg)
  {
    msg_.movement_frame = std::move(arg);
    return Init_MoveTCPAlongAxis_Goal_movement_axis(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_Goal msg_;
};

class Init_MoveTCPAlongAxis_Goal_baseline
{
public:
  Init_MoveTCPAlongAxis_Goal_baseline()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTCPAlongAxis_Goal_movement_frame baseline(::kr_msgs::action::MoveTCPAlongAxis_Goal::_baseline_type arg)
  {
    msg_.baseline = std::move(arg);
    return Init_MoveTCPAlongAxis_Goal_movement_frame(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_Goal>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_Goal_baseline();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_Result_current_time
{
public:
  Init_MoveTCPAlongAxis_Result_current_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_Result current_time(::kr_msgs::action::MoveTCPAlongAxis_Result::_current_time_type arg)
  {
    msg_.current_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_Result>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_Result_current_time();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_Feedback_success
{
public:
  Init_MoveTCPAlongAxis_Feedback_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_Feedback success(::kr_msgs::action::MoveTCPAlongAxis_Feedback::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_Feedback>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_Feedback_success();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_SendGoal_Request_goal
{
public:
  explicit Init_MoveTCPAlongAxis_SendGoal_Request_goal(::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request goal(::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request msg_;
};

class Init_MoveTCPAlongAxis_SendGoal_Request_goal_id
{
public:
  Init_MoveTCPAlongAxis_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTCPAlongAxis_SendGoal_Request_goal goal_id(::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveTCPAlongAxis_SendGoal_Request_goal(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_SendGoal_Request_goal_id();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_SendGoal_Response_stamp
{
public:
  explicit Init_MoveTCPAlongAxis_SendGoal_Response_stamp(::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response stamp(::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response msg_;
};

class Init_MoveTCPAlongAxis_SendGoal_Response_accepted
{
public:
  Init_MoveTCPAlongAxis_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTCPAlongAxis_SendGoal_Response_stamp accepted(::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveTCPAlongAxis_SendGoal_Response_stamp(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_SendGoal_Response_accepted();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_GetResult_Request_goal_id
{
public:
  Init_MoveTCPAlongAxis_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_GetResult_Request goal_id(::kr_msgs::action::MoveTCPAlongAxis_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_GetResult_Request_goal_id();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_GetResult_Response_result
{
public:
  explicit Init_MoveTCPAlongAxis_GetResult_Response_result(::kr_msgs::action::MoveTCPAlongAxis_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_GetResult_Response result(::kr_msgs::action::MoveTCPAlongAxis_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_GetResult_Response msg_;
};

class Init_MoveTCPAlongAxis_GetResult_Response_status
{
public:
  Init_MoveTCPAlongAxis_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTCPAlongAxis_GetResult_Response_result status(::kr_msgs::action::MoveTCPAlongAxis_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveTCPAlongAxis_GetResult_Response_result(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_GetResult_Response_status();
}

}  // namespace kr_msgs


namespace kr_msgs
{

namespace action
{

namespace builder
{

class Init_MoveTCPAlongAxis_FeedbackMessage_feedback
{
public:
  explicit Init_MoveTCPAlongAxis_FeedbackMessage_feedback(::kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage feedback(::kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage msg_;
};

class Init_MoveTCPAlongAxis_FeedbackMessage_goal_id
{
public:
  Init_MoveTCPAlongAxis_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTCPAlongAxis_FeedbackMessage_feedback goal_id(::kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveTCPAlongAxis_FeedbackMessage_feedback(msg_);
  }

private:
  ::kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage>()
{
  return kr_msgs::action::builder::Init_MoveTCPAlongAxis_FeedbackMessage_goal_id();
}

}  // namespace kr_msgs

#endif  // KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__BUILDER_HPP_
