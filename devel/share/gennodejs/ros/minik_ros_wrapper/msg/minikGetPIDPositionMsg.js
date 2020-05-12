// Auto-generated. Do not edit!

// (in-package minik_ros_wrapper.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class minikGetPIDPositionMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motorID = null;
      this.P = null;
      this.I = null;
      this.D = null;
    }
    else {
      if (initObj.hasOwnProperty('motorID')) {
        this.motorID = initObj.motorID
      }
      else {
        this.motorID = 0;
      }
      if (initObj.hasOwnProperty('P')) {
        this.P = initObj.P
      }
      else {
        this.P = 0;
      }
      if (initObj.hasOwnProperty('I')) {
        this.I = initObj.I
      }
      else {
        this.I = 0;
      }
      if (initObj.hasOwnProperty('D')) {
        this.D = initObj.D
      }
      else {
        this.D = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikGetPIDPositionMsg
    // Serialize message field [motorID]
    bufferOffset = _serializer.int32(obj.motorID, buffer, bufferOffset);
    // Serialize message field [P]
    bufferOffset = _serializer.char(obj.P, buffer, bufferOffset);
    // Serialize message field [I]
    bufferOffset = _serializer.char(obj.I, buffer, bufferOffset);
    // Serialize message field [D]
    bufferOffset = _serializer.char(obj.D, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikGetPIDPositionMsg
    let len;
    let data = new minikGetPIDPositionMsg(null);
    // Deserialize message field [motorID]
    data.motorID = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [P]
    data.P = _deserializer.char(buffer, bufferOffset);
    // Deserialize message field [I]
    data.I = _deserializer.char(buffer, bufferOffset);
    // Deserialize message field [D]
    data.D = _deserializer.char(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 7;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikGetPIDPositionMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e7ffde16b01cf7c9fd96dfa04f0bfdc6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Get Position PID Message
    
    int32 motorID
    char P
    char I
    char D
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikGetPIDPositionMsg(null);
    if (msg.motorID !== undefined) {
      resolved.motorID = msg.motorID;
    }
    else {
      resolved.motorID = 0
    }

    if (msg.P !== undefined) {
      resolved.P = msg.P;
    }
    else {
      resolved.P = 0
    }

    if (msg.I !== undefined) {
      resolved.I = msg.I;
    }
    else {
      resolved.I = 0
    }

    if (msg.D !== undefined) {
      resolved.D = msg.D;
    }
    else {
      resolved.D = 0
    }

    return resolved;
    }
};

module.exports = minikGetPIDPositionMsg;
