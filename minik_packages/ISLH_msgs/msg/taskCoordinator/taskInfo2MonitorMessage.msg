# The task's information to monitoringISLH

string taskUUID # the task's UUID

uint16 encounteringRobotID #robot id which encounters the task

int16 responsibleUnit # "who is responsible for the task"

uint64 encounteringTime #The encountering time

uint64 startHandlingTime #the time when the task starts being handled

geometry_msgs/Point posXY  # The position of the task

string taskResource

uint16 handlingDuration # in seconds - "the required time to handle the task"

uint16 timeOutDuration # "the timed-out duration for the task"

uint16 status # "status of the task"

uint64 taskSiteRadius
