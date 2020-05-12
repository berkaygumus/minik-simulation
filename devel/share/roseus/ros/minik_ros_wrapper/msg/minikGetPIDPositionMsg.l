;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikGetPIDPositionMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikGetPIDPositionMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKGETPIDPOSITIONMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKGETPIDPOSITIONMSG"))

(in-package "ROS")
;;//! \htmlinclude minikGetPIDPositionMsg.msg.html


(defclass minik_ros_wrapper::minikGetPIDPositionMsg
  :super ros::object
  :slots (_motorID _P _I _D ))

(defmethod minik_ros_wrapper::minikGetPIDPositionMsg
  (:init
   (&key
    ((:motorID __motorID) 0)
    ((:P __P) 0)
    ((:I __I) 0)
    ((:D __D) 0)
    )
   (send-super :init)
   (setq _motorID (round __motorID))
   (setq _P (round __P))
   (setq _I (round __I))
   (setq _D (round __D))
   self)
  (:motorID
   (&optional __motorID)
   (if __motorID (setq _motorID __motorID)) _motorID)
  (:P
   (&optional __P)
   (if __P (setq _P __P)) _P)
  (:I
   (&optional __I)
   (if __I (setq _I __I)) _I)
  (:D
   (&optional __D)
   (if __D (setq _D __D)) _D)
  (:serialization-length
   ()
   (+
    ;; int32 _motorID
    4
    ;; char _P
    1
    ;; char _I
    1
    ;; char _D
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _motorID
       (write-long _motorID s)
     ;; char _P
       (write-byte _P s)
     ;; char _I
       (write-byte _I s)
     ;; char _D
       (write-byte _D s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _motorID
     (setq _motorID (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; char _P
     (setq _P (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; char _I
     (setq _I (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; char _D
     (setq _D (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikGetPIDPositionMsg :md5sum-) "e7ffde16b01cf7c9fd96dfa04f0bfdc6")
(setf (get minik_ros_wrapper::minikGetPIDPositionMsg :datatype-) "minik_ros_wrapper/minikGetPIDPositionMsg")
(setf (get minik_ros_wrapper::minikGetPIDPositionMsg :definition-)
      "# Minik Get Position PID Message

int32 motorID
char P
char I
char D

")



(provide :minik_ros_wrapper/minikGetPIDPositionMsg "e7ffde16b01cf7c9fd96dfa04f0bfdc6")


