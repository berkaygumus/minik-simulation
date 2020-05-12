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

class minikGetPositionMsg {
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
        this.motorID = 0;
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikGetPositionMsg
    // Serialize message field [motorID]
    bufferOffset = _serializer.int32(obj.motorID, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = _serializer.int32(obj.position, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikGetPositionMsg
    let len;
    let data = new minikGetPositionMsg(null);
    // Deserialize message field [motorID]
    data.motorID = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikGetPositionMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9484186d0d818e0301bf0d58107b9a65';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Get Position Message
    
    int32 motorID
    int32 position
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikGetPositionMsg(null);
    if (msg.motorID !== undefined) {
      resolved.motorID = msg.motorID;
    }
    else {
      resolved.motorID = 0
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = 0
    }

    return resolved;
    }
};

module.exports = minikGetPositionMsg;
