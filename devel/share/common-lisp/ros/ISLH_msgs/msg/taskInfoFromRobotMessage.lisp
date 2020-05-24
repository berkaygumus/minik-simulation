; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude taskInfoFromRobotMessage.msg.html

(cl:defclass <taskInfoFromRobotMessage> (roslisp-msg-protocol:ros-message)
  ((senderRobotID
    :reader senderRobotID
    :initarg :senderRobotID
    :type cl:fixnum
    :initform 0)
   (infoMessageType
    :reader infoMessageType
    :initarg :infoMessageType
    :type cl:fixnum
    :initform 0)
   (taskUUID
    :reader taskUUID
    :initarg :taskUUID
    :type cl:string
    :initform "")
   (encounteringTime
    :reader encounteringTime
    :initarg :encounteringTime
    :type cl:integer
    :initform 0)
   (reachingTime
    :reader reachingTime
    :initarg :reachingTime
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
    :initform "")
   (posX
    :reader posX
    :initarg :posX
    :type cl:float
    :initform 0.0)
   (posY
    :reader posY
    :initarg :posY
    :type cl:float
    :initform 0.0))
)

(cl:defclass taskInfoFromRobotMessage (<taskInfoFromRobotMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <taskInfoFromRobotMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'taskInfoFromRobotMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<taskInfoFromRobotMessage> is deprecated: use ISLH_msgs-msg:taskInfoFromRobotMessage instead.")))

(cl:ensure-generic-function 'senderRobotID-val :lambda-list '(m))
(cl:defmethod senderRobotID-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:senderRobotID-val is deprecated.  Use ISLH_msgs-msg:senderRobotID instead.")
  (senderRobotID m))

(cl:ensure-generic-function 'infoMessageType-val :lambda-list '(m))
(cl:defmethod infoMessageType-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:infoMessageType-val is deprecated.  Use ISLH_msgs-msg:infoMessageType instead.")
  (infoMessageType m))

(cl:ensure-generic-function 'taskUUID-val :lambda-list '(m))
(cl:defmethod taskUUID-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:taskUUID-val is deprecated.  Use ISLH_msgs-msg:taskUUID instead.")
  (taskUUID m))

(cl:ensure-generic-function 'encounteringTime-val :lambda-list '(m))
(cl:defmethod encounteringTime-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:encounteringTime-val is deprecated.  Use ISLH_msgs-msg:encounteringTime instead.")
  (encounteringTime m))

(cl:ensure-generic-function 'reachingTime-val :lambda-list '(m))
(cl:defmethod reachingTime-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:reachingTime-val is deprecated.  Use ISLH_msgs-msg:reachingTime instead.")
  (reachingTime m))

(cl:ensure-generic-function 'handlingDuration-val :lambda-list '(m))
(cl:defmethod handlingDuration-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:handlingDuration-val is deprecated.  Use ISLH_msgs-msg:handlingDuration instead.")
  (handlingDuration m))

(cl:ensure-generic-function 'timeOutDuration-val :lambda-list '(m))
(cl:defmethod timeOutDuration-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:timeOutDuration-val is deprecated.  Use ISLH_msgs-msg:timeOutDuration instead.")
  (timeOutDuration m))

(cl:ensure-generic-function 'requiredResources-val :lambda-list '(m))
(cl:defmethod requiredResources-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:requiredResources-val is deprecated.  Use ISLH_msgs-msg:requiredResources instead.")
  (requiredResources m))

(cl:ensure-generic-function 'posX-val :lambda-list '(m))
(cl:defmethod posX-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:posX-val is deprecated.  Use ISLH_msgs-msg:posX instead.")
  (posX m))

(cl:ensure-generic-function 'posY-val :lambda-list '(m))
(cl:defmethod posY-val ((m <taskInfoFromRobotMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:posY-val is deprecated.  Use ISLH_msgs-msg:posY instead.")
  (posY m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <taskInfoFromRobotMessage>) ostream)
  "Serializes a message object of type '<taskInfoFromRobotMessage>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'senderRobotID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'senderRobotID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'infoMessageType)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'infoMessageType)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'taskUUID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'taskUUID))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reachingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reachingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reachingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reachingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'reachingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'reachingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'reachingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'reachingTime)) ostream)
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'posX))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'posY))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <taskInfoFromRobotMessage>) istream)
  "Deserializes a message object of type '<taskInfoFromRobotMessage>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'senderRobotID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'senderRobotID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'infoMessageType)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'infoMessageType)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'taskUUID) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'taskUUID) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'reachingTime)) (cl:read-byte istream))
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'posX) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'posY) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<taskInfoFromRobotMessage>)))
  "Returns string type for a message object of type '<taskInfoFromRobotMessage>"
  "ISLH_msgs/taskInfoFromRobotMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'taskInfoFromRobotMessage)))
  "Returns string type for a message object of type 'taskInfoFromRobotMessage"
  "ISLH_msgs/taskInfoFromRobotMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<taskInfoFromRobotMessage>)))
  "Returns md5sum for a message object of type '<taskInfoFromRobotMessage>"
  "e54b818b14e2cc4a576aa5a518a1a847")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'taskInfoFromRobotMessage)))
  "Returns md5sum for a message object of type 'taskInfoFromRobotMessage"
  "e54b818b14e2cc4a576aa5a518a1a847")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<taskInfoFromRobotMessage>)))
  "Returns full string definition for message of type '<taskInfoFromRobotMessage>"
  (cl:format cl:nil "# The task's information  from member robot to coalition leader~%~%uint16 senderRobotID #robot id which encounters the task~%~%uint16 infoMessageType~%~%string taskUUID # the task's UUID~%~%uint64 encounteringTime #The encountering time in timestamp form~%~%uint64 reachingTime # The time when the robot reached to the task site~%~%uint16 handlingDuration~%~%uint16 timeOutDuration~%~%string requiredResources # Required resources for this task~%~%float32 posX # The position of the task at x direction ~%float32 posY # The position of the task at y direction ~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'taskInfoFromRobotMessage)))
  "Returns full string definition for message of type 'taskInfoFromRobotMessage"
  (cl:format cl:nil "# The task's information  from member robot to coalition leader~%~%uint16 senderRobotID #robot id which encounters the task~%~%uint16 infoMessageType~%~%string taskUUID # the task's UUID~%~%uint64 encounteringTime #The encountering time in timestamp form~%~%uint64 reachingTime # The time when the robot reached to the task site~%~%uint16 handlingDuration~%~%uint16 timeOutDuration~%~%string requiredResources # Required resources for this task~%~%float32 posX # The position of the task at x direction ~%float32 posY # The position of the task at y direction ~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <taskInfoFromRobotMessage>))
  (cl:+ 0
     2
     2
     4 (cl:length (cl:slot-value msg 'taskUUID))
     8
     8
     2
     2
     4 (cl:length (cl:slot-value msg 'requiredResources))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <taskInfoFromRobotMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'taskInfoFromRobotMessage
    (cl:cons ':senderRobotID (senderRobotID msg))
    (cl:cons ':infoMessageType (infoMessageType msg))
    (cl:cons ':taskUUID (taskUUID msg))
    (cl:cons ':encounteringTime (encounteringTime msg))
    (cl:cons ':reachingTime (reachingTime msg))
    (cl:cons ':handlingDuration (handlingDuration msg))
    (cl:cons ':timeOutDuration (timeOutDuration msg))
    (cl:cons ':requiredResources (requiredResources msg))
    (cl:cons ':posX (posX msg))
    (cl:cons ':posY (posY msg))
))
