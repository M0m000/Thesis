# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:msg/RobotState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotState(type):
    """Metaclass of message 'RobotState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'INIT': 1,
        'STANDBY': 2,
        'MOVING': 3,
        'BACKDRIVE': 4,
        'SUSPENDED': 5,
        'ALARM': 6,
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
                'kr_msgs.msg.RobotState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'INIT': cls.__constants['INIT'],
            'STANDBY': cls.__constants['STANDBY'],
            'MOVING': cls.__constants['MOVING'],
            'BACKDRIVE': cls.__constants['BACKDRIVE'],
            'SUSPENDED': cls.__constants['SUSPENDED'],
            'ALARM': cls.__constants['ALARM'],
        }

    @property
    def INIT(self):
        """Message constant 'INIT'."""
        return Metaclass_RobotState.__constants['INIT']

    @property
    def STANDBY(self):
        """Message constant 'STANDBY'."""
        return Metaclass_RobotState.__constants['STANDBY']

    @property
    def MOVING(self):
        """Message constant 'MOVING'."""
        return Metaclass_RobotState.__constants['MOVING']

    @property
    def BACKDRIVE(self):
        """Message constant 'BACKDRIVE'."""
        return Metaclass_RobotState.__constants['BACKDRIVE']

    @property
    def SUSPENDED(self):
        """Message constant 'SUSPENDED'."""
        return Metaclass_RobotState.__constants['SUSPENDED']

    @property
    def ALARM(self):
        """Message constant 'ALARM'."""
        return Metaclass_RobotState.__constants['ALARM']


class RobotState(metaclass=Metaclass_RobotState):
    """
    Message class 'RobotState'.

    Constants:
      INIT
      STANDBY
      MOVING
      BACKDRIVE
      SUSPENDED
      ALARM
    """

    __slots__ = [
        '_val',
        '_str',
    ]

    _fields_and_field_types = {
        'val': 'int8',
        'str': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.val = kwargs.get('val', int())
        self.str = kwargs.get('str', str())

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
        if self.val != other.val:
            return False
        if self.str != other.str:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def val(self):
        """Message field 'val'."""
        return self._val

    @val.setter
    def val(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'val' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'val' field must be an integer in [-128, 127]"
        self._val = value

    @property  # noqa: A003
    def str(self):  # noqa: A003
        """Message field 'str'."""
        return self._str

    @str.setter  # noqa: A003
    def str(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'str' field must be of type 'str'"
        self._str = value
