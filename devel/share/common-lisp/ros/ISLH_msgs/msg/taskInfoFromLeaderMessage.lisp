; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude taskInfoFromLeaderMessage.msg.html

(cl:defclass <taskInfoFromLeaderMessage> (roslisp-msg-protocol:ros-message)
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
   (senderRobotID
    :reader senderRobotID
    :initarg :senderRobotID
    :type cl:fixnum
    :initform 0)
   (encounteringRobotID
    :reader encounteringRobotID
    :initarg :encounteringRobotID
    :type cl:fixnum
    :initform 0)
   (encounteringTime
    :reader encounteringTime
    :initarg :encounteringTime
    :type cl:integer
    :initform 0)
   (startHandlingTime
    :reader startHandlingTime
    :initarg :startHandlingTime
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
    :initform 0.0)
   (taskUUID
    :reader taskUUID
    :initarg :taskUUID
    :type cl:string
    :initform "")
   (extraMsg
    :reader extraMsg
    :initarg :extraMsg
    :type cl:string
    :initform ""))
)

(cl:defclass taskInfoFromLeaderMessage (<taskInfoFromLeaderMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <taskInfoFromLeaderMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'taskInfoFromLeaderMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<taskInfoFromLeaderMessage> is deprecated: use ISLH_msgs-msg:taskInfoFromLeaderMessage instead.")))

(cl:ensure-generic-function 'sendingTime-val :lambda-list '(m))
(cl:defmethod sendingTime-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:sendingTime-val is deprecated.  Use ISLH_msgs-msg:sendingTime instead.")
  (sendingTime m))

(cl:ensure-generic-function 'infoTypeID-val :lambda-list '(m))
(cl:defmethod infoTypeID-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:infoTypeID-val is deprecated.  Use ISLH_msgs-msg:infoTypeID instead.")
  (infoTypeID m))

(cl:ensure-generic-function 'senderRobotID-val :lambda-list '(m))
(cl:defmethod senderRobotID-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:senderRobotID-val is deprecated.  Use ISLH_msgs-msg:senderRobotID instead.")
  (senderRobotID m))

(cl:ensure-generic-function 'encounteringRobotID-val :lambda-list '(m))
(cl:defmethod encounteringRobotID-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:encounteringRobotID-val is deprecated.  Use ISLH_msgs-msg:encounteringRobotID instead.")
  (encounteringRobotID m))

(cl:ensure-generic-function 'encounteringTime-val :lambda-list '(m))
(cl:defmethod encounteringTime-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:encounteringTime-val is deprecated.  Use ISLH_msgs-msg:encounteringTime instead.")
  (encounteringTime m))

(cl:ensure-generic-function 'startHandlingTime-val :lambda-list '(m))
(cl:defmethod startHandlingTime-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:startHandlingTime-val is deprecated.  Use ISLH_msgs-msg:startHandlingTime instead.")
  (startHandlingTime m))

(cl:ensure-generic-function 'handlingDuration-val :lambda-list '(m))
(cl:defmethod handlingDuration-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:handlingDuration-val is deprecated.  Use ISLH_msgs-msg:handlingDuration instead.")
  (handlingDuration m))

(cl:ensure-generic-function 'timeOutDuration-val :lambda-list '(m))
(cl:defmethod timeOutDuration-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:timeOutDuration-val is deprecated.  Use ISLH_msgs-msg:timeOutDuration instead.")
  (timeOutDuration m))

(cl:ensure-generic-function 'requiredResources-val :lambda-list '(m))
(cl:defmethod requiredResources-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:requiredResources-val is deprecated.  Use ISLH_msgs-msg:requiredResources instead.")
  (requiredResources m))

(cl:ensure-generic-function 'posX-val :lambda-list '(m))
(cl:defmethod posX-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:posX-val is deprecated.  Use ISLH_msgs-msg:posX instead.")
  (posX m))

(cl:ensure-generic-function 'posY-val :lambda-list '(m))
(cl:defmethod posY-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:posY-val is deprecated.  Use ISLH_msgs-msg:posY instead.")
  (posY m))

(cl:ensure-generic-function 'taskUUID-val :lambda-list '(m))
(cl:defmethod taskUUID-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:taskUUID-val is deprecated.  Use ISLH_msgs-msg:taskUUID instead.")
  (taskUUID m))

(cl:ensure-generic-function 'extraMsg-val :lambda-list '(m))
(cl:defmethod extraMsg-val ((m <taskInfoFromLeaderMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:extraMsg-val is deprecated.  Use ISLH_msgs-msg:extraMsg instead.")
  (extraMsg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <taskInfoFromLeaderMessage>) ostream)
  "Serializes a message object of type '<taskInfoFromLeaderMessage>"
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'senderRobotID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'senderRobotID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringRobotID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringRobotID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'encounteringTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'startHandlingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'startHandlingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'startHandlingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'startHandlingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'startHandlingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'startHandlingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'startHandlingTime)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'startHandlingTime)) ostream)
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
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'taskUUID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'taskUUID))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'extraMsg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'extraMsg))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <taskInfoFromLeaderMessage>) istream)
  "Deserializes a message object of type '<taskInfoFromLeaderMessage>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'senderRobotID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'senderRobotID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringRobotID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringRobotID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'encounteringTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'startHandlingTime)) (cl:read-byte istream))
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
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'taskUUID) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'taskUUID) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'extraMsg) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'extraMsg) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<taskInfoFromLeaderMessage>)))
  "Returns string type for a message object of type '<taskInfoFromLeaderMessage>"
  "ISLH_msgs/taskInfoFromLeaderMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'taskInfoFromLeaderMessage)))
  "Returns string type for a message object of type 'taskInfoFromLeaderMessage"
  "ISLH_msgs/taskInfoFromLeaderMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<taskInfoFromLeaderMessage>)))
  "Returns md5sum for a message object of type '<taskInfoFromLeaderMessage>"
  "a19d17ade63c51621e68763c106dd71e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'taskInfoFromLeaderMessage)))
  "Returns md5sum for a message object of type 'taskInfoFromLeaderMessage"
  "a19d17ade63c51621e68763c106dd71e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<taskInfoFromLeaderMessage>)))
  "Returns full string definition for message of type '<taskInfoFromLeaderMessage>"
  (cl:format cl:nil "# The task's information to the task coordinator~%~%uint64 sendingTime #The sending time~%~%uint16 infoTypeID~%~%uint16 senderRobotID # robot id of coalition leader ~%~%uint16 encounteringRobotID #robot id which encounters the task~%~%uint64 encounteringTime #The encountering time in timestamp form~%~%uint64 startHandlingTime #the time when the task starts being handled~%~%uint16 handlingDuration~%~%uint16 timeOutDuration~%~%string requiredResources # Required resources for this task~%~%float32 posX # The position of the task at x direction~%float32 posY # The position of the task at y direction~%~%string taskUUID # the task's UUID~%~%string extraMsg~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'taskInfoFromLeaderMessage)))
  "Returns full string definition for message of type 'taskInfoFromLeaderMessage"
  (cl:format cl:nil "# The task's information to the task coordinator~%~%uint64 sendingTime #The sending time~%~%uint16 infoTypeID~%~%uint16 senderRobotID # robot id of coalition leader ~%~%uint16 encounteringRobotID #robot id which encounters the task~%~%uint64 encounteringTime #The encountering time in timestamp form~%~%uint64 startHandlingTime #the time when the task starts being handled~%~%uint16 handlingDuration~%~%uint16 timeOutDuration~%~%string requiredResources # Required resources for this task~%~%float32 posX # The position of the task at x direction~%float32 posY # The position of the task at y direction~%~%string taskUUID # the task's UUID~%~%string extraMsg~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <taskInfoFromLeaderMessage>))
  (cl:+ 0
     8
     2
     2
     2
     8
     8
     2
     2
     4 (cl:length (cl:slot-value msg 'requiredResources))
     4
     4
     4 (cl:length (cl:slot-value msg 'taskUUID))
     4 (cl:length (cl:slot-value msg 'extraMsg))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <taskInfoFromLeaderMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'taskInfoFromLeaderMessage
    (cl:cons ':sendingTime (sendingTime msg))
    (cl:cons ':infoTypeID (infoTypeID msg))
    (cl:cons ':senderRobotID (senderRobotID msg))
    (cl:cons ':encounteringRobotID (encounteringRobotID msg))
    (cl:cons ':encounteringTime (encounteringTime msg))
    (cl:cons ':startHandlingTime (startHandlingTime msg))
    (cl:cons ':handlingDuration (handlingDuration msg))
    (cl:cons ':timeOutDuration (timeOutDuration msg))
    (cl:cons ':requiredResources (requiredResources msg))
    (cl:cons ':posX (posX msg))
    (cl:cons ':posY (posY msg))
    (cl:cons ':taskUUID (taskUUID msg))
    (cl:cons ':extraMsg (extraMsg msg))
))
