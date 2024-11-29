// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:msg/SafetyZone.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/safety_zone__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `planes`
#include "kr_msgs/msg/detail/geometry_plane__functions.h"

bool
kr_msgs__msg__SafetyZone__init(kr_msgs__msg__SafetyZone * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    kr_msgs__msg__SafetyZone__fini(msg);
    return false;
  }
  // speed
  // buffer
  // sensitivity
  // safety_io
  // planes
  if (!kr_msgs__msg__GeometryPlane__Sequence__init(&msg->planes, 0)) {
    kr_msgs__msg__SafetyZone__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__msg__SafetyZone__fini(kr_msgs__msg__SafetyZone * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // speed
  // buffer
  // sensitivity
  // safety_io
  // planes
  kr_msgs__msg__GeometryPlane__Sequence__fini(&msg->planes);
}

bool
kr_msgs__msg__SafetyZone__are_equal(const kr_msgs__msg__SafetyZone * lhs, const kr_msgs__msg__SafetyZone * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // buffer
  if (lhs->buffer != rhs->buffer) {
    return false;
  }
  // sensitivity
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->sensitivity[i] != rhs->sensitivity[i]) {
      return false;
    }
  }
  // safety_io
  if (lhs->safety_io != rhs->safety_io) {
    return false;
  }
  // planes
  if (!kr_msgs__msg__GeometryPlane__Sequence__are_equal(
      &(lhs->planes), &(rhs->planes)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__msg__SafetyZone__copy(
  const kr_msgs__msg__SafetyZone * input,
  kr_msgs__msg__SafetyZone * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // speed
  output->speed = input->speed;
  // buffer
  output->buffer = input->buffer;
  // sensitivity
  for (size_t i = 0; i < 7; ++i) {
    output->sensitivity[i] = input->sensitivity[i];
  }
  // safety_io
  output->safety_io = input->safety_io;
  // planes
  if (!kr_msgs__msg__GeometryPlane__Sequence__copy(
      &(input->planes), &(output->planes)))
  {
    return false;
  }
  return true;
}

kr_msgs__msg__SafetyZone *
kr_msgs__msg__SafetyZone__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SafetyZone * msg = (kr_msgs__msg__SafetyZone *)allocator.allocate(sizeof(kr_msgs__msg__SafetyZone), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__msg__SafetyZone));
  bool success = kr_msgs__msg__SafetyZone__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__msg__SafetyZone__destroy(kr_msgs__msg__SafetyZone * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__msg__SafetyZone__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__msg__SafetyZone__Sequence__init(kr_msgs__msg__SafetyZone__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SafetyZone * data = NULL;

  if (size) {
    data = (kr_msgs__msg__SafetyZone *)allocator.zero_allocate(size, sizeof(kr_msgs__msg__SafetyZone), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__msg__SafetyZone__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__msg__SafetyZone__fini(&data[i - 1]);
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
kr_msgs__msg__SafetyZone__Sequence__fini(kr_msgs__msg__SafetyZone__Sequence * array)
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
      kr_msgs__msg__SafetyZone__fini(&array->data[i]);
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

kr_msgs__msg__SafetyZone__Sequence *
kr_msgs__msg__SafetyZone__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__SafetyZone__Sequence * array = (kr_msgs__msg__SafetyZone__Sequence *)allocator.allocate(sizeof(kr_msgs__msg__SafetyZone__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__msg__SafetyZone__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__msg__SafetyZone__Sequence__destroy(kr_msgs__msg__SafetyZone__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__msg__SafetyZone__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__msg__SafetyZone__Sequence__are_equal(const kr_msgs__msg__SafetyZone__Sequence * lhs, const kr_msgs__msg__SafetyZone__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__msg__SafetyZone__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__SafetyZone__Sequence__copy(
  const kr_msgs__msg__SafetyZone__Sequence * input,
  kr_msgs__msg__SafetyZone__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__msg__SafetyZone);
    kr_msgs__msg__SafetyZone * data =
      (kr_msgs__msg__SafetyZone *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__msg__SafetyZone__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__msg__SafetyZone__fini(&data[i]);
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
    if (!kr_msgs__msg__SafetyZone__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
