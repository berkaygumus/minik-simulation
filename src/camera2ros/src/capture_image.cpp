#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

//opencv
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;


int main(int argc,char** argv){

      ros::init(argc,argv,"capture_image_node");

      ros::NodeHandle n;
      ros::Rate loop(1);//1 image pair each 2 seconds
      ros::Rate loop_cap(5);

      VideoCapture cap1(1);
      cap1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
      cap1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
      Mat frame1;

      VideoCapture cap2(2);
      cap2.set(CV_CAP_PROP_FRAME_WIDTH, 640);
      cap2.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
      Mat frame2;


      if(!cap1.isOpened()){
            cout << "ERROR cam1!!" << endl;
            exit(1);
        }
        if(!cap2.isOpened()){
              cout << "ERROR cam2!!" << endl;
              exit(1);
          }



      while (ros::ok()){


          cap1 >> frame1;
          loop_cap.sleep();
          cap2 >> frame2;
          loop_cap.sleep();
          stringstream ss1;
          stringstream ss2;
          ss1 << "/home/berkay/catkin_ws/src/camera2ros/src/calib/images2/right.jpg";
          ss2 << "/home/berkay/catkin_ws/src/camera2ros/src/calib/images2/left.jpg";

          imwrite(ss1.str(),frame1);
          imwrite(ss2.str(),frame2);

          ros::spinOnce();
          loop.sleep();

      }




}
