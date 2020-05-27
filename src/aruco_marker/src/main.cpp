#include <ros/ros.h>
#include <arucoMarker.h>


int main(int argc,char** argv){

    ros::init(argc,argv,"aruco_marker2");
    cout << "aruco_marker_node" << endl;
    ArucoMarker* aruco_marker  = new ArucoMarker();
    //aruco_marker->work();

    //generates 4 markers for one robot
    //takes robotID as input
    //aruco_marker->markerGenerater(1);

    //takes image from the camera, detects aruco markers of the robot at the field of view and publishes robot positions and headings
    aruco_marker->calculateRobotPos();

}
