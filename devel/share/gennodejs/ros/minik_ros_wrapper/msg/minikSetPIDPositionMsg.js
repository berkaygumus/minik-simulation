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

class minikSetPIDPositionMsg {
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
        this.motorID = [];
      }
      if (initObj.hasOwnProperty('P')) {
        this.P = initObj.P
      }
      else {
        this.P = [];
      }
      if (initObj.hasOwnProperty('I')) {
        this.I = initObj.I
      }
      else {
        this.I = [];
      }
      if (initObj.hasOwnProperty('D')) {
        this.D = initObj.D
      }
      else {
        this.D = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikSetPIDPositionMsg
    // Serialize message field [motorID]
    bufferOffset = _arraySerializer.int32(obj.motorID, buffer, bufferOffset, null);
    // Serialize message field [P]
    bufferOffset = _arraySerializer.char(obj.P, buffer, bufferOffset, null);
    // Serialize message field [I]
    bufferOffset = _arraySerializer.char(obj.I, buffer, bufferOffset, null);
    // Serialize message field [D]
    bufferOffset = _arraySerializer.char(obj.D, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikSetPIDPositionMsg
    let len;
    let data = new minikSetPIDPositionMsg(null);
    // Deserialize message field [motorID]
    data.motorID = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [P]
    data.P = _arrayDeserializer.char(buffer, bufferOffset, null)
    // Deserialize message field [I]
    data.I = _arrayDeserializer.char(buffer, bufferOffset, null)
    // Deserialize message field [D]
    data.D = _arrayDeserializer.char(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.motorID.length;
    length += object.P.length;
    length += object.I.length;
    length += object.D.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikSetPIDPositionMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd3c57d08264ba7635ea33c90d92b0139';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Set Position PID Message
    
    int32[] motorID
    char[] P
    char[] I
    char[] D
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikSetPIDPositionMsg(null);
    if (msg.motorID !== undefined) {
      resolved.motorID = msg.motorID;
    }
    else {
      resolved.motorID = []
    }

    if (msg.P !== undefined) {
      resolved.P = msg.P;
    }
    else {
      resolved.P = []
    }

    if (msg.I !== undefined) {
      resolved.I = msg.I;
    }
    else {
      resolved.I = []
    }

    if (msg.D !== undefined) {
      resolved.D = msg.D;
    }
    else {
      resolved.D = []
    }

    return resolved;
    }
};

module.exports = minikSetPIDPositionMsg;
