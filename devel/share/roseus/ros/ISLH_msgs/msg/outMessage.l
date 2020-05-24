;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::outMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'outMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::OUTMESSAGE")
  (make-package "ISLH_MSGS::OUTMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude outMessage.msg.html


(defclass ISLH_msgs::outMessage
  :super ros::object
  :slots (_robotid _messageTypeID _messageIndx _message ))

(defmethod ISLH_msgs::outMessage
  (:init
   (&key
    ((:robotid __robotid) (make-array 0 :initial-element 0 :element-type :integer))
    ((:messageTypeID __messageTypeID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:messageIndx __messageIndx) (make-array 0 :initial-element 0 :element-type :integer))
    ((:message __message) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _robotid __robotid)
   (setq _messageTypeID __messageTypeID)
   (setq _messageIndx __messageIndx)
   (setq _message __message)
   self)
  (:robotid
   (&optional __robotid)
   (if __robotid (setq _robotid __robotid)) _robotid)
  (:messageTypeID
   (&optional __messageTypeID)
   (if __messageTypeID (setq _messageTypeID __messageTypeID)) _messageTypeID)
  (:messageIndx
   (&optional __messageIndx)
   (if __messageIndx (setq _messageIndx __messageIndx)) _messageIndx)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; uint16[] _robotid
    (* 2    (length _robotid)) 4
    ;; uint16[] _messageTypeID
    (* 2    (length _messageTypeID)) 4
    ;; uint16[] _messageIndx
    (* 2    (length _messageIndx)) 4
    ;; string[] _message
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _message)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16[] _robotid
     (write-long (length _robotid) s)
     (dotimes (i (length _robotid))
       (write-word (elt _robotid i) s)
       )
     ;; uint16[] _messageTypeID
     (write-long (length _messageTypeID) s)
     (dotimes (i (length _messageTypeID))
       (write-word (elt _messageTypeID i) s)
       )
     ;; uint16[] _messageIndx
     (write-long (length _messageIndx) s)
     (dotimes (i (length _messageIndx))
       (write-word (elt _messageIndx i) s)
       )
     ;; string[] _message
     (write-long (length _message) s)
     (dolist (elem _message)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16[] _robotid
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _robotid (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _robotid i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; uint16[] _messageTypeID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _messageTypeID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _messageTypeID i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; uint16[] _messageIndx
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _messageIndx (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _messageIndx i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; string[] _message
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _message (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _message i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(setf (get ISLH_msgs::outMessage :md5sum-) "8e9310b478059d7c506189771b569d0d")
(setf (get ISLH_msgs::outMessage :datatype-) "ISLH_msgs/outMessage")
(setf (get ISLH_msgs::outMessage :definition-)
      "# outgoing  messages

uint16[] robotid #receiver id

uint16[] messageTypeID

uint16[] messageIndx # which message is sent to which robot

string[] message #message



")



(provide :ISLH_msgs/outMessage "8e9310b478059d7c506189771b569d0d")


