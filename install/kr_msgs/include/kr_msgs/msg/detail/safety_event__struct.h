// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/SafetyEvent.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SAFETY_EVENT__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__SAFETY_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TYPE_ESTOP'.
enum
{
  kr_msgs__msg__SafetyEvent__TYPE_ESTOP = 1
};

/// Constant 'TYPE_PSTOP'.
enum
{
  kr_msgs__msg__SafetyEvent__TYPE_PSTOP = 2
};

/// Constant 'TYPE_SSTOP'.
enum
{
  kr_msgs__msg__SafetyEvent__TYPE_SSTOP = 3
};

/// Constant 'CODE_EXT_E_STOP_ACTIVATED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_EXT_E_STOP_ACTIVATED = 1l
};

/// Constant 'CODE_EXT_P_STOP_ACTIVATED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_EXT_P_STOP_ACTIVATED = 2l
};

/// Constant 'CODE_IOB_NOT_RESPONDING'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_IOB_NOT_RESPONDING = 3l
};

/// Constant 'CODE_JBS_NOT_RESPONDING'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_JBS_NOT_RESPONDING = 4l
};

/// Constant 'CODE_J_RATED_X_SENSOR_POS_SPAN'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_RATED_X_SENSOR_POS_SPAN = 5l
};

/// Constant 'CODE_J_RATED_POS_DELTA_SPAN'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_RATED_POS_DELTA_SPAN = 6l
};

/// Constant 'CODE_J_RATED_SPEED_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_RATED_SPEED_EXCEEDED = 7l
};

/// Constant 'CODE_J_RATED_TORQUE_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_RATED_TORQUE_EXCEEDED = 8l
};

/// Constant 'CODE_J_RATED_STATIC_TORQUE_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_RATED_STATIC_TORQUE_EXCEEDED = 9l
};

/// Constant 'CODE_J_RATED_TEMPERATURE_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_RATED_TEMPERATURE_EXCEEDED = 10l
};

/// Constant 'CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED = 11l
};

/// Constant 'CODE_MODEL_JS_SPAN_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_MODEL_JS_SPAN_EXCEEDED = 12l
};

/// Constant 'CODE_MODEL_WS_SPAN_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_MODEL_WS_SPAN_EXCEEDED = 13l
};

/// Constant 'CODE_MODEL_FRAME_SPEED_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_MODEL_FRAME_SPEED_EXCEEDED = 14l
};

/// Constant 'CODE_TRQ_MODE_JSPEED_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_TRQ_MODE_JSPEED_EXCEEDED = 15l
};

/// Constant 'CODE_INVALID_MODEL_STATE'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_INVALID_MODEL_STATE = 21l
};

/// Constant 'CODE_J_MODEL_VELOCITY_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_MODEL_VELOCITY_EXCEEDED = 22l
};

/// Constant 'CODE_J_MODEL_TORQUE_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_MODEL_TORQUE_EXCEEDED = 23l
};

/// Constant 'CODE_J_MODEL_STATIC_TORQUE_EXCEEDED'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_MODEL_STATIC_TORQUE_EXCEEDED = 24l
};

/// Constant 'CODE_J_MODEL_LIMIT_ESTIMATION'.
enum
{
  kr_msgs__msg__SafetyEvent__CODE_J_MODEL_LIMIT_ESTIMATION = 25l
};

// Struct defined in msg/SafetyEvent in the package kr_msgs.
typedef struct kr_msgs__msg__SafetyEvent
{
  int8_t type;
  int32_t code;
  uint32_t timestamp;
} kr_msgs__msg__SafetyEvent;

// Struct for a sequence of kr_msgs__msg__SafetyEvent.
typedef struct kr_msgs__msg__SafetyEvent__Sequence
{
  kr_msgs__msg__SafetyEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__SafetyEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__SAFETY_EVENT__STRUCT_H_
