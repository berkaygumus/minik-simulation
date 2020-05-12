;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikSetConfigMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikSetConfigMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKSETCONFIGMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKSETCONFIGMSG"))

(in-package "ROS")
;;//! \htmlinclude minikSetConfigMsg.msg.html


(defclass minik_ros_wrapper::minikSetConfigMsg
  :super ros::object
  :slots (_isSpeedSendON _isPositionSendON _frequency ))

(defmethod minik_ros_wrapper::minikSetConfigMsg
  (:init
   (&key
    ((:isSpeedSendON __isSpeedSendON) nil)
    ((:isPositionSendON __isPositionSendON) nil)
    ((:frequency __frequency) 0)
    )
   (send-super :init)
   (setq _isSpeedSendON __isSpeedSendON)
   (setq _isPositionSendON __isPositionSendON)
   (setq _frequency (round __frequency))
   self)
  (:isSpeedSendON
   (&optional __isSpeedSendON)
   (if __isSpeedSendON (setq _isSpeedSendON __isSpeedSendON)) _isSpeedSendON)
  (:isPositionSendON
   (&optional __isPositionSendON)
   (if __isPositionSendON (setq _isPositionSendON __isPositionSendON)) _isPositionSendON)
  (:frequency
   (&optional __frequency)
   (if __frequency (setq _frequency __frequency)) _frequency)
  (:serialization-length
   ()
   (+
    ;; bool _isSpeedSendON
    1
    ;; bool _isPositionSendON
    1
    ;; char _frequency
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _isSpeedSendON
       (if _isSpeedSendON (write-byte -1 s) (write-byte 0 s))
     ;; bool _isPositionSendON
       (if _isPositionSendON (write-byte -1 s) (write-byte 0 s))
     ;; char _frequency
       (write-byte _frequency s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _isSpeedSendON
     (setq _isSpeedSendON (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _isPositionSendON
     (setq _isPositionSendON (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; char _frequency
     (setq _frequency (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikSetConfigMsg :md5sum-) "e4dff864fd41bf1461aaa087ae928002")
(setf (get minik_ros_wrapper::minikSetConfigMsg :datatype-) "minik_ros_wrapper/minikSetConfigMsg")
(setf (get minik_ros_wrapper::minikSetConfigMsg :definition-)
      "# Minik Set Config Command

bool isSpeedSendON
bool isPositionSendON
char frequency

")



(provide :minik_ros_wrapper/minikSetConfigMsg "e4dff864fd41bf1461aaa087ae928002")


