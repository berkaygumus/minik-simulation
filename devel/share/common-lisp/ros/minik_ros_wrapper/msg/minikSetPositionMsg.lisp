; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikSetPositionMsg.msg.html

(cl:defclass <minikSetPositionMsg> (roslisp-msg-protocol:ros-message)
  ((motorID
    :reader motorID
    :initarg :motorID
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (position
    :reader position
    :initarg :position
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass minikSetPositionMsg (<minikSetPositionMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikSetPositionMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikSetPositionMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikSetPositionMsg> is deprecated: use minik_ros_wrapper-msg:minikSetPositionMsg instead.")))

(cl:ensure-generic-function 'motorID-val :lambda-list '(m))
(cl:defmethod motorID-val ((m <minikSetPositionMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:motorID-val is deprecated.  Use minik_ros_wrapper-msg:motorID instead.")
  (motorID m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <minikSetPositionMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:position-val is deprecated.  Use minik_ros_wrapper-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikSetPositionMsg>) ostream)
  "Serializes a message object of type '<minikSetPositionMsg>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'motorID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'motorID))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'position))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'position))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikSetPositionMsg>) istream)
  "Deserializes a message object of type '<minikSetPositionMsg>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'motorID) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'motorID)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'position) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'position)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikSetPositionMsg>)))
  "Returns string type for a message object of type '<minikSetPositionMsg>"
  "minik_ros_wrapper/minikSetPositionMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikSetPositionMsg)))
  "Returns string type for a message object of type 'minikSetPositionMsg"
  "minik_ros_wrapper/minikSetPositionMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikSetPositionMsg>)))
  "Returns md5sum for a message object of type '<minikSetPositionMsg>"
  "121261aaf42c6b46f74e88a84eea6cde")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikSetPositionMsg)))
  "Returns md5sum for a message object of type 'minikSetPositionMsg"
  "121261aaf42c6b46f74e88a84eea6cde")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikSetPositionMsg>)))
  "Returns full string definition for message of type '<minikSetPositionMsg>"
  (cl:format cl:nil "# Minik Set Position Command~%~%int32[] motorID~%int32[] position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikSetPositionMsg)))
  "Returns full string definition for message of type 'minikSetPositionMsg"
  (cl:format cl:nil "# Minik Set Position Command~%~%int32[] motorID~%int32[] position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikSetPositionMsg>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'motorID) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikSetPositionMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikSetPositionMsg
    (cl:cons ':motorID (motorID msg))
    (cl:cons ':position (position msg))
))
