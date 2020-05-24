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

class cmd2RobotsMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sendingTime = null;
      this.cmdType = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('sendingTime')) {
        this.sendingTime = initObj.sendingTime
      }
      else {
        this.sendingTime = 0;
      }
      if (initObj.hasOwnProperty('cmdType')) {
        this.cmdType = initObj.cmdType
      }
      else {
        this.cmdType = 0;
      }
      if (initObj.hasOwnProperty('message')) {
        this.message = initObj.message
      }
      else {
        this.message = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type cmd2RobotsMessage
    // Serialize message field [sendingTime]
    bufferOffset = _serializer.uint64(obj.sendingTime, buffer, bufferOffset);
    // Serialize message field [cmdType]
    bufferOffset = _serializer.uint16(obj.cmdType, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type cmd2RobotsMessage
    let len;
    let data = new cmd2RobotsMessage(null);
    // Deserialize message field [sendingTime]
    data.sendingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [cmdType]
    data.cmdType = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [message]
    data.message = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.message.length;
    return length + 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/cmd2RobotsMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '651ffc22f68ec2e97e413b004cae948b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The incoming command message from coalition leader
    
    uint64 sendingTime #The sending time
    
    uint16 cmdType
    
    string message
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new cmd2RobotsMessage(null);
    if (msg.sendingTime !== undefined) {
      resolved.sendingTime = msg.sendingTime;
    }
    else {
      resolved.sendingTime = 0
    }

    if (msg.cmdType !== undefined) {
      resolved.cmdType = msg.cmdType;
    }
    else {
      resolved.cmdType = 0
    }

    if (msg.message !== undefined) {
      resolved.message = msg.message;
    }
    else {
      resolved.message = ''
    }

    return resolved;
    }
};

module.exports = cmd2RobotsMessage;
