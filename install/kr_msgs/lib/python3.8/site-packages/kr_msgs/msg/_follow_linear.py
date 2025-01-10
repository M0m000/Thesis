# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:msg/FollowLinear.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'pos'
# Member 'rot'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FollowLinear(type):
    """Metaclass of message 'FollowLinear'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'WORLD': 0,
        'BASE': 1,
        'TCP': 2,
        'TT_VEL': 0,
        'TT_TIME': 1,
        'BP_STOP': 0,
        'BP_VIA': 1,
        'BT_ACC': 0,
        'BT_TIME': 1,
        'BT_RAD': 2,
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
                'kr_msgs.msg.FollowLinear')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__follow_linear
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__follow_linear
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__follow_linear
            cls._TYPE_SUPPORT = module.type_support_msg__msg__follow_linear
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__follow_linear

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'WORLD': cls.__constants['WORLD'],
            'BASE': cls.__constants['BASE'],
            'TCP': cls.__constants['TCP'],
            'TT_VEL': cls.__constants['TT_VEL'],
            'TT_TIME': cls.__constants['TT_TIME'],
            'BP_STOP': cls.__constants['BP_STOP'],
            'BP_VIA': cls.__constants['BP_VIA'],
            'BT_ACC': cls.__constants['BT_ACC'],
            'BT_TIME': cls.__constants['BT_TIME'],
            'BT_RAD': cls.__constants['BT_RAD'],
        }

    @property
    def WORLD(self):
        """Message constant 'WORLD'."""
        return Metaclass_FollowLinear.__constants['WORLD']

    @property
    def BASE(self):
        """Message constant 'BASE'."""
        return Metaclass_FollowLinear.__constants['BASE']

    @property
    def TCP(self):
        """Message constant 'TCP'."""
        return Metaclass_FollowLinear.__constants['TCP']

    @property
    def TT_VEL(self):
        """Message constant 'TT_VEL'."""
        return Metaclass_FollowLinear.__constants['TT_VEL']

    @property
    def TT_TIME(self):
        """Message constant 'TT_TIME'."""
        return Metaclass_FollowLinear.__constants['TT_TIME']

    @property
    def BP_STOP(self):
        """Message constant 'BP_STOP'."""
        return Metaclass_FollowLinear.__constants['BP_STOP']

    @property
    def BP_VIA(self):
        """Message constant 'BP_VIA'."""
        return Metaclass_FollowLinear.__constants['BP_VIA']

    @property
    def BT_ACC(self):
        """Message constant 'BT_ACC'."""
        return Metaclass_FollowLinear.__constants['BT_ACC']

    @property
    def BT_TIME(self):
        """Message constant 'BT_TIME'."""
        return Metaclass_FollowLinear.__constants['BT_TIME']

    @property
    def BT_RAD(self):
        """Message constant 'BT_RAD'."""
        return Metaclass_FollowLinear.__constants['BT_RAD']


class FollowLinear(metaclass=Metaclass_FollowLinear):
    """
    Message class 'FollowLinear'.

    Constants:
      WORLD
      BASE
      TCP
      TT_VEL
      TT_TIME
      BP_STOP
      BP_VIA
      BT_ACC
      BT_TIME
      BT_RAD
    """

    __slots__ = [
        '_pos',
        '_rot',
        '_ref',
        '_ttype',
        '_tvalue',
        '_bpoint',
        '_btype',
        '_bvalue',
    ]

    _fields_and_field_types = {
        'pos': 'double[3]',
        'rot': 'double[3]',
        'ref': 'int8',
        'ttype': 'int8',
        'tvalue': 'double',
        'bpoint': 'int8',
        'btype': 'int8',
        'bvalue': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
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
        self.ref = kwargs.get('ref', int())
        self.ttype = kwargs.get('ttype', int())
        self.tvalue = kwargs.get('tvalue', float())
        self.bpoint = kwargs.get('bpoint', int())
        self.btype = kwargs.get('btype', int())
        self.bvalue = kwargs.get('bvalue', float())

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
        if all(self.pos != other.pos):
            return False
        if all(self.rot != other.rot):
            return False
        if self.ref != other.ref:
            return False
        if self.ttype != other.ttype:
            return False
        if self.tvalue != other.tvalue:
            return False
        if self.bpoint != other.bpoint:
            return False
        if self.btype != other.btype:
            return False
        if self.bvalue != other.bvalue:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def ttype(self):
        """Message field 'ttype'."""
        return self._ttype

    @ttype.setter
    def ttype(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ttype' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ttype' field must be an integer in [-128, 127]"
        self._ttype = value

    @property
    def tvalue(self):
        """Message field 'tvalue'."""
        return self._tvalue

    @tvalue.setter
    def tvalue(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tvalue' field must be of type 'float'"
        self._tvalue = value

    @property
    def bpoint(self):
        """Message field 'bpoint'."""
        return self._bpoint

    @bpoint.setter
    def bpoint(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'bpoint' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'bpoint' field must be an integer in [-128, 127]"
        self._bpoint = value

    @property
    def btype(self):
        """Message field 'btype'."""
        return self._btype

    @btype.setter
    def btype(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'btype' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'btype' field must be an integer in [-128, 127]"
        self._btype = value

    @property
    def bvalue(self):
        """Message field 'bvalue'."""
        return self._bvalue

    @bvalue.setter
    def bvalue(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bvalue' field must be of type 'float'"
        self._bvalue = value
