#include <ros/ros.h>
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main(int argc,char** argv){

    ros::init(argc,argv,"capture_images");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);


    int nr_cameras = 1;

    VideoCapture cap1(1); //left cam
    cap1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame1;

    VideoCapture cap2(2); //right cam
    cap2.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap2.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame2;

    string img1_file = "/home/berkay/catkin_ws/src/detect_color_object/images/img1.jpg";
    string img2_file = "/home/berkay/catkin_ws/src/detect_color_object/images/img2.jpg";

    if(!cap1.isOpened()){
          cout << "ERROR cam1!!" << endl;
          exit(1);
    }

    if(!cap2.isOpened() && nr_cameras == 2 ){
          cout << "ERROR cam2!!" << endl;
          exit(1);
    }

    while(ros::ok()){


      cap1 >> frame1;
      imwrite(img1_file,frame1);

      if(nr_cameras == 2){
        cap2 >> frame2;
        imwrite(img2_file,frame2);
      }

      waitKey(25);
      ros::spinOnce();
      loop_rate.sleep();
    }
}
