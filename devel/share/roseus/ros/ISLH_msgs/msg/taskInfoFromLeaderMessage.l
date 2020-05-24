;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::taskInfoFromLeaderMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'taskInfoFromLeaderMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::TASKINFOFROMLEADERMESSAGE")
  (make-package "ISLH_MSGS::TASKINFOFROMLEADERMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude taskInfoFromLeaderMessage.msg.html


(defclass ISLH_msgs::taskInfoFromLeaderMessage
  :super ros::object
  :slots (_sendingTime _infoTypeID _senderRobotID _encounteringRobotID _encounteringTime _startHandlingTime _handlingDuration _timeOutDuration _requiredResources _posX _posY _taskUUID _extraMsg ))

(defmethod ISLH_msgs::taskInfoFromLeaderMessage
  (:init
   (&key
    ((:sendingTime __sendingTime) 0)
    ((:infoTypeID __infoTypeID) 0)
    ((:senderRobotID __senderRobotID) 0)
    ((:encounteringRobotID __encounteringRobotID) 0)
    ((:encounteringTime __encounteringTime) 0)
    ((:startHandlingTime __startHandlingTime) 0)
    ((:handlingDuration __handlingDuration) 0)
    ((:timeOutDuration __timeOutDuration) 0)
    ((:requiredResources __requiredResources) "")
    ((:posX __posX) 0.0)
    ((:posY __posY) 0.0)
    ((:taskUUID __taskUUID) "")
    ((:extraMsg __extraMsg) "")
    )
   (send-super :init)
   (setq _sendingTime (round __sendingTime))
   (setq _infoTypeID (round __infoTypeID))
   (setq _senderRobotID (round __senderRobotID))
   (setq _encounteringRobotID (round __encounteringRobotID))
   (setq _encounteringTime (round __encounteringTime))
   (setq _startHandlingTime (round __startHandlingTime))
   (setq _handlingDuration (round __handlingDuration))
   (setq _timeOutDuration (round __timeOutDuration))
   (setq _requiredResources (string __requiredResources))
   (setq _posX (float __posX))
   (setq _posY (float __posY))
   (setq _taskUUID (string __taskUUID))
   (setq _extraMsg (string __extraMsg))
   self)
  (:sendingTime
   (&optional __sendingTime)
   (if __sendingTime (setq _sendingTime __sendingTime)) _sendingTime)
  (:infoTypeID
   (&optional __infoTypeID)
   (if __infoTypeID (setq _infoTypeID __infoTypeID)) _infoTypeID)
  (:senderRobotID
   (&optional __senderRobotID)
   (if __senderRobotID (setq _senderRobotID __senderRobotID)) _senderRobotID)
  (:encounteringRobotID
   (&optional __encounteringRobotID)
   (if __encounteringRobotID (setq _encounteringRobotID __encounteringRobotID)) _encounteringRobotID)
  (:encounteringTime
   (&optional __encounteringTime)
   (if __encounteringTime (setq _encounteringTime __encounteringTime)) _encounteringTime)
  (:startHandlingTime
   (&optional __startHandlingTime)
   (if __startHandlingTime (setq _startHandlingTime __startHandlingTime)) _startHandlingTime)
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
  (:taskUUID
   (&optional __taskUUID)
   (if __taskUUID (setq _taskUUID __taskUUID)) _taskUUID)
  (:extraMsg
   (&optional __extraMsg)
   (if __extraMsg (setq _extraMsg __extraMsg)) _extraMsg)
  (:serialization-length
   ()
   (+
    ;; uint64 _sendingTime
    8
    ;; uint16 _infoTypeID
    2
    ;; uint16 _senderRobotID
    2
    ;; uint16 _encounteringRobotID
    2
    ;; uint64 _encounteringTime
    8
    ;; uint64 _startHandlingTime
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
    ;; string _taskUUID
    4 (length _taskUUID)
    ;; string _extraMsg
    4 (length _extraMsg)
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
     ;; uint16 _senderRobotID
       (write-word _senderRobotID s)
     ;; uint16 _encounteringRobotID
       (write-word _encounteringRobotID s)
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
     ;; uint64 _startHandlingTime
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _startHandlingTime (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _startHandlingTime) (= (length (_startHandlingTime . bv)) 2)) ;; bignum
              (write-long (ash (elt (_startHandlingTime . bv) 0) 0) s)
              (write-long (ash (elt (_startHandlingTime . bv) 1) -1) s))
             ((and (class _startHandlingTime) (= (length (_startHandlingTime . bv)) 1)) ;; big1
              (write-long (elt (_startHandlingTime . bv) 0) s)
              (write-long (if (>= _startHandlingTime 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _startHandlingTime s)(write-long (if (>= _startHandlingTime 0) 0 #xffffffff) s)))
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
     ;; string _taskUUID
       (write-long (length _taskUUID) s) (princ _taskUUID s)
     ;; string _extraMsg
       (write-long (length _extraMsg) s) (princ _extraMsg s)
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
   ;; uint16 _senderRobotID
     (setq _senderRobotID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _encounteringRobotID
     (setq _encounteringRobotID (sys::peek buf ptr- :short)) (incf ptr- 2)
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
   ;; uint64 _startHandlingTime
     
#+(or :alpha :irix6 :x86_64)
      (setf _startHandlingTime (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _startHandlingTime (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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
   ;; string _taskUUID
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _taskUUID (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _extraMsg
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _extraMsg (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ISLH_msgs::taskInfoFromLeaderMessage :md5sum-) "a19d17ade63c51621e68763c106dd71e")
(setf (get ISLH_msgs::taskInfoFromLeaderMessage :datatype-) "ISLH_msgs/taskInfoFromLeaderMessage")
(setf (get ISLH_msgs::taskInfoFromLeaderMessage :definition-)
      "# The task's information to the task coordinator

uint64 sendingTime #The sending time

uint16 infoTypeID

uint16 senderRobotID # robot id of coalition leader 

uint16 encounteringRobotID #robot id which encounters the task

uint64 encounteringTime #The encountering time in timestamp form

uint64 startHandlingTime #the time when the task starts being handled

uint16 handlingDuration

uint16 timeOutDuration

string requiredResources # Required resources for this task

float32 posX # The position of the task at x direction
float32 posY # The position of the task at y direction

string taskUUID # the task's UUID

string extraMsg


")



(provide :ISLH_msgs/taskInfoFromLeaderMessage "a19d17ade63c51621e68763c106dd71e")


