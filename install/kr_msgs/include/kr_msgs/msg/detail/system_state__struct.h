// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_
#define KR_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_mode'
#include "kr_msgs/msg/detail/robot_mode__struct.h"
// Member 'robot_state'
#include "kr_msgs/msg/detail/robot_state__struct.h"
// Member 'iob_quadratures'
#include "kr_msgs/msg/detail/quadrature__struct.h"

// Struct defined in msg/SystemState in the package kr_msgs.
typedef struct kr_msgs__msg__SystemState
{
  kr_msgs__msg__RobotMode robot_mode;
  kr_msgs__msg__RobotState robot_state;
  double sensed_pos[7];
  double sensed_vel[7];
  double sensed_trq[7];
  double target_pos[7];
  double target_vel[7];
  double target_trq[7];
  double pos[3];
  double rot[3];
  int8_t iob_digital_out[8];
  int8_t iob_relays[4];
  float iob_current_out[2];
  float iob_voltage_out[2];
  int8_t iob_digital_in[16];
  int8_t iob_safe_in[4];
  float iob_current_in[2];
  float iob_voltage_in[2];
  kr_msgs__msg__Quadrature iob_quadratures[2];
  int8_t tio_digital_out[4];
  int8_t tio_power_supply[3];
  float tio_analog_out[2];
  float tio_current_in[1];
  float tio_voltage_in[4];
  bool e_stop;
  bool p_stop;
  bool toggle;
  bool backdrive;
} kr_msgs__msg__SystemState;

// Struct for a sequence of kr_msgs__msg__SystemState.
typedef struct kr_msgs__msg__SystemState__Sequence
{
  kr_msgs__msg__SystemState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__msg__SystemState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_
