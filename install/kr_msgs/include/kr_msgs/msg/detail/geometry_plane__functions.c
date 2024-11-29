// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:msg/GeometryPlane.idl
// generated code does not contain a copyright notice
#include "kr_msgs/msg/detail/geometry_plane__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
kr_msgs__msg__GeometryPlane__init(kr_msgs__msg__GeometryPlane * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    kr_msgs__msg__GeometryPlane__fini(msg);
    return false;
  }
  // point
  // normal
  return true;
}

void
kr_msgs__msg__GeometryPlane__fini(kr_msgs__msg__GeometryPlane * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // point
  // normal
}

bool
kr_msgs__msg__GeometryPlane__are_equal(const kr_msgs__msg__GeometryPlane * lhs, const kr_msgs__msg__GeometryPlane * rhs)
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
  // point
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->point[i] != rhs->point[i]) {
      return false;
    }
  }
  // normal
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->normal[i] != rhs->normal[i]) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__GeometryPlane__copy(
  const kr_msgs__msg__GeometryPlane * input,
  kr_msgs__msg__GeometryPlane * output)
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
  // point
  for (size_t i = 0; i < 3; ++i) {
    output->point[i] = input->point[i];
  }
  // normal
  for (size_t i = 0; i < 3; ++i) {
    output->normal[i] = input->normal[i];
  }
  return true;
}

kr_msgs__msg__GeometryPlane *
kr_msgs__msg__GeometryPlane__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__GeometryPlane * msg = (kr_msgs__msg__GeometryPlane *)allocator.allocate(sizeof(kr_msgs__msg__GeometryPlane), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__msg__GeometryPlane));
  bool success = kr_msgs__msg__GeometryPlane__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__msg__GeometryPlane__destroy(kr_msgs__msg__GeometryPlane * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__msg__GeometryPlane__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__msg__GeometryPlane__Sequence__init(kr_msgs__msg__GeometryPlane__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__GeometryPlane * data = NULL;

  if (size) {
    data = (kr_msgs__msg__GeometryPlane *)allocator.zero_allocate(size, sizeof(kr_msgs__msg__GeometryPlane), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__msg__GeometryPlane__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__msg__GeometryPlane__fini(&data[i - 1]);
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
kr_msgs__msg__GeometryPlane__Sequence__fini(kr_msgs__msg__GeometryPlane__Sequence * array)
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
      kr_msgs__msg__GeometryPlane__fini(&array->data[i]);
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

kr_msgs__msg__GeometryPlane__Sequence *
kr_msgs__msg__GeometryPlane__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__msg__GeometryPlane__Sequence * array = (kr_msgs__msg__GeometryPlane__Sequence *)allocator.allocate(sizeof(kr_msgs__msg__GeometryPlane__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__msg__GeometryPlane__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__msg__GeometryPlane__Sequence__destroy(kr_msgs__msg__GeometryPlane__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__msg__GeometryPlane__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__msg__GeometryPlane__Sequence__are_equal(const kr_msgs__msg__GeometryPlane__Sequence * lhs, const kr_msgs__msg__GeometryPlane__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__msg__GeometryPlane__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__msg__GeometryPlane__Sequence__copy(
  const kr_msgs__msg__GeometryPlane__Sequence * input,
  kr_msgs__msg__GeometryPlane__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__msg__GeometryPlane);
    kr_msgs__msg__GeometryPlane * data =
      (kr_msgs__msg__GeometryPlane *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__msg__GeometryPlane__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__msg__GeometryPlane__fini(&data[i]);
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
    if (!kr_msgs__msg__GeometryPlane__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
