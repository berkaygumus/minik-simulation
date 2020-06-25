/*
 File name: arucoMarker.cpp
 Author: Berkay Gumus
 E-mail: berkay.gumus@boun.edu.tr
 Date created: 20.05.2020
 Date last modified: 08.06.2020
 */

#include "aruco_marker/arucoMarker.h"

ArucoMarker::ArucoMarker(){

}

ArucoMarker::~ArucoMarker(){

}

void ArucoMarker::markerGenerater(vector<int> robotIDs){

  Mat markerImage;
  //aruco marker dictionary
  Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

/*
The parameters of drawMarker are:

The first parameter is the Dictionary object previously created.
The second parameter is the marker id, in this case the marker 23 of the dictionary DICT_6X6_250. Note that each dictionary is composed of a different number of markers. In this case, the valid ids go from 0 to 249. Any specific id out of the valid range will produce an exception.
The third parameter, 200, is the size of the output marker image. In this case, the output image will have a size of 200x200 pixels. Note that this parameter should be large enough to store the number of bits for the specific dictionary. So, for instance, you cannot generate an image of 5x5 pixels for a marker size of 6x6 bits (and that is without considering the marker border). Furthermore, to avoid deformations, this parameter should be proportional to the number of bits + border size, or at least much higher than the marker size (like 200 in the example), so that deformations are insignificant.
The fourth parameter is the output image.
Finally, the last parameter is an optional parameter to specify the width of the marker black border. The size is specified proportional to the number of bits. For instance a value of 2 means that the border will have a width equivalent to the size of two internal bits. The default value is 1.
*/

/*
aruco marker arrangement on the robot
front: 4*(id-1) + 1
right: 4*(id-1) + 2
back: 4*(id-1) + 3
left: 4*(id-1) + 4
*/

  for(int i=0;i<robotIDs.size();i++){
    int robotID = robotIDs[i];
    ostringstream id;
    id << robotIDs[i];
    aruco::drawMarker(dictionary, 4*(robotID-1)+1, 200, markerImage, 1);//creates aruco marker
    imwrite(aruco_marker_folder + "robot" + id.str() + "front.jpg", markerImage);
    aruco::drawMarker(dictionary, 4*(robotID-1)+2, 200, markerImage, 1);
    imwrite(aruco_marker_folder + "robot" + id.str()  + "right.jpg", markerImage);
    aruco::drawMarker(dictionary, 4*(robotID-1)+3, 200, markerImage, 1);
    imwrite(aruco_marker_folder + "robot" + id.str()  + "back.jpg", markerImage);
    aruco::drawMarker(dictionary, 4*(robotID-1)+4, 200, markerImage, 1);
    imwrite(aruco_marker_folder + "robot" + id.str()  + "left.jpg", markerImage);
  }

  cout << "markers are generated" << endl;
}

void ArucoMarker::img11callback(const sensor_msgs::Image::ConstPtr& msg){

  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  imshow("msg image", cv_ptr->image);
    //src_image = msg->data;
    cout << "callback " << endl;
    waitKey(10);
    src_image = cv_ptr->image;
    start = 1;

}

void ArucoMarker::setCamParameters(){
  Camera_Calibration* calib  = new Camera_Calibration();
  calib->loadCameraCalibrationParams();

  //cameraMatrix = calib->getMonoCalibCamMat();// (Mat_<double>(3,3) << 371.42398 ,    0.00000 ,  312.84805 ,  0.00000 ,  371.39846 ,  231.62992 ,  0.00000 ,    0.00000 ,    1.00000);
  //distCoeffs = calib->getMonoCalibDistMat(); //
  //distCoeffs = (Mat_<double>(1,4) <<  -0.2180602166232231, 0.4587474927427831, -0.8959683693934485, 0.5567232386016293);
/*
  cameraMatrix = (Mat_<double>(3,3) << 371.42398 ,    0.00000 ,  312.84805 ,  0.00000 ,  371.39846 ,  231.62992 ,  0.00000 ,    0.00000 ,    1.00000);
  distCoeffs = (Mat_<double>(1,5) <<  -0.36019 ,    0.19207 ,    0.00165 ,  -0.00967 ,  -0.06027);
*/
  cameraMatrix = (Mat_<double>(3,3) << 278.0000, 0.0000 ,  320.0000 ,  0.00000 ,  278.0000 ,  240.0000 ,  0.0000 ,    0.0000 ,    1.00000);
  distCoeffs = (Mat_<double>(1,5) <<  0 ,    0 ,    0 ,  0 ,  0);

  cout << "cam mat: " << cameraMatrix << endl;
  cout << "dist mat: " << distCoeffs << endl;
}

void ArucoMarker::calculateRobotPos(){
  ros::Rate loop_rate(10);

  //dictionary for detection
  cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

  //video capture initialization
  VideoCapture cap(cameraID);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

  if(!cap.isOpened()){
        isCamera = 0;
        cout << "there is no camera " << cameraID << endl;
        cout << "images are taken from the file: " << input_img_name << endl;
    }


  //cap >> src_image;

  //sets camera parameters: camera matrix and distortion coefficients
  setCamParameters();

  //publisher for robot pos and angle
  ros::Publisher robotsPublisher = n.advertise<ISLH_msgs::robotPositions>("robot_list",1);
  ros::Subscriber img11sub = n.subscribe("/robot1/multisense_sl/camera/left/image_raw",1000,&ArucoMarker::img11callback,this);

  while(ros::ok()){

    while(start==0){
      cout << "waiting" << endl;
      waitKey(25);
      ros::spinOnce();
    }
    //video capture
    /*if(isCamera){
      cap >> src_image;
    }
    else{
      src_image = imread(input_img_name);
    }*/


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
    aruco::estimatePoseSingleMarkers(corners, 0.15, cameraMatrix, distCoeffs, rvecs, tvecs);

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
        cv::Vec3d rvec = rvecs[i]; //position vector
        cv::Vec3d tvec = tvecs[i]; //rotation vector
        int aruco_id = marker_IDs[i];  //marker ID
        //cout << "id i: " << marker_IDs[i] <<  endl;
        //cout << "rvec: " << endl;
        //cout << rvec*180/M_PI << endl;

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


        Mat rotM = Mat::zeros(3,3, CV_32F);//rotation matrix
        Mat jacobian;
        Rodrigues(rvec, rotM, jacobian); //calculates rotation matrix using rotation vector
        Mat mtxR,mtxQ;
        Vec3d angles = RQDecomp3x3(rotM, mtxR, mtxQ); //calculates angles around axes using rotation matrix

        double y_angle = angles[1];//related axis is y axis
        y_angle = - y_angle + 180; //correction for the camera frame
        double heading = y_angle + 90*(side-1); //heading from the side and its angle
        if(heading> 180){
          heading = heading - 360;
        }
        //cout << "heading:  " << heading << endl;
        positions.push_back(tvec);
        headings.push_back(heading);
        robot_IDs.push_back(robot_id);

        //cout << "tvec: " << endl;
        //cout << tvec << endl;
        aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvec, tvec, 10);//draws axes of markers detected on imageCopy
    }

    for(int i=0; i < positions.size();i++){
      cout << "ID: " << robot_IDs[i] << " pos: " << positions[i] << " heading: " <<  headings[i] << endl;
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


    cv::imshow("out", imageCopy); //shows image with markers detected

    ISLH_msgs::robotPositions msg; //message to publish: -> geometry_msgs::Pose2D[] positions
                                  //                     -> float32[] directions
                                  //                     -> int32[] IDs

    vector<geometry_msgs::Pose2D > msg_positions; //pos vector
    for(int i=0;i<robot_IDs.size();i++){
      geometry_msgs::Pose2D temp_pos; //temp pos
      temp_pos.x = positions[i][2]; //related axis is z
      temp_pos.y = -positions[i][0]; //related axis is -x
      temp_pos.theta = headings[i];

      msg_positions.push_back(temp_pos);
    }

      msg.positions = msg_positions;
      msg.directions = headings;
      msg.IDs = robot_IDs;

      robotsPublisher.publish(msg);

    waitKey(25);
    ros::spinOnce();
    loop_rate.sleep();

    /*if(!isCamera){
      waitKey(0);
    }*/

  }
}
