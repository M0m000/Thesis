# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:msg/SafetyZone.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'sensitivity'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SafetyZone(type):
    """Metaclass of message 'SafetyZone'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SDIO01': 1,
        'SDIO02': 2,
        'SDIO03': 3,
        'SDIO04': 4,
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
                'kr_msgs.msg.SafetyZone')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__safety_zone
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__safety_zone
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__safety_zone
            cls._TYPE_SUPPORT = module.type_support_msg__msg__safety_zone
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__safety_zone

            from kr_msgs.msg import GeometryPlane
            if GeometryPlane.__class__._TYPE_SUPPORT is None:
                GeometryPlane.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SDIO01': cls.__constants['SDIO01'],
            'SDIO02': cls.__constants['SDIO02'],
            'SDIO03': cls.__constants['SDIO03'],
            'SDIO04': cls.__constants['SDIO04'],
        }

    @property
    def SDIO01(self):
        """Message constant 'SDIO01'."""
        return Metaclass_SafetyZone.__constants['SDIO01']

    @property
    def SDIO02(self):
        """Message constant 'SDIO02'."""
        return Metaclass_SafetyZone.__constants['SDIO02']

    @property
    def SDIO03(self):
        """Message constant 'SDIO03'."""
        return Metaclass_SafetyZone.__constants['SDIO03']

    @property
    def SDIO04(self):
        """Message constant 'SDIO04'."""
        return Metaclass_SafetyZone.__constants['SDIO04']


class SafetyZone(metaclass=Metaclass_SafetyZone):
    """
    Message class 'SafetyZone'.

    Constants:
      SDIO01
      SDIO02
      SDIO03
      SDIO04
    """

    __slots__ = [
        '_name',
        '_speed',
        '_buffer',
        '_sensitivity',
        '_safety_io',
        '_planes',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'speed': 'double',
        'buffer': 'double',
        'sensitivity': 'double[7]',
        'safety_io': 'int8',
        'planes': 'sequence<kr_msgs/GeometryPlane>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['kr_msgs', 'msg'], 'GeometryPlane')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.speed = kwargs.get('speed', float())
        self.buffer = kwargs.get('buffer', float())
        if 'sensitivity' not in kwargs:
            self.sensitivity = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.sensitivity = numpy.array(kwargs.get('sensitivity'), dtype=numpy.float64)
            assert self.sensitivity.shape == (7, )
        self.safety_io = kwargs.get('safety_io', int())
        self.planes = kwargs.get('planes', [])

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
        if self.speed != other.speed:
            return False
        if self.buffer != other.buffer:
            return False
        if all(self.sensitivity != other.sensitivity):
            return False
        if self.safety_io != other.safety_io:
            return False
        if self.planes != other.planes:
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

    @property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
        self._speed = value

    @property
    def buffer(self):
        """Message field 'buffer'."""
        return self._buffer

    @buffer.setter
    def buffer(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'buffer' field must be of type 'float'"
        self._buffer = value

    @property
    def sensitivity(self):
        """Message field 'sensitivity'."""
        return self._sensitivity

    @sensitivity.setter
    def sensitivity(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'sensitivity' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'sensitivity' numpy.ndarray() must have a size of 7"
            self._sensitivity = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'sensitivity' field must be a set or sequence with length 7 and each value of type 'float'"
        self._sensitivity = numpy.array(value, dtype=numpy.float64)

    @property
    def safety_io(self):
        """Message field 'safety_io'."""
        return self._safety_io

    @safety_io.setter
    def safety_io(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'safety_io' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'safety_io' field must be an integer in [-128, 127]"
        self._safety_io = value

    @property
    def planes(self):
        """Message field 'planes'."""
        return self._planes

    @planes.setter
    def planes(self, value):
        if __debug__:
            from kr_msgs.msg import GeometryPlane
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
                 all(isinstance(v, GeometryPlane) for v in value) and
                 True), \
                "The 'planes' field must be a set or sequence and each value of type 'GeometryPlane'"
        self._planes = value
