;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::cmdFromLeaderMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'cmdFromLeaderMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::CMDFROMLEADERMESSAGE")
  (make-package "ISLH_MSGS::CMDFROMLEADERMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude cmdFromLeaderMessage.msg.html


(defclass ISLH_msgs::cmdFromLeaderMessage
  :super ros::object
  :slots (_sendingTime _cmdTypeID _cmdMessage ))

(defmethod ISLH_msgs::cmdFromLeaderMessage
  (:init
   (&key
    ((:sendingTime __sendingTime) 0)
    ((:cmdTypeID __cmdTypeID) 0)
    ((:cmdMessage __cmdMessage) "")
    )
   (send-super :init)
   (setq _sendingTime (round __sendingTime))
   (setq _cmdTypeID (round __cmdTypeID))
   (setq _cmdMessage (string __cmdMessage))
   self)
  (:sendingTime
   (&optional __sendingTime)
   (if __sendingTime (setq _sendingTime __sendingTime)) _sendingTime)
  (:cmdTypeID
   (&optional __cmdTypeID)
   (if __cmdTypeID (setq _cmdTypeID __cmdTypeID)) _cmdTypeID)
  (:cmdMessage
   (&optional __cmdMessage)
   (if __cmdMessage (setq _cmdMessage __cmdMessage)) _cmdMessage)
  (:serialization-length
   ()
   (+
    ;; uint64 _sendingTime
    8
    ;; uint16 _cmdTypeID
    2
    ;; string _cmdMessage
    4 (length _cmdMessage)
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
     ;; uint16 _cmdTypeID
       (write-word _cmdTypeID s)
     ;; string _cmdMessage
       (write-long (length _cmdMessage) s) (princ _cmdMessage s)
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
   ;; uint16 _cmdTypeID
     (setq _cmdTypeID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _cmdMessage
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _cmdMessage (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ISLH_msgs::cmdFromLeaderMessage :md5sum-) "49939506eb789fd4a67d4e6e601d80df")
(setf (get ISLH_msgs::cmdFromLeaderMessage :datatype-) "ISLH_msgs/cmdFromLeaderMessage")
(setf (get ISLH_msgs::cmdFromLeaderMessage :definition-)
      "# The incoming command message from coalition leader

uint64 sendingTime #The sending time

uint16 cmdTypeID

string cmdMessage

")



(provide :ISLH_msgs/cmdFromLeaderMessage "49939506eb789fd4a67d4e6e601d80df")


