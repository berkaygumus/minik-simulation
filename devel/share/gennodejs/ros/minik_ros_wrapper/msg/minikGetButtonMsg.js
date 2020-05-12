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

class minikGetButtonMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.isButton1Pressed = null;
      this.isButton2Pressed = null;
      this.isButton3Pressed = null;
    }
    else {
      if (initObj.hasOwnProperty('isButton1Pressed')) {
        this.isButton1Pressed = initObj.isButton1Pressed
      }
      else {
        this.isButton1Pressed = false;
      }
      if (initObj.hasOwnProperty('isButton2Pressed')) {
        this.isButton2Pressed = initObj.isButton2Pressed
      }
      else {
        this.isButton2Pressed = false;
      }
      if (initObj.hasOwnProperty('isButton3Pressed')) {
        this.isButton3Pressed = initObj.isButton3Pressed
      }
      else {
        this.isButton3Pressed = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikGetButtonMsg
    // Serialize message field [isButton1Pressed]
    bufferOffset = _serializer.bool(obj.isButton1Pressed, buffer, bufferOffset);
    // Serialize message field [isButton2Pressed]
    bufferOffset = _serializer.bool(obj.isButton2Pressed, buffer, bufferOffset);
    // Serialize message field [isButton3Pressed]
    bufferOffset = _serializer.bool(obj.isButton3Pressed, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikGetButtonMsg
    let len;
    let data = new minikGetButtonMsg(null);
    // Deserialize message field [isButton1Pressed]
    data.isButton1Pressed = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [isButton2Pressed]
    data.isButton2Pressed = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [isButton3Pressed]
    data.isButton3Pressed = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikGetButtonMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3853358d8e2e329f368156066a21f0b2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Get Button Message
    
    bool isButton1Pressed
    bool isButton2Pressed
    bool isButton3Pressed
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikGetButtonMsg(null);
    if (msg.isButton1Pressed !== undefined) {
      resolved.isButton1Pressed = msg.isButton1Pressed;
    }
    else {
      resolved.isButton1Pressed = false
    }

    if (msg.isButton2Pressed !== undefined) {
      resolved.isButton2Pressed = msg.isButton2Pressed;
    }
    else {
      resolved.isButton2Pressed = false
    }

    if (msg.isButton3Pressed !== undefined) {
      resolved.isButton3Pressed = msg.isButton3Pressed;
    }
    else {
      resolved.isButton3Pressed = false
    }

    return resolved;
    }
};

module.exports = minikGetButtonMsg;
