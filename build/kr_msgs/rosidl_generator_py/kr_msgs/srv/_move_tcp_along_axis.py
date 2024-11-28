# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:srv/MoveTCPAlongAxis.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveTCPAlongAxis_Request(type):
    """Metaclass of message 'MoveTCPAlongAxis_Request'."""

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
                'kr_msgs.srv.MoveTCPAlongAxis_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_tcp_along_axis__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_tcp_along_axis__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_tcp_along_axis__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_tcp_along_axis__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_tcp_along_axis__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveTCPAlongAxis_Request(metaclass=Metaclass_MoveTCPAlongAxis_Request):
    """Message class 'MoveTCPAlongAxis_Request'."""

    __slots__ = [
        '_baseline',
        '_frame',
        '_axis',
    ]

    _fields_and_field_types = {
        'baseline': 'float',
        'frame': 'string',
        'axis': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.baseline = kwargs.get('baseline', float())
        self.frame = kwargs.get('frame', str())
        self.axis = kwargs.get('axis', str())

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
        if self.baseline != other.baseline:
            return False
        if self.frame != other.frame:
            return False
        if self.axis != other.axis:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def baseline(self):
        """Message field 'baseline'."""
        return self._baseline

    @baseline.setter
    def baseline(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'baseline' field must be of type 'float'"
        self._baseline = value

    @property
    def frame(self):
        """Message field 'frame'."""
        return self._frame

    @frame.setter
    def frame(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'frame' field must be of type 'str'"
        self._frame = value

    @property
    def axis(self):
        """Message field 'axis'."""
        return self._axis

    @axis.setter
    def axis(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'axis' field must be of type 'str'"
        self._axis = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveTCPAlongAxis_Response(type):
    """Metaclass of message 'MoveTCPAlongAxis_Response'."""

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
                'kr_msgs.srv.MoveTCPAlongAxis_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_tcp_along_axis__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_tcp_along_axis__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_tcp_along_axis__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_tcp_along_axis__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_tcp_along_axis__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveTCPAlongAxis_Response(metaclass=Metaclass_MoveTCPAlongAxis_Response):
    """Message class 'MoveTCPAlongAxis_Response'."""

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


class Metaclass_MoveTCPAlongAxis(type):
    """Metaclass of service 'MoveTCPAlongAxis'."""

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
                'kr_msgs.srv.MoveTCPAlongAxis')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__move_tcp_along_axis

            from kr_msgs.srv import _move_tcp_along_axis
            if _move_tcp_along_axis.Metaclass_MoveTCPAlongAxis_Request._TYPE_SUPPORT is None:
                _move_tcp_along_axis.Metaclass_MoveTCPAlongAxis_Request.__import_type_support__()
            if _move_tcp_along_axis.Metaclass_MoveTCPAlongAxis_Response._TYPE_SUPPORT is None:
                _move_tcp_along_axis.Metaclass_MoveTCPAlongAxis_Response.__import_type_support__()


class MoveTCPAlongAxis(metaclass=Metaclass_MoveTCPAlongAxis):
    from kr_msgs.srv._move_tcp_along_axis import MoveTCPAlongAxis_Request as Request
    from kr_msgs.srv._move_tcp_along_axis import MoveTCPAlongAxis_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
