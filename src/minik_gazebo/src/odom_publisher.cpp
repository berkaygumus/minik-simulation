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

#define NOISE_RATIO 0.05
#define STUCK 0.05

OdomPublisher::OdomPublisher(){
  for(int i=0;i<n;i++){
    path_dist[i] = 0;
  }
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
    prevPos[0][0] = temp_x;
    prevPos[0][1] = temp_y;
    noisyPos[0][0] = temp_x;
    noisyPos[0][1] = temp_y;

  }
  else{
    if(prevPos[0][3]==1){
      prevPos[0][0] = pos[0][0];
      prevPos[0][1] = pos[0][1];
      prevPos[0][3] = 0;
    }
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
    prevPos[1][0] = temp_x;
    prevPos[1][1] = temp_y;
    noisyPos[1][0] = temp_x;
    noisyPos[1][1] = temp_y;
  }
  else{
    if(prevPos[1][3]==1){
      prevPos[1][0] = pos[1][0];
      prevPos[1][1] = pos[1][1];
      prevPos[1][3] = 0;
    }
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
    prevPos[2][0] = temp_x;
    prevPos[2][1] = temp_y;
    noisyPos[2][0] = temp_x;
    noisyPos[2][1] = temp_y;
  }
  else{
    if(prevPos[2][3]==1){
      prevPos[2][0] = pos[2][0];
      prevPos[2][1] = pos[2][1];
      prevPos[2][3] = 0;
    }
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
    prevPos[3][0] = temp_x;
    prevPos[3][1] = temp_y;
    noisyPos[3][0] = temp_x;
    noisyPos[3][1] = temp_y;
  }
  else{
    if(prevPos[3][3]==1){
      prevPos[3][0] = pos[3][0];
      prevPos[3][1] = pos[3][1];
      prevPos[3][3] = 0;
    }
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
    prevPos[4][0] = temp_x;
    prevPos[4][1] = temp_y;
    noisyPos[4][0] = temp_x;
    noisyPos[4][1] = temp_y;
  }
  else{
    if(prevPos[4][3]==1){
      prevPos[4][0] = pos[4][0];
      prevPos[4][1] = pos[4][1];
      prevPos[4][3] = 0;
    }
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

  double dx = pos[i][0] - prevPos[i][0];
  double dy = pos[i][1] - prevPos[i][1];
  prevPos[i][3]=1;
  double dist_factor = sqrt(pow(dx,2)+pow(dy,2));
  path_dist[i] = path_dist[i] + dist_factor;
  cout << "d" << i <<": " << dx << " " << dy << endl;
  cout << "path dist:" <<i<< ": "  << path_dist[i] << endl;
  /*adding noise to odometry data
  there are two kind of noise: gaussian noise and stuck noise
  gaussian noise: 2d gaussian distribution, mean: 0, standard deviation is NOISE_RATIO*distance(between previous pos and current pos, I assume the movement is discrete)
  stuck noise: not random, opposite to the velocity direction: noise_x = -STUCK*distance*cos(heading)
                                                               noise_y = -STUCK*distance*sin(heading)
  */
  std::normal_distribution<double> distribution(0,NOISE_RATIO);
  double gaussian_number_x = distribution(generator);
  double gaussian_number_y = distribution(generator);

  double gaussian_noise_x = gaussian_number_x * dist_factor - dist_factor*cos(pos[i][2])*STUCK;
  double gaussian_noise_y = gaussian_number_y * dist_factor - dist_factor*sin(pos[i][2])*STUCK;
  cout << "noise" << i <<": " << gaussian_noise_x << " " << gaussian_noise_y << endl;
  double tempNoisyPosX = noisyPos[i][0];
  double tempNoisyPosY = noisyPos[i][1];

  noisyPos[i][0] = noisyPos[i][0] + dx + gaussian_noise_x;
  noisyPos[i][1] = noisyPos[i][1] + dy + gaussian_noise_y;

  noisyPrevPos[i][0] = tempNoisyPosX;
  noisyPrevPos[i][1] = tempNoisyPosY;

  //cout << "real pos" << i <<": " << pos[i][0] << " " << pos[i][1] << endl;
  //cout << "noisy pos" << i <<": " << noisyPos[i][0] << " " << noisyPos[i][1] << endl;
  //cout << "dif pos" << i <<": " << noisyPos[i][0] - pos[i][0]  << " " << noisyPos[i][1] - pos[i][1] << endl ;

////////////////////////////////
  double posX0 = noisyPos[i][0];
  double posY0 = noisyPos[i][1];
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
  cout << "odom pos" << i <<": " << posR[0] << " " << posR[1] << endl<< endl;
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
