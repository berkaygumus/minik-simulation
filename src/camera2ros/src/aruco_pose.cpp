#include <ros/ros.h>
#include <camera_calibration.h>
#include <globaldefs.h>
#include <opencv2/tracking.hpp> //for roi
#include <opencv2/aruco.hpp>
#include <opencv2/videoio.hpp>

int main(int argc,char** argv){

    ros::init(argc,argv,"camera2ros");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);
    Camera_Calibration* calib  = new Camera_Calibration();

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
    calib->loadStereoCalibrationParams(frame1.size());

    //aruco marker dictionary
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

    while(ros::ok()){

      cap1 >> frame1;
      cap2 >> frame2;

      Mat undist1, undist2, disp, disp8;
      calib->applyStereoCalibration( frame1,  frame2,  undist1,  undist2);
      imshow("init_left",frame1);
      imshow("init_right",frame2);
      imshow("undist_left",undist1);
      imshow("undist_right",undist2);

      cv::Mat image,imageCopy;
      undist1.copyTo(image);
      image.copyTo(imageCopy);
      std::vector<int> ids;
      std::vector<std::vector<cv::Point2f> > corners;
      cv::aruco::detectMarkers(image, dictionary, corners, ids);
      // if at least one marker detected
      if (ids.size() > 0)
          cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
      //cv::imshow("out", imageCopy);

      //cv::Mat cameraMatrix[3][3], distCoeffs[5];
      Mat distCoeffs = Mat::zeros(1, 5, CV_32F);//{0,0,0,0,0};
      //Mat cameraMatrix[3][3] = {{3.2980705649113719e+02, 0., 3.0991789834865335e+02},{0.,3.2749961188628993e+02, 2.1460654247926990e+02},{ 0., 0., 1.}};
      Mat cameraMatrix = (Mat_<double>(3,3) << 3.2980705649113719e+02, 0., 3.0991789834865335e+02,0.,3.2749961188628993e+02, 2.1460654247926990e+02,0., 0., 1.);

      std::vector<cv::Vec3d> rvecs, tvecs;
      cv::aruco::estimatePoseSingleMarkers(corners, 5.3, cameraMatrix, distCoeffs, rvecs, tvecs);

      //Mat outputImage;
      //imageCopy.copyTo(outputImage);
      for (int i = 0; i < rvecs.size(); ++i) {
          cv::Vec3d rvec = rvecs[i];
          cv::Vec3d tvec = tvecs[i];
          cout << "id i: " << ids[i] <<  endl;
          cout << "rvec: " << endl;
          cout << rvec*180/M_PI << endl;
          cout << "tvec: " << endl;
          cout << tvec << endl;
          cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvec, tvec, 10);
      }
      cv::imshow("out", imageCopy);

      waitKey(25);
      ros::spinOnce();
      loop_rate.sleep();
    }

}
