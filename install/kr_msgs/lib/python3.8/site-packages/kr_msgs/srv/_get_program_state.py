# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:srv/GetProgramState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetProgramState_Request(type):
    """Metaclass of message 'GetProgramState_Request'."""

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
                'kr_msgs.srv.GetProgramState_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_program_state__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_program_state__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_program_state__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_program_state__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_program_state__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetProgramState_Request(metaclass=Metaclass_GetProgramState_Request):
    """Message class 'GetProgramState_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GetProgramState_Response(type):
    """Metaclass of message 'GetProgramState_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NONE': 0,
        'RUNNING': 1,
        'PAUSED': 2,
        'HALTED': 3,
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
                'kr_msgs.srv.GetProgramState_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_program_state__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_program_state__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_program_state__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_program_state__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_program_state__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NONE': cls.__constants['NONE'],
            'RUNNING': cls.__constants['RUNNING'],
            'PAUSED': cls.__constants['PAUSED'],
            'HALTED': cls.__constants['HALTED'],
        }

    @property
    def NONE(self):
        """Message constant 'NONE'."""
        return Metaclass_GetProgramState_Response.__constants['NONE']

    @property
    def RUNNING(self):
        """Message constant 'RUNNING'."""
        return Metaclass_GetProgramState_Response.__constants['RUNNING']

    @property
    def PAUSED(self):
        """Message constant 'PAUSED'."""
        return Metaclass_GetProgramState_Response.__constants['PAUSED']

    @property
    def HALTED(self):
        """Message constant 'HALTED'."""
        return Metaclass_GetProgramState_Response.__constants['HALTED']


class GetProgramState_Response(metaclass=Metaclass_GetProgramState_Response):
    """
    Message class 'GetProgramState_Response'.

    Constants:
      NONE
      RUNNING
      PAUSED
      HALTED
    """

    __slots__ = [
        '_state',
        '_success',
    ]

    _fields_and_field_types = {
        'state': 'uint32',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.state = kwargs.get('state', int())
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
        if self.state != other.state:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'state' field must be an unsigned integer in [0, 4294967295]"
        self._state = value

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


class Metaclass_GetProgramState(type):
    """Metaclass of service 'GetProgramState'."""

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
                'kr_msgs.srv.GetProgramState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_program_state

            from kr_msgs.srv import _get_program_state
            if _get_program_state.Metaclass_GetProgramState_Request._TYPE_SUPPORT is None:
                _get_program_state.Metaclass_GetProgramState_Request.__import_type_support__()
            if _get_program_state.Metaclass_GetProgramState_Response._TYPE_SUPPORT is None:
                _get_program_state.Metaclass_GetProgramState_Response.__import_type_support__()


class GetProgramState(metaclass=Metaclass_GetProgramState):
    from kr_msgs.srv._get_program_state import GetProgramState_Request as Request
    from kr_msgs.srv._get_program_state import GetProgramState_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
