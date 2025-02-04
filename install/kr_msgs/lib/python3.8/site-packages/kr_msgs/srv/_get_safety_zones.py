# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:srv/GetSafetyZones.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetSafetyZones_Request(type):
    """Metaclass of message 'GetSafetyZones_Request'."""

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
                'kr_msgs.srv.GetSafetyZones_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_safety_zones__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_safety_zones__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_safety_zones__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_safety_zones__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_safety_zones__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetSafetyZones_Request(metaclass=Metaclass_GetSafetyZones_Request):
    """Message class 'GetSafetyZones_Request'."""

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


class Metaclass_GetSafetyZones_Response(type):
    """Metaclass of message 'GetSafetyZones_Response'."""

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
                'kr_msgs.srv.GetSafetyZones_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_safety_zones__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_safety_zones__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_safety_zones__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_safety_zones__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_safety_zones__response

            from kr_msgs.msg import SafetyZone
            if SafetyZone.__class__._TYPE_SUPPORT is None:
                SafetyZone.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetSafetyZones_Response(metaclass=Metaclass_GetSafetyZones_Response):
    """Message class 'GetSafetyZones_Response'."""

    __slots__ = [
        '_zones',
        '_success',
    ]

    _fields_and_field_types = {
        'zones': 'sequence<kr_msgs/SafetyZone>',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['kr_msgs', 'msg'], 'SafetyZone')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.zones = kwargs.get('zones', [])
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
        if self.zones != other.zones:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def zones(self):
        """Message field 'zones'."""
        return self._zones

    @zones.setter
    def zones(self, value):
        if __debug__:
            from kr_msgs.msg import SafetyZone
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
                 all(isinstance(v, SafetyZone) for v in value) and
                 True), \
                "The 'zones' field must be a set or sequence and each value of type 'SafetyZone'"
        self._zones = value

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


class Metaclass_GetSafetyZones(type):
    """Metaclass of service 'GetSafetyZones'."""

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
                'kr_msgs.srv.GetSafetyZones')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_safety_zones

            from kr_msgs.srv import _get_safety_zones
            if _get_safety_zones.Metaclass_GetSafetyZones_Request._TYPE_SUPPORT is None:
                _get_safety_zones.Metaclass_GetSafetyZones_Request.__import_type_support__()
            if _get_safety_zones.Metaclass_GetSafetyZones_Response._TYPE_SUPPORT is None:
                _get_safety_zones.Metaclass_GetSafetyZones_Response.__import_type_support__()


class GetSafetyZones(metaclass=Metaclass_GetSafetyZones):
    from kr_msgs.srv._get_safety_zones import GetSafetyZones_Request as Request
    from kr_msgs.srv._get_safety_zones import GetSafetyZones_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
