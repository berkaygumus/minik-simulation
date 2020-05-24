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

class newTaskInfoMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.taskUUID = null;
      this.timeStamp = null;
      this.handlingDuration = null;
      this.timeOutDuration = null;
      this.requiredResources = null;
    }
    else {
      if (initObj.hasOwnProperty('taskUUID')) {
        this.taskUUID = initObj.taskUUID
      }
      else {
        this.taskUUID = '';
      }
      if (initObj.hasOwnProperty('timeStamp')) {
        this.timeStamp = initObj.timeStamp
      }
      else {
        this.timeStamp = 0;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type newTaskInfoMessage
    // Serialize message field [taskUUID]
    bufferOffset = _serializer.string(obj.taskUUID, buffer, bufferOffset);
    // Serialize message field [timeStamp]
    bufferOffset = _serializer.uint64(obj.timeStamp, buffer, bufferOffset);
    // Serialize message field [handlingDuration]
    bufferOffset = _serializer.uint16(obj.handlingDuration, buffer, bufferOffset);
    // Serialize message field [timeOutDuration]
    bufferOffset = _serializer.uint16(obj.timeOutDuration, buffer, bufferOffset);
    // Serialize message field [requiredResources]
    bufferOffset = _serializer.string(obj.requiredResources, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type newTaskInfoMessage
    let len;
    let data = new newTaskInfoMessage(null);
    // Deserialize message field [taskUUID]
    data.taskUUID = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [timeStamp]
    data.timeStamp = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [handlingDuration]
    data.handlingDuration = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [timeOutDuration]
    data.timeOutDuration = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [requiredResources]
    data.requiredResources = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.taskUUID.length;
    length += object.requiredResources.length;
    return length + 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/newTaskInfoMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0857da229f3a63b6ca6a5f69dd323a29';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # New task's information
    
    string taskUUID # Universally Unique Identifier (UUID)
    
    uint64 timeStamp #The encountering time
    
    uint16 handlingDuration
    
    uint16 timeOutDuration
    
    string requiredResources # Required resources for this task
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new newTaskInfoMessage(null);
    if (msg.taskUUID !== undefined) {
      resolved.taskUUID = msg.taskUUID;
    }
    else {
      resolved.taskUUID = ''
    }

    if (msg.timeStamp !== undefined) {
      resolved.timeStamp = msg.timeStamp;
    }
    else {
      resolved.timeStamp = 0
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

    return resolved;
    }
};

module.exports = newTaskInfoMessage;
