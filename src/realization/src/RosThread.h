/*
 File name: RosThread.h
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 17.12.2019
 Date last modified: 17.12.2019
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
#define PI 3.14159265359
#define N 5
#define K 6
#define THRESHOLD 3
#define RO_IJ 0.5
#define LOOP_RATE 10
//#define id 1

class RosThread{
  public:

    RosThread(int argc,char** argv,int);
    ~RosThread();
    void work();

  private:
    int argc;
    char** argv;
    ///////////////////////////////cases
    //int A[N][N]= {{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};
    //int A[N][N]= {{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}}; // circle for 4: 0 1 2 3
    //int A[N][N]= {{0,1,0,0},{1,0,1,0},{0,1,0,1},{0,0,1,0}};
    //int A[N][N]= {{0,0,0,0},{0,0,1,0},{0,1,0,1},{0,0,1,0}};
    //int A[N][N]= {{0,1,0,0},{1,0,1,0},{0,1,0,0},{0,0,1,0}};
    //int A[N][N]= {{0,1,1,1},{1,0,1,0},{1,1,0,0},{1,0,1,0}};
    //int A[N][N]= {{0,0,0},{0,0,0},{0,0,0}};
    //int A[N][N]= {{0,0,1},{0,0,1},{1,1,0}};
    //int A[N][N]= {{0,0},{0,0}};
    //int A[N][N]= {{0,1},{1,0}};

    //int A[N][N]= {{0,1,0,0,1},{1,0,1,0,0},{0,1,0,1,0},{0,0,1,0,1},{1,0,0,1,0}}; //topology 1  // circle for 5: 0 1 2 3 4
    //int A[N][N]= {{0,1,0,1,0},{1,0,1,0,0},{0,1,0,0,1},{1,0,0,0,1},{0,0,1,1,0}};  // topology 2
    //int A[N][N]= {{0,1,0,0,0},{1,0,1,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,1,0,0,0}};  // topology 3
    int A[N][N]= {{0,1,0,0,1},{1,0,1,0,0},{0,1,0,0,0},{0,0,0,0,1},{1,0,0,1,0}}; //topology 4
    //int A[N][N]= {{0,1,0,0,1},{1,0,1,0,1},{0,1,0,1,0},{0,0,1,0,0},{1,1,0,0,0}};  // topology 5

    //int A[N][N]= {{0,0,0,0,1,1},{0,0,1,0,0,1},{0,1,0,1,0,0},{0,0,1,0,1,0},{1,0,0,1,0,0},{1,1,0,0,0,0}}; //circle for 6: 1 2 3 4 0 5
    //int A[N][N]= {{0,1,0,0,0,0,1},{1,0,1,0,0,0,0},{0,1,0,1,0,0,0},{0,0,1,0,1,0,0},{0,0,0,1,0,1,0},{0,0,0,0,1,0,1},{1,0,0,0,0,1,0}};
    double b[N][2];
    double calcPos[N][N][2];
    int n =N;


    double distance[N][N];
    double eta[N][N];
    float pose_x,pose_y,pose_theta;
    int id;
    double gama_sum=0;
    double beta_product = 1;
    double gama_b_dot[N][2];
    double beta_b_dot[N][2];
    double gama_eta_dot[N][N];
    double fi_b_dot[N][2];
    double fi_eta_dot[N][N];
    double fi_eta_dot2[N][N];

    ////////////////////////////////parameters
    double threshold = THRESHOLD;
    double ro_ij = RO_IJ;
    double k=K;
    double f = LOOP_RATE;
    double step_size = 1/f;
    ////////////////////////////////

    ros::NodeHandle poseOdomSub;
    ros::NodeHandle poseSub;
    ros::NodeHandle poseOverheadCamSub;
    ros::NodeHandle velPub;
    ros::NodeHandle trSub;
    //ros::NodeHandle ser;

    ros::Publisher vel_pub;

    double orientation2theta(double, double, double, double);

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

    ////////////////////////partial part/////////////////////////
    void odomCallback0(const geometry_msgs::Pose::ConstPtr&);
    void odomCallback1(const geometry_msgs::Pose::ConstPtr&);
    void odomCallback2(const geometry_msgs::Pose::ConstPtr&);
    void odomCallback3(const geometry_msgs::Pose::ConstPtr&);
    void odomCallback4(const geometry_msgs::Pose::ConstPtr&);

    void calcPosCallback0(const geometry_msgs::PoseArray::ConstPtr&);
    void calcPosCallback1(const geometry_msgs::PoseArray::ConstPtr&);
    void calcPosCallback2(const geometry_msgs::PoseArray::ConstPtr&);
    void calcPosCallback3(const geometry_msgs::PoseArray::ConstPtr&);
    void calcPosCallback4(const geometry_msgs::PoseArray::ConstPtr&);

    void transformCallback(const std_msgs::Bool::ConstPtr&);

    //////////////////////////////////////////////////////////

//////////////////////turtlesim completed/////////////////////
    /*void poseOdomCallback0(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback1(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback2(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback3(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback4(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback5(const turtlesim::Pose::ConstPtr&);
    void poseOdomCallback6(const turtlesim::Pose::ConstPtr&);*/

/////////////////////completed part /////////////////////////////
/*
    void gazeboOdomCallback0(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback2(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback3(const nav_msgs::Odometry::ConstPtr&);
    void gazeboOdomCallback4(const nav_msgs::Odometry::ConstPtr&);*/
///////////////////////////////////



    void distanceCalculator();
    int flagN[N];
    int flag=1;
    int completed = 0;

    void poseOverCallback(const ISLH_msgs::robotPositions::ConstPtr&);
    //void turtleService();

    void setVelocity();

    double linear_vel;
    double angular_vel;

    void turnToSee();
    bool isSeen = false;


};
