# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:msg/SafetyEvent.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SafetyEvent(type):
    """Metaclass of message 'SafetyEvent'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TYPE_ESTOP': 1,
        'TYPE_PSTOP': 2,
        'TYPE_SSTOP': 3,
        'CODE_EXT_E_STOP_ACTIVATED': 1,
        'CODE_EXT_P_STOP_ACTIVATED': 2,
        'CODE_IOB_NOT_RESPONDING': 3,
        'CODE_JBS_NOT_RESPONDING': 4,
        'CODE_J_RATED_X_SENSOR_POS_SPAN': 5,
        'CODE_J_RATED_POS_DELTA_SPAN': 6,
        'CODE_J_RATED_SPEED_EXCEEDED': 7,
        'CODE_J_RATED_TORQUE_EXCEEDED': 8,
        'CODE_J_RATED_STATIC_TORQUE_EXCEEDED': 9,
        'CODE_J_RATED_TEMPERATURE_EXCEEDED': 10,
        'CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED': 11,
        'CODE_MODEL_JS_SPAN_EXCEEDED': 12,
        'CODE_MODEL_WS_SPAN_EXCEEDED': 13,
        'CODE_MODEL_FRAME_SPEED_EXCEEDED': 14,
        'CODE_TRQ_MODE_JSPEED_EXCEEDED': 15,
        'CODE_INVALID_MODEL_STATE': 21,
        'CODE_J_MODEL_VELOCITY_EXCEEDED': 22,
        'CODE_J_MODEL_TORQUE_EXCEEDED': 23,
        'CODE_J_MODEL_STATIC_TORQUE_EXCEEDED': 24,
        'CODE_J_MODEL_LIMIT_ESTIMATION': 25,
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
                'kr_msgs.msg.SafetyEvent')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__safety_event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__safety_event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__safety_event
            cls._TYPE_SUPPORT = module.type_support_msg__msg__safety_event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__safety_event

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TYPE_ESTOP': cls.__constants['TYPE_ESTOP'],
            'TYPE_PSTOP': cls.__constants['TYPE_PSTOP'],
            'TYPE_SSTOP': cls.__constants['TYPE_SSTOP'],
            'CODE_EXT_E_STOP_ACTIVATED': cls.__constants['CODE_EXT_E_STOP_ACTIVATED'],
            'CODE_EXT_P_STOP_ACTIVATED': cls.__constants['CODE_EXT_P_STOP_ACTIVATED'],
            'CODE_IOB_NOT_RESPONDING': cls.__constants['CODE_IOB_NOT_RESPONDING'],
            'CODE_JBS_NOT_RESPONDING': cls.__constants['CODE_JBS_NOT_RESPONDING'],
            'CODE_J_RATED_X_SENSOR_POS_SPAN': cls.__constants['CODE_J_RATED_X_SENSOR_POS_SPAN'],
            'CODE_J_RATED_POS_DELTA_SPAN': cls.__constants['CODE_J_RATED_POS_DELTA_SPAN'],
            'CODE_J_RATED_SPEED_EXCEEDED': cls.__constants['CODE_J_RATED_SPEED_EXCEEDED'],
            'CODE_J_RATED_TORQUE_EXCEEDED': cls.__constants['CODE_J_RATED_TORQUE_EXCEEDED'],
            'CODE_J_RATED_STATIC_TORQUE_EXCEEDED': cls.__constants['CODE_J_RATED_STATIC_TORQUE_EXCEEDED'],
            'CODE_J_RATED_TEMPERATURE_EXCEEDED': cls.__constants['CODE_J_RATED_TEMPERATURE_EXCEEDED'],
            'CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED': cls.__constants['CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED'],
            'CODE_MODEL_JS_SPAN_EXCEEDED': cls.__constants['CODE_MODEL_JS_SPAN_EXCEEDED'],
            'CODE_MODEL_WS_SPAN_EXCEEDED': cls.__constants['CODE_MODEL_WS_SPAN_EXCEEDED'],
            'CODE_MODEL_FRAME_SPEED_EXCEEDED': cls.__constants['CODE_MODEL_FRAME_SPEED_EXCEEDED'],
            'CODE_TRQ_MODE_JSPEED_EXCEEDED': cls.__constants['CODE_TRQ_MODE_JSPEED_EXCEEDED'],
            'CODE_INVALID_MODEL_STATE': cls.__constants['CODE_INVALID_MODEL_STATE'],
            'CODE_J_MODEL_VELOCITY_EXCEEDED': cls.__constants['CODE_J_MODEL_VELOCITY_EXCEEDED'],
            'CODE_J_MODEL_TORQUE_EXCEEDED': cls.__constants['CODE_J_MODEL_TORQUE_EXCEEDED'],
            'CODE_J_MODEL_STATIC_TORQUE_EXCEEDED': cls.__constants['CODE_J_MODEL_STATIC_TORQUE_EXCEEDED'],
            'CODE_J_MODEL_LIMIT_ESTIMATION': cls.__constants['CODE_J_MODEL_LIMIT_ESTIMATION'],
        }

    @property
    def TYPE_ESTOP(self):
        """Message constant 'TYPE_ESTOP'."""
        return Metaclass_SafetyEvent.__constants['TYPE_ESTOP']

    @property
    def TYPE_PSTOP(self):
        """Message constant 'TYPE_PSTOP'."""
        return Metaclass_SafetyEvent.__constants['TYPE_PSTOP']

    @property
    def TYPE_SSTOP(self):
        """Message constant 'TYPE_SSTOP'."""
        return Metaclass_SafetyEvent.__constants['TYPE_SSTOP']

    @property
    def CODE_EXT_E_STOP_ACTIVATED(self):
        """Message constant 'CODE_EXT_E_STOP_ACTIVATED'."""
        return Metaclass_SafetyEvent.__constants['CODE_EXT_E_STOP_ACTIVATED']

    @property
    def CODE_EXT_P_STOP_ACTIVATED(self):
        """Message constant 'CODE_EXT_P_STOP_ACTIVATED'."""
        return Metaclass_SafetyEvent.__constants['CODE_EXT_P_STOP_ACTIVATED']

    @property
    def CODE_IOB_NOT_RESPONDING(self):
        """Message constant 'CODE_IOB_NOT_RESPONDING'."""
        return Metaclass_SafetyEvent.__constants['CODE_IOB_NOT_RESPONDING']

    @property
    def CODE_JBS_NOT_RESPONDING(self):
        """Message constant 'CODE_JBS_NOT_RESPONDING'."""
        return Metaclass_SafetyEvent.__constants['CODE_JBS_NOT_RESPONDING']

    @property
    def CODE_J_RATED_X_SENSOR_POS_SPAN(self):
        """Message constant 'CODE_J_RATED_X_SENSOR_POS_SPAN'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_RATED_X_SENSOR_POS_SPAN']

    @property
    def CODE_J_RATED_POS_DELTA_SPAN(self):
        """Message constant 'CODE_J_RATED_POS_DELTA_SPAN'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_RATED_POS_DELTA_SPAN']

    @property
    def CODE_J_RATED_SPEED_EXCEEDED(self):
        """Message constant 'CODE_J_RATED_SPEED_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_RATED_SPEED_EXCEEDED']

    @property
    def CODE_J_RATED_TORQUE_EXCEEDED(self):
        """Message constant 'CODE_J_RATED_TORQUE_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_RATED_TORQUE_EXCEEDED']

    @property
    def CODE_J_RATED_STATIC_TORQUE_EXCEEDED(self):
        """Message constant 'CODE_J_RATED_STATIC_TORQUE_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_RATED_STATIC_TORQUE_EXCEEDED']

    @property
    def CODE_J_RATED_TEMPERATURE_EXCEEDED(self):
        """Message constant 'CODE_J_RATED_TEMPERATURE_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_RATED_TEMPERATURE_EXCEEDED']

    @property
    def CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED(self):
        """Message constant 'CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED']

    @property
    def CODE_MODEL_JS_SPAN_EXCEEDED(self):
        """Message constant 'CODE_MODEL_JS_SPAN_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_MODEL_JS_SPAN_EXCEEDED']

    @property
    def CODE_MODEL_WS_SPAN_EXCEEDED(self):
        """Message constant 'CODE_MODEL_WS_SPAN_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_MODEL_WS_SPAN_EXCEEDED']

    @property
    def CODE_MODEL_FRAME_SPEED_EXCEEDED(self):
        """Message constant 'CODE_MODEL_FRAME_SPEED_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_MODEL_FRAME_SPEED_EXCEEDED']

    @property
    def CODE_TRQ_MODE_JSPEED_EXCEEDED(self):
        """Message constant 'CODE_TRQ_MODE_JSPEED_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_TRQ_MODE_JSPEED_EXCEEDED']

    @property
    def CODE_INVALID_MODEL_STATE(self):
        """Message constant 'CODE_INVALID_MODEL_STATE'."""
        return Metaclass_SafetyEvent.__constants['CODE_INVALID_MODEL_STATE']

    @property
    def CODE_J_MODEL_VELOCITY_EXCEEDED(self):
        """Message constant 'CODE_J_MODEL_VELOCITY_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_MODEL_VELOCITY_EXCEEDED']

    @property
    def CODE_J_MODEL_TORQUE_EXCEEDED(self):
        """Message constant 'CODE_J_MODEL_TORQUE_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_MODEL_TORQUE_EXCEEDED']

    @property
    def CODE_J_MODEL_STATIC_TORQUE_EXCEEDED(self):
        """Message constant 'CODE_J_MODEL_STATIC_TORQUE_EXCEEDED'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_MODEL_STATIC_TORQUE_EXCEEDED']

    @property
    def CODE_J_MODEL_LIMIT_ESTIMATION(self):
        """Message constant 'CODE_J_MODEL_LIMIT_ESTIMATION'."""
        return Metaclass_SafetyEvent.__constants['CODE_J_MODEL_LIMIT_ESTIMATION']


class SafetyEvent(metaclass=Metaclass_SafetyEvent):
    """
    Message class 'SafetyEvent'.

    Constants:
      TYPE_ESTOP
      TYPE_PSTOP
      TYPE_SSTOP
      CODE_EXT_E_STOP_ACTIVATED
      CODE_EXT_P_STOP_ACTIVATED
      CODE_IOB_NOT_RESPONDING
      CODE_JBS_NOT_RESPONDING
      CODE_J_RATED_X_SENSOR_POS_SPAN
      CODE_J_RATED_POS_DELTA_SPAN
      CODE_J_RATED_SPEED_EXCEEDED
      CODE_J_RATED_TORQUE_EXCEEDED
      CODE_J_RATED_STATIC_TORQUE_EXCEEDED
      CODE_J_RATED_TEMPERATURE_EXCEEDED
      CODE_J_RATED_TORQUE_DEVIATION_EXCEEDED
      CODE_MODEL_JS_SPAN_EXCEEDED
      CODE_MODEL_WS_SPAN_EXCEEDED
      CODE_MODEL_FRAME_SPEED_EXCEEDED
      CODE_TRQ_MODE_JSPEED_EXCEEDED
      CODE_INVALID_MODEL_STATE
      CODE_J_MODEL_VELOCITY_EXCEEDED
      CODE_J_MODEL_TORQUE_EXCEEDED
      CODE_J_MODEL_STATIC_TORQUE_EXCEEDED
      CODE_J_MODEL_LIMIT_ESTIMATION
    """

    __slots__ = [
        '_type',
        '_code',
        '_timestamp',
    ]

    _fields_and_field_types = {
        'type': 'int8',
        'code': 'int32',
        'timestamp': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.type = kwargs.get('type', int())
        self.code = kwargs.get('code', int())
        self.timestamp = kwargs.get('timestamp', int())

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
        if self.type != other.type:
            return False
        if self.code != other.code:
            return False
        if self.timestamp != other.timestamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'type' field must be an integer in [-128, 127]"
        self._type = value

    @property
    def code(self):
        """Message field 'code'."""
        return self._code

    @code.setter
    def code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'code' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'code' field must be an integer in [-2147483648, 2147483647]"
        self._code = value

    @property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'timestamp' field must be an unsigned integer in [0, 4294967295]"
        self._timestamp = value
