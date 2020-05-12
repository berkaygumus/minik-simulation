;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikGetDistSensorMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikGetDistSensorMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKGETDISTSENSORMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKGETDISTSENSORMSG"))

(in-package "ROS")
;;//! \htmlinclude minikGetDistSensorMsg.msg.html


(defclass minik_ros_wrapper::minikGetDistSensorMsg
  :super ros::object
  :slots (_rightSensor _leftSensor ))

(defmethod minik_ros_wrapper::minikGetDistSensorMsg
  (:init
   (&key
    ((:rightSensor __rightSensor) 0)
    ((:leftSensor __leftSensor) 0)
    )
   (send-super :init)
   (setq _rightSensor (round __rightSensor))
   (setq _leftSensor (round __leftSensor))
   self)
  (:rightSensor
   (&optional __rightSensor)
   (if __rightSensor (setq _rightSensor __rightSensor)) _rightSensor)
  (:leftSensor
   (&optional __leftSensor)
   (if __leftSensor (setq _leftSensor __leftSensor)) _leftSensor)
  (:serialization-length
   ()
   (+
    ;; int16 _rightSensor
    2
    ;; int16 _leftSensor
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _rightSensor
       (write-word _rightSensor s)
     ;; int16 _leftSensor
       (write-word _leftSensor s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _rightSensor
     (setq _rightSensor (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _leftSensor
     (setq _leftSensor (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikGetDistSensorMsg :md5sum-) "ecaa6ae02155044a20eae821d6e0498f")
(setf (get minik_ros_wrapper::minikGetDistSensorMsg :datatype-) "minik_ros_wrapper/minikGetDistSensorMsg")
(setf (get minik_ros_wrapper::minikGetDistSensorMsg :definition-)
      "# Minik Get Sharp Distance Sensor Message

int16 rightSensor
int16 leftSensor

")



(provide :minik_ros_wrapper/minikGetDistSensorMsg "ecaa6ae02155044a20eae821d6e0498f")


