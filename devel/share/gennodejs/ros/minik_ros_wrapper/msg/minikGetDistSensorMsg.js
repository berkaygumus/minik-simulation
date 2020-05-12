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

class minikGetDistSensorMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.rightSensor = null;
      this.leftSensor = null;
    }
    else {
      if (initObj.hasOwnProperty('rightSensor')) {
        this.rightSensor = initObj.rightSensor
      }
      else {
        this.rightSensor = 0;
      }
      if (initObj.hasOwnProperty('leftSensor')) {
        this.leftSensor = initObj.leftSensor
      }
      else {
        this.leftSensor = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikGetDistSensorMsg
    // Serialize message field [rightSensor]
    bufferOffset = _serializer.int16(obj.rightSensor, buffer, bufferOffset);
    // Serialize message field [leftSensor]
    bufferOffset = _serializer.int16(obj.leftSensor, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikGetDistSensorMsg
    let len;
    let data = new minikGetDistSensorMsg(null);
    // Deserialize message field [rightSensor]
    data.rightSensor = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [leftSensor]
    data.leftSensor = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikGetDistSensorMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ecaa6ae02155044a20eae821d6e0498f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Get Sharp Distance Sensor Message
    
    int16 rightSensor
    int16 leftSensor
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikGetDistSensorMsg(null);
    if (msg.rightSensor !== undefined) {
      resolved.rightSensor = msg.rightSensor;
    }
    else {
      resolved.rightSensor = 0
    }

    if (msg.leftSensor !== undefined) {
      resolved.leftSensor = msg.leftSensor;
    }
    else {
      resolved.leftSensor = 0
    }

    return resolved;
    }
};

module.exports = minikGetDistSensorMsg;
