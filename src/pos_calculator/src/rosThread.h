/*
 Package name: pos_calculator
 File name: rosThread.h
 Author: Berkay Gümüş
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 07.01.2020
 Date last modified: 24.08.2020

 Takes partial data from aruco marker detection and odometry data;
 calculates frame transformations and robot positions;
 publishes them
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

#define N 5 //number of robot
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

//turtlesim
/*
    void sensorCallback0(const geometry_msgs::PoseArray::ConstPtr&);
    void sensorCallback1(const geometry_msgs::PoseArray::ConstPtr&);
    void sensorCallback2(const geometry_msgs::PoseArray::ConstPtr&);
*/

    //subscribers for positions, headings, ID's of robots detected
    void arucoCallback1(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback2(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback3(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback4(const ISLH_msgs::robotPositions::ConstPtr&);
    void arucoCallback5(const ISLH_msgs::robotPositions::ConstPtr&);

    //subscribers for odometry from gazebo
    void odom1callback(const geometry_msgs::Pose::ConstPtr&);
    void odom2callback(const geometry_msgs::Pose::ConstPtr&);
    void odom3callback(const geometry_msgs::Pose::ConstPtr&);
    void odom4callback(const geometry_msgs::Pose::ConstPtr&);
    void odom5callback(const geometry_msgs::Pose::ConstPtr&);

    int n = N;
    int sizeP = SIZE_P;//length of pos data, 100 data for 10 second, f=10 hz
    int sizeT = SIZE_T;//length of time data, 3 last seen time data
    int t = 0;//time
    int index_t = 0;//time index
    double robotsSeen[SIZE_P][N][N][2];// saves robot positions when one robot is observed another robot at any time >> [observation time][observer robot][observed robot][x,y]
    int lastSeen[N][N][SIZE_T];//observation time >> [observer robot][observed robot][which observation]
    double anglesTr[N][N];//transformation angles for initial robot frames
    double posTr[N][N][2];//translation vectors for initial robot frames
    double posRobots[N][N][2];//robot positions wrt each initial robot frames
    bool connected[N][N];// whether robot pairs' transformation is calculated
    bool completed = false; // whether all transformations are calculated

    void addSeenTime(int i, int j);//adds observation time to data
    bool checkSeenTime(int i, int j);//deletes old data
    void checkLastSeen();//check observation is valid to be added to data
    void calculateTransform1();//calculates transformations using method 1
    void calculateTransform2();//calculates transformations using method 2
    void completeTransform();//completes other transformation if there are connections
    void calculateRobotPos();//calculates robot positions wrt initial robot frames




};
