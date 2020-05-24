; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude cmd2RobotsFromLeaderMessage.msg.html

(cl:defclass <cmd2RobotsFromLeaderMessage> (roslisp-msg-protocol:ros-message)
  ((receiverRobotID
    :reader receiverRobotID
    :initarg :receiverRobotID
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (sendingTime
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

(cl:defclass cmd2RobotsFromLeaderMessage (<cmd2RobotsFromLeaderMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd2RobotsFromLeaderMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd2RobotsFromLeaderMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<cmd2RobotsFromLeaderMessage> is deprecated: use ISLH_msgs-msg:cmd2RobotsFromLeaderMessage instead.")))

(cl:ensure-generic-function 'receiverRobotID-val :lambda-list '(m))
(cl:defmethod receiverRobotID-val ((m <cmd2RobotsFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:receiverRobotID-val is deprecated.  Use ISLH_msgs-msg:receiverRobotID instead.")
  (receiverRobotID m))

(cl:ensure-generic-function 'sendingTime-val :lambda-list '(m))
(cl:defmethod sendingTime-val ((m <cmd2RobotsFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:sendingTime-val is deprecated.  Use ISLH_msgs-msg:sendingTime instead.")
  (sendingTime m))

(cl:ensure-generic-function 'cmdTypeID-val :lambda-list '(m))
(cl:defmethod cmdTypeID-val ((m <cmd2RobotsFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:cmdTypeID-val is deprecated.  Use ISLH_msgs-msg:cmdTypeID instead.")
  (cmdTypeID m))

(cl:ensure-generic-function 'cmdMessage-val :lambda-list '(m))
(cl:defmethod cmdMessage-val ((m <cmd2RobotsFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:cmdMessage-val is deprecated.  Use ISLH_msgs-msg:cmdMessage instead.")
  (cmdMessage m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd2RobotsFromLeaderMessage>) ostream)
  "Serializes a message object of type '<cmd2RobotsFromLeaderMessage>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'receiverRobotID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'receiverRobotID))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd2RobotsFromLeaderMessage>) istream)
  "Deserializes a message object of type '<cmd2RobotsFromLeaderMessage>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'receiverRobotID) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'receiverRobotID)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream)))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd2RobotsFromLeaderMessage>)))
  "Returns string type for a message object of type '<cmd2RobotsFromLeaderMessage>"
  "ISLH_msgs/cmd2RobotsFromLeaderMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd2RobotsFromLeaderMessage)))
  "Returns string type for a message object of type 'cmd2RobotsFromLeaderMessage"
  "ISLH_msgs/cmd2RobotsFromLeaderMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd2RobotsFromLeaderMessage>)))
  "Returns md5sum for a message object of type '<cmd2RobotsFromLeaderMessage>"
  "56a7753bb3b7a241e2936846abb3f9d4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd2RobotsFromLeaderMessage)))
  "Returns md5sum for a message object of type 'cmd2RobotsFromLeaderMessage"
  "56a7753bb3b7a241e2936846abb3f9d4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd2RobotsFromLeaderMessage>)))
  "Returns full string definition for message of type '<cmd2RobotsFromLeaderMessage>"
  (cl:format cl:nil "# The outgoing command message from coalition leader~%~%uint16[] receiverRobotID~%~%uint64 sendingTime #The sending time~%~%uint16 cmdTypeID~%~%string cmdMessage~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd2RobotsFromLeaderMessage)))
  "Returns full string definition for message of type 'cmd2RobotsFromLeaderMessage"
  (cl:format cl:nil "# The outgoing command message from coalition leader~%~%uint16[] receiverRobotID~%~%uint64 sendingTime #The sending time~%~%uint16 cmdTypeID~%~%string cmdMessage~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd2RobotsFromLeaderMessage>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'receiverRobotID) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     8
     2
     4 (cl:length (cl:slot-value msg 'cmdMessage))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd2RobotsFromLeaderMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd2RobotsFromLeaderMessage
    (cl:cons ':receiverRobotID (receiverRobotID msg))
    (cl:cons ':sendingTime (sendingTime msg))
    (cl:cons ':cmdTypeID (cmdTypeID msg))
    (cl:cons ':cmdMessage (cmdMessage msg))
))
