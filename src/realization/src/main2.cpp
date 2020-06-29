#include <ros/ros.h>
#include <RosThread.h>
//#define N 4

int main(int argc,char** argv){

    ros::init(argc,argv,"realization2");
    int minik = 2;
    RosThread* rosthread  = new RosThread(argc,argv,minik);
    rosthread->work();


}
