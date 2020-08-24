/*
 Package name: pos_calculator
 File name: rosThread.cpp
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 07.01.2020
 Date last modified: 24.08.2020

 Takes partial data from aruco marker detection and odometry data;
 calculates frame transformations and robot positions;
 publishes them
 */
#include "rosThread.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <geometry_msgs/PoseArray.h>

using namespace std;



RosThread::RosThread(){
  for(int tt=0;tt<sizeP;tt++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        for(int k=0;k<2;k++){
          //data initialization; -1000 means it's unknown
          robotsSeen[tt][i][j][k] = -1000;
        }
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      connected[i][j] = false;
      for(int k=0;k<sizeT;k++){
        //data initialization; -1 means there is not observation
        lastSeen[i][j][k] = -1;
      }
    }
  }

  cout << "pos_calculator is created!" << endl;
}

RosThread::~RosThread(){

}

//subscribers for odometry from turtlesim

/*void RosThread::sensorCallback0(const geometry_msgs::PoseArray::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  for(int j=0;j<n;j++){
    robotsSeen[index_t][0][j][0] = msg->poses[j].position.x;
    robotsSeen[index_t][0][j][1] = msg->poses[j].position.y;
    //cout << "call 0-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;

    if(checkSeenTime(0,j)){//if it observes the robot
        addSeenTime(0,j);
    }
  }
  posRobots[0][0][0] = robotsSeen[index_t][0][0][0];
  posRobots[0][0][1] = robotsSeen[index_t][0][0][1];



}

void RosThread::sensorCallback1(const geometry_msgs::PoseArray::ConstPtr& msg){
  //cout << "callback1: " << t << endl;
  for(int j=0;j<n;j++){
    robotsSeen[index_t][1][j][0] = msg->poses[j].position.x;
    robotsSeen[index_t][1][j][1] = msg->poses[j].position.y;
    //cout << "1-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;
    if(checkSeenTime(1,j)){
        addSeenTime(1,j);
    }
  }
  posRobots[1][1][0] = robotsSeen[index_t][1][1][0];
  posRobots[1][1][1] = robotsSeen[index_t][1][1][1];

}

void RosThread::sensorCallback2(const geometry_msgs::PoseArray::ConstPtr& msg){
  for(int j=0;j<n;j++){
    robotsSeen[index_t][2][j][0] = msg->poses[j].position.x;
    robotsSeen[index_t][2][j][1] = msg->poses[j].position.y;
    //cout << "2-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;
    if(checkSeenTime(2,j)){
        addSeenTime(2,j);
    }
  }
  posRobots[2][2][0] = robotsSeen[index_t][2][2][0];
  posRobots[2][2][1] = robotsSeen[index_t][2][2][1];
}*/


//subscribers for odometry from gazebo

void RosThread::odom1callback(const geometry_msgs::Pose::ConstPtr& msg){
  int temp_id = 0;
    robotsSeen[index_t][temp_id][temp_id][0] = msg->position.x;//adds odometry to data
    robotsSeen[index_t][temp_id][temp_id][1] = msg->position.y;
    if(checkSeenTime(temp_id,temp_id)){
        addSeenTime(temp_id,temp_id);
    }
  posRobots[temp_id][temp_id][0] = robotsSeen[index_t][temp_id][temp_id][0];//odometry is the position wrt itself, so it's added to posRobots data
  posRobots[temp_id][temp_id][1] = robotsSeen[index_t][temp_id][temp_id][1];


}

void RosThread::odom2callback(const geometry_msgs::Pose::ConstPtr& msg){
  int temp_id = 1;
    robotsSeen[index_t][temp_id][temp_id][0] = msg->position.x;
    robotsSeen[index_t][temp_id][temp_id][1] = msg->position.y;
    if(checkSeenTime(temp_id,temp_id)){
        addSeenTime(temp_id,temp_id);
    }
  posRobots[temp_id][temp_id][0] = robotsSeen[index_t][temp_id][temp_id][0];
  posRobots[temp_id][temp_id][1] = robotsSeen[index_t][temp_id][temp_id][1];

}

void RosThread::odom3callback(const geometry_msgs::Pose::ConstPtr& msg){
  int temp_id = 2;
    robotsSeen[index_t][temp_id][temp_id][0] = msg->position.x;
    robotsSeen[index_t][temp_id][temp_id][1] = msg->position.y;
    if(checkSeenTime(temp_id,temp_id)){
        addSeenTime(temp_id,temp_id);
    }
  posRobots[temp_id][temp_id][0] = robotsSeen[index_t][temp_id][temp_id][0];
  posRobots[temp_id][temp_id][1] = robotsSeen[index_t][temp_id][temp_id][1];

}

void RosThread::odom4callback(const geometry_msgs::Pose::ConstPtr& msg){
  int temp_id = 3;
    robotsSeen[index_t][temp_id][temp_id][0] = msg->position.x;
    robotsSeen[index_t][temp_id][temp_id][1] = msg->position.y;
    if(checkSeenTime(temp_id,temp_id)){
        addSeenTime(temp_id,temp_id);
    }
  posRobots[temp_id][temp_id][0] = robotsSeen[index_t][temp_id][temp_id][0];
  posRobots[temp_id][temp_id][1] = robotsSeen[index_t][temp_id][temp_id][1];

}

void RosThread::odom5callback(const geometry_msgs::Pose::ConstPtr& msg){
  int temp_id = 4;
    robotsSeen[index_t][temp_id][temp_id][0] = msg->position.x;
    robotsSeen[index_t][temp_id][temp_id][1] = msg->position.y;
    if(checkSeenTime(temp_id,temp_id)){
        addSeenTime(temp_id,temp_id);
    }
  posRobots[temp_id][temp_id][0] = robotsSeen[index_t][temp_id][temp_id][0];
  posRobots[temp_id][temp_id][1] = robotsSeen[index_t][temp_id][temp_id][1];

}

//subscribers for positions, headings, ID's of robots detected

void RosThread::arucoCallback1(const ISLH_msgs::robotPositions::ConstPtr& msg){
  cout << "robot 0 observation //////////////////" << endl;
  for(int j=0;j<n;j++){
    //initialization, assumes that it is not seen; -1000 means there is not observation
    if(j!=0){
      robotsSeen[index_t][0][j][0] = -1000; //robotsSeen[time index][observer robot: robot 0][observed robot: robot j][x]
      robotsSeen[index_t][0][j][1] = -1000; //robotsSeen[time index][observer robot: robot 0][observed robot: robot j][y]
    }

  }

  vector<geometry_msgs::Pose2D > msg_positions;//position vector for each robot observed
  vector<float> headings; //heading vector for each robot observed
  vector<int> robot_IDs;//robotID vector for each robot observed

   msg_positions = msg->positions;
   headings = msg->directions;
   robot_IDs = msg->IDs;
   for(int i=0;i<msg_positions.size();i++){//for each robots observed
     int temp_id = robot_IDs[i];//id
     double temp_x = msg_positions[i].x;//x
     double temp_y = msg_positions[i].y;//y
     double temp_theta = msg_positions[i].theta;//heading
     cout << "ID: " << temp_id << " pos: " << temp_x << " " << temp_y << " " <<  temp_theta <<  endl;
     robotsSeen[index_t][0][temp_id][0] = temp_x;//adds observation to data
     robotsSeen[index_t][0][temp_id][1] = temp_y;
     if(checkSeenTime(0,temp_id)){//if it's valid observation, adds observation time to data
         addSeenTime(0,temp_id);
     }
   }


}

void RosThread::arucoCallback2(const ISLH_msgs::robotPositions::ConstPtr& msg){
  cout << "robot 1 observation //////////////////" << endl;
  for(int j=0;j<n;j++){
    if(j!=1){
      robotsSeen[index_t][1][j][0] = -1000;
      robotsSeen[index_t][1][j][1] = -1000;
    }
  }
  vector<geometry_msgs::Pose2D > msg_positions;
  vector<float> headings;
  vector<int> robot_IDs;

   msg_positions = msg->positions;
   headings = msg->directions;
   robot_IDs = msg->IDs;
   for(int i=0;i<msg_positions.size();i++){
     int temp_id = robot_IDs[i];
     double temp_x = msg_positions[i].x;
     double temp_y = msg_positions[i].y;
     double temp_theta = msg_positions[i].theta;
     cout << "ID: " << temp_id << " pos: " << temp_x << " " << temp_y << " " <<  temp_theta <<  endl;
     robotsSeen[index_t][1][temp_id][0] = temp_x;
     robotsSeen[index_t][1][temp_id][1] = temp_y;
     if(checkSeenTime(1,temp_id)){
         addSeenTime(1,temp_id);
     }
   }


}

void RosThread::arucoCallback3(const ISLH_msgs::robotPositions::ConstPtr& msg){
  cout << "robot 2 observation //////////////////" << endl;
  for(int j=0;j<n;j++){
    if(j!=2){
      robotsSeen[index_t][2][j][0] = -1000;
      robotsSeen[index_t][2][j][1] = -1000;
    }
  }

  vector<geometry_msgs::Pose2D > msg_positions;
  vector<float> headings;
  vector<int> robot_IDs;

   msg_positions = msg->positions;
   headings = msg->directions;
   robot_IDs = msg->IDs;
   for(int i=0;i<msg_positions.size();i++){
     int temp_id = robot_IDs[i];
     double temp_x = msg_positions[i].x;
     double temp_y = msg_positions[i].y;
     double temp_theta = msg_positions[i].theta;
     cout << "ID: " << temp_id << " pos: " << temp_x << " " << temp_y << " " <<  temp_theta <<  endl;
     robotsSeen[index_t][2][temp_id][0] = temp_x;
     robotsSeen[index_t][2][temp_id][1] = temp_y;
     if(checkSeenTime(2,temp_id)){
         addSeenTime(2,temp_id);
     }
   }

}

void RosThread::arucoCallback4(const ISLH_msgs::robotPositions::ConstPtr& msg){
  cout << "robot 3 observation //////////////////" << endl;
  for(int j=0;j<n;j++){
    if(j!=3){
      robotsSeen[index_t][3][j][0] = -1000;
      robotsSeen[index_t][3][j][1] = -1000;
    }

  }

  vector<geometry_msgs::Pose2D > msg_positions;
  vector<float> headings;
  vector<int> robot_IDs;

   msg_positions = msg->positions;
   headings = msg->directions;
   robot_IDs = msg->IDs;
   for(int i=0;i<msg_positions.size();i++){
     int temp_id = robot_IDs[i];
     double temp_x = msg_positions[i].x;
     double temp_y = msg_positions[i].y;
     double temp_theta = msg_positions[i].theta;
     cout << "ID: " << temp_id << " pos: " << temp_x << " " << temp_y << " " <<  temp_theta <<  endl;
     robotsSeen[index_t][3][temp_id][0] = temp_x;
     robotsSeen[index_t][3][temp_id][1] = temp_y;
     if(checkSeenTime(3,temp_id)){
         addSeenTime(3,temp_id);
     }
   }

}

void RosThread::arucoCallback5(const ISLH_msgs::robotPositions::ConstPtr& msg){
  cout << "robot 4 observation //////////////////" << endl;
  for(int j=0;j<n;j++){
    if(j!=4){
      robotsSeen[index_t][4][j][0] = -1000;
      robotsSeen[index_t][4][j][1] = -1000;
    }
  }

  vector<geometry_msgs::Pose2D > msg_positions;
  vector<float> headings;
  vector<int> robot_IDs;

   msg_positions = msg->positions;
   headings = msg->directions;
   robot_IDs = msg->IDs;
   for(int i=0;i<msg_positions.size();i++){
     int temp_id = robot_IDs[i];
     double temp_x = msg_positions[i].x;
     double temp_y = msg_positions[i].y;
     double temp_theta = msg_positions[i].theta;
     cout << "ID: " << temp_id << " pos: " << temp_x << " " << temp_y << " " <<  temp_theta <<  endl;
     robotsSeen[index_t][4][temp_id][0] = temp_x;
     robotsSeen[index_t][4][temp_id][1] = temp_y;
     if(checkSeenTime(4,temp_id)){
         addSeenTime(4,temp_id);
     }
   }

}



void RosThread::addSeenTime(int i, int j){//adds observation time to lastSeen data; it's valid only for SIZE_T 3
  if(lastSeen[i][j][0] == -1){
    lastSeen[i][j][0] = t;
  }

  else if(lastSeen[i][j][1] == -1){
    lastSeen[i][j][1] = lastSeen[i][j][0];
    lastSeen[i][j][0] = t;
  }

  else{
    lastSeen[i][j][2] = lastSeen[i][j][1];
    lastSeen[i][j][1] = lastSeen[i][j][0];
    lastSeen[i][j][0] = t;
  }

}

bool RosThread::checkSeenTime(int i, int j){//checks whether observation is proper to be added to data
  //cout << "index t: " << index_t << endl;
  if(robotsSeen[index_t][i][j][0]<-890){ //if there is no observation; sensor sends -1000+error when there is no pos data, they must be ignored
    return false;
  }

  //if there is observation, there is a condition to add observation to data
  //the difference between positions of the robot observed at this observation and previous observation must be more than threshold,
  //   if there is not previous observation, this condition is not necessary, observation is valid.
  int prev_t = lastSeen[i][j][0];//newest observation time

  if(prev_t == -1){//if there is not previous observation
    return true;//it's valid
  }

  else{//two conditions must be checked
    int index_prev_t = prev_t%sizeP;//previous observation time index
    double prev_x = robotsSeen[index_prev_t][i][j][0];//x at previous observation
    double prev_y = robotsSeen[index_prev_t][i][j][1];//y at previous observation
    double x = robotsSeen[index_t][i][j][0];//x at this observation
    double y = robotsSeen[index_t][i][j][1];//y at this observation
    double dist = pow(x-prev_x,2) + pow(y-prev_y,2);//distance
    if(dist>DIST_THRESHOLD){//if condition holds, it's valid
      //cout << i << "--> " << j << endl;
      //cout << "prev: " <<  prev_x << " " << prev_y << endl;
      //cout << "curr: " <<  x << " " << y << endl;
      return true;//it's valid
    }
    else{
      return false;//it's not valid
    }
  }

}

void RosThread::checkLastSeen(){
  //checks and deletes old observation data, it is called before each main loop
  for(int i=0;i<n;i++){//observer robot
    for(int j=0;j<n;j++){//observed robot
      if(lastSeen[i][j][0] !=-1){//index 0 is the newest observation time; if it is -1 (empty), there is not any observation saved and it's not necessary to check data
        for(int k=0;k<sizeT;k++){//for each observations
          if(t-lastSeen[i][j][k] > sizeP-1){//if time difference is more than the threshold (observation time capacity; at this case it is 100 (10 seconds, 10 data for each second) )
            lastSeen[i][j][k] = -1; //deletes old data
          }
        }
      }
    }
  }
}

void RosThread::calculateTransform1(){
  /*
  Suppose robot i observes robot j at time t1 and t2.
  The position of robot j at time t1 and t2 with respect to initial
  robot i and robot j frames are calculated
  */
  double dxi,dyi,dxj,dyj,thetai,thetaj,theta,dx,dy,dx2,dy2;
  int t2,t1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if((lastSeen[i][j][1] !=-1) && (i!=j)){//at least there are 2 observations and they are different robots
        //robotsSeen[index_t1][i][j] and robotsSeen[index_t2][i][j] are known from observations (aruco marker detection)
        //robotsSeen[index_t1][j][j] and robotsSeen[index_t2][j][j] are known from odometry
        t2 = lastSeen[i][j][0];//observation 2 time
        t1 = lastSeen[i][j][1];//observation 1 time
        int index_t2 = t2%sizeP;
        int index_t1 = t1%sizeP;

        dxi = robotsSeen[index_t2][i][j][0]-robotsSeen[index_t1][i][j][0];//difference at x axis wrt robot i frame
        dyi = robotsSeen[index_t2][i][j][1]-robotsSeen[index_t1][i][j][1];//difference at y axis wrt robot i frame
        dxj = robotsSeen[index_t2][j][j][0]-robotsSeen[index_t1][j][j][0];//difference at x axis wrt robot j frame
        dyj = robotsSeen[index_t2][j][j][1]-robotsSeen[index_t1][j][j][1];//difference at y axis wrt robot j frame
        thetai = atan2(dyi,dxi);//displacement angle wrt robot i frame
        thetaj = atan2(dyj,dxj);//displacement angle wrt robot j frame
        theta = thetai-thetaj;//angle difference
        anglesTr[i][j] = theta; //theta from i frame to j frame xi-->xj; angle x axis at frame i to x axis frame j
        anglesTr[j][i] = -theta; //theta from j frame to i frame xj-->xi

        //translation vector; position of j frame origin wrt i frame
        dx = robotsSeen[index_t2][i][j][0] - robotsSeen[index_t2][j][j][0]*cos(theta) + robotsSeen[index_t2][j][j][1]*sin(theta);
        dy = robotsSeen[index_t2][i][j][1] - robotsSeen[index_t2][j][j][0]*sin(theta) - robotsSeen[index_t2][j][j][1]*cos(theta);

        //position of j frame origin wrt i frame
        posTr[i][j][0] = dx;
        posTr[i][j][1] = dy;

        //translation vector; position of i frame origin wrt j frame
        dx2 = -cos(-theta)*dx + sin(-theta)*dy;
        dy2 = -sin(-theta)*dx - cos(-theta)*dy;

        //position of i frame origin wrt j frame
        posTr[j][i][0] = dx2;
        posTr[j][i][1] = dy2;

        //transformation is completed
        connected[i][j] = true;
        connected[j][i] = true;



        cout << " transform 1 for " << i << " ---------> " << j << endl;
        cout << i << "-->" << j << " theta tr: " << anglesTr[i][j] << " d tr: " << posTr[i][j][0]<< " "  << posTr[i][j][1] << endl;
        cout << j << "-->" << i << " theta tr: " << anglesTr[j][i] << " d tr: " << posTr[j][i][0]<< " "  << posTr[j][i][1] << endl;

      }
    }
  }
}

void RosThread::calculateTransform2(){
  /*
  Suppose robot i observes robot j at time t1 and
  robot j observes robot i at time t2.
  The position of robot j with respect to initial robot i at time t1 and
  the position of robot i with respect to initial robot j at time t2 are calculated
  */
  int t1,t2,index_t1,index_t2;
  double dxi,dyi,dxj,dyj,thetai,thetaj,theta,dx,dy,dx2,dy2;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(lastSeen[i][j][0] !=-1 && lastSeen[j][i][0] != -1 && (i!=j)){//robot i and robot j observe each others
        t1 = lastSeen[i][j][0];//observation 1 time; robot i observes robot j at t1
        t2 = lastSeen[j][i][0];//observation 2 time; robot j observes robot i at t2
        int index_t2 = t2%sizeP;
        int index_t1 = t1%sizeP;
        dxi = robotsSeen[index_t2][i][i][0]-robotsSeen[index_t1][i][j][0];//difference at x axis wrt robot i frame
        dyi = robotsSeen[index_t2][i][i][1]-robotsSeen[index_t1][i][j][1];//difference at y axis wrt robot i frame
        dxj = robotsSeen[index_t2][j][i][0]-robotsSeen[index_t1][j][j][0];//difference at x axis wrt robot j frame
        dyj = robotsSeen[index_t2][j][i][1]-robotsSeen[index_t1][j][j][1];//difference at y axis wrt robot j frame
        thetai = atan2(dyi,dxi);//angle wrt robot i frame
        thetaj = atan2(dyj,dxj);//angle wrt robot i frame
        theta = thetai-thetaj;//angle difference
        anglesTr[i][j] = theta; //theta from i frame to j frame xi-->xj; angle x axis at frame i to x axis frame j
        anglesTr[j][i] = -theta; //theta from j frame to i frame xj-->xi

        //translation vector; position of j frame origin wrt i frame
        dx = robotsSeen[index_t1][i][j][0] - robotsSeen[index_t1][j][j][0]*cos(theta) + robotsSeen[index_t1][j][j][1]*sin(theta);
        dy = robotsSeen[index_t1][i][j][1] - robotsSeen[index_t1][j][j][0]*sin(theta) - robotsSeen[index_t1][j][j][1]*cos(theta);

        //position of j frame origin wrt i frame
        posTr[i][j][0] = dx;
        posTr[i][j][1] = dy;

        //translation vector; position of i frame origin wrt j frame
        dx2 = -cos(-theta)*dx + sin(-theta)*dy;
        dy2 = -sin(-theta)*dx - cos(-theta)*dy;

        //position of i frame origin wrt j frame
        posTr[j][i][0] = dx2;
        posTr[j][i][1] = dy2;

        //transformation is completed
        connected[i][j] = true;
        connected[j][i] = true;



        cout << " transform 2 for " << i << " ---------> " << j << endl;
        cout << i << "-->" << j << " theta tr: " << anglesTr[i][j] << " d tr: " << posTr[i][j][0]<< " "  << posTr[i][j][1] << endl;
        cout << j << "-->" << i << " theta tr: " << anglesTr[j][i] << " d tr: " << posTr[j][i][0]<< " "  << posTr[j][i][1] << endl;



      }
    }
  }
}

void RosThread::completeTransform(){
  //if frame i - frame j and frame j - frame i transformaions are known and frame i- frame k transformation is unknown; it can be calculated
  bool notCompleted = false;
  for(int i=0;i<n;i++){//for each robot
    for(int j=0;j<n;j++){//for each robot
      if(i!=j && !connected[i][j]){
        notCompleted = true;
      }
      if(connected[i][j]){//for all connected robot pairs; robot i and robot j are connected
        for(int k=0;k<n;k++){//for other robots
          if(connected[j][k] && !connected[i][k] && i!=k){//if robot j and robot k are connected but robot i and robot k are not connected
            double theta,dx,dy,dx2,dy2;
            theta = anglesTr[i][j] + anglesTr[j][k];
            anglesTr[i][k] = theta; //theta from i frame to k frame xi-->xk; angle x axis at frame i to x axis frame k
            anglesTr[k][i] = -theta;
            //translation vector; position of k frame origin wrt i frame
            dx = posTr[i][j][0] + posTr[j][k][0]*cos(anglesTr[i][j]) - posTr[j][k][1]*sin(anglesTr[i][j]);
            dy = posTr[i][j][1] + posTr[j][k][0]*sin(anglesTr[i][j]) + posTr[j][k][1]*cos(anglesTr[i][j]);
            //position of k frame origin wrt i frame
            posTr[i][k][0] = dx;
            posTr[i][k][1] = dy;

            //translation vector; position of i frame origin wrt k frame
            dx2 = -cos(-theta)*dx + sin(-theta)*dy;
            dy2 = -sin(-theta)*dx - cos(-theta)*dy;
            //position of i frame origin wrt k frame
            posTr[k][i][0] = dx2;
            posTr[k][i][1] = dy2;

            connected[i][k] = true;
            connected[k][i] = true;



            cout << " transform 3 for " << i << " ---------> " << k << endl;
            cout << i << "-->" << k << " theta tr: " << anglesTr[i][k] << " d tr: " << posTr[i][k][0]<< " "  << posTr[i][k][1] << endl;
            cout << k << "-->" << i << " theta tr: " << anglesTr[k][i] << " d tr: " << posTr[k][i][0]<< " "  << posTr[k][i][1] << endl;

          }
        }
      }
    }
  }
  completed = !notCompleted;
}

void RosThread::calculateRobotPos(){
  //calculates robot positions wrt other initial robot frames using odometry data and frame transformations
  double xi,yi, xj, yj, thetaTr,xTr,yTr;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(connected[i][j]){//if transformation is known
        thetaTr = anglesTr[i][j];//angle
        xTr = posTr[i][j][0];//translation x
        yTr = posTr[i][j][1];//translation y
        xj = robotsSeen[index_t][j][j][0];//odometry data >> pos wrt its initial frame
        yj = robotsSeen[index_t][j][j][1];
        xi = xTr + cos(thetaTr)*xj - sin(thetaTr)*yj;//position wrt another initial frame
        yi = yTr + sin(thetaTr)*xj + cos(thetaTr)*yj;
        cout << "robot pos: " << i << "-->" << j <<  " d: " << xi << " "  << yi << endl;

        posRobots[i][j][0] = xi;
        posRobots[i][j][1] = yi;

      }
      else{
        if(i!=j){//if it's unknown, it is -1000
          posRobots[i][j][0] = -1000;
          posRobots[i][j][1] = -1000;
        }
      }
    }
  }

}


void RosThread::work(){

  //publishers for robot positions wrt each initial robot frames
  ros::Publisher pos_pub0 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos0", 100);
  ros::Publisher pos_pub1 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos1", 100);
  ros::Publisher pos_pub2 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos2", 100);
  ros::Publisher pos_pub3 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos3", 100);
  ros::Publisher pos_pub4 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos4", 100);

  //publisher for whether transformations are completed
  ros::Publisher transform_pub = trPub.advertise<std_msgs::Bool>("transformCompleted",100);


  /*
  //subscribers for positions, headings, ID's of robots detected from turtlesim
  ros::Subscriber sensor_sub1 = sensorSub.subscribe("/pos0",1000,&RosThread::sensorCallback0,this);
  ros::Subscriber sensor_sub2 = sensorSub.subscribe("/pos1",1000,&RosThread::sensorCallback1,this);
  ros::Subscriber sensor_sub3 = sensorSub.subscribe("/pos2",1000,&RosThread::sensorCallback2,this);
  */

  //subscribers for positions, headings, ID's of robots detected from gazebo
  ros::Subscriber aruco_sub1 = sensorSub.subscribe("/detected_aruco1",1000,&RosThread::arucoCallback1,this);
  ros::Subscriber aruco_sub2 = sensorSub.subscribe("/detected_aruco2",1000,&RosThread::arucoCallback2,this);
  ros::Subscriber aruco_sub3 = sensorSub.subscribe("/detected_aruco3",1000,&RosThread::arucoCallback3,this);
  ros::Subscriber aruco_sub4 = sensorSub.subscribe("/detected_aruco4",1000,&RosThread::arucoCallback4,this);
  ros::Subscriber aruco_sub5 = sensorSub.subscribe("/detected_aruco5",1000,&RosThread::arucoCallback5,this);

  //subscribers for odometry from gazebo
  ros::Subscriber odom1sub = sensorSub.subscribe("/odom1",1000,&RosThread::odom1callback,this);
  ros::Subscriber odom2sub = sensorSub.subscribe("/odom2",1000,&RosThread::odom2callback,this);
  ros::Subscriber odom3sub = sensorSub.subscribe("/odom3",1000,&RosThread::odom3callback,this);
  ros::Subscriber odom4sub = sensorSub.subscribe("/odom4",1000,&RosThread::odom4callback,this);
  ros::Subscriber odom5sub = sensorSub.subscribe("/odom5",1000,&RosThread::odom5callback,this);




  ros::Rate loop_rate(10);

  while (ros::ok()){

    double t0 =ros::Time::now().toSec();//start time to check delay
    checkLastSeen();//checks and deletes old observation data
    index_t = t%sizeP;//time index
    //t always increases with 10 hz, to use it effectively, it is encrypted using modulo operator
    cout << "time: " << t << endl;

    loop_rate.sleep();
    ros::spinOnce();

    std_msgs::Bool transformIsCompleted;//message whether all transformations are calculated

    if(completed){
      transformIsCompleted.data = true;
      cout << "completed" << endl;

    }
    else{
      transformIsCompleted.data = false;
      cout << "not completed" << endl;
    }
    transform_pub.publish(transformIsCompleted);//publishes message

    /*for(int i=0;i<n;i++){
      for(int j=0; j<n; j++){
       cout << "last seen: " << i << " -->> " << j << " " << lastSeen[i][j][0] << endl;
      }
    }*/


    calculateTransform1();//calculates transformations using method 1
    calculateTransform2();//calculates transformations using method 2
    completeTransform();//completes transformations
    calculateRobotPos();//calculates robot positions using transformations and odometry data

    geometry_msgs::PoseArray posRobots0;
    geometry_msgs::PoseArray posRobots1;
    geometry_msgs::PoseArray posRobots2;
    geometry_msgs::PoseArray posRobots3;
    geometry_msgs::PoseArray posRobots4;

    posRobots0.poses.resize(n);
    posRobots1.poses.resize(n);
    posRobots2.poses.resize(n);
    posRobots3.poses.resize(n);
    posRobots4.poses.resize(n);

    //robot positions wrt robot 0
    for(int j=0;j<n;j++){
      posRobots0.poses[j].position.x = posRobots[0][j][0];
      posRobots0.poses[j].position.y = posRobots[0][j][1];
    }

    pos_pub0.publish(posRobots0);

    //robot positions wrt robot 1
    for(int j=0;j<n;j++){
      posRobots1.poses[j].position.x = posRobots[1][j][0];
      posRobots1.poses[j].position.y = posRobots[1][j][1];
    }

    pos_pub1.publish(posRobots1);

    //robot positions wrt robot2
    for(int j=0;j<n;j++){
      posRobots2.poses[j].position.x = posRobots[2][j][0];
      posRobots2.poses[j].position.y = posRobots[2][j][1];
    }

    pos_pub2.publish(posRobots2);

    //robot positions wrt robot 3
    for(int j=0;j<n;j++){
      posRobots3.poses[j].position.x = posRobots[3][j][0];
      posRobots3.poses[j].position.y = posRobots[3][j][1];
    }

    pos_pub3.publish(posRobots3);

    //robot positions wrt robot4
    for(int j=0;j<n;j++){
      posRobots4.poses[j].position.x = posRobots[4][j][0];
      posRobots4.poses[j].position.y = posRobots[4][j][1];
    }

    pos_pub4.publish(posRobots4);




    //double t1 =ros::Time::now().toSec();
    //cout << "delay: " << t1-t0 << " second" << endl;

    t++;
    //cout << endl;

  }

}
