/*
 File name: detectArucoObject.h
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified: 27.05.2020
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

#include "camera_calibration/camera_calibration.h"
#define N 3
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

    void img1callback(const sensor_msgs::Image::ConstPtr&);
    void img2callback(const sensor_msgs::Image::ConstPtr&);
    void img3callback(const sensor_msgs::Image::ConstPtr&);
    //void img4callback(const sensor_msgs::Image::ConstPtr&);
    //void img5callback(const sensor_msgs::Image::ConstPtr&);

    void odom1callback(const geometry_msgs::Pose::ConstPtr&);
    void odom2callback(const geometry_msgs::Pose::ConstPtr&);
    void odom3callback(const geometry_msgs::Pose::ConstPtr&);

    ros::Publisher robotsPublisher[3];


    void calculateRobotPos(Mat, int);

    double odomPos[N][3];


    Mat src_image1;//source image
    Mat src_image2;//source image
    Mat src_image3;//source image
    //Mat src_image4;//source image
    //Mat src_image5;//source image

    bool isImg1 = 0;
    bool isImg2 = 0;
    bool isImg3 = 0;


};
