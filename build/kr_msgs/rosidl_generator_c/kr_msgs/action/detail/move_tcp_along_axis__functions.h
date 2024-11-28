// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from kr_msgs:action/MoveTCPAlongAxis.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__FUNCTIONS_H_
#define KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "kr_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "kr_msgs/action/detail/move_tcp_along_axis__struct.h"

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_Goal
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Goal__init(kr_msgs__action__MoveTCPAlongAxis_Goal * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Goal__fini(kr_msgs__action__MoveTCPAlongAxis_Goal * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_Goal *
kr_msgs__action__MoveTCPAlongAxis_Goal__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Goal__destroy(kr_msgs__action__MoveTCPAlongAxis_Goal * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Goal__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Goal * lhs, const kr_msgs__action__MoveTCPAlongAxis_Goal * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_Goal__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Goal * input,
  kr_msgs__action__MoveTCPAlongAxis_Goal * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence *
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_Goal__Sequence * output);

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_Result
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Result__init(kr_msgs__action__MoveTCPAlongAxis_Result * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Result__fini(kr_msgs__action__MoveTCPAlongAxis_Result * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_Result *
kr_msgs__action__MoveTCPAlongAxis_Result__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Result__destroy(kr_msgs__action__MoveTCPAlongAxis_Result * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Result__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Result * lhs, const kr_msgs__action__MoveTCPAlongAxis_Result * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_Result__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Result * input,
  kr_msgs__action__MoveTCPAlongAxis_Result * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence *
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_Result__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_Result__Sequence * output);

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_Feedback
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__init(kr_msgs__action__MoveTCPAlongAxis_Feedback * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Feedback__fini(kr_msgs__action__MoveTCPAlongAxis_Feedback * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_Feedback *
kr_msgs__action__MoveTCPAlongAxis_Feedback__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Feedback__destroy(kr_msgs__action__MoveTCPAlongAxis_Feedback * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Feedback * lhs, const kr_msgs__action__MoveTCPAlongAxis_Feedback * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_Feedback__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Feedback * input,
  kr_msgs__action__MoveTCPAlongAxis_Feedback * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence *
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_Feedback__Sequence * output);

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Request__Sequence * output);

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence *
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_SendGoal_Response__Sequence * output);

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Request__Sequence * output);

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence *
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_GetResult_Response__Sequence * output);

/// Initialize action/MoveTCPAlongAxis message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage
 * )) before or use
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * msg);

/// Finalize action/MoveTCPAlongAxis message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * msg);

/// Create action/MoveTCPAlongAxis message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage *
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__create();

/// Destroy action/MoveTCPAlongAxis message.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__destroy(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * msg);

/// Check for action/MoveTCPAlongAxis message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__are_equal(const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * lhs, const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * rhs);

/// Copy a action/MoveTCPAlongAxis message.
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
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__copy(
  const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * input,
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage * output);

/// Initialize array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the number of elements and calls
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__init(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__fini(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * array);

/// Create array of action/MoveTCPAlongAxis messages.
/**
 * It allocates the memory for the array and calls
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence *
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/MoveTCPAlongAxis messages.
/**
 * It calls
 * kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
void
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__destroy(kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * array);

/// Check for action/MoveTCPAlongAxis message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kr_msgs
bool
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__are_equal(const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * lhs, const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/MoveTCPAlongAxis messages.
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
kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence__copy(
  const kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * input,
  kr_msgs__action__MoveTCPAlongAxis_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__ACTION__DETAIL__MOVE_TCP_ALONG_AXIS__FUNCTIONS_H_
