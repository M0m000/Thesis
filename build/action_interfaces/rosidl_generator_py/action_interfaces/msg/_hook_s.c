// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from action_interfaces:msg/Hook.idl
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
#include "action_interfaces/msg/detail/hook__struct.h"
#include "action_interfaces/msg/detail/hook__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool action_interfaces__msg__bounding_box__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * action_interfaces__msg__bounding_box__convert_to_py(void * raw_ros_message);
bool action_interfaces__msg__bounding_box__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * action_interfaces__msg__bounding_box__convert_to_py(void * raw_ros_message);
bool action_interfaces__msg__bounding_box__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * action_interfaces__msg__bounding_box__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
bool action_interfaces__msg__uv__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * action_interfaces__msg__uv__convert_to_py(void * raw_ros_message);
bool action_interfaces__msg__uv__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * action_interfaces__msg__uv__convert_to_py(void * raw_ros_message);
bool action_interfaces__msg__uv__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * action_interfaces__msg__uv__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool action_interfaces__msg__hook__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
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
    assert(strncmp("action_interfaces.msg._hook.Hook", full_classname_dest, 32) == 0);
  }
  action_interfaces__msg__Hook * ros_message = _ros_message;
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // hook_box
    PyObject * field = PyObject_GetAttrString(_pymsg, "hook_box");
    if (!field) {
      return false;
    }
    if (!action_interfaces__msg__bounding_box__convert_from_py(field, &ros_message->hook_box)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // tip_box
    PyObject * field = PyObject_GetAttrString(_pymsg, "tip_box");
    if (!field) {
      return false;
    }
    if (!action_interfaces__msg__bounding_box__convert_from_py(field, &ros_message->tip_box)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // lowpoint_box
    PyObject * field = PyObject_GetAttrString(_pymsg, "lowpoint_box");
    if (!field) {
      return false;
    }
    if (!action_interfaces__msg__bounding_box__convert_from_py(field, &ros_message->lowpoint_box)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // hook_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "hook_mask");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->hook_mask)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // tip_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "tip_mask");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->tip_mask)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // lowpoint_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "lowpoint_mask");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->lowpoint_mask)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // conf_hook
    PyObject * field = PyObject_GetAttrString(_pymsg, "conf_hook");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->conf_hook = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // conf_tip
    PyObject * field = PyObject_GetAttrString(_pymsg, "conf_tip");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->conf_tip = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // conf_lowpoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "conf_lowpoint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->conf_lowpoint = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // uv_hook
    PyObject * field = PyObject_GetAttrString(_pymsg, "uv_hook");
    if (!field) {
      return false;
    }
    if (!action_interfaces__msg__uv__convert_from_py(field, &ros_message->uv_hook)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // uv_tip
    PyObject * field = PyObject_GetAttrString(_pymsg, "uv_tip");
    if (!field) {
      return false;
    }
    if (!action_interfaces__msg__uv__convert_from_py(field, &ros_message->uv_tip)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // uv_lowpoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "uv_lowpoint");
    if (!field) {
      return false;
    }
    if (!action_interfaces__msg__uv__convert_from_py(field, &ros_message->uv_lowpoint)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * action_interfaces__msg__hook__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Hook */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("action_interfaces.msg._hook");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Hook");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  action_interfaces__msg__Hook * ros_message = (action_interfaces__msg__Hook *)raw_ros_message;
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hook_box
    PyObject * field = NULL;
    field = action_interfaces__msg__bounding_box__convert_to_py(&ros_message->hook_box);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "hook_box", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tip_box
    PyObject * field = NULL;
    field = action_interfaces__msg__bounding_box__convert_to_py(&ros_message->tip_box);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tip_box", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lowpoint_box
    PyObject * field = NULL;
    field = action_interfaces__msg__bounding_box__convert_to_py(&ros_message->lowpoint_box);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "lowpoint_box", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hook_mask
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->hook_mask);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "hook_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tip_mask
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->tip_mask);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tip_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lowpoint_mask
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->lowpoint_mask);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "lowpoint_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // conf_hook
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->conf_hook);
    {
      int rc = PyObject_SetAttrString(_pymessage, "conf_hook", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // conf_tip
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->conf_tip);
    {
      int rc = PyObject_SetAttrString(_pymessage, "conf_tip", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // conf_lowpoint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->conf_lowpoint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "conf_lowpoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // uv_hook
    PyObject * field = NULL;
    field = action_interfaces__msg__uv__convert_to_py(&ros_message->uv_hook);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "uv_hook", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // uv_tip
    PyObject * field = NULL;
    field = action_interfaces__msg__uv__convert_to_py(&ros_message->uv_tip);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "uv_tip", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // uv_lowpoint
    PyObject * field = NULL;
    field = action_interfaces__msg__uv__convert_to_py(&ros_message->uv_lowpoint);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "uv_lowpoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
