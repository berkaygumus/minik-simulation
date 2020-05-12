; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikSetConfigMsg.msg.html

(cl:defclass <minikSetConfigMsg> (roslisp-msg-protocol:ros-message)
  ((isSpeedSendON
    :reader isSpeedSendON
    :initarg :isSpeedSendON
    :type cl:boolean
    :initform cl:nil)
   (isPositionSendON
    :reader isPositionSendON
    :initarg :isPositionSendON
    :type cl:boolean
    :initform cl:nil)
   (frequency
    :reader frequency
    :initarg :frequency
    :type cl:integer
    :initform 0))
)

(cl:defclass minikSetConfigMsg (<minikSetConfigMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikSetConfigMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikSetConfigMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikSetConfigMsg> is deprecated: use minik_ros_wrapper-msg:minikSetConfigMsg instead.")))

(cl:ensure-generic-function 'isSpeedSendON-val :lambda-list '(m))
(cl:defmethod isSpeedSendON-val ((m <minikSetConfigMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isSpeedSendON-val is deprecated.  Use minik_ros_wrapper-msg:isSpeedSendON instead.")
  (isSpeedSendON m))

(cl:ensure-generic-function 'isPositionSendON-val :lambda-list '(m))
(cl:defmethod isPositionSendON-val ((m <minikSetConfigMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isPositionSendON-val is deprecated.  Use minik_ros_wrapper-msg:isPositionSendON instead.")
  (isPositionSendON m))

(cl:ensure-generic-function 'frequency-val :lambda-list '(m))
(cl:defmethod frequency-val ((m <minikSetConfigMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:frequency-val is deprecated.  Use minik_ros_wrapper-msg:frequency instead.")
  (frequency m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikSetConfigMsg>) ostream)
  "Serializes a message object of type '<minikSetConfigMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isSpeedSendON) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isPositionSendON) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frequency)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikSetConfigMsg>) istream)
  "Deserializes a message object of type '<minikSetConfigMsg>"
    (cl:setf (cl:slot-value msg 'isSpeedSendON) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'isPositionSendON) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frequency)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikSetConfigMsg>)))
  "Returns string type for a message object of type '<minikSetConfigMsg>"
  "minik_ros_wrapper/minikSetConfigMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikSetConfigMsg)))
  "Returns string type for a message object of type 'minikSetConfigMsg"
  "minik_ros_wrapper/minikSetConfigMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikSetConfigMsg>)))
  "Returns md5sum for a message object of type '<minikSetConfigMsg>"
  "e4dff864fd41bf1461aaa087ae928002")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikSetConfigMsg)))
  "Returns md5sum for a message object of type 'minikSetConfigMsg"
  "e4dff864fd41bf1461aaa087ae928002")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikSetConfigMsg>)))
  "Returns full string definition for message of type '<minikSetConfigMsg>"
  (cl:format cl:nil "# Minik Set Config Command~%~%bool isSpeedSendON~%bool isPositionSendON~%char frequency~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikSetConfigMsg)))
  "Returns full string definition for message of type 'minikSetConfigMsg"
  (cl:format cl:nil "# Minik Set Config Command~%~%bool isSpeedSendON~%bool isPositionSendON~%char frequency~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikSetConfigMsg>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikSetConfigMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikSetConfigMsg
    (cl:cons ':isSpeedSendON (isSpeedSendON msg))
    (cl:cons ':isPositionSendON (isPositionSendON msg))
    (cl:cons ':frequency (frequency msg))
))
