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

/*double OdomPublisher::orientation2theta(double x, double y, double z, double w){
  double siny_cosp = 2*(w*z + x*y);
  double cosy_cosp = 1 - 2*(y*y + z*z);
  double theta = atan2(siny_cosp,cosy_cosp);
  return theta;
}*/



void OdomPublisher::gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr& msg){
  double temp_x = msg->pose.pose.position.x;
  double temp_y = msg->pose.pose.position.y;

  tf::Quaternion q(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y,
                     msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  tf::Matrix3x3 m(q);
  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);

  double temp_theta = yaw;

  if(flag==0){
    initPos[0][0] = temp_x;
    initPos[0][1] = temp_y;
    initPos[0][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  }
  pos[0][0] = temp_x;
  pos[0][1] = temp_y;
  pos[0][2] = temp_theta;//orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);

  flagN[0]=1;

}

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

vector<double> OdomPublisher::calculatePos(int i){
  //for initial frame
  double initX = initPos[i][0];
  double initY = initPos[i][1];
  double initTheta = initPos[i][2];

  //for the position wrt world frame
  double posX0 = pos[i][0];
  double posY0 = pos[i][1];
  double posTheta0 = pos[i][2];

  //for the position wrt frame robot r
  vector<double> posR;
  posR.resize(3);


  //i-->j
  double rot[3][3] = {{cos(initTheta),sin(initTheta),0},{-sin(initTheta),cos(initTheta),0},{0,0,1}};
  double trans[3] = {posX0 - initX, posY0-initY,1};

  posR[0] = rot[0][0] * trans[0] + rot[0][1] * trans[1];
  posR[1] = rot[1][0] * trans[0] + rot[1][1] * trans[1];
  posR[2] = posTheta0 - initTheta;

  //cout << i <<"-->" << j << " pos: " << posR[0] << " " << posR[1] << endl;

  return posR;

}



void OdomPublisher::work(){

  ros::Publisher pos_odom1 = posPub.advertise<geometry_msgs::Pose>("/odom1",100);
  ros::Publisher pos_odom2 = posPub.advertise<geometry_msgs::Pose>("/odom2",100);
  ros::Publisher pos_odom3 = posPub.advertise<geometry_msgs::Pose>("/odom3",100);

  ros::Subscriber calc_sub1 = poseSub.subscribe("/robot1/odom",1000,&OdomPublisher::gazeboOdomCallback1,this);
  ros::Subscriber calc_sub2 = poseSub.subscribe("/robot2/odom",1000,&OdomPublisher::gazeboOdomCallback2,this);
  ros::Subscriber calc_sub3 = poseSub.subscribe("/robot3/odom",1000,&OdomPublisher::gazeboOdomCallback3,this);
  ros::Rate loop_rate(10);

  while (ros::ok()){

    flag = 1;
    for(int i=0;i<N;i++){
      flag = flag * flagN[i];
    }

    if(flag==1){

      vector<double> odom1 = calculatePos(0);
      vector<double> odom2 = calculatePos(1);
      vector<double> odom3 = calculatePos(2);

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

      pos_odom1.publish(odomPos1);
      pos_odom2.publish(odomPos2);
      pos_odom3.publish(odomPos3);



    }
    else{

      ROS_INFO("waiting...");
    }




    ros::spinOnce();

    loop_rate.sleep();

  }



}
