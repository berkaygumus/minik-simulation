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

class cmd2RobotsFromLeaderMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.receiverRobotID = null;
      this.sendingTime = null;
      this.cmdTypeID = null;
      this.cmdMessage = null;
    }
    else {
      if (initObj.hasOwnProperty('receiverRobotID')) {
        this.receiverRobotID = initObj.receiverRobotID
      }
      else {
        this.receiverRobotID = [];
      }
      if (initObj.hasOwnProperty('sendingTime')) {
        this.sendingTime = initObj.sendingTime
      }
      else {
        this.sendingTime = 0;
      }
      if (initObj.hasOwnProperty('cmdTypeID')) {
        this.cmdTypeID = initObj.cmdTypeID
      }
      else {
        this.cmdTypeID = 0;
      }
      if (initObj.hasOwnProperty('cmdMessage')) {
        this.cmdMessage = initObj.cmdMessage
      }
      else {
        this.cmdMessage = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type cmd2RobotsFromLeaderMessage
    // Serialize message field [receiverRobotID]
    bufferOffset = _arraySerializer.uint16(obj.receiverRobotID, buffer, bufferOffset, null);
    // Serialize message field [sendingTime]
    bufferOffset = _serializer.uint64(obj.sendingTime, buffer, bufferOffset);
    // Serialize message field [cmdTypeID]
    bufferOffset = _serializer.uint16(obj.cmdTypeID, buffer, bufferOffset);
    // Serialize message field [cmdMessage]
    bufferOffset = _serializer.string(obj.cmdMessage, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type cmd2RobotsFromLeaderMessage
    let len;
    let data = new cmd2RobotsFromLeaderMessage(null);
    // Deserialize message field [receiverRobotID]
    data.receiverRobotID = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [sendingTime]
    data.sendingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [cmdTypeID]
    data.cmdTypeID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [cmdMessage]
    data.cmdMessage = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 2 * object.receiverRobotID.length;
    length += object.cmdMessage.length;
    return length + 18;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/cmd2RobotsFromLeaderMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '56a7753bb3b7a241e2936846abb3f9d4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The outgoing command message from coalition leader
    
    uint16[] receiverRobotID
    
    uint64 sendingTime #The sending time
    
    uint16 cmdTypeID
    
    string cmdMessage
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new cmd2RobotsFromLeaderMessage(null);
    if (msg.receiverRobotID !== undefined) {
      resolved.receiverRobotID = msg.receiverRobotID;
    }
    else {
      resolved.receiverRobotID = []
    }

    if (msg.sendingTime !== undefined) {
      resolved.sendingTime = msg.sendingTime;
    }
    else {
      resolved.sendingTime = 0
    }

    if (msg.cmdTypeID !== undefined) {
      resolved.cmdTypeID = msg.cmdTypeID;
    }
    else {
      resolved.cmdTypeID = 0
    }

    if (msg.cmdMessage !== undefined) {
      resolved.cmdMessage = msg.cmdMessage;
    }
    else {
      resolved.cmdMessage = ''
    }

    return resolved;
    }
};

module.exports = cmd2RobotsFromLeaderMessage;
