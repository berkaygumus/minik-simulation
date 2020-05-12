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

class minikSetPositionMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motorID = null;
      this.position = null;
    }
    else {
      if (initObj.hasOwnProperty('motorID')) {
        this.motorID = initObj.motorID
      }
      else {
        this.motorID = [];
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikSetPositionMsg
    // Serialize message field [motorID]
    bufferOffset = _arraySerializer.int32(obj.motorID, buffer, bufferOffset, null);
    // Serialize message field [position]
    bufferOffset = _arraySerializer.int32(obj.position, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikSetPositionMsg
    let len;
    let data = new minikSetPositionMsg(null);
    // Deserialize message field [motorID]
    data.motorID = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [position]
    data.position = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.motorID.length;
    length += 4 * object.position.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikSetPositionMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '121261aaf42c6b46f74e88a84eea6cde';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Set Position Command
    
    int32[] motorID
    int32[] position
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikSetPositionMsg(null);
    if (msg.motorID !== undefined) {
      resolved.motorID = msg.motorID;
    }
    else {
      resolved.motorID = []
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = []
    }

    return resolved;
    }
};

module.exports = minikSetPositionMsg;
