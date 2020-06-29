#include <ros/ros.h>
#include <odom_publisher.h>

using namespace std;

int main(int argc,char** argv){

    ros::init(argc,argv,"odom_publisher_node");
    cout << "odom_publisher_node" << endl;
    OdomPublisher* odom_publisher = new OdomPublisher();
    odom_publisher->work();

}
