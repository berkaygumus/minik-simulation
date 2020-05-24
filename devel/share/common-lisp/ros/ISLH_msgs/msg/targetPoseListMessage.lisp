; Auto-generated. Do not edit!


(cl:in-package ISLH_msgs-msg)


;//! \htmlinclude targetPoseListMessage.msg.html

(cl:defclass <targetPoseListMessage> (roslisp-msg-protocol:ros-message)
  ((robotIDs
    :reader robotIDs
    :initarg :robotIDs
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (targetPoses
    :reader targetPoses
    :initarg :targetPoses
    :type (cl:vector geometry_msgs-msg:Pose2D)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Pose2D :initial-element (cl:make-instance 'geometry_msgs-msg:Pose2D))))
)

(cl:defclass targetPoseListMessage (<targetPoseListMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <targetPoseListMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'targetPoseListMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ISLH_msgs-msg:<targetPoseListMessage> is deprecated: use ISLH_msgs-msg:targetPoseListMessage instead.")))

(cl:ensure-generic-function 'robotIDs-val :lambda-list '(m))
(cl:defmethod robotIDs-val ((m <targetPoseListMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:robotIDs-val is deprecated.  Use ISLH_msgs-msg:robotIDs instead.")
  (robotIDs m))

(cl:ensure-generic-function 'targetPoses-val :lambda-list '(m))
(cl:defmethod targetPoses-val ((m <targetPoseListMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ISLH_msgs-msg:targetPoses-val is deprecated.  Use ISLH_msgs-msg:targetPoses instead.")
  (targetPoses m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <targetPoseListMessage>) ostream)
  "Serializes a message object of type '<targetPoseListMessage>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'robotIDs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'robotIDs))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'targetPoses))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'targetPoses))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <targetPoseListMessage>) istream)
  "Deserializes a message object of type '<targetPoseListMessage>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'robotIDs) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'robotIDs)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'targetPoses) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'targetPoses)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Pose2D))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<targetPoseListMessage>)))
  "Returns string type for a message object of type '<targetPoseListMessage>"
  "ISLH_msgs/targetPoseListMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'targetPoseListMessage)))
  "Returns string type for a message object of type 'targetPoseListMessage"
  "ISLH_msgs/targetPoseListMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<targetPoseListMessage>)))
  "Returns md5sum for a message object of type '<targetPoseListMessage>"
  "d1b04727e448336dea593a258b3fabf6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'targetPoseListMessage)))
  "Returns md5sum for a message object of type 'targetPoseListMessage"
  "d1b04727e448336dea593a258b3fabf6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<targetPoseListMessage>)))
  "Returns full string definition for message of type '<targetPoseListMessage>"
  (cl:format cl:nil "# The incoming message (target pose list) from coalition leader~%~%uint16[] robotIDs~%~%geometry_msgs/Pose2D[] targetPoses~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'targetPoseListMessage)))
  "Returns full string definition for message of type 'targetPoseListMessage"
  (cl:format cl:nil "# The incoming message (target pose list) from coalition leader~%~%uint16[] robotIDs~%~%geometry_msgs/Pose2D[] targetPoses~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <targetPoseListMessage>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'robotIDs) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'targetPoses) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <targetPoseListMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'targetPoseListMessage
    (cl:cons ':robotIDs (robotIDs msg))
    (cl:cons ':targetPoses (targetPoses msg))
))
