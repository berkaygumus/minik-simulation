; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude outMessage.msg.html

(cl:defclass <outMessage> (roslisp-msg-protocol:ros-message)
  ((robotid
    :reader robotid
    :initarg :robotid
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (messageTypeID
    :reader messageTypeID
    :initarg :messageTypeID
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (messageIndx
    :reader messageIndx
    :initarg :messageIndx
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (message
    :reader message
    :initarg :message
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass outMessage (<outMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <outMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'outMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<outMessage> is deprecated: use ISLH_msgs-msg:outMessage instead.")))

(cl:ensure-generic-function 'robotid-val :lambda-list '(m))
(cl:defmethod robotid-val ((m <outMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:robotid-val is deprecated.  Use ISLH_msgs-msg:robotid instead.")
  (robotid m))

(cl:ensure-generic-function 'messageTypeID-val :lambda-list '(m))
(cl:defmethod messageTypeID-val ((m <outMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:messageTypeID-val is deprecated.  Use ISLH_msgs-msg:messageTypeID instead.")
  (messageTypeID m))

(cl:ensure-generic-function 'messageIndx-val :lambda-list '(m))
(cl:defmethod messageIndx-val ((m <outMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:messageIndx-val is deprecated.  Use ISLH_msgs-msg:messageIndx instead.")
  (messageIndx m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <outMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:message-val is deprecated.  Use ISLH_msgs-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <outMessage>) ostream)
  "Serializes a message object of type '<outMessage>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'robotid))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'robotid))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'messageTypeID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'messageTypeID))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'messageIndx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'messageIndx))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <outMessage>) istream)
  "Deserializes a message object of type '<outMessage>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'robotid) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'robotid)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream)))))
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
  (cl:setf (cl:slot-value msg 'messageIndx) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'messageIndx)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<outMessage>)))
  "Returns string type for a message object of type '<outMessage>"
  "ISLH_msgs/outMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'outMessage)))
  "Returns string type for a message object of type 'outMessage"
  "ISLH_msgs/outMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<outMessage>)))
  "Returns md5sum for a message object of type '<outMessage>"
  "8e9310b478059d7c506189771b569d0d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'outMessage)))
  "Returns md5sum for a message object of type 'outMessage"
  "8e9310b478059d7c506189771b569d0d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<outMessage>)))
  "Returns full string definition for message of type '<outMessage>"
  (cl:format cl:nil "# outgoing  messages~%~%uint16[] robotid #receiver id~%~%uint16[] messageTypeID~%~%uint16[] messageIndx # which message is sent to which robot~%~%string[] message #message~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'outMessage)))
  "Returns full string definition for message of type 'outMessage"
  (cl:format cl:nil "# outgoing  messages~%~%uint16[] robotid #receiver id~%~%uint16[] messageTypeID~%~%uint16[] messageIndx # which message is sent to which robot~%~%string[] message #message~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <outMessage>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'robotid) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'messageTypeID) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'messageIndx) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'message) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <outMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'outMessage
    (cl:cons ':robotid (robotid msg))
    (cl:cons ':messageTypeID (messageTypeID msg))
    (cl:cons ':messageIndx (messageIndx msg))
    (cl:cons ':message (message msg))
))
