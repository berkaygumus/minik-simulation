; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude cmdFromCoordinatorMessage.msg.html

(cl:defclass <cmdFromCoordinatorMessage> (roslisp-msg-protocol:ros-message)
  ((sendingTime
    :reader sendingTime
    :initarg :sendingTime
    :type cl:integer
    :initform 0)
   (messageTypeID
    :reader messageTypeID
    :initarg :messageTypeID
    :type cl:fixnum
    :initform 0)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass cmdFromCoordinatorMessage (<cmdFromCoordinatorMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmdFromCoordinatorMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmdFromCoordinatorMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<cmdFromCoordinatorMessage> is deprecated: use ISLH_msgs-msg:cmdFromCoordinatorMessage instead.")))

(cl:ensure-generic-function 'sendingTime-val :lambda-list '(m))
(cl:defmethod sendingTime-val ((m <cmdFromCoordinatorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:sendingTime-val is deprecated.  Use ISLH_msgs-msg:sendingTime instead.")
  (sendingTime m))

(cl:ensure-generic-function 'messageTypeID-val :lambda-list '(m))
(cl:defmethod messageTypeID-val ((m <cmdFromCoordinatorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:messageTypeID-val is deprecated.  Use ISLH_msgs-msg:messageTypeID instead.")
  (messageTypeID m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <cmdFromCoordinatorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:message-val is deprecated.  Use ISLH_msgs-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmdFromCoordinatorMessage>) ostream)
  "Serializes a message object of type '<cmdFromCoordinatorMessage>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageTypeID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageTypeID)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmdFromCoordinatorMessage>) istream)
  "Deserializes a message object of type '<cmdFromCoordinatorMessage>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageTypeID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageTypeID)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmdFromCoordinatorMessage>)))
  "Returns string type for a message object of type '<cmdFromCoordinatorMessage>"
  "ISLH_msgs/cmdFromCoordinatorMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmdFromCoordinatorMessage)))
  "Returns string type for a message object of type 'cmdFromCoordinatorMessage"
  "ISLH_msgs/cmdFromCoordinatorMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmdFromCoordinatorMessage>)))
  "Returns md5sum for a message object of type '<cmdFromCoordinatorMessage>"
  "6b00d2e721f211550b5ec2a337817798")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmdFromCoordinatorMessage)))
  "Returns md5sum for a message object of type 'cmdFromCoordinatorMessage"
  "6b00d2e721f211550b5ec2a337817798")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmdFromCoordinatorMessage>)))
  "Returns full string definition for message of type '<cmdFromCoordinatorMessage>"
  (cl:format cl:nil "# The incoming command message from the coordinator~%~%uint64 sendingTime #The sending time~%~%uint16 messageTypeID~%~%string message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmdFromCoordinatorMessage)))
  "Returns full string definition for message of type 'cmdFromCoordinatorMessage"
  (cl:format cl:nil "# The incoming command message from the coordinator~%~%uint64 sendingTime #The sending time~%~%uint16 messageTypeID~%~%string message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmdFromCoordinatorMessage>))
  (cl:+ 0
     8
     2
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmdFromCoordinatorMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'cmdFromCoordinatorMessage
    (cl:cons ':sendingTime (sendingTime msg))
    (cl:cons ':messageTypeID (messageTypeID msg))
    (cl:cons ':message (message msg))
))
