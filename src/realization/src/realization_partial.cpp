#include "realization_partial.h"

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;
using namespace cv;


RealizationPartial::RealizationPartial(int argc,char** argv,int ID){

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

RealizationPartial::~RealizationPartial(){

}

double RealizationPartial::orientation2theta(double x, double y, double z, double w){
  //calculates angles using quaternion
  double siny_cosp = 2*(w*z + x*y);
  double cosy_cosp = 1 - 2*(y*y + z*z);
  double theta = atan2(siny_cosp,cosy_cosp);
  return theta;
}


//subscribers for real pos from gazebo
void RealizationPartial::gazeboOdomCallback0(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 0;
  if(temp_id == id){

    real_pose_x = msg->pose.pose.position.x;
    real_pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      real_path_distance = real_path_distance + sqrt(pow(real_prev_pose_x-real_pose_x,2)+pow(real_prev_pose_y-real_pose_y,2));//path distance update
    }
    real_prev_pose_x = real_pose_x;//previous position
    real_prev_pose_y = real_pose_y;

  }

  for(int j=0;j<n;j++){
    real_pose[j][temp_id][0] = msg->pose.pose.position.x;
    real_pose[j][temp_id][1] = msg->pose.pose.position.y;

  }

}

void RealizationPartial::gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 1;
  if(temp_id == id){

    real_pose_x = msg->pose.pose.position.x;
    real_pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      real_path_distance = real_path_distance + sqrt(pow(real_prev_pose_x-real_pose_x,2)+pow(real_prev_pose_y-real_pose_y,2));//path distance update
    }
    real_prev_pose_x = real_pose_x;//previous position
    real_prev_pose_y = real_pose_y;

  }

  for(int j=0;j<n;j++){
    real_pose[j][temp_id][0] = msg->pose.pose.position.x;
    real_pose[j][temp_id][1] = msg->pose.pose.position.y;

  }
}

void RealizationPartial::gazeboOdomCallback2(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 2;
  if(temp_id == id){

    real_pose_x = msg->pose.pose.position.x;
    real_pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      real_path_distance = real_path_distance + sqrt(pow(real_prev_pose_x-real_pose_x,2)+pow(real_prev_pose_y-real_pose_y,2));//path distance update
    }
    real_prev_pose_x = real_pose_x;//previous position
    real_prev_pose_y = real_pose_y;

  }

  for(int j=0;j<n;j++){
    real_pose[j][temp_id][0] = msg->pose.pose.position.x;
    real_pose[j][temp_id][1] = msg->pose.pose.position.y;

  }
}

void RealizationPartial::gazeboOdomCallback3(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 3;
  if(temp_id == id){

    real_pose_x = msg->pose.pose.position.x;
    real_pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      real_path_distance = real_path_distance + sqrt(pow(real_prev_pose_x-real_pose_x,2)+pow(real_prev_pose_y-real_pose_y,2));//path distance update
    }
    real_prev_pose_x = real_pose_x;//previous position
    real_prev_pose_y = real_pose_y;

  }

  for(int j=0;j<n;j++){
    real_pose[j][temp_id][0] = msg->pose.pose.position.x;
    real_pose[j][temp_id][1] = msg->pose.pose.position.y;

  }
}

void RealizationPartial::gazeboOdomCallback4(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 4;
  if(temp_id == id){

    real_pose_x = msg->pose.pose.position.x;
    real_pose_y = msg->pose.pose.position.y;
    if(!initialize_prev){
      initialize_prev = true;
    }
    else{
      real_path_distance = real_path_distance + sqrt(pow(real_prev_pose_x-real_pose_x,2)+pow(real_prev_pose_y-real_pose_y,2));//path distance update
    }
    real_prev_pose_x = real_pose_x;//previous position
    real_prev_pose_y = real_pose_y;

  }

  for(int j=0;j<n;j++){
    real_pose[j][temp_id][0] = msg->pose.pose.position.x;
    real_pose[j][temp_id][1] = msg->pose.pose.position.y;

  }
}

void RealizationPartial::realDistanceCalculator(){
  //calculates distances among robots
  for(int i=0;i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        realDistance[i][j]=sqrt(pow(real_pose[i][i][0]-real_pose[i][j][0],2)+pow(real_pose[i][i][1]-real_pose[i][j][1],2));
        realDistance[j][i] = realDistance[i][j];
        if(print_distances){
          if(i<j){
            cout << "real distance " << i << j << " " << realDistance[i][j] << endl;
          }
        }
      }
    }
  }
}

void RealizationPartial::RealComparator(){
  //checks goal topology is realized
  realCompleted = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i<j){
          if(realDistance[i][j] < threshold){
            realCompleted = realCompleted * A[i][j];
          }
          else{
            realCompleted = realCompleted * (1-A[i][j]);
          }
      }
    }
  }
  if(realCompleted == 1){
    cout << "REAL MISSION COMPLETED !!! " << endl;
  }
  else{
    cout << "real next time :(" << endl;
  }
}

//subscribers for odometry from gazebo

void RealizationPartial::odomCallback0(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==0){
    pose_theta = msg->position.z;//heading
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));//path distance update
      prev_pose_x = pose_x;//previous position
      prev_pose_y = pose_y;
    }

    cout << "path distance robot1: " << path_distance << endl;
  }
}

void RealizationPartial::odomCallback1(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback1: " << t << endl;
  if(id ==1){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot2: " << path_distance << endl;

    }
  }


void RealizationPartial::odomCallback2(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==2){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot3: " << path_distance << endl;
  }
}

void RealizationPartial::odomCallback3(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==3){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot4: " << path_distance << endl;
  }
}

void RealizationPartial::odomCallback4(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==4){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot5: " << path_distance << endl;
  }
}

//subscribers for robot positions calculated at pos_calculator package
void RealizationPartial::calcPosCallback0(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 0;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;//calcPos[reference frame][target]
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RealizationPartial::calcPosCallback1(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 1;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RealizationPartial::calcPosCallback2(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 2;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RealizationPartial::calcPosCallback3(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 3;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RealizationPartial::calcPosCallback4(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 4;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

//subscriber for signal whether transformation is completed
void RealizationPartial::transformCallback(const std_msgs::Bool::ConstPtr& msg){
  isSeen = msg->data;
}

//////////////////////////////////////////////////////////////////////////////////////

void RealizationPartial::distanceCalculator(){
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




void RealizationPartial::gamaFinder(){
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

void RealizationPartial::gamaBDotFinder(){
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

void RealizationPartial::betaFinder(){
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

void RealizationPartial::betaBDotFinder(){
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

void RealizationPartial::gamaEtaDotFinder(){
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

void RealizationPartial::fiBDotFinder(){
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

void RealizationPartial::fiEtaDotFinder(){
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


void RealizationPartial::etaFinder(){
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

  RealizationPartial::fiEtaDotFinder();//eta0

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot0 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k1[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k1  " << i << j << " " << k1[i][j] << endl;
      eta[i][j] = eta[i][j] + k1[i][j] /2;


    }
  }

  RealizationPartial::fiEtaDotFinder();//eta0 + k1/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot1 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k2[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k2  " << i << j << " " << k2[i][j] << endl;
      eta[i][j] = eta[i][j] + k2[i][j] /2 - k1[i][j] /2;


    }
  }

  RealizationPartial::fiEtaDotFinder();//eta0 + k2/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot2 " << i << j << " " << fi_eta_dot[i][j] << " step size " << step_size << endl;
      k3[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k3  " << i << j << " " << k3[i][j] << endl;
      eta[i][j] = eta[i][j] + k3[i][j] - k2[i][j] /2;;

    }
  }

  RealizationPartial::fiEtaDotFinder();//eta0 + k3

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

void RealizationPartial::Comparator(){
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



void RealizationPartial::finalRealization(){
  //calculates velocities and eta values
  RealizationPartial::gamaFinder(); //calculates gamma
  RealizationPartial::gamaBDotFinder(); //calculates derivative of gamma with respect to b(position)
  RealizationPartial::betaFinder(); //calculates beta
  RealizationPartial::betaBDotFinder(); //calculates derivative of beta with respect to b(position)
  RealizationPartial::gamaEtaDotFinder(); //calculates derivative of gamma with respect to eta
  RealizationPartial::fiBDotFinder(); //calculates derivative of fi with respect to b(position)
  RealizationPartial::etaFinder(); //calculates new eta values using runge kutta
  RealizationPartial::setVelocity();//calculates linear and angular velocities
  RealizationPartial::Comparator(); //checks goal topology is realized
  RealizationPartial::RealComparator();

}

void RealizationPartial::setVelocity(){
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



void RealizationPartial::turnToSee(){
  //turns to observe other robots
  geometry_msgs::Twist msg;

  msg.linear.x = 0; //zero linear velocity
  msg.angular.z = PI/4; //angular velocity

  vel_pub.publish(msg);

}


void RealizationPartial::work(){

  ostringstream ss;
  ss << id + 1;
  string name =  "robot" + ss.str(); //message name for velocity at gazebo

  vel_pub = velPub.advertise<geometry_msgs::Twist>(name+"/cmd_vel", 100);//publisher for velocity at gazebo

  //subscribers for odometry from gazebo
  ros::Subscriber odom_sub1 = poseSub.subscribe("/odom1",1000,&RealizationPartial::odomCallback0,this);
  ros::Subscriber odom_sub2 = poseSub.subscribe("/odom2",1000,&RealizationPartial::odomCallback1,this);
  ros::Subscriber odom_sub3 = poseSub.subscribe("/odom3",1000,&RealizationPartial::odomCallback2,this);
  ros::Subscriber odom_sub4 = poseSub.subscribe("/odom4",1000,&RealizationPartial::odomCallback3,this);
  ros::Subscriber odom_sub5 = poseSub.subscribe("/odom5",1000,&RealizationPartial::odomCallback4,this);

  //subscriber for completed signal
  ros::Subscriber tr_sub = trSub.subscribe("/transformCompleted",1000,&RealizationPartial::transformCallback,this);

  //subscribers for calculated positions
  ros::Subscriber calc_sub1 = poseSub.subscribe("/completedPos0",1000,&RealizationPartial::calcPosCallback0,this);
  ros::Subscriber calc_sub2 = poseSub.subscribe("/completedPos1",1000,&RealizationPartial::calcPosCallback1,this);
  ros::Subscriber calc_sub3 = poseSub.subscribe("/completedPos2",1000,&RealizationPartial::calcPosCallback2,this);
  ros::Subscriber calc_sub4 = poseSub.subscribe("/completedPos3",1000,&RealizationPartial::calcPosCallback3,this);
  ros::Subscriber calc_sub5 = poseSub.subscribe("/completedPos4",1000,&RealizationPartial::calcPosCallback4,this);

  //subscriber for gazebo pose
  ros::Subscriber calc_sub11 = poseSub.subscribe("/robot1/odom",1000,&RealizationPartial::gazeboOdomCallback0,this);
  ros::Subscriber calc_sub21 = poseSub.subscribe("/robot2/odom",1000,&RealizationPartial::gazeboOdomCallback1,this);
  ros::Subscriber calc_sub31 = poseSub.subscribe("/robot3/odom",1000,&RealizationPartial::gazeboOdomCallback2,this);
  ros::Subscriber calc_sub41 = poseSub.subscribe("/robot4/odom",1000,&RealizationPartial::gazeboOdomCallback3,this);
  ros::Subscriber calc_sub51 = poseSub.subscribe("/robot5/odom",1000,&RealizationPartial::gazeboOdomCallback4,this);

  ros::Rate loop_rate(f);


  while (ros::ok() && !completed_stop){

    if(isSeen){//if transformations are completed and positions are calculated
      RealizationPartial::distanceCalculator();//calculates distances among robots
      RealizationPartial::realDistanceCalculator();
      RealizationPartial::finalRealization(); //realization algortihm

      geometry_msgs::Twist msg;//velocity message

      msg.linear.x = this->linear_vel;
      msg.angular.z = this->angular_vel;

      vel_pub.publish(msg); //publishes velocity message
    }

    else{
      //turnToSee();
      geometry_msgs::Twist msg;//velocity message to turn

      msg.linear.x = 0;
      msg.angular.z = 0.8;


      vel_pub.publish(msg); //publishes velocity message
      ROS_INFO("turning...");
    }

    ros::spinOnce();
    loop_rate.sleep();
  }


  ostringstream ss2;
  ss2 << id + 1;
  string path_distance_param_name =  "robot" + ss2.str();//param name related to path distance
  string real_path_distance_param_name =  "real robot" + ss2.str();//param name related to path distance

  string ok = "ok";
  string fail = "fail";

  string real_ok = "real ok";
  string real_fail = "real fail";

  getParamHandle.setParam(path_distance_param_name, this->path_distance);
  //cout << path_distance_param_name << ": " << this->path_distance;

  //cout << path_distance_param_name << ": " << this->path_distance;

  string path_file; //path file name to save
  getParamHandle.getParam("/yaml_file_name", path_file);
  cout << "param name " << path_distance_param_name << endl;

  FileStorage fs(path_file, FileStorage::APPEND);
  if( fs.isOpened() ){
    cout << "opened" <<endl;
    //fs.write(path_distance_param_name,this->path_distance);//this->path_distance;
    fs.write(real_path_distance_param_name,this->real_path_distance);//this->path_distance;
    //fs.release();
    if(completed == 1){
      fs.write(ok,1);
    }
    else{
      fs.write(fail,0);
    }
    if(realCompleted == 1){
      fs.write(real_ok,1);
    }
    else{
      fs.write(real_fail,0);
    }

    cout << "path distance " << id+1 <<" saved to " << path_file  << endl;
  }
  else{
    cout << "yaml file is not opened" << endl;
  }


}
