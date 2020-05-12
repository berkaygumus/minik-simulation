; Auto-generated. Do not edit!


(cl:in-package minik_ros_wrapper-msg)


;//! \htmlinclude minikSetPIDVelocityMsg.msg.html

(cl:defclass <minikSetPIDVelocityMsg> (roslisp-msg-protocol:ros-message)
  ((motorID
    :reader motorID
    :initarg :motorID
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (P
    :reader P
    :initarg :P
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (I
    :reader I
    :initarg :I
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (D
    :reader D
    :initarg :D
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass minikSetPIDVelocityMsg (<minikSetPIDVelocityMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <minikSetPIDVelocityMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'minikSetPIDVelocityMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name minik_ros_wrapper-msg:<minikSetPIDVelocityMsg> is deprecated: use minik_ros_wrapper-msg:minikSetPIDVelocityMsg instead.")))

(cl:ensure-generic-function 'motorID-val :lambda-list '(m))
(cl:defmethod motorID-val ((m <minikSetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:motorID-val is deprecated.  Use minik_ros_wrapper-msg:motorID instead.")
  (motorID m))

(cl:ensure-generic-function 'P-val :lambda-list '(m))
(cl:defmethod P-val ((m <minikSetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:P-val is deprecated.  Use minik_ros_wrapper-msg:P instead.")
  (P m))

(cl:ensure-generic-function 'I-val :lambda-list '(m))
(cl:defmethod I-val ((m <minikSetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:I-val is deprecated.  Use minik_ros_wrapper-msg:I instead.")
  (I m))

(cl:ensure-generic-function 'D-val :lambda-list '(m))
(cl:defmethod D-val ((m <minikSetPIDVelocityMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader minik_ros_wrapper-msg:D-val is deprecated.  Use minik_ros_wrapper-msg:D instead.")
  (D m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <minikSetPIDVelocityMsg>) ostream)
  "Serializes a message object of type '<minikSetPIDVelocityMsg>"
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
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'P))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'P))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'I))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'I))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'D))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'D))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <minikSetPIDVelocityMsg>) istream)
  "Deserializes a message object of type '<minikSetPIDVelocityMsg>"
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
  (cl:setf (cl:slot-value msg 'P) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'P)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'I) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'I)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'D) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'D)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<minikSetPIDVelocityMsg>)))
  "Returns string type for a message object of type '<minikSetPIDVelocityMsg>"
  "minik_ros_wrapper/minikSetPIDVelocityMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'minikSetPIDVelocityMsg)))
  "Returns string type for a message object of type 'minikSetPIDVelocityMsg"
  "minik_ros_wrapper/minikSetPIDVelocityMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<minikSetPIDVelocityMsg>)))
  "Returns md5sum for a message object of type '<minikSetPIDVelocityMsg>"
  "d3c57d08264ba7635ea33c90d92b0139")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'minikSetPIDVelocityMsg)))
  "Returns md5sum for a message object of type 'minikSetPIDVelocityMsg"
  "d3c57d08264ba7635ea33c90d92b0139")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<minikSetPIDVelocityMsg>)))
  "Returns full string definition for message of type '<minikSetPIDVelocityMsg>"
  (cl:format cl:nil "# Minik Set Velocity PID Message~%~%int32[] motorID~%char[] P~%char[] I~%char[] D~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'minikSetPIDVelocityMsg)))
  "Returns full string definition for message of type 'minikSetPIDVelocityMsg"
  (cl:format cl:nil "# Minik Set Velocity PID Message~%~%int32[] motorID~%char[] P~%char[] I~%char[] D~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <minikSetPIDVelocityMsg>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'motorID) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'P) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'I) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'D) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <minikSetPIDVelocityMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'minikSetPIDVelocityMsg
    (cl:cons ':motorID (motorID msg))
    (cl:cons ':P (P msg))
    (cl:cons ':I (I msg))
    (cl:cons ':D (D msg))
))
