#include <ros/ros.h>
#include "camera_calibration/camera_calibration.h"

#include <geometry_msgs/Pose2D.h>
#include "ISLH_msgs/robotPositions.h"
#include "detect_color_object/robot_IDs.h"
#include "detect_color_object/hsv_range.h"
#include "float.h"

typedef struct Marker{
	Point2f pos;
	int color; // Blue, Red, Yellow, Green
} Marker;
class Robot{
public:
	Marker top;
	Marker bottom;

	Point2f center;
	int ID;
	Robot(){ ID = 0;}
};
class Group{
public:
	vector<Marker> markers;
	Point2f center;
	Group(){}
};

inline double getDist(Point2f p1, Point2f p2){
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool isInGroups(vector<Group> *groups, Marker m){
	for (unsigned i = 0; i < groups->size(); i++){
		Group g = groups->at(i);
		for (unsigned j = 0; j < g.markers.size(); j++){
			Marker _m = g.markers[j];
			if (_m.pos == m.pos && _m.color == m.color) return true;
		}
	}
	return false;
}

void colorCircle(Mat img, int x, int y, int radius, Scalar color, int thickness = 2) {
	int lineType = 8;

	ellipse(img,
		Point(x, y),
		Size(radius, radius),
		0,
		0,
		360,
		color,
		thickness,
		lineType);
}

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

void  enhanceImg(Mat &image){

     // morphological opening (remove small objects from the foreground)

     erode(image, image, getStructuringElement(MORPH_RECT, Size(15, 15)) );
     dilate( image, image, getStructuringElement(MORPH_RECT, Size(15, 15)) );

     //morphological closing (fill small holes in the foreground)
     dilate( image, image, getStructuringElement(MORPH_RECT, Size(15, 15)) );
     erode(image, image, getStructuringElement(MORPH_RECT, Size(15, 15)) );
}


void getColorImage(Mat &image, Mat &image_r, Mat &image_g, Mat &image_b){
    int hlow, slow, vlow,  hhigh,  shigh, vhigh;

    setHSVRange(1,  hlow,  slow,  vlow,   hhigh,  shigh,  vhigh);
    inRange(image, Scalar(hlow,slow,vlow), Scalar(hhigh,shigh,vhigh), image_r);
    enhanceImg(image_r);

    setHSVRange(2,  hlow,  slow,  vlow,   hhigh,  shigh,  vhigh);
    inRange(image, Scalar(hlow,slow,vlow), Scalar(hhigh,shigh,vhigh), image_g);
    enhanceImg(image_g);

    setHSVRange(3,  hlow,  slow,  vlow,   hhigh,  shigh,  vhigh);
    inRange(image, Scalar(hlow,slow,vlow), Scalar(hhigh,shigh,vhigh), image_b);
    enhanceImg(image_b);

 }

 vector<Point2f> getMC(Mat *img){
 	Mat bw;
 	bw = *img;
 	vector<vector<Point> > contours;
 	findContours(bw, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
 	/// Get the moments
 	vector<Moments> mu;
 	for (unsigned i = 0; i < contours.size(); i++)
 		mu.push_back(moments(contours[i], false));
 	/// mu[i].m00 is the area of contour
 	for (unsigned i = 0; i < mu.size(); i++){
 		if (mu[i].m00 == 0){
 			mu.erase(mu.begin() + i);
 			i--;
 			continue;
 		}
 		/*double factor = getDist(Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00),Point2f(640 / 2.0, 480 / 2.0)) / 250 + 1;
    cout << "factor: " << factor << endl;
 		if (mu[i].m00 * factor < 150 ||
 			mu[i].m00 * factor > 550){
 			mu.erase(mu.begin() + i);
 			i--;
 		}*/
 	}
 	///  Get the mass centers:
 	vector<Point2f> mc;
 	for (unsigned i = 0; i < mu.size(); i++)
 		mc.push_back(Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00));

 	return mc;
 }

 void checkC(vector<Point2f> &v1, vector<Point2f> &v2, vector<Point2f> &v3){
   int max_dist_x = 10;
   int min_dist_y = 2;
 	for (unsigned i = 0; i < v1.size(); i++){
 		Point2f p = v1[i];
 		int neigh = 0;
 		for (unsigned j = 0; j < v1.size(); j++){
 			Point2f p2 = v1[j];
 			double dst_x = abs(p.x- p2.x);
      double dst_y = abs(p.y- p2.y);
 			if (dst_x == 0 && dst_y == 0) continue;
 			if (dst_x < max_dist_x && dst_y > min_dist_y) neigh++;
 		}
 		for (unsigned j = 0; j < v2.size(); j++){
 			Point2f p2 = v2[j];
      double dst_x = abs(p.x- p2.x);
      double dst_y = abs(p.y- p2.y);
 			if (dst_x == 0 && dst_y == 0) continue;
 			if (dst_x < max_dist_x && dst_y > min_dist_y) neigh++;
 		}
 		for (unsigned j = 0; j < v3.size(); j++){
 			Point2f p2 = v3[j];
      double dst_x = abs(p.x- p2.x);
      double dst_y = abs(p.y- p2.y);
 			if (dst_x == 0 && dst_y == 0) continue;
 		  if (dst_x < max_dist_x && dst_y > min_dist_y) neigh++;
 		}
 		if (neigh != 1){
 			v1.erase(v1.begin() + i);
 			i--;
 		}
 	}
 }

 void checkConsistency(vector<vector<Point2f> > &mcs){
 	checkC(mcs[0], mcs[1], mcs[2]);
 	checkC(mcs[1], mcs[0], mcs[2]);
 	checkC(mcs[2], mcs[1], mcs[0]);
 }

 Robot calculatePos(Robot r_l, Robot r_r, Camera_Calibration* calib){

	float himsizex = WEBCAM_FOV_WIDTH_PIXELS*SAMPLING_FACTOR; //width in terms of pixel
	float himsizey = WEBCAM_FOV_HEIGHT_PIXELS*SAMPLING_FACTOR; //height in terms of pixel


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

	//double radius_obs = (width_left+ width_right)/2;

	// angle calculations
	double y_shift_obs = -imcenterpan + (r_l.center.x + r_r.center.x)/2;
	double shift_degree_obs = atan(tan( M_PI * cam_ang/ PI_DEG )* y_shift_obs / imcenterpan);

	/*double shift_degree_max_obs, shift_degree_min_obs;


	if (y_shift_obs < 0){
			shift_degree_max_obs =atan( (y_shift_obs - radius_obs/2) / imcenterpan *tan( M_PI * cam_ang/ PI_DEG ));
			shift_degree_min_obs = atan( (y_shift_obs + radius_obs/2) / imcenterpan *tan( M_PI * cam_ang / PI_DEG ));
	}
	else{
			shift_degree_max_obs = atan( (y_shift_obs + radius_obs/2) / imcenterpan *tan( M_PI * cam_ang / PI_DEG ));
			shift_degree_min_obs = atan( (y_shift_obs - radius_obs/2) / imcenterpan *tan( M_PI * cam_ang/ PI_DEG ));
}*/


	// d >> pixel distance between left and right images

	d_obs= fabs(r_l.center.x - r_r.center.x);//disparity
	//cout << "d_obs " << d_obs << endl;
	//cout << "f " << f << endl;//focal length
	//cout << "b " << b << endl;//base distance
	float dummy_radius;

	//position calculations
	distance_x_obs = b*f/d_obs;
	distance_y_obs = -distance_x_obs * tan(shift_degree_obs);
	//dummy_radius= fabs(distance_x_obs * tan(shift_degree_max_obs) - distance_x_obs * tan(shift_degree_min_obs) );

	//cout << "x y radius: " << distance_x_obs << " " << distance_y_obs << " " << dummy_radius<<  endl;

	Robot robot;
	robot.center.x = distance_x_obs/10;//mm to cm
	robot.center.y = distance_y_obs/10;//mm to cm
	//object.radius = dummy_radius;

	return robot;
}


 vector<Robot> findRobots(vector<vector<Point2f> > mcs_l, vector<vector<Point2f> > mcs_r,Camera_Calibration* calib){
 	/// Find Groups of 3 Markers
  int max_dist_x = 10;
  int min_dist_y = 2;
 	vector<Group> groups_l;
 	for (unsigned coli = 0; coli < 3; coli++){
 		for (unsigned mari = 0; mari < mcs_l[coli].size(); mari++){
 			Marker marker;
 			marker.color = coli;
 			marker.pos = mcs_l[coli][mari];
 			if (isInGroups(&groups_l, marker)) continue;
 			Group g;
 			g.markers.push_back(marker);
 			for (unsigned colj = 0; colj < 3; colj++){
 				for (unsigned marj = 0; marj < mcs_l[colj].size(); marj++){
 					if (coli == colj && mari == marj) continue;

 					//double dist = getDist(mcs_l[coli][mari], mcs_l[colj][marj]);
          double dst_x = abs(mcs_l[coli][mari].x- mcs_l[colj][marj].x);
          double dst_y = abs(mcs_l[coli][mari].y- mcs_l[colj][marj].y);
 					if (dst_x < max_dist_x && dst_y > min_dist_y){
 						Marker m;
 						m.color = colj;
 						m.pos = mcs_l[colj][marj];
 						g.markers.push_back(m);
 					}
 				}
 			}
 			groups_l.push_back(g);
 		}
 	}


 	//std::cout << "Group left size: " << groups_l.size() << endl;

  /*for(int i=0;i<groups_l.size();i++){
    cout << "left colors: " << groups_l[i].markers[0].color << groups_l[i].markers[1].color << endl;
  }*/

  vector<Group> groups_r;
 	for (unsigned coli = 0; coli < 3; coli++){
 		for (unsigned mari = 0; mari < mcs_r[coli].size(); mari++){
 			Marker marker;
 			marker.color = coli;
 			marker.pos = mcs_r[coli][mari];
 			if (isInGroups(&groups_r, marker)) continue;
 			Group g;
 			g.markers.push_back(marker);
 			for (unsigned colj = 0; colj < 3; colj++){
 				for (unsigned marj = 0; marj < mcs_r[colj].size(); marj++){
 					if (coli == colj && mari == marj) continue;

 					//double dist = getDist(mcs_r[coli][mari], mcs_r[colj][marj]);
          double dst_x = abs(mcs_r[coli][mari].x- mcs_r[colj][marj].x);
          double dst_y = abs(mcs_r[coli][mari].y- mcs_r[colj][marj].y);
 					if (dst_x < max_dist_x && dst_y > min_dist_y){
 						Marker m;
 						m.color = colj;
 						m.pos = mcs_r[colj][marj];
 						g.markers.push_back(m);
 					}
 				}
 			}
 			groups_r.push_back(g);
 		}
 	}

 	//std::cout << "Group right size: " << groups_r.size() << std::endl;
  /*for (int i=0;i<groups_r.size();i++){
    cout << "right colors: " << groups_r[i].markers[0].color << groups_r[i].markers[1].color << endl;
  }*/

 	/// Create Robot class for each correct group
 	vector<Robot> robots_l;
  vector<Robot> robots_r;

  /*if (groups_r.size() != groups_l.size()){
    return robots;
  }*/

  //robots at left image
 	for (unsigned groi = 0; groi < groups_l.size(); groi++){
 		Robot r;
 		Group g = groups_l[groi];

 		/// If group doesn't have 2 marker than it is not correct
 		if (g.markers.size() != 2 )
 			continue;

    double y0 = g.markers[0].pos.y;
    double y1 = g.markers[1].pos.y;
    if(y0 < y1){
      r.top = g.markers[0];
      r.bottom = g.markers[1];
    }
    else{
      r.top = g.markers[1];
      r.bottom = g.markers[0];
    }
 		/// Find ID of the robot
 		r.ID = -1;
 		for (int i = 0; i < numrobots; i++){
 			if (r.top.color == robIDList[i][0] && r.bottom.color == robIDList[i][1]){
 				r.ID = i + 1;
        cout << "robot left is found and id: " << 	r.ID << endl;
 				break;
 			}
 		}
 		if (r.ID == -1)
 			continue;

 		/// Find center position
 		double x = (r.top.pos.x + r.bottom.pos.x ) / 2;
 		double y = (r.top.pos.y + r.bottom.pos.y ) / 2;
 		r.center = Point2f(x, y);

 		robots_l.push_back(r);
 	}

  //std::cout << "robot left :" << robots_l.size() << std::endl;

  //robots at right image
  for (unsigned groi = 0; groi < groups_r.size(); groi++){
 		Robot r;
 		Group g = groups_r[groi];

 		/// If group doesn't have 2 marker than it is not correct
 		if (g.markers.size() != 2)
 			continue;

    double y0 = g.markers[0].pos.y;
    double y1 = g.markers[1].pos.y;
    if(y0 < y1){
      r.top = g.markers[0];
      r.bottom = g.markers[1];
    }
    else{
      r.top = g.markers[1];
      r.bottom = g.markers[0];
    }
 		/// Find ID of the robot
 		r.ID = -1;
 		for (int i = 0; i < numrobots; i++){
 			if (r.top.color == robIDList[i][0] && r.bottom.color == robIDList[i][1]){
 				r.ID = i + 1;
        cout << "robot right is found and id: " << 	r.ID << endl;
 				break;
 			}
 		}
 		if (r.ID == -1)
 			continue;

 		/// Find center position
 		double x = (r.top.pos.x + r.bottom.pos.x ) / 2;
 		double y = (r.top.pos.y + r.bottom.pos.y ) / 2;
 		r.center = Point2f(x, y);

 		robots_r.push_back(r);
 	}

  //std::cout << "robot right :" << robots_r.size() << std::endl;

	vector<Robot> robots;
  for(int i=0;i<robots_l.size();i++){
    for(int j=0;j<robots_r.size();j++){
      if(robots_l[i].ID == robots_r[j].ID){
        //cout << "robot: " << endl;
        //cout << "ID: " << robots_l[i].ID << "color: " << robots_l[i].top.color << " " << robots_l[i].bottom.color << endl;
        //cout << "ID: " << robots_r[j].ID << "color: " << robots_r[j].top.color << " " << robots_r[j].bottom.color << endl;
				Robot robot_temp = calculatePos(robots_l[i],robots_r[j],calib);
				robot_temp.ID = robots_l[i].ID;
				robot_temp.top.color = robots_l[i].top.color;
				robot_temp.bottom.color = robots_l[i].bottom.color;
				robots.push_back(robot_temp);
      }
    }
  }

 	return robots;
 }

/*void getColorImage(Mat &b, Mat &g, Mat &r, Mat &blue, Mat &red, Mat &yellow, Mat &green){

	blue = ((r + g + b > 75) & (b * 2 / 3.0 > r) & ((b > g) | (g - b < 10)) & (g * 2 / 3.0 > r));
	yellow = ((r > 150) & (g > 150) & (b < g - 30) & (r * 4.5 / 5.0 > b));
	red = ((r + g + b > 75) & (r * 2 / 3.0 > g) & (r * 2 / 3.0 > b));
	green = ((r + g + b > 75) & (r < g * 6 / 7.0) & (b < g * 6 / 7.0));

	/*blue = ((r + g + b > 75) & (b * 2 / 3.0 > r) & ((b > g) | (g - b < 10)) & (g * 2 / 3.0 > r));
	red = ((r + g + b > 75) & (r * 2 / 3.0 > g) & (r * 2 / 3.0 > b));
	green = ((r + g + b > 75) & (r < g * 4 / 7.0) & (b < g * 4 / 7.0));
	yellow = ((r > 150) & (g > 150) & (b < g - 100) & (r * 4 / 5.0 > b));

	yellow = (r > 176)&(r < 216)&(g>194)&(g < 220)&(b>72)&(b < 143);*/
//}




int main(int argc,char** argv){

    ros::init(argc,argv,"color_id_object");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

		ros::Publisher robotsPublisher = n.advertise<ISLH_msgs::robotPositions>("robot_list",1);


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

    //images from files
    //frame_left = imread("/home/berkay/udemy_ws/src/camera2ros/src/calib/images/left01.jpg");
    //frame_right = imread("/home/berkay/udemy_ws/src/camera2ros/src/calib/images/right01.jpg");

    //calib->runStereoCalibrationAndSave();


    cap_left >> frame_left;
    calib->loadStereoCalibrationParams(frame_left.size());
    //imshow("init_left",frame_left);
    //imshow("init_right",frame_right);
    int number_objects;
    //HSV RANGE Control
    vector<vector<int> > threshold_settings;


    while(ros::ok()){
      ros::Time begin = ros::Time::now();
      //capture images
      cap_left >> frame_left;
      cap_right >> frame_right;
      //cout << "elapsed capture : " << ros::Time::now() - begin << endl;

      //calibration
      calib->applyStereoCalibration(frame_left, frame_right, rgb_left, rgb_right);
      //imshow("init_left",frame_left);
      //imshow("init_right",frame_right);
      //imshow("undist_left",rgb_left);
      //imshow("undist_right",rgb_right);
      //cout << "elapsed calib : " << ros::Time::now() - begin << endl;

      //rgb to hsv
      cvtColor(rgb_right, hsv_right, COLOR_BGR2HSV);
      cvtColor(rgb_left, hsv_left, COLOR_BGR2HSV);
      //cout << "elapsed hsv : " << ros::Time::now() - begin << endl;

      //HSV IMAGES AND PROCESS
      Mat blue_l,red_l,green_l, blue_r,red_r, green_r;
      getColorImage(hsv_right, red_r, green_r, blue_r);
      getColorImage(hsv_left, red_l, green_l, blue_l);
			//cout << "color image hsv : " << ros::Time::now() - begin << endl;
      /*Mat bgr_r[3],bgr_l[3];
      split(rgb_left,bgr_l);
      split(rgb_right,bgr_r);


      getColorImage(bgr_r[0], bgr_r[1], bgr_r[2], blue_r, red_r, yellow_r, green_r);
      getColorImage(bgr_l[0], bgr_l[1], bgr_l[2], blue_l, red_l, yellow_l, green_l);*/
      /*imshow("1.channel left", bgr_l[0]);
      imshow("2.channel left", bgr_l[1]);
      imshow("3.channel left", bgr_l[2]);
      imshow("1.channel right", bgr_r[0]);
      imshow("2.channel right", bgr_r[1]);
      imshow("3.channel right", bgr_r[2]);*/




      //OBJECT DETECTION
      vector<vector<Point2f> > mcs_l;
      mcs_l = vector<vector<Point2f> >(3);

  		mcs_l[0] = getMC(&red_l);
  		mcs_l[1] = getMC(&green_l);
      mcs_l[2] = getMC(&blue_l);

      vector<vector<Point2f> > mcs_r;
      mcs_r = vector<vector<Point2f> >(3);

  		mcs_r[0] = getMC(&red_r);
  		mcs_r[1] = getMC(&green_r);
      mcs_r[2] = getMC(&blue_r);


      for (unsigned i = 0; i < mcs_l[0].size(); i++)
			if (mcs_l[0][i].x == mcs_l[0][i].x && mcs_l[0][i].y == mcs_l[0][i].y)
				colorCircle(red_l, (int)mcs_l[0][i].x, (int)mcs_l[0][i].y, 10, Scalar(55));

      for (unsigned i = 0; i < mcs_l[1].size(); i++)
			if (mcs_l[1][i].x == mcs_l[1][i].x && mcs_l[1][i].y == mcs_l[1][i].y)
				colorCircle(green_l, (int)mcs_l[1][i].x, (int)mcs_l[1][i].y, 10, Scalar(55));

      for (unsigned i = 0; i < mcs_l[2].size(); i++)
			if (mcs_l[2][i].x == mcs_l[2][i].x && mcs_l[2][i].y == mcs_l[2][i].y)
				colorCircle(blue_l, (int)mcs_l[2][i].x, (int)mcs_l[2][i].y, 10, Scalar(55));

        for (unsigned i = 0; i < mcs_r[0].size(); i++)
  			if (mcs_r[0][i].x == mcs_r[0][i].x && mcs_r[0][i].y == mcs_r[0][i].y)
  				colorCircle(red_r, (int)mcs_r[0][i].x, (int)mcs_r[0][i].y, 10, Scalar(55));

        for (unsigned i = 0; i < mcs_r[1].size(); i++)
  			if (mcs_r[1][i].x == mcs_r[1][i].x && mcs_r[1][i].y == mcs_r[1][i].y)
  				colorCircle(green_r, (int)mcs_r[1][i].x, (int)mcs_r[1][i].y, 10, Scalar(55));

        for (unsigned i = 0; i < mcs_r[2].size(); i++)
  			if (mcs_r[2][i].x == mcs_r[2][i].x && mcs_r[2][i].y == mcs_r[2][i].y)
  				colorCircle(blue_r, (int)mcs_r[2][i].x, (int)mcs_r[2][i].y, 10, Scalar(55));

        imshow("blue left", blue_l);
        imshow("red left", red_l);
        //imshow("yellow left", yellow_l);
        imshow("green left", green_l);
        imshow("blue right", blue_r);
        imshow("red right", red_r);
        //imshow("yellow right", yellow_r);
        imshow("green right", green_r);

        checkConsistency(mcs_l);
        checkConsistency(mcs_r);

        vector<Robot> robots = findRobots(mcs_l, mcs_r,calib);
				//cout << "final robot size: " << robots.size() << endl;

				for(int i=0;i<robots.size();i++){
					//cout << "robot " << i << " id : " << robots[i].ID << " pos: " << robots[i].center << endl;
				}

				ISLH_msgs::robotPositions msg;
				vector<geometry_msgs::Pose2D> positions;
				for(int i=0;i<numrobots;i++){
					geometry_msgs::Pose2D temp_pos;
					temp_pos.x = -1;
					temp_pos.y = -1;
					for(int j=0;j<robots.size();j++){
						if(i+1==robots[j].ID){
							temp_pos.x = robots[j].center.x;
							temp_pos.y = robots[j].center.y;
						}
					}
					positions.push_back(temp_pos);
				}
					msg.positions = positions;
					robotsPublisher.publish(msg);

				/*for(int i=0;i<positions.size();i++){
					cout << "id: " << i+1<< "pos: " << positions[i] << endl;
				}
				for(int i=0;i<msg.positions.size();i++){
					cout << "id: " << i+1<< "pos: " << msg.positions[i] << endl;
				}*/

				//cout << "robot pos : " << ros::Time::now() - begin << endl;

      waitKey(25);
      ros::spinOnce();
      loop_rate.sleep();
    }
}
