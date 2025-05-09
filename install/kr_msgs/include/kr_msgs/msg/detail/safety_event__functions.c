// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:msg/SafetyEvent.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/safety_event__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
kr_msgs__msg__SafetyEvent__init(kr_msgs__msg__SafetyEvent * msg)
{
  if (!msg) {
    return false;
  }
  // type
  // code
  // timestamp
  return true;
}

void
kr_msgs__msg__SafetyEvent__fini(kr_msgs__msg__SafetyEvent * msg)
{
  if (!msg) {
    return;
  }
  // type
  // code
  // timestamp
}

bool
kr_msgs__msg__SafetyEvent__are_equal(const kr_msgs__msg__SafetyEvent * lhs, const kr_msgs__msg__SafetyEvent * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // code
  if (lhs->code != rhs->code) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  return true;
}

bool
kr_msgs__msg__SafetyEvent__copy(
  const kr_msgs__msg__SafetyEvent * input,
  kr_msgs__msg__SafetyEvent * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // code
  output->code = input->code;
  // timestamp
  output->timestamp = input->timestamp;
  return true;
}

kr_msgs__msg__SafetyEvent *
kr_msgs__msg__SafetyEvent__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SafetyEvent * msg = (kr_msgs__msg__SafetyEvent *)allocator.allocate(sizeof(kr_msgs__msg__SafetyEvent), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__msg__SafetyEvent));
  bool success = kr_msgs__msg__SafetyEvent__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__msg__SafetyEvent__destroy(kr_msgs__msg__SafetyEvent * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__msg__SafetyEvent__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__msg__SafetyEvent__Sequence__init(kr_msgs__msg__SafetyEvent__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SafetyEvent * data = NULL;

  if (size) {
    data = (kr_msgs__msg__SafetyEvent *)allocator.zero_allocate(size, sizeof(kr_msgs__msg__SafetyEvent), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__msg__SafetyEvent__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__msg__SafetyEvent__fini(&data[i - 1]);
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
kr_msgs__msg__SafetyEvent__Sequence__fini(kr_msgs__msg__SafetyEvent__Sequence * array)
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
      kr_msgs__msg__SafetyEvent__fini(&array->data[i]);
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

kr_msgs__msg__SafetyEvent__Sequence *
kr_msgs__msg__SafetyEvent__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SafetyEvent__Sequence * array = (kr_msgs__msg__SafetyEvent__Sequence *)allocator.allocate(sizeof(kr_msgs__msg__SafetyEvent__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__msg__SafetyEvent__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__msg__SafetyEvent__Sequence__destroy(kr_msgs__msg__SafetyEvent__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__msg__SafetyEvent__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__msg__SafetyEvent__Sequence__are_equal(const kr_msgs__msg__SafetyEvent__Sequence * lhs, const kr_msgs__msg__SafetyEvent__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__msg__SafetyEvent__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__SafetyEvent__Sequence__copy(
  const kr_msgs__msg__SafetyEvent__Sequence * input,
  kr_msgs__msg__SafetyEvent__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__msg__SafetyEvent);
    kr_msgs__msg__SafetyEvent * data =
      (kr_msgs__msg__SafetyEvent *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__msg__SafetyEvent__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__msg__SafetyEvent__fini(&data[i]);
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
    if (!kr_msgs__msg__SafetyEvent__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
