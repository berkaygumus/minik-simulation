/*
Package name: minik_gazebo
File name: odom_publisher.h
Author: Berkay Gumus
E-mail: berkay.gumus@boun.edu.tr
Date created: 28.06.2020
Date last modified: 24.08.2020

Takes robot positions and headings with respect to world frame,
converts to them with respect to initial robot frames
 */

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>
#include <math.h>
#include <cfloat>
#define PI 3.14159265359
#define LOOP_RATE 10
#define N 5

using namespace std;

class OdomPublisher{
  public:

    OdomPublisher();
    ~OdomPublisher();
    void work();

  private:


    ros::NodeHandle poseOdomSub;
    ros::NodeHandle posPub;
    ros::NodeHandle poseSub;

    //subscribers for posit,ons with respect to world frame for each robot
    void gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback2(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback3(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback4(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback5(const nav_msgs::Odometry::ConstPtr&);

    vector<double> calculatePos(int);

    int n = N;
    double initPos[N][3];
    double pos[N][3];
    int flagN[N];
    int flag = 0;


};
