/*
Package name: minik_gazebo
File name: odom_publisher.cpp
Author: Berkay Gumus
E-mail: berkay.gumus@boun.edu.tr
Date created: 28.06.2020
Date last modified: 24.08.2020

Takes robot positions and headings with respect to world frame,
converts to them with respect to initial robot frames
*/

#include "odom_publisher.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>


using namespace std;



OdomPublisher::OdomPublisher(){
}

OdomPublisher::~OdomPublisher(){
}

//subscriber for robot 1 position
void OdomPublisher::gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr& msg){
  //position with respect to world frame: x,y
  double temp_x = msg->pose.pose.position.x;
  double temp_y = msg->pose.pose.position.y;

  //quaternion
  tf::Quaternion q(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y,
                     msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  //rotation angles
  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);

  //related angle is yaw >> heading with respect to world frame
  double temp_theta = yaw;

  //to save initial position and heading
  if(flag==0){
    initPos[0][0] = temp_x;
    initPos[0][1] = temp_y;
    initPos[0][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  }
  //current position and heading
  pos[0][0] = temp_x;
  pos[0][1] = temp_y;
  pos[0][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);

  flagN[0]=1; //check whether initial position and heading are saved for robot 1

}

//subscriber for robot 2 position
void OdomPublisher::gazeboOdomCallback2(const nav_msgs::Odometry::ConstPtr& msg){
  double temp_x = msg->pose.pose.position.x;
  double temp_y = msg->pose.pose.position.y;

  tf::Quaternion q(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y,
                     msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);

  double temp_theta = yaw;

  if(flag==0){
    initPos[1][0] = temp_x;
    initPos[1][1] = temp_y;
    initPos[1][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  }
  pos[1][0] = temp_x;
  pos[1][1] = temp_y;
  pos[1][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);

  flagN[1]=1;
}

//subscriber for robot 3 position
void OdomPublisher::gazeboOdomCallback3(const nav_msgs::Odometry::ConstPtr& msg){
  double temp_x = msg->pose.pose.position.x;
  double temp_y = msg->pose.pose.position.y;

  tf::Quaternion q(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y,
                     msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);

  double temp_theta = yaw;

  if(flag==0){
    initPos[2][0] = temp_x;
    initPos[2][1] = temp_y;
    initPos[2][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  }
  pos[2][0] = temp_x;
  pos[2][1] = temp_y;
  pos[2][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);

  flagN[2]=1;
}

//subscriber for robot 4 position
void OdomPublisher::gazeboOdomCallback4(const nav_msgs::Odometry::ConstPtr& msg){
  double temp_x = msg->pose.pose.position.x;
  double temp_y = msg->pose.pose.position.y;

  tf::Quaternion q(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y,
                     msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);

  double temp_theta = yaw;

  if(flag==0){
    initPos[3][0] = temp_x;
    initPos[3][1] = temp_y;
    initPos[3][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  }
  pos[3][0] = temp_x;
  pos[3][1] = temp_y;
  pos[3][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);

  flagN[3]=1;
}

//subscriber for robot 5 position
void OdomPublisher::gazeboOdomCallback5(const nav_msgs::Odometry::ConstPtr& msg){
  double temp_x = msg->pose.pose.position.x;
  double temp_y = msg->pose.pose.position.y;

  tf::Quaternion q(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y,
                     msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);

  double temp_theta = yaw;

  if(flag==0){
    initPos[4][0] = temp_x;
    initPos[4][1] = temp_y;
    initPos[4][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  }
  pos[4][0] = temp_x;
  pos[4][1] = temp_y;
  pos[4][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);

  flagN[4]=1;
}

vector<double> OdomPublisher::calculatePos(int i){
  //Takes robot id, converts its pos wrt world frame to wrt initial frame

  //initial robot frame
  double initX = initPos[i][0];
  double initY = initPos[i][1];
  double initTheta = initPos[i][2];

  // position wrt world frame
  double posX0 = pos[i][0];
  double posY0 = pos[i][1];
  double posTheta0 = pos[i][2];

  //initialization of position wrt frame robot r
  vector<double> posR;
  posR.resize(3);


  //rotation matrix
  double rot[3][3] = {{cos(initTheta),sin(initTheta),0},{-sin(initTheta),cos(initTheta),0},{0,0,1}};
  //translation vector
  double trans[3] = {posX0 - initX, posY0-initY,1};

  //position and heading wrt initial robot frame
  posR[0] = rot[0][0] * trans[0] + rot[0][1] * trans[1];
  posR[1] = rot[1][0] * trans[0] + rot[1][1] * trans[1];
  posR[2] = posTheta0 - initTheta;

  //cout << i <<"-->" << j << " pos: " << posR[0] << " " << posR[1] << endl;

  //return position and heading wrt initial robot frame
  return posR;

}



void OdomPublisher::work(){

  //publishers for positions wrt initial robot frames
  ros::Publisher pos_odom1 = posPub.advertise<geometry_msgs::Pose>("/odom1",100);
  ros::Publisher pos_odom2 = posPub.advertise<geometry_msgs::Pose>("/odom2",100);
  ros::Publisher pos_odom3 = posPub.advertise<geometry_msgs::Pose>("/odom3",100);
  ros::Publisher pos_odom4 = posPub.advertise<geometry_msgs::Pose>("/odom4",100);
  ros::Publisher pos_odom5 = posPub.advertise<geometry_msgs::Pose>("/odom5",100);

  //subscribers for positions wrt world frame
  ros::Subscriber calc_sub1 = poseSub.subscribe("/robot1/odom",1000,&OdomPublisher::gazeboOdomCallback1,this);
  ros::Subscriber calc_sub2 = poseSub.subscribe("/robot2/odom",1000,&OdomPublisher::gazeboOdomCallback2,this);
  ros::Subscriber calc_sub3 = poseSub.subscribe("/robot3/odom",1000,&OdomPublisher::gazeboOdomCallback3,this);
  ros::Subscriber calc_sub4 = poseSub.subscribe("/robot4/odom",1000,&OdomPublisher::gazeboOdomCallback4,this);
  ros::Subscriber calc_sub5 = poseSub.subscribe("/robot5/odom",1000,&OdomPublisher::gazeboOdomCallback5,this);
  ros::Rate loop_rate(10);

  while (ros::ok()){

    //check whether each initial robot frame is saved
    flag = 1;
    for(int i=0;i<N;i++){
      flag = flag * flagN[i];
    }

    if(flag==1){//if each initial robot frame is saved, calculates positions wrt initial robot frames

      //positions wrt initial robot frames
      vector<double> odom1 = calculatePos(0);
      vector<double> odom2 = calculatePos(1);
      vector<double> odom3 = calculatePos(2);
      vector<double> odom4 = calculatePos(3);
      vector<double> odom5 = calculatePos(4);

      //geometry_msgs::Pose messages for each robot using previous calculations
      geometry_msgs::Pose odomPos1;
      odomPos1.position.x = odom1[0];
      odomPos1.position.y = odom1[1];
      odomPos1.position.z = odom1[2];

      geometry_msgs::Pose odomPos2;
      odomPos2.position.x = odom2[0];
      odomPos2.position.y = odom2[1];
      odomPos2.position.z = odom2[2];

      geometry_msgs::Pose odomPos3;
      odomPos3.position.x = odom3[0];
      odomPos3.position.y = odom3[1];
      odomPos3.position.z = odom3[2];


      geometry_msgs::Pose odomPos4;
      odomPos4.position.x = odom4[0];
      odomPos4.position.y = odom4[1];
      odomPos4.position.z = odom4[2];

      geometry_msgs::Pose odomPos5;
      odomPos5.position.x = odom5[0];
      odomPos5.position.y = odom5[1];
      odomPos5.position.z = odom5[2];

      //publishes each position
      pos_odom1.publish(odomPos1);
      pos_odom2.publish(odomPos2);
      pos_odom3.publish(odomPos3);
      pos_odom4.publish(odomPos4);
      pos_odom5.publish(odomPos5);

    }
    else{

      ROS_INFO("waiting...");
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
}
