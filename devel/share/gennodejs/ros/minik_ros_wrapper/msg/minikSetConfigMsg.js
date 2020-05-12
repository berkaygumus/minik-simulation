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

class minikSetConfigMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.isSpeedSendON = null;
      this.isPositionSendON = null;
      this.frequency = null;
    }
    else {
      if (initObj.hasOwnProperty('isSpeedSendON')) {
        this.isSpeedSendON = initObj.isSpeedSendON
      }
      else {
        this.isSpeedSendON = false;
      }
      if (initObj.hasOwnProperty('isPositionSendON')) {
        this.isPositionSendON = initObj.isPositionSendON
      }
      else {
        this.isPositionSendON = false;
      }
      if (initObj.hasOwnProperty('frequency')) {
        this.frequency = initObj.frequency
      }
      else {
        this.frequency = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type minikSetConfigMsg
    // Serialize message field [isSpeedSendON]
    bufferOffset = _serializer.bool(obj.isSpeedSendON, buffer, bufferOffset);
    // Serialize message field [isPositionSendON]
    bufferOffset = _serializer.bool(obj.isPositionSendON, buffer, bufferOffset);
    // Serialize message field [frequency]
    bufferOffset = _serializer.char(obj.frequency, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type minikSetConfigMsg
    let len;
    let data = new minikSetConfigMsg(null);
    // Deserialize message field [isSpeedSendON]
    data.isSpeedSendON = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [isPositionSendON]
    data.isPositionSendON = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [frequency]
    data.frequency = _deserializer.char(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'minik_ros_wrapper/minikSetConfigMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e4dff864fd41bf1461aaa087ae928002';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Minik Set Config Command
    
    bool isSpeedSendON
    bool isPositionSendON
    char frequency
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new minikSetConfigMsg(null);
    if (msg.isSpeedSendON !== undefined) {
      resolved.isSpeedSendON = msg.isSpeedSendON;
    }
    else {
      resolved.isSpeedSendON = false
    }

    if (msg.isPositionSendON !== undefined) {
      resolved.isPositionSendON = msg.isPositionSendON;
    }
    else {
      resolved.isPositionSendON = false
    }

    if (msg.frequency !== undefined) {
      resolved.frequency = msg.frequency;
    }
    else {
      resolved.frequency = 0
    }

    return resolved;
    }
};

module.exports = minikSetConfigMsg;
