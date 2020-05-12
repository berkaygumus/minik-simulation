#include <ros/ros.h>
#include <rosThread.h>


int main(int argc,char** argv){

    ros::init(argc,argv,"errorComp");
    RosThread* rosthread  = new RosThread();
    rosthread->work();




}
