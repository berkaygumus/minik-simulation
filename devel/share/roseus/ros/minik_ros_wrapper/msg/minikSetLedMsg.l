;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikSetLedMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikSetLedMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKSETLEDMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKSETLEDMSG"))

(in-package "ROS")
;;//! \htmlinclude minikSetLedMsg.msg.html


(defclass minik_ros_wrapper::minikSetLedMsg
  :super ros::object
  :slots (_isLed1ON _isLed2ON ))

(defmethod minik_ros_wrapper::minikSetLedMsg
  (:init
   (&key
    ((:isLed1ON __isLed1ON) nil)
    ((:isLed2ON __isLed2ON) nil)
    )
   (send-super :init)
   (setq _isLed1ON __isLed1ON)
   (setq _isLed2ON __isLed2ON)
   self)
  (:isLed1ON
   (&optional __isLed1ON)
   (if __isLed1ON (setq _isLed1ON __isLed1ON)) _isLed1ON)
  (:isLed2ON
   (&optional __isLed2ON)
   (if __isLed2ON (setq _isLed2ON __isLed2ON)) _isLed2ON)
  (:serialization-length
   ()
   (+
    ;; bool _isLed1ON
    1
    ;; bool _isLed2ON
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _isLed1ON
       (if _isLed1ON (write-byte -1 s) (write-byte 0 s))
     ;; bool _isLed2ON
       (if _isLed2ON (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _isLed1ON
     (setq _isLed1ON (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _isLed2ON
     (setq _isLed2ON (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikSetLedMsg :md5sum-) "416c0731914825378ec0a0ce9d25cbb7")
(setf (get minik_ros_wrapper::minikSetLedMsg :datatype-) "minik_ros_wrapper/minikSetLedMsg")
(setf (get minik_ros_wrapper::minikSetLedMsg :definition-)
      "# Minik Set Led Command

bool isLed1ON
bool isLed2ON

")



(provide :minik_ros_wrapper/minikSetLedMsg "416c0731914825378ec0a0ce9d25cbb7")


