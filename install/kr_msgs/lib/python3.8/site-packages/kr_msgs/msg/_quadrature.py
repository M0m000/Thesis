# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:msg/Quadrature.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Quadrature(type):
    """Metaclass of message 'Quadrature'."""

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
                'kr_msgs.msg.Quadrature')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__quadrature
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__quadrature
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__quadrature
            cls._TYPE_SUPPORT = module.type_support_msg__msg__quadrature
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__quadrature

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Quadrature(metaclass=Metaclass_Quadrature):
    """Message class 'Quadrature'."""

    __slots__ = [
        '_direction',
        '_pulse_count',
        '_frequency',
        '_abs_pulse_count',
        '_pulse_per_sec',
    ]

    _fields_and_field_types = {
        'direction': 'int8',
        'pulse_count': 'int32',
        'frequency': 'int32',
        'abs_pulse_count': 'int32',
        'pulse_per_sec': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.direction = kwargs.get('direction', int())
        self.pulse_count = kwargs.get('pulse_count', int())
        self.frequency = kwargs.get('frequency', int())
        self.abs_pulse_count = kwargs.get('abs_pulse_count', int())
        self.pulse_per_sec = kwargs.get('pulse_per_sec', int())

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
        if self.direction != other.direction:
            return False
        if self.pulse_count != other.pulse_count:
            return False
        if self.frequency != other.frequency:
            return False
        if self.abs_pulse_count != other.abs_pulse_count:
            return False
        if self.pulse_per_sec != other.pulse_per_sec:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'direction' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'direction' field must be an integer in [-128, 127]"
        self._direction = value

    @property
    def pulse_count(self):
        """Message field 'pulse_count'."""
        return self._pulse_count

    @pulse_count.setter
    def pulse_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pulse_count' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'pulse_count' field must be an integer in [-2147483648, 2147483647]"
        self._pulse_count = value

    @property
    def frequency(self):
        """Message field 'frequency'."""
        return self._frequency

    @frequency.setter
    def frequency(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'frequency' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'frequency' field must be an integer in [-2147483648, 2147483647]"
        self._frequency = value

    @property
    def abs_pulse_count(self):
        """Message field 'abs_pulse_count'."""
        return self._abs_pulse_count

    @abs_pulse_count.setter
    def abs_pulse_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'abs_pulse_count' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'abs_pulse_count' field must be an integer in [-2147483648, 2147483647]"
        self._abs_pulse_count = value

    @property
    def pulse_per_sec(self):
        """Message field 'pulse_per_sec'."""
        return self._pulse_per_sec

    @pulse_per_sec.setter
    def pulse_per_sec(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pulse_per_sec' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'pulse_per_sec' field must be an integer in [-2147483648, 2147483647]"
        self._pulse_per_sec = value
