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

class cmdFromLeaderMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sendingTime = null;
      this.cmdTypeID = null;
      this.cmdMessage = null;
    }
    else {
      if (initObj.hasOwnProperty('sendingTime')) {
        this.sendingTime = initObj.sendingTime
      }
      else {
        this.sendingTime = 0;
      }
      if (initObj.hasOwnProperty('cmdTypeID')) {
        this.cmdTypeID = initObj.cmdTypeID
      }
      else {
        this.cmdTypeID = 0;
      }
      if (initObj.hasOwnProperty('cmdMessage')) {
        this.cmdMessage = initObj.cmdMessage
      }
      else {
        this.cmdMessage = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type cmdFromLeaderMessage
    // Serialize message field [sendingTime]
    bufferOffset = _serializer.uint64(obj.sendingTime, buffer, bufferOffset);
    // Serialize message field [cmdTypeID]
    bufferOffset = _serializer.uint16(obj.cmdTypeID, buffer, bufferOffset);
    // Serialize message field [cmdMessage]
    bufferOffset = _serializer.string(obj.cmdMessage, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type cmdFromLeaderMessage
    let len;
    let data = new cmdFromLeaderMessage(null);
    // Deserialize message field [sendingTime]
    data.sendingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [cmdTypeID]
    data.cmdTypeID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [cmdMessage]
    data.cmdMessage = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.cmdMessage.length;
    return length + 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/cmdFromLeaderMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '49939506eb789fd4a67d4e6e601d80df';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The incoming command message from coalition leader
    
    uint64 sendingTime #The sending time
    
    uint16 cmdTypeID
    
    string cmdMessage
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new cmdFromLeaderMessage(null);
    if (msg.sendingTime !== undefined) {
      resolved.sendingTime = msg.sendingTime;
    }
    else {
      resolved.sendingTime = 0
    }

    if (msg.cmdTypeID !== undefined) {
      resolved.cmdTypeID = msg.cmdTypeID;
    }
    else {
      resolved.cmdTypeID = 0
    }

    if (msg.cmdMessage !== undefined) {
      resolved.cmdMessage = msg.cmdMessage;
    }
    else {
      resolved.cmdMessage = ''
    }

    return resolved;
    }
};

module.exports = cmdFromLeaderMessage;
