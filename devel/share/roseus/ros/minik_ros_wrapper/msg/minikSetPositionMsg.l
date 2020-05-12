;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikSetPositionMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikSetPositionMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKSETPOSITIONMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKSETPOSITIONMSG"))

(in-package "ROS")
;;//! \htmlinclude minikSetPositionMsg.msg.html


(defclass minik_ros_wrapper::minikSetPositionMsg
  :super ros::object
  :slots (_motorID _position ))

(defmethod minik_ros_wrapper::minikSetPositionMsg
  (:init
   (&key
    ((:motorID __motorID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:position __position) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _motorID __motorID)
   (setq _position __position)
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
    ;; int32[] _motorID
    (* 4    (length _motorID)) 4
    ;; int32[] _position
    (* 4    (length _position)) 4
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
     ;; int32[] _position
     (write-long (length _position) s)
     (dotimes (i (length _position))
       (write-long (elt _position i) s)
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
   ;; int32[] _position
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _position (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _position i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikSetPositionMsg :md5sum-) "121261aaf42c6b46f74e88a84eea6cde")
(setf (get minik_ros_wrapper::minikSetPositionMsg :datatype-) "minik_ros_wrapper/minikSetPositionMsg")
(setf (get minik_ros_wrapper::minikSetPositionMsg :definition-)
      "# Minik Set Position Command

int32[] motorID
int32[] position

")



(provide :minik_ros_wrapper/minikSetPositionMsg "121261aaf42c6b46f74e88a84eea6cde")


