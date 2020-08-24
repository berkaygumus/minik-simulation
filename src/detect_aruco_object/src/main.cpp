/*
 Package name: detect_aruco_object
 File name: main.cpp
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified: 24.08.2020

 subscribes odometry and source image messages;
 calculates and publishes positions, headings, ID's of robots detected by each robot
 */

#include <ros/ros.h>
#include <detect_aruco_object/detectArucoObject.h> //detect_aruco_object library

using namespace std;

int main(int argc,char** argv){

    ros::init(argc,argv,"detect_aruco_object");
    cout << "detect_aruco_object_node" << endl;
    DetectArucoObject* detect_aruco_object  = new DetectArucoObject();
    detect_aruco_object->work();


}
