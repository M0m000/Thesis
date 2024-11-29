// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/system_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_mode`
#include "kr_msgs/msg/detail/robot_mode__functions.h"
// Member `robot_state`
#include "kr_msgs/msg/detail/robot_state__functions.h"
// Member `iob_quadratures`
#include "kr_msgs/msg/detail/quadrature__functions.h"

bool
kr_msgs__msg__SystemState__init(kr_msgs__msg__SystemState * msg)
{
  if (!msg) {
    return false;
  }
  // robot_mode
  if (!kr_msgs__msg__RobotMode__init(&msg->robot_mode)) {
    kr_msgs__msg__SystemState__fini(msg);
    return false;
  }
  // robot_state
  if (!kr_msgs__msg__RobotState__init(&msg->robot_state)) {
    kr_msgs__msg__SystemState__fini(msg);
    return false;
  }
  // sensed_pos
  // sensed_vel
  // sensed_trq
  // target_pos
  // target_vel
  // target_trq
  // pos
  // rot
  // iob_digital_out
  // iob_relays
  // iob_current_out
  // iob_voltage_out
  // iob_digital_in
  // iob_safe_in
  // iob_current_in
  // iob_voltage_in
  // iob_quadratures
  for (size_t i = 0; i < 2; ++i) {
    if (!kr_msgs__msg__Quadrature__init(&msg->iob_quadratures[i])) {
      kr_msgs__msg__SystemState__fini(msg);
      return false;
    }
  }
  // tio_digital_out
  // tio_power_supply
  // tio_analog_out
  // tio_current_in
  // tio_voltage_in
  // e_stop
  // p_stop
  // toggle
  // backdrive
  return true;
}

void
kr_msgs__msg__SystemState__fini(kr_msgs__msg__SystemState * msg)
{
  if (!msg) {
    return;
  }
  // robot_mode
  kr_msgs__msg__RobotMode__fini(&msg->robot_mode);
  // robot_state
  kr_msgs__msg__RobotState__fini(&msg->robot_state);
  // sensed_pos
  // sensed_vel
  // sensed_trq
  // target_pos
  // target_vel
  // target_trq
  // pos
  // rot
  // iob_digital_out
  // iob_relays
  // iob_current_out
  // iob_voltage_out
  // iob_digital_in
  // iob_safe_in
  // iob_current_in
  // iob_voltage_in
  // iob_quadratures
  for (size_t i = 0; i < 2; ++i) {
    kr_msgs__msg__Quadrature__fini(&msg->iob_quadratures[i]);
  }
  // tio_digital_out
  // tio_power_supply
  // tio_analog_out
  // tio_current_in
  // tio_voltage_in
  // e_stop
  // p_stop
  // toggle
  // backdrive
}

bool
kr_msgs__msg__SystemState__are_equal(const kr_msgs__msg__SystemState * lhs, const kr_msgs__msg__SystemState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_mode
  if (!kr_msgs__msg__RobotMode__are_equal(
      &(lhs->robot_mode), &(rhs->robot_mode)))
  {
    return false;
  }
  // robot_state
  if (!kr_msgs__msg__RobotState__are_equal(
      &(lhs->robot_state), &(rhs->robot_state)))
  {
    return false;
  }
  // sensed_pos
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->sensed_pos[i] != rhs->sensed_pos[i]) {
      return false;
    }
  }
  // sensed_vel
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->sensed_vel[i] != rhs->sensed_vel[i]) {
      return false;
    }
  }
  // sensed_trq
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->sensed_trq[i] != rhs->sensed_trq[i]) {
      return false;
    }
  }
  // target_pos
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->target_pos[i] != rhs->target_pos[i]) {
      return false;
    }
  }
  // target_vel
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->target_vel[i] != rhs->target_vel[i]) {
      return false;
    }
  }
  // target_trq
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->target_trq[i] != rhs->target_trq[i]) {
      return false;
    }
  }
  // pos
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->pos[i] != rhs->pos[i]) {
      return false;
    }
  }
  // rot
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->rot[i] != rhs->rot[i]) {
      return false;
    }
  }
  // iob_digital_out
  for (size_t i = 0; i < 8; ++i) {
    if (lhs->iob_digital_out[i] != rhs->iob_digital_out[i]) {
      return false;
    }
  }
  // iob_relays
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->iob_relays[i] != rhs->iob_relays[i]) {
      return false;
    }
  }
  // iob_current_out
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->iob_current_out[i] != rhs->iob_current_out[i]) {
      return false;
    }
  }
  // iob_voltage_out
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->iob_voltage_out[i] != rhs->iob_voltage_out[i]) {
      return false;
    }
  }
  // iob_digital_in
  for (size_t i = 0; i < 16; ++i) {
    if (lhs->iob_digital_in[i] != rhs->iob_digital_in[i]) {
      return false;
    }
  }
  // iob_safe_in
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->iob_safe_in[i] != rhs->iob_safe_in[i]) {
      return false;
    }
  }
  // iob_current_in
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->iob_current_in[i] != rhs->iob_current_in[i]) {
      return false;
    }
  }
  // iob_voltage_in
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->iob_voltage_in[i] != rhs->iob_voltage_in[i]) {
      return false;
    }
  }
  // iob_quadratures
  for (size_t i = 0; i < 2; ++i) {
    if (!kr_msgs__msg__Quadrature__are_equal(
        &(lhs->iob_quadratures[i]), &(rhs->iob_quadratures[i])))
    {
      return false;
    }
  }
  // tio_digital_out
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->tio_digital_out[i] != rhs->tio_digital_out[i]) {
      return false;
    }
  }
  // tio_power_supply
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->tio_power_supply[i] != rhs->tio_power_supply[i]) {
      return false;
    }
  }
  // tio_analog_out
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->tio_analog_out[i] != rhs->tio_analog_out[i]) {
      return false;
    }
  }
  // tio_current_in
  for (size_t i = 0; i < 1; ++i) {
    if (lhs->tio_current_in[i] != rhs->tio_current_in[i]) {
      return false;
    }
  }
  // tio_voltage_in
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->tio_voltage_in[i] != rhs->tio_voltage_in[i]) {
      return false;
    }
  }
  // e_stop
  if (lhs->e_stop != rhs->e_stop) {
    return false;
  }
  // p_stop
  if (lhs->p_stop != rhs->p_stop) {
    return false;
  }
  // toggle
  if (lhs->toggle != rhs->toggle) {
    return false;
  }
  // backdrive
  if (lhs->backdrive != rhs->backdrive) {
    return false;
  }
  return true;
}

bool
kr_msgs__msg__SystemState__copy(
  const kr_msgs__msg__SystemState * input,
  kr_msgs__msg__SystemState * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_mode
  if (!kr_msgs__msg__RobotMode__copy(
      &(input->robot_mode), &(output->robot_mode)))
  {
    return false;
  }
  // robot_state
  if (!kr_msgs__msg__RobotState__copy(
      &(input->robot_state), &(output->robot_state)))
  {
    return false;
  }
  // sensed_pos
  for (size_t i = 0; i < 7; ++i) {
    output->sensed_pos[i] = input->sensed_pos[i];
  }
  // sensed_vel
  for (size_t i = 0; i < 7; ++i) {
    output->sensed_vel[i] = input->sensed_vel[i];
  }
  // sensed_trq
  for (size_t i = 0; i < 7; ++i) {
    output->sensed_trq[i] = input->sensed_trq[i];
  }
  // target_pos
  for (size_t i = 0; i < 7; ++i) {
    output->target_pos[i] = input->target_pos[i];
  }
  // target_vel
  for (size_t i = 0; i < 7; ++i) {
    output->target_vel[i] = input->target_vel[i];
  }
  // target_trq
  for (size_t i = 0; i < 7; ++i) {
    output->target_trq[i] = input->target_trq[i];
  }
  // pos
  for (size_t i = 0; i < 3; ++i) {
    output->pos[i] = input->pos[i];
  }
  // rot
  for (size_t i = 0; i < 3; ++i) {
    output->rot[i] = input->rot[i];
  }
  // iob_digital_out
  for (size_t i = 0; i < 8; ++i) {
    output->iob_digital_out[i] = input->iob_digital_out[i];
  }
  // iob_relays
  for (size_t i = 0; i < 4; ++i) {
    output->iob_relays[i] = input->iob_relays[i];
  }
  // iob_current_out
  for (size_t i = 0; i < 2; ++i) {
    output->iob_current_out[i] = input->iob_current_out[i];
  }
  // iob_voltage_out
  for (size_t i = 0; i < 2; ++i) {
    output->iob_voltage_out[i] = input->iob_voltage_out[i];
  }
  // iob_digital_in
  for (size_t i = 0; i < 16; ++i) {
    output->iob_digital_in[i] = input->iob_digital_in[i];
  }
  // iob_safe_in
  for (size_t i = 0; i < 4; ++i) {
    output->iob_safe_in[i] = input->iob_safe_in[i];
  }
  // iob_current_in
  for (size_t i = 0; i < 2; ++i) {
    output->iob_current_in[i] = input->iob_current_in[i];
  }
  // iob_voltage_in
  for (size_t i = 0; i < 2; ++i) {
    output->iob_voltage_in[i] = input->iob_voltage_in[i];
  }
  // iob_quadratures
  for (size_t i = 0; i < 2; ++i) {
    if (!kr_msgs__msg__Quadrature__copy(
        &(input->iob_quadratures[i]), &(output->iob_quadratures[i])))
    {
      return false;
    }
  }
  // tio_digital_out
  for (size_t i = 0; i < 4; ++i) {
    output->tio_digital_out[i] = input->tio_digital_out[i];
  }
  // tio_power_supply
  for (size_t i = 0; i < 3; ++i) {
    output->tio_power_supply[i] = input->tio_power_supply[i];
  }
  // tio_analog_out
  for (size_t i = 0; i < 2; ++i) {
    output->tio_analog_out[i] = input->tio_analog_out[i];
  }
  // tio_current_in
  for (size_t i = 0; i < 1; ++i) {
    output->tio_current_in[i] = input->tio_current_in[i];
  }
  // tio_voltage_in
  for (size_t i = 0; i < 4; ++i) {
    output->tio_voltage_in[i] = input->tio_voltage_in[i];
  }
  // e_stop
  output->e_stop = input->e_stop;
  // p_stop
  output->p_stop = input->p_stop;
  // toggle
  output->toggle = input->toggle;
  // backdrive
  output->backdrive = input->backdrive;
  return true;
}

kr_msgs__msg__SystemState *
kr_msgs__msg__SystemState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SystemState * msg = (kr_msgs__msg__SystemState *)allocator.allocate(sizeof(kr_msgs__msg__SystemState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__msg__SystemState));
  bool success = kr_msgs__msg__SystemState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__msg__SystemState__destroy(kr_msgs__msg__SystemState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__msg__SystemState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__msg__SystemState__Sequence__init(kr_msgs__msg__SystemState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SystemState * data = NULL;

  if (size) {
    data = (kr_msgs__msg__SystemState *)allocator.zero_allocate(size, sizeof(kr_msgs__msg__SystemState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__msg__SystemState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__msg__SystemState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
kr_msgs__msg__SystemState__Sequence__fini(kr_msgs__msg__SystemState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      kr_msgs__msg__SystemState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

kr_msgs__msg__SystemState__Sequence *
kr_msgs__msg__SystemState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SystemState__Sequence * array = (kr_msgs__msg__SystemState__Sequence *)allocator.allocate(sizeof(kr_msgs__msg__SystemState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__msg__SystemState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__msg__SystemState__Sequence__destroy(kr_msgs__msg__SystemState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__msg__SystemState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__msg__SystemState__Sequence__are_equal(const kr_msgs__msg__SystemState__Sequence * lhs, const kr_msgs__msg__SystemState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__msg__SystemState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__SystemState__Sequence__copy(
  const kr_msgs__msg__SystemState__Sequence * input,
  kr_msgs__msg__SystemState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__msg__SystemState);
    kr_msgs__msg__SystemState * data =
      (kr_msgs__msg__SystemState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__msg__SystemState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__msg__SystemState__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kr_msgs__msg__SystemState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
