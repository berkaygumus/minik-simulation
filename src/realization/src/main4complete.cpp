#include <ros/ros.h>
#include <realization_complete.h>

int main(int argc,char** argv){

    ros::init(argc,argv,"realization4complete");
    int minik = 4;
    RealizationComplete* realization_complete  = new RealizationComplete(argc,argv,minik);
    realization_complete->work();

}
