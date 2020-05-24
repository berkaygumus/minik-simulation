;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::cmd2LeadersMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'cmd2LeadersMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::CMD2LEADERSMESSAGE")
  (make-package "ISLH_MSGS::CMD2LEADERSMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude cmd2LeadersMessage.msg.html


(defclass ISLH_msgs::cmd2LeadersMessage
  :super ros::object
  :slots (_leaderRobotID _sendingTime _messageTypeID _message ))

(defmethod ISLH_msgs::cmd2LeadersMessage
  (:init
   (&key
    ((:leaderRobotID __leaderRobotID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:sendingTime __sendingTime) 0)
    ((:messageTypeID __messageTypeID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:message __message) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _leaderRobotID __leaderRobotID)
   (setq _sendingTime (round __sendingTime))
   (setq _messageTypeID __messageTypeID)
   (setq _message __message)
   self)
  (:leaderRobotID
   (&optional __leaderRobotID)
   (if __leaderRobotID (setq _leaderRobotID __leaderRobotID)) _leaderRobotID)
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
    ;; uint16[] _leaderRobotID
    (* 2    (length _leaderRobotID)) 4
    ;; uint64 _sendingTime
    8
    ;; uint16[] _messageTypeID
    (* 2    (length _messageTypeID)) 4
    ;; string[] _message
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _message)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16[] _leaderRobotID
     (write-long (length _leaderRobotID) s)
     (dotimes (i (length _leaderRobotID))
       (write-word (elt _leaderRobotID i) s)
       )
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
     ;; uint16[] _messageTypeID
     (write-long (length _messageTypeID) s)
     (dotimes (i (length _messageTypeID))
       (write-word (elt _messageTypeID i) s)
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
   ;; uint16[] _leaderRobotID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _leaderRobotID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _leaderRobotID i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
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
   ;; uint16[] _messageTypeID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _messageTypeID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _messageTypeID i) (sys::peek buf ptr- :short)) (incf ptr- 2)
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

(setf (get ISLH_msgs::cmd2LeadersMessage :md5sum-) "dea84c50c103ccf3d723b1874cc1b015")
(setf (get ISLH_msgs::cmd2LeadersMessage :datatype-) "ISLH_msgs/cmd2LeadersMessage")
(setf (get ISLH_msgs::cmd2LeadersMessage :definition-)
      "# The task's information from coalition leader

uint16[] leaderRobotID #robot id to which the message will be sent 

uint64 sendingTime #The sending time

uint16[] messageTypeID

string[] message

")



(provide :ISLH_msgs/cmd2LeadersMessage "dea84c50c103ccf3d723b1874cc1b015")


