;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::robotPositions)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'robotPositions (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::ROBOTPOSITIONS")
  (make-package "ISLH_MSGS::ROBOTPOSITIONS"))

(in-package "ROS")
;;//! \htmlinclude robotPositions.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass ISLH_msgs::robotPositions
  :super ros::object
  :slots (_positions _directions _IDs ))

(defmethod ISLH_msgs::robotPositions
  (:init
   (&key
    ((:positions __positions) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Pose2D :init) r)) r))
    ((:directions __directions) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:IDs __IDs) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _positions __positions)
   (setq _directions __directions)
   (setq _IDs __IDs)
   self)
  (:positions
   (&rest __positions)
   (if (keywordp (car __positions))
       (send* _positions __positions)
     (progn
       (if __positions (setq _positions (car __positions)))
       _positions)))
  (:directions
   (&optional __directions)
   (if __directions (setq _directions __directions)) _directions)
  (:IDs
   (&optional __IDs)
   (if __IDs (setq _IDs __IDs)) _IDs)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose2D[] _positions
    (apply #'+ (send-all _positions :serialization-length)) 4
    ;; float32[] _directions
    (* 4    (length _directions)) 4
    ;; int32[] _IDs
    (* 4    (length _IDs)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose2D[] _positions
     (write-long (length _positions) s)
     (dolist (elem _positions)
       (send elem :serialize s)
       )
     ;; float32[] _directions
     (write-long (length _directions) s)
     (dotimes (i (length _directions))
       (sys::poke (elt _directions i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; int32[] _IDs
     (write-long (length _IDs) s)
     (dotimes (i (length _IDs))
       (write-long (elt _IDs i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose2D[] _positions
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _positions (let (r) (dotimes (i n) (push (instance geometry_msgs::Pose2D :init) r)) r))
     (dolist (elem- _positions)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; float32[] _directions
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _directions (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _directions i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; int32[] _IDs
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _IDs (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _IDs i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get ISLH_msgs::robotPositions :md5sum-) "34cbcefe1d81906e675edae485d8d875")
(setf (get ISLH_msgs::robotPositions :datatype-) "ISLH_msgs/robotPositions")
(setf (get ISLH_msgs::robotPositions :definition-)
      "#The robots' position information

geometry_msgs/Pose2D[] positions

float32[] directions

int32[] IDs

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



(provide :ISLH_msgs/robotPositions "34cbcefe1d81906e675edae485d8d875")


