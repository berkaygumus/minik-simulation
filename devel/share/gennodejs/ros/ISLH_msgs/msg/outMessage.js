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

class outMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robotid = null;
      this.messageTypeID = null;
      this.messageIndx = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('robotid')) {
        this.robotid = initObj.robotid
      }
      else {
        this.robotid = [];
      }
      if (initObj.hasOwnProperty('messageTypeID')) {
        this.messageTypeID = initObj.messageTypeID
      }
      else {
        this.messageTypeID = [];
      }
      if (initObj.hasOwnProperty('messageIndx')) {
        this.messageIndx = initObj.messageIndx
      }
      else {
        this.messageIndx = [];
      }
      if (initObj.hasOwnProperty('message')) {
        this.message = initObj.message
      }
      else {
        this.message = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type outMessage
    // Serialize message field [robotid]
    bufferOffset = _arraySerializer.uint16(obj.robotid, buffer, bufferOffset, null);
    // Serialize message field [messageTypeID]
    bufferOffset = _arraySerializer.uint16(obj.messageTypeID, buffer, bufferOffset, null);
    // Serialize message field [messageIndx]
    bufferOffset = _arraySerializer.uint16(obj.messageIndx, buffer, bufferOffset, null);
    // Serialize message field [message]
    bufferOffset = _arraySerializer.string(obj.message, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type outMessage
    let len;
    let data = new outMessage(null);
    // Deserialize message field [robotid]
    data.robotid = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [messageTypeID]
    data.messageTypeID = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [messageIndx]
    data.messageIndx = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [message]
    data.message = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 2 * object.robotid.length;
    length += 2 * object.messageTypeID.length;
    length += 2 * object.messageIndx.length;
    object.message.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/outMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8e9310b478059d7c506189771b569d0d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # outgoing  messages
    
    uint16[] robotid #receiver id
    
    uint16[] messageTypeID
    
    uint16[] messageIndx # which message is sent to which robot
    
    string[] message #message
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new outMessage(null);
    if (msg.robotid !== undefined) {
      resolved.robotid = msg.robotid;
    }
    else {
      resolved.robotid = []
    }

    if (msg.messageTypeID !== undefined) {
      resolved.messageTypeID = msg.messageTypeID;
    }
    else {
      resolved.messageTypeID = []
    }

    if (msg.messageIndx !== undefined) {
      resolved.messageIndx = msg.messageIndx;
    }
    else {
      resolved.messageIndx = []
    }

    if (msg.message !== undefined) {
      resolved.message = msg.message;
    }
    else {
      resolved.message = []
    }

    return resolved;
    }
};

module.exports = outMessage;
