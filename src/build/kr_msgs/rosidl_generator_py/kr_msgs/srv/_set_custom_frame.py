# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:srv/SetCustomFrame.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'pos'
# Member 'rot'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetCustomFrame_Request(type):
    """Metaclass of message 'SetCustomFrame_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kr_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kr_msgs.srv.SetCustomFrame_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_custom_frame__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_custom_frame__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_custom_frame__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_custom_frame__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_custom_frame__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetCustomFrame_Request(metaclass=Metaclass_SetCustomFrame_Request):
    """Message class 'SetCustomFrame_Request'."""

    __slots__ = [
        '_ref',
        '_pos',
        '_rot',
    ]

    _fields_and_field_types = {
        'ref': 'int8',
        'pos': 'double[3]',
        'rot': 'double[3]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ref = kwargs.get('ref', int())
        if 'pos' not in kwargs:
            self.pos = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.pos = numpy.array(kwargs.get('pos'), dtype=numpy.float64)
            assert self.pos.shape == (3, )
        if 'rot' not in kwargs:
            self.rot = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.rot = numpy.array(kwargs.get('rot'), dtype=numpy.float64)
            assert self.rot.shape == (3, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.ref != other.ref:
            return False
        if all(self.pos != other.pos):
            return False
        if all(self.rot != other.rot):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def ref(self):
        """Message field 'ref'."""
        return self._ref

    @ref.setter
    def ref(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ref' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ref' field must be an integer in [-128, 127]"
        self._ref = value

    @property
    def pos(self):
        """Message field 'pos'."""
        return self._pos

    @pos.setter
    def pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'pos' numpy.ndarray() must have a size of 3"
            self._pos = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'pos' field must be a set or sequence with length 3 and each value of type 'float'"
        self._pos = numpy.array(value, dtype=numpy.float64)

    @property
    def rot(self):
        """Message field 'rot'."""
        return self._rot

    @rot.setter
    def rot(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'rot' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'rot' numpy.ndarray() must have a size of 3"
            self._rot = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'rot' field must be a set or sequence with length 3 and each value of type 'float'"
        self._rot = numpy.array(value, dtype=numpy.float64)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SetCustomFrame_Response(type):
    """Metaclass of message 'SetCustomFrame_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kr_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kr_msgs.srv.SetCustomFrame_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_custom_frame__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_custom_frame__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_custom_frame__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_custom_frame__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_custom_frame__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetCustomFrame_Response(metaclass=Metaclass_SetCustomFrame_Response):
    """Message class 'SetCustomFrame_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_SetCustomFrame(type):
    """Metaclass of service 'SetCustomFrame'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kr_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kr_msgs.srv.SetCustomFrame')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_custom_frame

            from kr_msgs.srv import _set_custom_frame
            if _set_custom_frame.Metaclass_SetCustomFrame_Request._TYPE_SUPPORT is None:
                _set_custom_frame.Metaclass_SetCustomFrame_Request.__import_type_support__()
            if _set_custom_frame.Metaclass_SetCustomFrame_Response._TYPE_SUPPORT is None:
                _set_custom_frame.Metaclass_SetCustomFrame_Response.__import_type_support__()


class SetCustomFrame(metaclass=Metaclass_SetCustomFrame):
    from kr_msgs.srv._set_custom_frame import SetCustomFrame_Request as Request
    from kr_msgs.srv._set_custom_frame import SetCustomFrame_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')