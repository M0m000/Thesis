// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from action_interfaces:srv/GenerateFrame.idl
// generated code does not contain a copyright notice
#include "action_interfaces/srv/detail/generate_frame__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `frame_new`
// Member `frame_ref`
#include "rosidl_runtime_c/string_functions.h"

bool
action_interfaces__srv__GenerateFrame_Request__init(action_interfaces__srv__GenerateFrame_Request * msg)
{
  if (!msg) {
    return false;
  }
  // frame_new
  if (!rosidl_runtime_c__String__init(&msg->frame_new)) {
    action_interfaces__srv__GenerateFrame_Request__fini(msg);
    return false;
  }
  // frame_ref
  if (!rosidl_runtime_c__String__init(&msg->frame_ref)) {
    action_interfaces__srv__GenerateFrame_Request__fini(msg);
    return false;
  }
  // translation
  // rotation_rpy
  return true;
}

void
action_interfaces__srv__GenerateFrame_Request__fini(action_interfaces__srv__GenerateFrame_Request * msg)
{
  if (!msg) {
    return;
  }
  // frame_new
  rosidl_runtime_c__String__fini(&msg->frame_new);
  // frame_ref
  rosidl_runtime_c__String__fini(&msg->frame_ref);
  // translation
  // rotation_rpy
}

bool
action_interfaces__srv__GenerateFrame_Request__are_equal(const action_interfaces__srv__GenerateFrame_Request * lhs, const action_interfaces__srv__GenerateFrame_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // frame_new
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_new), &(rhs->frame_new)))
  {
    return false;
  }
  // frame_ref
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_ref), &(rhs->frame_ref)))
  {
    return false;
  }
  // translation
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->translation[i] != rhs->translation[i]) {
      return false;
    }
  }
  // rotation_rpy
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->rotation_rpy[i] != rhs->rotation_rpy[i]) {
      return false;
    }
  }
  return true;
}

bool
action_interfaces__srv__GenerateFrame_Request__copy(
  const action_interfaces__srv__GenerateFrame_Request * input,
  action_interfaces__srv__GenerateFrame_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // frame_new
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_new), &(output->frame_new)))
  {
    return false;
  }
  // frame_ref
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_ref), &(output->frame_ref)))
  {
    return false;
  }
  // translation
  for (size_t i = 0; i < 3; ++i) {
    output->translation[i] = input->translation[i];
  }
  // rotation_rpy
  for (size_t i = 0; i < 3; ++i) {
    output->rotation_rpy[i] = input->rotation_rpy[i];
  }
  return true;
}

action_interfaces__srv__GenerateFrame_Request *
action_interfaces__srv__GenerateFrame_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__srv__GenerateFrame_Request * msg = (action_interfaces__srv__GenerateFrame_Request *)allocator.allocate(sizeof(action_interfaces__srv__GenerateFrame_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_interfaces__srv__GenerateFrame_Request));
  bool success = action_interfaces__srv__GenerateFrame_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_interfaces__srv__GenerateFrame_Request__destroy(action_interfaces__srv__GenerateFrame_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_interfaces__srv__GenerateFrame_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_interfaces__srv__GenerateFrame_Request__Sequence__init(action_interfaces__srv__GenerateFrame_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__srv__GenerateFrame_Request * data = NULL;

  if (size) {
    data = (action_interfaces__srv__GenerateFrame_Request *)allocator.zero_allocate(size, sizeof(action_interfaces__srv__GenerateFrame_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_interfaces__srv__GenerateFrame_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_interfaces__srv__GenerateFrame_Request__fini(&data[i - 1]);
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
action_interfaces__srv__GenerateFrame_Request__Sequence__fini(action_interfaces__srv__GenerateFrame_Request__Sequence * array)
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
      action_interfaces__srv__GenerateFrame_Request__fini(&array->data[i]);
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

action_interfaces__srv__GenerateFrame_Request__Sequence *
action_interfaces__srv__GenerateFrame_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__srv__GenerateFrame_Request__Sequence * array = (action_interfaces__srv__GenerateFrame_Request__Sequence *)allocator.allocate(sizeof(action_interfaces__srv__GenerateFrame_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_interfaces__srv__GenerateFrame_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_interfaces__srv__GenerateFrame_Request__Sequence__destroy(action_interfaces__srv__GenerateFrame_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_interfaces__srv__GenerateFrame_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_interfaces__srv__GenerateFrame_Request__Sequence__are_equal(const action_interfaces__srv__GenerateFrame_Request__Sequence * lhs, const action_interfaces__srv__GenerateFrame_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_interfaces__srv__GenerateFrame_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_interfaces__srv__GenerateFrame_Request__Sequence__copy(
  const action_interfaces__srv__GenerateFrame_Request__Sequence * input,
  action_interfaces__srv__GenerateFrame_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_interfaces__srv__GenerateFrame_Request);
    action_interfaces__srv__GenerateFrame_Request * data =
      (action_interfaces__srv__GenerateFrame_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_interfaces__srv__GenerateFrame_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_interfaces__srv__GenerateFrame_Request__fini(&data[i]);
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
    if (!action_interfaces__srv__GenerateFrame_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
action_interfaces__srv__GenerateFrame_Response__init(action_interfaces__srv__GenerateFrame_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    action_interfaces__srv__GenerateFrame_Response__fini(msg);
    return false;
  }
  return true;
}

void
action_interfaces__srv__GenerateFrame_Response__fini(action_interfaces__srv__GenerateFrame_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
action_interfaces__srv__GenerateFrame_Response__are_equal(const action_interfaces__srv__GenerateFrame_Response * lhs, const action_interfaces__srv__GenerateFrame_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
action_interfaces__srv__GenerateFrame_Response__copy(
  const action_interfaces__srv__GenerateFrame_Response * input,
  action_interfaces__srv__GenerateFrame_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

action_interfaces__srv__GenerateFrame_Response *
action_interfaces__srv__GenerateFrame_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__srv__GenerateFrame_Response * msg = (action_interfaces__srv__GenerateFrame_Response *)allocator.allocate(sizeof(action_interfaces__srv__GenerateFrame_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_interfaces__srv__GenerateFrame_Response));
  bool success = action_interfaces__srv__GenerateFrame_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_interfaces__srv__GenerateFrame_Response__destroy(action_interfaces__srv__GenerateFrame_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_interfaces__srv__GenerateFrame_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_interfaces__srv__GenerateFrame_Response__Sequence__init(action_interfaces__srv__GenerateFrame_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__srv__GenerateFrame_Response * data = NULL;

  if (size) {
    data = (action_interfaces__srv__GenerateFrame_Response *)allocator.zero_allocate(size, sizeof(action_interfaces__srv__GenerateFrame_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_interfaces__srv__GenerateFrame_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_interfaces__srv__GenerateFrame_Response__fini(&data[i - 1]);
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
action_interfaces__srv__GenerateFrame_Response__Sequence__fini(action_interfaces__srv__GenerateFrame_Response__Sequence * array)
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
      action_interfaces__srv__GenerateFrame_Response__fini(&array->data[i]);
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

action_interfaces__srv__GenerateFrame_Response__Sequence *
action_interfaces__srv__GenerateFrame_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__srv__GenerateFrame_Response__Sequence * array = (action_interfaces__srv__GenerateFrame_Response__Sequence *)allocator.allocate(sizeof(action_interfaces__srv__GenerateFrame_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_interfaces__srv__GenerateFrame_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_interfaces__srv__GenerateFrame_Response__Sequence__destroy(action_interfaces__srv__GenerateFrame_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_interfaces__srv__GenerateFrame_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_interfaces__srv__GenerateFrame_Response__Sequence__are_equal(const action_interfaces__srv__GenerateFrame_Response__Sequence * lhs, const action_interfaces__srv__GenerateFrame_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_interfaces__srv__GenerateFrame_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_interfaces__srv__GenerateFrame_Response__Sequence__copy(
  const action_interfaces__srv__GenerateFrame_Response__Sequence * input,
  action_interfaces__srv__GenerateFrame_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_interfaces__srv__GenerateFrame_Response);
    action_interfaces__srv__GenerateFrame_Response * data =
      (action_interfaces__srv__GenerateFrame_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_interfaces__srv__GenerateFrame_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_interfaces__srv__GenerateFrame_Response__fini(&data[i]);
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
    if (!action_interfaces__srv__GenerateFrame_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
