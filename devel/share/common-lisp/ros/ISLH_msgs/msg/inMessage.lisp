; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude inMessage.msg.html

(cl:defclass <inMessage> (roslisp-msg-protocol:ros-message)
  ((robotid
    :reader robotid
    :initarg :robotid
    :type cl:fixnum
    :initform 0)
   (messageid
    :reader messageid
    :initarg :messageid
    :type cl:fixnum
    :initform 0)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass inMessage (<inMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <inMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'inMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<inMessage> is deprecated: use ISLH_msgs-msg:inMessage instead.")))

(cl:ensure-generic-function 'robotid-val :lambda-list '(m))
(cl:defmethod robotid-val ((m <inMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:robotid-val is deprecated.  Use ISLH_msgs-msg:robotid instead.")
  (robotid m))

(cl:ensure-generic-function 'messageid-val :lambda-list '(m))
(cl:defmethod messageid-val ((m <inMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:messageid-val is deprecated.  Use ISLH_msgs-msg:messageid instead.")
  (messageid m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <inMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:message-val is deprecated.  Use ISLH_msgs-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <inMessage>) ostream)
  "Serializes a message object of type '<inMessage>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robotid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'robotid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <inMessage>) istream)
  "Deserializes a message object of type '<inMessage>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robotid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'robotid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<inMessage>)))
  "Returns string type for a message object of type '<inMessage>"
  "ISLH_msgs/inMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'inMessage)))
  "Returns string type for a message object of type 'inMessage"
  "ISLH_msgs/inMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<inMessage>)))
  "Returns md5sum for a message object of type '<inMessage>"
  "29816f7dd48299059674f73ccfcba3d5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'inMessage)))
  "Returns md5sum for a message object of type 'inMessage"
  "29816f7dd48299059674f73ccfcba3d5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<inMessage>)))
  "Returns full string definition for message of type '<inMessage>"
  (cl:format cl:nil "# Incoming messages~%~%uint16 robotid #sender id~%~%uint16 messageid~%~%string message #message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'inMessage)))
  "Returns full string definition for message of type 'inMessage"
  (cl:format cl:nil "# Incoming messages~%~%uint16 robotid #sender id~%~%uint16 messageid~%~%string message #message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <inMessage>))
  (cl:+ 0
     2
     2
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <inMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'inMessage
    (cl:cons ':robotid (robotid msg))
    (cl:cons ':messageid (messageid msg))
    (cl:cons ':message (message msg))
))
