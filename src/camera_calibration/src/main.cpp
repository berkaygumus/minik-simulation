#include <ros/ros.h>
#include "camera_calibration/camera_calibration.h"
#include "camera_calibration/globaldefs.h"
#include <opencv2/tracking.hpp> //for roi
#include <opencv2/videoio.hpp>

int main(int argc,char** argv){

    ros::init(argc,argv,"camera_calibrate");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);
    Camera_Calibration* calib  = new Camera_Calibration();

    //Examples:

    ////////////////////////////////////////////////////////////////////
    //1)for mono camera:
    //calib->calibrate();

    ///////////////////////////////////////////////////////////////////
    //2)for stereo camera calibration:
    calib->runStereoCalibrationAndSave(); //it is necessary only once.

    //////////////////////////////////////////////////////////////////
    //3)after runStereoCalibrationAndSave function runs once, this part can be used.

    /*
    VideoCapture cap1(1); //left cam
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
        }

    cap1 >> frame1;
    //load parameters from the file
    calib->loadStereoCalibrationParams(frame1.size());

    while(ros::ok()){
      cap1 >> frame1;
      cap2 >> frame2;
      Mat undistorted1, undistorted2;
      calib->applyStereoCalibration(frame1, frame2, undistorted1, undistorted2);
      imshow("frame1",frame1);
      imshow("frame2",frame2);
      imshow("undistorted1",undistorted1);
      imshow("undistorted2",undistorted2);
      waitKey(25);

    }
    */

}
