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

class robotInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.neighbors = null;
      this.posX = null;
      this.posY = null;
      this.radius = null;
      this.targetX = null;
      this.targetY = null;
    }
    else {
      if (initObj.hasOwnProperty('neighbors')) {
        this.neighbors = initObj.neighbors
      }
      else {
        this.neighbors = [];
      }
      if (initObj.hasOwnProperty('posX')) {
        this.posX = initObj.posX
      }
      else {
        this.posX = 0.0;
      }
      if (initObj.hasOwnProperty('posY')) {
        this.posY = initObj.posY
      }
      else {
        this.posY = 0.0;
      }
      if (initObj.hasOwnProperty('radius')) {
        this.radius = initObj.radius
      }
      else {
        this.radius = 0.0;
      }
      if (initObj.hasOwnProperty('targetX')) {
        this.targetX = initObj.targetX
      }
      else {
        this.targetX = 0.0;
      }
      if (initObj.hasOwnProperty('targetY')) {
        this.targetY = initObj.targetY
      }
      else {
        this.targetY = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robotInfo
    // Serialize message field [neighbors]
    bufferOffset = _arraySerializer.string(obj.neighbors, buffer, bufferOffset, null);
    // Serialize message field [posX]
    bufferOffset = _serializer.float32(obj.posX, buffer, bufferOffset);
    // Serialize message field [posY]
    bufferOffset = _serializer.float32(obj.posY, buffer, bufferOffset);
    // Serialize message field [radius]
    bufferOffset = _serializer.float32(obj.radius, buffer, bufferOffset);
    // Serialize message field [targetX]
    bufferOffset = _serializer.float32(obj.targetX, buffer, bufferOffset);
    // Serialize message field [targetY]
    bufferOffset = _serializer.float32(obj.targetY, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robotInfo
    let len;
    let data = new robotInfo(null);
    // Deserialize message field [neighbors]
    data.neighbors = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [posX]
    data.posX = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [posY]
    data.posY = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [radius]
    data.radius = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [targetX]
    data.targetX = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [targetY]
    data.targetY = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.neighbors.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/robotInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'efd1aeeed9405e7a52385c335c0151bb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #The robot's information that is relayed to the other robots
    
    string[] neighbors #Neighbor robot names
    
    float32 posX # The current position of the robot at x direction
    float32 posY # The current position of the robot at y direction
    
    float32 radius # The radius of the robot
    
    float32 targetX # The current target position of the robot at x direction
    float32 targetY # The current target position of the robot at y direction
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robotInfo(null);
    if (msg.neighbors !== undefined) {
      resolved.neighbors = msg.neighbors;
    }
    else {
      resolved.neighbors = []
    }

    if (msg.posX !== undefined) {
      resolved.posX = msg.posX;
    }
    else {
      resolved.posX = 0.0
    }

    if (msg.posY !== undefined) {
      resolved.posY = msg.posY;
    }
    else {
      resolved.posY = 0.0
    }

    if (msg.radius !== undefined) {
      resolved.radius = msg.radius;
    }
    else {
      resolved.radius = 0.0
    }

    if (msg.targetX !== undefined) {
      resolved.targetX = msg.targetX;
    }
    else {
      resolved.targetX = 0.0
    }

    if (msg.targetY !== undefined) {
      resolved.targetY = msg.targetY;
    }
    else {
      resolved.targetY = 0.0
    }

    return resolved;
    }
};

module.exports = robotInfo;
