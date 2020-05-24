;; Auto-generated. Do not edit!


(when (boundp 'ISLH_msgs::taskInfo2MonitorMessage)
  (if (not (find-package "ISLH_MSGS"))
    (make-package "ISLH_MSGS"))
  (shadow 'taskInfo2MonitorMessage (find-package "ISLH_MSGS")))
(unless (find-package "ISLH_MSGS::TASKINFO2MONITORMESSAGE")
  (make-package "ISLH_MSGS::TASKINFO2MONITORMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude taskInfo2MonitorMessage.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass ISLH_msgs::taskInfo2MonitorMessage
  :super ros::object
  :slots (_taskUUID _encounteringRobotID _responsibleUnit _encounteringTime _startHandlingTime _posXY _taskResource _handlingDuration _timeOutDuration _status _taskSiteRadius ))

(defmethod ISLH_msgs::taskInfo2MonitorMessage
  (:init
   (&key
    ((:taskUUID __taskUUID) "")
    ((:encounteringRobotID __encounteringRobotID) 0)
    ((:responsibleUnit __responsibleUnit) 0)
    ((:encounteringTime __encounteringTime) 0)
    ((:startHandlingTime __startHandlingTime) 0)
    ((:posXY __posXY) (instance geometry_msgs::Point :init))
    ((:taskResource __taskResource) "")
    ((:handlingDuration __handlingDuration) 0)
    ((:timeOutDuration __timeOutDuration) 0)
    ((:status __status) 0)
    ((:taskSiteRadius __taskSiteRadius) 0)
    )
   (send-super :init)
   (setq _taskUUID (string __taskUUID))
   (setq _encounteringRobotID (round __encounteringRobotID))
   (setq _responsibleUnit (round __responsibleUnit))
   (setq _encounteringTime (round __encounteringTime))
   (setq _startHandlingTime (round __startHandlingTime))
   (setq _posXY __posXY)
   (setq _taskResource (string __taskResource))
   (setq _handlingDuration (round __handlingDuration))
   (setq _timeOutDuration (round __timeOutDuration))
   (setq _status (round __status))
   (setq _taskSiteRadius (round __taskSiteRadius))
   self)
  (:taskUUID
   (&optional __taskUUID)
   (if __taskUUID (setq _taskUUID __taskUUID)) _taskUUID)
  (:encounteringRobotID
   (&optional __encounteringRobotID)
   (if __encounteringRobotID (setq _encounteringRobotID __encounteringRobotID)) _encounteringRobotID)
  (:responsibleUnit
   (&optional __responsibleUnit)
   (if __responsibleUnit (setq _responsibleUnit __responsibleUnit)) _responsibleUnit)
  (:encounteringTime
   (&optional __encounteringTime)
   (if __encounteringTime (setq _encounteringTime __encounteringTime)) _encounteringTime)
  (:startHandlingTime
   (&optional __startHandlingTime)
   (if __startHandlingTime (setq _startHandlingTime __startHandlingTime)) _startHandlingTime)
  (:posXY
   (&rest __posXY)
   (if (keywordp (car __posXY))
       (send* _posXY __posXY)
     (progn
       (if __posXY (setq _posXY (car __posXY)))
       _posXY)))
  (:taskResource
   (&optional __taskResource)
   (if __taskResource (setq _taskResource __taskResource)) _taskResource)
  (:handlingDuration
   (&optional __handlingDuration)
   (if __handlingDuration (setq _handlingDuration __handlingDuration)) _handlingDuration)
  (:timeOutDuration
   (&optional __timeOutDuration)
   (if __timeOutDuration (setq _timeOutDuration __timeOutDuration)) _timeOutDuration)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:taskSiteRadius
   (&optional __taskSiteRadius)
   (if __taskSiteRadius (setq _taskSiteRadius __taskSiteRadius)) _taskSiteRadius)
  (:serialization-length
   ()
   (+
    ;; string _taskUUID
    4 (length _taskUUID)
    ;; uint16 _encounteringRobotID
    2
    ;; int16 _responsibleUnit
    2
    ;; uint64 _encounteringTime
    8
    ;; uint64 _startHandlingTime
    8
    ;; geometry_msgs/Point _posXY
    (send _posXY :serialization-length)
    ;; string _taskResource
    4 (length _taskResource)
    ;; uint16 _handlingDuration
    2
    ;; uint16 _timeOutDuration
    2
    ;; uint16 _status
    2
    ;; uint64 _taskSiteRadius
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _taskUUID
       (write-long (length _taskUUID) s) (princ _taskUUID s)
     ;; uint16 _encounteringRobotID
       (write-word _encounteringRobotID s)
     ;; int16 _responsibleUnit
       (write-word _responsibleUnit s)
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
     ;; geometry_msgs/Point _posXY
       (send _posXY :serialize s)
     ;; string _taskResource
       (write-long (length _taskResource) s) (princ _taskResource s)
     ;; uint16 _handlingDuration
       (write-word _handlingDuration s)
     ;; uint16 _timeOutDuration
       (write-word _timeOutDuration s)
     ;; uint16 _status
       (write-word _status s)
     ;; uint64 _taskSiteRadius
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _taskSiteRadius (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _taskSiteRadius) (= (length (_taskSiteRadius . bv)) 2)) ;; bignum
              (write-long (ash (elt (_taskSiteRadius . bv) 0) 0) s)
              (write-long (ash (elt (_taskSiteRadius . bv) 1) -1) s))
             ((and (class _taskSiteRadius) (= (length (_taskSiteRadius . bv)) 1)) ;; big1
              (write-long (elt (_taskSiteRadius . bv) 0) s)
              (write-long (if (>= _taskSiteRadius 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _taskSiteRadius s)(write-long (if (>= _taskSiteRadius 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _taskUUID
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _taskUUID (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint16 _encounteringRobotID
     (setq _encounteringRobotID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _responsibleUnit
     (setq _responsibleUnit (sys::peek buf ptr- :short)) (incf ptr- 2)
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
   ;; geometry_msgs/Point _posXY
     (send _posXY :deserialize buf ptr-) (incf ptr- (send _posXY :serialization-length))
   ;; string _taskResource
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _taskResource (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint16 _handlingDuration
     (setq _handlingDuration (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _timeOutDuration
     (setq _timeOutDuration (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _status
     (setq _status (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint64 _taskSiteRadius
     
#+(or :alpha :irix6 :x86_64)
      (setf _taskSiteRadius (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _taskSiteRadius (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get ISLH_msgs::taskInfo2MonitorMessage :md5sum-) "306235d16ea68afd7b8cdaafd193738f")
(setf (get ISLH_msgs::taskInfo2MonitorMessage :datatype-) "ISLH_msgs/taskInfo2MonitorMessage")
(setf (get ISLH_msgs::taskInfo2MonitorMessage :definition-)
      "# The task's information to monitoringISLH

string taskUUID # the task's UUID

uint16 encounteringRobotID #robot id which encounters the task

int16 responsibleUnit # \"who is responsible for the task\"

uint64 encounteringTime #The encountering time

uint64 startHandlingTime #the time when the task starts being handled

geometry_msgs/Point posXY  # The position of the task

string taskResource

uint16 handlingDuration # in seconds - \"the required time to handle the task\"

uint16 timeOutDuration # \"the timed-out duration for the task\"

uint16 status # \"status of the task\"

uint64 taskSiteRadius

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :ISLH_msgs/taskInfo2MonitorMessage "306235d16ea68afd7b8cdaafd193738f")


