// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kr_msgs:srv/MoveJoint.idl
// generated code does not contain a copyright notice
#include "kr_msgs/srv/detail/move_joint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
kr_msgs__srv__MoveJoint_Request__init(kr_msgs__srv__MoveJoint_Request * msg)
{
  if (!msg) {
    return false;
  }
  // jsconf
  // ttype
  // tvalue
  // bpoint
  // btype
  // bvalue
  // sync
  // chaining
  return true;
}

void
kr_msgs__srv__MoveJoint_Request__fini(kr_msgs__srv__MoveJoint_Request * msg)
{
  if (!msg) {
    return;
  }
  // jsconf
  // ttype
  // tvalue
  // bpoint
  // btype
  // bvalue
  // sync
  // chaining
}

bool
kr_msgs__srv__MoveJoint_Request__are_equal(const kr_msgs__srv__MoveJoint_Request * lhs, const kr_msgs__srv__MoveJoint_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // jsconf
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->jsconf[i] != rhs->jsconf[i]) {
      return false;
    }
  }
  // ttype
  if (lhs->ttype != rhs->ttype) {
    return false;
  }
  // tvalue
  if (lhs->tvalue != rhs->tvalue) {
    return false;
  }
  // bpoint
  if (lhs->bpoint != rhs->bpoint) {
    return false;
  }
  // btype
  if (lhs->btype != rhs->btype) {
    return false;
  }
  // bvalue
  if (lhs->bvalue != rhs->bvalue) {
    return false;
  }
  // sync
  if (lhs->sync != rhs->sync) {
    return false;
  }
  // chaining
  if (lhs->chaining != rhs->chaining) {
    return false;
  }
  return true;
}

bool
kr_msgs__srv__MoveJoint_Request__copy(
  const kr_msgs__srv__MoveJoint_Request * input,
  kr_msgs__srv__MoveJoint_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // jsconf
  for (size_t i = 0; i < 7; ++i) {
    output->jsconf[i] = input->jsconf[i];
  }
  // ttype
  output->ttype = input->ttype;
  // tvalue
  output->tvalue = input->tvalue;
  // bpoint
  output->bpoint = input->bpoint;
  // btype
  output->btype = input->btype;
  // bvalue
  output->bvalue = input->bvalue;
  // sync
  output->sync = input->sync;
  // chaining
  output->chaining = input->chaining;
  return true;
}

kr_msgs__srv__MoveJoint_Request *
kr_msgs__srv__MoveJoint_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__MoveJoint_Request * msg = (kr_msgs__srv__MoveJoint_Request *)allocator.allocate(sizeof(kr_msgs__srv__MoveJoint_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__srv__MoveJoint_Request));
  bool success = kr_msgs__srv__MoveJoint_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__srv__MoveJoint_Request__destroy(kr_msgs__srv__MoveJoint_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__srv__MoveJoint_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__srv__MoveJoint_Request__Sequence__init(kr_msgs__srv__MoveJoint_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__MoveJoint_Request * data = NULL;

  if (size) {
    data = (kr_msgs__srv__MoveJoint_Request *)allocator.zero_allocate(size, sizeof(kr_msgs__srv__MoveJoint_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__srv__MoveJoint_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__srv__MoveJoint_Request__fini(&data[i - 1]);
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
kr_msgs__srv__MoveJoint_Request__Sequence__fini(kr_msgs__srv__MoveJoint_Request__Sequence * array)
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
      kr_msgs__srv__MoveJoint_Request__fini(&array->data[i]);
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

kr_msgs__srv__MoveJoint_Request__Sequence *
kr_msgs__srv__MoveJoint_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__MoveJoint_Request__Sequence * array = (kr_msgs__srv__MoveJoint_Request__Sequence *)allocator.allocate(sizeof(kr_msgs__srv__MoveJoint_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__srv__MoveJoint_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__srv__MoveJoint_Request__Sequence__destroy(kr_msgs__srv__MoveJoint_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__srv__MoveJoint_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__srv__MoveJoint_Request__Sequence__are_equal(const kr_msgs__srv__MoveJoint_Request__Sequence * lhs, const kr_msgs__srv__MoveJoint_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__srv__MoveJoint_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__srv__MoveJoint_Request__Sequence__copy(
  const kr_msgs__srv__MoveJoint_Request__Sequence * input,
  kr_msgs__srv__MoveJoint_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__srv__MoveJoint_Request);
    kr_msgs__srv__MoveJoint_Request * data =
      (kr_msgs__srv__MoveJoint_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__srv__MoveJoint_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__srv__MoveJoint_Request__fini(&data[i]);
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
    if (!kr_msgs__srv__MoveJoint_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
kr_msgs__srv__MoveJoint_Response__init(kr_msgs__srv__MoveJoint_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
kr_msgs__srv__MoveJoint_Response__fini(kr_msgs__srv__MoveJoint_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
kr_msgs__srv__MoveJoint_Response__are_equal(const kr_msgs__srv__MoveJoint_Response * lhs, const kr_msgs__srv__MoveJoint_Response * rhs)
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
kr_msgs__srv__MoveJoint_Response__copy(
  const kr_msgs__srv__MoveJoint_Response * input,
  kr_msgs__srv__MoveJoint_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

kr_msgs__srv__MoveJoint_Response *
kr_msgs__srv__MoveJoint_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__MoveJoint_Response * msg = (kr_msgs__srv__MoveJoint_Response *)allocator.allocate(sizeof(kr_msgs__srv__MoveJoint_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kr_msgs__srv__MoveJoint_Response));
  bool success = kr_msgs__srv__MoveJoint_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kr_msgs__srv__MoveJoint_Response__destroy(kr_msgs__srv__MoveJoint_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kr_msgs__srv__MoveJoint_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kr_msgs__srv__MoveJoint_Response__Sequence__init(kr_msgs__srv__MoveJoint_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__MoveJoint_Response * data = NULL;

  if (size) {
    data = (kr_msgs__srv__MoveJoint_Response *)allocator.zero_allocate(size, sizeof(kr_msgs__srv__MoveJoint_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kr_msgs__srv__MoveJoint_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kr_msgs__srv__MoveJoint_Response__fini(&data[i - 1]);
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
kr_msgs__srv__MoveJoint_Response__Sequence__fini(kr_msgs__srv__MoveJoint_Response__Sequence * array)
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
      kr_msgs__srv__MoveJoint_Response__fini(&array->data[i]);
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

kr_msgs__srv__MoveJoint_Response__Sequence *
kr_msgs__srv__MoveJoint_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kr_msgs__srv__MoveJoint_Response__Sequence * array = (kr_msgs__srv__MoveJoint_Response__Sequence *)allocator.allocate(sizeof(kr_msgs__srv__MoveJoint_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kr_msgs__srv__MoveJoint_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kr_msgs__srv__MoveJoint_Response__Sequence__destroy(kr_msgs__srv__MoveJoint_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kr_msgs__srv__MoveJoint_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kr_msgs__srv__MoveJoint_Response__Sequence__are_equal(const kr_msgs__srv__MoveJoint_Response__Sequence * lhs, const kr_msgs__srv__MoveJoint_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kr_msgs__srv__MoveJoint_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kr_msgs__srv__MoveJoint_Response__Sequence__copy(
  const kr_msgs__srv__MoveJoint_Response__Sequence * input,
  kr_msgs__srv__MoveJoint_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kr_msgs__srv__MoveJoint_Response);
    kr_msgs__srv__MoveJoint_Response * data =
      (kr_msgs__srv__MoveJoint_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kr_msgs__srv__MoveJoint_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kr_msgs__srv__MoveJoint_Response__fini(&data[i]);
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
    if (!kr_msgs__srv__MoveJoint_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
