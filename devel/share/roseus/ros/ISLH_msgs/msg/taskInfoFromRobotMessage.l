;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::taskInfoFromRobotMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'taskInfoFromRobotMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::TASKINFOFROMROBOTMESSAGE")
  (make-package "ISLH_MSGS::TASKINFOFROMROBOTMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude taskInfoFromRobotMessage.msg.html


(defclass ISLH_msgs::taskInfoFromRobotMessage
  :super ros::object
  :slots (_senderRobotID _infoMessageType _taskUUID _encounteringTime _reachingTime _handlingDuration _timeOutDuration _requiredResources _posX _posY ))

(defmethod ISLH_msgs::taskInfoFromRobotMessage
  (:init
   (&key
    ((:senderRobotID __senderRobotID) 0)
    ((:infoMessageType __infoMessageType) 0)
    ((:taskUUID __taskUUID) "")
    ((:encounteringTime __encounteringTime) 0)
    ((:reachingTime __reachingTime) 0)
    ((:handlingDuration __handlingDuration) 0)
    ((:timeOutDuration __timeOutDuration) 0)
    ((:requiredResources __requiredResources) "")
    ((:posX __posX) 0.0)
    ((:posY __posY) 0.0)
    )
   (send-super :init)
   (setq _senderRobotID (round __senderRobotID))
   (setq _infoMessageType (round __infoMessageType))
   (setq _taskUUID (string __taskUUID))
   (setq _encounteringTime (round __encounteringTime))
   (setq _reachingTime (round __reachingTime))
   (setq _handlingDuration (round __handlingDuration))
   (setq _timeOutDuration (round __timeOutDuration))
   (setq _requiredResources (string __requiredResources))
   (setq _posX (float __posX))
   (setq _posY (float __posY))
   self)
  (:senderRobotID
   (&optional __senderRobotID)
   (if __senderRobotID (setq _senderRobotID __senderRobotID)) _senderRobotID)
  (:infoMessageType
   (&optional __infoMessageType)
   (if __infoMessageType (setq _infoMessageType __infoMessageType)) _infoMessageType)
  (:taskUUID
   (&optional __taskUUID)
   (if __taskUUID (setq _taskUUID __taskUUID)) _taskUUID)
  (:encounteringTime
   (&optional __encounteringTime)
   (if __encounteringTime (setq _encounteringTime __encounteringTime)) _encounteringTime)
  (:reachingTime
   (&optional __reachingTime)
   (if __reachingTime (setq _reachingTime __reachingTime)) _reachingTime)
  (:handlingDuration
   (&optional __handlingDuration)
   (if __handlingDuration (setq _handlingDuration __handlingDuration)) _handlingDuration)
  (:timeOutDuration
   (&optional __timeOutDuration)
   (if __timeOutDuration (setq _timeOutDuration __timeOutDuration)) _timeOutDuration)
  (:requiredResources
   (&optional __requiredResources)
   (if __requiredResources (setq _requiredResources __requiredResources)) _requiredResources)
  (:posX
   (&optional __posX)
   (if __posX (setq _posX __posX)) _posX)
  (:posY
   (&optional __posY)
   (if __posY (setq _posY __posY)) _posY)
  (:serialization-length
   ()
   (+
    ;; uint16 _senderRobotID
    2
    ;; uint16 _infoMessageType
    2
    ;; string _taskUUID
    4 (length _taskUUID)
    ;; uint64 _encounteringTime
    8
    ;; uint64 _reachingTime
    8
    ;; uint16 _handlingDuration
    2
    ;; uint16 _timeOutDuration
    2
    ;; string _requiredResources
    4 (length _requiredResources)
    ;; float32 _posX
    4
    ;; float32 _posY
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _senderRobotID
       (write-word _senderRobotID s)
     ;; uint16 _infoMessageType
       (write-word _infoMessageType s)
     ;; string _taskUUID
       (write-long (length _taskUUID) s) (princ _taskUUID s)
     ;; uint64 _encounteringTime
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _encounteringTime (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _encounteringTime) (= (length (_encounteringTime . bv)) 2)) ;; bignum
              (write-long (ash (elt (_encounteringTime . bv) 0) 0) s)
              (write-long (ash (elt (_encounteringTime . bv) 1) -1) s))
             ((and (class _encounteringTime) (= (length (_encounteringTime . bv)) 1)) ;; big1
              (write-long (elt (_encounteringTime . bv) 0) s)
              (write-long (if (>= _encounteringTime 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _encounteringTime s)(write-long (if (>= _encounteringTime 0) 0 #xffffffff) s)))
     ;; uint64 _reachingTime
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _reachingTime (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _reachingTime) (= (length (_reachingTime . bv)) 2)) ;; bignum
              (write-long (ash (elt (_reachingTime . bv) 0) 0) s)
              (write-long (ash (elt (_reachingTime . bv) 1) -1) s))
             ((and (class _reachingTime) (= (length (_reachingTime . bv)) 1)) ;; big1
              (write-long (elt (_reachingTime . bv) 0) s)
              (write-long (if (>= _reachingTime 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _reachingTime s)(write-long (if (>= _reachingTime 0) 0 #xffffffff) s)))
     ;; uint16 _handlingDuration
       (write-word _handlingDuration s)
     ;; uint16 _timeOutDuration
       (write-word _timeOutDuration s)
     ;; string _requiredResources
       (write-long (length _requiredResources) s) (princ _requiredResources s)
     ;; float32 _posX
       (sys::poke _posX (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _posY
       (sys::poke _posY (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _senderRobotID
     (setq _senderRobotID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _infoMessageType
     (setq _infoMessageType (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _taskUUID
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _taskUUID (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint64 _encounteringTime
     
#+(or :alpha :irix6 :x86_64)
      (setf _encounteringTime (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _encounteringTime (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; uint64 _reachingTime
     
#+(or :alpha :irix6 :x86_64)
      (setf _reachingTime (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _reachingTime (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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
   ;; float32 _posX
     (setq _posX (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _posY
     (setq _posY (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get ISLH_msgs::taskInfoFromRobotMessage :md5sum-) "e54b818b14e2cc4a576aa5a518a1a847")
(setf (get ISLH_msgs::taskInfoFromRobotMessage :datatype-) "ISLH_msgs/taskInfoFromRobotMessage")
(setf (get ISLH_msgs::taskInfoFromRobotMessage :definition-)
      "# The task's information  from member robot to coalition leader

uint16 senderRobotID #robot id which encounters the task

uint16 infoMessageType

string taskUUID # the task's UUID

uint64 encounteringTime #The encountering time in timestamp form

uint64 reachingTime # The time when the robot reached to the task site

uint16 handlingDuration

uint16 timeOutDuration

string requiredResources # Required resources for this task

float32 posX # The position of the task at x direction 
float32 posY # The position of the task at y direction 



")



(provide :ISLH_msgs/taskInfoFromRobotMessage "e54b818b14e2cc4a576aa5a518a1a847")


