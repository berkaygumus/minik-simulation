#include <ros/ros.h>

#include <opencv2/aruco.hpp>

#include "ISLH_msgs/robotPositions.h"

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc,char** argv){

    ros::init(argc,argv,"aruco_marker");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    VideoCapture cap1(1); //left cam
    cap1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame1;

    if(!cap1.isOpened()){
          cout << "ERROR cam1!!" << endl;
          exit(1);
      }

    //aruco marker dictionary
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

    while(ros::ok()){

      cap1 >> frame1;

      imshow("init_left",frame1);

      cv::Mat image,imageCopy;
      frame1.copyTo(image);
      image.copyTo(imageCopy);
      std::vector<int> ids;
      std::vector<std::vector<cv::Point2f> > corners;
      cv::aruco::detectMarkers(image, dictionary, corners, ids);
      // if at least one marker detected
      if (ids.size() > 0)
          cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
      //cv::imshow("out", imageCopy);

      Mat distCoeffs = Mat::zeros(1, 5, CV_32F);//{0,0,0,0,0};
      Mat cameraMatrix = (Mat_<double>(3,3) << 3.2980705649113719e+02, 0., 3.0991789834865335e+02,0.,3.2749961188628993e+02, 2.1460654247926990e+02,0., 0., 1.);
      //Mat cameraMatrix = (Mat_<double>(3,3) << 371.42398 ,    0.00000 ,  312.84805 ,  0.00000 ,  371.39846 ,  231.62992 ,  0.00000 ,    0.00000 ,    1.00000);
      //Mat distCoeffs = (Mat_<double>(1,5) <<  -0.36019 ,    0.19207 ,    0.00165 ,  -0.00967 ,  -0.06027);
      /*K : [ 371.42398 ,    0.00000 ,  312.84805 ,
   0.00000 ,  371.39846 ,  231.62992 ,
   0.00000 ,    0.00000 ,    1.00000]
P : [ 371.42398 ,    0.00000 ,  312.84805 ,    0.00000 ,
   0.00000 ,  371.39846 ,  231.62992,    0.00000 ,
   0.00000 ,    0.00000,    1.00000 ,    0.00000]
Dist : [  -0.36019 ,    0.19207 ,    0.00165 ,  -0.00967 ,  -0.06027]*/



      std::vector<cv::Vec3d> rvecs, tvecs;
      cv::aruco::estimatePoseSingleMarkers(corners, 5.3, cameraMatrix, distCoeffs, rvecs, tvecs);//2.parameter: the widht of aruco markers, if it's cm, the results will be in terms of cm
//4.5
      //Mat outputImage;
      //imageCopy.copyTo(outputImage);
      vector<Vec3d> positions;
      vector<double> headings;
      vector<int> robot_IDs;
      for (int i = 0; i < rvecs.size(); ++i) {
          cv::Vec3d rvec = rvecs[i];
          cv::Vec3d tvec = tvecs[i];
          int aruco_id = ids[i];
          //cout << "id i: " << ids[i] <<  endl;
          //cout << "rvec: " << endl;
          cout << rvec*180/M_PI << endl;
          int robot_id = (aruco_id-1)/4;
          //cout << "robot id: " << robot_id << endl;
          int side = aruco_id%4-1;
          //cout << "side: " << side << endl;


          Mat rotM = Mat::zeros(3,3, CV_32F); //np.zeros(shape=(3,3));
          Mat jacobian;
          Rodrigues(rvec, rotM,jacobian);
          Mat mtxR,mtxQ;
          Vec3d angles = RQDecomp3x3(rotM, mtxR, mtxQ);
          //cout << "angles: " << angles << endl;
          /*cv2.Rodrigues(rvec[i-1], rotM, jacobian = 0);
          ypr = cv2.RQDecomp3x3(rotM);*/

          double z_angle = angles[1];//rvec[2]*180/M_PI;
          z_angle = - z_angle + 180;
          double heading = z_angle + 90*side;
          if(heading> 180){
            heading = heading - 360;
          }
          //cout << "heading:  " << heading << endl;
          positions.push_back(tvec);
          headings.push_back(heading);
          robot_IDs.push_back(robot_id);

          //cout << "tvec: " << endl;
          //cout << tvec << endl;
          cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvec, tvec, 10);
      }

      for(int i=0; i < positions.size();i++){
        cout << "ID: " << robot_IDs[i] << " pos: " << positions[i] << " heading: " <<  headings[i] << endl;
      }

      //mu.erase(mu.begin() + i);
 			//i--;

      vector<Vec3d> c_positions;
      vector<double> c_headings;
      vector<int> c_robot_IDs;
      for(int i=0; i < positions.size();i++){
        for(int j=i+1; j < positions.size();j++){
          if(robot_IDs[i]==robot_IDs[j]){
              cv::Vec3d c_pos = (positions[i]+positions[j])/2;
              double c_heading = (headings[i]+headings[j])/2;
              positions[i] = c_pos;
              headings[i] = c_heading;
              positions.erase(positions.begin() + j);
              headings.erase(headings.begin() + j);
              robot_IDs.erase(robot_IDs.begin() + j);
              j--;
          }
        }
        cout << "ID: " << robot_IDs[i] << " combined pos: " << positions[i] << " combined heading: " <<  headings[i] << endl;
      }


      cv::imshow("out", imageCopy);

      waitKey(25);
      ros::spinOnce();
      loop_rate.sleep();
    }

}
