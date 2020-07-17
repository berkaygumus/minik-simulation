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
          robotsSeen[tt][i][j][k] = -1000;
        }
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      connected[i][j] = false;
      for(int k=0;k<sizeT;k++){
        lastSeen[i][j][k] = -1;
      }
    }
  }

  cout << "pos_calculator is created!" << endl;
}

RosThread::~RosThread(){

}

//////turtlesim
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


///// gazebo odometry


void RosThread::odom1callback(const geometry_msgs::Pose::ConstPtr& msg){
  int temp_id = 0;
    robotsSeen[index_t][temp_id][temp_id][0] = msg->position.x;
    robotsSeen[index_t][temp_id][temp_id][1] = msg->position.y;
    //cout << "2-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;
    if(checkSeenTime(temp_id,temp_id)){
        addSeenTime(temp_id,temp_id);
    }
  posRobots[temp_id][temp_id][0] = robotsSeen[index_t][temp_id][temp_id][0];
  posRobots[temp_id][temp_id][1] = robotsSeen[index_t][temp_id][temp_id][1];


}

void RosThread::odom2callback(const geometry_msgs::Pose::ConstPtr& msg){
  int temp_id = 1;
    robotsSeen[index_t][temp_id][temp_id][0] = msg->position.x;
    robotsSeen[index_t][temp_id][temp_id][1] = msg->position.y;
    //cout << "2-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;
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
    //cout << "2-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;
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
    //cout << "2-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;
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
    //cout << "2-->" << j << " " << msg->poses[j].position.x << " " << msg->poses[j].position.y << endl;
    if(checkSeenTime(temp_id,temp_id)){
        addSeenTime(temp_id,temp_id);
    }
  posRobots[temp_id][temp_id][0] = robotsSeen[index_t][temp_id][temp_id][0];
  posRobots[temp_id][temp_id][1] = robotsSeen[index_t][temp_id][temp_id][1];

}

///////////aruco callback

void RosThread::arucoCallback1(const ISLH_msgs::robotPositions::ConstPtr& msg){
  cout << "robot 0 observation //////////////////" << endl;
  for(int j=0;j<n;j++){
    //initialization, assumes that it is not seen
    if(j!=0){
      robotsSeen[index_t][0][j][0] = -1000;
      robotsSeen[index_t][0][j][1] = -1000;
    }

  }

  vector<geometry_msgs::Pose2D > msg_positions;//position vector for each marker
  vector<float> headings; //heading of the robot (the angle around z axis) vector for each marker
  vector<int> robot_IDs;//robotID vector

   msg_positions = msg->positions;
   headings = msg->directions;
   robot_IDs = msg->IDs;
   for(int i=0;i<msg_positions.size();i++){
     int temp_id = robot_IDs[i];
     double temp_x = msg_positions[i].x;
     double temp_y = msg_positions[i].y;
     double temp_theta = msg_positions[i].theta;
     cout << "ID: " << temp_id << " pos: " << temp_x << " " << temp_y << " " <<  temp_theta <<  endl;
     robotsSeen[index_t][0][temp_id][0] = temp_x;
     robotsSeen[index_t][0][temp_id][1] = temp_y;
     if(checkSeenTime(0,temp_id)){
         addSeenTime(0,temp_id);
     }
   }


}

void RosThread::arucoCallback2(const ISLH_msgs::robotPositions::ConstPtr& msg){
  cout << "robot 1 observation //////////////////" << endl;
  for(int j=0;j<n;j++){
    //initialization, assumes that it is not seen
    if(j!=1){
      robotsSeen[index_t][1][j][0] = -1000;
      robotsSeen[index_t][1][j][1] = -1000;
    }

  }

  vector<geometry_msgs::Pose2D > msg_positions;//position vector for each marker
  vector<float> headings; //heading of the robot (the angle around z axis) vector for each marker
  vector<int> robot_IDs;//robotID vector

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
    //initialization, assumes that it is not seen
    if(j!=2){
      robotsSeen[index_t][2][j][0] = -1000;
      robotsSeen[index_t][2][j][1] = -1000;
    }
  }

  vector<geometry_msgs::Pose2D > msg_positions;//position vector for each marker
  vector<float> headings; //heading of the robot (the angle around z axis) vector for each marker
  vector<int> robot_IDs;//robotID vector

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
    //initialization, assumes that it is not seen
    if(j!=3){
      robotsSeen[index_t][3][j][0] = -1000;
      robotsSeen[index_t][3][j][1] = -1000;
    }

  }

  vector<geometry_msgs::Pose2D > msg_positions;//position vector for each marker
  vector<float> headings; //heading of the robot (the angle around z axis) vector for each marker
  vector<int> robot_IDs;//robotID vector

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
    //initialization, assumes that it is not seen
    if(j!=4){
      robotsSeen[index_t][4][j][0] = -1000;
      robotsSeen[index_t][4][j][1] = -1000;
    }
  }

  vector<geometry_msgs::Pose2D > msg_positions;//position vector for each marker
  vector<float> headings; //heading of the robot (the angle around z axis) vector for each marker
  vector<int> robot_IDs;//robotID vector

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



void RosThread::addSeenTime(int i, int j){//it's valid only for SIZE_T 3
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

bool RosThread::checkSeenTime(int i, int j){
  //cout << "index t: " << index_t << endl;
  if(robotsSeen[index_t][i][j][0]<-890){ //sensor sends -1000+error when there is no pos data, they must be ignored
    return false;
  }

  int prev_t = lastSeen[i][j][0];

  if(prev_t == -1){
    return true;
  }

  else{
    int index_prev_t = prev_t%sizeP;
    double prev_x = robotsSeen[index_prev_t][i][j][0];
    double prev_y = robotsSeen[index_prev_t][i][j][1];
    double x = robotsSeen[index_t][i][j][0];
    double y = robotsSeen[index_t][i][j][1];
    double dist = pow(x-prev_x,2) + pow(y-prev_y,2);
    if(dist>DIST_THRESHOLD){
      cout << i << "--> " << j << endl;
      cout << "prev: " <<  prev_x << " " << prev_y << endl;
      cout << "curr: " <<  x << " " << y << endl;
      return true;
    }
    else{
      return false;
    }
  }

}

void RosThread::checkLastSeen(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(lastSeen[i][j][0] !=-1){
        for(int k=0;k<sizeT;k++){
          if(t-lastSeen[i][j][k] > sizeP-1){
            lastSeen[i][j][k] = -1;
          }
        }
      }
    }
  }
}

void RosThread::calculateTransform1(){
  double dxi,dyi,dxj,dyj,thetai,thetaj,theta,dx,dy,dx2,dy2;
  int t2,t1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if((lastSeen[i][j][1] !=-1) && (i!=j)){
        t2 = lastSeen[i][j][0];
        t1 = lastSeen[i][j][1];
        int index_t2 = t2%sizeP;
        int index_t1 = t1%sizeP;

        dxi = robotsSeen[index_t2][i][j][0]-robotsSeen[index_t1][i][j][0];
        dyi = robotsSeen[index_t2][i][j][1]-robotsSeen[index_t1][i][j][1];
        dxj = robotsSeen[index_t2][j][j][0]-robotsSeen[index_t1][j][j][0];
        dyj = robotsSeen[index_t2][j][j][1]-robotsSeen[index_t1][j][j][1];
        thetai = atan2(dyi,dxi);
        thetaj = atan2(dyj,dxj);
        theta = thetai-thetaj;
        anglesTr[i][j] = theta; //theta from i to j   i-->j
        anglesTr[j][i] = -theta;

        dx = robotsSeen[index_t2][i][j][0] - robotsSeen[index_t2][j][j][0]*cos(theta) + robotsSeen[index_t2][j][j][1]*sin(theta);
        dy = robotsSeen[index_t2][i][j][1] - robotsSeen[index_t2][j][j][0]*sin(theta) - robotsSeen[index_t2][j][j][1]*cos(theta);

        posTr[i][j][0] = dx;
        posTr[i][j][1] = dy;

        dx2 = -cos(-theta)*dx + sin(-theta)*dy;
        dy2 = -sin(-theta)*dx - cos(-theta)*dy;

        posTr[j][i][0] = dx2;
        posTr[j][i][1] = dy2;

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
  int t1,t2,index_t1,index_t2;
  double dxi,dyi,dxj,dyj,thetai,thetaj,theta,dx,dy,dx2,dy2;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(lastSeen[i][j][0] !=-1 && lastSeen[j][i][0] != -1 && (i!=j)){
        t1 = lastSeen[i][j][0];
        t2 = lastSeen[j][i][0];
        int index_t2 = t2%sizeP;
        int index_t1 = t1%sizeP;
        dxi = robotsSeen[index_t2][i][i][0]-robotsSeen[index_t1][i][j][0];
        dyi = robotsSeen[index_t2][i][i][1]-robotsSeen[index_t1][i][j][1];
        dxj = robotsSeen[index_t2][j][i][0]-robotsSeen[index_t1][j][j][0];
        dyj = robotsSeen[index_t2][j][i][1]-robotsSeen[index_t1][j][j][1];
        thetai = atan2(dyi,dxi);
        thetaj = atan2(dyj,dxj);
        theta = thetai-thetaj;
        anglesTr[i][j] = theta; //theta from i to j   i-->j
        anglesTr[j][i] = -theta;

        dx = robotsSeen[index_t1][i][j][0] - robotsSeen[index_t1][j][j][0]*cos(theta) + robotsSeen[index_t1][j][j][1]*sin(theta);
        dy = robotsSeen[index_t1][i][j][1] - robotsSeen[index_t1][j][j][0]*sin(theta) - robotsSeen[index_t1][j][j][1]*cos(theta);

        posTr[i][j][0] = dx;
        posTr[i][j][1] = dy;

        dx2 = -cos(-theta)*dx + sin(-theta)*dy;
        dy2 = -sin(-theta)*dx - cos(-theta)*dy;

        posTr[j][i][0] = dx2;
        posTr[j][i][1] = dy2;

        connected[i][j] = true;
        connected[j][i] = true;



        cout << " transform 2 for " << i << " ---------> " << j << endl;
        cout << i << "-->" << j << " theta tr: " << anglesTr[i][j] << " d tr: " << posTr[i][j][0]<< " "  << posTr[i][j][1] << endl;
        cout << j << "-->" << i << " theta tr: " << anglesTr[j][i] << " d tr: " << posTr[j][i][0]<< " "  << posTr[j][i][1] << endl;



      }
    }
  }
}

//depth first search or a star algortihm
void RosThread::completeTransform(){
  bool notCompleted = false;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j && !connected[i][j]){
        notCompleted = true;
      }
      if(connected[i][j]){
        for(int k=0;k<n;k++){
          if(connected[j][k] && !connected[i][k] && i!=k){
            double theta,dx,dy,dx2,dy2;
            theta = anglesTr[i][j] + anglesTr[j][k];
            anglesTr[i][k] = theta;
            anglesTr[k][i] = -theta;
            dx = posTr[i][j][0] + posTr[j][k][0]*cos(anglesTr[i][j]) - posTr[j][k][1]*sin(anglesTr[i][j]);
            dy = posTr[i][j][1] + posTr[j][k][0]*sin(anglesTr[i][j]) + posTr[j][k][1]*cos(anglesTr[i][j]);
            posTr[i][k][0] = dx;
            posTr[i][k][1] = dy;

            dx2 = -cos(-theta)*dx + sin(-theta)*dy;
            dy2 = -sin(-theta)*dx - cos(-theta)*dy;

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
  double xi,yi, xj, yj, thetaTr,xTr,yTr;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(connected[i][j]){
        thetaTr = anglesTr[i][j];
        xTr = posTr[i][j][0];
        yTr = posTr[i][j][1];
        xj = robotsSeen[index_t][j][j][0];
        yj = robotsSeen[index_t][j][j][1];
        xi = xTr + cos(thetaTr)*xj - sin(thetaTr)*yj;
        yi = yTr + sin(thetaTr)*xj + cos(thetaTr)*yj;
        cout << "robot pos: " << i << "-->" << j <<  " d: " << xi << " "  << yi << endl;

        posRobots[i][j][0] = xi;
        posRobots[i][j][1] = yi;

      }
      else{
        if(i!=j){
          posRobots[i][j][0] = -1000;
          posRobots[i][j][1] = -1000;
        }
      }
    }
  }

}


void RosThread::work(){

  ros::Publisher pos_pub0 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos0", 100);
  ros::Publisher pos_pub1 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos1", 100);
  ros::Publisher pos_pub2 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos2", 100);
  ros::Publisher pos_pub3 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos3", 100);
  ros::Publisher pos_pub4 = posPub.advertise<geometry_msgs::PoseArray>("/completedPos4", 100);
  ros::Publisher transform_pub = trPub.advertise<std_msgs::Bool>("transformCompleted",100);

//////turtlesim
/*
  ros::Subscriber sensor_sub1 = sensorSub.subscribe("/pos0",1000,&RosThread::sensorCallback0,this);
  ros::Subscriber sensor_sub2 = sensorSub.subscribe("/pos1",1000,&RosThread::sensorCallback1,this);
  ros::Subscriber sensor_sub3 = sensorSub.subscribe("/pos2",1000,&RosThread::sensorCallback2,this);
*/

//aruco marker sub
  ros::Subscriber aruco_sub1 = sensorSub.subscribe("/detected_aruco1",1000,&RosThread::arucoCallback1,this);
  ros::Subscriber aruco_sub2 = sensorSub.subscribe("/detected_aruco2",1000,&RosThread::arucoCallback2,this);
  ros::Subscriber aruco_sub3 = sensorSub.subscribe("/detected_aruco3",1000,&RosThread::arucoCallback3,this);
  ros::Subscriber aruco_sub4 = sensorSub.subscribe("/detected_aruco4",1000,&RosThread::arucoCallback4,this);
  ros::Subscriber aruco_sub5 = sensorSub.subscribe("/detected_aruco5",1000,&RosThread::arucoCallback5,this);

//gazebo odom
  ros::Subscriber odom1sub = sensorSub.subscribe("/odom1",1000,&RosThread::odom1callback,this);
  ros::Subscriber odom2sub = sensorSub.subscribe("/odom2",1000,&RosThread::odom2callback,this);
  ros::Subscriber odom3sub = sensorSub.subscribe("/odom3",1000,&RosThread::odom3callback,this);
  ros::Subscriber odom4sub = sensorSub.subscribe("/odom4",1000,&RosThread::odom4callback,this);
  ros::Subscriber odom5sub = sensorSub.subscribe("/odom5",1000,&RosThread::odom5callback,this);




  ros::Rate loop_rate(10);

  while (ros::ok()){
    //cout << "connected 0 0 " << connected[0][0];


    double t0 =ros::Time::now().toSec();
    checkLastSeen();
    index_t = t%sizeP;
    cout << "time: " << t << endl;

    loop_rate.sleep();
    ros::spinOnce();

    std_msgs::Bool transformIsCompleted;

    if(completed){
      transformIsCompleted.data = true;
      cout << "completed" << endl;

    }
    else{
      transformIsCompleted.data = false;
      cout << "not completed" << endl;
    }
    transform_pub.publish(transformIsCompleted);

    /*for(int i=0;i<n;i++){
      for(int j=0; j<n; j++){
       cout << "last seen: " << i << " -->> " << j << " " << lastSeen[i][j][0] << endl;
      }
    }*/


    calculateTransform1();
    calculateTransform2();
    completeTransform();
    calculateRobotPos();

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

    //robot 0
    for(int j=0;j<n;j++){
      posRobots0.poses[j].position.x = posRobots[0][j][0];
      posRobots0.poses[j].position.y = posRobots[0][j][1];
    }

    pos_pub0.publish(posRobots0);

    //robot 1
    for(int j=0;j<n;j++){
      posRobots1.poses[j].position.x = posRobots[1][j][0];
      posRobots1.poses[j].position.y = posRobots[1][j][1];
    }

    pos_pub1.publish(posRobots1);

    //robot2
    for(int j=0;j<n;j++){
      posRobots2.poses[j].position.x = posRobots[2][j][0];
      posRobots2.poses[j].position.y = posRobots[2][j][1];
    }

    pos_pub2.publish(posRobots2);

    //robot 3
    for(int j=0;j<n;j++){
      posRobots3.poses[j].position.x = posRobots[3][j][0];
      posRobots3.poses[j].position.y = posRobots[3][j][1];
    }

    pos_pub3.publish(posRobots3);

    //robot4
    for(int j=0;j<n;j++){
      posRobots4.poses[j].position.x = posRobots[4][j][0];
      posRobots4.poses[j].position.y = posRobots[4][j][1];
    }

    pos_pub4.publish(posRobots4);




    double t1 =ros::Time::now().toSec();
    //cout << "delay: " << t1-t0 << " second" << endl;

    t++;
    //cout << endl;



  }




}
