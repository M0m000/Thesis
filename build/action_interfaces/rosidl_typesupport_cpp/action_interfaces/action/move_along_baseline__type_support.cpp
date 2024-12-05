// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from action_interfaces:action/MoveAlongBaseline.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_Goal_type_support_ids_t;

static const _MoveAlongBaseline_Goal_type_support_ids_t _MoveAlongBaseline_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_Goal_type_support_symbol_names_t _MoveAlongBaseline_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_Goal)),
  }
};

typedef struct _MoveAlongBaseline_Goal_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_Goal_type_support_data_t;

static _MoveAlongBaseline_Goal_type_support_data_t _MoveAlongBaseline_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_Goal_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_Goal>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_Goal)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_Result_type_support_ids_t;

static const _MoveAlongBaseline_Result_type_support_ids_t _MoveAlongBaseline_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_Result_type_support_symbol_names_t _MoveAlongBaseline_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_Result)),
  }
};

typedef struct _MoveAlongBaseline_Result_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_Result_type_support_data_t;

static _MoveAlongBaseline_Result_type_support_data_t _MoveAlongBaseline_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_Result_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_Result_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_Result_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_Result>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_Result)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_Feedback_type_support_ids_t;

static const _MoveAlongBaseline_Feedback_type_support_ids_t _MoveAlongBaseline_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_Feedback_type_support_symbol_names_t _MoveAlongBaseline_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_Feedback)),
  }
};

typedef struct _MoveAlongBaseline_Feedback_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_Feedback_type_support_data_t;

static _MoveAlongBaseline_Feedback_type_support_data_t _MoveAlongBaseline_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_Feedback_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_Feedback>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_Feedback)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_SendGoal_Request_type_support_ids_t;

static const _MoveAlongBaseline_SendGoal_Request_type_support_ids_t _MoveAlongBaseline_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_SendGoal_Request_type_support_symbol_names_t _MoveAlongBaseline_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal_Request)),
  }
};

typedef struct _MoveAlongBaseline_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_SendGoal_Request_type_support_data_t;

static _MoveAlongBaseline_SendGoal_Request_type_support_data_t _MoveAlongBaseline_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_SendGoal_Request_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_SendGoal_Request>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal_Request)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_SendGoal_Response_type_support_ids_t;

static const _MoveAlongBaseline_SendGoal_Response_type_support_ids_t _MoveAlongBaseline_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_SendGoal_Response_type_support_symbol_names_t _MoveAlongBaseline_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal_Response)),
  }
};

typedef struct _MoveAlongBaseline_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_SendGoal_Response_type_support_data_t;

static _MoveAlongBaseline_SendGoal_Response_type_support_data_t _MoveAlongBaseline_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_SendGoal_Response_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_SendGoal_Response>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal_Response)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_SendGoal_type_support_ids_t;

static const _MoveAlongBaseline_SendGoal_type_support_ids_t _MoveAlongBaseline_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_SendGoal_type_support_symbol_names_t _MoveAlongBaseline_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal)),
  }
};

typedef struct _MoveAlongBaseline_SendGoal_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_SendGoal_type_support_data_t;

static _MoveAlongBaseline_SendGoal_type_support_data_t _MoveAlongBaseline_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_SendGoal_service_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveAlongBaseline_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<action_interfaces::action::MoveAlongBaseline_SendGoal>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<action_interfaces::action::MoveAlongBaseline_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_GetResult_Request_type_support_ids_t;

static const _MoveAlongBaseline_GetResult_Request_type_support_ids_t _MoveAlongBaseline_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_GetResult_Request_type_support_symbol_names_t _MoveAlongBaseline_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_GetResult_Request)),
  }
};

typedef struct _MoveAlongBaseline_GetResult_Request_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_GetResult_Request_type_support_data_t;

static _MoveAlongBaseline_GetResult_Request_type_support_data_t _MoveAlongBaseline_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_GetResult_Request_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_GetResult_Request>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_GetResult_Request)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_GetResult_Response_type_support_ids_t;

static const _MoveAlongBaseline_GetResult_Response_type_support_ids_t _MoveAlongBaseline_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_GetResult_Response_type_support_symbol_names_t _MoveAlongBaseline_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_GetResult_Response)),
  }
};

typedef struct _MoveAlongBaseline_GetResult_Response_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_GetResult_Response_type_support_data_t;

static _MoveAlongBaseline_GetResult_Response_type_support_data_t _MoveAlongBaseline_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_GetResult_Response_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_GetResult_Response>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_GetResult_Response)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_GetResult_type_support_ids_t;

static const _MoveAlongBaseline_GetResult_type_support_ids_t _MoveAlongBaseline_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_GetResult_type_support_symbol_names_t _MoveAlongBaseline_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_GetResult)),
  }
};

typedef struct _MoveAlongBaseline_GetResult_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_GetResult_type_support_data_t;

static _MoveAlongBaseline_GetResult_type_support_data_t _MoveAlongBaseline_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_GetResult_service_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveAlongBaseline_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<action_interfaces::action::MoveAlongBaseline_GetResult>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<action_interfaces::action::MoveAlongBaseline_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveAlongBaseline_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAlongBaseline_FeedbackMessage_type_support_ids_t;

static const _MoveAlongBaseline_FeedbackMessage_type_support_ids_t _MoveAlongBaseline_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveAlongBaseline_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAlongBaseline_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAlongBaseline_FeedbackMessage_type_support_symbol_names_t _MoveAlongBaseline_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interfaces, action, MoveAlongBaseline_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interfaces, action, MoveAlongBaseline_FeedbackMessage)),
  }
};

typedef struct _MoveAlongBaseline_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _MoveAlongBaseline_FeedbackMessage_type_support_data_t;

static _MoveAlongBaseline_FeedbackMessage_type_support_data_t _MoveAlongBaseline_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAlongBaseline_FeedbackMessage_message_typesupport_map = {
  2,
  "action_interfaces",
  &_MoveAlongBaseline_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAlongBaseline_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAlongBaseline_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAlongBaseline_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAlongBaseline_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_FeedbackMessage>()
{
  return &::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline_FeedbackMessage)() {
  return get_message_type_support_handle<action_interfaces::action::MoveAlongBaseline_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "action_interfaces/action/detail/move_along_baseline__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace action_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t MoveAlongBaseline_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<action_interfaces::action::MoveAlongBaseline>()
{
  using ::action_interfaces::action::rosidl_typesupport_cpp::MoveAlongBaseline_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  MoveAlongBaseline_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::action_interfaces::action::MoveAlongBaseline::Impl::SendGoalService>();
  MoveAlongBaseline_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::action_interfaces::action::MoveAlongBaseline::Impl::GetResultService>();
  MoveAlongBaseline_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::action_interfaces::action::MoveAlongBaseline::Impl::CancelGoalService>();
  MoveAlongBaseline_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::action_interfaces::action::MoveAlongBaseline::Impl::FeedbackMessage>();
  MoveAlongBaseline_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::action_interfaces::action::MoveAlongBaseline::Impl::GoalStatusMessage>();
  return &MoveAlongBaseline_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, action_interfaces, action, MoveAlongBaseline)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<action_interfaces::action::MoveAlongBaseline>();
}

#ifdef __cplusplus
}
#endif
