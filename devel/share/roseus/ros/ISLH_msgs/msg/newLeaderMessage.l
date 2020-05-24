;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::newLeaderMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'newLeaderMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::NEWLEADERMESSAGE")
  (make-package "ISLH_MSGS::NEWLEADERMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude newLeaderMessage.msg.html


(defclass ISLH_msgs::newLeaderMessage
  :super ros::object
  :slots (_sendingTime _infoTypeID _infoMessage ))

(defmethod ISLH_msgs::newLeaderMessage
  (:init
   (&key
    ((:sendingTime __sendingTime) 0)
    ((:infoTypeID __infoTypeID) 0)
    ((:infoMessage __infoMessage) "")
    )
   (send-super :init)
   (setq _sendingTime (round __sendingTime))
   (setq _infoTypeID (round __infoTypeID))
   (setq _infoMessage (string __infoMessage))
   self)
  (:sendingTime
   (&optional __sendingTime)
   (if __sendingTime (setq _sendingTime __sendingTime)) _sendingTime)
  (:infoTypeID
   (&optional __infoTypeID)
   (if __infoTypeID (setq _infoTypeID __infoTypeID)) _infoTypeID)
  (:infoMessage
   (&optional __infoMessage)
   (if __infoMessage (setq _infoMessage __infoMessage)) _infoMessage)
  (:serialization-length
   ()
   (+
    ;; uint64 _sendingTime
    8
    ;; uint16 _infoTypeID
    2
    ;; string _infoMessage
    4 (length _infoMessage)
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
     ;; uint16 _infoTypeID
       (write-word _infoTypeID s)
     ;; string _infoMessage
       (write-long (length _infoMessage) s) (princ _infoMessage s)
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
   ;; uint16 _infoTypeID
     (setq _infoTypeID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _infoMessage
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _infoMessage (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ISLH_msgs::newLeaderMessage :md5sum-) "e3baee834452566b366f59c79fcdfa75")
(setf (get ISLH_msgs::newLeaderMessage :datatype-) "ISLH_msgs/newLeaderMessage")
(setf (get ISLH_msgs::newLeaderMessage :definition-)
      "# The incoming info message from old coalition leader to new coalition leader

uint64 sendingTime #The sending time

uint16 infoTypeID

string infoMessage

")



(provide :ISLH_msgs/newLeaderMessage "e3baee834452566b366f59c79fcdfa75")


