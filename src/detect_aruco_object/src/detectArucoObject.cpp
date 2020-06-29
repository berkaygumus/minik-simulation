/*
 File name: detectArucoObject.cpp
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified: 08.06.2020
 */

#include "detect_aruco_object/detectArucoObject.h"

DetectArucoObject::DetectArucoObject(){

}

DetectArucoObject::~DetectArucoObject(){

}

void DetectArucoObject::img1callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  //imshow("msg image1", cv_ptr->image);
    //src_image = msg->data;
    //cout << "callback1 " << endl;
  //  waitKey(10);
    src_image1 = cv_ptr->image;
    isImg1 = 1;
}

void DetectArucoObject::img2callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  //imshow("msg image2", cv_ptr->image);
    //src_image = msg->data;
    //cout << "callback2 " << endl;
    //waitKey(10);
    src_image2 = cv_ptr->image;
    isImg2 = 1;
}

void DetectArucoObject::img3callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  //imshow("msg image3", cv_ptr->image);
    //src_image = msg->data;
    //cout << "callback3 " << endl;
    //waitKey(10);
    src_image3 = cv_ptr->image;
    isImg3 = 1;
}

void DetectArucoObject::odom1callback(const geometry_msgs::Pose::ConstPtr& msg){
   odomPos[0][0] =  msg->position.x;
   odomPos[0][1] =  msg->position.y;
   odomPos[0][2] =  msg->position.z;
   //cout << "odom1: " << odomPos[0][0] << endl;

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


void DetectArucoObject::calculateRobotPos(Mat src_image, int id){
  cout << endl << "ID " << id << "////////////////////////////" << endl;
  Mat cameraMatrix = (Mat_<double>(3,3) << 278.0000, 0.0000 ,  320.0000 ,  0.00000 ,  278.0000 ,  240.0000 ,  0.0000 ,    0.0000 ,    1.00000);
  Mat distCoeffs = (Mat_<double>(1,5) <<  0 ,    0 ,    0 ,  0 ,  0);

  cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
  cv::Mat image,imageCopy;
  src_image.copyTo(image);
  image.copyTo(imageCopy);
  vector<int> marker_IDs; //marker ID vector
  vector<vector<Point2f> > corners; //marker corners vector

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

  vector<Vec3d> positions; //position vector for each marker
  vector<float> headings; //heading of the robot (the angle around z axis) vector for each marker
  vector<int> robot_IDs; //robotID vector
  for (int i = 0; i < rvecs.size(); ++i) {
      cv::Vec3d tvec = tvecs[i]; //position vector
      cv::Vec3d rvec = rvecs[i]; //rotation vector
      int aruco_id = marker_IDs[i];  //marker ID
      //cout << "id i: " << marker_IDs[i] <<  endl;
      //cout << "rvec: " << endl;
      //cout << rvec*180/M_PI << endl;




      Mat rotM = Mat::zeros(3,3, CV_32F);//rotation matrix
      Mat jacobian;
      Rodrigues(rvec, rotM, jacobian); //calculates rotation matrix using rotation vector
      Mat mtxR,mtxQ;
      Vec3d angles = RQDecomp3x3(rotM, mtxR, mtxQ); //calculates angles around axes using rotation matrix(in terms of degree)

      double y_angle = angles[1];//related axis is y axis
      //aruco marker detection frame is different from the odometry frame
      //aruco marker pos and theta, not robot pos and theta
      double arucoPosX = tvec[2];
      double arucoPosY = -tvec[0];
      double arucoPosTheta = -y_angle + 180 ;
      //cout <<"odom frame aruco: x: " << arucoPosX << " y: " << arucoPosY << " theta: " << arucoPosTheta << endl;

      double l = 0.15;//distance between marker and center of robot observed
      arucoPosTheta = arucoPosTheta * PI /180 ;
      double robotPosX = arucoPosX - l * cos(arucoPosTheta) + 0.15;//the distance between stereo camera and observer robot center is 0.15
      double robotPosY = arucoPosY - l * sin(arucoPosTheta) + 0.05;//the source image comes from left cam, the shift is 0.05
      //cout <<"odom frame robot: x: " << robotPosX << " y: " << robotPosY << endl;

      /*
      aruco marker arrangement on the robot
      front: 4*(id-1) + 1
      right: 4*(id-1) + 2
      back: 4*(id-1) + 3
      left: 4*(id-1) + 4
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

  for(int i=0; i < positions.size();i++){
    //cout << "ID: " << robot_IDs[i] << " pos: " << positions[i] << " heading: " <<  headings[i] << endl;
  }


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
    cout << "ID: " << robot_IDs[i] << " combined pos: " << positions[i] << " combined heading: " <<  headings[i] << endl;
  }

  ostringstream ss;
  ss << id +1;
  string name =  "robot" + ss.str();
  cv::imshow(name, imageCopy); //shows image with markers detected

  //positions with respect to current robot frame are done,
  //but these posiitons must be converted wrt initial robot frame

  //obser robot pos and theta
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


  ////////////////////////////////////////////////////////////////////////////////

  ISLH_msgs::robotPositions msg; //message to publish: -> geometry_msgs::Pose2D[] positions
                                //                     -> float32[] directions
                                //                     -> int32[] IDs

  vector<geometry_msgs::Pose2D > msg_positions; //pos vector
  for(int i=0;i<robot_IDs.size();i++){
    geometry_msgs::Pose2D temp_pos; //temp pos
    temp_pos.x = positions[i][0];
    temp_pos.y = positions[i][1];
    temp_pos.theta = headings[i];

    msg_positions.push_back(temp_pos);
  }

    msg.positions = msg_positions;
    msg.directions = headings;
    msg.IDs = robot_IDs;



    robotsPublisher[id].publish(msg);
    cout << "published" << endl;

}



void DetectArucoObject::work(){
  ros::Rate loop_rate(10);


  ros::Subscriber img1sub = n.subscribe("/robot1/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img1callback,this);
  ros::Subscriber img2sub = n.subscribe("/robot2/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img2callback,this);
  ros::Subscriber img3sub = n.subscribe("/robot3/multisense_sl/camera/left/image_raw",1000,&DetectArucoObject::img3callback,this);

  ros::Subscriber odom1sub = n.subscribe("/odom1",1000,&DetectArucoObject::odom1callback,this);
  ros::Subscriber odom2sub = n.subscribe("/odom2",1000,&DetectArucoObject::odom2callback,this);
  ros::Subscriber odom3sub = n.subscribe("/odom3",1000,&DetectArucoObject::odom3callback,this);

  robotsPublisher[0] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco1",1);
  robotsPublisher[1] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco2",1);
  robotsPublisher[2] = n.advertise<ISLH_msgs::robotPositions>("detected_aruco3",1);

  while(ros::ok()){
    if(isImg1){
      calculateRobotPos(src_image1,0);
    }
    if(isImg2){
      calculateRobotPos(src_image2,1);
    }
    if(isImg3){
      calculateRobotPos(src_image3,2);
    }

    waitKey(25);
    ros::spinOnce();
    loop_rate.sleep();

  }
}
