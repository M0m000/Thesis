// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kr_msgs:action/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__TRAITS_HPP_
#define KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__TRAITS_HPP_

#include "kr_msgs/action/detail/move_tcp_along_axis__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_Goal>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_Goal";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_Goal>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_Goal";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_Result>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_Result";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_Result>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_Result";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_Feedback>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_Feedback";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_Feedback>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_Feedback";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "kr_msgs/action/detail/move_tcp_along_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_SendGoal_Request";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_SendGoal_Response";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_SendGoal>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_SendGoal";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_SendGoal>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_SendGoal";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>::value &&
    has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>::value &&
    has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<kr_msgs::action::MoveTCPAlongAxis_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kr_msgs::action::MoveTCPAlongAxis_SendGoal_Response>
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
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_GetResult_Request";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_GetResult_Request";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_GetResult_Response";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_GetResult_Response";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_Result>::value> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_Result>::value> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_GetResult>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_GetResult";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_GetResult>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_GetResult";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>::value &&
    has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>::value &&
    has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>::value
  >
{
};

template<>
struct is_service<kr_msgs::action::MoveTCPAlongAxis_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<kr_msgs::action::MoveTCPAlongAxis_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kr_msgs::action::MoveTCPAlongAxis_GetResult_Response>
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
// #include "kr_msgs/action/detail/move_tcp_along_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage>()
{
  return "kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage";
}

template<>
inline const char * name<kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage>()
{
  return "kr_msgs/action/MoveTCPAlongAxis_FeedbackMessage";
}

template<>
struct has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<kr_msgs::action::MoveTCPAlongAxis_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<kr_msgs::action::MoveTCPAlongAxis_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<kr_msgs::action::MoveTCPAlongAxis_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<kr_msgs::action::MoveTCPAlongAxis>
  : std::true_type
{
};

template<>
struct is_action_goal<kr_msgs::action::MoveTCPAlongAxis_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<kr_msgs::action::MoveTCPAlongAxis_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<kr_msgs::action::MoveTCPAlongAxis_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__TRAITS_HPP_
