; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude cmd2LeadersMessage.msg.html

(cl:defclass <cmd2LeadersMessage> (roslisp-msg-protocol:ros-message)
  ((leaderRobotID
    :reader leaderRobotID
    :initarg :leaderRobotID
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (sendingTime
    :reader sendingTime
    :initarg :sendingTime
    :type cl:integer
    :initform 0)
   (messageTypeID
    :reader messageTypeID
    :initarg :messageTypeID
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (message
    :reader message
    :initarg :message
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass cmd2LeadersMessage (<cmd2LeadersMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd2LeadersMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd2LeadersMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<cmd2LeadersMessage> is deprecated: use ISLH_msgs-msg:cmd2LeadersMessage instead.")))

(cl:ensure-generic-function 'leaderRobotID-val :lambda-list '(m))
(cl:defmethod leaderRobotID-val ((m <cmd2LeadersMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:leaderRobotID-val is deprecated.  Use ISLH_msgs-msg:leaderRobotID instead.")
  (leaderRobotID m))

(cl:ensure-generic-function 'sendingTime-val :lambda-list '(m))
(cl:defmethod sendingTime-val ((m <cmd2LeadersMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:sendingTime-val is deprecated.  Use ISLH_msgs-msg:sendingTime instead.")
  (sendingTime m))

(cl:ensure-generic-function 'messageTypeID-val :lambda-list '(m))
(cl:defmethod messageTypeID-val ((m <cmd2LeadersMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:messageTypeID-val is deprecated.  Use ISLH_msgs-msg:messageTypeID instead.")
  (messageTypeID m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <cmd2LeadersMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:message-val is deprecated.  Use ISLH_msgs-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd2LeadersMessage>) ostream)
  "Serializes a message object of type '<cmd2LeadersMessage>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'leaderRobotID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'leaderRobotID))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'sendingTime)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'messageTypeID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'messageTypeID))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd2LeadersMessage>) istream)
  "Deserializes a message object of type '<cmd2LeadersMessage>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'leaderRobotID) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'leaderRobotID)))
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
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'messageTypeID) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'messageTypeID)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'message) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'message)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd2LeadersMessage>)))
  "Returns string type for a message object of type '<cmd2LeadersMessage>"
  "ISLH_msgs/cmd2LeadersMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd2LeadersMessage)))
  "Returns string type for a message object of type 'cmd2LeadersMessage"
  "ISLH_msgs/cmd2LeadersMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd2LeadersMessage>)))
  "Returns md5sum for a message object of type '<cmd2LeadersMessage>"
  "dea84c50c103ccf3d723b1874cc1b015")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd2LeadersMessage)))
  "Returns md5sum for a message object of type 'cmd2LeadersMessage"
  "dea84c50c103ccf3d723b1874cc1b015")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd2LeadersMessage>)))
  "Returns full string definition for message of type '<cmd2LeadersMessage>"
  (cl:format cl:nil "# The task's information from coalition leader~%~%uint16[] leaderRobotID #robot id to which the message will be sent ~%~%uint64 sendingTime #The sending time~%~%uint16[] messageTypeID~%~%string[] message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd2LeadersMessage)))
  "Returns full string definition for message of type 'cmd2LeadersMessage"
  (cl:format cl:nil "# The task's information from coalition leader~%~%uint16[] leaderRobotID #robot id to which the message will be sent ~%~%uint64 sendingTime #The sending time~%~%uint16[] messageTypeID~%~%string[] message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd2LeadersMessage>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'leaderRobotID) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     8
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'messageTypeID) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'message) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd2LeadersMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd2LeadersMessage
    (cl:cons ':leaderRobotID (leaderRobotID msg))
    (cl:cons ':sendingTime (sendingTime msg))
    (cl:cons ':messageTypeID (messageTypeID msg))
    (cl:cons ':message (message msg))
))
