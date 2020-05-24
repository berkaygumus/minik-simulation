# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ISLH_msgs/robotInfo.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class robotInfo(genpy.Message):
  _md5sum = "efd1aeeed9405e7a52385c335c0151bb"
  _type = "ISLH_msgs/robotInfo"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """#The robot's information that is relayed to the other robots

string[] neighbors #Neighbor robot names

float32 posX # The current position of the robot at x direction
float32 posY # The current position of the robot at y direction

float32 radius # The radius of the robot

float32 targetX # The current target position of the robot at x direction
float32 targetY # The current target position of the robot at y direction
"""
  __slots__ = ['neighbors','posX','posY','radius','targetX','targetY']
  _slot_types = ['string[]','float32','float32','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       neighbors,posX,posY,radius,targetX,targetY

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(robotInfo, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.neighbors is None:
        self.neighbors = []
      if self.posX is None:
        self.posX = 0.
      if self.posY is None:
        self.posY = 0.
      if self.radius is None:
        self.radius = 0.
      if self.targetX is None:
        self.targetX = 0.
      if self.targetY is None:
        self.targetY = 0.
    else:
      self.neighbors = []
      self.posX = 0.
      self.posY = 0.
      self.radius = 0.
      self.targetX = 0.
      self.targetY = 0.

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
      length = len(self.neighbors)
      buff.write(_struct_I.pack(length))
      for val1 in self.neighbors:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.pack('<I%ss'%length, length, val1))
      _x = self
      buff.write(_get_struct_5f().pack(_x.posX, _x.posY, _x.radius, _x.targetX, _x.targetY))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.neighbors = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8')
        else:
          val1 = str[start:end]
        self.neighbors.append(val1)
      _x = self
      start = end
      end += 20
      (_x.posX, _x.posY, _x.radius, _x.targetX, _x.targetY,) = _get_struct_5f().unpack(str[start:end])
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
      length = len(self.neighbors)
      buff.write(_struct_I.pack(length))
      for val1 in self.neighbors:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.pack('<I%ss'%length, length, val1))
      _x = self
      buff.write(_get_struct_5f().pack(_x.posX, _x.posY, _x.radius, _x.targetX, _x.targetY))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.neighbors = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8')
        else:
          val1 = str[start:end]
        self.neighbors.append(val1)
      _x = self
      start = end
      end += 20
      (_x.posX, _x.posY, _x.radius, _x.targetX, _x.targetY,) = _get_struct_5f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_5f = None
def _get_struct_5f():
    global _struct_5f
    if _struct_5f is None:
        _struct_5f = struct.Struct("<5f")
    return _struct_5f
