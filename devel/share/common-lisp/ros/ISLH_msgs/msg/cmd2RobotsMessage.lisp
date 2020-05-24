; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude cmd2RobotsMessage.msg.html

(cl:defclass <cmd2RobotsMessage> (roslisp-msg-protocol:ros-message)
  ((sendingTime
    :reader sendingTime
    :initarg :sendingTime
    :type cl:integer
    :initform 0)
   (cmdType
    :reader cmdType
    :initarg :cmdType
    :type cl:fixnum
    :initform 0)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass cmd2RobotsMessage (<cmd2RobotsMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd2RobotsMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd2RobotsMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<cmd2RobotsMessage> is deprecated: use ISLH_msgs-msg:cmd2RobotsMessage instead.")))

(cl:ensure-generic-function 'sendingTime-val :lambda-list '(m))
(cl:defmethod sendingTime-val ((m <cmd2RobotsMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:sendingTime-val is deprecated.  Use ISLH_msgs-msg:sendingTime instead.")
  (sendingTime m))

(cl:ensure-generic-function 'cmdType-val :lambda-list '(m))
(cl:defmethod cmdType-val ((m <cmd2RobotsMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:cmdType-val is deprecated.  Use ISLH_msgs-msg:cmdType instead.")
  (cmdType m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <cmd2RobotsMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:message-val is deprecated.  Use ISLH_msgs-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd2RobotsMessage>) ostream)
  "Serializes a message object of type '<cmd2RobotsMessage>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cmdType)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'cmdType)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd2RobotsMessage>) istream)
  "Deserializes a message object of type '<cmd2RobotsMessage>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cmdType)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'cmdType)) (cl:read-byte istream))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd2RobotsMessage>)))
  "Returns string type for a message object of type '<cmd2RobotsMessage>"
  "ISLH_msgs/cmd2RobotsMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd2RobotsMessage)))
  "Returns string type for a message object of type 'cmd2RobotsMessage"
  "ISLH_msgs/cmd2RobotsMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd2RobotsMessage>)))
  "Returns md5sum for a message object of type '<cmd2RobotsMessage>"
  "651ffc22f68ec2e97e413b004cae948b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd2RobotsMessage)))
  "Returns md5sum for a message object of type 'cmd2RobotsMessage"
  "651ffc22f68ec2e97e413b004cae948b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd2RobotsMessage>)))
  "Returns full string definition for message of type '<cmd2RobotsMessage>"
  (cl:format cl:nil "# The incoming command message from coalition leader~%~%uint64 sendingTime #The sending time~%~%uint16 cmdType~%~%string message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd2RobotsMessage)))
  "Returns full string definition for message of type 'cmd2RobotsMessage"
  (cl:format cl:nil "# The incoming command message from coalition leader~%~%uint64 sendingTime #The sending time~%~%uint16 cmdType~%~%string message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd2RobotsMessage>))
  (cl:+ 0
     8
     2
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd2RobotsMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd2RobotsMessage
    (cl:cons ':sendingTime (sendingTime msg))
    (cl:cons ':cmdType (cmdType msg))
    (cl:cons ':message (message msg))
))
