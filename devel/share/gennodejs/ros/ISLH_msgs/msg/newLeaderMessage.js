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

class newLeaderMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sendingTime = null;
      this.infoTypeID = null;
      this.infoMessage = null;
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
      if (initObj.hasOwnProperty('infoMessage')) {
        this.infoMessage = initObj.infoMessage
      }
      else {
        this.infoMessage = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type newLeaderMessage
    // Serialize message field [sendingTime]
    bufferOffset = _serializer.uint64(obj.sendingTime, buffer, bufferOffset);
    // Serialize message field [infoTypeID]
    bufferOffset = _serializer.uint16(obj.infoTypeID, buffer, bufferOffset);
    // Serialize message field [infoMessage]
    bufferOffset = _serializer.string(obj.infoMessage, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type newLeaderMessage
    let len;
    let data = new newLeaderMessage(null);
    // Deserialize message field [sendingTime]
    data.sendingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [infoTypeID]
    data.infoTypeID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [infoMessage]
    data.infoMessage = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.infoMessage.length;
    return length + 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/newLeaderMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e3baee834452566b366f59c79fcdfa75';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The incoming info message from old coalition leader to new coalition leader
    
    uint64 sendingTime #The sending time
    
    uint16 infoTypeID
    
    string infoMessage
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new newLeaderMessage(null);
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

    if (msg.infoMessage !== undefined) {
      resolved.infoMessage = msg.infoMessage;
    }
    else {
      resolved.infoMessage = ''
    }

    return resolved;
    }
};

module.exports = newLeaderMessage;
