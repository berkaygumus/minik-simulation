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

class cmd2LeadersMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.leaderRobotID = null;
      this.sendingTime = null;
      this.messageTypeID = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('leaderRobotID')) {
        this.leaderRobotID = initObj.leaderRobotID
      }
      else {
        this.leaderRobotID = [];
      }
      if (initObj.hasOwnProperty('sendingTime')) {
        this.sendingTime = initObj.sendingTime
      }
      else {
        this.sendingTime = 0;
      }
      if (initObj.hasOwnProperty('messageTypeID')) {
        this.messageTypeID = initObj.messageTypeID
      }
      else {
        this.messageTypeID = [];
      }
      if (initObj.hasOwnProperty('message')) {
        this.message = initObj.message
      }
      else {
        this.message = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type cmd2LeadersMessage
    // Serialize message field [leaderRobotID]
    bufferOffset = _arraySerializer.uint16(obj.leaderRobotID, buffer, bufferOffset, null);
    // Serialize message field [sendingTime]
    bufferOffset = _serializer.uint64(obj.sendingTime, buffer, bufferOffset);
    // Serialize message field [messageTypeID]
    bufferOffset = _arraySerializer.uint16(obj.messageTypeID, buffer, bufferOffset, null);
    // Serialize message field [message]
    bufferOffset = _arraySerializer.string(obj.message, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type cmd2LeadersMessage
    let len;
    let data = new cmd2LeadersMessage(null);
    // Deserialize message field [leaderRobotID]
    data.leaderRobotID = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [sendingTime]
    data.sendingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [messageTypeID]
    data.messageTypeID = _arrayDeserializer.uint16(buffer, bufferOffset, null)
    // Deserialize message field [message]
    data.message = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 2 * object.leaderRobotID.length;
    length += 2 * object.messageTypeID.length;
    object.message.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/cmd2LeadersMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dea84c50c103ccf3d723b1874cc1b015';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The task's information from coalition leader
    
    uint16[] leaderRobotID #robot id to which the message will be sent 
    
    uint64 sendingTime #The sending time
    
    uint16[] messageTypeID
    
    string[] message
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new cmd2LeadersMessage(null);
    if (msg.leaderRobotID !== undefined) {
      resolved.leaderRobotID = msg.leaderRobotID;
    }
    else {
      resolved.leaderRobotID = []
    }

    if (msg.sendingTime !== undefined) {
      resolved.sendingTime = msg.sendingTime;
    }
    else {
      resolved.sendingTime = 0
    }

    if (msg.messageTypeID !== undefined) {
      resolved.messageTypeID = msg.messageTypeID;
    }
    else {
      resolved.messageTypeID = []
    }

    if (msg.message !== undefined) {
      resolved.message = msg.message;
    }
    else {
      resolved.message = []
    }

    return resolved;
    }
};

module.exports = cmd2LeadersMessage;
