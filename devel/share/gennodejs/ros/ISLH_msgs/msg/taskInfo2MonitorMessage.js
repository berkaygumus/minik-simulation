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

class taskInfo2MonitorMessage {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.taskUUID = null;
      this.encounteringRobotID = null;
      this.responsibleUnit = null;
      this.encounteringTime = null;
      this.startHandlingTime = null;
      this.posXY = null;
      this.taskResource = null;
      this.handlingDuration = null;
      this.timeOutDuration = null;
      this.status = null;
      this.taskSiteRadius = null;
    }
    else {
      if (initObj.hasOwnProperty('taskUUID')) {
        this.taskUUID = initObj.taskUUID
      }
      else {
        this.taskUUID = '';
      }
      if (initObj.hasOwnProperty('encounteringRobotID')) {
        this.encounteringRobotID = initObj.encounteringRobotID
      }
      else {
        this.encounteringRobotID = 0;
      }
      if (initObj.hasOwnProperty('responsibleUnit')) {
        this.responsibleUnit = initObj.responsibleUnit
      }
      else {
        this.responsibleUnit = 0;
      }
      if (initObj.hasOwnProperty('encounteringTime')) {
        this.encounteringTime = initObj.encounteringTime
      }
      else {
        this.encounteringTime = 0;
      }
      if (initObj.hasOwnProperty('startHandlingTime')) {
        this.startHandlingTime = initObj.startHandlingTime
      }
      else {
        this.startHandlingTime = 0;
      }
      if (initObj.hasOwnProperty('posXY')) {
        this.posXY = initObj.posXY
      }
      else {
        this.posXY = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('taskResource')) {
        this.taskResource = initObj.taskResource
      }
      else {
        this.taskResource = '';
      }
      if (initObj.hasOwnProperty('handlingDuration')) {
        this.handlingDuration = initObj.handlingDuration
      }
      else {
        this.handlingDuration = 0;
      }
      if (initObj.hasOwnProperty('timeOutDuration')) {
        this.timeOutDuration = initObj.timeOutDuration
      }
      else {
        this.timeOutDuration = 0;
      }
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
      if (initObj.hasOwnProperty('taskSiteRadius')) {
        this.taskSiteRadius = initObj.taskSiteRadius
      }
      else {
        this.taskSiteRadius = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type taskInfo2MonitorMessage
    // Serialize message field [taskUUID]
    bufferOffset = _serializer.string(obj.taskUUID, buffer, bufferOffset);
    // Serialize message field [encounteringRobotID]
    bufferOffset = _serializer.uint16(obj.encounteringRobotID, buffer, bufferOffset);
    // Serialize message field [responsibleUnit]
    bufferOffset = _serializer.int16(obj.responsibleUnit, buffer, bufferOffset);
    // Serialize message field [encounteringTime]
    bufferOffset = _serializer.uint64(obj.encounteringTime, buffer, bufferOffset);
    // Serialize message field [startHandlingTime]
    bufferOffset = _serializer.uint64(obj.startHandlingTime, buffer, bufferOffset);
    // Serialize message field [posXY]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.posXY, buffer, bufferOffset);
    // Serialize message field [taskResource]
    bufferOffset = _serializer.string(obj.taskResource, buffer, bufferOffset);
    // Serialize message field [handlingDuration]
    bufferOffset = _serializer.uint16(obj.handlingDuration, buffer, bufferOffset);
    // Serialize message field [timeOutDuration]
    bufferOffset = _serializer.uint16(obj.timeOutDuration, buffer, bufferOffset);
    // Serialize message field [status]
    bufferOffset = _serializer.uint16(obj.status, buffer, bufferOffset);
    // Serialize message field [taskSiteRadius]
    bufferOffset = _serializer.uint64(obj.taskSiteRadius, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type taskInfo2MonitorMessage
    let len;
    let data = new taskInfo2MonitorMessage(null);
    // Deserialize message field [taskUUID]
    data.taskUUID = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [encounteringRobotID]
    data.encounteringRobotID = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [responsibleUnit]
    data.responsibleUnit = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [encounteringTime]
    data.encounteringTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [startHandlingTime]
    data.startHandlingTime = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [posXY]
    data.posXY = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [taskResource]
    data.taskResource = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [handlingDuration]
    data.handlingDuration = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [timeOutDuration]
    data.timeOutDuration = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [status]
    data.status = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [taskSiteRadius]
    data.taskSiteRadius = _deserializer.uint64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.taskUUID.length;
    length += object.taskResource.length;
    return length + 66;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ISLH_msgs/taskInfo2MonitorMessage';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '306235d16ea68afd7b8cdaafd193738f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # The task's information to monitoringISLH
    
    string taskUUID # the task's UUID
    
    uint16 encounteringRobotID #robot id which encounters the task
    
    int16 responsibleUnit # "who is responsible for the task"
    
    uint64 encounteringTime #The encountering time
    
    uint64 startHandlingTime #the time when the task starts being handled
    
    geometry_msgs/Point posXY  # The position of the task
    
    string taskResource
    
    uint16 handlingDuration # in seconds - "the required time to handle the task"
    
    uint16 timeOutDuration # "the timed-out duration for the task"
    
    uint16 status # "status of the task"
    
    uint64 taskSiteRadius
    
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
    const resolved = new taskInfo2MonitorMessage(null);
    if (msg.taskUUID !== undefined) {
      resolved.taskUUID = msg.taskUUID;
    }
    else {
      resolved.taskUUID = ''
    }

    if (msg.encounteringRobotID !== undefined) {
      resolved.encounteringRobotID = msg.encounteringRobotID;
    }
    else {
      resolved.encounteringRobotID = 0
    }

    if (msg.responsibleUnit !== undefined) {
      resolved.responsibleUnit = msg.responsibleUnit;
    }
    else {
      resolved.responsibleUnit = 0
    }

    if (msg.encounteringTime !== undefined) {
      resolved.encounteringTime = msg.encounteringTime;
    }
    else {
      resolved.encounteringTime = 0
    }

    if (msg.startHandlingTime !== undefined) {
      resolved.startHandlingTime = msg.startHandlingTime;
    }
    else {
      resolved.startHandlingTime = 0
    }

    if (msg.posXY !== undefined) {
      resolved.posXY = geometry_msgs.msg.Point.Resolve(msg.posXY)
    }
    else {
      resolved.posXY = new geometry_msgs.msg.Point()
    }

    if (msg.taskResource !== undefined) {
      resolved.taskResource = msg.taskResource;
    }
    else {
      resolved.taskResource = ''
    }

    if (msg.handlingDuration !== undefined) {
      resolved.handlingDuration = msg.handlingDuration;
    }
    else {
      resolved.handlingDuration = 0
    }

    if (msg.timeOutDuration !== undefined) {
      resolved.timeOutDuration = msg.timeOutDuration;
    }
    else {
      resolved.timeOutDuration = 0
    }

    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    if (msg.taskSiteRadius !== undefined) {
      resolved.taskSiteRadius = msg.taskSiteRadius;
    }
    else {
      resolved.taskSiteRadius = 0
    }

    return resolved;
    }
};

module.exports = taskInfo2MonitorMessage;
