#include <ros/ros.h>
#include <realization_complete.h>

int main(int argc,char** argv){

    ros::init(argc,argv,"realization2complete");
    int minik = 2;
    RealizationComplete* realization_complete  = new RealizationComplete(argc,argv,minik);
    realization_complete->work();

}
