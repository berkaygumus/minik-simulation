#include "realization_complete.h"

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;
using namespace cv;

#define NOISE_RATIO 0.05

RealizationComplete::RealizationComplete(int argc,char** argv,int ID){

    this->argc = argc;
    this->argv = argv;

    this->id = ID;//robot ID

    //PARAMETERS FROM YAML FILE
    //goal topology
    vector<int>  topology_vector;
    getParamHandle.getParam("/goal_topology", topology_vector);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        this->A[i][j] = topology_vector[i*N+j];
      }
    }

    //ro_ij : ro_i + ro_j
    getParamHandle.getParam("/ro_ij", this->ro_ij);

    //k
    getParamHandle.getParam("/k", this->k);

    //threshold distance
    getParamHandle.getParam("/threshold", this->threshold);

    getParamHandle.getParam("/quite_mode", this->quite_mode);

    getParamHandle.getParam("/print_fi_b_dot", this->print_fi_b_dot);

    getParamHandle.getParam("/print_distances", this->print_distances);

    getParamHandle.getParam("/print_eta", this->print_eta);

    getParamHandle.getParam("/print_fi_eta_dot", this->print_fi_eta_dot);



    //eta initialization
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
}

RealizationComplete::~RealizationComplete(){

}

double RealizationComplete::orientation2theta(double x, double y, double z, double w){
  //calculates angles using quaternion
  double siny_cosp = 2*(w*z + x*y);
  double cosy_cosp = 1 - 2*(y*y + z*z);
  double theta = atan2(siny_cosp,cosy_cosp);
  return theta;
}



//subscribers for odometry from gazebo
void RealizationComplete::gazeboOdomCallback0(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 0;
  if(temp_id == id){
    //converts quaternion to angles
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    pose_x = msg->pose.pose.position.x;
    pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));//path distance update
    }
    prev_pose_x = pose_x;//previous position
    prev_pose_y = pose_y;

  }

  /*adding noise to robot posR
    gaussian noise: gaussian distribution, mean: 0, standard deviation is NOISE_RATIO
  */

  std::normal_distribution<double> distribution(0,NOISE_RATIO);
  double gaussian_number_x = distribution(generator);
  double gaussian_number_y = distribution(generator);

  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x + gaussian_number_x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y + gaussian_number_y;

  }

  flagN[temp_id] = 1;//position data is taken
}

void RealizationComplete::gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 1;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    pose_x = msg->pose.pose.position.x;
    pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));//path distance update
    }
    prev_pose_x = pose_x;//previous position
    prev_pose_y = pose_y;
  }

  std::normal_distribution<double> distribution(0,NOISE_RATIO);
  double gaussian_number_x = distribution(generator);
  double gaussian_number_y = distribution(generator);

  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x + gaussian_number_x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y + gaussian_number_y;

  }
  flagN[temp_id] = 1;
}

void RealizationComplete::gazeboOdomCallback2(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 2;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    pose_x = msg->pose.pose.position.x;
    pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));//path distance update
    }
    prev_pose_x = pose_x;//previous position
    prev_pose_y = pose_y;
  }

  std::normal_distribution<double> distribution(0,NOISE_RATIO);
  double gaussian_number_x = distribution(generator);
  double gaussian_number_y = distribution(generator);

  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x + gaussian_number_x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y + gaussian_number_y;

  }
  flagN[temp_id] = 1;
}

void RealizationComplete::gazeboOdomCallback3(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 3;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    pose_x = msg->pose.pose.position.x;
    pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));//path distance update
    }
    prev_pose_x = pose_x;//previous position
    prev_pose_y = pose_y;
  }

  std::normal_distribution<double> distribution(0,NOISE_RATIO);
  double gaussian_number_x = distribution(generator);
  double gaussian_number_y = distribution(generator);

  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x + gaussian_number_x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y + gaussian_number_y;

  }
  flagN[temp_id] = 1;
}

void RealizationComplete::gazeboOdomCallback4(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 4;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    pose_x = msg->pose.pose.position.x;
    pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));//path distance update
    }
    prev_pose_x = pose_x;//previous position
    prev_pose_y = pose_y;
  }

  std::normal_distribution<double> distribution(0,NOISE_RATIO);
  double gaussian_number_x = distribution(generator);
  double gaussian_number_y = distribution(generator);

  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x + gaussian_number_x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y + gaussian_number_y;

  }
  flagN[temp_id] = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RealizationComplete::distanceCalculator(){
  //calculates distances among robots
  for(int i=0;i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        distance[i][j]=sqrt(pow(calcPos[i][i][0]-calcPos[i][j][0],2)+pow(calcPos[i][i][1]-calcPos[i][j][1],2));
        distance[j][i] = distance[i][j];
        if(print_distances){
          if(i<j){
            cout << "distance " << i << j << " " << distance[i][j] << endl;
          }
        }
      }
    }
  }
}


void RealizationComplete::gamaFinder(){
  //calculates gamma values
  gama_sum = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i<j){
        gama_sum = gama_sum + A[i][j]*pow( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ,2) + (1-A[i][j])*pow( pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2) ,2);

      }
    }
  }
  if(!quite_mode){
    cout << "gama_sum: " << gama_sum << endl;
  }
}

void RealizationComplete::gamaBDotFinder(){
  //calculates derivative of gamma with respect to b(position) >> gama_b_dot
  for(int i=0; i<N;i++){//i >> robot id
    gama_b_dot[i][0] = 0;
    gama_b_dot[i][1] = 0;
    for(int j=0; j<N; j++){
      if(j!=i){
        gama_b_dot[i][0] = gama_b_dot[i][0] + 4*(calcPos[i][i][0]-calcPos[i][j][0])*(A[i][j]*( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ) + (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
        gama_b_dot[i][1] = gama_b_dot[i][1] + 4*(calcPos[i][i][1]-calcPos[i][j][1])*(A[i][j]*( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ) + (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
      }
    }

    if(!quite_mode){
      cout << "gama_b_dot " << i <<  " 0: " << gama_b_dot[i][0] << endl;
      cout << "gama_b_dot " << i <<  " 1: " << gama_b_dot[i][1] << endl;
    }
  }
}

void RealizationComplete::betaFinder(){
  //calculates beta values
  beta_product = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i<j){
        beta_product = beta_product*(pow(distance[i][j],2)-pow(ro_ij,2));
      }
    }
  }
  if(!quite_mode){
    cout << "beta_product: " << beta_product << endl;
  }
}

void RealizationComplete::betaBDotFinder(){
  //calculates derivative of beta with respect to b(position) >> beta_b_dot
  for(int i = 0; i<N; i++){
    beta_b_dot[i][0] = 0;
    beta_b_dot[i][1] = 0;
    for(int j=0; j<N; j++){
      if(i!=j){
        beta_b_dot[i][0] = beta_b_dot[i][0] + 2*(calcPos[i][i][0]-calcPos[i][j][0])*beta_product/(pow(distance[i][j],2)-pow(ro_ij,2));
        beta_b_dot[i][1] = beta_b_dot[i][1] + 2*(calcPos[i][i][1]-calcPos[i][j][1])*beta_product/(pow(distance[i][j],2)-pow(ro_ij,2));
      }
    }
    if(!quite_mode){
      cout << "beta_b_dot " << i <<  " 0 " << beta_b_dot[i][0] << endl;
      cout << "beta_b_dot " << i <<  " 1 " << beta_b_dot[i][1] << endl;
    }
  }
}

void RealizationComplete::gamaEtaDotFinder(){
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

void RealizationComplete::fiBDotFinder(){
  //calculates derivative of fi with respect to b(position) >> fi_b_dot
  for(int i=0; i<N; i++){
    for(int j=0; j<2;j++){
      fi_b_dot[i][j] = -(1/k)*pow(pow(gama_sum,k)/(beta_product+pow(gama_sum,k)),((1/k)-1))*(k*pow(gama_sum,k-1)*gama_b_dot[i][j]*(beta_product+pow(gama_sum,k))-pow(gama_sum,k)*(beta_b_dot[i][j]+k*pow(gama_sum,k-1)*gama_b_dot[i][j]))/pow((beta_product+pow(gama_sum,k)),2);
      if(print_fi_b_dot){
        cout << "fi_b_dot " << i << " " << j << " " << fi_b_dot[i][j] << endl;
      }
    }
  }
}

void RealizationComplete::fiEtaDotFinder(){
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


void RealizationComplete::etaFinder(){
  //calculates eta values using runge kutta

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

  RealizationComplete::fiEtaDotFinder();//eta0

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot0 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k1[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k1  " << i << j << " " << k1[i][j] << endl;
      eta[i][j] = eta[i][j] + k1[i][j] /2;


    }
  }

  RealizationComplete::fiEtaDotFinder();//eta0 + k1/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot1 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k2[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k2  " << i << j << " " << k2[i][j] << endl;
      eta[i][j] = eta[i][j] + k2[i][j] /2 - k1[i][j] /2;


    }
  }

  RealizationComplete::fiEtaDotFinder();//eta0 + k2/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot2 " << i << j << " " << fi_eta_dot[i][j] << " step size " << step_size << endl;
      k3[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k3  " << i << j << " " << k3[i][j] << endl;
      eta[i][j] = eta[i][j] + k3[i][j] - k2[i][j] /2;;

    }
  }

  RealizationComplete::fiEtaDotFinder();//eta0 + k3

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
          if(print_fi_eta_dot){
            cout << "fi eta dot " << i << j << " " << fi_eta_dot[i][j] <<endl;
          }
          if(print_eta){
            cout << "eta " << i << j << " " << eta[i][j] <<endl;
          }

        }

    }
  }
}

void RealizationComplete::Comparator(){
  //checks goal topology is realized
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
}

void RealizationComplete::finalRealization(){
  //calculates velocities and eta values
  RealizationComplete::gamaFinder(); //calculates gamma
  RealizationComplete::gamaBDotFinder(); //calculates derivative of gamma with respect to b(position)
  RealizationComplete::betaFinder(); //calculates beta
  RealizationComplete::betaBDotFinder(); //calculates derivative of beta with respect to b(position)
  RealizationComplete::gamaEtaDotFinder(); //calculates derivative of gamma with respect to eta
  RealizationComplete::fiBDotFinder(); //calculates derivative of fi with respect to b(position)
  RealizationComplete::etaFinder(); //calculates new eta values using runge kutta
  RealizationComplete::setVelocity();//calculates linear and angular velocities
  RealizationComplete::Comparator(); //checks goal topology is realized

}

void RealizationComplete::setVelocity(){
  double vx, vy;
  cout << "completed: " << completed << endl;
  if(completed == 1){//if goal topology is realized
    time_counter ++;
    if(time_counter>100){ //if it lasts 10 seconds
      vx = 0;
      vy = 0;
      cout <<"set velocity zero" << endl;
      completed_stop = 1;
    }
    else{//waits 10 seconds to stop
      cout << "completed but continue" << endl;
      vx = fi_b_dot[id][0];
      vy = fi_b_dot[id][1];
      completed_stop = 0;
    }

  }
  else{//if goal topology is not realized
    time_counter = 0;
    vx = fi_b_dot[id][0];
    vy = fi_b_dot[id][1];
    completed_stop = 0;
  }

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
    velocity_angle = atan(vy/vx);//velocity angle
    if(vx<0){
      velocity_angle = velocity_angle + PI;
    }
  }

  if(velZero==false){
    double delta_angle = velocity_angle-pose_theta;//angle between heading and velocity calculated by realization
    linear_vel = cos(delta_angle)*0.2; //linear velocity; max linear velocity is 0.2
    angular_vel = sin(delta_angle)*PI/3; //angular velocity; max angular velocity is PI/3
  }
}


void RealizationComplete::work(){

  ostringstream ss;
  ss << id + 1;
  string name =  "robot" + ss.str(); //message name for velocity at gazebo

  vel_pub = velPub.advertise<geometry_msgs::Twist>(name+"/cmd_vel", 100);//publisher for velocity at gazebo

  ros::Subscriber calc_sub11 = poseSub.subscribe("/robot1/odom",1000,&RealizationComplete::gazeboOdomCallback0,this);
  ros::Subscriber calc_sub21 = poseSub.subscribe("/robot2/odom",1000,&RealizationComplete::gazeboOdomCallback1,this);
  ros::Subscriber calc_sub31 = poseSub.subscribe("/robot3/odom",1000,&RealizationComplete::gazeboOdomCallback2,this);
  ros::Subscriber calc_sub41 = poseSub.subscribe("/robot4/odom",1000,&RealizationComplete::gazeboOdomCallback3,this);
  ros::Subscriber calc_sub51 = poseSub.subscribe("/robot5/odom",1000,&RealizationComplete::gazeboOdomCallback4,this);

  ros::Rate loop_rate(f);

  while (ros::ok() && !completed_stop){

    flag = 1;
    for(int i=0;i<N;i++){
      flag = flag * flagN[i];
    }

    RealizationComplete::distanceCalculator();//calculates distances among robots
    RealizationComplete::finalRealization(); //realization algortihm

    geometry_msgs::Twist msg;//velocity message

    if(flag){//realization starts
      msg.linear.x = this->linear_vel;
      msg.angular.z = this->angular_vel;
    }
    else{//waits until all position data is taken
      msg.linear.x = 0;
      msg.angular.z = 0;
    }


    vel_pub.publish(msg); //publishes velocity message

    ros::spinOnce();
    loop_rate.sleep();
  }

  ostringstream ss2;
  ss2 << id + 1;
  string path_distance_param_name =  "robot" + ss2.str();//param name related to path distance
  cout << path_distance_param_name << ": " << this->path_distance;
  string ok = "ok";
  string fail = "fail";

  getParamHandle.setParam(path_distance_param_name, this->path_distance);

  string path_file; //path file name to save
  getParamHandle.getParam("/yaml_file_name", path_file);
  cout << "param name " << path_distance_param_name << endl;

  FileStorage fs(path_file, FileStorage::APPEND);
  if( fs.isOpened() ){
    cout << "opened" <<endl;
    fs.write(path_distance_param_name,this->path_distance);//this->path_distance;
    //fs.release();
    cout << "path distance " << id+1 <<" saved to " << path_file  << endl;
    if(completed == 1){
      fs.write(ok,1);
    }
    else{
      fs.write(fail,0);
    }

  }
  else{
    cout << "yaml file is not opened" << endl;
  }
}
