#include <ros/ros.h>
#include "realization_partial.h"

int main(int argc,char** argv){

    ros::init(argc,argv,"realization0partial");
    int minik = 0;
    RealizationPartial* realization_partial  = new RealizationPartial(argc,argv,minik);
    realization_partial->work();

}
