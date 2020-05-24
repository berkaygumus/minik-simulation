// Auto-generated. Do not edit!

// (in-package ISLH_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class robotPose {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.id = null;
      this.position = null;
      this.target = null;
      this.calYaw = null;
      this.radYaw = null;
    }
    else {
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('target')) {
        this.target = initObj.target
      }
      else {
        this.target = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('calYaw')) {
        this.calYaw = initObj.calYaw
      }
      else {
        this.calYaw = 0.0;
      }
      if (initObj.hasOwnProperty('radYaw')) {
        this.radYaw = initObj.radYaw
      }
      else {
        this.radYaw = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robotPose
    // Serialize message field [id]
    bufferOffset = _serializer.int32(obj.id, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.position, buffer, bufferOffset);
    // Serialize message field [target]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.target, buffer, bufferOffset);
    // Serialize message field [calYaw]
    bufferOffset = _serializer.float32(obj.calYaw, buffer, bufferOffset);
    // Serialize message field [radYaw]
    bufferOffset = _serializer.float32(obj.radYaw, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robotPose
    let len;
    let data = new robotPose(null);
    // Deserialize message field [id]
    data.id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [target]
    data.target = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [calYaw]
    data.calYaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [radYaw]
    data.radYaw = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 60;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/robotPose';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0eef6d6e44271c92907c87eea9d5073a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #The robot's position information and target information
    
    int32 id
    
    geometry_msgs/Point position
    
    geometry_msgs/Point target
    
    float32 calYaw
    float32 radYaw
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robotPose(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.position !== undefined) {
      resolved.position = geometry_msgs.msg.Point.Resolve(msg.position)
    }
    else {
      resolved.position = new geometry_msgs.msg.Point()
    }

    if (msg.target !== undefined) {
      resolved.target = geometry_msgs.msg.Point.Resolve(msg.target)
    }
    else {
      resolved.target = new geometry_msgs.msg.Point()
    }

    if (msg.calYaw !== undefined) {
      resolved.calYaw = msg.calYaw;
    }
    else {
      resolved.calYaw = 0.0
    }

    if (msg.radYaw !== undefined) {
      resolved.radYaw = msg.radYaw;
    }
    else {
      resolved.radYaw = 0.0
    }

    return resolved;
    }
};

module.exports = robotPose;
