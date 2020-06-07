---------------------------------------aruco_marker package------------------------------------------

-----------------------ArucoMarker class---------------------------
This class has two main functions:
1)markerGenerater
  It takes robotIDs vector as input,
  generates related markers to use on the robots and adds them to the folder defined at arucoMarker.h file.
  Also, cameraID must be defined at arucoMarker.h file.

2)calculateRobotPos
  It takes image from the camera,
  detects markers, calculates robot positions and headings,
  publishes them at the workspace as "robot_list".


---------------------executables-------------------------------------
1) main.cpp >>  aruco_marker_node
