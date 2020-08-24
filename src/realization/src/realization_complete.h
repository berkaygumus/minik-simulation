/*
 File name: RosThread.h
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 17.12.2019
 Date last modified: 24.08.2020
 */

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <std_msgs/Bool.h>
#include <math.h>
#include <cfloat>
#include "ISLH_msgs/robotPositions.h"
#include <geometry_msgs/PoseArray.h>
#include <nav_msgs/Odometry.h>

//file storage
#include <opencv2/core.hpp>
#include <iostream>
#include <string>

#define PI 3.14159265359
#define N 5
#define LOOP_RATE 10

class RealizationComplete{
  public:

    RealizationComplete(int argc,char** argv,int);
    ~RealizationComplete();
    void work();

  private:
    int argc;
    char** argv;


    int A[N][N];//goal topology
    double calcPos[N][N][2];//robot posiitons; calcPos[reference frame][target robot]
    int n = N;


    double distance[N][N];//distance matrix
    double eta[N][N]; //eta values
    float pose_x,pose_y,pose_theta;//position and heading
    float prev_pose_x = 0;//previous position
    float prev_pose_y = 0;
    int id;//robot ID
    double gama_sum=0;//gamma
    double beta_product = 1;//beta
    double gama_b_dot[N][2];
    double beta_b_dot[N][2];
    double gama_eta_dot[N][N];
    double fi_b_dot[N][2];
    double fi_eta_dot[N][N];
    double fi_eta_dot2[N][N];

    ////////////////////////////////parameters
    double threshold;
    double ro_ij;
    double k;
    double f = LOOP_RATE;
    double step_size = 1/f;
    bool quite_mode;//not to print values,
    bool print_fi_b_dot;
    ////////////////////////////////


    ros::NodeHandle getParamHandle;
    ros::NodeHandle poseOdomSub;
    ros::NodeHandle poseSub;
    ros::NodeHandle poseOverheadCamSub;
    ros::NodeHandle velPub;
    ros::NodeHandle trSub;

    ros::Publisher vel_pub;

    double orientation2theta(double, double, double, double);//calculates angles using quaternion

    void gamaFinder();
    void gamaBDotFinder();
    void betaFinder();
    void betaBDotFinder();
    void gamaEtaDotFinder();
    void fiBDotFinder();
    void fiEtaDotFinder();
    void etaFinder();
    void finalRealization();
    void Comparator();


//////////////////////turtlesim completed/////////////////////
    /*void poseOdomCallback0(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback1(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback2(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback3(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback4(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback5(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback6(const turtlesim::Pose::ConstPtr&);*/

/////////////////////completed part /////////////////////////////

    void gazeboOdomCallback0(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback2(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback3(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback4(const nav_msgs::Odometry::ConstPtr&);

///////////////////////////////////



    void distanceCalculator();
    int flagN[N];
    int flag=1;
    int completed = 0;
    int completed_stop = 0;
    int time_counter = 0;
    double path_distance = 0;

    void poseOverCallback(const ISLH_msgs::robotPositions::ConstPtr&);
    //void turtleService();

    void setVelocity();

    double linear_vel;
    double angular_vel;



};
