# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:srv/GetSystemLoad.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetSystemLoad_Request(type):
    """Metaclass of message 'GetSystemLoad_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TOOLLOAD': 'toolload',
        'PAYLOAD': 'payload',
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
                'kr_msgs.srv.GetSystemLoad_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_system_load__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_system_load__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_system_load__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_system_load__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_system_load__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TOOLLOAD': cls.__constants['TOOLLOAD'],
            'PAYLOAD': cls.__constants['PAYLOAD'],
        }

    @property
    def TOOLLOAD(self):
        """Message constant 'TOOLLOAD'."""
        return Metaclass_GetSystemLoad_Request.__constants['TOOLLOAD']

    @property
    def PAYLOAD(self):
        """Message constant 'PAYLOAD'."""
        return Metaclass_GetSystemLoad_Request.__constants['PAYLOAD']


class GetSystemLoad_Request(metaclass=Metaclass_GetSystemLoad_Request):
    """
    Message class 'GetSystemLoad_Request'.

    Constants:
      TOOLLOAD
      PAYLOAD
    """

    __slots__ = [
        '_name',
    ]

    _fields_and_field_types = {
        'name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())

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
        if self.name != other.name:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value


# Import statements for member types

# Member 'cog'
# Member 'imx'
import numpy  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GetSystemLoad_Response(type):
    """Metaclass of message 'GetSystemLoad_Response'."""

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
                'kr_msgs.srv.GetSystemLoad_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_system_load__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_system_load__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_system_load__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_system_load__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_system_load__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetSystemLoad_Response(metaclass=Metaclass_GetSystemLoad_Response):
    """Message class 'GetSystemLoad_Response'."""

    __slots__ = [
        '_mass',
        '_cog',
        '_imx',
        '_success',
    ]

    _fields_and_field_types = {
        'mass': 'double',
        'cog': 'double[3]',
        'imx': 'double[6]',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mass = kwargs.get('mass', float())
        if 'cog' not in kwargs:
            self.cog = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.cog = numpy.array(kwargs.get('cog'), dtype=numpy.float64)
            assert self.cog.shape == (3, )
        if 'imx' not in kwargs:
            self.imx = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.imx = numpy.array(kwargs.get('imx'), dtype=numpy.float64)
            assert self.imx.shape == (6, )
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
        if self.mass != other.mass:
            return False
        if all(self.cog != other.cog):
            return False
        if all(self.imx != other.imx):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def mass(self):
        """Message field 'mass'."""
        return self._mass

    @mass.setter
    def mass(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'mass' field must be of type 'float'"
        self._mass = value

    @property
    def cog(self):
        """Message field 'cog'."""
        return self._cog

    @cog.setter
    def cog(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'cog' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'cog' numpy.ndarray() must have a size of 3"
            self._cog = value
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
                "The 'cog' field must be a set or sequence with length 3 and each value of type 'float'"
        self._cog = numpy.array(value, dtype=numpy.float64)

    @property
    def imx(self):
        """Message field 'imx'."""
        return self._imx

    @imx.setter
    def imx(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'imx' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'imx' numpy.ndarray() must have a size of 6"
            self._imx = value
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
                 len(value) == 6 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'imx' field must be a set or sequence with length 6 and each value of type 'float'"
        self._imx = numpy.array(value, dtype=numpy.float64)

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


class Metaclass_GetSystemLoad(type):
    """Metaclass of service 'GetSystemLoad'."""

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
                'kr_msgs.srv.GetSystemLoad')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_system_load

            from kr_msgs.srv import _get_system_load
            if _get_system_load.Metaclass_GetSystemLoad_Request._TYPE_SUPPORT is None:
                _get_system_load.Metaclass_GetSystemLoad_Request.__import_type_support__()
            if _get_system_load.Metaclass_GetSystemLoad_Response._TYPE_SUPPORT is None:
                _get_system_load.Metaclass_GetSystemLoad_Response.__import_type_support__()


class GetSystemLoad(metaclass=Metaclass_GetSystemLoad):
    from kr_msgs.srv._get_system_load import GetSystemLoad_Request as Request
    from kr_msgs.srv._get_system_load import GetSystemLoad_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
