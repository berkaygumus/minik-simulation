#include <ros/ros.h>
#include "camera_calibration/camera_calibration.h"
#include "detect_color_object/hsv_range.h"
#include <geometry_msgs/Pose2D.h>

struct object_pos
{
    double x;
    double y;
    double radius;
};


void setHSVRange(int colorID, int& hlow, int& slow, int& vlow, int&  hhigh, int& shigh, int& vhigh){

    switch (colorID){
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

}

Mat colorThreshold(int colorID, Mat hsv_image, int himsizex, int himsizey){
    int hlow, slow, vlow,  hhigh,  shigh, vhigh;
    //sets hsv ranges, defined at detect_color_object/hsv_range.h
    setHSVRange( colorID,  hlow,  slow,  vlow,   hhigh,  shigh,  vhigh);
    resize(hsv_image,hsv_image,Size(himsizex,himsizey));
    Mat object_image;
    inRange(hsv_image, Scalar(hlow,slow,vlow), Scalar(hhigh,shigh,vhigh), object_image);

    return object_image;
 }

 Mat  enhanceImg(Mat obs_r1, int sizex,int sizey){

     // morphological opening (remove small objects from the foreground)

     erode(obs_r1, obs_r1, getStructuringElement(MORPH_RECT, Size(15, 15)) );
     dilate( obs_r1, obs_r1, getStructuringElement(MORPH_RECT, Size(15, 15)) );

     //morphological closing (fill small holes in the foreground)
     dilate( obs_r1, obs_r1, getStructuringElement(MORPH_RECT, Size(15, 15)) );
     erode(obs_r1, obs_r1, getStructuringElement(MORPH_RECT, Size(15, 15)) );

     resize(obs_r1,obs_r1,Size(sizex,sizey));
     return obs_r1;

 }

 void findMaxSizedComponent(Mat stats, int nlabels, int& max_area, int& numbersaved){
     max_area=0;
     for (int i=1;i<nlabels;i++)
     {
         int area=stats.at<int>(i,4);
         if(area>max_area){
             max_area=area;
             numbersaved=i;
         }
     }

 }

 object_pos detectObject(Mat hsv_left,Mat hsv_right, int robot_id, Camera_Calibration* calib){
   //takes left and right hsv images, robot id and calibration parameters,
   //calculates position and radius, returns object_pos(x,y, radius)

   //defined at globaldefs.h
   float himsizex = WEBCAM_FOV_WIDTH_PIXELS*SAMPLING_FACTOR; //width in terms of pixel
   float himsizey = WEBCAM_FOV_HEIGHT_PIXELS*SAMPLING_FACTOR; //height in terms of pixel

   //threshold for the object with HSV range
   Mat object_r(Size(himsizex,himsizey), CV_8U);
   Mat object_l(Size(himsizex,himsizey), CV_8U );
   //color threshold(hsv range)
   object_l = colorThreshold(robot_id, hsv_left, himsizex,himsizey);
   object_r = colorThreshold(robot_id, hsv_right, himsizex,himsizey);
   //imshow("object_l",object_l);
   //imshow("object_r",object_r);

   //erode and dilate
   object_l = enhanceImg(object_l,himsizex,himsizey);
   object_r = enhanceImg(object_r,himsizex,himsizey);
   imshow("enhanced object_l",object_l);
   imshow("enhanced object_r",object_r);

   //the components of binary images
   Mat stats_left, centroids_left,stats_right, centroids_right;
   Mat labelImage_right(object_r.size(), CV_32S );
   int n_labels_right = connectedComponentsWithStats(object_r, labelImage_right, stats_right, centroids_right, 8, CV_32S);

   Mat labelImage_left(object_l.size(), CV_32S );
   int n_labels_left =  connectedComponentsWithStats(object_l, labelImage_left, stats_left, centroids_left, 8, CV_32S);

   // the biggest component
   int max_right, max_left;
   int numbersavedr, numbersavedl;
   findMaxSizedComponent(stats_left, n_labels_left, max_left, numbersavedl);
   findMaxSizedComponent(stats_right, n_labels_right, max_right,  numbersavedr);
   //cout << "max right area: " << max_right << "max left area: " << max_left << endl;

   Point a1,a2;//the top left points of the biggest components at the right and left image
   int width_right, width_left;

   if ( max_right > MIN_COMPONENT_AREA_THRESHOLD && max_left >MIN_COMPONENT_AREA_THRESHOLD ) //eliminates if object is a little behind of something
   {
       //cout<<"centroids"<<i<<endl<<centroids_right.at<double>(i,0)<<" "<<centroids_right.at<double>(i,1)<<endl;
       a1.x =centroids_right.at<double>(numbersavedr,0); a1.y=centroids_right.at<double>(numbersavedr,1);
       width_right=stats_right.at<int>(numbersavedr,2);
       //cout<<a1.x<< " " <<a1.y<< " " <<width_right<<endl;

       a2.x=centroids_left.at<double>(numbersavedl,0); a2.y=centroids_left.at<double>(numbersavedl,1);
       width_left=stats_left.at<int>(numbersavedl,2);
       //cout<<a2.x<< " " <<a2.y<< " " <<width_left<<endl;

   }
   else
   {
     //cout << "there is no object"<< endl;
     object_pos object;
     object.x = -1;
     object.y = -1;
     object.radius = -1;

     return object;
   }

   //cout << "right center: " << a1.x << " " << a1.y << endl;
   //cout << "left center: " << a2.x << " " << a2.y << endl;

   circle(object_r, a1, width_right/2, 50, 5);
   circle(object_l, a2, width_left/2, 50, 5);

   imshow("enhanced object_l",object_l);
   imshow("enhanced object_r",object_r);

   float d_obs;
   double distance_x_obs;
   double distance_y_obs;

   double cam_ang=49;//atan(304/263)*180/pi;// cx/fx WEBCAM_PAN_FOV/2;
   //cout << "fow angle: " << 2*cam_ang << endl;
   //base distance
   Mat cam_mat = calib->getStereoCameraBaseline();
   double b=norm(cam_mat,NORM_L2);
   //focal length
   int f = 263;//=calib->getCameraFocalLength().at<float>(0,0) but it gives wrong value?

   int imcenterpan = WEBCAM_FOV_WIDTH_PIXELS*SAMPLING_FACTOR*0.5;//width/2

   double radius_obs = (width_left+ width_right)/2;

   // angle calculations
   double y_shift_obs = -imcenterpan + (a1.x+a2.x)/2;
   double shift_degree_obs = atan(tan( M_PI * cam_ang/ PI_DEG )* y_shift_obs / imcenterpan);

   double shift_degree_max_obs, shift_degree_min_obs;


   if (y_shift_obs < 0){
       shift_degree_max_obs =atan( (y_shift_obs - radius_obs/2) / imcenterpan *tan( M_PI * cam_ang/ PI_DEG ));
       shift_degree_min_obs = atan( (y_shift_obs + radius_obs/2) / imcenterpan *tan( M_PI * cam_ang / PI_DEG ));
   }
   else{
       shift_degree_max_obs = atan( (y_shift_obs + radius_obs/2) / imcenterpan *tan( M_PI * cam_ang / PI_DEG ));
       shift_degree_min_obs = atan( (y_shift_obs - radius_obs/2) / imcenterpan *tan( M_PI * cam_ang/ PI_DEG ));
 }


   // d >> pixel distance between left and right images

   d_obs= fabs(a2.x-a1.x);//disparity
   //cout << "d_obs " << d_obs << endl;
   //cout << "f " << f << endl;//focal length
   //cout << "b " << b << endl;//base distance
   float dummy_radius;

   //position calculations
   distance_x_obs = b*f/d_obs;
   distance_y_obs = -distance_x_obs * tan(shift_degree_obs);
   dummy_radius= fabs(distance_x_obs * tan(shift_degree_max_obs) - distance_x_obs * tan(shift_degree_min_obs) );

   //cout << "x y radius: " << distance_x_obs << " " << distance_y_obs << " " << dummy_radius<<  endl;

   object_pos object;
   object.x = distance_x_obs;
   object.y = distance_y_obs;
   object.radius = dummy_radius;

   return object;
 }


int main(int argc,char** argv){

    ros::init(argc,argv,"color_object");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    //Publishers for robot 1 and robot2 positions, new robots can be added.
    ros::Publisher robotPublisher1 = n.advertise<geometry_msgs::Pose2D>("robot1", 1);
    ros::Publisher robotPublisher2 = n.advertise<geometry_msgs::Pose2D>("robot2", 1);


    Camera_Calibration* calib  = new Camera_Calibration();

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
          cout << "ERROR cam1!!" << endl;
          exit(1);
    }
    if(!cap_right.isOpened()){
          cout << "ERROR cam2!!" << endl;
          exit(1);
    }


    cap_left >> frame_left;
    calib->loadStereoCalibrationParams(frame_left.size());//loads camera calibration parameters.

    int number_objects;//2: robot1 and robot2

    //cout << "enter number of objects: " << endl;
    //cin >> number_objects;
    number_objects = 2;


    while(ros::ok()){
      ros::Time begin = ros::Time::now();
      //capture images
      cap_left >> frame_left;
      cap_right >> frame_right;
      cout << "elapsed capture : " << ros::Time::now() - begin << endl;

      //stereo calibration
      calib->applyStereoCalibration(frame_left, frame_right, rgb_left, rgb_right);
      //imshow("init_left",frame_left);
      //imshow("init_right",frame_right);
      //imshow("undist_left",rgb_left);
      //imshow("undist_right",rgb_right);
      cout << "elapsed calib : " << ros::Time::now() - begin << endl;

      //rgb to hsv
      cvtColor(rgb_right, hsv_right, COLOR_BGR2HSV);
      cvtColor(rgb_left, hsv_left, COLOR_BGR2HSV);
      cout << "elapsed hsv : " << ros::Time::now() - begin << endl;

      //pos calculation
      object_pos object1;
      object1 = detectObject(hsv_left,hsv_right, 1,calib);//detects robot and calculates its position and radius
      cout << "object 1 pos " << object1.x << " " << object1.y << " " << object1.radius << endl;
      geometry_msgs::Pose2D robotPose1;
      robotPose1.x = object1.x;
      robotPose1.y = object1.y;
      robotPublisher1.publish(robotPose1);
      cout << "elapsed object1 : " << ros::Time::now() - begin << endl;

      object_pos object2;
      object2 = detectObject(hsv_left,hsv_right, 2,calib);
      cout << "object 2 pos " << object2.x << " " << object2.y << " " << object2.radius << endl;
      geometry_msgs::Pose2D robotPose2;
      robotPose2.x = object2.x;
      robotPose2.y = object2.y;
      robotPublisher2.publish(robotPose2);
      cout << "elapsed object2 : " << ros::Time::now() - begin << endl;

      waitKey(25);
      ros::spinOnce();
      loop_rate.sleep();
    }
}
