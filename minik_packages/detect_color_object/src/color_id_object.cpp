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

		//sets hsv ranges, defined at detect_color_object/hsv_range.h
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
 	}
 	///  Get the mass centers:
 	vector<Point2f> mc;
 	for (unsigned i = 0; i < mu.size(); i++)
 		mc.push_back(Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00));

 	return mc;
 }

 void checkC(vector<Point2f> &v1, vector<Point2f> &v2, vector<Point2f> &v3){
	 //calculates how many neighbor it has (it must be 1)
	 //the color id shape is top-bottom: If it has neighbour, it must be at top or bottom.
   int max_dist_x = 20;//prevents creating neighborhood with side color, if it is far at x axis(horizontal), it can not be neighbor
   int min_dist_y = 2;
	 //all possible combinations are checked and calculates the number of neighbor for each center
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
			//if it doesn't have only 1 neighbor, it is not a necessary center.
 			v1.erase(v1.begin() + i);
 			i--;
 		}
 	}
 }

 void checkConsistency(vector<vector<Point2f> > &mcs){
 	checkC(mcs[0], mcs[1], mcs[2]);//centers at red images are checked
 	checkC(mcs[1], mcs[0], mcs[2]);//centers at green images are checked
 	checkC(mcs[2], mcs[1], mcs[0]);//centers at blue images are checked
 }

 Robot calculatePos(Robot r_l, Robot r_r, Camera_Calibration* calib){

	float himsizex = WEBCAM_FOV_WIDTH_PIXELS*SAMPLING_FACTOR; //width in terms of pixel
	float himsizey = WEBCAM_FOV_HEIGHT_PIXELS*SAMPLING_FACTOR; //height in terms of pixel


	float d_obs;
	double distance_x_obs;
	double distance_y_obs;

 //it can be calculated from camera matrix, however there is a problem at get functions FIX IT!!!!
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


 vector<Robot> findRobots(vector<vector<Point2f> > mcs_l, vector<vector<Point2f> > mcs_r,Camera_Calibration* calib, Mat rgb_left, Mat rgb_right){
 	/// Find Groups of 3 Markers
  int max_dist_x = 20;
  int min_dist_y = 2;
 	vector<Group> groups_l;//creates color groups for color id
 	for (unsigned coli = 0; coli < 3; coli++){//for each color
 		for (unsigned mari = 0; mari < mcs_l[coli].size(); mari++){//each center at the center vector
 			Marker marker; //creates marker containing color and pos
 			marker.color = coli; //color
 			marker.pos = mcs_l[coli][mari]; //pos
 			if (isInGroups(&groups_l, marker)) continue; //if it exists, it is not necessary to create again
 			Group g;//containing two markers(2 colors and 2 centers)
 			g.markers.push_back(marker);
 			for (unsigned colj = 0; colj < 3; colj++){//searches another(neighbor) marker
 				for (unsigned marj = 0; marj < mcs_l[colj].size(); marj++){
 					if (coli == colj && mari == marj) continue; //if it is itself

 					//double dist = getDist(mcs_l[coli][mari], mcs_l[colj][marj]);
          double dst_x = abs(mcs_l[coli][mari].x- mcs_l[colj][marj].x);//difference at horizontal
          double dst_y = abs(mcs_l[coli][mari].y- mcs_l[colj][marj].y);//difference at verticel
 					if (dst_x < max_dist_x && dst_y > min_dist_y){//if it is not far at the horizontal
 						Marker m;
 						m.color = colj;
 						m.pos = mcs_l[colj][marj];
 						g.markers.push_back(m);//another marker
 					}
 				}
 			}
 			groups_l.push_back(g);//all groups are added to group vector
 		}
 	}


 	//std::cout << "Group left size: " << groups_l.size() << endl;

  /*for(int i=0;i<groups_l.size();i++){
    cout << "left colors: " << groups_l[i].markers[0].color << groups_l[i].markers[1].color << endl;
  }*/

//same things for right image
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

 		/// If group doesn't have 2 markers then it is not correct
 		if (g.markers.size() != 2 )
 			continue;

    double y0 = g.markers[0].pos.y;
    double y1 = g.markers[1].pos.y;
		//determines top color bottom color
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
 		for (int i = 0; i < numrobots; i++){//searches robot id list defined at detect_color_object/robot_IDs.h to determine robot id
 			if (r.top.color == robIDList[i][0] && r.bottom.color == robIDList[i][1]){
 				r.ID = i + 1; //IDs start from 1, not 0
        ///cout << "robot left is found and id: " << 	r.ID << endl;
 				break;
 			}
 		}
 		if (r.ID == -1)
 			continue;

 		/// Find average center position at the image
 		double x = (r.top.pos.x + r.bottom.pos.x ) / 2;
 		double y = (r.top.pos.y + r.bottom.pos.y ) / 2;
 		r.center = Point2f(x, y);

 		robots_l.push_back(r);
		colorCircle(rgb_left, (int)x, (int)y, 10, Scalar(55));
 	}

	imshow("undist_left",rgb_left);


  //std::cout << "robot left :" << robots_l.size() << std::endl;

  //same things for right image
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
        ///cout << "robot right is found and id: " << 	r.ID << endl;
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
		colorCircle(rgb_right, (int)x, (int)y, 10, Scalar(55));
 	}
imshow("undist_right",rgb_right);
  //std::cout << "robot right :" << robots_r.size() << std::endl;

	vector<Robot> robots; // robot vector
  for(int i=0;i<robots_l.size();i++){
    for(int j=0;j<robots_r.size();j++){
      if(robots_l[i].ID == robots_r[j].ID){//same robot IDs for right and left
        //cout << "robot: " << endl;
        //cout << "ID: " << robots_l[i].ID << "color: " << robots_l[i].top.color << " " << robots_l[i].bottom.color << endl;
        //cout << "ID: " << robots_r[j].ID << "color: " << robots_r[j].top.color << " " << robots_r[j].bottom.color << endl;
				Robot robot_temp = calculatePos(robots_l[i],robots_r[j],calib);//calculates robot position
				robot_temp.ID = robots_l[i].ID;
				robot_temp.top.color = robots_l[i].top.color;
				robot_temp.bottom.color = robots_l[i].bottom.color;
				robots.push_back(robot_temp);
      }
    }
  }

 	return robots;
 }


int main(int argc,char** argv){

    ros::init(argc,argv,"color_id_object");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

		//publisher for the robot pos list
		ros::Publisher robotsPublisher = n.advertise<ISLH_msgs::robotPositions>("robot_list",1);

		//calibration object
    Camera_Calibration* calib  = new Camera_Calibration();

		bool isCamera = 1;
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

    calib->loadStereoCalibrationParams(frame_left.size());//loads calibration parameters from the file.


    while(ros::ok()){
      ros::Time begin = ros::Time::now();
      //capture images
			if(isCamera){
        cap_left >> frame_left;
        cap_right >> frame_right;
      }
      else{
        frame_left = imread(left_img_name);//left image
        frame_right = imread(right_img_name);//right image
      }
      //cout << "elapsed capture : " << ros::Time::now() - begin << endl;

      //calibration
      calib->applyStereoCalibration(frame_left, frame_right, rgb_left, rgb_right);
      imshow("init_left",frame_left);
      imshow("init_right",frame_right);
      //imshow("undist_left",rgb_left);
      //imshow("undist_right",rgb_right);
      //cout << "elapsed calib : " << ros::Time::now() - begin << endl;

      //rgb to hsv
      cvtColor(rgb_right, hsv_right, COLOR_BGR2HSV);
      cvtColor(rgb_left, hsv_left, COLOR_BGR2HSV);
      //cout << "elapsed hsv : " << ros::Time::now() - begin << endl;

      //HSV IMAGES AND PROCESS
      Mat blue_l,red_l,green_l, blue_r,red_r, green_r; //binary red, green, blue images
      getColorImage(hsv_right, red_r, green_r, blue_r); //converts HSV image to binary images
      getColorImage(hsv_left, red_l, green_l, blue_l);
			//cout << "color image hsv : " << ros::Time::now() - begin << endl;

      //OBJECT DETECTION
			//left
      vector<vector<Point2f> > mcs_l; //centers(x,y) of thresholded parts at three images(red, green, blue)
      mcs_l = vector<vector<Point2f> >(3);

  		mcs_l[0] = getMC(&red_l);//centers of parts at red image
  		mcs_l[1] = getMC(&green_l);//centers of parts at green_l image
      mcs_l[2] = getMC(&blue_l);//centers of parts at blue image

			//same things for right
      vector<vector<Point2f> > mcs_r;
      mcs_r = vector<vector<Point2f> >(3);

  		mcs_r[0] = getMC(&red_r);
  		mcs_r[1] = getMC(&green_r);
      mcs_r[2] = getMC(&blue_r);

			//circles are added at the centers
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

        checkConsistency(mcs_l);//checks neighborhood among the centers, if it doesn't have only one neighbor, it is removed from the vector
        checkConsistency(mcs_r);

				//calculates robot posiitons and creates robot vector
        vector<Robot> robots = findRobots(mcs_l, mcs_r,calib,rgb_left,rgb_right);
				//cout << "final robot size: " << robots.size() << endl;

				for(int i=0;i<robots.size();i++){
					//cout << "robot " << i << " id : " << robots[i].ID << " pos: " << robots[i].center << endl;
				}

				ISLH_msgs::robotPositions msg;//message to publish
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
					cout << endl << "detected objects:" << endl;
				for(int i=0;i<positions.size()-1;i++){
					cout << "id: " << i+1<< "pos(cm) x: " << positions[i].x << " y: " <<  positions[i].y<< endl;
				}
				for(int i=0;i<msg.positions.size();i++){
					//cout << "id: " << i+1<< "pos: " << msg.positions[i] << endl;
				}

				//cout << "robot pos : " << ros::Time::now() - begin << endl;

      waitKey(25);
      ros::spinOnce();
      loop_rate.sleep();
    }
}
