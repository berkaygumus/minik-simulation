#include <ros/ros.h>
#include <camera_calibration.h>
#include <globaldefs.h>
#include <opencv2/tracking.hpp> //for roi
#include <opencv2/aruco.hpp>
#include <opencv2/videoio.hpp>

int main(int argc,char** argv){

    ros::init(argc,argv,"aruco_pose");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    /*cv::Mat markerImage;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::drawMarker(dictionary, 1, 500, markerImage, 1);
    cv::imwrite("/home/berkay/catkin_ws/src/camera2ros/src/aruco_markers/marker1_500.jpg", markerImage);
    cv::aruco::drawMarker(dictionary, 2, 500, markerImage, 1);
    cv::imwrite("/home/berkay/catkin_ws/src/camera2ros/src/aruco_markers/marker2_500.jpg", markerImage);
    cv::aruco::drawMarker(dictionary, 3, 500, markerImage, 1);
    cv::imwrite("/home/berkay/catkin_ws/src/camera2ros/src/aruco_markers/marker3_500.jpg", markerImage);
    cv::aruco::drawMarker(dictionary, 4, 500, markerImage, 1);
    cv::imwrite("/home/berkay/catkin_ws/src/camera2ros/src/aruco_markers/marker4_500.jpg", markerImage);
*/
    /*Mat read_image;
    read_image = imread("/home/berkay/catkin_ws/src/camera2ros/src/aruco_markers/marker23.jpg");
    cout << "written " << endl;

    while(ros::ok()){

      imshow("read_image",read_image);

    }*/


  VideoCapture inputVideo(0);
  cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
  while (ros::ok()){
      cv::Mat image, imageCopy;
      inputVideo >> image;
      image.copyTo(imageCopy);
      std::vector<int> ids;
      std::vector<std::vector<cv::Point2f> > corners;
      cv::aruco::detectMarkers(image, dictionary, corners, ids);
      // if at least one marker detected
      if (ids.size() > 0)
          cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
      cv::imshow("out", imageCopy);

        waitKey(25);
        ros::spinOnce();
        loop_rate.sleep();
}
}
