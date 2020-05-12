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

class minikGetVelocityMsg {
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
        this.motorID = 0;
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikGetVelocityMsg
    // Serialize message field [motorID]
    bufferOffset = _serializer.int32(obj.motorID, buffer, bufferOffset);
    // Serialize message field [velocity]
    bufferOffset = _serializer.int16(obj.velocity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikGetVelocityMsg
    let len;
    let data = new minikGetVelocityMsg(null);
    // Deserialize message field [motorID]
    data.motorID = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [velocity]
    data.velocity = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikGetVelocityMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a94dbef25ebdc880900454ec307048c1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Get Velocity Message
    
    int32 motorID
    int16 velocity
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikGetVelocityMsg(null);
    if (msg.motorID !== undefined) {
      resolved.motorID = msg.motorID;
    }
    else {
      resolved.motorID = 0
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = 0
    }

    return resolved;
    }
};

module.exports = minikGetVelocityMsg;
