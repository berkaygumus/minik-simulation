;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikGetVelocityMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikGetVelocityMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKGETVELOCITYMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKGETVELOCITYMSG"))

(in-package "ROS")
;;//! \htmlinclude minikGetVelocityMsg.msg.html


(defclass minik_ros_wrapper::minikGetVelocityMsg
  :super ros::object
  :slots (_motorID _velocity ))

(defmethod minik_ros_wrapper::minikGetVelocityMsg
  (:init
   (&key
    ((:motorID __motorID) 0)
    ((:velocity __velocity) 0)
    )
   (send-super :init)
   (setq _motorID (round __motorID))
   (setq _velocity (round __velocity))
   self)
  (:motorID
   (&optional __motorID)
   (if __motorID (setq _motorID __motorID)) _motorID)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:serialization-length
   ()
   (+
    ;; int32 _motorID
    4
    ;; int16 _velocity
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _motorID
       (write-long _motorID s)
     ;; int16 _velocity
       (write-word _velocity s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _motorID
     (setq _motorID (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _velocity
     (setq _velocity (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikGetVelocityMsg :md5sum-) "a94dbef25ebdc880900454ec307048c1")
(setf (get minik_ros_wrapper::minikGetVelocityMsg :datatype-) "minik_ros_wrapper/minikGetVelocityMsg")
(setf (get minik_ros_wrapper::minikGetVelocityMsg :definition-)
      "# Minik Get Velocity Message

int32 motorID
int16 velocity

")



(provide :minik_ros_wrapper/minikGetVelocityMsg "a94dbef25ebdc880900454ec307048c1")


