;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::targetPoseListMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'targetPoseListMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::TARGETPOSELISTMESSAGE")
  (make-package "ISLH_MSGS::TARGETPOSELISTMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude targetPoseListMessage.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass ISLH_msgs::targetPoseListMessage
  :super ros::object
  :slots (_robotIDs _targetPoses ))

(defmethod ISLH_msgs::targetPoseListMessage
  (:init
   (&key
    ((:robotIDs __robotIDs) (make-array 0 :initial-element 0 :element-type :integer))
    ((:targetPoses __targetPoses) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Pose2D :init) r)) r))
    )
   (send-super :init)
   (setq _robotIDs __robotIDs)
   (setq _targetPoses __targetPoses)
   self)
  (:robotIDs
   (&optional __robotIDs)
   (if __robotIDs (setq _robotIDs __robotIDs)) _robotIDs)
  (:targetPoses
   (&rest __targetPoses)
   (if (keywordp (car __targetPoses))
       (send* _targetPoses __targetPoses)
     (progn
       (if __targetPoses (setq _targetPoses (car __targetPoses)))
       _targetPoses)))
  (:serialization-length
   ()
   (+
    ;; uint16[] _robotIDs
    (* 2    (length _robotIDs)) 4
    ;; geometry_msgs/Pose2D[] _targetPoses
    (apply #'+ (send-all _targetPoses :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16[] _robotIDs
     (write-long (length _robotIDs) s)
     (dotimes (i (length _robotIDs))
       (write-word (elt _robotIDs i) s)
       )
     ;; geometry_msgs/Pose2D[] _targetPoses
     (write-long (length _targetPoses) s)
     (dolist (elem _targetPoses)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16[] _robotIDs
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _robotIDs (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _robotIDs i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; geometry_msgs/Pose2D[] _targetPoses
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _targetPoses (let (r) (dotimes (i n) (push (instance geometry_msgs::Pose2D :init) r)) r))
     (dolist (elem- _targetPoses)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get ISLH_msgs::targetPoseListMessage :md5sum-) "d1b04727e448336dea593a258b3fabf6")
(setf (get ISLH_msgs::targetPoseListMessage :datatype-) "ISLH_msgs/targetPoseListMessage")
(setf (get ISLH_msgs::targetPoseListMessage :definition-)
      "# The incoming message (target pose list) from coalition leader

uint16[] robotIDs

geometry_msgs/Pose2D[] targetPoses

================================================================================
MSG: geometry_msgs/Pose2D
# Deprecated
# Please use the full 3D pose.

# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.

# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.


# This expresses a position and orientation on a 2D manifold.

float64 x
float64 y
float64 theta

")



(provide :ISLH_msgs/targetPoseListMessage "d1b04727e448336dea593a258b3fabf6")


