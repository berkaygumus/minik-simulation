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

class minikSetVelocityMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motorID = null;
      this.velocity = null;
    }
    else {
      if (initObj.hasOwnProperty('motorID')) {
        this.motorID = initObj.motorID
      }
      else {
        this.motorID = [];
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikSetVelocityMsg
    // Serialize message field [motorID]
    bufferOffset = _arraySerializer.int32(obj.motorID, buffer, bufferOffset, null);
    // Serialize message field [velocity]
    bufferOffset = _arraySerializer.int32(obj.velocity, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikSetVelocityMsg
    let len;
    let data = new minikSetVelocityMsg(null);
    // Deserialize message field [motorID]
    data.motorID = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [velocity]
    data.velocity = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.motorID.length;
    length += 4 * object.velocity.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikSetVelocityMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c8adc9ee4fc03605a59580c725817899';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Set Velocity Command
    
    int32[] motorID
    int32[] velocity
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikSetVelocityMsg(null);
    if (msg.motorID !== undefined) {
      resolved.motorID = msg.motorID;
    }
    else {
      resolved.motorID = []
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = []
    }

    return resolved;
    }
};

module.exports = minikSetVelocityMsg;
