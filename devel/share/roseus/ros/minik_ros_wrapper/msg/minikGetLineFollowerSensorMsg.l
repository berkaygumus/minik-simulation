;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikGetLineFollowerSensorMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikGetLineFollowerSensorMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKGETLINEFOLLOWERSENSORMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKGETLINEFOLLOWERSENSORMSG"))

(in-package "ROS")
;;//! \htmlinclude minikGetLineFollowerSensorMsg.msg.html


(defclass minik_ros_wrapper::minikGetLineFollowerSensorMsg
  :super ros::object
  :slots (_rightSensor _middleSensor _leftSensor ))

(defmethod minik_ros_wrapper::minikGetLineFollowerSensorMsg
  (:init
   (&key
    ((:rightSensor __rightSensor) 0)
    ((:middleSensor __middleSensor) 0)
    ((:leftSensor __leftSensor) 0)
    )
   (send-super :init)
   (setq _rightSensor (round __rightSensor))
   (setq _middleSensor (round __middleSensor))
   (setq _leftSensor (round __leftSensor))
   self)
  (:rightSensor
   (&optional __rightSensor)
   (if __rightSensor (setq _rightSensor __rightSensor)) _rightSensor)
  (:middleSensor
   (&optional __middleSensor)
   (if __middleSensor (setq _middleSensor __middleSensor)) _middleSensor)
  (:leftSensor
   (&optional __leftSensor)
   (if __leftSensor (setq _leftSensor __leftSensor)) _leftSensor)
  (:serialization-length
   ()
   (+
    ;; char _rightSensor
    1
    ;; char _middleSensor
    1
    ;; char _leftSensor
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; char _rightSensor
       (write-byte _rightSensor s)
     ;; char _middleSensor
       (write-byte _middleSensor s)
     ;; char _leftSensor
       (write-byte _leftSensor s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; char _rightSensor
     (setq _rightSensor (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; char _middleSensor
     (setq _middleSensor (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; char _leftSensor
     (setq _leftSensor (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikGetLineFollowerSensorMsg :md5sum-) "117f4dd679610c07fd2b537377a09014")
(setf (get minik_ros_wrapper::minikGetLineFollowerSensorMsg :datatype-) "minik_ros_wrapper/minikGetLineFollowerSensorMsg")
(setf (get minik_ros_wrapper::minikGetLineFollowerSensorMsg :definition-)
      "# Minik Get Line Follower Message

char rightSensor
char middleSensor
char leftSensor

")



(provide :minik_ros_wrapper/minikGetLineFollowerSensorMsg "117f4dd679610c07fd2b537377a09014")


