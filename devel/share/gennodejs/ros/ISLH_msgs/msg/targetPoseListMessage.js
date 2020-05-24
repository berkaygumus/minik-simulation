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

class targetPoseListMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.robotIDs = null;
      this.targetPoses = null;
    }
    else {
      if (initObj.hasOwnProperty('robotIDs')) {
        this.robotIDs = initObj.robotIDs
      }
      else {
        this.robotIDs = [];
      }
      if (initObj.hasOwnProperty('targetPoses')) {
        this.targetPoses = initObj.targetPoses
      }
      else {
        this.targetPoses = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type targetPoseListMessage
    // Serialize message field [robotIDs]
    bufferOffset = _arraySerializer.uint16(obj.robotIDs, buffer, bufferOffset, null);
    // Serialize message field [targetPoses]
    // Serialize the length for message field [targetPoses]
    bufferOffset = _serializer.uint32(obj.targetPoses.length, buffer, bufferOffset);
    obj.targetPoses.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Pose2D.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type targetPoseListMessage
    let len;
    let data = new targetPoseListMessage(null);
    // Deserialize message field [robotIDs]
    data.robotIDs = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [targetPoses]
    // Deserialize array length for message field [targetPoses]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.targetPoses = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.targetPoses[i] = geometry_msgs.msg.Pose2D.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 2 * object.robotIDs.length;
    length += 24 * object.targetPoses.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/targetPoseListMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd1b04727e448336dea593a258b3fabf6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The incoming message (target pose list) from coalition leader
    
    uint16[] robotIDs
    
    geometry_msgs/Pose2D[] targetPoses
    
    ================================================================================
    MSG: geometry_msgs/Pose2D
    # Deprecated
    # Please use the full 3D pose.
    
    # In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.
    
    # If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.
    
    
    # This expresses a position and orientation on a 2D manifold.
    
    float64 x
    float64 y
    float64 theta
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new targetPoseListMessage(null);
    if (msg.robotIDs !== undefined) {
      resolved.robotIDs = msg.robotIDs;
    }
    else {
      resolved.robotIDs = []
    }

    if (msg.targetPoses !== undefined) {
      resolved.targetPoses = new Array(msg.targetPoses.length);
      for (let i = 0; i < resolved.targetPoses.length; ++i) {
        resolved.targetPoses[i] = geometry_msgs.msg.Pose2D.Resolve(msg.targetPoses[i]);
      }
    }
    else {
      resolved.targetPoses = []
    }

    return resolved;
    }
};

module.exports = targetPoseListMessage;
