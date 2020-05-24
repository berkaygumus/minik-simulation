# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ISLH_msgs/robotPose.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class robotPose(genpy.Message):
  _md5sum = "0eef6d6e44271c92907c87eea9d5073a"
  _type = "ISLH_msgs/robotPose"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """#The robot's position information and target information

int32 id

geometry_msgs/Point position

geometry_msgs/Point target

float32 calYaw
float32 radYaw

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
"""
  __slots__ = ['id','position','target','calYaw','radYaw']
  _slot_types = ['int32','geometry_msgs/Point','geometry_msgs/Point','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       id,position,target,calYaw,radYaw

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(robotPose, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = 0
      if self.position is None:
        self.position = geometry_msgs.msg.Point()
      if self.target is None:
        self.target = geometry_msgs.msg.Point()
      if self.calYaw is None:
        self.calYaw = 0.
      if self.radYaw is None:
        self.radYaw = 0.
    else:
      self.id = 0
      self.position = geometry_msgs.msg.Point()
      self.target = geometry_msgs.msg.Point()
      self.calYaw = 0.
      self.radYaw = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_i6d2f().pack(_x.id, _x.position.x, _x.position.y, _x.position.z, _x.target.x, _x.target.y, _x.target.z, _x.calYaw, _x.radYaw))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.position is None:
        self.position = geometry_msgs.msg.Point()
      if self.target is None:
        self.target = geometry_msgs.msg.Point()
      end = 0
      _x = self
      start = end
      end += 60
      (_x.id, _x.position.x, _x.position.y, _x.position.z, _x.target.x, _x.target.y, _x.target.z, _x.calYaw, _x.radYaw,) = _get_struct_i6d2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_i6d2f().pack(_x.id, _x.position.x, _x.position.y, _x.position.z, _x.target.x, _x.target.y, _x.target.z, _x.calYaw, _x.radYaw))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.position is None:
        self.position = geometry_msgs.msg.Point()
      if self.target is None:
        self.target = geometry_msgs.msg.Point()
      end = 0
      _x = self
      start = end
      end += 60
      (_x.id, _x.position.x, _x.position.y, _x.position.z, _x.target.x, _x.target.y, _x.target.z, _x.calYaw, _x.radYaw,) = _get_struct_i6d2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i6d2f = None
def _get_struct_i6d2f():
    global _struct_i6d2f
    if _struct_i6d2f is None:
        _struct_i6d2f = struct.Struct("<i6d2f")
    return _struct_i6d2f
