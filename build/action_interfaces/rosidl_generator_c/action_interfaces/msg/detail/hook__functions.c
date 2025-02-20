// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice
#include "action_interfaces/msg/detail/hook__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `hook_box`
// Member `tip_box`
// Member `lowpoint_box`
#include "action_interfaces/msg/detail/bounding_box__functions.h"
// Member `hook_mask`
// Member `tip_mask`
// Member `lowpoint_mask`
// Member `skeleton_mask`
#include "sensor_msgs/msg/detail/image__functions.h"
// Member `uv_hook`
// Member `uv_tip`
// Member `uv_lowpoint`
// Member `shortest_path`
// Member `path_points`
#include "action_interfaces/msg/detail/uv__functions.h"

bool
action_interfaces__msg__Hook__init(action_interfaces__msg__Hook * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // hook_box
  if (!action_interfaces__msg__BoundingBox__init(&msg->hook_box)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // tip_box
  if (!action_interfaces__msg__BoundingBox__init(&msg->tip_box)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // lowpoint_box
  if (!action_interfaces__msg__BoundingBox__init(&msg->lowpoint_box)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // hook_mask
  if (!sensor_msgs__msg__Image__init(&msg->hook_mask)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // tip_mask
  if (!sensor_msgs__msg__Image__init(&msg->tip_mask)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // lowpoint_mask
  if (!sensor_msgs__msg__Image__init(&msg->lowpoint_mask)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // skeleton_mask
  if (!sensor_msgs__msg__Image__init(&msg->skeleton_mask)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // conf_hook
  // conf_tip
  // conf_lowpoint
  // uv_hook
  if (!action_interfaces__msg__UV__init(&msg->uv_hook)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // uv_tip
  if (!action_interfaces__msg__UV__init(&msg->uv_tip)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // uv_lowpoint
  if (!action_interfaces__msg__UV__init(&msg->uv_lowpoint)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // shortest_path
  if (!action_interfaces__msg__UV__Sequence__init(&msg->shortest_path, 0)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  // path_points
  if (!action_interfaces__msg__UV__Sequence__init(&msg->path_points, 0)) {
    action_interfaces__msg__Hook__fini(msg);
    return false;
  }
  return true;
}

void
action_interfaces__msg__Hook__fini(action_interfaces__msg__Hook * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // hook_box
  action_interfaces__msg__BoundingBox__fini(&msg->hook_box);
  // tip_box
  action_interfaces__msg__BoundingBox__fini(&msg->tip_box);
  // lowpoint_box
  action_interfaces__msg__BoundingBox__fini(&msg->lowpoint_box);
  // hook_mask
  sensor_msgs__msg__Image__fini(&msg->hook_mask);
  // tip_mask
  sensor_msgs__msg__Image__fini(&msg->tip_mask);
  // lowpoint_mask
  sensor_msgs__msg__Image__fini(&msg->lowpoint_mask);
  // skeleton_mask
  sensor_msgs__msg__Image__fini(&msg->skeleton_mask);
  // conf_hook
  // conf_tip
  // conf_lowpoint
  // uv_hook
  action_interfaces__msg__UV__fini(&msg->uv_hook);
  // uv_tip
  action_interfaces__msg__UV__fini(&msg->uv_tip);
  // uv_lowpoint
  action_interfaces__msg__UV__fini(&msg->uv_lowpoint);
  // shortest_path
  action_interfaces__msg__UV__Sequence__fini(&msg->shortest_path);
  // path_points
  action_interfaces__msg__UV__Sequence__fini(&msg->path_points);
}

bool
action_interfaces__msg__Hook__are_equal(const action_interfaces__msg__Hook * lhs, const action_interfaces__msg__Hook * rhs)
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
  // hook_box
  if (!action_interfaces__msg__BoundingBox__are_equal(
      &(lhs->hook_box), &(rhs->hook_box)))
  {
    return false;
  }
  // tip_box
  if (!action_interfaces__msg__BoundingBox__are_equal(
      &(lhs->tip_box), &(rhs->tip_box)))
  {
    return false;
  }
  // lowpoint_box
  if (!action_interfaces__msg__BoundingBox__are_equal(
      &(lhs->lowpoint_box), &(rhs->lowpoint_box)))
  {
    return false;
  }
  // hook_mask
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->hook_mask), &(rhs->hook_mask)))
  {
    return false;
  }
  // tip_mask
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->tip_mask), &(rhs->tip_mask)))
  {
    return false;
  }
  // lowpoint_mask
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->lowpoint_mask), &(rhs->lowpoint_mask)))
  {
    return false;
  }
  // skeleton_mask
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->skeleton_mask), &(rhs->skeleton_mask)))
  {
    return false;
  }
  // conf_hook
  if (lhs->conf_hook != rhs->conf_hook) {
    return false;
  }
  // conf_tip
  if (lhs->conf_tip != rhs->conf_tip) {
    return false;
  }
  // conf_lowpoint
  if (lhs->conf_lowpoint != rhs->conf_lowpoint) {
    return false;
  }
  // uv_hook
  if (!action_interfaces__msg__UV__are_equal(
      &(lhs->uv_hook), &(rhs->uv_hook)))
  {
    return false;
  }
  // uv_tip
  if (!action_interfaces__msg__UV__are_equal(
      &(lhs->uv_tip), &(rhs->uv_tip)))
  {
    return false;
  }
  // uv_lowpoint
  if (!action_interfaces__msg__UV__are_equal(
      &(lhs->uv_lowpoint), &(rhs->uv_lowpoint)))
  {
    return false;
  }
  // shortest_path
  if (!action_interfaces__msg__UV__Sequence__are_equal(
      &(lhs->shortest_path), &(rhs->shortest_path)))
  {
    return false;
  }
  // path_points
  if (!action_interfaces__msg__UV__Sequence__are_equal(
      &(lhs->path_points), &(rhs->path_points)))
  {
    return false;
  }
  return true;
}

bool
action_interfaces__msg__Hook__copy(
  const action_interfaces__msg__Hook * input,
  action_interfaces__msg__Hook * output)
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
  // hook_box
  if (!action_interfaces__msg__BoundingBox__copy(
      &(input->hook_box), &(output->hook_box)))
  {
    return false;
  }
  // tip_box
  if (!action_interfaces__msg__BoundingBox__copy(
      &(input->tip_box), &(output->tip_box)))
  {
    return false;
  }
  // lowpoint_box
  if (!action_interfaces__msg__BoundingBox__copy(
      &(input->lowpoint_box), &(output->lowpoint_box)))
  {
    return false;
  }
  // hook_mask
  if (!sensor_msgs__msg__Image__copy(
      &(input->hook_mask), &(output->hook_mask)))
  {
    return false;
  }
  // tip_mask
  if (!sensor_msgs__msg__Image__copy(
      &(input->tip_mask), &(output->tip_mask)))
  {
    return false;
  }
  // lowpoint_mask
  if (!sensor_msgs__msg__Image__copy(
      &(input->lowpoint_mask), &(output->lowpoint_mask)))
  {
    return false;
  }
  // skeleton_mask
  if (!sensor_msgs__msg__Image__copy(
      &(input->skeleton_mask), &(output->skeleton_mask)))
  {
    return false;
  }
  // conf_hook
  output->conf_hook = input->conf_hook;
  // conf_tip
  output->conf_tip = input->conf_tip;
  // conf_lowpoint
  output->conf_lowpoint = input->conf_lowpoint;
  // uv_hook
  if (!action_interfaces__msg__UV__copy(
      &(input->uv_hook), &(output->uv_hook)))
  {
    return false;
  }
  // uv_tip
  if (!action_interfaces__msg__UV__copy(
      &(input->uv_tip), &(output->uv_tip)))
  {
    return false;
  }
  // uv_lowpoint
  if (!action_interfaces__msg__UV__copy(
      &(input->uv_lowpoint), &(output->uv_lowpoint)))
  {
    return false;
  }
  // shortest_path
  if (!action_interfaces__msg__UV__Sequence__copy(
      &(input->shortest_path), &(output->shortest_path)))
  {
    return false;
  }
  // path_points
  if (!action_interfaces__msg__UV__Sequence__copy(
      &(input->path_points), &(output->path_points)))
  {
    return false;
  }
  return true;
}

action_interfaces__msg__Hook *
action_interfaces__msg__Hook__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__Hook * msg = (action_interfaces__msg__Hook *)allocator.allocate(sizeof(action_interfaces__msg__Hook), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_interfaces__msg__Hook));
  bool success = action_interfaces__msg__Hook__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_interfaces__msg__Hook__destroy(action_interfaces__msg__Hook * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_interfaces__msg__Hook__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_interfaces__msg__Hook__Sequence__init(action_interfaces__msg__Hook__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__Hook * data = NULL;

  if (size) {
    data = (action_interfaces__msg__Hook *)allocator.zero_allocate(size, sizeof(action_interfaces__msg__Hook), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_interfaces__msg__Hook__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_interfaces__msg__Hook__fini(&data[i - 1]);
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
action_interfaces__msg__Hook__Sequence__fini(action_interfaces__msg__Hook__Sequence * array)
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
      action_interfaces__msg__Hook__fini(&array->data[i]);
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

action_interfaces__msg__Hook__Sequence *
action_interfaces__msg__Hook__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__Hook__Sequence * array = (action_interfaces__msg__Hook__Sequence *)allocator.allocate(sizeof(action_interfaces__msg__Hook__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_interfaces__msg__Hook__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_interfaces__msg__Hook__Sequence__destroy(action_interfaces__msg__Hook__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_interfaces__msg__Hook__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_interfaces__msg__Hook__Sequence__are_equal(const action_interfaces__msg__Hook__Sequence * lhs, const action_interfaces__msg__Hook__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_interfaces__msg__Hook__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_interfaces__msg__Hook__Sequence__copy(
  const action_interfaces__msg__Hook__Sequence * input,
  action_interfaces__msg__Hook__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_interfaces__msg__Hook);
    action_interfaces__msg__Hook * data =
      (action_interfaces__msg__Hook *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_interfaces__msg__Hook__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_interfaces__msg__Hook__fini(&data[i]);
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
    if (!action_interfaces__msg__Hook__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
