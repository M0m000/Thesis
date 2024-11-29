// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:msg/RobotMode.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/robot_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `str`
#include "rosidl_runtime_c/string_functions.h"

bool
kr_msgs__msg__RobotMode__init(kr_msgs__msg__RobotMode * msg)
{
  if (!msg) {
    return false;
  }
  // val
  // str
  if (!rosidl_runtime_c__String__init(&msg->str)) {
    kr_msgs__msg__RobotMode__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__msg__RobotMode__fini(kr_msgs__msg__RobotMode * msg)
{
  if (!msg) {
    return;
  }
  // val
  // str
  rosidl_runtime_c__String__fini(&msg->str);
}

bool
kr_msgs__msg__RobotMode__are_equal(const kr_msgs__msg__RobotMode * lhs, const kr_msgs__msg__RobotMode * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // val
  if (lhs->val != rhs->val) {
    return false;
  }
  // str
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->str), &(rhs->str)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__msg__RobotMode__copy(
  const kr_msgs__msg__RobotMode * input,
  kr_msgs__msg__RobotMode * output)
{
  if (!input || !output) {
    return false;
  }
  // val
  output->val = input->val;
  // str
  if (!rosidl_runtime_c__String__copy(
      &(input->str), &(output->str)))
  {
    return false;
  }
  return true;
}

kr_msgs__msg__RobotMode *
kr_msgs__msg__RobotMode__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__RobotMode * msg = (kr_msgs__msg__RobotMode *)allocator.allocate(sizeof(kr_msgs__msg__RobotMode), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__msg__RobotMode));
  bool success = kr_msgs__msg__RobotMode__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__msg__RobotMode__destroy(kr_msgs__msg__RobotMode * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__msg__RobotMode__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__msg__RobotMode__Sequence__init(kr_msgs__msg__RobotMode__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__RobotMode * data = NULL;

  if (size) {
    data = (kr_msgs__msg__RobotMode *)allocator.zero_allocate(size, sizeof(kr_msgs__msg__RobotMode), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__msg__RobotMode__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__msg__RobotMode__fini(&data[i - 1]);
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
kr_msgs__msg__RobotMode__Sequence__fini(kr_msgs__msg__RobotMode__Sequence * array)
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
      kr_msgs__msg__RobotMode__fini(&array->data[i]);
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

kr_msgs__msg__RobotMode__Sequence *
kr_msgs__msg__RobotMode__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__RobotMode__Sequence * array = (kr_msgs__msg__RobotMode__Sequence *)allocator.allocate(sizeof(kr_msgs__msg__RobotMode__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__msg__RobotMode__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__msg__RobotMode__Sequence__destroy(kr_msgs__msg__RobotMode__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__msg__RobotMode__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__msg__RobotMode__Sequence__are_equal(const kr_msgs__msg__RobotMode__Sequence * lhs, const kr_msgs__msg__RobotMode__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__msg__RobotMode__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__RobotMode__Sequence__copy(
  const kr_msgs__msg__RobotMode__Sequence * input,
  kr_msgs__msg__RobotMode__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__msg__RobotMode);
    kr_msgs__msg__RobotMode * data =
      (kr_msgs__msg__RobotMode *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__msg__RobotMode__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__msg__RobotMode__fini(&data[i]);
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
    if (!kr_msgs__msg__RobotMode__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
