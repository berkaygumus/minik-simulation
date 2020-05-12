; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikGetLedMsg.msg.html

(cl:defclass <minikGetLedMsg> (roslisp-msg-protocol:ros-message)
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

(cl:defclass minikGetLedMsg (<minikGetLedMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikGetLedMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikGetLedMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikGetLedMsg> is deprecated: use minik_ros_wrapper-msg:minikGetLedMsg instead.")))

(cl:ensure-generic-function 'isLed1ON-val :lambda-list '(m))
(cl:defmethod isLed1ON-val ((m <minikGetLedMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isLed1ON-val is deprecated.  Use minik_ros_wrapper-msg:isLed1ON instead.")
  (isLed1ON m))

(cl:ensure-generic-function 'isLed2ON-val :lambda-list '(m))
(cl:defmethod isLed2ON-val ((m <minikGetLedMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isLed2ON-val is deprecated.  Use minik_ros_wrapper-msg:isLed2ON instead.")
  (isLed2ON m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikGetLedMsg>) ostream)
  "Serializes a message object of type '<minikGetLedMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isLed1ON) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isLed2ON) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikGetLedMsg>) istream)
  "Deserializes a message object of type '<minikGetLedMsg>"
    (cl:setf (cl:slot-value msg 'isLed1ON) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'isLed2ON) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikGetLedMsg>)))
  "Returns string type for a message object of type '<minikGetLedMsg>"
  "minik_ros_wrapper/minikGetLedMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikGetLedMsg)))
  "Returns string type for a message object of type 'minikGetLedMsg"
  "minik_ros_wrapper/minikGetLedMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikGetLedMsg>)))
  "Returns md5sum for a message object of type '<minikGetLedMsg>"
  "416c0731914825378ec0a0ce9d25cbb7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikGetLedMsg)))
  "Returns md5sum for a message object of type 'minikGetLedMsg"
  "416c0731914825378ec0a0ce9d25cbb7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikGetLedMsg>)))
  "Returns full string definition for message of type '<minikGetLedMsg>"
  (cl:format cl:nil "# Minik Get Led Message~%~%bool isLed1ON~%bool isLed2ON~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikGetLedMsg)))
  "Returns full string definition for message of type 'minikGetLedMsg"
  (cl:format cl:nil "# Minik Get Led Message~%~%bool isLed1ON~%bool isLed2ON~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikGetLedMsg>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikGetLedMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikGetLedMsg
    (cl:cons ':isLed1ON (isLed1ON msg))
    (cl:cons ':isLed2ON (isLed2ON msg))
))
