; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikGetButtonMsg.msg.html

(cl:defclass <minikGetButtonMsg> (roslisp-msg-protocol:ros-message)
  ((isButton1Pressed
    :reader isButton1Pressed
    :initarg :isButton1Pressed
    :type cl:boolean
    :initform cl:nil)
   (isButton2Pressed
    :reader isButton2Pressed
    :initarg :isButton2Pressed
    :type cl:boolean
    :initform cl:nil)
   (isButton3Pressed
    :reader isButton3Pressed
    :initarg :isButton3Pressed
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass minikGetButtonMsg (<minikGetButtonMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikGetButtonMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikGetButtonMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikGetButtonMsg> is deprecated: use minik_ros_wrapper-msg:minikGetButtonMsg instead.")))

(cl:ensure-generic-function 'isButton1Pressed-val :lambda-list '(m))
(cl:defmethod isButton1Pressed-val ((m <minikGetButtonMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isButton1Pressed-val is deprecated.  Use minik_ros_wrapper-msg:isButton1Pressed instead.")
  (isButton1Pressed m))

(cl:ensure-generic-function 'isButton2Pressed-val :lambda-list '(m))
(cl:defmethod isButton2Pressed-val ((m <minikGetButtonMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isButton2Pressed-val is deprecated.  Use minik_ros_wrapper-msg:isButton2Pressed instead.")
  (isButton2Pressed m))

(cl:ensure-generic-function 'isButton3Pressed-val :lambda-list '(m))
(cl:defmethod isButton3Pressed-val ((m <minikGetButtonMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:isButton3Pressed-val is deprecated.  Use minik_ros_wrapper-msg:isButton3Pressed instead.")
  (isButton3Pressed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikGetButtonMsg>) ostream)
  "Serializes a message object of type '<minikGetButtonMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isButton1Pressed) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isButton2Pressed) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isButton3Pressed) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikGetButtonMsg>) istream)
  "Deserializes a message object of type '<minikGetButtonMsg>"
    (cl:setf (cl:slot-value msg 'isButton1Pressed) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'isButton2Pressed) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'isButton3Pressed) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikGetButtonMsg>)))
  "Returns string type for a message object of type '<minikGetButtonMsg>"
  "minik_ros_wrapper/minikGetButtonMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikGetButtonMsg)))
  "Returns string type for a message object of type 'minikGetButtonMsg"
  "minik_ros_wrapper/minikGetButtonMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikGetButtonMsg>)))
  "Returns md5sum for a message object of type '<minikGetButtonMsg>"
  "3853358d8e2e329f368156066a21f0b2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikGetButtonMsg)))
  "Returns md5sum for a message object of type 'minikGetButtonMsg"
  "3853358d8e2e329f368156066a21f0b2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikGetButtonMsg>)))
  "Returns full string definition for message of type '<minikGetButtonMsg>"
  (cl:format cl:nil "# Minik Get Button Message~%~%bool isButton1Pressed~%bool isButton2Pressed~%bool isButton3Pressed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikGetButtonMsg)))
  "Returns full string definition for message of type 'minikGetButtonMsg"
  (cl:format cl:nil "# Minik Get Button Message~%~%bool isButton1Pressed~%bool isButton2Pressed~%bool isButton3Pressed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikGetButtonMsg>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikGetButtonMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikGetButtonMsg
    (cl:cons ':isButton1Pressed (isButton1Pressed msg))
    (cl:cons ':isButton2Pressed (isButton2Pressed msg))
    (cl:cons ':isButton3Pressed (isButton3Pressed msg))
))
