; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude newLeaderMessage.msg.html

(cl:defclass <newLeaderMessage> (roslisp-msg-protocol:ros-message)
  ((sendingTime
    :reader sendingTime
    :initarg :sendingTime
    :type cl:integer
    :initform 0)
   (infoTypeID
    :reader infoTypeID
    :initarg :infoTypeID
    :type cl:fixnum
    :initform 0)
   (infoMessage
    :reader infoMessage
    :initarg :infoMessage
    :type cl:string
    :initform ""))
)

(cl:defclass newLeaderMessage (<newLeaderMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <newLeaderMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'newLeaderMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<newLeaderMessage> is deprecated: use ISLH_msgs-msg:newLeaderMessage instead.")))

(cl:ensure-generic-function 'sendingTime-val :lambda-list '(m))
(cl:defmethod sendingTime-val ((m <newLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:sendingTime-val is deprecated.  Use ISLH_msgs-msg:sendingTime instead.")
  (sendingTime m))

(cl:ensure-generic-function 'infoTypeID-val :lambda-list '(m))
(cl:defmethod infoTypeID-val ((m <newLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:infoTypeID-val is deprecated.  Use ISLH_msgs-msg:infoTypeID instead.")
  (infoTypeID m))

(cl:ensure-generic-function 'infoMessage-val :lambda-list '(m))
(cl:defmethod infoMessage-val ((m <newLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:infoMessage-val is deprecated.  Use ISLH_msgs-msg:infoMessage instead.")
  (infoMessage m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <newLeaderMessage>) ostream)
  "Serializes a message object of type '<newLeaderMessage>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'infoTypeID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'infoTypeID)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'infoMessage))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'infoMessage))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <newLeaderMessage>) istream)
  "Deserializes a message object of type '<newLeaderMessage>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'infoTypeID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'infoTypeID)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'infoMessage) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'infoMessage) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<newLeaderMessage>)))
  "Returns string type for a message object of type '<newLeaderMessage>"
  "ISLH_msgs/newLeaderMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'newLeaderMessage)))
  "Returns string type for a message object of type 'newLeaderMessage"
  "ISLH_msgs/newLeaderMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<newLeaderMessage>)))
  "Returns md5sum for a message object of type '<newLeaderMessage>"
  "e3baee834452566b366f59c79fcdfa75")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'newLeaderMessage)))
  "Returns md5sum for a message object of type 'newLeaderMessage"
  "e3baee834452566b366f59c79fcdfa75")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<newLeaderMessage>)))
  "Returns full string definition for message of type '<newLeaderMessage>"
  (cl:format cl:nil "# The incoming info message from old coalition leader to new coalition leader~%~%uint64 sendingTime #The sending time~%~%uint16 infoTypeID~%~%string infoMessage~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'newLeaderMessage)))
  "Returns full string definition for message of type 'newLeaderMessage"
  (cl:format cl:nil "# The incoming info message from old coalition leader to new coalition leader~%~%uint64 sendingTime #The sending time~%~%uint16 infoTypeID~%~%string infoMessage~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <newLeaderMessage>))
  (cl:+ 0
     8
     2
     4 (cl:length (cl:slot-value msg 'infoMessage))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <newLeaderMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'newLeaderMessage
    (cl:cons ':sendingTime (sendingTime msg))
    (cl:cons ':infoTypeID (infoTypeID msg))
    (cl:cons ':infoMessage (infoMessage msg))
))
