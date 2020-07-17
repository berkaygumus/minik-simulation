#include "RosThread.h"

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
//#define ID 0

using namespace std;


RosThread::RosThread(int argc,char** argv,int ID){

    this->argc = argc;
    this->argv = argv;

    this->id = ID;

    //other robots
    //scenario 1.1:
    /*
    b[1][0] = 1.0;
    b[1][1] = 3.5;
    b[2][0] = 1.0;
    b[2][1] = 1.0;
    b[3][0] = 3.5;
    b[3][1] = 1.0;
    */
    //scenario 1.2:
    /*
    b[1][0] = 4.0;
    b[1][1] = 6.5;
    b[2][0] = 4.0;
    b[2][1] = 4.0;
    b[3][0] = 6.5;
    b[3][1] = 4.0;
    */


    //scenario 2:
    /*
    b[1][0] = 1.0;
    b[1][1] = 1.0;
    b[2][0] = 4.0;
    b[2][1] = 4.0;
    b[3][0] = 6.5;
    b[3][1] = 4.0;
    */
    //scenario 3:
    /*
    b[1][0] = 7.0;
    b[1][1] = 7.5;
    b[2][0] = 7.0;
    b[2][1] = 5.0;
    b[3][0] = 9.5;
    b[3][1] = 5.0;
    */
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(A[i][j]==1){
          eta[i][j] = threshold - ro_ij;
        }
        else if(A[i][j]==0){
          eta[i][j] = threshold + ro_ij;
        }
      }
    }

    //ros::ServiceClient turtles = ser.ServiceClient<turtlesim::Spawn>()

    //A[][] = {{0,1},{1,0}};

}

RosThread::~RosThread(){

}



void RosThread::poseOdomCallback0(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[0][0] = msg->x;
  b[0][1] = msg->y;
  if(id==0){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[0]=1;
}

void RosThread::poseOdomCallback1(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[1][0] = msg->x;
  b[1][1] = msg->y;
  if(id==1){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[1]=1;
}

void RosThread::poseOdomCallback2(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[2][0] = msg->x;
  b[2][1] = msg->y;
  if(id==2){
    //ROS_INFO("id 2");
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[2]=1;
}

void RosThread::poseOdomCallback3(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[3][0] = msg->x;
  b[3][1] = msg->y;
  if(id==3){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[3]=1;
}

void RosThread::poseOdomCallback4(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[4][0] = msg->x;
  b[4][1] = msg->y;
  if(id==4){
    //ROS_INFO("id 2");
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[4]=1;
}

void RosThread::poseOdomCallback5(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[5][0] = msg->x;
  b[5][1] = msg->y;
  if(id==5){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[5]=1;
}

void RosThread::poseOdomCallback6(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  b[6][0] = msg->x;
  b[6][1] = msg->y;
  if(id==6){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }
  flagN[6]=1;
}

void RosThread::distanceCalculator(){
  for(int i=0;i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        distance[i][j]=sqrt(pow(b[i][0]-b[j][0],2)+pow(b[i][1]-b[j][1],2));
        distance[j][i] = distance[i][j];
        if(i<j){
          cout << "distance " << i << j << " " << distance[i][j] << endl;
        }
      }
    }
    //cout << "bbb " << i << "x: " << " " << b[i][0] <<  endl;
    //cout << "bbb " << i << "y: " << " " << b[i][1] << endl;
    //ROS_INFO("b %d: %f , %f",i,b[i][0],b[i][1]);
  }

    //cout << "bbb " << i << "x: " << " " << b[i][0] <<  endl;
    //cout << "bbb " << i << "y: " << " " << b[i][1] << endl;
    //ROS_INFO("b %d: %f , %f",i,b[i][0],b[i][1]);


}

/*void turtleService(const turtlesim::Spawn::ConstPtr& ser){


}*/

/*void RosThread::poseOverCallback(const ISLH_msgs::robotPositions::ConstPtr& msg){
  for(int i =0;i<N ; i++){
		b[i][0] = msg->positions[i].x;
		b[i][1] = msg->positions[i].y;
		//b[i][2] = msg->directions[i];
	}

}*/

void RosThread::gamaFinder(){
  //ROS_INFO("gama finder b0: %f %f ",b[0][0],b[0][1]);
  gama_sum = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i<j){
        gama_sum = gama_sum + A[i][j]*pow( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ,2) + (1-A[i][j])*pow( pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2) ,2);

      }
    }
  }

  //cout << "gama_sum: " << gama_sum << endl;
}

void RosThread::gamaBDotFinder(){
  for(int i=0; i<N;i++){//i >> robot id
    gama_b_dot[i][0] = 0;
    gama_b_dot[i][1] = 0;
    for(int j=0; j<N; j++){
      if(j!=i){
        gama_b_dot[i][0] = gama_b_dot[i][0] + 4*(b[i][0]-b[j][0])*(A[i][j]*( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ) + (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
        gama_b_dot[i][1] = gama_b_dot[i][1] + 4*(b[i][1]-b[j][1])*(A[i][j]*( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ) + (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
      }
    }

    //cout << "gama_b_dot " << i <<  " 0 " << gama_b_dot[i][0] << endl;
    //cout << "gama_b_dot " << i <<  " 1 " << gama_b_dot[i][1] << endl;
  }




}

void RosThread::betaFinder(){
  beta_product = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i<j){
        beta_product = beta_product*(pow(distance[i][j],2)-pow(ro_ij,2));
      }
    }

  }
  //cout << "beta_product: " << beta_product << endl;
}

void RosThread::betaBDotFinder(){
  for(int i = 0; i<N; i++){
    beta_b_dot[i][0] = 0;
    beta_b_dot[i][1] = 0;
    for(int j=0; j<N; j++){
      if(i!=j){
        beta_b_dot[i][0] = beta_b_dot[i][0] + 2*(b[i][0]-b[j][0])*beta_product/(pow(distance[i][j],2)-pow(ro_ij,2));
        beta_b_dot[i][1] = beta_b_dot[i][1] + 2*(b[i][1]-b[j][1])*beta_product/(pow(distance[i][j],2)-pow(ro_ij,2));
      }
    }
    //cout << "beta_b_dot " << i <<  " 0 " << beta_b_dot[i][0] << endl;
    //cout << "beta_b_dot " << i <<  " 1 " << beta_b_dot[i][1] << endl;
  }
}

void RosThread::gamaEtaDotFinder(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      gama_eta_dot[i][j] = 0;
      if(i!=j){
        gama_eta_dot[i][j] = 4*eta[i][j]*( A[i][j]*(pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2)) - (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
        //cout << "gama_eta_dot " << i << j << " " << gama_eta_dot[i][j] << endl;
      }
    }
  }
}

void RosThread::fiBDotFinder(){
  for(int i=0; i<N; i++){
    for(int j=0; j<2;j++){
      fi_b_dot[i][j] = -(1/k)*pow(pow(gama_sum,k)/(beta_product+pow(gama_sum,k)),((1/k)-1))*(k*pow(gama_sum,k-1)*gama_b_dot[i][j]*(beta_product+pow(gama_sum,k))-pow(gama_sum,k)*(beta_b_dot[i][j]+k*pow(gama_sum,k-1)*gama_b_dot[i][j]))/pow((beta_product+pow(gama_sum,k)),2);
      cout << "fi_b_dot " << i << " " << j << " " << fi_b_dot[i][j] << endl;
    }
  }
}

void RosThread::fiEtaDotFinder(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        fi_eta_dot[i][j] = -pow((pow(gama_sum,k)/(beta_product+pow(gama_sum,k))),(1/k)-1)*beta_product*pow(gama_sum,(k-1))*gama_eta_dot[i][j]/pow((beta_product+pow(gama_sum,k)),2);

        if(fi_eta_dot[i][j]>-999999999){
            //cout << "fi_eta_dot " << i << j << " "<< fi_eta_dot[i][j] << endl;
        }
      }
    }
  }
}


void RosThread::etaFinder(){


  //cout << "differential: " << endl;


  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i!=j){
        fi_eta_dot2[i][j] = -pow((pow(gama_sum,k)/(beta_product+pow(gama_sum,k))),(1/k)-1)*beta_product*pow(gama_sum,(k-1))*gama_eta_dot[i][j]/pow((beta_product+pow(gama_sum,k)),2);
        //cout << "diff fi_eta_dot " << i << j << " " << step_size * fi_eta_dot2[i][j] << endl;
        //cout << "diff eta_dot " << i << j << " " << eta[i][j] + step_size * fi_eta_dot2[i][j] << endl;
      }
    }
  }


  //cout << "runge kutta " << endl;
  double temp_eta[N][N];
  double k1[N][N],k2[N][N],k3[N][N],k4[N][N];

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      temp_eta[i][j] = eta[i][j];

    }
  }

  RosThread::fiEtaDotFinder();//eta0

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot0 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k1[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k1  " << i << j << " " << k1[i][j] << endl;
      eta[i][j] = eta[i][j] + k1[i][j] /2;


    }
  }

  RosThread::fiEtaDotFinder();//eta0 + k1/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot1 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k2[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k2  " << i << j << " " << k2[i][j] << endl;
      eta[i][j] = eta[i][j] + k2[i][j] /2 - k1[i][j] /2;


    }
  }

  RosThread::fiEtaDotFinder();//eta0 + k2/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot2 " << i << j << " " << fi_eta_dot[i][j] << " step size " << step_size << endl;
      k3[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k3  " << i << j << " " << k3[i][j] << endl;
      eta[i][j] = eta[i][j] + k3[i][j] - k2[i][j] /2;;

    }
  }

  RosThread::fiEtaDotFinder();//eta0 + k3

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot3 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k4[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k4  " << i << j << " " << k4[i][j] << endl;

    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        eta[i][j] = temp_eta[i][j] + k1[i][j]/6 + k2[i][j]/3 + k3[i][j]/3 + k4[i][j]/6;
        if(i!=j){
          /*cout << "runge delta eta :" << i << j << " " << k1[i][j]/6 + k2[i][j]/3 + k3[i][j]/3 + k4[i][j]/6 <<endl;
          cout << "differential eta: " << fi_eta_dot2[i][j]*step_size << endl;
          cout << "runga eta " << i << j << " " << eta[i][j] <<endl;
          cout << "diff runge and diff " <<  step_size * fi_eta_dot2[i][j] - (  k1[i][j]/6 + k2[i][j]/3 + k3[i][j]/3 + k4[i][j]/6  ) << endl;*/
          cout << "eta " << i << j << " " << eta[i][j] <<endl;
        }

    }
  }



  /*for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        if(fi_eta_dot[i][j]>-999999999){
            eta[i][j] = eta[i][j] + fi_eta_dot[i][j]/f ;////derivative
            cout << "eta " << i << j << " " << eta[i][j] <<endl;
        }
      }

    }
  }*/
}

void RosThread::Comparator(){
  completed = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i<j){
          if(distance[i][j] < threshold){
            completed = completed * A[i][j];
          }
          else{
            completed = completed * (1-A[i][j]);
          }
      }
    }
  }
  if(completed == 1){
    cout << "MISSION COMPLETED !!! " << endl;
  }
  else{
    cout << "next time :(" << endl;
  }
  completed = 0;
}

void RosThread::finalRealization(){
  RosThread::gamaFinder();
  RosThread::gamaBDotFinder();
  RosThread::betaFinder();
  RosThread::betaBDotFinder();
  RosThread::gamaEtaDotFinder();
  RosThread::fiBDotFinder();
  //RosThread::fiEtaDotFinder();
  RosThread::etaFinder();
  RosThread::setVelocity();
  RosThread::Comparator();

}

void RosThread::setVelocity(){
  double vx = fi_b_dot[id][0];
  double vy = fi_b_dot[id][1];
  double v = sqrt(pow(vx,2)+pow(vy,2));


  double velocity_angle;
  bool velZero = false;
  if(vx==0){
    if(vy==0){
      velZero = true;
      linear_vel = 0;
      angular_vel = 0;
    }
    else if(vy>0){
      velocity_angle = PI/2;
    }
    else if(vy<0){
      velocity_angle = -PI/2;
    }

  }
  else{
    velocity_angle = atan(vy/vx);
    if(vx<0){
      velocity_angle = velocity_angle + PI;
    }
  }

  if(velZero==false){
    double delta_angle = velocity_angle-pose_theta;
    linear_vel = cos(delta_angle)*0.2;
    angular_vel = sin(delta_angle)*PI/3;
  }



}


void RosThread::work(){




  ostringstream ss;
  ss << id +1;
  string name =  "turtle" + ss.str();

  ros::Publisher vel_pub = velPub.advertise<geometry_msgs::Twist>(name+"/cmd_vel", 100);
  //ros::Publisher vel_pub = velPub.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
  ros::Subscriber pose_odom_sub1 = poseOdomSub.subscribe("turtle1/pose",1000,&RosThread::poseOdomCallback0,this);
  ros::Subscriber pose_odom_sub2 = poseOdomSub.subscribe("turtle2/pose",1000,&RosThread::poseOdomCallback1,this);
  ros::Subscriber pose_odom_sub3 = poseOdomSub.subscribe("turtle3/pose",1000,&RosThread::poseOdomCallback2,this);
  ros::Subscriber pose_odom_sub4 = poseOdomSub.subscribe("turtle4/pose",1000,&RosThread::poseOdomCallback3,this);
  ros::Subscriber pose_odom_sub5 = poseOdomSub.subscribe("turtle5/pose",1000,&RosThread::poseOdomCallback4,this);
  ros::Subscriber pose_odom_sub6 = poseOdomSub.subscribe("turtle6/pose",1000,&RosThread::poseOdomCallback5,this);
  ros::Subscriber pose_odom_sub7 = poseOdomSub.subscribe("turtle7/pose",1000,&RosThread::poseOdomCallback6,this);

  //ros::Subscriber pose_over_sub=poseOverheadCamSub.subscribe<ISLH_msgs::robotPositions>("robots_final_positions",1,&RosThread::poseOverCallback,this);

  ros::Rate loop_rate(f);


  while (ros::ok()){

    flag = 1;
    for(int i=0;i<N;i++){
      flag = flag * flagN[i];
    }

    if(flag==1){
      RosThread::distanceCalculator();
      for(int i=0; i<N; i++){
        //ROS_INFO("b %d: %f , %f",i,b[i][0],b[i][1]);
        cout << "b" << i << ": " << b[i][0] << "  "<< b[i][1] << endl;
        //ROS_INFO("work ");
      }

      RosThread::finalRealization();

      geometry_msgs::Twist msg;

      msg.linear.x = this->linear_vel;
      msg.angular.z = this->angular_vel;


      vel_pub.publish(msg);
    }
    else{
      ROS_INFO("waiting...");
    }




    ros::spinOnce();

    loop_rate.sleep();

  }



}
