#include <ros/ros.h>
#include <detect_aruco_object/detectArucoObject.h>

using namespace std;

int main(int argc,char** argv){

    ros::init(argc,argv,"detect_aruco_object");
    cout << "detect_aruco_object_node" << endl;
    DetectArucoObject* detect_aruco_object  = new DetectArucoObject();
    detect_aruco_object->work();


}
