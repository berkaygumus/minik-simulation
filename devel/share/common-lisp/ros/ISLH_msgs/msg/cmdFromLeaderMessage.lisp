; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude cmdFromLeaderMessage.msg.html

(cl:defclass <cmdFromLeaderMessage> (roslisp-msg-protocol:ros-message)
  ((sendingTime
    :reader sendingTime
    :initarg :sendingTime
    :type cl:integer
    :initform 0)
   (cmdTypeID
    :reader cmdTypeID
    :initarg :cmdTypeID
    :type cl:fixnum
    :initform 0)
   (cmdMessage
    :reader cmdMessage
    :initarg :cmdMessage
    :type cl:string
    :initform ""))
)

(cl:defclass cmdFromLeaderMessage (<cmdFromLeaderMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmdFromLeaderMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmdFromLeaderMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<cmdFromLeaderMessage> is deprecated: use ISLH_msgs-msg:cmdFromLeaderMessage instead.")))

(cl:ensure-generic-function 'sendingTime-val :lambda-list '(m))
(cl:defmethod sendingTime-val ((m <cmdFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:sendingTime-val is deprecated.  Use ISLH_msgs-msg:sendingTime instead.")
  (sendingTime m))

(cl:ensure-generic-function 'cmdTypeID-val :lambda-list '(m))
(cl:defmethod cmdTypeID-val ((m <cmdFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:cmdTypeID-val is deprecated.  Use ISLH_msgs-msg:cmdTypeID instead.")
  (cmdTypeID m))

(cl:ensure-generic-function 'cmdMessage-val :lambda-list '(m))
(cl:defmethod cmdMessage-val ((m <cmdFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:cmdMessage-val is deprecated.  Use ISLH_msgs-msg:cmdMessage instead.")
  (cmdMessage m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmdFromLeaderMessage>) ostream)
  "Serializes a message object of type '<cmdFromLeaderMessage>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cmdTypeID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'cmdTypeID)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'cmdMessage))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'cmdMessage))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmdFromLeaderMessage>) istream)
  "Deserializes a message object of type '<cmdFromLeaderMessage>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cmdTypeID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'cmdTypeID)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cmdMessage) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'cmdMessage) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmdFromLeaderMessage>)))
  "Returns string type for a message object of type '<cmdFromLeaderMessage>"
  "ISLH_msgs/cmdFromLeaderMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmdFromLeaderMessage)))
  "Returns string type for a message object of type 'cmdFromLeaderMessage"
  "ISLH_msgs/cmdFromLeaderMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmdFromLeaderMessage>)))
  "Returns md5sum for a message object of type '<cmdFromLeaderMessage>"
  "49939506eb789fd4a67d4e6e601d80df")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmdFromLeaderMessage)))
  "Returns md5sum for a message object of type 'cmdFromLeaderMessage"
  "49939506eb789fd4a67d4e6e601d80df")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmdFromLeaderMessage>)))
  "Returns full string definition for message of type '<cmdFromLeaderMessage>"
  (cl:format cl:nil "# The incoming command message from coalition leader~%~%uint64 sendingTime #The sending time~%~%uint16 cmdTypeID~%~%string cmdMessage~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmdFromLeaderMessage)))
  "Returns full string definition for message of type 'cmdFromLeaderMessage"
  (cl:format cl:nil "# The incoming command message from coalition leader~%~%uint64 sendingTime #The sending time~%~%uint16 cmdTypeID~%~%string cmdMessage~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmdFromLeaderMessage>))
  (cl:+ 0
     8
     2
     4 (cl:length (cl:slot-value msg 'cmdMessage))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmdFromLeaderMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'cmdFromLeaderMessage
    (cl:cons ':sendingTime (sendingTime msg))
    (cl:cons ':cmdTypeID (cmdTypeID msg))
    (cl:cons ':cmdMessage (cmdMessage msg))
))
