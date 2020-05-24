#include "rosThread.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <geometry_msgs/PoseArray.h>

using namespace std;



RosThread::RosThread(){

}

RosThread::~RosThread(){

}

void RosThread::calcCallback0(const geometry_msgs::PoseArray::ConstPtr& msg){
  int id = 0;
  for(int j=0;j<n;j++){
    calcPos[id][j][0] = msg->poses[j].position.x;
    calcPos[id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::calcCallback1(const geometry_msgs::PoseArray::ConstPtr& msg){
  int id = 1;
  for(int j=0;j<n;j++){
    calcPos[id][j][0] = msg->poses[j].position.x;
    calcPos[id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::calcCallback2(const geometry_msgs::PoseArray::ConstPtr& msg){
  int id = 2;
  for(int j=0;j<n;j++){
    calcPos[id][j][0] = msg->poses[j].position.x;
    calcPos[id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::realCallback0(const geometry_msgs::PoseArray::ConstPtr& msg){
  int id = 0;
  for(int j=0;j<n;j++){
    realPos[id][j][0] = msg->poses[j].position.x;
    realPos[id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::realCallback1(const geometry_msgs::PoseArray::ConstPtr& msg){
  int id = 1;
  for(int j=0;j<n;j++){
    realPos[id][j][0] = msg->poses[j].position.x;
    realPos[id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::realCallback2(const geometry_msgs::PoseArray::ConstPtr& msg){
  int id = 2;
  for(int j=0;j<n;j++){
    realPos[id][j][0] = msg->poses[j].position.x;
    realPos[id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::errorCalculate(){
  double dx,dy,d;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(calcPos[i][j][0]!=-1000){
        dx = calcPos[i][j][0] - realPos[i][j][0];
        dy = calcPos[i][j][1] - realPos[i][j][1];
        d = sqrt(pow(dx,2)+pow(dy,2));
        cout << i << "-->" << j << " error dx dy d: " << dx << " " << dy << " " << d << endl;
      }
    }
  }
}



void RosThread::work(){

  ros::Subscriber calc_sub1 = poseSub.subscribe("/completedPos0",1000,&RosThread::calcCallback0,this);
  ros::Subscriber calc_sub2 = poseSub.subscribe("/completedPos1",1000,&RosThread::calcCallback1,this);
  ros::Subscriber calc_sub3 = poseSub.subscribe("/completedPos2",1000,&RosThread::calcCallback2,this);

  ros::Subscriber real_sub1 = poseSub.subscribe("/realPos0",1000,&RosThread::realCallback0,this);
  ros::Subscriber real_sub2 = poseSub.subscribe("/realPos1",1000,&RosThread::realCallback1,this);
  ros::Subscriber real_sub3 = poseSub.subscribe("/realPos2",1000,&RosThread::realCallback2,this);



  ros::Rate loop_rate(10);


  while (ros::ok()){

    errorCalculate();



    ros::spinOnce();

    loop_rate.sleep();

  }



}
