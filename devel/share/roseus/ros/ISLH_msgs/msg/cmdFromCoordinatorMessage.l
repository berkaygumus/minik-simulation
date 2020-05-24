;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::cmdFromCoordinatorMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'cmdFromCoordinatorMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::CMDFROMCOORDINATORMESSAGE")
  (make-package "ISLH_MSGS::CMDFROMCOORDINATORMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude cmdFromCoordinatorMessage.msg.html


(defclass ISLH_msgs::cmdFromCoordinatorMessage
  :super ros::object
  :slots (_sendingTime _messageTypeID _message ))

(defmethod ISLH_msgs::cmdFromCoordinatorMessage
  (:init
   (&key
    ((:sendingTime __sendingTime) 0)
    ((:messageTypeID __messageTypeID) 0)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _sendingTime (round __sendingTime))
   (setq _messageTypeID (round __messageTypeID))
   (setq _message (string __message))
   self)
  (:sendingTime
   (&optional __sendingTime)
   (if __sendingTime (setq _sendingTime __sendingTime)) _sendingTime)
  (:messageTypeID
   (&optional __messageTypeID)
   (if __messageTypeID (setq _messageTypeID __messageTypeID)) _messageTypeID)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; uint64 _sendingTime
    8
    ;; uint16 _messageTypeID
    2
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint64 _sendingTime
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _sendingTime (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _sendingTime) (= (length (_sendingTime . bv)) 2)) ;; bignum
              (write-long (ash (elt (_sendingTime . bv) 0) 0) s)
              (write-long (ash (elt (_sendingTime . bv) 1) -1) s))
             ((and (class _sendingTime) (= (length (_sendingTime . bv)) 1)) ;; big1
              (write-long (elt (_sendingTime . bv) 0) s)
              (write-long (if (>= _sendingTime 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _sendingTime s)(write-long (if (>= _sendingTime 0) 0 #xffffffff) s)))
     ;; uint16 _messageTypeID
       (write-word _messageTypeID s)
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint64 _sendingTime
     
#+(or :alpha :irix6 :x86_64)
      (setf _sendingTime (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _sendingTime (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; uint16 _messageTypeID
     (setq _messageTypeID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ISLH_msgs::cmdFromCoordinatorMessage :md5sum-) "6b00d2e721f211550b5ec2a337817798")
(setf (get ISLH_msgs::cmdFromCoordinatorMessage :datatype-) "ISLH_msgs/cmdFromCoordinatorMessage")
(setf (get ISLH_msgs::cmdFromCoordinatorMessage :definition-)
      "# The incoming command message from the coordinator

uint64 sendingTime #The sending time

uint16 messageTypeID

string message

")



(provide :ISLH_msgs/cmdFromCoordinatorMessage "6b00d2e721f211550b5ec2a337817798")


