#include <ros/ros.h>
#include <RosThread.h>
//#define N 4

int main(int argc,char** argv){

    ros::init(argc,argv,"realization3");
    int minik = 3;
    RosThread* rosthread  = new RosThread(argc,argv,minik);
    rosthread->work();


}
