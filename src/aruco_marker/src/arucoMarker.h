/*
 File name: arucoMarker.h
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified:
 */

#include "ros/ros.h"
#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>

using namespace std;
using namespace cv;

class ArucoMarker{
  public:

    ArucoMarker();
    ~ArucoMarker();
    void markerGenerater(int);
    void setCamParameters();
    void calculateRobotPos();


  private:

    ros::NodeHandle n;

    string aruco_marker_folder = "/home/berkay/catkin_ws/src/aruco_marker/aruco_markers/";//folder to add aruco marker images for markerGenerater function
    int cameraID = 1;//camera ID

    Mat cameraMatrix;
    Mat distCoeffs;

};
