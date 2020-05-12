;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikGetButtonMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikGetButtonMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKGETBUTTONMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKGETBUTTONMSG"))

(in-package "ROS")
;;//! \htmlinclude minikGetButtonMsg.msg.html


(defclass minik_ros_wrapper::minikGetButtonMsg
  :super ros::object
  :slots (_isButton1Pressed _isButton2Pressed _isButton3Pressed ))

(defmethod minik_ros_wrapper::minikGetButtonMsg
  (:init
   (&key
    ((:isButton1Pressed __isButton1Pressed) nil)
    ((:isButton2Pressed __isButton2Pressed) nil)
    ((:isButton3Pressed __isButton3Pressed) nil)
    )
   (send-super :init)
   (setq _isButton1Pressed __isButton1Pressed)
   (setq _isButton2Pressed __isButton2Pressed)
   (setq _isButton3Pressed __isButton3Pressed)
   self)
  (:isButton1Pressed
   (&optional __isButton1Pressed)
   (if __isButton1Pressed (setq _isButton1Pressed __isButton1Pressed)) _isButton1Pressed)
  (:isButton2Pressed
   (&optional __isButton2Pressed)
   (if __isButton2Pressed (setq _isButton2Pressed __isButton2Pressed)) _isButton2Pressed)
  (:isButton3Pressed
   (&optional __isButton3Pressed)
   (if __isButton3Pressed (setq _isButton3Pressed __isButton3Pressed)) _isButton3Pressed)
  (:serialization-length
   ()
   (+
    ;; bool _isButton1Pressed
    1
    ;; bool _isButton2Pressed
    1
    ;; bool _isButton3Pressed
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _isButton1Pressed
       (if _isButton1Pressed (write-byte -1 s) (write-byte 0 s))
     ;; bool _isButton2Pressed
       (if _isButton2Pressed (write-byte -1 s) (write-byte 0 s))
     ;; bool _isButton3Pressed
       (if _isButton3Pressed (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _isButton1Pressed
     (setq _isButton1Pressed (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _isButton2Pressed
     (setq _isButton2Pressed (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _isButton3Pressed
     (setq _isButton3Pressed (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikGetButtonMsg :md5sum-) "3853358d8e2e329f368156066a21f0b2")
(setf (get minik_ros_wrapper::minikGetButtonMsg :datatype-) "minik_ros_wrapper/minikGetButtonMsg")
(setf (get minik_ros_wrapper::minikGetButtonMsg :definition-)
      "# Minik Get Button Message

bool isButton1Pressed
bool isButton2Pressed
bool isButton3Pressed

")



(provide :minik_ros_wrapper/minikGetButtonMsg "3853358d8e2e329f368156066a21f0b2")


