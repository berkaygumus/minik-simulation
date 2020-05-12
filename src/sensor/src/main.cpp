#include <ros/ros.h>
#include <rosThread.h>


int main(int argc,char** argv){

    ros::init(argc,argv,"sensor");
    int minik = 0;
    RosThread* rosthread  = new RosThread(minik);
    rosthread->work();




}
