;; Auto-generated. Do not edit!


(when (boundp 'minik_ros_wrapper::minikSetPIDPositionMsg)
  (if (not (find-package "MINIK_ROS_WRAPPER"))
    (make-package "MINIK_ROS_WRAPPER"))
  (shadow 'minikSetPIDPositionMsg (find-package "MINIK_ROS_WRAPPER")))
(unless (find-package "MINIK_ROS_WRAPPER::MINIKSETPIDPOSITIONMSG")
  (make-package "MINIK_ROS_WRAPPER::MINIKSETPIDPOSITIONMSG"))

(in-package "ROS")
;;//! \htmlinclude minikSetPIDPositionMsg.msg.html


(defclass minik_ros_wrapper::minikSetPIDPositionMsg
  :super ros::object
  :slots (_motorID _P _I _D ))

(defmethod minik_ros_wrapper::minikSetPIDPositionMsg
  (:init
   (&key
    ((:motorID __motorID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:P __P) (make-array 0 :initial-element 0 :element-type :integer))
    ((:I __I) (make-array 0 :initial-element 0 :element-type :integer))
    ((:D __D) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _motorID __motorID)
   (setq _P __P)
   (setq _I __I)
   (setq _D __D)
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
    ;; int32[] _motorID
    (* 4    (length _motorID)) 4
    ;; char[] _P
    (* 1    (length _P)) 4
    ;; char[] _I
    (* 1    (length _I)) 4
    ;; char[] _D
    (* 1    (length _D)) 4
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
     ;; char[] _P
     (write-long (length _P) s)
     (dotimes (i (length _P))
       (write-byte (elt _P i) s)
       )
     ;; char[] _I
     (write-long (length _I) s)
     (dotimes (i (length _I))
       (write-byte (elt _I i) s)
       )
     ;; char[] _D
     (write-long (length _D) s)
     (dotimes (i (length _D))
       (write-byte (elt _D i) s)
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
   ;; char[] _P
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _P (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _P i) (sys::peek buf ptr- :char)) (incf ptr- 1)
     ))
   ;; char[] _I
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _I (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _I i) (sys::peek buf ptr- :char)) (incf ptr- 1)
     ))
   ;; char[] _D
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _D (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _D i) (sys::peek buf ptr- :char)) (incf ptr- 1)
     ))
   ;;
   self)
  )

(setf (get minik_ros_wrapper::minikSetPIDPositionMsg :md5sum-) "d3c57d08264ba7635ea33c90d92b0139")
(setf (get minik_ros_wrapper::minikSetPIDPositionMsg :datatype-) "minik_ros_wrapper/minikSetPIDPositionMsg")
(setf (get minik_ros_wrapper::minikSetPIDPositionMsg :definition-)
      "# Minik Set Position PID Message

int32[] motorID
char[] P
char[] I
char[] D

")



(provide :minik_ros_wrapper/minikSetPIDPositionMsg "d3c57d08264ba7635ea33c90d92b0139")


