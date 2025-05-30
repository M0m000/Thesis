# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:msg/RobotPose.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'pos'
# Member 'rot'
# Member 'jsconf'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotPose(type):
    """Metaclass of message 'RobotPose'."""

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
                'kr_msgs.msg.RobotPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_pose
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_pose
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_pose
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_pose
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_pose

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotPose(metaclass=Metaclass_RobotPose):
    """Message class 'RobotPose'."""

    __slots__ = [
        '_pos',
        '_rot',
        '_jsconf',
    ]

    _fields_and_field_types = {
        'pos': 'double[3]',
        'rot': 'double[3]',
        'jsconf': 'double[7]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
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
        if 'jsconf' not in kwargs:
            self.jsconf = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.jsconf = numpy.array(kwargs.get('jsconf'), dtype=numpy.float64)
            assert self.jsconf.shape == (7, )

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
        if all(self.jsconf != other.jsconf):
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
    def jsconf(self):
        """Message field 'jsconf'."""
        return self._jsconf

    @jsconf.setter
    def jsconf(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'jsconf' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'jsconf' numpy.ndarray() must have a size of 7"
            self._jsconf = value
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
                "The 'jsconf' field must be a set or sequence with length 7 and each value of type 'float'"
        self._jsconf = numpy.array(value, dtype=numpy.float64)
