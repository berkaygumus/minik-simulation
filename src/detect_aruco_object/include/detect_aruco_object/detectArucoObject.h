/*
 Package name: detect_aruco_object
 File name: detectArucoObject.h
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified: 24.08.2020

 subscribes odometry and source image messages;
 calculates and publishes positions, headings, ID's of robots detected by each robot
 */

#include "ros/ros.h"
#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Pose.h>
#include "ISLH_msgs/robotPositions.h"
#include <sensor_msgs/Image.h>
#include "float.h"

#include "camera_calibration/camera_calibration.h"//camera_calibration library from camera_calibration package
#define N 5
#define PI 3.14159265359




using namespace std;
using namespace cv;

class DetectArucoObject{
  public:

    DetectArucoObject();
    ~DetectArucoObject();

    void work();


  private:

    ros::NodeHandle n;

    //subscribers for images
    void img1callback(const sensor_msgs::Image::ConstPtr&);
    void img2callback(const sensor_msgs::Image::ConstPtr&);
    void img3callback(const sensor_msgs::Image::ConstPtr&);
    void img4callback(const sensor_msgs::Image::ConstPtr&);
    void img5callback(const sensor_msgs::Image::ConstPtr&);

    //subscribers for odometry
    void odom1callback(const geometry_msgs::Pose::ConstPtr&);
    void odom2callback(const geometry_msgs::Pose::ConstPtr&);
    void odom3callback(const geometry_msgs::Pose::ConstPtr&);
    void odom4callback(const geometry_msgs::Pose::ConstPtr&);
    void odom5callback(const geometry_msgs::Pose::ConstPtr&);

    //publisher for positions of detected robots
    ros::Publisher robotsPublisher[N];


    void calculateRobotPos(Mat, int);
    /*
    takes source image from the camera on the robot and this robot ID;
    calculates positions and headings of robots detected by this robot with respect to initial robot frame;
    publishes robot ID's, positions and headings of detected robots
    */

    //odometry for each robot
    double odomPos[N][3];

    //source images for each camera on robot
    Mat src_image1;
    Mat src_image2;
    Mat src_image3;
    Mat src_image4;
    Mat src_image5;

    //checks whether the image is taken
    bool isImg1 = 0;
    bool isImg2 = 0;
    bool isImg3 = 0;
    bool isImg4 = 0;
    bool isImg5 = 0;

    std::default_random_engine generator;
    




};
