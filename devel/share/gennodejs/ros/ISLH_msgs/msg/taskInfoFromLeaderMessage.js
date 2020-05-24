// Auto-generated. Do not edit!

// (in-package ISLH_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class taskInfoFromLeaderMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sendingTime = null;
      this.infoTypeID = null;
      this.senderRobotID = null;
      this.encounteringRobotID = null;
      this.encounteringTime = null;
      this.startHandlingTime = null;
      this.handlingDuration = null;
      this.timeOutDuration = null;
      this.requiredResources = null;
      this.posX = null;
      this.posY = null;
      this.taskUUID = null;
      this.extraMsg = null;
    }
    else {
      if (initObj.hasOwnProperty('sendingTime')) {
        this.sendingTime = initObj.sendingTime
      }
      else {
        this.sendingTime = 0;
      }
      if (initObj.hasOwnProperty('infoTypeID')) {
        this.infoTypeID = initObj.infoTypeID
      }
      else {
        this.infoTypeID = 0;
      }
      if (initObj.hasOwnProperty('senderRobotID')) {
        this.senderRobotID = initObj.senderRobotID
      }
      else {
        this.senderRobotID = 0;
      }
      if (initObj.hasOwnProperty('encounteringRobotID')) {
        this.encounteringRobotID = initObj.encounteringRobotID
      }
      else {
        this.encounteringRobotID = 0;
      }
      if (initObj.hasOwnProperty('encounteringTime')) {
        this.encounteringTime = initObj.encounteringTime
      }
      else {
        this.encounteringTime = 0;
      }
      if (initObj.hasOwnProperty('startHandlingTime')) {
        this.startHandlingTime = initObj.startHandlingTime
      }
      else {
        this.startHandlingTime = 0;
      }
      if (initObj.hasOwnProperty('handlingDuration')) {
        this.handlingDuration = initObj.handlingDuration
      }
      else {
        this.handlingDuration = 0;
      }
      if (initObj.hasOwnProperty('timeOutDuration')) {
        this.timeOutDuration = initObj.timeOutDuration
      }
      else {
        this.timeOutDuration = 0;
      }
      if (initObj.hasOwnProperty('requiredResources')) {
        this.requiredResources = initObj.requiredResources
      }
      else {
        this.requiredResources = '';
      }
      if (initObj.hasOwnProperty('posX')) {
        this.posX = initObj.posX
      }
      else {
        this.posX = 0.0;
      }
      if (initObj.hasOwnProperty('posY')) {
        this.posY = initObj.posY
      }
      else {
        this.posY = 0.0;
      }
      if (initObj.hasOwnProperty('taskUUID')) {
        this.taskUUID = initObj.taskUUID
      }
      else {
        this.taskUUID = '';
      }
      if (initObj.hasOwnProperty('extraMsg')) {
        this.extraMsg = initObj.extraMsg
      }
      else {
        this.extraMsg = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type taskInfoFromLeaderMessage
    // Serialize message field [sendingTime]
    bufferOffset = _serializer.uint64(obj.sendingTime, buffer, bufferOffset);
    // Serialize message field [infoTypeID]
    bufferOffset = _serializer.uint16(obj.infoTypeID, buffer, bufferOffset);
    // Serialize message field [senderRobotID]
    bufferOffset = _serializer.uint16(obj.senderRobotID, buffer, bufferOffset);
    // Serialize message field [encounteringRobotID]
    bufferOffset = _serializer.uint16(obj.encounteringRobotID, buffer, bufferOffset);
    // Serialize message field [encounteringTime]
    bufferOffset = _serializer.uint64(obj.encounteringTime, buffer, bufferOffset);
    // Serialize message field [startHandlingTime]
    bufferOffset = _serializer.uint64(obj.startHandlingTime, buffer, bufferOffset);
    // Serialize message field [handlingDuration]
    bufferOffset = _serializer.uint16(obj.handlingDuration, buffer, bufferOffset);
    // Serialize message field [timeOutDuration]
    bufferOffset = _serializer.uint16(obj.timeOutDuration, buffer, bufferOffset);
    // Serialize message field [requiredResources]
    bufferOffset = _serializer.string(obj.requiredResources, buffer, bufferOffset);
    // Serialize message field [posX]
    bufferOffset = _serializer.float32(obj.posX, buffer, bufferOffset);
    // Serialize message field [posY]
    bufferOffset = _serializer.float32(obj.posY, buffer, bufferOffset);
    // Serialize message field [taskUUID]
    bufferOffset = _serializer.string(obj.taskUUID, buffer, bufferOffset);
    // Serialize message field [extraMsg]
    bufferOffset = _serializer.string(obj.extraMsg, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type taskInfoFromLeaderMessage
    let len;
    let data = new taskInfoFromLeaderMessage(null);
    // Deserialize message field [sendingTime]
    data.sendingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [infoTypeID]
    data.infoTypeID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [senderRobotID]
    data.senderRobotID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [encounteringRobotID]
    data.encounteringRobotID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [encounteringTime]
    data.encounteringTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [startHandlingTime]
    data.startHandlingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [handlingDuration]
    data.handlingDuration = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [timeOutDuration]
    data.timeOutDuration = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [requiredResources]
    data.requiredResources = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [posX]
    data.posX = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [posY]
    data.posY = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [taskUUID]
    data.taskUUID = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [extraMsg]
    data.extraMsg = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.requiredResources.length;
    length += object.taskUUID.length;
    length += object.extraMsg.length;
    return length + 54;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/taskInfoFromLeaderMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a19d17ade63c51621e68763c106dd71e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The task's information to the task coordinator
    
    uint64 sendingTime #The sending time
    
    uint16 infoTypeID
    
    uint16 senderRobotID # robot id of coalition leader 
    
    uint16 encounteringRobotID #robot id which encounters the task
    
    uint64 encounteringTime #The encountering time in timestamp form
    
    uint64 startHandlingTime #the time when the task starts being handled
    
    uint16 handlingDuration
    
    uint16 timeOutDuration
    
    string requiredResources # Required resources for this task
    
    float32 posX # The position of the task at x direction
    float32 posY # The position of the task at y direction
    
    string taskUUID # the task's UUID
    
    string extraMsg
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new taskInfoFromLeaderMessage(null);
    if (msg.sendingTime !== undefined) {
      resolved.sendingTime = msg.sendingTime;
    }
    else {
      resolved.sendingTime = 0
    }

    if (msg.infoTypeID !== undefined) {
      resolved.infoTypeID = msg.infoTypeID;
    }
    else {
      resolved.infoTypeID = 0
    }

    if (msg.senderRobotID !== undefined) {
      resolved.senderRobotID = msg.senderRobotID;
    }
    else {
      resolved.senderRobotID = 0
    }

    if (msg.encounteringRobotID !== undefined) {
      resolved.encounteringRobotID = msg.encounteringRobotID;
    }
    else {
      resolved.encounteringRobotID = 0
    }

    if (msg.encounteringTime !== undefined) {
      resolved.encounteringTime = msg.encounteringTime;
    }
    else {
      resolved.encounteringTime = 0
    }

    if (msg.startHandlingTime !== undefined) {
      resolved.startHandlingTime = msg.startHandlingTime;
    }
    else {
      resolved.startHandlingTime = 0
    }

    if (msg.handlingDuration !== undefined) {
      resolved.handlingDuration = msg.handlingDuration;
    }
    else {
      resolved.handlingDuration = 0
    }

    if (msg.timeOutDuration !== undefined) {
      resolved.timeOutDuration = msg.timeOutDuration;
    }
    else {
      resolved.timeOutDuration = 0
    }

    if (msg.requiredResources !== undefined) {
      resolved.requiredResources = msg.requiredResources;
    }
    else {
      resolved.requiredResources = ''
    }

    if (msg.posX !== undefined) {
      resolved.posX = msg.posX;
    }
    else {
      resolved.posX = 0.0
    }

    if (msg.posY !== undefined) {
      resolved.posY = msg.posY;
    }
    else {
      resolved.posY = 0.0
    }

    if (msg.taskUUID !== undefined) {
      resolved.taskUUID = msg.taskUUID;
    }
    else {
      resolved.taskUUID = ''
    }

    if (msg.extraMsg !== undefined) {
      resolved.extraMsg = msg.extraMsg;
    }
    else {
      resolved.extraMsg = ''
    }

    return resolved;
    }
};

module.exports = taskInfoFromLeaderMessage;
