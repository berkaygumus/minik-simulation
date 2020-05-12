; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikGetPositionMsg.msg.html

(cl:defclass <minikGetPositionMsg> (roslisp-msg-protocol:ros-message)
  ((motorID
    :reader motorID
    :initarg :motorID
    :type cl:integer
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0))
)

(cl:defclass minikGetPositionMsg (<minikGetPositionMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikGetPositionMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikGetPositionMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikGetPositionMsg> is deprecated: use minik_ros_wrapper-msg:minikGetPositionMsg instead.")))

(cl:ensure-generic-function 'motorID-val :lambda-list '(m))
(cl:defmethod motorID-val ((m <minikGetPositionMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:motorID-val is deprecated.  Use minik_ros_wrapper-msg:motorID instead.")
  (motorID m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <minikGetPositionMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:position-val is deprecated.  Use minik_ros_wrapper-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikGetPositionMsg>) ostream)
  "Serializes a message object of type '<minikGetPositionMsg>"
  (cl:let* ((signed (cl:slot-value msg 'motorID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikGetPositionMsg>) istream)
  "Deserializes a message object of type '<minikGetPositionMsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motorID) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikGetPositionMsg>)))
  "Returns string type for a message object of type '<minikGetPositionMsg>"
  "minik_ros_wrapper/minikGetPositionMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikGetPositionMsg)))
  "Returns string type for a message object of type 'minikGetPositionMsg"
  "minik_ros_wrapper/minikGetPositionMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikGetPositionMsg>)))
  "Returns md5sum for a message object of type '<minikGetPositionMsg>"
  "9484186d0d818e0301bf0d58107b9a65")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikGetPositionMsg)))
  "Returns md5sum for a message object of type 'minikGetPositionMsg"
  "9484186d0d818e0301bf0d58107b9a65")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikGetPositionMsg>)))
  "Returns full string definition for message of type '<minikGetPositionMsg>"
  (cl:format cl:nil "# Minik Get Position Message~%~%int32 motorID~%int32 position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikGetPositionMsg)))
  "Returns full string definition for message of type 'minikGetPositionMsg"
  (cl:format cl:nil "# Minik Get Position Message~%~%int32 motorID~%int32 position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikGetPositionMsg>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikGetPositionMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikGetPositionMsg
    (cl:cons ':motorID (motorID msg))
    (cl:cons ':position (position msg))
))
