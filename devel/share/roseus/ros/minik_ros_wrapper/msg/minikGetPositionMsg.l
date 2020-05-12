;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikGetPositionMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikGetPositionMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKGETPOSITIONMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKGETPOSITIONMSG"))

(in-package "ROS")
;;//! \htmlinclude minikGetPositionMsg.msg.html


(defclass minik_ros_wrapper::minikGetPositionMsg
  :super ros::object
  :slots (_motorID _position ))

(defmethod minik_ros_wrapper::minikGetPositionMsg
  (:init
   (&key
    ((:motorID __motorID) 0)
    ((:position __position) 0)
    )
   (send-super :init)
   (setq _motorID (round __motorID))
   (setq _position (round __position))
   self)
  (:motorID
   (&optional __motorID)
   (if __motorID (setq _motorID __motorID)) _motorID)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:serialization-length
   ()
   (+
    ;; int32 _motorID
    4
    ;; int32 _position
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _motorID
       (write-long _motorID s)
     ;; int32 _position
       (write-long _position s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _motorID
     (setq _motorID (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _position
     (setq _position (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikGetPositionMsg :md5sum-) "9484186d0d818e0301bf0d58107b9a65")
(setf (get minik_ros_wrapper::minikGetPositionMsg :datatype-) "minik_ros_wrapper/minikGetPositionMsg")
(setf (get minik_ros_wrapper::minikGetPositionMsg :definition-)
      "# Minik Get Position Message

int32 motorID
int32 position

")



(provide :minik_ros_wrapper/minikGetPositionMsg "9484186d0d818e0301bf0d58107b9a65")


