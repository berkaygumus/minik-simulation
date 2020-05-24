; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude taskInfo2MonitorMessage.msg.html

(cl:defclass <taskInfo2MonitorMessage> (roslisp-msg-protocol:ros-message)
  ((taskUUID
    :reader taskUUID
    :initarg :taskUUID
    :type cl:string
    :initform "")
   (encounteringRobotID
    :reader encounteringRobotID
    :initarg :encounteringRobotID
    :type cl:fixnum
    :initform 0)
   (responsibleUnit
    :reader responsibleUnit
    :initarg :responsibleUnit
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
   (posXY
    :reader posXY
    :initarg :posXY
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (taskResource
    :reader taskResource
    :initarg :taskResource
    :type cl:string
    :initform "")
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
   (status
    :reader status
    :initarg :status
    :type cl:fixnum
    :initform 0)
   (taskSiteRadius
    :reader taskSiteRadius
    :initarg :taskSiteRadius
    :type cl:integer
    :initform 0))
)

(cl:defclass taskInfo2MonitorMessage (<taskInfo2MonitorMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <taskInfo2MonitorMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'taskInfo2MonitorMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<taskInfo2MonitorMessage> is deprecated: use ISLH_msgs-msg:taskInfo2MonitorMessage instead.")))

(cl:ensure-generic-function 'taskUUID-val :lambda-list '(m))
(cl:defmethod taskUUID-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:taskUUID-val is deprecated.  Use ISLH_msgs-msg:taskUUID instead.")
  (taskUUID m))

(cl:ensure-generic-function 'encounteringRobotID-val :lambda-list '(m))
(cl:defmethod encounteringRobotID-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:encounteringRobotID-val is deprecated.  Use ISLH_msgs-msg:encounteringRobotID instead.")
  (encounteringRobotID m))

(cl:ensure-generic-function 'responsibleUnit-val :lambda-list '(m))
(cl:defmethod responsibleUnit-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:responsibleUnit-val is deprecated.  Use ISLH_msgs-msg:responsibleUnit instead.")
  (responsibleUnit m))

(cl:ensure-generic-function 'encounteringTime-val :lambda-list '(m))
(cl:defmethod encounteringTime-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:encounteringTime-val is deprecated.  Use ISLH_msgs-msg:encounteringTime instead.")
  (encounteringTime m))

(cl:ensure-generic-function 'startHandlingTime-val :lambda-list '(m))
(cl:defmethod startHandlingTime-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:startHandlingTime-val is deprecated.  Use ISLH_msgs-msg:startHandlingTime instead.")
  (startHandlingTime m))

(cl:ensure-generic-function 'posXY-val :lambda-list '(m))
(cl:defmethod posXY-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:posXY-val is deprecated.  Use ISLH_msgs-msg:posXY instead.")
  (posXY m))

(cl:ensure-generic-function 'taskResource-val :lambda-list '(m))
(cl:defmethod taskResource-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:taskResource-val is deprecated.  Use ISLH_msgs-msg:taskResource instead.")
  (taskResource m))

(cl:ensure-generic-function 'handlingDuration-val :lambda-list '(m))
(cl:defmethod handlingDuration-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:handlingDuration-val is deprecated.  Use ISLH_msgs-msg:handlingDuration instead.")
  (handlingDuration m))

(cl:ensure-generic-function 'timeOutDuration-val :lambda-list '(m))
(cl:defmethod timeOutDuration-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:timeOutDuration-val is deprecated.  Use ISLH_msgs-msg:timeOutDuration instead.")
  (timeOutDuration m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:status-val is deprecated.  Use ISLH_msgs-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'taskSiteRadius-val :lambda-list '(m))
(cl:defmethod taskSiteRadius-val ((m <taskInfo2MonitorMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:taskSiteRadius-val is deprecated.  Use ISLH_msgs-msg:taskSiteRadius instead.")
  (taskSiteRadius m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <taskInfo2MonitorMessage>) ostream)
  "Serializes a message object of type '<taskInfo2MonitorMessage>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'taskUUID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'taskUUID))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringRobotID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringRobotID)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'responsibleUnit)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
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
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'posXY) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'taskResource))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'taskResource))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'handlingDuration)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'handlingDuration)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeOutDuration)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeOutDuration)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'status)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'taskSiteRadius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'taskSiteRadius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'taskSiteRadius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'taskSiteRadius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'taskSiteRadius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'taskSiteRadius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'taskSiteRadius)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'taskSiteRadius)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <taskInfo2MonitorMessage>) istream)
  "Deserializes a message object of type '<taskInfo2MonitorMessage>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'taskUUID) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'taskUUID) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encounteringRobotID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encounteringRobotID)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'responsibleUnit) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
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
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'posXY) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'taskResource) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'taskResource) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'handlingDuration)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'handlingDuration)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeOutDuration)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeOutDuration)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'status)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'taskSiteRadius)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<taskInfo2MonitorMessage>)))
  "Returns string type for a message object of type '<taskInfo2MonitorMessage>"
  "ISLH_msgs/taskInfo2MonitorMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'taskInfo2MonitorMessage)))
  "Returns string type for a message object of type 'taskInfo2MonitorMessage"
  "ISLH_msgs/taskInfo2MonitorMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<taskInfo2MonitorMessage>)))
  "Returns md5sum for a message object of type '<taskInfo2MonitorMessage>"
  "306235d16ea68afd7b8cdaafd193738f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'taskInfo2MonitorMessage)))
  "Returns md5sum for a message object of type 'taskInfo2MonitorMessage"
  "306235d16ea68afd7b8cdaafd193738f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<taskInfo2MonitorMessage>)))
  "Returns full string definition for message of type '<taskInfo2MonitorMessage>"
  (cl:format cl:nil "# The task's information to monitoringISLH~%~%string taskUUID # the task's UUID~%~%uint16 encounteringRobotID #robot id which encounters the task~%~%int16 responsibleUnit # \"who is responsible for the task\"~%~%uint64 encounteringTime #The encountering time~%~%uint64 startHandlingTime #the time when the task starts being handled~%~%geometry_msgs/Point posXY  # The position of the task~%~%string taskResource~%~%uint16 handlingDuration # in seconds - \"the required time to handle the task\"~%~%uint16 timeOutDuration # \"the timed-out duration for the task\"~%~%uint16 status # \"status of the task\"~%~%uint64 taskSiteRadius~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'taskInfo2MonitorMessage)))
  "Returns full string definition for message of type 'taskInfo2MonitorMessage"
  (cl:format cl:nil "# The task's information to monitoringISLH~%~%string taskUUID # the task's UUID~%~%uint16 encounteringRobotID #robot id which encounters the task~%~%int16 responsibleUnit # \"who is responsible for the task\"~%~%uint64 encounteringTime #The encountering time~%~%uint64 startHandlingTime #the time when the task starts being handled~%~%geometry_msgs/Point posXY  # The position of the task~%~%string taskResource~%~%uint16 handlingDuration # in seconds - \"the required time to handle the task\"~%~%uint16 timeOutDuration # \"the timed-out duration for the task\"~%~%uint16 status # \"status of the task\"~%~%uint64 taskSiteRadius~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <taskInfo2MonitorMessage>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'taskUUID))
     2
     2
     8
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'posXY))
     4 (cl:length (cl:slot-value msg 'taskResource))
     2
     2
     2
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <taskInfo2MonitorMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'taskInfo2MonitorMessage
    (cl:cons ':taskUUID (taskUUID msg))
    (cl:cons ':encounteringRobotID (encounteringRobotID msg))
    (cl:cons ':responsibleUnit (responsibleUnit msg))
    (cl:cons ':encounteringTime (encounteringTime msg))
    (cl:cons ':startHandlingTime (startHandlingTime msg))
    (cl:cons ':posXY (posXY msg))
    (cl:cons ':taskResource (taskResource msg))
    (cl:cons ':handlingDuration (handlingDuration msg))
    (cl:cons ':timeOutDuration (timeOutDuration msg))
    (cl:cons ':status (status msg))
    (cl:cons ':taskSiteRadius (taskSiteRadius msg))
))
