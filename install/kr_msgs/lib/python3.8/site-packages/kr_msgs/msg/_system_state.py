# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kr_msgs:msg/SystemState.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'sensed_pos'
# Member 'sensed_vel'
# Member 'sensed_trq'
# Member 'target_pos'
# Member 'target_vel'
# Member 'target_trq'
# Member 'pos'
# Member 'rot'
# Member 'iob_digital_out'
# Member 'iob_relays'
# Member 'iob_current_out'
# Member 'iob_voltage_out'
# Member 'iob_digital_in'
# Member 'iob_safe_in'
# Member 'iob_current_in'
# Member 'iob_voltage_in'
# Member 'tio_digital_out'
# Member 'tio_power_supply'
# Member 'tio_analog_out'
# Member 'tio_current_in'
# Member 'tio_voltage_in'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SystemState(type):
    """Metaclass of message 'SystemState'."""

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
                'kr_msgs.msg.SystemState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__system_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__system_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__system_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__system_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__system_state

            from kr_msgs.msg import Quadrature
            if Quadrature.__class__._TYPE_SUPPORT is None:
                Quadrature.__class__.__import_type_support__()

            from kr_msgs.msg import RobotMode
            if RobotMode.__class__._TYPE_SUPPORT is None:
                RobotMode.__class__.__import_type_support__()

            from kr_msgs.msg import RobotState
            if RobotState.__class__._TYPE_SUPPORT is None:
                RobotState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SystemState(metaclass=Metaclass_SystemState):
    """Message class 'SystemState'."""

    __slots__ = [
        '_robot_mode',
        '_robot_state',
        '_sensed_pos',
        '_sensed_vel',
        '_sensed_trq',
        '_target_pos',
        '_target_vel',
        '_target_trq',
        '_pos',
        '_rot',
        '_iob_digital_out',
        '_iob_relays',
        '_iob_current_out',
        '_iob_voltage_out',
        '_iob_digital_in',
        '_iob_safe_in',
        '_iob_current_in',
        '_iob_voltage_in',
        '_iob_quadratures',
        '_tio_digital_out',
        '_tio_power_supply',
        '_tio_analog_out',
        '_tio_current_in',
        '_tio_voltage_in',
        '_e_stop',
        '_p_stop',
        '_toggle',
        '_backdrive',
    ]

    _fields_and_field_types = {
        'robot_mode': 'kr_msgs/RobotMode',
        'robot_state': 'kr_msgs/RobotState',
        'sensed_pos': 'double[7]',
        'sensed_vel': 'double[7]',
        'sensed_trq': 'double[7]',
        'target_pos': 'double[7]',
        'target_vel': 'double[7]',
        'target_trq': 'double[7]',
        'pos': 'double[3]',
        'rot': 'double[3]',
        'iob_digital_out': 'int8[8]',
        'iob_relays': 'int8[4]',
        'iob_current_out': 'float[2]',
        'iob_voltage_out': 'float[2]',
        'iob_digital_in': 'int8[16]',
        'iob_safe_in': 'int8[4]',
        'iob_current_in': 'float[2]',
        'iob_voltage_in': 'float[2]',
        'iob_quadratures': 'kr_msgs/Quadrature[2]',
        'tio_digital_out': 'int8[4]',
        'tio_power_supply': 'int8[3]',
        'tio_analog_out': 'float[2]',
        'tio_current_in': 'float[1]',
        'tio_voltage_in': 'float[4]',
        'e_stop': 'boolean',
        'p_stop': 'boolean',
        'toggle': 'boolean',
        'backdrive': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['kr_msgs', 'msg'], 'RobotMode'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['kr_msgs', 'msg'], 'RobotState'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 8),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 16),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['kr_msgs', 'msg'], 'Quadrature'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 1),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from kr_msgs.msg import RobotMode
        self.robot_mode = kwargs.get('robot_mode', RobotMode())
        from kr_msgs.msg import RobotState
        self.robot_state = kwargs.get('robot_state', RobotState())
        if 'sensed_pos' not in kwargs:
            self.sensed_pos = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.sensed_pos = numpy.array(kwargs.get('sensed_pos'), dtype=numpy.float64)
            assert self.sensed_pos.shape == (7, )
        if 'sensed_vel' not in kwargs:
            self.sensed_vel = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.sensed_vel = numpy.array(kwargs.get('sensed_vel'), dtype=numpy.float64)
            assert self.sensed_vel.shape == (7, )
        if 'sensed_trq' not in kwargs:
            self.sensed_trq = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.sensed_trq = numpy.array(kwargs.get('sensed_trq'), dtype=numpy.float64)
            assert self.sensed_trq.shape == (7, )
        if 'target_pos' not in kwargs:
            self.target_pos = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.target_pos = numpy.array(kwargs.get('target_pos'), dtype=numpy.float64)
            assert self.target_pos.shape == (7, )
        if 'target_vel' not in kwargs:
            self.target_vel = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.target_vel = numpy.array(kwargs.get('target_vel'), dtype=numpy.float64)
            assert self.target_vel.shape == (7, )
        if 'target_trq' not in kwargs:
            self.target_trq = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.target_trq = numpy.array(kwargs.get('target_trq'), dtype=numpy.float64)
            assert self.target_trq.shape == (7, )
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
        if 'iob_digital_out' not in kwargs:
            self.iob_digital_out = numpy.zeros(8, dtype=numpy.int8)
        else:
            self.iob_digital_out = numpy.array(kwargs.get('iob_digital_out'), dtype=numpy.int8)
            assert self.iob_digital_out.shape == (8, )
        if 'iob_relays' not in kwargs:
            self.iob_relays = numpy.zeros(4, dtype=numpy.int8)
        else:
            self.iob_relays = numpy.array(kwargs.get('iob_relays'), dtype=numpy.int8)
            assert self.iob_relays.shape == (4, )
        if 'iob_current_out' not in kwargs:
            self.iob_current_out = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.iob_current_out = numpy.array(kwargs.get('iob_current_out'), dtype=numpy.float32)
            assert self.iob_current_out.shape == (2, )
        if 'iob_voltage_out' not in kwargs:
            self.iob_voltage_out = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.iob_voltage_out = numpy.array(kwargs.get('iob_voltage_out'), dtype=numpy.float32)
            assert self.iob_voltage_out.shape == (2, )
        if 'iob_digital_in' not in kwargs:
            self.iob_digital_in = numpy.zeros(16, dtype=numpy.int8)
        else:
            self.iob_digital_in = numpy.array(kwargs.get('iob_digital_in'), dtype=numpy.int8)
            assert self.iob_digital_in.shape == (16, )
        if 'iob_safe_in' not in kwargs:
            self.iob_safe_in = numpy.zeros(4, dtype=numpy.int8)
        else:
            self.iob_safe_in = numpy.array(kwargs.get('iob_safe_in'), dtype=numpy.int8)
            assert self.iob_safe_in.shape == (4, )
        if 'iob_current_in' not in kwargs:
            self.iob_current_in = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.iob_current_in = numpy.array(kwargs.get('iob_current_in'), dtype=numpy.float32)
            assert self.iob_current_in.shape == (2, )
        if 'iob_voltage_in' not in kwargs:
            self.iob_voltage_in = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.iob_voltage_in = numpy.array(kwargs.get('iob_voltage_in'), dtype=numpy.float32)
            assert self.iob_voltage_in.shape == (2, )
        from kr_msgs.msg import Quadrature
        self.iob_quadratures = kwargs.get(
            'iob_quadratures',
            [Quadrature() for x in range(2)]
        )
        if 'tio_digital_out' not in kwargs:
            self.tio_digital_out = numpy.zeros(4, dtype=numpy.int8)
        else:
            self.tio_digital_out = numpy.array(kwargs.get('tio_digital_out'), dtype=numpy.int8)
            assert self.tio_digital_out.shape == (4, )
        if 'tio_power_supply' not in kwargs:
            self.tio_power_supply = numpy.zeros(3, dtype=numpy.int8)
        else:
            self.tio_power_supply = numpy.array(kwargs.get('tio_power_supply'), dtype=numpy.int8)
            assert self.tio_power_supply.shape == (3, )
        if 'tio_analog_out' not in kwargs:
            self.tio_analog_out = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.tio_analog_out = numpy.array(kwargs.get('tio_analog_out'), dtype=numpy.float32)
            assert self.tio_analog_out.shape == (2, )
        if 'tio_current_in' not in kwargs:
            self.tio_current_in = numpy.zeros(1, dtype=numpy.float32)
        else:
            self.tio_current_in = numpy.array(kwargs.get('tio_current_in'), dtype=numpy.float32)
            assert self.tio_current_in.shape == (1, )
        if 'tio_voltage_in' not in kwargs:
            self.tio_voltage_in = numpy.zeros(4, dtype=numpy.float32)
        else:
            self.tio_voltage_in = numpy.array(kwargs.get('tio_voltage_in'), dtype=numpy.float32)
            assert self.tio_voltage_in.shape == (4, )
        self.e_stop = kwargs.get('e_stop', bool())
        self.p_stop = kwargs.get('p_stop', bool())
        self.toggle = kwargs.get('toggle', bool())
        self.backdrive = kwargs.get('backdrive', bool())

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
        if self.robot_mode != other.robot_mode:
            return False
        if self.robot_state != other.robot_state:
            return False
        if all(self.sensed_pos != other.sensed_pos):
            return False
        if all(self.sensed_vel != other.sensed_vel):
            return False
        if all(self.sensed_trq != other.sensed_trq):
            return False
        if all(self.target_pos != other.target_pos):
            return False
        if all(self.target_vel != other.target_vel):
            return False
        if all(self.target_trq != other.target_trq):
            return False
        if all(self.pos != other.pos):
            return False
        if all(self.rot != other.rot):
            return False
        if all(self.iob_digital_out != other.iob_digital_out):
            return False
        if all(self.iob_relays != other.iob_relays):
            return False
        if all(self.iob_current_out != other.iob_current_out):
            return False
        if all(self.iob_voltage_out != other.iob_voltage_out):
            return False
        if all(self.iob_digital_in != other.iob_digital_in):
            return False
        if all(self.iob_safe_in != other.iob_safe_in):
            return False
        if all(self.iob_current_in != other.iob_current_in):
            return False
        if all(self.iob_voltage_in != other.iob_voltage_in):
            return False
        if self.iob_quadratures != other.iob_quadratures:
            return False
        if all(self.tio_digital_out != other.tio_digital_out):
            return False
        if all(self.tio_power_supply != other.tio_power_supply):
            return False
        if all(self.tio_analog_out != other.tio_analog_out):
            return False
        if all(self.tio_current_in != other.tio_current_in):
            return False
        if all(self.tio_voltage_in != other.tio_voltage_in):
            return False
        if self.e_stop != other.e_stop:
            return False
        if self.p_stop != other.p_stop:
            return False
        if self.toggle != other.toggle:
            return False
        if self.backdrive != other.backdrive:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def robot_mode(self):
        """Message field 'robot_mode'."""
        return self._robot_mode

    @robot_mode.setter
    def robot_mode(self, value):
        if __debug__:
            from kr_msgs.msg import RobotMode
            assert \
                isinstance(value, RobotMode), \
                "The 'robot_mode' field must be a sub message of type 'RobotMode'"
        self._robot_mode = value

    @property
    def robot_state(self):
        """Message field 'robot_state'."""
        return self._robot_state

    @robot_state.setter
    def robot_state(self, value):
        if __debug__:
            from kr_msgs.msg import RobotState
            assert \
                isinstance(value, RobotState), \
                "The 'robot_state' field must be a sub message of type 'RobotState'"
        self._robot_state = value

    @property
    def sensed_pos(self):
        """Message field 'sensed_pos'."""
        return self._sensed_pos

    @sensed_pos.setter
    def sensed_pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'sensed_pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'sensed_pos' numpy.ndarray() must have a size of 7"
            self._sensed_pos = value
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
                "The 'sensed_pos' field must be a set or sequence with length 7 and each value of type 'float'"
        self._sensed_pos = numpy.array(value, dtype=numpy.float64)

    @property
    def sensed_vel(self):
        """Message field 'sensed_vel'."""
        return self._sensed_vel

    @sensed_vel.setter
    def sensed_vel(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'sensed_vel' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'sensed_vel' numpy.ndarray() must have a size of 7"
            self._sensed_vel = value
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
                "The 'sensed_vel' field must be a set or sequence with length 7 and each value of type 'float'"
        self._sensed_vel = numpy.array(value, dtype=numpy.float64)

    @property
    def sensed_trq(self):
        """Message field 'sensed_trq'."""
        return self._sensed_trq

    @sensed_trq.setter
    def sensed_trq(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'sensed_trq' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'sensed_trq' numpy.ndarray() must have a size of 7"
            self._sensed_trq = value
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
                "The 'sensed_trq' field must be a set or sequence with length 7 and each value of type 'float'"
        self._sensed_trq = numpy.array(value, dtype=numpy.float64)

    @property
    def target_pos(self):
        """Message field 'target_pos'."""
        return self._target_pos

    @target_pos.setter
    def target_pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'target_pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'target_pos' numpy.ndarray() must have a size of 7"
            self._target_pos = value
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
                "The 'target_pos' field must be a set or sequence with length 7 and each value of type 'float'"
        self._target_pos = numpy.array(value, dtype=numpy.float64)

    @property
    def target_vel(self):
        """Message field 'target_vel'."""
        return self._target_vel

    @target_vel.setter
    def target_vel(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'target_vel' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'target_vel' numpy.ndarray() must have a size of 7"
            self._target_vel = value
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
                "The 'target_vel' field must be a set or sequence with length 7 and each value of type 'float'"
        self._target_vel = numpy.array(value, dtype=numpy.float64)

    @property
    def target_trq(self):
        """Message field 'target_trq'."""
        return self._target_trq

    @target_trq.setter
    def target_trq(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'target_trq' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'target_trq' numpy.ndarray() must have a size of 7"
            self._target_trq = value
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
                "The 'target_trq' field must be a set or sequence with length 7 and each value of type 'float'"
        self._target_trq = numpy.array(value, dtype=numpy.float64)

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
    def iob_digital_out(self):
        """Message field 'iob_digital_out'."""
        return self._iob_digital_out

    @iob_digital_out.setter
    def iob_digital_out(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'iob_digital_out' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 8, \
                "The 'iob_digital_out' numpy.ndarray() must have a size of 8"
            self._iob_digital_out = value
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
                 len(value) == 8 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'iob_digital_out' field must be a set or sequence with length 8 and each value of type 'int' and each integer in [-128, 127]"
        self._iob_digital_out = numpy.array(value, dtype=numpy.int8)

    @property
    def iob_relays(self):
        """Message field 'iob_relays'."""
        return self._iob_relays

    @iob_relays.setter
    def iob_relays(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'iob_relays' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 4, \
                "The 'iob_relays' numpy.ndarray() must have a size of 4"
            self._iob_relays = value
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'iob_relays' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-128, 127]"
        self._iob_relays = numpy.array(value, dtype=numpy.int8)

    @property
    def iob_current_out(self):
        """Message field 'iob_current_out'."""
        return self._iob_current_out

    @iob_current_out.setter
    def iob_current_out(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'iob_current_out' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'iob_current_out' numpy.ndarray() must have a size of 2"
            self._iob_current_out = value
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
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'iob_current_out' field must be a set or sequence with length 2 and each value of type 'float'"
        self._iob_current_out = numpy.array(value, dtype=numpy.float32)

    @property
    def iob_voltage_out(self):
        """Message field 'iob_voltage_out'."""
        return self._iob_voltage_out

    @iob_voltage_out.setter
    def iob_voltage_out(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'iob_voltage_out' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'iob_voltage_out' numpy.ndarray() must have a size of 2"
            self._iob_voltage_out = value
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
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'iob_voltage_out' field must be a set or sequence with length 2 and each value of type 'float'"
        self._iob_voltage_out = numpy.array(value, dtype=numpy.float32)

    @property
    def iob_digital_in(self):
        """Message field 'iob_digital_in'."""
        return self._iob_digital_in

    @iob_digital_in.setter
    def iob_digital_in(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'iob_digital_in' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 16, \
                "The 'iob_digital_in' numpy.ndarray() must have a size of 16"
            self._iob_digital_in = value
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
                 len(value) == 16 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'iob_digital_in' field must be a set or sequence with length 16 and each value of type 'int' and each integer in [-128, 127]"
        self._iob_digital_in = numpy.array(value, dtype=numpy.int8)

    @property
    def iob_safe_in(self):
        """Message field 'iob_safe_in'."""
        return self._iob_safe_in

    @iob_safe_in.setter
    def iob_safe_in(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'iob_safe_in' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 4, \
                "The 'iob_safe_in' numpy.ndarray() must have a size of 4"
            self._iob_safe_in = value
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'iob_safe_in' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-128, 127]"
        self._iob_safe_in = numpy.array(value, dtype=numpy.int8)

    @property
    def iob_current_in(self):
        """Message field 'iob_current_in'."""
        return self._iob_current_in

    @iob_current_in.setter
    def iob_current_in(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'iob_current_in' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'iob_current_in' numpy.ndarray() must have a size of 2"
            self._iob_current_in = value
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
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'iob_current_in' field must be a set or sequence with length 2 and each value of type 'float'"
        self._iob_current_in = numpy.array(value, dtype=numpy.float32)

    @property
    def iob_voltage_in(self):
        """Message field 'iob_voltage_in'."""
        return self._iob_voltage_in

    @iob_voltage_in.setter
    def iob_voltage_in(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'iob_voltage_in' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'iob_voltage_in' numpy.ndarray() must have a size of 2"
            self._iob_voltage_in = value
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
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'iob_voltage_in' field must be a set or sequence with length 2 and each value of type 'float'"
        self._iob_voltage_in = numpy.array(value, dtype=numpy.float32)

    @property
    def iob_quadratures(self):
        """Message field 'iob_quadratures'."""
        return self._iob_quadratures

    @iob_quadratures.setter
    def iob_quadratures(self, value):
        if __debug__:
            from kr_msgs.msg import Quadrature
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
                 len(value) == 2 and
                 all(isinstance(v, Quadrature) for v in value) and
                 True), \
                "The 'iob_quadratures' field must be a set or sequence with length 2 and each value of type 'Quadrature'"
        self._iob_quadratures = value

    @property
    def tio_digital_out(self):
        """Message field 'tio_digital_out'."""
        return self._tio_digital_out

    @tio_digital_out.setter
    def tio_digital_out(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'tio_digital_out' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 4, \
                "The 'tio_digital_out' numpy.ndarray() must have a size of 4"
            self._tio_digital_out = value
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'tio_digital_out' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-128, 127]"
        self._tio_digital_out = numpy.array(value, dtype=numpy.int8)

    @property
    def tio_power_supply(self):
        """Message field 'tio_power_supply'."""
        return self._tio_power_supply

    @tio_power_supply.setter
    def tio_power_supply(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'tio_power_supply' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 3, \
                "The 'tio_power_supply' numpy.ndarray() must have a size of 3"
            self._tio_power_supply = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'tio_power_supply' field must be a set or sequence with length 3 and each value of type 'int' and each integer in [-128, 127]"
        self._tio_power_supply = numpy.array(value, dtype=numpy.int8)

    @property
    def tio_analog_out(self):
        """Message field 'tio_analog_out'."""
        return self._tio_analog_out

    @tio_analog_out.setter
    def tio_analog_out(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'tio_analog_out' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'tio_analog_out' numpy.ndarray() must have a size of 2"
            self._tio_analog_out = value
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
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'tio_analog_out' field must be a set or sequence with length 2 and each value of type 'float'"
        self._tio_analog_out = numpy.array(value, dtype=numpy.float32)

    @property
    def tio_current_in(self):
        """Message field 'tio_current_in'."""
        return self._tio_current_in

    @tio_current_in.setter
    def tio_current_in(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'tio_current_in' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 1, \
                "The 'tio_current_in' numpy.ndarray() must have a size of 1"
            self._tio_current_in = value
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
                 len(value) == 1 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'tio_current_in' field must be a set or sequence with length 1 and each value of type 'float'"
        self._tio_current_in = numpy.array(value, dtype=numpy.float32)

    @property
    def tio_voltage_in(self):
        """Message field 'tio_voltage_in'."""
        return self._tio_voltage_in

    @tio_voltage_in.setter
    def tio_voltage_in(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'tio_voltage_in' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 4, \
                "The 'tio_voltage_in' numpy.ndarray() must have a size of 4"
            self._tio_voltage_in = value
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
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'tio_voltage_in' field must be a set or sequence with length 4 and each value of type 'float'"
        self._tio_voltage_in = numpy.array(value, dtype=numpy.float32)

    @property
    def e_stop(self):
        """Message field 'e_stop'."""
        return self._e_stop

    @e_stop.setter
    def e_stop(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'e_stop' field must be of type 'bool'"
        self._e_stop = value

    @property
    def p_stop(self):
        """Message field 'p_stop'."""
        return self._p_stop

    @p_stop.setter
    def p_stop(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'p_stop' field must be of type 'bool'"
        self._p_stop = value

    @property
    def toggle(self):
        """Message field 'toggle'."""
        return self._toggle

    @toggle.setter
    def toggle(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'toggle' field must be of type 'bool'"
        self._toggle = value

    @property
    def backdrive(self):
        """Message field 'backdrive'."""
        return self._backdrive

    @backdrive.setter
    def backdrive(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'backdrive' field must be of type 'bool'"
        self._backdrive = value
