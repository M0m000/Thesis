# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:srv/SelectJoggingFrame.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SelectJoggingFrame_Request(type):
    """Metaclass of message 'SelectJoggingFrame_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'WORLD': 0,
        'BASE': 1,
        'TCP': 2,
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
                'kr_msgs.srv.SelectJoggingFrame_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__select_jogging_frame__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__select_jogging_frame__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__select_jogging_frame__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__select_jogging_frame__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__select_jogging_frame__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'WORLD': cls.__constants['WORLD'],
            'BASE': cls.__constants['BASE'],
            'TCP': cls.__constants['TCP'],
        }

    @property
    def WORLD(self):
        """Message constant 'WORLD'."""
        return Metaclass_SelectJoggingFrame_Request.__constants['WORLD']

    @property
    def BASE(self):
        """Message constant 'BASE'."""
        return Metaclass_SelectJoggingFrame_Request.__constants['BASE']

    @property
    def TCP(self):
        """Message constant 'TCP'."""
        return Metaclass_SelectJoggingFrame_Request.__constants['TCP']


class SelectJoggingFrame_Request(metaclass=Metaclass_SelectJoggingFrame_Request):
    """
    Message class 'SelectJoggingFrame_Request'.

    Constants:
      WORLD
      BASE
      TCP
    """

    __slots__ = [
        '_ref',
    ]

    _fields_and_field_types = {
        'ref': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ref = kwargs.get('ref', int())

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


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SelectJoggingFrame_Response(type):
    """Metaclass of message 'SelectJoggingFrame_Response'."""

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
                'kr_msgs.srv.SelectJoggingFrame_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__select_jogging_frame__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__select_jogging_frame__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__select_jogging_frame__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__select_jogging_frame__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__select_jogging_frame__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SelectJoggingFrame_Response(metaclass=Metaclass_SelectJoggingFrame_Response):
    """Message class 'SelectJoggingFrame_Response'."""

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


class Metaclass_SelectJoggingFrame(type):
    """Metaclass of service 'SelectJoggingFrame'."""

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
                'kr_msgs.srv.SelectJoggingFrame')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__select_jogging_frame

            from kr_msgs.srv import _select_jogging_frame
            if _select_jogging_frame.Metaclass_SelectJoggingFrame_Request._TYPE_SUPPORT is None:
                _select_jogging_frame.Metaclass_SelectJoggingFrame_Request.__import_type_support__()
            if _select_jogging_frame.Metaclass_SelectJoggingFrame_Response._TYPE_SUPPORT is None:
                _select_jogging_frame.Metaclass_SelectJoggingFrame_Response.__import_type_support__()


class SelectJoggingFrame(metaclass=Metaclass_SelectJoggingFrame):
    from kr_msgs.srv._select_jogging_frame import SelectJoggingFrame_Request as Request
    from kr_msgs.srv._select_jogging_frame import SelectJoggingFrame_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
