#include <ros/ros.h>
#include "camera_calibration/camera_calibration.h"
#include "detect_color_object/hsv_range.h"

void setInitialHSVRange(int colorID){//int colorID, int& hlow, int& slow, int& vlow, int&  hhigh, int& shigh, int& vhigh){
  int hlow, slow, vlow, hhigh, shigh, vhigh;
   switch (colorID+1){
    case 1:
        hlow = HSVCOLOR1_RANGE[0];slow = HSVCOLOR1_RANGE[1]; vlow = HSVCOLOR1_RANGE[2];
        hhigh = HSVCOLOR1_RANGE[3];shigh = HSVCOLOR1_RANGE[4];vhigh= HSVCOLOR1_RANGE[5];
        break;
    case 2:
        hlow = HSVCOLOR2_RANGE[0];slow = HSVCOLOR2_RANGE[1];vlow = HSVCOLOR2_RANGE[2];
        hhigh = HSVCOLOR2_RANGE[3];shigh = HSVCOLOR2_RANGE[4];vhigh= HSVCOLOR2_RANGE[5];
        break;
    case 3:
        hlow = HSVCOLOR3_RANGE[0];slow = HSVCOLOR3_RANGE[1];vlow = HSVCOLOR3_RANGE[2];
        hhigh = HSVCOLOR3_RANGE[3];shigh = HSVCOLOR3_RANGE[4];vhigh= HSVCOLOR3_RANGE[5];
        break;
    case 4:
        hlow = HSVCOLOR4_RANGE[0];slow = HSVCOLOR4_RANGE[1];vlow = HSVCOLOR4_RANGE[2];
        hhigh = HSVCOLOR4_RANGE[3];shigh = HSVCOLOR4_RANGE[4];vhigh= HSVCOLOR4_RANGE[5];
        break;
    case 5:
        hlow = HSVCOLOR5_RANGE[0];slow = HSVCOLOR5_RANGE[1];vlow = HSVCOLOR5_RANGE[2];
        hhigh = HSVCOLOR5_RANGE[3];shigh = HSVCOLOR5_RANGE[4];vhigh= HSVCOLOR5_RANGE[5];
        break;
    default:
        break;
      }
      setTrackbarPos("range select ok", "Control", 0);
      setTrackbarPos("LowH", "Control", hlow); //Hue (0 - 179)
      setTrackbarPos("HighH", "Control", hhigh);

      setTrackbarPos("LowS", "Control", slow); //Saturation (0 - 255)
      setTrackbarPos("HighS", "Control", shigh);

      setTrackbarPos("LowV", "Control", vlow); //Value (0 - 255)
      setTrackbarPos("HighV", "Control", vhigh);

}

void setHSV_Range(VideoCapture cap_left,VideoCapture cap_right,int& number_objects,vector<vector <int> >& threshold_settings, Camera_Calibration* calib, bool isCamera, string left_img_name, string right_img_name){
  Mat object_image_l,frame_left,rgb_left, hsv_left;
  Mat object_image_r,frame_right,rgb_right, hsv_right;

  namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

  int iLowH = 0;
  int iHighH = 179;

  int iLowS = 0;
  int iHighS = 255;

  int iLowV = 0;
  int iHighV = 255;

  int nOpen = 5;
  int nClose = 5;
  int ok = 0;

  //Create trackbars in "Control" window
  cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
  cvCreateTrackbar("HighH", "Control", &iHighH, 179);

  cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
  cvCreateTrackbar("HighS", "Control", &iHighS, 255);

  cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
  cvCreateTrackbar("HighV", "Control", &iHighV, 255);

  cvCreateTrackbar("opening element", "Control", &nOpen, 25); //Value (0 - 25)
  cvCreateTrackbar("closing element", "Control", &nClose, 25);
  cvCreateTrackbar("range select ok", "Control", &ok, 1);




  for(int i=0;i<number_objects;i++){
    //setInitialHSVRange(i);
    //setTrackbarPos("range select ok", "Control", 0);
    ok = getTrackbarPos("range select ok", "Control");
    cout << "object : " <<  i << endl;
    vector<int>  temp_color_range;
    setInitialHSVRange(i);
    while(ok==0 && ros::ok()){
      if(isCamera){
        cap_left >> frame_left;
        cap_right >> frame_right;
      }
      else{
        frame_left = imread(left_img_name);//left image
        frame_right = imread(right_img_name);//right image
      }
      calib->applyStereoCalibration(frame_left, frame_right, rgb_left, rgb_right);
      cvtColor(rgb_right, hsv_right, COLOR_BGR2HSV);
      cvtColor(rgb_left, hsv_left, COLOR_BGR2HSV);

      inRange(hsv_right, Scalar(iLowH,iLowS,iLowV), Scalar(iHighH,iHighS,iHighV), object_image_r);
      inRange(hsv_left, Scalar(iLowH,iLowS,iLowV), Scalar(iHighH,iHighS,iHighV), object_image_l);

      // morphological opening (remove small objects from the foreground)
      erode(object_image_r, object_image_r, getStructuringElement(MORPH_RECT, Size(nOpen, nOpen)) );
      dilate( object_image_r, object_image_r, getStructuringElement(MORPH_RECT, Size(nOpen, nOpen)) );
      erode(object_image_l, object_image_l, getStructuringElement(MORPH_RECT, Size(nOpen, nOpen)) );
      dilate( object_image_l, object_image_l, getStructuringElement(MORPH_RECT, Size(nOpen, nOpen)) );

      //morphological closing (fill small holes in the foreground)
      dilate( object_image_r, object_image_r, getStructuringElement(MORPH_RECT, Size(nClose, nClose)) );
      erode(object_image_r, object_image_r, getStructuringElement(MORPH_RECT, Size(nClose, nClose)) );
      dilate( object_image_l, object_image_l, getStructuringElement(MORPH_RECT, Size(nClose, nClose)) );
      erode(object_image_l, object_image_l, getStructuringElement(MORPH_RECT, Size(nClose, nClose)) );
      namedWindow("rgb_left", CV_WINDOW_AUTOSIZE);
      imshow("rgb_left",rgb_left);
      imshow("rgb_right",rgb_right);
      imshow("object_image_l",object_image_l);
      imshow("object_image_r",object_image_r);
      waitKey(25);

    }
    temp_color_range.push_back(iLowH);
    temp_color_range.push_back(iLowS);
    temp_color_range.push_back(iLowV);
    temp_color_range.push_back(iHighH);
    temp_color_range.push_back(iHighS);
    temp_color_range.push_back(iHighV);
    temp_color_range.push_back(nOpen);
    temp_color_range.push_back(nClose);
    temp_color_range.resize(8);
    threshold_settings.push_back(temp_color_range);
    threshold_settings.resize(i+1);
    cout << "HSVCOLOR" << i+1 << "_RANGE[6] ={" << threshold_settings[i][0] <<","<< threshold_settings[i][1] <<","<< threshold_settings[i][2] <<","<< threshold_settings[i][3] <<","<< threshold_settings[i][4] <<","<< threshold_settings[i][5] << "};" << endl;
  }

destroyAllWindows();
}


int main(int argc,char** argv){

    ros::init(argc,argv,"select_hsv_range");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);
    Camera_Calibration* calib  = new Camera_Calibration();

    bool isCamera = 0;
    string left_img_name = "/home/berkay/catkin_ws/src/detect_color_object/images/color_id_left3.jpg";
    string right_img_name = "/home/berkay/catkin_ws/src/detect_color_object/images/color_id_right3.jpg";


    VideoCapture cap_left(1); //left cam
    cap_left.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap_left.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame_left;//initial distorted image
    Mat rgb_left;//undistorted rgb image
    Mat hsv_left;//undistorted hsv image


    VideoCapture cap_right(2); //right cam
    cap_right.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap_right.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    Mat frame_right;//initial distorted image
    Mat rgb_right;//undistorted rgb image
    Mat hsv_right;//undistorted hsv image

    if(!cap_left.isOpened()){
      cout << "there is no camera 1" << endl;
      cout << "images are taken from the file" << endl;
      isCamera = 0;
    }
    if(!cap_right.isOpened()){
      cout << "there is no camera 2" << endl;
      cout << "images are taken from the file" << endl;
      isCamera = 0;
    }

		if(isCamera){
      cap_left >> frame_left;
    }
    else{
      frame_left = imread(left_img_name);//left image
    }

    calib->loadStereoCalibrationParams(frame_left.size());
    int number_objects;
    //HSV RANGE Control
    vector<vector<int> > threshold_settings;
    cout << "enter number of colors: " << endl;
    cin >> number_objects;
    cout << "select 1 at range select slider at GUI for the next color " << endl;
    setHSV_Range(cap_left,cap_right,number_objects,threshold_settings, calib, isCamera, left_img_name, right_img_name );



}
