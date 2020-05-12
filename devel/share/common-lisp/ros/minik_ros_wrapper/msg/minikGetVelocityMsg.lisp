; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikGetVelocityMsg.msg.html

(cl:defclass <minikGetVelocityMsg> (roslisp-msg-protocol:ros-message)
  ((motorID
    :reader motorID
    :initarg :motorID
    :type cl:integer
    :initform 0)
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:fixnum
    :initform 0))
)

(cl:defclass minikGetVelocityMsg (<minikGetVelocityMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikGetVelocityMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikGetVelocityMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikGetVelocityMsg> is deprecated: use minik_ros_wrapper-msg:minikGetVelocityMsg instead.")))

(cl:ensure-generic-function 'motorID-val :lambda-list '(m))
(cl:defmethod motorID-val ((m <minikGetVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:motorID-val is deprecated.  Use minik_ros_wrapper-msg:motorID instead.")
  (motorID m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <minikGetVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:velocity-val is deprecated.  Use minik_ros_wrapper-msg:velocity instead.")
  (velocity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikGetVelocityMsg>) ostream)
  "Serializes a message object of type '<minikGetVelocityMsg>"
  (cl:let* ((signed (cl:slot-value msg 'motorID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'velocity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikGetVelocityMsg>) istream)
  "Deserializes a message object of type '<minikGetVelocityMsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motorID) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'velocity) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikGetVelocityMsg>)))
  "Returns string type for a message object of type '<minikGetVelocityMsg>"
  "minik_ros_wrapper/minikGetVelocityMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikGetVelocityMsg)))
  "Returns string type for a message object of type 'minikGetVelocityMsg"
  "minik_ros_wrapper/minikGetVelocityMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikGetVelocityMsg>)))
  "Returns md5sum for a message object of type '<minikGetVelocityMsg>"
  "a94dbef25ebdc880900454ec307048c1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikGetVelocityMsg)))
  "Returns md5sum for a message object of type 'minikGetVelocityMsg"
  "a94dbef25ebdc880900454ec307048c1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikGetVelocityMsg>)))
  "Returns full string definition for message of type '<minikGetVelocityMsg>"
  (cl:format cl:nil "# Minik Get Velocity Message~%~%int32 motorID~%int16 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikGetVelocityMsg)))
  "Returns full string definition for message of type 'minikGetVelocityMsg"
  (cl:format cl:nil "# Minik Get Velocity Message~%~%int32 motorID~%int16 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikGetVelocityMsg>))
  (cl:+ 0
     4
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikGetVelocityMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikGetVelocityMsg
    (cl:cons ':motorID (motorID msg))
    (cl:cons ':velocity (velocity msg))
))
