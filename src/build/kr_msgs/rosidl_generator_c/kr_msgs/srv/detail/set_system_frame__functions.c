// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:srv/SetSystemFrame.idl
// generated code does not contain a copyright notice
#include "kr_msgs/srv/detail/set_system_frame__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
// Member `ref`
#include "rosidl_runtime_c/string_functions.h"

bool
kr_msgs__srv__SetSystemFrame_Request__init(kr_msgs__srv__SetSystemFrame_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    kr_msgs__srv__SetSystemFrame_Request__fini(msg);
    return false;
  }
  // pos
  // rot
  // ref
  if (!rosidl_runtime_c__String__init(&msg->ref)) {
    kr_msgs__srv__SetSystemFrame_Request__fini(msg);
    return false;
  }
  return true;
}

void
kr_msgs__srv__SetSystemFrame_Request__fini(kr_msgs__srv__SetSystemFrame_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // pos
  // rot
  // ref
  rosidl_runtime_c__String__fini(&msg->ref);
}

bool
kr_msgs__srv__SetSystemFrame_Request__are_equal(const kr_msgs__srv__SetSystemFrame_Request * lhs, const kr_msgs__srv__SetSystemFrame_Request * rhs)
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
  // ref
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->ref), &(rhs->ref)))
  {
    return false;
  }
  return true;
}

bool
kr_msgs__srv__SetSystemFrame_Request__copy(
  const kr_msgs__srv__SetSystemFrame_Request * input,
  kr_msgs__srv__SetSystemFrame_Request * output)
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
  // pos
  for (size_t i = 0; i < 3; ++i) {
    output->pos[i] = input->pos[i];
  }
  // rot
  for (size_t i = 0; i < 3; ++i) {
    output->rot[i] = input->rot[i];
  }
  // ref
  if (!rosidl_runtime_c__String__copy(
      &(input->ref), &(output->ref)))
  {
    return false;
  }
  return true;
}

kr_msgs__srv__SetSystemFrame_Request *
kr_msgs__srv__SetSystemFrame_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__SetSystemFrame_Request * msg = (kr_msgs__srv__SetSystemFrame_Request *)allocator.allocate(sizeof(kr_msgs__srv__SetSystemFrame_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__srv__SetSystemFrame_Request));
  bool success = kr_msgs__srv__SetSystemFrame_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__srv__SetSystemFrame_Request__destroy(kr_msgs__srv__SetSystemFrame_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__srv__SetSystemFrame_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__srv__SetSystemFrame_Request__Sequence__init(kr_msgs__srv__SetSystemFrame_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__SetSystemFrame_Request * data = NULL;

  if (size) {
    data = (kr_msgs__srv__SetSystemFrame_Request *)allocator.zero_allocate(size, sizeof(kr_msgs__srv__SetSystemFrame_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__srv__SetSystemFrame_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__srv__SetSystemFrame_Request__fini(&data[i - 1]);
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
kr_msgs__srv__SetSystemFrame_Request__Sequence__fini(kr_msgs__srv__SetSystemFrame_Request__Sequence * array)
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
      kr_msgs__srv__SetSystemFrame_Request__fini(&array->data[i]);
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

kr_msgs__srv__SetSystemFrame_Request__Sequence *
kr_msgs__srv__SetSystemFrame_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__SetSystemFrame_Request__Sequence * array = (kr_msgs__srv__SetSystemFrame_Request__Sequence *)allocator.allocate(sizeof(kr_msgs__srv__SetSystemFrame_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__srv__SetSystemFrame_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__srv__SetSystemFrame_Request__Sequence__destroy(kr_msgs__srv__SetSystemFrame_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__srv__SetSystemFrame_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__srv__SetSystemFrame_Request__Sequence__are_equal(const kr_msgs__srv__SetSystemFrame_Request__Sequence * lhs, const kr_msgs__srv__SetSystemFrame_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__srv__SetSystemFrame_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__srv__SetSystemFrame_Request__Sequence__copy(
  const kr_msgs__srv__SetSystemFrame_Request__Sequence * input,
  kr_msgs__srv__SetSystemFrame_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__srv__SetSystemFrame_Request);
    kr_msgs__srv__SetSystemFrame_Request * data =
      (kr_msgs__srv__SetSystemFrame_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__srv__SetSystemFrame_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__srv__SetSystemFrame_Request__fini(&data[i]);
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
    if (!kr_msgs__srv__SetSystemFrame_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
kr_msgs__srv__SetSystemFrame_Response__init(kr_msgs__srv__SetSystemFrame_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
kr_msgs__srv__SetSystemFrame_Response__fini(kr_msgs__srv__SetSystemFrame_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
kr_msgs__srv__SetSystemFrame_Response__are_equal(const kr_msgs__srv__SetSystemFrame_Response * lhs, const kr_msgs__srv__SetSystemFrame_Response * rhs)
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
kr_msgs__srv__SetSystemFrame_Response__copy(
  const kr_msgs__srv__SetSystemFrame_Response * input,
  kr_msgs__srv__SetSystemFrame_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

kr_msgs__srv__SetSystemFrame_Response *
kr_msgs__srv__SetSystemFrame_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__SetSystemFrame_Response * msg = (kr_msgs__srv__SetSystemFrame_Response *)allocator.allocate(sizeof(kr_msgs__srv__SetSystemFrame_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__srv__SetSystemFrame_Response));
  bool success = kr_msgs__srv__SetSystemFrame_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__srv__SetSystemFrame_Response__destroy(kr_msgs__srv__SetSystemFrame_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__srv__SetSystemFrame_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__srv__SetSystemFrame_Response__Sequence__init(kr_msgs__srv__SetSystemFrame_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__SetSystemFrame_Response * data = NULL;

  if (size) {
    data = (kr_msgs__srv__SetSystemFrame_Response *)allocator.zero_allocate(size, sizeof(kr_msgs__srv__SetSystemFrame_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__srv__SetSystemFrame_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__srv__SetSystemFrame_Response__fini(&data[i - 1]);
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
kr_msgs__srv__SetSystemFrame_Response__Sequence__fini(kr_msgs__srv__SetSystemFrame_Response__Sequence * array)
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
      kr_msgs__srv__SetSystemFrame_Response__fini(&array->data[i]);
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

kr_msgs__srv__SetSystemFrame_Response__Sequence *
kr_msgs__srv__SetSystemFrame_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__SetSystemFrame_Response__Sequence * array = (kr_msgs__srv__SetSystemFrame_Response__Sequence *)allocator.allocate(sizeof(kr_msgs__srv__SetSystemFrame_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__srv__SetSystemFrame_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__srv__SetSystemFrame_Response__Sequence__destroy(kr_msgs__srv__SetSystemFrame_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__srv__SetSystemFrame_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__srv__SetSystemFrame_Response__Sequence__are_equal(const kr_msgs__srv__SetSystemFrame_Response__Sequence * lhs, const kr_msgs__srv__SetSystemFrame_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__srv__SetSystemFrame_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__srv__SetSystemFrame_Response__Sequence__copy(
  const kr_msgs__srv__SetSystemFrame_Response__Sequence * input,
  kr_msgs__srv__SetSystemFrame_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__srv__SetSystemFrame_Response);
    kr_msgs__srv__SetSystemFrame_Response * data =
      (kr_msgs__srv__SetSystemFrame_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__srv__SetSystemFrame_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__srv__SetSystemFrame_Response__fini(&data[i]);
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
    if (!kr_msgs__srv__SetSystemFrame_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
