/*
 File name: rosThread.h
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 07.01.2020
 Date last modified: 07.01.2020
 */

#include "ros/ros.h"
#include <geometry_msgs/PoseArray.h>
#include "ISLH_msgs/robotPositions.h"
#include <geometry_msgs/Pose2D.h>
#include <turtlesim/Pose.h>
#include <std_msgs/Bool.h>
#include <math.h>
#include <cfloat>
#include <time.h>
#define PI 3.14159265359
#define LOOP_RATE 10

#define N 5
#define SIZE_P 100 //length of pos data, 100 data for 10 second, f=10 hz
#define SIZE_T 3 //length of time data, 3 last seen time data
#define DIST_THRESHOLD 0.7 //threshold distance to add new pos data and to be able to use methods
using namespace std;

class RosThread{
  public:

    RosThread();
    ~RosThread();
    void work();

  private:


    ros::NodeHandle sensorSub;
    ros::NodeHandle posPub;
    ros::NodeHandle trPub;



    void sensorCallback0(const geometry_msgs::PoseArray::ConstPtr&);
    void sensorCallback1(const geometry_msgs::PoseArray::ConstPtr&);
    void sensorCallback2(const geometry_msgs::PoseArray::ConstPtr&);


    //aruco callback arucoCallback1
    void arucoCallback1(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback2(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback3(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback4(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback5(const ISLH_msgs::robotPositions::ConstPtr&);

    ///odometry
    void odom1callback(const geometry_msgs::Pose::ConstPtr&);
    void odom2callback(const geometry_msgs::Pose::ConstPtr&);
    void odom3callback(const geometry_msgs::Pose::ConstPtr&);
    void odom4callback(const geometry_msgs::Pose::ConstPtr&);
    void odom5callback(const geometry_msgs::Pose::ConstPtr&);

    int n = N;
    int sizeP = SIZE_P;
    int sizeT = SIZE_T;
    int t = 0;
    int index_t = 0;
    double robotsSeen[SIZE_P][N][N][2];
    int lastSeen[N][N][SIZE_T];
    double anglesTr[N][N];
    double posTr[N][N][2];
    double posRobots[N][N][2];
    bool connected[N][N];
    bool completed = false;

    void addSeenTime(int i, int j);
    bool checkSeenTime(int i, int j);
    void checkLastSeen();
    void calculateTransform1();
    void calculateTransform2();
    void completeTransform();
    void calculateRobotPos();




};
