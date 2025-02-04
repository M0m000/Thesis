// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from kr_msgs:msg/FollowLinear.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__FUNCTIONS_H_
#define KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "kr_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "kr_msgs/msg/detail/follow_linear__struct.h"

/// Initialize msg/FollowLinear message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__msg__FollowLinear
 * )) before or use
 * kr_msgs__msg__FollowLinear__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__msg__FollowLinear__init(kr_msgs__msg__FollowLinear * msg);

/// Finalize msg/FollowLinear message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__msg__FollowLinear__fini(kr_msgs__msg__FollowLinear * msg);

/// Create msg/FollowLinear message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__msg__FollowLinear__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__msg__FollowLinear *
kr_msgs__msg__FollowLinear__create();

/// Destroy msg/FollowLinear message.
/**
 * It calls
 * kr_msgs__msg__FollowLinear__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__msg__FollowLinear__destroy(kr_msgs__msg__FollowLinear * msg);

/// Check for msg/FollowLinear message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__msg__FollowLinear__are_equal(const kr_msgs__msg__FollowLinear * lhs, const kr_msgs__msg__FollowLinear * rhs);

/// Copy a msg/FollowLinear message.
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
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__msg__FollowLinear__copy(
  const kr_msgs__msg__FollowLinear * input,
  kr_msgs__msg__FollowLinear * output);

/// Initialize array of msg/FollowLinear messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__msg__FollowLinear__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__msg__FollowLinear__Sequence__init(kr_msgs__msg__FollowLinear__Sequence * array, size_t size);

/// Finalize array of msg/FollowLinear messages.
/**
 * It calls
 * kr_msgs__msg__FollowLinear__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__msg__FollowLinear__Sequence__fini(kr_msgs__msg__FollowLinear__Sequence * array);

/// Create array of msg/FollowLinear messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__msg__FollowLinear__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__msg__FollowLinear__Sequence *
kr_msgs__msg__FollowLinear__Sequence__create(size_t size);

/// Destroy array of msg/FollowLinear messages.
/**
 * It calls
 * kr_msgs__msg__FollowLinear__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__msg__FollowLinear__Sequence__destroy(kr_msgs__msg__FollowLinear__Sequence * array);

/// Check for msg/FollowLinear message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__msg__FollowLinear__Sequence__are_equal(const kr_msgs__msg__FollowLinear__Sequence * lhs, const kr_msgs__msg__FollowLinear__Sequence * rhs);

/// Copy an array of msg/FollowLinear messages.
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
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__msg__FollowLinear__Sequence__copy(
  const kr_msgs__msg__FollowLinear__Sequence * input,
  kr_msgs__msg__FollowLinear__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__MSG__DETAIL__FOLLOW_LINEAR__FUNCTIONS_H_
