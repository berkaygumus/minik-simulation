; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikGetPIDVelocityMsg.msg.html

(cl:defclass <minikGetPIDVelocityMsg> (roslisp-msg-protocol:ros-message)
  ((motorID
    :reader motorID
    :initarg :motorID
    :type cl:integer
    :initform 0)
   (P
    :reader P
    :initarg :P
    :type cl:integer
    :initform 0)
   (I
    :reader I
    :initarg :I
    :type cl:integer
    :initform 0)
   (D
    :reader D
    :initarg :D
    :type cl:integer
    :initform 0))
)

(cl:defclass minikGetPIDVelocityMsg (<minikGetPIDVelocityMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikGetPIDVelocityMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikGetPIDVelocityMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikGetPIDVelocityMsg> is deprecated: use minik_ros_wrapper-msg:minikGetPIDVelocityMsg instead.")))

(cl:ensure-generic-function 'motorID-val :lambda-list '(m))
(cl:defmethod motorID-val ((m <minikGetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:motorID-val is deprecated.  Use minik_ros_wrapper-msg:motorID instead.")
  (motorID m))

(cl:ensure-generic-function 'P-val :lambda-list '(m))
(cl:defmethod P-val ((m <minikGetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:P-val is deprecated.  Use minik_ros_wrapper-msg:P instead.")
  (P m))

(cl:ensure-generic-function 'I-val :lambda-list '(m))
(cl:defmethod I-val ((m <minikGetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:I-val is deprecated.  Use minik_ros_wrapper-msg:I instead.")
  (I m))

(cl:ensure-generic-function 'D-val :lambda-list '(m))
(cl:defmethod D-val ((m <minikGetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:D-val is deprecated.  Use minik_ros_wrapper-msg:D instead.")
  (D m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikGetPIDVelocityMsg>) ostream)
  "Serializes a message object of type '<minikGetPIDVelocityMsg>"
  (cl:let* ((signed (cl:slot-value msg 'motorID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'P)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'I)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'D)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikGetPIDVelocityMsg>) istream)
  "Deserializes a message object of type '<minikGetPIDVelocityMsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motorID) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'P)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'I)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'D)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikGetPIDVelocityMsg>)))
  "Returns string type for a message object of type '<minikGetPIDVelocityMsg>"
  "minik_ros_wrapper/minikGetPIDVelocityMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikGetPIDVelocityMsg)))
  "Returns string type for a message object of type 'minikGetPIDVelocityMsg"
  "minik_ros_wrapper/minikGetPIDVelocityMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikGetPIDVelocityMsg>)))
  "Returns md5sum for a message object of type '<minikGetPIDVelocityMsg>"
  "e7ffde16b01cf7c9fd96dfa04f0bfdc6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikGetPIDVelocityMsg)))
  "Returns md5sum for a message object of type 'minikGetPIDVelocityMsg"
  "e7ffde16b01cf7c9fd96dfa04f0bfdc6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikGetPIDVelocityMsg>)))
  "Returns full string definition for message of type '<minikGetPIDVelocityMsg>"
  (cl:format cl:nil "# Minik Get Velocity PID Message~%~%int32 motorID~%char P~%char I~%char D~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikGetPIDVelocityMsg)))
  "Returns full string definition for message of type 'minikGetPIDVelocityMsg"
  (cl:format cl:nil "# Minik Get Velocity PID Message~%~%int32 motorID~%char P~%char I~%char D~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikGetPIDVelocityMsg>))
  (cl:+ 0
     4
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikGetPIDVelocityMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikGetPIDVelocityMsg
    (cl:cons ':motorID (motorID msg))
    (cl:cons ':P (P msg))
    (cl:cons ':I (I msg))
    (cl:cons ':D (D msg))
))
