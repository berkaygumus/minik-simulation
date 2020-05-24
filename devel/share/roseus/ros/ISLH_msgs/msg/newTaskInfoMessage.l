;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::newTaskInfoMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'newTaskInfoMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::NEWTASKINFOMESSAGE")
  (make-package "ISLH_MSGS::NEWTASKINFOMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude newTaskInfoMessage.msg.html


(defclass ISLH_msgs::newTaskInfoMessage
  :super ros::object
  :slots (_taskUUID _timeStamp _handlingDuration _timeOutDuration _requiredResources ))

(defmethod ISLH_msgs::newTaskInfoMessage
  (:init
   (&key
    ((:taskUUID __taskUUID) "")
    ((:timeStamp __timeStamp) 0)
    ((:handlingDuration __handlingDuration) 0)
    ((:timeOutDuration __timeOutDuration) 0)
    ((:requiredResources __requiredResources) "")
    )
   (send-super :init)
   (setq _taskUUID (string __taskUUID))
   (setq _timeStamp (round __timeStamp))
   (setq _handlingDuration (round __handlingDuration))
   (setq _timeOutDuration (round __timeOutDuration))
   (setq _requiredResources (string __requiredResources))
   self)
  (:taskUUID
   (&optional __taskUUID)
   (if __taskUUID (setq _taskUUID __taskUUID)) _taskUUID)
  (:timeStamp
   (&optional __timeStamp)
   (if __timeStamp (setq _timeStamp __timeStamp)) _timeStamp)
  (:handlingDuration
   (&optional __handlingDuration)
   (if __handlingDuration (setq _handlingDuration __handlingDuration)) _handlingDuration)
  (:timeOutDuration
   (&optional __timeOutDuration)
   (if __timeOutDuration (setq _timeOutDuration __timeOutDuration)) _timeOutDuration)
  (:requiredResources
   (&optional __requiredResources)
   (if __requiredResources (setq _requiredResources __requiredResources)) _requiredResources)
  (:serialization-length
   ()
   (+
    ;; string _taskUUID
    4 (length _taskUUID)
    ;; uint64 _timeStamp
    8
    ;; uint16 _handlingDuration
    2
    ;; uint16 _timeOutDuration
    2
    ;; string _requiredResources
    4 (length _requiredResources)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _taskUUID
       (write-long (length _taskUUID) s) (princ _taskUUID s)
     ;; uint64 _timeStamp
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _timeStamp (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _timeStamp) (= (length (_timeStamp . bv)) 2)) ;; bignum
              (write-long (ash (elt (_timeStamp . bv) 0) 0) s)
              (write-long (ash (elt (_timeStamp . bv) 1) -1) s))
             ((and (class _timeStamp) (= (length (_timeStamp . bv)) 1)) ;; big1
              (write-long (elt (_timeStamp . bv) 0) s)
              (write-long (if (>= _timeStamp 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _timeStamp s)(write-long (if (>= _timeStamp 0) 0 #xffffffff) s)))
     ;; uint16 _handlingDuration
       (write-word _handlingDuration s)
     ;; uint16 _timeOutDuration
       (write-word _timeOutDuration s)
     ;; string _requiredResources
       (write-long (length _requiredResources) s) (princ _requiredResources s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _taskUUID
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _taskUUID (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint64 _timeStamp
     
#+(or :alpha :irix6 :x86_64)
      (setf _timeStamp (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _timeStamp (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; uint16 _handlingDuration
     (setq _handlingDuration (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _timeOutDuration
     (setq _timeOutDuration (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _requiredResources
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _requiredResources (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ISLH_msgs::newTaskInfoMessage :md5sum-) "0857da229f3a63b6ca6a5f69dd323a29")
(setf (get ISLH_msgs::newTaskInfoMessage :datatype-) "ISLH_msgs/newTaskInfoMessage")
(setf (get ISLH_msgs::newTaskInfoMessage :definition-)
      "# New task's information

string taskUUID # Universally Unique Identifier (UUID)

uint64 timeStamp #The encountering time

uint16 handlingDuration

uint16 timeOutDuration

string requiredResources # Required resources for this task


")



(provide :ISLH_msgs/newTaskInfoMessage "0857da229f3a63b6ca6a5f69dd323a29")


