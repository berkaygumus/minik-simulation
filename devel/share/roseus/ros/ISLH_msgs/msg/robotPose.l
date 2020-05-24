;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::robotPose)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'robotPose (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::ROBOTPOSE")
  (make-package "ISLH_MSGS::ROBOTPOSE"))

(in-package "ROS")
;;//! \htmlinclude robotPose.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass ISLH_msgs::robotPose
  :super ros::object
  :slots (_id _position _target _calYaw _radYaw ))

(defmethod ISLH_msgs::robotPose
  (:init
   (&key
    ((:id __id) 0)
    ((:position __position) (instance geometry_msgs::Point :init))
    ((:target __target) (instance geometry_msgs::Point :init))
    ((:calYaw __calYaw) 0.0)
    ((:radYaw __radYaw) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _position __position)
   (setq _target __target)
   (setq _calYaw (float __calYaw))
   (setq _radYaw (float __radYaw))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:target
   (&rest __target)
   (if (keywordp (car __target))
       (send* _target __target)
     (progn
       (if __target (setq _target (car __target)))
       _target)))
  (:calYaw
   (&optional __calYaw)
   (if __calYaw (setq _calYaw __calYaw)) _calYaw)
  (:radYaw
   (&optional __radYaw)
   (if __radYaw (setq _radYaw __radYaw)) _radYaw)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; geometry_msgs/Point _position
    (send _position :serialization-length)
    ;; geometry_msgs/Point _target
    (send _target :serialization-length)
    ;; float32 _calYaw
    4
    ;; float32 _radYaw
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; geometry_msgs/Point _position
       (send _position :serialize s)
     ;; geometry_msgs/Point _target
       (send _target :serialize s)
     ;; float32 _calYaw
       (sys::poke _calYaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _radYaw
       (sys::poke _radYaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Point _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; geometry_msgs/Point _target
     (send _target :deserialize buf ptr-) (incf ptr- (send _target :serialization-length))
   ;; float32 _calYaw
     (setq _calYaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _radYaw
     (setq _radYaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get ISLH_msgs::robotPose :md5sum-) "0eef6d6e44271c92907c87eea9d5073a")
(setf (get ISLH_msgs::robotPose :datatype-) "ISLH_msgs/robotPose")
(setf (get ISLH_msgs::robotPose :definition-)
      "#The robot's position information and target information

int32 id

geometry_msgs/Point position

geometry_msgs/Point target

float32 calYaw
float32 radYaw

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :ISLH_msgs/robotPose "0eef6d6e44271c92907c87eea9d5073a")


