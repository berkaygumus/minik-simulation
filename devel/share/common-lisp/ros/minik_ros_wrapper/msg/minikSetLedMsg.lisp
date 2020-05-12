; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikSetLedMsg.msg.html

(cl:defclass <minikSetLedMsg> (roslisp-msg-protocol:ros-message)
  ((isLed1ON
    :reader isLed1ON
    :initarg :isLed1ON
    :type cl:boolean
    :initform cl:nil)
   (isLed2ON
    :reader isLed2ON
    :initarg :isLed2ON
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass minikSetLedMsg (<minikSetLedMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikSetLedMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikSetLedMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikSetLedMsg> is deprecated: use minik_ros_wrapper-msg:minikSetLedMsg instead.")))

(cl:ensure-generic-function 'isLed1ON-val :lambda-list '(m))
(cl:defmethod isLed1ON-val ((m <minikSetLedMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isLed1ON-val is deprecated.  Use minik_ros_wrapper-msg:isLed1ON instead.")
  (isLed1ON m))

(cl:ensure-generic-function 'isLed2ON-val :lambda-list '(m))
(cl:defmethod isLed2ON-val ((m <minikSetLedMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isLed2ON-val is deprecated.  Use minik_ros_wrapper-msg:isLed2ON instead.")
  (isLed2ON m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikSetLedMsg>) ostream)
  "Serializes a message object of type '<minikSetLedMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isLed1ON) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isLed2ON) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikSetLedMsg>) istream)
  "Deserializes a message object of type '<minikSetLedMsg>"
    (cl:setf (cl:slot-value msg 'isLed1ON) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'isLed2ON) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikSetLedMsg>)))
  "Returns string type for a message object of type '<minikSetLedMsg>"
  "minik_ros_wrapper/minikSetLedMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikSetLedMsg)))
  "Returns string type for a message object of type 'minikSetLedMsg"
  "minik_ros_wrapper/minikSetLedMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikSetLedMsg>)))
  "Returns md5sum for a message object of type '<minikSetLedMsg>"
  "416c0731914825378ec0a0ce9d25cbb7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikSetLedMsg)))
  "Returns md5sum for a message object of type 'minikSetLedMsg"
  "416c0731914825378ec0a0ce9d25cbb7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikSetLedMsg>)))
  "Returns full string definition for message of type '<minikSetLedMsg>"
  (cl:format cl:nil "# Minik Set Led Command~%~%bool isLed1ON~%bool isLed2ON~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikSetLedMsg)))
  "Returns full string definition for message of type 'minikSetLedMsg"
  (cl:format cl:nil "# Minik Set Led Command~%~%bool isLed1ON~%bool isLed2ON~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikSetLedMsg>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikSetLedMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikSetLedMsg
    (cl:cons ':isLed1ON (isLed1ON msg))
    (cl:cons ':isLed2ON (isLed2ON msg))
))
