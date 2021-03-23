/*
 Package name: detect_aruco_object
 File name: detectArucoObject.cpp
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified: 24.08.2020

 subscribes odometry and source image messages;
 calculates and publishes positions, headings, ID's of robots detected by each robot
 */

#include "detect_aruco_object/detectArucoObject.h"
#include <random>

#define NOISE_RATIO 0.05

DetectArucoObject::DetectArucoObject(){

}

DetectArucoObject::~DetectArucoObject(){

}

//subscriber for image from the camera on robot 1
void DetectArucoObject::img1callback(const sensor_msgs::Image::ConstPtr& msg){
  cv_bridge::CvImagePtr cv_ptr; //cv_bridge to convert ROS image message to opencv imaga
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  /*
  //prints source image
  imshow("msg image1", cv_ptr->image);
  waitKey(10);
  */
  src_image1 = cv_ptr->image;//source image
  isImg1 = 1; //the image is taken
}

void DetectArucoObject::img2callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  /*
  //prints source image
  imshow("msg image2", cv_ptr->image);
  waitKey(10);
  */
  src_image2 = cv_ptr->image;
  isImg2 = 1;
}

void DetectArucoObject::img3callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  /*
  //prints source image
  imshow("msg image3", cv_ptr->image);
  waitKey(10);
  */
  src_image3 = cv_ptr->image;
  isImg3 = 1;
}

void DetectArucoObject::img4callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  /*
  //prints source image
  imshow("msg image4", cv_ptr->image);
  waitKey(10);
  */
  src_image4 = cv_ptr->image;
  isImg4 = 1;
}

void DetectArucoObject::img5callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  /*
  //prints source image
  imshow("msg image5", cv_ptr->image);
  waitKey(10);
  */
  src_image5 = cv_ptr->image;
  isImg5 = 1;
}

//subscriber for odometry
void DetectArucoObject::odom1callback(const geometry_msgs::Pose::ConstPtr& msg){
   odomPos[0][0] =  msg->position.x;
   odomPos[0][1] =  msg->position.y;
   odomPos[0][2] =  msg->position.z;

}

void DetectArucoObject::odom2callback(const geometry_msgs::Pose::ConstPtr& msg){
   odomPos[1][0] =  msg->position.x;
   odomPos[1][1] =  msg->position.y;
   odomPos[1][2] =  msg->position.z;

}

void DetectArucoObject::odom3callback(const geometry_msgs::Pose::ConstPtr& msg){
   odomPos[2][0] =  msg->position.x;
   odomPos[2][1] =  msg->position.y;
   odomPos[2][2] =  msg->position.z;

}

void DetectArucoObject::odom4callback(const geometry_msgs::Pose::ConstPtr& msg){
   odomPos[3][0] =  msg->position.x;
   odomPos[3][1] =  msg->position.y;
   odomPos[3][2] =  msg->position.z;

}

void DetectArucoObject::odom5callback(const geometry_msgs::Pose::ConstPtr& msg){
   odomPos[4][0] =  msg->position.x;
   odomPos[4][1] =  msg->position.y;
   odomPos[4][2] =  msg->position.z;

}


void DetectArucoObject::calculateRobotPos(Mat src_image, int id){
  /*
  takes source image from the camera on the robot and this robot ID;
  calculates positions and headings of robots detected by this robot with respect to initial robot frame;
  publishes robot ID's, positions and headings of detected robots
  */
  cout << endl << "Observer Robot ID " << id << "////////////////////////////" << endl;
  //camera matrix and distortion coefficients are necessary for aruco marker detection and position calculations
  Mat cameraMatrix = (Mat_<double>(3,3) << 278.0000, 0.0000 ,  320.0000 ,  0.00000 ,  278.0000 ,  240.0000 ,  0.0000 ,    0.0000 ,    1.00000);
  Mat distCoeffs = (Mat_<double>(1,5) <<  0 ,    0 ,    0 ,  0 ,  0);

  //aruco marker dictionary
  cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
  cv::Mat image,imageCopy;
  src_image.copyTo(image);
  image.copyTo(imageCopy);
  vector<int> marker_IDs; //marker ID vector for detected markers
  vector<vector<Point2f> > corners; //marker corners vector for detected markers

  aruco::detectMarkers(image, dictionary, corners, marker_IDs);//marker detection

  /*
  The parameters of detectMarkers are:

  The first parameter is the image containing the markers to be detected.
  The second parameter is the dictionary object, in this case one of the predefined dictionaries (DICT_6X6_250).
  The detected markers are stored in the markerCorners and markerIds structures:
  markerCorners is the list of corners of the detected markers. For each marker, its four corners are returned in their original order (which is clockwise starting with top left). So, the first corner is the top left corner, followed by the top right, bottom right and bottom left.
  markerIds is the list of ids of each of the detected markers in markerCorners. Note that the returned markerCorners and markerIds vectors have the same size.
  The fourth parameter is the object of type DetectionParameters. This object includes all the parameters that can be customized during the detection process. These parameters are explained in the next section.
  The final parameter, rejectedCandidates, is a returned list of marker candidates, i.e. shapes that were found and considered but did not contain a valid marker. Each candidate is also defined by its four corners, and its format is the same as the markerCorners parameter. This parameter can be omitted and is only useful for debugging purposes and for ‘refind’ strategies (see refineDetectedMarkers() ).
  */

  // if at least one marker detected
  if (marker_IDs.size() > 0){
      aruco::drawDetectedMarkers(imageCopy, corners, marker_IDs);//draws markers detected on imageCopy
  }


  vector<Vec3d> rvecs, tvecs;//rotation and translation vectors of markers
  aruco::estimatePoseSingleMarkers(corners, 0.15, cameraMatrix, distCoeffs, rvecs, tvecs);//0.15 is aruco length

  /*
  The markerCorners parameter is the vector of marker corners returned by the detectMarkers() function.
  The second parameter is the size of the marker side in meters or in any other unit. Note that the translation vectors of the estimated poses will be in the same unit
  cameraMatrix and distCoeffs are the camera calibration parameters that were created during the camera calibration process.
  The output parameters rvecs and tvecs are the rotation and translation vectors respectively, for each of the markers in markerCorners.
  */

  vector<Vec3d> positions; //position vector for each robot related to marker detected
  vector<float> headings; //heading vector for each robot related to marker detected
  vector<int> robot_IDs; //robotID vector for each robot related to marker detected

  //for each marker detected
  for (int i = 0; i < rvecs.size(); ++i) {
      cv::Vec3d tvec = tvecs[i]; //position vector
      cv::Vec3d rvec = rvecs[i]; //rotation vector
      int aruco_id = marker_IDs[i];  //marker ID
      //cout << "id: " << marker_IDs[i] <<  endl;
      //cout << "rvec: " << endl;
      //cout << rvec*180/M_PI << endl;

      //converts rotation matrix to rotation vector
      Mat rotM = Mat::zeros(3,3, CV_32F);//rotation matrix
      Mat jacobian;
      Rodrigues(rvec, rotM, jacobian); //calculates rotation matrix using rotation vector
      Mat mtxR,mtxQ;
      Vec3d angles = RQDecomp3x3(rotM, mtxR, mtxQ); //calculates rotation vector using rotation matrix(in terms of degree) and RQ decomposition

      double y_angle = angles[1];//related axis is y axis
      //aruco marker detection frame is different from the odometry frame
      //aruco marker pos and theta, not robot pos and theta
      //aruco marker detection frame to odometry frame
      double arucoPosX = tvec[2];
      double arucoPosY = -tvec[0];
      double arucoPosTheta = -y_angle + 180 ;
      //cout <<"odom frame aruco: x: " << arucoPosX << " y: " << arucoPosY << " theta: " << arucoPosTheta << endl;

      //calculation of robot pos using aruco pos, aruco marker is not at the center of robot, the pos must be shifted
      double l = 0.15;//distance between marker and center of robot observed
      arucoPosTheta = arucoPosTheta * PI /180 ;//in terms of radian
      double robotPosX = arucoPosX - l * cos(arucoPosTheta) + 0.15;//the distance between stereo camera and observer robot center is 0.15
      double robotPosY = arucoPosY - l * sin(arucoPosTheta) + 0.05;//the source image comes from left cam, the shift is 0.05
      //cout <<"odom frame robot: x: " << robotPosX << " y: " << robotPosY << endl;

      /* adding noise to aruco marker DetectionParameters: gaussian noise
      gaussian noise: gaussian distribution, mean: 0, standard deviation is NOISE_RATIO*distance(between the robot and aruco marker)
      */
      std::normal_distribution<double> distribution(0,NOISE_RATIO);
      double gaussian_number_x = distribution(generator);
      double gaussian_number_y = distribution(generator);
      double dist_factor = sqrt(pow(robotPosX,2)+pow(robotPosY,2));
      double gaussian_noise_x = gaussian_number_x * dist_factor;
      double gaussian_noise_y = gaussian_number_y * dist_factor;

      cout << "real pos " << robotPosX << " " << robotPosY << endl;
      cout << "gaussian_noise_x " << gaussian_noise_x << " gaussian_noise_y" << gaussian_noise_y << endl;
      robotPosX = robotPosX + gaussian_noise_x;
      robotPosY = robotPosY + gaussian_noise_y;

      cout << "noisy pos " << robotPosX << " " << robotPosY << endl;

      /*
      aruco marker arrangement on the robot
      front: 4*(id) + 1
      right: 4*(id) + 2
      back: 4*(id) + 3
      left: 4*(id) + 4
      */
      int robot_id = (aruco_id-1)/4; //robotID from markerID
      //cout << "robot id: " << robot_id << endl;
      int side = aruco_id%4; //side from markerID
      //cout << "side: " << side << endl;


      y_angle = - y_angle + 180; //correction for the camera frame
      double heading = y_angle + 90*(side-1); //heading from the side and its angle
      if(heading> 180){
        heading = heading - 360;
      }
      //cout << "heading:  " << heading << endl;

      //position of robot observed wrt observer robot frame
      Vec3d robotPos;
      robotPos[0] = robotPosX;
      robotPos[1] = robotPosY;
      robotPos[2] = 0;
      heading = heading * PI / 180;
      positions.push_back(robotPos);
      headings.push_back(heading);
      robot_IDs.push_back(robot_id);

      //cout << "tvec: " << endl;
      //cout << tvec << endl;
      aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvec, tvec, 0.3);//draws axes of markers detected on imageCopy
  }

  /*for(int i=0; i < positions.size();i++){
    cout << "ID: " << robot_IDs[i] << " pos: " << positions[i] << " heading: " <<  headings[i] << endl;
  }*/


  //combines data belonged the same robot (if its two sides are detected)
  for(int i=0; i < positions.size();i++){
    for(int j=i+1; j < positions.size();j++){
      if(robot_IDs[i]==robot_IDs[j]){ //if same robot
          cv::Vec3d temp_pos = (positions[i]+positions[j])/2; //average position
          double temp_heading = (headings[i]+headings[j])/2; //average heading
          positions[i] = temp_pos; //position update
          headings[i] = temp_heading; //heading update
          positions.erase(positions.begin() + j); //second data is removed
          headings.erase(headings.begin() + j);
          robot_IDs.erase(robot_IDs.begin() + j);
          j--; //index is decreased
      }
    }
    cout << "Robot ID: " << robot_IDs[i] << " final pos: " << positions[i] << " final heading: " <<  headings[i] << endl;
  }

  //shows image with markers detected
  ostringstream ss;
  ss << id +1;
  string name =  "robot" + ss.str();
  //+++cv::imshow(name, imageCopy);

  //positions with respect to current robot frame are done,
  //but these posiitons must be converted wrt initial robot frame

  //observer robot pos and theta from odometry data
  double observerTh = odomPos[id][2];
  double observerX = odomPos[id][0];
  double observerY = odomPos[id][1];
  for(int i = 0; i < positions.size();i++){
      double observedX = observerX + positions[i][0]*cos(observerTh) - positions[i][1]*sin(observerTh);
      double observedY = observerY + positions[i][0]*sin(observerTh) + positions[i][1]*cos(observerTh);
      double observedTh = observerTh + headings[i];
      cout << "initial frame x: " << observedX << " y: " << observedY << " theta: " << observedTh << endl;

      positions[i][0] = observedX;
      positions[i][1] = observedY;
      headings[i] = observedTh;

  }

  //calculations are done :D
  ////////////////////////////////////////////////////////////////////////////////

  ISLH_msgs::robotPositions msg; //message to publish: -> geometry_msgs::Pose2D[] positions
                                //                     -> float32[] directions
                                //                     -> int32[] IDs

  vector<geometry_msgs::Pose2D > msg_positions; //pos vector
  for(int i=0;i<robot_IDs.size();i++){//for each robot detected
    geometry_msgs::Pose2D temp_pos; //temp pos
    temp_pos.x = positions[i][0];
    temp_pos.y = positions[i][1];
    temp_pos.theta = headings[i];

    msg_positions.push_back(temp_pos); //msg_positions message
  }

  msg.positions = msg_positions; //position vector
  msg.directions = headings; //heading vector
  msg.IDs = robot_IDs; //Robot ID vector

  robotsPublisher[id].publish(msg);//publishes message
  cout << "published" << endl;

}



void DetectArucoObject::work(){

  ros::Rate loop_rate(10);

  //subscribers for images
  ros::Subscriber img1sub = n.subscribe("/robot1/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img1callback,this);
  ros::Subscriber img2sub = n.subscribe("/robot2/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img2callback,this);
  ros::Subscriber img3sub = n.subscribe("/robot3/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img3callback,this);
  ros::Subscriber img4sub = n.subscribe("/robot4/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img4callback,this);
  ros::Subscriber img5sub = n.subscribe("/robot5/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img5callback,this);

  //subscribers for odometry
  ros::Subscriber odom1sub = n.subscribe("/odom1",1000,&DetectArucoObject::odom1callback,this);
  ros::Subscriber odom2sub = n.subscribe("/odom2",1000,&DetectArucoObject::odom2callback,this);
  ros::Subscriber odom3sub = n.subscribe("/odom3",1000,&DetectArucoObject::odom3callback,this);
  ros::Subscriber odom4sub = n.subscribe("/odom4",1000,&DetectArucoObject::odom4callback,this);
  ros::Subscriber odom5sub = n.subscribe("/odom5",1000,&DetectArucoObject::odom5callback,this);

  //publishers for positions of detected robots by each robot
  robotsPublisher[0] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco1",1);//positions of detected robots by robot 1
  robotsPublisher[1] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco2",1);//positions of detected robots by robot 2
  robotsPublisher[2] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco3",1);//positions of detected robots by robot 3
  robotsPublisher[3] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco4",1);//positions of detected robots by robot 4
  robotsPublisher[4] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco5",1);//positions of detected robots by robot 5

  while(ros::ok()){
    if(isImg1){//if source image is taken
      calculateRobotPos(src_image1,0);//calculates and publishes positions, headings, ID's of robots detected by robot 1
    }
    if(isImg2){
      calculateRobotPos(src_image2,1);//calculates and publishes positions, headings, ID's of robots detected by robot 2
    }
    if(isImg3){
      calculateRobotPos(src_image3,2);//calculates and publishes positions, headings, ID's of robots detected by robot 3
    }
    if(isImg4){
      calculateRobotPos(src_image4,3);//calculates and publishes positions, headings, ID's of robots detected by robot 4
    }
    if(isImg5){
      calculateRobotPos(src_image5,4);//calculates and publishes positions, headings, ID's of robots detected by robot 5
    }


    waitKey(25);
    ros::spinOnce();
    loop_rate.sleep();

  }
}
