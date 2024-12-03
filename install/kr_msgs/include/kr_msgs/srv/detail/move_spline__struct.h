// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kr_msgs:srv/MoveSpline.idl
// generated code does not contain a copyright notice

#ifndef KR_MSGS__SRV__DETAIL__MOVE_SPLINE__STRUCT_H_
#define KR_MSGS__SRV__DETAIL__MOVE_SPLINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'WORLD'.
enum
{
  kr_msgs__srv__MoveSpline_Request__WORLD = 0
};

/// Constant 'BASE'.
enum
{
  kr_msgs__srv__MoveSpline_Request__BASE = 1
};

/// Constant 'TCP'.
enum
{
  kr_msgs__srv__MoveSpline_Request__TCP = 2
};

/// Constant 'TT_VEL'.
enum
{
  kr_msgs__srv__MoveSpline_Request__TT_VEL = 0
};

/// Constant 'TT_TIME'.
enum
{
  kr_msgs__srv__MoveSpline_Request__TT_TIME = 1
};

/// Constant 'BP_STOP'.
enum
{
  kr_msgs__srv__MoveSpline_Request__BP_STOP = 0
};

/// Constant 'BP_VIA'.
enum
{
  kr_msgs__srv__MoveSpline_Request__BP_VIA = 1
};

/// Constant 'BT_ACC'.
enum
{
  kr_msgs__srv__MoveSpline_Request__BT_ACC = 0
};

/// Constant 'SO_FIXED'.
enum
{
  kr_msgs__srv__MoveSpline_Request__SO_FIXED = 0
};

/// Constant 'SO_TAN_X'.
enum
{
  kr_msgs__srv__MoveSpline_Request__SO_TAN_X = 1
};

/// Constant 'SO_TAN_Z'.
enum
{
  kr_msgs__srv__MoveSpline_Request__SO_TAN_Z = 2
};

// Struct defined in srv/MoveSpline in the package kr_msgs.
typedef struct kr_msgs__srv__MoveSpline_Request
{
  double pos[3];
  double rot[3];
  int8_t ref;
  int8_t ttype;
  double tvalue;
  int8_t bpoint;
  int8_t btype;
  double bvalue;
  double sync;
  int8_t orient;
  int8_t horizon;
} kr_msgs__srv__MoveSpline_Request;

// Struct for a sequence of kr_msgs__srv__MoveSpline_Request.
typedef struct kr_msgs__srv__MoveSpline_Request__Sequence
{
  kr_msgs__srv__MoveSpline_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__MoveSpline_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/MoveSpline in the package kr_msgs.
typedef struct kr_msgs__srv__MoveSpline_Response
{
  bool success;
} kr_msgs__srv__MoveSpline_Response;

// Struct for a sequence of kr_msgs__srv__MoveSpline_Response.
typedef struct kr_msgs__srv__MoveSpline_Response__Sequence
{
  kr_msgs__srv__MoveSpline_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kr_msgs__srv__MoveSpline_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KR_MSGS__SRV__DETAIL__MOVE_SPLINE__STRUCT_H_
