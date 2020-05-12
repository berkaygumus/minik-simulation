;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikSetVelocityMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikSetVelocityMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKSETVELOCITYMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKSETVELOCITYMSG"))

(in-package "ROS")
;;//! \htmlinclude minikSetVelocityMsg.msg.html


(defclass minik_ros_wrapper::minikSetVelocityMsg
  :super ros::object
  :slots (_motorID _velocity ))

(defmethod minik_ros_wrapper::minikSetVelocityMsg
  (:init
   (&key
    ((:motorID __motorID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:velocity __velocity) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _motorID __motorID)
   (setq _velocity __velocity)
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
    ;; int32[] _motorID
    (* 4    (length _motorID)) 4
    ;; int32[] _velocity
    (* 4    (length _velocity)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[] _motorID
     (write-long (length _motorID) s)
     (dotimes (i (length _motorID))
       (write-long (elt _motorID i) s)
       )
     ;; int32[] _velocity
     (write-long (length _velocity) s)
     (dotimes (i (length _velocity))
       (write-long (elt _velocity i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[] _motorID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _motorID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _motorID i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32[] _velocity
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _velocity (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _velocity i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikSetVelocityMsg :md5sum-) "c8adc9ee4fc03605a59580c725817899")
(setf (get minik_ros_wrapper::minikSetVelocityMsg :datatype-) "minik_ros_wrapper/minikSetVelocityMsg")
(setf (get minik_ros_wrapper::minikSetVelocityMsg :definition-)
      "# Minik Set Velocity Command

int32[] motorID
int32[] velocity

")



(provide :minik_ros_wrapper/minikSetVelocityMsg "c8adc9ee4fc03605a59580c725817899")


