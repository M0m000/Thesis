// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:action/MoveTcpAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__TRAITS_HPP_
#define ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__TRAITS_HPP_

#include "action_interfaces/action/detail/move_tcp_along_axis__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_Goal>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_Goal";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_Goal>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_Goal";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_Result>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_Result";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_Result>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_Result";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_Feedback>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_Feedback";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_Feedback>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_Feedback";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "action_interfaces/action/detail/move_tcp_along_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_SendGoal_Request";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_SendGoal_Response";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_SendGoal>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_SendGoal";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_SendGoal>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_SendGoal";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>::value &&
    has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>::value &&
    has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<action_interfaces::action::MoveTcpAlongAxis_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interfaces::action::MoveTcpAlongAxis_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_GetResult_Request";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_GetResult_Request";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_GetResult_Response";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_GetResult_Response";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_Result>::value> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_Result>::value> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_GetResult>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_GetResult";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_GetResult>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_GetResult";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>::value &&
    has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>::value &&
    has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>::value
  >
{
};

template<>
struct is_service<action_interfaces::action::MoveTcpAlongAxis_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<action_interfaces::action::MoveTcpAlongAxis_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interfaces::action::MoveTcpAlongAxis_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "action_interfaces/action/detail/move_tcp_along_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage>()
{
  return "action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage";
}

template<>
inline const char * name<action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage>()
{
  return "action_interfaces/action/MoveTcpAlongAxis_FeedbackMessage";
}

template<>
struct has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<action_interfaces::action::MoveTcpAlongAxis_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<action_interfaces::action::MoveTcpAlongAxis_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interfaces::action::MoveTcpAlongAxis_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<action_interfaces::action::MoveTcpAlongAxis>
  : std::true_type
{
};

template<>
struct is_action_goal<action_interfaces::action::MoveTcpAlongAxis_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<action_interfaces::action::MoveTcpAlongAxis_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<action_interfaces::action::MoveTcpAlongAxis_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ACTION_INTERFACES__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__TRAITS_HPP_
