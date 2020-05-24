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

class taskInfoFromRobotMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.senderRobotID = null;
      this.infoMessageType = null;
      this.taskUUID = null;
      this.encounteringTime = null;
      this.reachingTime = null;
      this.handlingDuration = null;
      this.timeOutDuration = null;
      this.requiredResources = null;
      this.posX = null;
      this.posY = null;
    }
    else {
      if (initObj.hasOwnProperty('senderRobotID')) {
        this.senderRobotID = initObj.senderRobotID
      }
      else {
        this.senderRobotID = 0;
      }
      if (initObj.hasOwnProperty('infoMessageType')) {
        this.infoMessageType = initObj.infoMessageType
      }
      else {
        this.infoMessageType = 0;
      }
      if (initObj.hasOwnProperty('taskUUID')) {
        this.taskUUID = initObj.taskUUID
      }
      else {
        this.taskUUID = '';
      }
      if (initObj.hasOwnProperty('encounteringTime')) {
        this.encounteringTime = initObj.encounteringTime
      }
      else {
        this.encounteringTime = 0;
      }
      if (initObj.hasOwnProperty('reachingTime')) {
        this.reachingTime = initObj.reachingTime
      }
      else {
        this.reachingTime = 0;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type taskInfoFromRobotMessage
    // Serialize message field [senderRobotID]
    bufferOffset = _serializer.uint16(obj.senderRobotID, buffer, bufferOffset);
    // Serialize message field [infoMessageType]
    bufferOffset = _serializer.uint16(obj.infoMessageType, buffer, bufferOffset);
    // Serialize message field [taskUUID]
    bufferOffset = _serializer.string(obj.taskUUID, buffer, bufferOffset);
    // Serialize message field [encounteringTime]
    bufferOffset = _serializer.uint64(obj.encounteringTime, buffer, bufferOffset);
    // Serialize message field [reachingTime]
    bufferOffset = _serializer.uint64(obj.reachingTime, buffer, bufferOffset);
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
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type taskInfoFromRobotMessage
    let len;
    let data = new taskInfoFromRobotMessage(null);
    // Deserialize message field [senderRobotID]
    data.senderRobotID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [infoMessageType]
    data.infoMessageType = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [taskUUID]
    data.taskUUID = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [encounteringTime]
    data.encounteringTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [reachingTime]
    data.reachingTime = _deserializer.uint64(buffer, bufferOffset);
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
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.taskUUID.length;
    length += object.requiredResources.length;
    return length + 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/taskInfoFromRobotMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e54b818b14e2cc4a576aa5a518a1a847';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The task's information  from member robot to coalition leader
    
    uint16 senderRobotID #robot id which encounters the task
    
    uint16 infoMessageType
    
    string taskUUID # the task's UUID
    
    uint64 encounteringTime #The encountering time in timestamp form
    
    uint64 reachingTime # The time when the robot reached to the task site
    
    uint16 handlingDuration
    
    uint16 timeOutDuration
    
    string requiredResources # Required resources for this task
    
    float32 posX # The position of the task at x direction 
    float32 posY # The position of the task at y direction 
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new taskInfoFromRobotMessage(null);
    if (msg.senderRobotID !== undefined) {
      resolved.senderRobotID = msg.senderRobotID;
    }
    else {
      resolved.senderRobotID = 0
    }

    if (msg.infoMessageType !== undefined) {
      resolved.infoMessageType = msg.infoMessageType;
    }
    else {
      resolved.infoMessageType = 0
    }

    if (msg.taskUUID !== undefined) {
      resolved.taskUUID = msg.taskUUID;
    }
    else {
      resolved.taskUUID = ''
    }

    if (msg.encounteringTime !== undefined) {
      resolved.encounteringTime = msg.encounteringTime;
    }
    else {
      resolved.encounteringTime = 0
    }

    if (msg.reachingTime !== undefined) {
      resolved.reachingTime = msg.reachingTime;
    }
    else {
      resolved.reachingTime = 0
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

    return resolved;
    }
};

module.exports = taskInfoFromRobotMessage;
