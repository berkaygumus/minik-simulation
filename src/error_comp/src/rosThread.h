/*
 File name: rosThread.h
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 13.02.2020
 Date last modified:
 */

#include "ros/ros.h"
#include <geometry_msgs/PoseArray.h>
#include <turtlesim/Pose.h>
#include <math.h>
#include <cfloat>
#define PI 3.14159265359
#define LOOP_RATE 10

#define N 3

using namespace std;

class RosThread{
  public:

    RosThread();
    ~RosThread();
    void work();

  private:


    ros::NodeHandle poseSub;

    void calcCallback0(const geometry_msgs::PoseArray::ConstPtr&);
    void calcCallback1(const geometry_msgs::PoseArray::ConstPtr&);
    void calcCallback2(const geometry_msgs::PoseArray::ConstPtr&);

    void realCallback0(const geometry_msgs::PoseArray::ConstPtr&);
    void realCallback1(const geometry_msgs::PoseArray::ConstPtr&);
    void realCallback2(const geometry_msgs::PoseArray::ConstPtr&);

    void errorCalculate();

    int n = N;
    double calcPos[N][N][2];
    double realPos[N][N][2];


};
