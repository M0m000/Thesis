// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:action/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice
#include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `movement_frame`
// Member `movement_axis`
#include "rosidl_runtime_c/string_functions.h"

bool
kr_msgs__action__MoveTCPAlongAxis_Goal__init(kr_msgs__action__MoveTCPAlongAxis_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // baseline
  // movement_frame
  if (!rosidl_runtime_c__String__init(&msg->movement_frame)) {
    kr_msgs__action__MoveTCPAlongAxis_Goal__fini(msg);
    return false;
  }
  // movement_axis
  if (!rosidl_runtime_c__String__init(&msg->movement_axis)) {
    kr_msgs__action__MoveTCPAlongAxis_Goal__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_Goal__fini(kr_msgs__action__MoveTCPAlongAxis_Goal * msg)
{
  if (!msg) {
    return;
  }
  // baseline
  // movement_frame
  rosidl_runtime_c__String__fini(&msg->movement_frame);
  // movement_axis
  rosidl_runtime_c__String__fini(&msg->movement_axis);
}

bool
kr_msgs__action__MoveTCPAlongAxis_Goal__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Goal * lhs, const kr_msgs__action__MoveTCPAlongAxis_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // baseline
  if (lhs->baseline != rhs->baseline) {
    return false;
  }
  // movement_frame
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->movement_frame), &(rhs->movement_frame)))
  {
    return false;
  }
  // movement_axis
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->movement_axis), &(rhs->movement_axis)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_Goal__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Goal * input,
  kr_msgs__action__MoveTCPAlongAxis_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // baseline
  output->baseline = input->baseline;
  // movement_frame
  if (!rosidl_runtime_c__String__copy(
      &(input->movement_frame), &(output->movement_frame)))
  {
    return false;
  }
  // movement_axis
  if (!rosidl_runtime_c__String__copy(
      &(input->movement_axis), &(output->movement_axis)))
  {
    return false;
  }
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_Goal *
kr_msgs__action__MoveTCPAlongAxis_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Goal * msg = (kr_msgs__action__MoveTCPAlongAxis_Goal *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_Goal));
  bool success = kr_msgs__action__MoveTCPAlongAxis_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_Goal__destroy(kr_msgs__action__MoveTCPAlongAxis_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Goal * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_Goal *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_Goal__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_Goal__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence *
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_Goal);
    kr_msgs__action__MoveTCPAlongAxis_Goal * data =
      (kr_msgs__action__MoveTCPAlongAxis_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_Goal__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
kr_msgs__action__MoveTCPAlongAxis_Result__init(kr_msgs__action__MoveTCPAlongAxis_Result * msg)
{
  if (!msg) {
    return false;
  }
  // current_time
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_Result__fini(kr_msgs__action__MoveTCPAlongAxis_Result * msg)
{
  if (!msg) {
    return;
  }
  // current_time
}

bool
kr_msgs__action__MoveTCPAlongAxis_Result__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Result * lhs, const kr_msgs__action__MoveTCPAlongAxis_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_time
  if (lhs->current_time != rhs->current_time) {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_Result__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Result * input,
  kr_msgs__action__MoveTCPAlongAxis_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // current_time
  output->current_time = input->current_time;
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_Result *
kr_msgs__action__MoveTCPAlongAxis_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Result * msg = (kr_msgs__action__MoveTCPAlongAxis_Result *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_Result));
  bool success = kr_msgs__action__MoveTCPAlongAxis_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_Result__destroy(kr_msgs__action__MoveTCPAlongAxis_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Result * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_Result *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_Result__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_Result__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_Result__Sequence *
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_Result__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_Result);
    kr_msgs__action__MoveTCPAlongAxis_Result * data =
      (kr_msgs__action__MoveTCPAlongAxis_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_Result__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__init(kr_msgs__action__MoveTCPAlongAxis_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(kr_msgs__action__MoveTCPAlongAxis_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Feedback * lhs, const kr_msgs__action__MoveTCPAlongAxis_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Feedback * input,
  kr_msgs__action__MoveTCPAlongAxis_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_Feedback *
kr_msgs__action__MoveTCPAlongAxis_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Feedback * msg = (kr_msgs__action__MoveTCPAlongAxis_Feedback *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_Feedback));
  bool success = kr_msgs__action__MoveTCPAlongAxis_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_Feedback__destroy(kr_msgs__action__MoveTCPAlongAxis_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Feedback * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_Feedback *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence *
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_Feedback);
    kr_msgs__action__MoveTCPAlongAxis_Feedback * data =
      (kr_msgs__action__MoveTCPAlongAxis_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!kr_msgs__action__MoveTCPAlongAxis_Goal__init(&msg->goal)) {
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  kr_msgs__action__MoveTCPAlongAxis_Goal__fini(&msg->goal);
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!kr_msgs__action__MoveTCPAlongAxis_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!kr_msgs__action__MoveTCPAlongAxis_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * msg = (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request));
  bool success = kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request);
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * data =
      (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * msg = (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response));
  bool success = kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response);
    kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * data =
      (kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_GetResult_Request *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * msg = (kr_msgs__action__MoveTCPAlongAxis_GetResult_Request *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request));
  bool success = kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_GetResult_Request *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request);
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * data =
      (kr_msgs__action__MoveTCPAlongAxis_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!kr_msgs__action__MoveTCPAlongAxis_Result__init(&msg->result)) {
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  kr_msgs__action__MoveTCPAlongAxis_Result__fini(&msg->result);
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!kr_msgs__action__MoveTCPAlongAxis_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!kr_msgs__action__MoveTCPAlongAxis_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_GetResult_Response *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * msg = (kr_msgs__action__MoveTCPAlongAxis_GetResult_Response *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response));
  bool success = kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_GetResult_Response *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response);
    kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * data =
      (kr_msgs__action__MoveTCPAlongAxis_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "kr_msgs/action/detail/move_tcp_along_axis__functions.h"

bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!kr_msgs__action__MoveTCPAlongAxis_Feedback__init(&msg->feedback)) {
    kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(&msg->feedback);
}

bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__are_equal(const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * lhs, const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!kr_msgs__action__MoveTCPAlongAxis_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__copy(
  const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * input,
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!kr_msgs__action__MoveTCPAlongAxis_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage *
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * msg = (kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage));
  bool success = kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__destroy(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * data = NULL;

  if (size) {
    data = (kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage *)allocator.zero_allocate(size, sizeof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(&data[i - 1]);
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
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * array)
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
      kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(&array->data[i]);
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

kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence *
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * array = (kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence *)allocator.allocate(sizeof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage);
    kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * data =
      (kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(&data[i]);
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
    if (!kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
