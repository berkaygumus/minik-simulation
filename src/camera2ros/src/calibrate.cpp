#include <ros/ros.h>
#include <camera_calibration.h>
#include <globaldefs.h>
#include <opencv2/tracking.hpp> //for roi
#include <opencv2/aruco.hpp>
#include <opencv2/videoio.hpp>

int main(int argc,char** argv){

    ros::init(argc,argv,"calibrate");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);
    Camera_Calibration* calib  = new Camera_Calibration();

    /*VideoCapture cap1(1); //left cam
    cap1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame1;

    VideoCapture cap2(2); //right cam
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
        }*/

    //cap1 >> frame1;
    //calib->calibrateMain(argc, argv);
    //for mono camera
    calib->calibrate();

    //calib->runStereoCalibrationAndSave();

    //aruco marker dictionary



}
