;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::inMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'inMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::INMESSAGE")
  (make-package "ISLH_MSGS::INMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude inMessage.msg.html


(defclass ISLH_msgs::inMessage
  :super ros::object
  :slots (_robotid _messageid _message ))

(defmethod ISLH_msgs::inMessage
  (:init
   (&key
    ((:robotid __robotid) 0)
    ((:messageid __messageid) 0)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _robotid (round __robotid))
   (setq _messageid (round __messageid))
   (setq _message (string __message))
   self)
  (:robotid
   (&optional __robotid)
   (if __robotid (setq _robotid __robotid)) _robotid)
  (:messageid
   (&optional __messageid)
   (if __messageid (setq _messageid __messageid)) _messageid)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; uint16 _robotid
    2
    ;; uint16 _messageid
    2
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _robotid
       (write-word _robotid s)
     ;; uint16 _messageid
       (write-word _messageid s)
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _robotid
     (setq _robotid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _messageid
     (setq _messageid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ISLH_msgs::inMessage :md5sum-) "29816f7dd48299059674f73ccfcba3d5")
(setf (get ISLH_msgs::inMessage :datatype-) "ISLH_msgs/inMessage")
(setf (get ISLH_msgs::inMessage :definition-)
      "# Incoming messages

uint16 robotid #sender id

uint16 messageid

string message #message

")



(provide :ISLH_msgs/inMessage "29816f7dd48299059674f73ccfcba3d5")


