#include <ros/ros.h>
#include "camera_calibration/camera_calibration.h"
#include <opencv2/tracking.hpp> //for roi

int main(int argc,char** argv){

    ros::init(argc,argv,"disparity");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);
    Camera_Calibration* calib  = new Camera_Calibration();

    bool isCamera = 0;
    string left_img_name = "/home/berkay/catkin_ws/src/detect_color_object/images/disparity_left1.jpg";
		string right_img_name = "/home/berkay/catkin_ws/src/detect_color_object/images/disparity_right1.jpg";

    VideoCapture cap1(1); //left cam
    cap1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame1;

    VideoCapture cap2(2); //right cam
    cap2.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap2.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame2;

    if(!cap1.isOpened()){
      cout << "there is no camera 1" << endl;
      cout << "images are taken from the file" << endl;
      isCamera = 0;
    }
    if(!cap2.isOpened()){
      cout << "there is no camera 2" << endl;
      cout << "images are taken from the file" << endl;
      isCamera = 0;
    }


    if(isCamera){
      cap1 >> frame1;
    }
    else{
      frame1 = imread(left_img_name);//left image
      frame2 = imread(right_img_name);//right image
    }

    calib->loadStereoCalibrationParams(frame1.size());

    Ptr<StereoSGBM> sgbm = StereoSGBM::create(0,16,3);
    cout << "roi: " <<endl;
    Rect2d roi = selectROI(frame1);
    cout << "roi: " << roi << endl;



    int cn = 1; //img1.channels();
    int SADWindowSize = 9;
    int sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;

    int setPreFilterCap = 63;
    int setMinDisparity = 0;

    int setNumDisparities = 128;
    int setUniquenessRatio = 10;
    int setSpeckleWindowSize = 100;
    int setSpeckleRange = 32;
    int setDisp12MaxDiff = 1;


    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
    //Create trackbars in "Control" window
    cvCreateTrackbar("cn", "Control", &cn, 3);
    cvCreateTrackbar("SADWindowSize", "Control", &SADWindowSize, 100);

    cvCreateTrackbar("setPreFilterCap", "Control", &setPreFilterCap, 150);
    cvCreateTrackbar("setMinDisparity", "Control", &setMinDisparity, 10);

    cvCreateTrackbar("setNumDisparities", "Control", &setNumDisparities, 300);
    cvCreateTrackbar("setUniquenessRatio", "Control", &setUniquenessRatio, 30);

    cvCreateTrackbar("setSpeckleWindowSize", "Control", &setSpeckleWindowSize, 200);
    cvCreateTrackbar(" setSpeckleRange", "Control", &setSpeckleRange, 60);
    cvCreateTrackbar("setDisp12MaxDiff", "Control", &setDisp12MaxDiff, 10);



    while(ros::ok()){
      sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;
      sgbm->setPreFilterCap(setPreFilterCap);
      sgbm->setBlockSize(sgbmWinSize);
      sgbm->setP1(8*cn*sgbmWinSize*sgbmWinSize);
      sgbm->setP2(32*cn*sgbmWinSize*sgbmWinSize);
      sgbm->setMinDisparity(setMinDisparity);
      sgbm->setNumDisparities(setNumDisparities);
      sgbm->setUniquenessRatio(setUniquenessRatio);
      sgbm->setSpeckleWindowSize(setSpeckleWindowSize);
      sgbm->setSpeckleRange(setSpeckleRange);
      sgbm->setDisp12MaxDiff(setDisp12MaxDiff);
      sgbm->setMode(StereoSGBM::MODE_SGBM);


      if(isCamera){
        cap1 >> frame1;
        cap2 >> frame2;
      }
      else{
        frame1 = imread("/home/berkay/udemy_ws/src/camera_deneme/src/capture/left/left_initial_distorted_images/000004.jpg");//left image
        frame2 = imread("/home/berkay/udemy_ws/src/camera_deneme/src/capture/right/right_initial_distorted_images/000004.jpg");//right image
      }

      Mat undist1, undist2, disp, disp8;
      calib->applyStereoCalibration( frame1,  frame2,  undist1,  undist2);
      imshow("init_left",frame1);
      imshow("init_right",frame2);
      imshow("undist_left",undist1);
      imshow("undist_right",undist2);
      Mat disp_l,disp_r;
      undist1.convertTo(disp_l,CV_8UC1);
      undist2.convertTo(disp_r,CV_8UC1);

      sgbm->compute(disp_l, disp_r, disp);
      disp.convertTo(disp8, CV_8U, 255/(128*16.));



      imshow("scaled disparity", disp8);
      imshow("disparity", disp);
      stringstream ss1;
      ss1 << "/home/berkay/catkin_ws/src/camera2ros/disp.jpg";
      imwrite(ss1.str(),disp8);


      waitKey(25);
      ros::spinOnce();
      loop_rate.sleep();
    }

    //for mono camera
    //calib->calibrate();
    //char c = (char)waitKey();

}
