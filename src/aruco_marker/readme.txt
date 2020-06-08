---------------------------------------aruco_marker package------------------------------------------
ISLH_msgs and camera_calibration packages are used at this package.

-----------------------ArucoMarker class---------------------------
This class has two main functions:
1)markerGenerater
  It takes robotIDs vector as input,
  generates related markers to use on the robots and adds them to the folder defined at arucoMarker.h file.
  Also, cameraID must be defined at arucoMarker.h file.

2)calculateRobotPos
  It takes image from the camera or jpg file,
  detects markers, calculates robot positions and headings,
  publishes them at the workspace as "robot_list".

  When "ısCamera" variable is 1, it takes image from the camera,
  when it is 0, it takes from the jpg file defined with "input_img_name" variable.
  These variables are at arucoMarker.h file.


---------------------executables-------------------------------------
1) main.cpp >>  aruco_marker_node
