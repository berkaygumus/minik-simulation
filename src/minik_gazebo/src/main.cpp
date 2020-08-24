/*
 Package name: minik_gazebo
 File name: main.cpp
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 28.06.2020
 Date last modified: 24.08.2020

 Takes robot positions and headings with respect to world frame,
 converts to them with respect to initial robot frames
 */
#include <ros/ros.h>
#include <odom_publisher.h> //odom_publisher library

using namespace std;

int main(int argc,char** argv){

    ros::init(argc,argv,"odom_publisher_node");
    cout << "odom_publisher_node" << endl;
    OdomPublisher* odom_publisher = new OdomPublisher();
    odom_publisher->work();

}
