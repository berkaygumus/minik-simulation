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

class cmdFromCoordinatorMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sendingTime = null;
      this.messageTypeID = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('sendingTime')) {
        this.sendingTime = initObj.sendingTime
      }
      else {
        this.sendingTime = 0;
      }
      if (initObj.hasOwnProperty('messageTypeID')) {
        this.messageTypeID = initObj.messageTypeID
      }
      else {
        this.messageTypeID = 0;
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
    // Serializes a message object of type cmdFromCoordinatorMessage
    // Serialize message field [sendingTime]
    bufferOffset = _serializer.uint64(obj.sendingTime, buffer, bufferOffset);
    // Serialize message field [messageTypeID]
    bufferOffset = _serializer.uint16(obj.messageTypeID, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type cmdFromCoordinatorMessage
    let len;
    let data = new cmdFromCoordinatorMessage(null);
    // Deserialize message field [sendingTime]
    data.sendingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [messageTypeID]
    data.messageTypeID = _deserializer.uint16(buffer, bufferOffset);
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
    return 'ISLH_msgs/cmdFromCoordinatorMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6b00d2e721f211550b5ec2a337817798';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The incoming command message from the coordinator
    
    uint64 sendingTime #The sending time
    
    uint16 messageTypeID
    
    string message
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new cmdFromCoordinatorMessage(null);
    if (msg.sendingTime !== undefined) {
      resolved.sendingTime = msg.sendingTime;
    }
    else {
      resolved.sendingTime = 0
    }

    if (msg.messageTypeID !== undefined) {
      resolved.messageTypeID = msg.messageTypeID;
    }
    else {
      resolved.messageTypeID = 0
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

module.exports = cmdFromCoordinatorMessage;
