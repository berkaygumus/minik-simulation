/*
 Package name: pos_calculator
 File name: main.cpp
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 07.01.2020
 Date last modified: 24.08.2020

 Takes partial data from aruco marker detection and odometry data;
 calculates frame transformations and robot positions;
 publishes them
 */

#include <ros/ros.h>
#include <rosThread.h>//pos_calculator library


int main(int argc,char** argv){

    ros::init(argc,argv,"pos_calculator");
    RosThread* rosthread  = new RosThread();
    rosthread->work();




}
