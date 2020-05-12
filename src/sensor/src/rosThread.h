/*
 File name: rosThread.h
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 04.01.2020
 Date last modified: 04.01.2020
 */

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/Pose.h>
#include <math.h>
#include <cfloat>
#define PI 3.14159265359
#define LOOP_RATE 10

#define N 3

using namespace std;

class RosThread{
  public:

    RosThread(int id);
    ~RosThread();
    void work();

  private:


    ros::NodeHandle poseOdomSub;
    ros::NodeHandle posPub;


    void poseOdomCallback0(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback1(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback2(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback3(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback4(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback5(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback6(const turtlesim::Pose::ConstPtr&);

    bool checkRange(int i, int j);
    vector<double> calculatePos(int i, int j);
    void publishPos();

    double addError(double);


    int id;
    int n = N;
    float pose_x,pose_y,pose_theta;
    double b[N][3];
    double initPos[N][3];
    double robotsSeen[N][N][2];
    double robotPosReal[N][N][2];
    int flagN[N];
    int flag = 0;


};
