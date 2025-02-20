# generated from rosidl_generator_py/resource/_idl.py.em
# with input from action_interfaces:msg/Hook.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Hook(type):
    """Metaclass of message 'Hook'."""

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
                'action_interfaces.msg.Hook')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hook
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hook
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hook
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hook
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hook

            from action_interfaces.msg import BoundingBox
            if BoundingBox.__class__._TYPE_SUPPORT is None:
                BoundingBox.__class__.__import_type_support__()

            from action_interfaces.msg import UV
            if UV.__class__._TYPE_SUPPORT is None:
                UV.__class__.__import_type_support__()

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hook(metaclass=Metaclass_Hook):
    """Message class 'Hook'."""

    __slots__ = [
        '_name',
        '_hook_box',
        '_tip_box',
        '_lowpoint_box',
        '_hook_mask',
        '_tip_mask',
        '_lowpoint_mask',
        '_skeleton_mask',
        '_conf_hook',
        '_conf_tip',
        '_conf_lowpoint',
        '_uv_hook',
        '_uv_tip',
        '_uv_lowpoint',
        '_shortest_path',
        '_path_points',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'hook_box': 'action_interfaces/BoundingBox',
        'tip_box': 'action_interfaces/BoundingBox',
        'lowpoint_box': 'action_interfaces/BoundingBox',
        'hook_mask': 'sensor_msgs/Image',
        'tip_mask': 'sensor_msgs/Image',
        'lowpoint_mask': 'sensor_msgs/Image',
        'skeleton_mask': 'sensor_msgs/Image',
        'conf_hook': 'float',
        'conf_tip': 'float',
        'conf_lowpoint': 'float',
        'uv_hook': 'action_interfaces/UV',
        'uv_tip': 'action_interfaces/UV',
        'uv_lowpoint': 'action_interfaces/UV',
        'shortest_path': 'sequence<action_interfaces/UV>',
        'path_points': 'sequence<action_interfaces/UV>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'BoundingBox'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'BoundingBox'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'BoundingBox'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'UV'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'UV'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'UV'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'UV')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['action_interfaces', 'msg'], 'UV')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        from action_interfaces.msg import BoundingBox
        self.hook_box = kwargs.get('hook_box', BoundingBox())
        from action_interfaces.msg import BoundingBox
        self.tip_box = kwargs.get('tip_box', BoundingBox())
        from action_interfaces.msg import BoundingBox
        self.lowpoint_box = kwargs.get('lowpoint_box', BoundingBox())
        from sensor_msgs.msg import Image
        self.hook_mask = kwargs.get('hook_mask', Image())
        from sensor_msgs.msg import Image
        self.tip_mask = kwargs.get('tip_mask', Image())
        from sensor_msgs.msg import Image
        self.lowpoint_mask = kwargs.get('lowpoint_mask', Image())
        from sensor_msgs.msg import Image
        self.skeleton_mask = kwargs.get('skeleton_mask', Image())
        self.conf_hook = kwargs.get('conf_hook', float())
        self.conf_tip = kwargs.get('conf_tip', float())
        self.conf_lowpoint = kwargs.get('conf_lowpoint', float())
        from action_interfaces.msg import UV
        self.uv_hook = kwargs.get('uv_hook', UV())
        from action_interfaces.msg import UV
        self.uv_tip = kwargs.get('uv_tip', UV())
        from action_interfaces.msg import UV
        self.uv_lowpoint = kwargs.get('uv_lowpoint', UV())
        self.shortest_path = kwargs.get('shortest_path', [])
        self.path_points = kwargs.get('path_points', [])

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
        if self.name != other.name:
            return False
        if self.hook_box != other.hook_box:
            return False
        if self.tip_box != other.tip_box:
            return False
        if self.lowpoint_box != other.lowpoint_box:
            return False
        if self.hook_mask != other.hook_mask:
            return False
        if self.tip_mask != other.tip_mask:
            return False
        if self.lowpoint_mask != other.lowpoint_mask:
            return False
        if self.skeleton_mask != other.skeleton_mask:
            return False
        if self.conf_hook != other.conf_hook:
            return False
        if self.conf_tip != other.conf_tip:
            return False
        if self.conf_lowpoint != other.conf_lowpoint:
            return False
        if self.uv_hook != other.uv_hook:
            return False
        if self.uv_tip != other.uv_tip:
            return False
        if self.uv_lowpoint != other.uv_lowpoint:
            return False
        if self.shortest_path != other.shortest_path:
            return False
        if self.path_points != other.path_points:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @property
    def hook_box(self):
        """Message field 'hook_box'."""
        return self._hook_box

    @hook_box.setter
    def hook_box(self, value):
        if __debug__:
            from action_interfaces.msg import BoundingBox
            assert \
                isinstance(value, BoundingBox), \
                "The 'hook_box' field must be a sub message of type 'BoundingBox'"
        self._hook_box = value

    @property
    def tip_box(self):
        """Message field 'tip_box'."""
        return self._tip_box

    @tip_box.setter
    def tip_box(self, value):
        if __debug__:
            from action_interfaces.msg import BoundingBox
            assert \
                isinstance(value, BoundingBox), \
                "The 'tip_box' field must be a sub message of type 'BoundingBox'"
        self._tip_box = value

    @property
    def lowpoint_box(self):
        """Message field 'lowpoint_box'."""
        return self._lowpoint_box

    @lowpoint_box.setter
    def lowpoint_box(self, value):
        if __debug__:
            from action_interfaces.msg import BoundingBox
            assert \
                isinstance(value, BoundingBox), \
                "The 'lowpoint_box' field must be a sub message of type 'BoundingBox'"
        self._lowpoint_box = value

    @property
    def hook_mask(self):
        """Message field 'hook_mask'."""
        return self._hook_mask

    @hook_mask.setter
    def hook_mask(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'hook_mask' field must be a sub message of type 'Image'"
        self._hook_mask = value

    @property
    def tip_mask(self):
        """Message field 'tip_mask'."""
        return self._tip_mask

    @tip_mask.setter
    def tip_mask(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'tip_mask' field must be a sub message of type 'Image'"
        self._tip_mask = value

    @property
    def lowpoint_mask(self):
        """Message field 'lowpoint_mask'."""
        return self._lowpoint_mask

    @lowpoint_mask.setter
    def lowpoint_mask(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'lowpoint_mask' field must be a sub message of type 'Image'"
        self._lowpoint_mask = value

    @property
    def skeleton_mask(self):
        """Message field 'skeleton_mask'."""
        return self._skeleton_mask

    @skeleton_mask.setter
    def skeleton_mask(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'skeleton_mask' field must be a sub message of type 'Image'"
        self._skeleton_mask = value

    @property
    def conf_hook(self):
        """Message field 'conf_hook'."""
        return self._conf_hook

    @conf_hook.setter
    def conf_hook(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'conf_hook' field must be of type 'float'"
        self._conf_hook = value

    @property
    def conf_tip(self):
        """Message field 'conf_tip'."""
        return self._conf_tip

    @conf_tip.setter
    def conf_tip(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'conf_tip' field must be of type 'float'"
        self._conf_tip = value

    @property
    def conf_lowpoint(self):
        """Message field 'conf_lowpoint'."""
        return self._conf_lowpoint

    @conf_lowpoint.setter
    def conf_lowpoint(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'conf_lowpoint' field must be of type 'float'"
        self._conf_lowpoint = value

    @property
    def uv_hook(self):
        """Message field 'uv_hook'."""
        return self._uv_hook

    @uv_hook.setter
    def uv_hook(self, value):
        if __debug__:
            from action_interfaces.msg import UV
            assert \
                isinstance(value, UV), \
                "The 'uv_hook' field must be a sub message of type 'UV'"
        self._uv_hook = value

    @property
    def uv_tip(self):
        """Message field 'uv_tip'."""
        return self._uv_tip

    @uv_tip.setter
    def uv_tip(self, value):
        if __debug__:
            from action_interfaces.msg import UV
            assert \
                isinstance(value, UV), \
                "The 'uv_tip' field must be a sub message of type 'UV'"
        self._uv_tip = value

    @property
    def uv_lowpoint(self):
        """Message field 'uv_lowpoint'."""
        return self._uv_lowpoint

    @uv_lowpoint.setter
    def uv_lowpoint(self, value):
        if __debug__:
            from action_interfaces.msg import UV
            assert \
                isinstance(value, UV), \
                "The 'uv_lowpoint' field must be a sub message of type 'UV'"
        self._uv_lowpoint = value

    @property
    def shortest_path(self):
        """Message field 'shortest_path'."""
        return self._shortest_path

    @shortest_path.setter
    def shortest_path(self, value):
        if __debug__:
            from action_interfaces.msg import UV
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
                 all(isinstance(v, UV) for v in value) and
                 True), \
                "The 'shortest_path' field must be a set or sequence and each value of type 'UV'"
        self._shortest_path = value

    @property
    def path_points(self):
        """Message field 'path_points'."""
        return self._path_points

    @path_points.setter
    def path_points(self, value):
        if __debug__:
            from action_interfaces.msg import UV
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
                 all(isinstance(v, UV) for v in value) and
                 True), \
                "The 'path_points' field must be a set or sequence and each value of type 'UV'"
        self._path_points = value
