// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from action_interfaces:msg/Hook.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__HOOK__FUNCTIONS_H_
#define ACTION_INTERFACES__MSG__DETAIL__HOOK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "action_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "action_interfaces/msg/detail/hook__struct.h"

/// Initialize msg/Hook message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__msg__Hook
 * )) before or use
 * action_interfaces__msg__Hook__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__Hook__init(action_interfaces__msg__Hook * msg);

/// Finalize msg/Hook message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__Hook__fini(action_interfaces__msg__Hook * msg);

/// Create msg/Hook message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__msg__Hook__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__msg__Hook *
action_interfaces__msg__Hook__create();

/// Destroy msg/Hook message.
/**
 * It calls
 * action_interfaces__msg__Hook__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__Hook__destroy(action_interfaces__msg__Hook * msg);

/// Check for msg/Hook message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__Hook__are_equal(const action_interfaces__msg__Hook * lhs, const action_interfaces__msg__Hook * rhs);

/// Copy a msg/Hook message.
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
action_interfaces__msg__Hook__copy(
  const action_interfaces__msg__Hook * input,
  action_interfaces__msg__Hook * output);

/// Initialize array of msg/Hook messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__msg__Hook__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__Hook__Sequence__init(action_interfaces__msg__Hook__Sequence * array, size_t size);

/// Finalize array of msg/Hook messages.
/**
 * It calls
 * action_interfaces__msg__Hook__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__Hook__Sequence__fini(action_interfaces__msg__Hook__Sequence * array);

/// Create array of msg/Hook messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__msg__Hook__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__msg__Hook__Sequence *
action_interfaces__msg__Hook__Sequence__create(size_t size);

/// Destroy array of msg/Hook messages.
/**
 * It calls
 * action_interfaces__msg__Hook__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__msg__Hook__Sequence__destroy(action_interfaces__msg__Hook__Sequence * array);

/// Check for msg/Hook message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__msg__Hook__Sequence__are_equal(const action_interfaces__msg__Hook__Sequence * lhs, const action_interfaces__msg__Hook__Sequence * rhs);

/// Copy an array of msg/Hook messages.
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
action_interfaces__msg__Hook__Sequence__copy(
  const action_interfaces__msg__Hook__Sequence * input,
  action_interfaces__msg__Hook__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__HOOK__FUNCTIONS_H_
