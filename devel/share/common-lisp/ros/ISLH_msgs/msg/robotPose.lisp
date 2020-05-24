; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude robotPose.msg.html

(cl:defclass <robotPose> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (target
    :reader target
    :initarg :target
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (calYaw
    :reader calYaw
    :initarg :calYaw
    :type cl:float
    :initform 0.0)
   (radYaw
    :reader radYaw
    :initarg :radYaw
    :type cl:float
    :initform 0.0))
)

(cl:defclass robotPose (<robotPose>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <robotPose>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'robotPose)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<robotPose> is deprecated: use ISLH_msgs-msg:robotPose instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <robotPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:id-val is deprecated.  Use ISLH_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <robotPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:position-val is deprecated.  Use ISLH_msgs-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'target-val :lambda-list '(m))
(cl:defmethod target-val ((m <robotPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:target-val is deprecated.  Use ISLH_msgs-msg:target instead.")
  (target m))

(cl:ensure-generic-function 'calYaw-val :lambda-list '(m))
(cl:defmethod calYaw-val ((m <robotPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:calYaw-val is deprecated.  Use ISLH_msgs-msg:calYaw instead.")
  (calYaw m))

(cl:ensure-generic-function 'radYaw-val :lambda-list '(m))
(cl:defmethod radYaw-val ((m <robotPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:radYaw-val is deprecated.  Use ISLH_msgs-msg:radYaw instead.")
  (radYaw m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <robotPose>) ostream)
  "Serializes a message object of type '<robotPose>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'target) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'calYaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'radYaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <robotPose>) istream)
  "Deserializes a message object of type '<robotPose>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'target) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'calYaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radYaw) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<robotPose>)))
  "Returns string type for a message object of type '<robotPose>"
  "ISLH_msgs/robotPose")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'robotPose)))
  "Returns string type for a message object of type 'robotPose"
  "ISLH_msgs/robotPose")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<robotPose>)))
  "Returns md5sum for a message object of type '<robotPose>"
  "0eef6d6e44271c92907c87eea9d5073a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'robotPose)))
  "Returns md5sum for a message object of type 'robotPose"
  "0eef6d6e44271c92907c87eea9d5073a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<robotPose>)))
  "Returns full string definition for message of type '<robotPose>"
  (cl:format cl:nil "#The robot's position information and target information~%~%int32 id~%~%geometry_msgs/Point position~%~%geometry_msgs/Point target~%~%float32 calYaw~%float32 radYaw~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'robotPose)))
  "Returns full string definition for message of type 'robotPose"
  (cl:format cl:nil "#The robot's position information and target information~%~%int32 id~%~%geometry_msgs/Point position~%~%geometry_msgs/Point target~%~%float32 calYaw~%float32 radYaw~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <robotPose>))
  (cl:+ 0
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'target))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <robotPose>))
  "Converts a ROS message object to a list"
  (cl:list 'robotPose
    (cl:cons ':id (id msg))
    (cl:cons ':position (position msg))
    (cl:cons ':target (target msg))
    (cl:cons ':calYaw (calYaw msg))
    (cl:cons ':radYaw (radYaw msg))
))
