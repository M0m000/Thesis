// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from kr_msgs:msg/Quadrature.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "kr_msgs/msg/detail/quadrature__struct.h"
#include "kr_msgs/msg/detail/quadrature__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool kr_msgs__msg__quadrature__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("kr_msgs.msg._quadrature.Quadrature", full_classname_dest, 34) == 0);
  }
  kr_msgs__msg__Quadrature * ros_message = _ros_message;
  {  // direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "direction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->direction = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pulse_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "pulse_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pulse_count = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // frequency
    PyObject * field = PyObject_GetAttrString(_pymsg, "frequency");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->frequency = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // abs_pulse_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "abs_pulse_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->abs_pulse_count = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pulse_per_sec
    PyObject * field = PyObject_GetAttrString(_pymsg, "pulse_per_sec");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pulse_per_sec = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * kr_msgs__msg__quadrature__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Quadrature */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("kr_msgs.msg._quadrature");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Quadrature");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  kr_msgs__msg__Quadrature * ros_message = (kr_msgs__msg__Quadrature *)raw_ros_message;
  {  // direction
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->direction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pulse_count
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pulse_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pulse_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frequency
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->frequency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frequency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // abs_pulse_count
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->abs_pulse_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "abs_pulse_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pulse_per_sec
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pulse_per_sec);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pulse_per_sec", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
