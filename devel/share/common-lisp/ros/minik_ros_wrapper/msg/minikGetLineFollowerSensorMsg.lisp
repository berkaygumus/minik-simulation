; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikGetLineFollowerSensorMsg.msg.html

(cl:defclass <minikGetLineFollowerSensorMsg> (roslisp-msg-protocol:ros-message)
  ((rightSensor
    :reader rightSensor
    :initarg :rightSensor
    :type cl:integer
    :initform 0)
   (middleSensor
    :reader middleSensor
    :initarg :middleSensor
    :type cl:integer
    :initform 0)
   (leftSensor
    :reader leftSensor
    :initarg :leftSensor
    :type cl:integer
    :initform 0))
)

(cl:defclass minikGetLineFollowerSensorMsg (<minikGetLineFollowerSensorMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikGetLineFollowerSensorMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikGetLineFollowerSensorMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikGetLineFollowerSensorMsg> is deprecated: use minik_ros_wrapper-msg:minikGetLineFollowerSensorMsg instead.")))

(cl:ensure-generic-function 'rightSensor-val :lambda-list '(m))
(cl:defmethod rightSensor-val ((m <minikGetLineFollowerSensorMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:rightSensor-val is deprecated.  Use minik_ros_wrapper-msg:rightSensor instead.")
  (rightSensor m))

(cl:ensure-generic-function 'middleSensor-val :lambda-list '(m))
(cl:defmethod middleSensor-val ((m <minikGetLineFollowerSensorMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:middleSensor-val is deprecated.  Use minik_ros_wrapper-msg:middleSensor instead.")
  (middleSensor m))

(cl:ensure-generic-function 'leftSensor-val :lambda-list '(m))
(cl:defmethod leftSensor-val ((m <minikGetLineFollowerSensorMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:leftSensor-val is deprecated.  Use minik_ros_wrapper-msg:leftSensor instead.")
  (leftSensor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikGetLineFollowerSensorMsg>) ostream)
  "Serializes a message object of type '<minikGetLineFollowerSensorMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rightSensor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'middleSensor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'leftSensor)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikGetLineFollowerSensorMsg>) istream)
  "Deserializes a message object of type '<minikGetLineFollowerSensorMsg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rightSensor)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'middleSensor)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'leftSensor)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikGetLineFollowerSensorMsg>)))
  "Returns string type for a message object of type '<minikGetLineFollowerSensorMsg>"
  "minik_ros_wrapper/minikGetLineFollowerSensorMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikGetLineFollowerSensorMsg)))
  "Returns string type for a message object of type 'minikGetLineFollowerSensorMsg"
  "minik_ros_wrapper/minikGetLineFollowerSensorMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikGetLineFollowerSensorMsg>)))
  "Returns md5sum for a message object of type '<minikGetLineFollowerSensorMsg>"
  "117f4dd679610c07fd2b537377a09014")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikGetLineFollowerSensorMsg)))
  "Returns md5sum for a message object of type 'minikGetLineFollowerSensorMsg"
  "117f4dd679610c07fd2b537377a09014")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikGetLineFollowerSensorMsg>)))
  "Returns full string definition for message of type '<minikGetLineFollowerSensorMsg>"
  (cl:format cl:nil "# Minik Get Line Follower Message~%~%char rightSensor~%char middleSensor~%char leftSensor~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikGetLineFollowerSensorMsg)))
  "Returns full string definition for message of type 'minikGetLineFollowerSensorMsg"
  (cl:format cl:nil "# Minik Get Line Follower Message~%~%char rightSensor~%char middleSensor~%char leftSensor~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikGetLineFollowerSensorMsg>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikGetLineFollowerSensorMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikGetLineFollowerSensorMsg
    (cl:cons ':rightSensor (rightSensor msg))
    (cl:cons ':middleSensor (middleSensor msg))
    (cl:cons ':leftSensor (leftSensor msg))
))
