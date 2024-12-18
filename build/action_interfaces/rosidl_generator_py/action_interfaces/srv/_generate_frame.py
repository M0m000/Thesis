# generated from rosidl_generator_py/resource/_idl.py.em
# with input from action_interfaces:srv/GenerateFrame.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'translation'
# Member 'rotation_rpy'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GenerateFrame_Request(type):
    """Metaclass of message 'GenerateFrame_Request'."""

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
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.srv.GenerateFrame_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__generate_frame__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__generate_frame__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__generate_frame__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__generate_frame__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__generate_frame__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GenerateFrame_Request(metaclass=Metaclass_GenerateFrame_Request):
    """Message class 'GenerateFrame_Request'."""

    __slots__ = [
        '_frame_new',
        '_frame_ref',
        '_translation',
        '_rotation_rpy',
    ]

    _fields_and_field_types = {
        'frame_new': 'string',
        'frame_ref': 'string',
        'translation': 'double[3]',
        'rotation_rpy': 'double[3]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.frame_new = kwargs.get('frame_new', str())
        self.frame_ref = kwargs.get('frame_ref', str())
        if 'translation' not in kwargs:
            self.translation = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.translation = numpy.array(kwargs.get('translation'), dtype=numpy.float64)
            assert self.translation.shape == (3, )
        if 'rotation_rpy' not in kwargs:
            self.rotation_rpy = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.rotation_rpy = numpy.array(kwargs.get('rotation_rpy'), dtype=numpy.float64)
            assert self.rotation_rpy.shape == (3, )

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
        if self.frame_new != other.frame_new:
            return False
        if self.frame_ref != other.frame_ref:
            return False
        if all(self.translation != other.translation):
            return False
        if all(self.rotation_rpy != other.rotation_rpy):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def frame_new(self):
        """Message field 'frame_new'."""
        return self._frame_new

    @frame_new.setter
    def frame_new(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'frame_new' field must be of type 'str'"
        self._frame_new = value

    @property
    def frame_ref(self):
        """Message field 'frame_ref'."""
        return self._frame_ref

    @frame_ref.setter
    def frame_ref(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'frame_ref' field must be of type 'str'"
        self._frame_ref = value

    @property
    def translation(self):
        """Message field 'translation'."""
        return self._translation

    @translation.setter
    def translation(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'translation' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'translation' numpy.ndarray() must have a size of 3"
            self._translation = value
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
                "The 'translation' field must be a set or sequence with length 3 and each value of type 'float'"
        self._translation = numpy.array(value, dtype=numpy.float64)

    @property
    def rotation_rpy(self):
        """Message field 'rotation_rpy'."""
        return self._rotation_rpy

    @rotation_rpy.setter
    def rotation_rpy(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'rotation_rpy' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'rotation_rpy' numpy.ndarray() must have a size of 3"
            self._rotation_rpy = value
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
                "The 'rotation_rpy' field must be a set or sequence with length 3 and each value of type 'float'"
        self._rotation_rpy = numpy.array(value, dtype=numpy.float64)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GenerateFrame_Response(type):
    """Metaclass of message 'GenerateFrame_Response'."""

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
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.srv.GenerateFrame_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__generate_frame__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__generate_frame__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__generate_frame__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__generate_frame__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__generate_frame__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GenerateFrame_Response(metaclass=Metaclass_GenerateFrame_Response):
    """Message class 'GenerateFrame_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

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
        if self.message != other.message:
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

    @property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_GenerateFrame(type):
    """Metaclass of service 'GenerateFrame'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.srv.GenerateFrame')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__generate_frame

            from action_interfaces.srv import _generate_frame
            if _generate_frame.Metaclass_GenerateFrame_Request._TYPE_SUPPORT is None:
                _generate_frame.Metaclass_GenerateFrame_Request.__import_type_support__()
            if _generate_frame.Metaclass_GenerateFrame_Response._TYPE_SUPPORT is None:
                _generate_frame.Metaclass_GenerateFrame_Response.__import_type_support__()


class GenerateFrame(metaclass=Metaclass_GenerateFrame):
    from action_interfaces.srv._generate_frame import GenerateFrame_Request as Request
    from action_interfaces.srv._generate_frame import GenerateFrame_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
