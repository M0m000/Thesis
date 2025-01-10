// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:msg/JogJoint.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/jog_joint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
kr_msgs__msg__JogJoint__init(kr_msgs__msg__JogJoint * msg)
{
  if (!msg) {
    return false;
  }
  // jsvel
  return true;
}

void
kr_msgs__msg__JogJoint__fini(kr_msgs__msg__JogJoint * msg)
{
  if (!msg) {
    return;
  }
  // jsvel
}

bool
kr_msgs__msg__JogJoint__are_equal(const kr_msgs__msg__JogJoint * lhs, const kr_msgs__msg__JogJoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // jsvel
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->jsvel[i] != rhs->jsvel[i]) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__JogJoint__copy(
  const kr_msgs__msg__JogJoint * input,
  kr_msgs__msg__JogJoint * output)
{
  if (!input || !output) {
    return false;
  }
  // jsvel
  for (size_t i = 0; i < 7; ++i) {
    output->jsvel[i] = input->jsvel[i];
  }
  return true;
}

kr_msgs__msg__JogJoint *
kr_msgs__msg__JogJoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__JogJoint * msg = (kr_msgs__msg__JogJoint *)allocator.allocate(sizeof(kr_msgs__msg__JogJoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__msg__JogJoint));
  bool success = kr_msgs__msg__JogJoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__msg__JogJoint__destroy(kr_msgs__msg__JogJoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__msg__JogJoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__msg__JogJoint__Sequence__init(kr_msgs__msg__JogJoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__JogJoint * data = NULL;

  if (size) {
    data = (kr_msgs__msg__JogJoint *)allocator.zero_allocate(size, sizeof(kr_msgs__msg__JogJoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__msg__JogJoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__msg__JogJoint__fini(&data[i - 1]);
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
kr_msgs__msg__JogJoint__Sequence__fini(kr_msgs__msg__JogJoint__Sequence * array)
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
      kr_msgs__msg__JogJoint__fini(&array->data[i]);
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

kr_msgs__msg__JogJoint__Sequence *
kr_msgs__msg__JogJoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__JogJoint__Sequence * array = (kr_msgs__msg__JogJoint__Sequence *)allocator.allocate(sizeof(kr_msgs__msg__JogJoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__msg__JogJoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__msg__JogJoint__Sequence__destroy(kr_msgs__msg__JogJoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__msg__JogJoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__msg__JogJoint__Sequence__are_equal(const kr_msgs__msg__JogJoint__Sequence * lhs, const kr_msgs__msg__JogJoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__msg__JogJoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__JogJoint__Sequence__copy(
  const kr_msgs__msg__JogJoint__Sequence * input,
  kr_msgs__msg__JogJoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__msg__JogJoint);
    kr_msgs__msg__JogJoint * data =
      (kr_msgs__msg__JogJoint *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__msg__JogJoint__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__msg__JogJoint__fini(&data[i]);
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
    if (!kr_msgs__msg__JogJoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
