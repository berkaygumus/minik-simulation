;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::cmd2RobotsMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'cmd2RobotsMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::CMD2ROBOTSMESSAGE")
  (make-package "ISLH_MSGS::CMD2ROBOTSMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude cmd2RobotsMessage.msg.html


(defclass ISLH_msgs::cmd2RobotsMessage
  :super ros::object
  :slots (_sendingTime _cmdType _message ))

(defmethod ISLH_msgs::cmd2RobotsMessage
  (:init
   (&key
    ((:sendingTime __sendingTime) 0)
    ((:cmdType __cmdType) 0)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _sendingTime (round __sendingTime))
   (setq _cmdType (round __cmdType))
   (setq _message (string __message))
   self)
  (:sendingTime
   (&optional __sendingTime)
   (if __sendingTime (setq _sendingTime __sendingTime)) _sendingTime)
  (:cmdType
   (&optional __cmdType)
   (if __cmdType (setq _cmdType __cmdType)) _cmdType)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; uint64 _sendingTime
    8
    ;; uint16 _cmdType
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
     ;; uint16 _cmdType
       (write-word _cmdType s)
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
   ;; uint16 _cmdType
     (setq _cmdType (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ISLH_msgs::cmd2RobotsMessage :md5sum-) "651ffc22f68ec2e97e413b004cae948b")
(setf (get ISLH_msgs::cmd2RobotsMessage :datatype-) "ISLH_msgs/cmd2RobotsMessage")
(setf (get ISLH_msgs::cmd2RobotsMessage :definition-)
      "# The incoming command message from coalition leader

uint64 sendingTime #The sending time

uint16 cmdType

string message

")



(provide :ISLH_msgs/cmd2RobotsMessage "651ffc22f68ec2e97e413b004cae948b")


