#include "rosThread.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#define FOV 98
#define ERROR 2
using namespace std;



RosThread::RosThread(int id){
  this->id = id;
}

RosThread::~RosThread(){

}



void RosThread::poseOdomCallback0(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[0][0] = msg->x;
  b[0][1] = msg->y;
  b[0][2] = msg->theta;

  if(flag==0){
    initPos[0][0] = msg->x;
    initPos[0][1] = msg->y;
    initPos[0][2] = msg->theta;
  }

  if(id==0){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[0]=1;
}

void RosThread::poseOdomCallback1(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[1][0] = msg->x;
  b[1][1] = msg->y;
  b[1][2] = msg->theta;

  if(flag==0){
    initPos[1][0] = msg->x;
    initPos[1][1] = msg->y;
    initPos[1][2] = msg->theta;
  }

  if(id==1){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[1]=1;
}

void RosThread::poseOdomCallback2(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[2][0] = msg->x;
  b[2][1] = msg->y;
  b[2][2] = msg->theta;

  if(flag==0){
    initPos[2][0] = msg->x;
    initPos[2][1] = msg->y;
    initPos[2][2] = msg->theta;
  }

  if(id==2){
    //ROS_INFO("id 2");
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[2]=1;
}

void RosThread::poseOdomCallback3(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[3][0] = msg->x;
  b[3][1] = msg->y;
  b[3][2] = msg->theta;

  if(flag==0){
    initPos[3][0] = msg->x;
    initPos[3][1] = msg->y;
    initPos[3][2] = msg->theta;
  }

  if(id==3){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[3]=1;
}

void RosThread::poseOdomCallback4(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[4][0] = msg->x;
  b[4][1] = msg->y;
  b[4][2] = msg->theta;

  if(flag==0){
    initPos[4][0] = msg->x;
    initPos[4][1] = msg->y;
    initPos[4][2] = msg->theta;
  }

  if(id==4){
    //ROS_INFO("id 2");
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[4]=1;
}

void RosThread::poseOdomCallback5(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[5][0] = msg->x;
  b[5][1] = msg->y;
  b[5][2] = msg->theta;

  if(flag==0){
    initPos[5][0] = msg->x;
    initPos[5][1] = msg->y;
    initPos[5][2] = msg->theta;
  }

  if(id==5){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[5]=1;
}

void RosThread::poseOdomCallback6(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[6][0] = msg->x;
  b[6][1] = msg->y;
  b[6][2] = msg->theta;

  if(flag==0){
    initPos[6][0] = msg->x;
    initPos[6][1] = msg->y;
    initPos[6][2] = msg->theta;
  }

  if(id==6){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[6]=1;
}

bool RosThread::checkRange(int r1, int r2){

  if(r1==r2){
    return true;
  }
  //if r2 is at the range of r1
  //r1 --> r2
  double thetaT = atan2(b[r2][1]-b[r1][1],b[r2][0]-b[r1][0]);
  double thetaR = b[r1][2];
  //cout << "THETAT " << thetaT << " " << thetaR << endl;
  double diff = (thetaT-thetaR)*180/PI;
  //cout << "diff1 " << diff;
  if(diff>180){
    diff = diff -360;
  }
  if(diff<-180){
    diff = diff +360;
  }
  //cout << " diff2 " << diff ;
  diff = abs(diff);
  //cout << " diff3 " << diff << endl;
  return diff < FOV/2 ;
}

vector<double> RosThread::calculatePos(int i, int j){
  //for initial frame
  double initX = initPos[i][0];
  double initY = initPos[i][1];
  double initTheta = initPos[i][2];

  //for the position wrt world frame
  double posX0 = b[j][0];
  double posY0 = b[j][1];

  //for the position wrt frame robot r
  vector<double> posR;
  posR.resize(2);


  //i-->j
  double rot[3][3] = {{cos(initTheta),sin(initTheta),0},{-sin(initTheta),cos(initTheta),0},{0,0,1}};
  double trans[3] = {posX0 - initX, posY0-initY,1};

  posR[0] = rot[0][0] * trans[0] + rot[0][1] * trans[1];
  posR[1] = rot[1][0] * trans[0] + rot[1][1] * trans[1];

  //cout << i <<"-->" << j << " pos: " << posR[0] << " " << posR[1] << endl;

  return posR;

}

void RosThread::publishPos(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      vector<double> tempPos;
      tempPos = RosThread::calculatePos(i, j);
      robotPosReal[i][j][0] = tempPos[0];
      robotPosReal[i][j][1] = tempPos[1];
      if(RosThread::checkRange(i,j)){
        if(i==j){
          robotsSeen[i][j][0] = tempPos[0];
          robotsSeen[i][j][1] = tempPos[1];
          cout <<"pos " << j << " wrt robot "<<i <<": "  << robotsSeen[i][j][0] << " " << robotsSeen[i][j][1] << endl;
        }
        else{
          robotsSeen[i][j][0] = tempPos[0] + addError(ERROR);
          robotsSeen[i][j][1] = tempPos[1] + addError(ERROR);
          cout <<"pos " << j << " wrt robot "<<i <<": "  << robotsSeen[i][j][0] << " " << robotsSeen[i][j][1] << endl;
        }

      }
      else{
        robotsSeen[i][j][0] = -1000;
        robotsSeen[i][j][1] = -1000;



        //cout << i << "--> " << j << " ---" << endl;
      }
    }
  }
  cout << endl;
}

double RosThread::addError(double maxError){
  //generates random error between -maxError and maxError
  double e = rand() %201; // (0,200) and d=1
  e = e/100; //(0,2) and d = 0.01
  e = e-1; // (-1,1) and d=0.01
  e = e*maxError; //(-maxError,+maxError)
  //cout << "error: " << e << endl;
  return e;



}

void RosThread::work(){

  ostringstream ss;
  ss << id +1;
  string name =  "turtle" + ss.str();

  ros::Publisher pos_pub0 = posPub.advertise<geometry_msgs::PoseArray>("/pos0", 100);
  ros::Publisher pos_pub1 = posPub.advertise<geometry_msgs::PoseArray>("/pos1", 100);
  ros::Publisher pos_pub2 = posPub.advertise<geometry_msgs::PoseArray>("/pos2", 100);
  ros::Publisher pos_odom0 = posPub.advertise<geometry_msgs::Pose>("/odom0",100);
  ros::Publisher pos_odom1 = posPub.advertise<geometry_msgs::Pose>("/odom1",100);
  ros::Publisher pos_odom2 = posPub.advertise<geometry_msgs::Pose>("/odom2",100);

  ros::Publisher realPos_pub0 = posPub.advertise<geometry_msgs::PoseArray>("/realPos0", 100);
  ros::Publisher realPos_pub1 = posPub.advertise<geometry_msgs::PoseArray>("/realPos1", 100);
  ros::Publisher realPos_pub2 = posPub.advertise<geometry_msgs::PoseArray>("/realPos2", 100);

  ros::Subscriber pose_odom_sub1 = poseOdomSub.subscribe("turtle1/pose",1000,&RosThread::poseOdomCallback0,this);
  ros::Subscriber pose_odom_sub2 = poseOdomSub.subscribe("turtle2/pose",1000,&RosThread::poseOdomCallback1,this);
  ros::Subscriber pose_odom_sub3 = poseOdomSub.subscribe("turtle3/pose",1000,&RosThread::poseOdomCallback2,this);
  ros::Subscriber pose_odom_sub4 = poseOdomSub.subscribe("turtle4/pose",1000,&RosThread::poseOdomCallback3,this);
  ros::Subscriber pose_odom_sub5 = poseOdomSub.subscribe("turtle5/pose",1000,&RosThread::poseOdomCallback4,this);
  ros::Subscriber pose_odom_sub6 = poseOdomSub.subscribe("turtle6/pose",1000,&RosThread::poseOdomCallback5,this);
  ros::Subscriber pose_odom_sub7 = poseOdomSub.subscribe("turtle7/pose",1000,&RosThread::poseOdomCallback6,this);



  ros::Rate loop_rate(10);

  while (ros::ok()){

    flag = 1;
    for(int i=0;i<N;i++){
      flag = flag * flagN[i];
    }

    if(flag==1){

      for(int i=0; i<N; i++){
        //ROS_INFO("b %d: %f , %f",i,b[i][0],b[i][1]);
        //cout << "init pos   " << i << ": " << initPos[i][0] << "  "<< initPos[i][1] << "  "<< initPos[i][2] << endl;
        cout << "pos "<<i <<"  wrt world frame: "<< b[i][0] << "  "<< b[i][1] << "  "<< b[i][2] << endl;


        //ROS_INFO("work ");
      }

      RosThread::publishPos();

      /*for(int i=0;i<n;i++){
        cout << i ;
        for(int j=0;j<n;j++){
          cout <<"--> " <<j <<":";
          for(int k=0;k<2;k++){
            cout << " " << robotsSeen[i][j][k];
          }
        }
        cout << endl;
      }*/

      geometry_msgs::Pose odomPos0;
      geometry_msgs::Pose odomPos1;
      geometry_msgs::Pose odomPos2;
      odomPos0.position.z = b[0][2] - initPos[0][2];
      odomPos1.position.z = b[1][2] - initPos[1][2];
      odomPos2.position.z = b[2][2] - initPos[2][2];
      pos_odom0.publish(odomPos0);
      pos_odom1.publish(odomPos1);
      pos_odom2.publish(odomPos2);



      geometry_msgs::PoseArray positions0;
      geometry_msgs::PoseArray positions1;
      geometry_msgs::PoseArray positions2;

      positions0.poses.resize(n);
      positions1.poses.resize(n);
      positions2.poses.resize(n);

      geometry_msgs::PoseArray realPositions0;
      geometry_msgs::PoseArray realPositions1;
      geometry_msgs::PoseArray realPositions2;

      realPositions0.poses.resize(n);
      realPositions1.poses.resize(n);
      realPositions2.poses.resize(n);


      //robot 0
      for(int j=0;j<n;j++){
        positions0.poses[j].position.x = robotsSeen[0][j][0];
        positions0.poses[j].position.y = robotsSeen[0][j][1];
        realPositions0.poses[j].position.x = robotPosReal[0][j][0];
        realPositions0.poses[j].position.y = robotPosReal[0][j][1];
      }

      pos_pub0.publish(positions0);
      realPos_pub0.publish(realPositions0);


      //robot 1
      for(int j=0;j<n;j++){
        positions1.poses[j].position.x = robotsSeen[1][j][0];
        positions1.poses[j].position.y = robotsSeen[1][j][1];
        realPositions1.poses[j].position.x = robotPosReal[1][j][0];
        realPositions1.poses[j].position.y = robotPosReal[1][j][1];
      }

      pos_pub1.publish(positions1);
      realPos_pub1.publish(realPositions1);

      //robot2
      for(int j=0;j<n;j++){
        positions2.poses[j].position.x = robotsSeen[2][j][0];
        positions2.poses[j].position.y = robotsSeen[2][j][1];
        realPositions2.poses[j].position.x = robotPosReal[2][j][0];
        realPositions2.poses[j].position.y = robotPosReal[2][j][1];
      }

      pos_pub2.publish(positions2);
      realPos_pub2.publish(realPositions2);


    }
    else{

      ROS_INFO("waiting...");
    }




    ros::spinOnce();

    loop_rate.sleep();

  }



}
