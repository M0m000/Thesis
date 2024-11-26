// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/robot_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
kr_msgs__msg__RobotPose__init(kr_msgs__msg__RobotPose * msg)
{
  if (!msg) {
    return false;
  }
  // pos
  // rot
  // jsconf
  return true;
}

void
kr_msgs__msg__RobotPose__fini(kr_msgs__msg__RobotPose * msg)
{
  if (!msg) {
    return;
  }
  // pos
  // rot
  // jsconf
}

bool
kr_msgs__msg__RobotPose__are_equal(const kr_msgs__msg__RobotPose * lhs, const kr_msgs__msg__RobotPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
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
  // jsconf
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->jsconf[i] != rhs->jsconf[i]) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__RobotPose__copy(
  const kr_msgs__msg__RobotPose * input,
  kr_msgs__msg__RobotPose * output)
{
  if (!input || !output) {
    return false;
  }
  // pos
  for (size_t i = 0; i < 3; ++i) {
    output->pos[i] = input->pos[i];
  }
  // rot
  for (size_t i = 0; i < 3; ++i) {
    output->rot[i] = input->rot[i];
  }
  // jsconf
  for (size_t i = 0; i < 7; ++i) {
    output->jsconf[i] = input->jsconf[i];
  }
  return true;
}

kr_msgs__msg__RobotPose *
kr_msgs__msg__RobotPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__RobotPose * msg = (kr_msgs__msg__RobotPose *)allocator.allocate(sizeof(kr_msgs__msg__RobotPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__msg__RobotPose));
  bool success = kr_msgs__msg__RobotPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__msg__RobotPose__destroy(kr_msgs__msg__RobotPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__msg__RobotPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__msg__RobotPose__Sequence__init(kr_msgs__msg__RobotPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__RobotPose * data = NULL;

  if (size) {
    data = (kr_msgs__msg__RobotPose *)allocator.zero_allocate(size, sizeof(kr_msgs__msg__RobotPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__msg__RobotPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__msg__RobotPose__fini(&data[i - 1]);
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
kr_msgs__msg__RobotPose__Sequence__fini(kr_msgs__msg__RobotPose__Sequence * array)
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
      kr_msgs__msg__RobotPose__fini(&array->data[i]);
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

kr_msgs__msg__RobotPose__Sequence *
kr_msgs__msg__RobotPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__RobotPose__Sequence * array = (kr_msgs__msg__RobotPose__Sequence *)allocator.allocate(sizeof(kr_msgs__msg__RobotPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__msg__RobotPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__msg__RobotPose__Sequence__destroy(kr_msgs__msg__RobotPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__msg__RobotPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__msg__RobotPose__Sequence__are_equal(const kr_msgs__msg__RobotPose__Sequence * lhs, const kr_msgs__msg__RobotPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__msg__RobotPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__RobotPose__Sequence__copy(
  const kr_msgs__msg__RobotPose__Sequence * input,
  kr_msgs__msg__RobotPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__msg__RobotPose);
    kr_msgs__msg__RobotPose * data =
      (kr_msgs__msg__RobotPose *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__msg__RobotPose__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__msg__RobotPose__fini(&data[i]);
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
    if (!kr_msgs__msg__RobotPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
