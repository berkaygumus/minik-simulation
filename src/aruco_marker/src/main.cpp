#include <ros/ros.h>
#include <arucoMarker.h>

using namespace std;

int main(int argc,char** argv){

    ros::init(argc,argv,"aruco_marker");
    cout << "aruco_marker_node" << endl;
    ArucoMarker* aruco_marker  = new ArucoMarker();


    //generates 4 markers for one robot
    //takes robotIDs vector as input
    /*
    vector<int> robotIDs;
    robotIDs.push_back(1);
    robotIDs.push_back(2);
    aruco_marker->markerGenerater(robotIDs);*/

    //takes image from the camera, detects aruco markers of the robot at the field of view and publishes robot positions and headings
    aruco_marker->calculateRobotPos();

}
