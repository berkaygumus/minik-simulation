/*
 File name: arucoMarker.h
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified: 27.05.2020
 */

#include "ros/ros.h"
#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>

#include <geometry_msgs/Pose2D.h>
#include "ISLH_msgs/robotPositions.h"
#include "float.h"

#include "camera_calibration/camera_calibration.h"

using namespace std;
using namespace cv;

class ArucoMarker{
  public:

    ArucoMarker();
    ~ArucoMarker();
    void markerGenerater(vector<int>);
    void setCamParameters();
    void calculateRobotPos();


  private:

    ros::NodeHandle n;

    string aruco_marker_folder = "/home/berkay/catkin_ws/src/aruco_marker/aruco_markers/";//folder to add aruco marker images for markerGenerater function
    int cameraID = 1;//camera ID
    bool isCamera = 1;
    string input_img_name = "/home/berkay/catkin_ws/src/aruco_marker/images/aruco4.jpg";

    Mat cameraMatrix;
    Mat distCoeffs;

};
