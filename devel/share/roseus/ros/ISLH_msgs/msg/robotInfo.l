;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::robotInfo)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'robotInfo (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::ROBOTINFO")
  (make-package "ISLH_MSGS::ROBOTINFO"))

(in-package "ROS")
;;//! \htmlinclude robotInfo.msg.html


(defclass ISLH_msgs::robotInfo
  :super ros::object
  :slots (_neighbors _posX _posY _radius _targetX _targetY ))

(defmethod ISLH_msgs::robotInfo
  (:init
   (&key
    ((:neighbors __neighbors) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:posX __posX) 0.0)
    ((:posY __posY) 0.0)
    ((:radius __radius) 0.0)
    ((:targetX __targetX) 0.0)
    ((:targetY __targetY) 0.0)
    )
   (send-super :init)
   (setq _neighbors __neighbors)
   (setq _posX (float __posX))
   (setq _posY (float __posY))
   (setq _radius (float __radius))
   (setq _targetX (float __targetX))
   (setq _targetY (float __targetY))
   self)
  (:neighbors
   (&optional __neighbors)
   (if __neighbors (setq _neighbors __neighbors)) _neighbors)
  (:posX
   (&optional __posX)
   (if __posX (setq _posX __posX)) _posX)
  (:posY
   (&optional __posY)
   (if __posY (setq _posY __posY)) _posY)
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:targetX
   (&optional __targetX)
   (if __targetX (setq _targetX __targetX)) _targetX)
  (:targetY
   (&optional __targetY)
   (if __targetY (setq _targetY __targetY)) _targetY)
  (:serialization-length
   ()
   (+
    ;; string[] _neighbors
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _neighbors)) 4
    ;; float32 _posX
    4
    ;; float32 _posY
    4
    ;; float32 _radius
    4
    ;; float32 _targetX
    4
    ;; float32 _targetY
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string[] _neighbors
     (write-long (length _neighbors) s)
     (dolist (elem _neighbors)
       (write-long (length elem) s) (princ elem s)
       )
     ;; float32 _posX
       (sys::poke _posX (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _posY
       (sys::poke _posY (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _radius
       (sys::poke _radius (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _targetX
       (sys::poke _targetX (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _targetY
       (sys::poke _targetY (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string[] _neighbors
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _neighbors (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _neighbors i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; float32 _posX
     (setq _posX (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _posY
     (setq _posY (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _radius
     (setq _radius (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _targetX
     (setq _targetX (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _targetY
     (setq _targetY (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get ISLH_msgs::robotInfo :md5sum-) "efd1aeeed9405e7a52385c335c0151bb")
(setf (get ISLH_msgs::robotInfo :datatype-) "ISLH_msgs/robotInfo")
(setf (get ISLH_msgs::robotInfo :definition-)
      "#The robot's information that is relayed to the other robots

string[] neighbors #Neighbor robot names

float32 posX # The current position of the robot at x direction
float32 posY # The current position of the robot at y direction

float32 radius # The radius of the robot

float32 targetX # The current target position of the robot at x direction
float32 targetY # The current target position of the robot at y direction

")



(provide :ISLH_msgs/robotInfo "efd1aeeed9405e7a52385c335c0151bb")


