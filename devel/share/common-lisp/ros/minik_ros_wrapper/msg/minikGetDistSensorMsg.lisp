; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikGetDistSensorMsg.msg.html

(cl:defclass <minikGetDistSensorMsg> (roslisp-msg-protocol:ros-message)
  ((rightSensor
    :reader rightSensor
    :initarg :rightSensor
    :type cl:fixnum
    :initform 0)
   (leftSensor
    :reader leftSensor
    :initarg :leftSensor
    :type cl:fixnum
    :initform 0))
)

(cl:defclass minikGetDistSensorMsg (<minikGetDistSensorMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikGetDistSensorMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikGetDistSensorMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikGetDistSensorMsg> is deprecated: use minik_ros_wrapper-msg:minikGetDistSensorMsg instead.")))

(cl:ensure-generic-function 'rightSensor-val :lambda-list '(m))
(cl:defmethod rightSensor-val ((m <minikGetDistSensorMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:rightSensor-val is deprecated.  Use minik_ros_wrapper-msg:rightSensor instead.")
  (rightSensor m))

(cl:ensure-generic-function 'leftSensor-val :lambda-list '(m))
(cl:defmethod leftSensor-val ((m <minikGetDistSensorMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:leftSensor-val is deprecated.  Use minik_ros_wrapper-msg:leftSensor instead.")
  (leftSensor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikGetDistSensorMsg>) ostream)
  "Serializes a message object of type '<minikGetDistSensorMsg>"
  (cl:let* ((signed (cl:slot-value msg 'rightSensor)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'leftSensor)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikGetDistSensorMsg>) istream)
  "Deserializes a message object of type '<minikGetDistSensorMsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rightSensor) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'leftSensor) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikGetDistSensorMsg>)))
  "Returns string type for a message object of type '<minikGetDistSensorMsg>"
  "minik_ros_wrapper/minikGetDistSensorMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikGetDistSensorMsg)))
  "Returns string type for a message object of type 'minikGetDistSensorMsg"
  "minik_ros_wrapper/minikGetDistSensorMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikGetDistSensorMsg>)))
  "Returns md5sum for a message object of type '<minikGetDistSensorMsg>"
  "ecaa6ae02155044a20eae821d6e0498f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikGetDistSensorMsg)))
  "Returns md5sum for a message object of type 'minikGetDistSensorMsg"
  "ecaa6ae02155044a20eae821d6e0498f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikGetDistSensorMsg>)))
  "Returns full string definition for message of type '<minikGetDistSensorMsg>"
  (cl:format cl:nil "# Minik Get Sharp Distance Sensor Message~%~%int16 rightSensor~%int16 leftSensor~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikGetDistSensorMsg)))
  "Returns full string definition for message of type 'minikGetDistSensorMsg"
  (cl:format cl:nil "# Minik Get Sharp Distance Sensor Message~%~%int16 rightSensor~%int16 leftSensor~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikGetDistSensorMsg>))
  (cl:+ 0
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikGetDistSensorMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikGetDistSensorMsg
    (cl:cons ':rightSensor (rightSensor msg))
    (cl:cons ':leftSensor (leftSensor msg))
))
