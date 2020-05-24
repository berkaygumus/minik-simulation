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

class inMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robotid = null;
      this.messageid = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('robotid')) {
        this.robotid = initObj.robotid
      }
      else {
        this.robotid = 0;
      }
      if (initObj.hasOwnProperty('messageid')) {
        this.messageid = initObj.messageid
      }
      else {
        this.messageid = 0;
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
    // Serializes a message object of type inMessage
    // Serialize message field [robotid]
    bufferOffset = _serializer.uint16(obj.robotid, buffer, bufferOffset);
    // Serialize message field [messageid]
    bufferOffset = _serializer.uint16(obj.messageid, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type inMessage
    let len;
    let data = new inMessage(null);
    // Deserialize message field [robotid]
    data.robotid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [messageid]
    data.messageid = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [message]
    data.message = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.message.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/inMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '29816f7dd48299059674f73ccfcba3d5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Incoming messages
    
    uint16 robotid #sender id
    
    uint16 messageid
    
    string message #message
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new inMessage(null);
    if (msg.robotid !== undefined) {
      resolved.robotid = msg.robotid;
    }
    else {
      resolved.robotid = 0
    }

    if (msg.messageid !== undefined) {
      resolved.messageid = msg.messageid;
    }
    else {
      resolved.messageid = 0
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

module.exports = inMessage;
