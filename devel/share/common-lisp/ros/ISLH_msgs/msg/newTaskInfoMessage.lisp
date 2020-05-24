; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude newTaskInfoMessage.msg.html

(cl:defclass <newTaskInfoMessage> (roslisp-msg-protocol:ros-message)
  ((taskUUID
    :reader taskUUID
    :initarg :taskUUID
    :type cl:string
    :initform "")
   (timeStamp
    :reader timeStamp
    :initarg :timeStamp
    :type cl:integer
    :initform 0)
   (handlingDuration
    :reader handlingDuration
    :initarg :handlingDuration
    :type cl:fixnum
    :initform 0)
   (timeOutDuration
    :reader timeOutDuration
    :initarg :timeOutDuration
    :type cl:fixnum
    :initform 0)
   (requiredResources
    :reader requiredResources
    :initarg :requiredResources
    :type cl:string
    :initform ""))
)

(cl:defclass newTaskInfoMessage (<newTaskInfoMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <newTaskInfoMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'newTaskInfoMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<newTaskInfoMessage> is deprecated: use ISLH_msgs-msg:newTaskInfoMessage instead.")))

(cl:ensure-generic-function 'taskUUID-val :lambda-list '(m))
(cl:defmethod taskUUID-val ((m <newTaskInfoMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:taskUUID-val is deprecated.  Use ISLH_msgs-msg:taskUUID instead.")
  (taskUUID m))

(cl:ensure-generic-function 'timeStamp-val :lambda-list '(m))
(cl:defmethod timeStamp-val ((m <newTaskInfoMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:timeStamp-val is deprecated.  Use ISLH_msgs-msg:timeStamp instead.")
  (timeStamp m))

(cl:ensure-generic-function 'handlingDuration-val :lambda-list '(m))
(cl:defmethod handlingDuration-val ((m <newTaskInfoMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:handlingDuration-val is deprecated.  Use ISLH_msgs-msg:handlingDuration instead.")
  (handlingDuration m))

(cl:ensure-generic-function 'timeOutDuration-val :lambda-list '(m))
(cl:defmethod timeOutDuration-val ((m <newTaskInfoMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:timeOutDuration-val is deprecated.  Use ISLH_msgs-msg:timeOutDuration instead.")
  (timeOutDuration m))

(cl:ensure-generic-function 'requiredResources-val :lambda-list '(m))
(cl:defmethod requiredResources-val ((m <newTaskInfoMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:requiredResources-val is deprecated.  Use ISLH_msgs-msg:requiredResources instead.")
  (requiredResources m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <newTaskInfoMessage>) ostream)
  "Serializes a message object of type '<newTaskInfoMessage>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'taskUUID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'taskUUID))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'timeStamp)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'handlingDuration)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'handlingDuration)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeOutDuration)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeOutDuration)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'requiredResources))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'requiredResources))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <newTaskInfoMessage>) istream)
  "Deserializes a message object of type '<newTaskInfoMessage>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'taskUUID) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'taskUUID) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'timeStamp)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'handlingDuration)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'handlingDuration)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeOutDuration)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeOutDuration)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'requiredResources) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'requiredResources) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<newTaskInfoMessage>)))
  "Returns string type for a message object of type '<newTaskInfoMessage>"
  "ISLH_msgs/newTaskInfoMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'newTaskInfoMessage)))
  "Returns string type for a message object of type 'newTaskInfoMessage"
  "ISLH_msgs/newTaskInfoMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<newTaskInfoMessage>)))
  "Returns md5sum for a message object of type '<newTaskInfoMessage>"
  "0857da229f3a63b6ca6a5f69dd323a29")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'newTaskInfoMessage)))
  "Returns md5sum for a message object of type 'newTaskInfoMessage"
  "0857da229f3a63b6ca6a5f69dd323a29")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<newTaskInfoMessage>)))
  "Returns full string definition for message of type '<newTaskInfoMessage>"
  (cl:format cl:nil "# New task's information~%~%string taskUUID # Universally Unique Identifier (UUID)~%~%uint64 timeStamp #The encountering time~%~%uint16 handlingDuration~%~%uint16 timeOutDuration~%~%string requiredResources # Required resources for this task~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'newTaskInfoMessage)))
  "Returns full string definition for message of type 'newTaskInfoMessage"
  (cl:format cl:nil "# New task's information~%~%string taskUUID # Universally Unique Identifier (UUID)~%~%uint64 timeStamp #The encountering time~%~%uint16 handlingDuration~%~%uint16 timeOutDuration~%~%string requiredResources # Required resources for this task~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <newTaskInfoMessage>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'taskUUID))
     8
     2
     2
     4 (cl:length (cl:slot-value msg 'requiredResources))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <newTaskInfoMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'newTaskInfoMessage
    (cl:cons ':taskUUID (taskUUID msg))
    (cl:cons ':timeStamp (timeStamp msg))
    (cl:cons ':handlingDuration (handlingDuration msg))
    (cl:cons ':timeOutDuration (timeOutDuration msg))
    (cl:cons ':requiredResources (requiredResources msg))
))
