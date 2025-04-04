// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from action_interfaces:msg/UV.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__UV__FUNCTIONS_H_
#define ACTION_INTERFACES__MSG__DETAIL__UV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "action_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "action_interfaces/msg/detail/uv__struct.h"

/// Initialize msg/UV message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__msg__UV
 * )) before or use
 * action_interfaces__msg__UV__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__UV__init(action_interfaces__msg__UV * msg);

/// Finalize msg/UV message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__UV__fini(action_interfaces__msg__UV * msg);

/// Create msg/UV message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__msg__UV__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__msg__UV *
action_interfaces__msg__UV__create();

/// Destroy msg/UV message.
/**
 * It calls
 * action_interfaces__msg__UV__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__UV__destroy(action_interfaces__msg__UV * msg);

/// Check for msg/UV message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__UV__are_equal(const action_interfaces__msg__UV * lhs, const action_interfaces__msg__UV * rhs);

/// Copy a msg/UV message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__UV__copy(
  const action_interfaces__msg__UV * input,
  action_interfaces__msg__UV * output);

/// Initialize array of msg/UV messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__msg__UV__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__UV__Sequence__init(action_interfaces__msg__UV__Sequence * array, size_t size);

/// Finalize array of msg/UV messages.
/**
 * It calls
 * action_interfaces__msg__UV__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__UV__Sequence__fini(action_interfaces__msg__UV__Sequence * array);

/// Create array of msg/UV messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__msg__UV__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__msg__UV__Sequence *
action_interfaces__msg__UV__Sequence__create(size_t size);

/// Destroy array of msg/UV messages.
/**
 * It calls
 * action_interfaces__msg__UV__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__UV__Sequence__destroy(action_interfaces__msg__UV__Sequence * array);

/// Check for msg/UV message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__UV__Sequence__are_equal(const action_interfaces__msg__UV__Sequence * lhs, const action_interfaces__msg__UV__Sequence * rhs);

/// Copy an array of msg/UV messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__UV__Sequence__copy(
  const action_interfaces__msg__UV__Sequence * input,
  action_interfaces__msg__UV__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__UV__FUNCTIONS_H_
