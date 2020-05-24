# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ISLH_msgs/taskInfo2CoordinatorMessage.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class taskInfo2CoordinatorMessage(genpy.Message):
  _md5sum = "0297b8535571357f947ead3aedb14c47"
  _type = "ISLH_msgs/taskInfo2CoordinatorMessage"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# The task's information to coalition leader

uint64 sendingTime #The sending time

uint16 infoTypeID

uint16 receiverRobotID #robot id to which the message will be sent 

uint16 senderRobotID #robot id of coalition leader

uint16 encounteringRobotID #robot id which encounters the task

uint64 encounteringTime #The encountering time

uint16 handlingDuration

uint16 timeOutDuration

uint64 startHandlingTime #the time when the task starts being handled

float32 posX # The position of the task at x direction
float32 posY # The position of the task at y direction

string taskResource

string taskUUID # the task's UUID

string extraMsg

"""
  __slots__ = ['sendingTime','infoTypeID','receiverRobotID','senderRobotID','encounteringRobotID','encounteringTime','handlingDuration','timeOutDuration','startHandlingTime','posX','posY','taskResource','taskUUID','extraMsg']
  _slot_types = ['uint64','uint16','uint16','uint16','uint16','uint64','uint16','uint16','uint64','float32','float32','string','string','string']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       sendingTime,infoTypeID,receiverRobotID,senderRobotID,encounteringRobotID,encounteringTime,handlingDuration,timeOutDuration,startHandlingTime,posX,posY,taskResource,taskUUID,extraMsg

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(taskInfo2CoordinatorMessage, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.sendingTime is None:
        self.sendingTime = 0
      if self.infoTypeID is None:
        self.infoTypeID = 0
      if self.receiverRobotID is None:
        self.receiverRobotID = 0
      if self.senderRobotID is None:
        self.senderRobotID = 0
      if self.encounteringRobotID is None:
        self.encounteringRobotID = 0
      if self.encounteringTime is None:
        self.encounteringTime = 0
      if self.handlingDuration is None:
        self.handlingDuration = 0
      if self.timeOutDuration is None:
        self.timeOutDuration = 0
      if self.startHandlingTime is None:
        self.startHandlingTime = 0
      if self.posX is None:
        self.posX = 0.
      if self.posY is None:
        self.posY = 0.
      if self.taskResource is None:
        self.taskResource = ''
      if self.taskUUID is None:
        self.taskUUID = ''
      if self.extraMsg is None:
        self.extraMsg = ''
    else:
      self.sendingTime = 0
      self.infoTypeID = 0
      self.receiverRobotID = 0
      self.senderRobotID = 0
      self.encounteringRobotID = 0
      self.encounteringTime = 0
      self.handlingDuration = 0
      self.timeOutDuration = 0
      self.startHandlingTime = 0
      self.posX = 0.
      self.posY = 0.
      self.taskResource = ''
      self.taskUUID = ''
      self.extraMsg = ''

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
      buff.write(_get_struct_Q4HQ2HQ2f().pack(_x.sendingTime, _x.infoTypeID, _x.receiverRobotID, _x.senderRobotID, _x.encounteringRobotID, _x.encounteringTime, _x.handlingDuration, _x.timeOutDuration, _x.startHandlingTime, _x.posX, _x.posY))
      _x = self.taskResource
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.taskUUID
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.extraMsg
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 44
      (_x.sendingTime, _x.infoTypeID, _x.receiverRobotID, _x.senderRobotID, _x.encounteringRobotID, _x.encounteringTime, _x.handlingDuration, _x.timeOutDuration, _x.startHandlingTime, _x.posX, _x.posY,) = _get_struct_Q4HQ2HQ2f().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.taskResource = str[start:end].decode('utf-8')
      else:
        self.taskResource = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.taskUUID = str[start:end].decode('utf-8')
      else:
        self.taskUUID = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.extraMsg = str[start:end].decode('utf-8')
      else:
        self.extraMsg = str[start:end]
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
      buff.write(_get_struct_Q4HQ2HQ2f().pack(_x.sendingTime, _x.infoTypeID, _x.receiverRobotID, _x.senderRobotID, _x.encounteringRobotID, _x.encounteringTime, _x.handlingDuration, _x.timeOutDuration, _x.startHandlingTime, _x.posX, _x.posY))
      _x = self.taskResource
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.taskUUID
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.extraMsg
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
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
      _x = self
      start = end
      end += 44
      (_x.sendingTime, _x.infoTypeID, _x.receiverRobotID, _x.senderRobotID, _x.encounteringRobotID, _x.encounteringTime, _x.handlingDuration, _x.timeOutDuration, _x.startHandlingTime, _x.posX, _x.posY,) = _get_struct_Q4HQ2HQ2f().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.taskResource = str[start:end].decode('utf-8')
      else:
        self.taskResource = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.taskUUID = str[start:end].decode('utf-8')
      else:
        self.taskUUID = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.extraMsg = str[start:end].decode('utf-8')
      else:
        self.extraMsg = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_Q4HQ2HQ2f = None
def _get_struct_Q4HQ2HQ2f():
    global _struct_Q4HQ2HQ2f
    if _struct_Q4HQ2HQ2f is None:
        _struct_Q4HQ2HQ2f = struct.Struct("<Q4HQ2HQ2f")
    return _struct_Q4HQ2HQ2f
